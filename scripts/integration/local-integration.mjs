import { execFileSync, spawn } from 'node:child_process'
import { createWriteStream } from 'node:fs'
import { mkdir, writeFile } from 'node:fs/promises'
import path from 'node:path'
import process from 'node:process'

const DEFAULT_BACKEND_URL = 'http://127.0.0.1:8080'
const DEFAULT_FRONTEND_URL = 'http://127.0.0.1:3000'
const DEFAULT_OUTPUT_DIR = 'tmp/integration-artifacts'

function parseArgs(argv) {
  const options = {
    backendUrl: process.env.BACKEND_URL || DEFAULT_BACKEND_URL,
    frontendUrl: process.env.FRONTEND_URL || DEFAULT_FRONTEND_URL,
    outputDir: process.env.OUTPUT_DIR || DEFAULT_OUTPUT_DIR,
    skipFrontendCheck: process.env.SKIP_FRONTEND_CHECK === 'true',
    autoStartBackend: process.env.AUTO_START_BACKEND === 'true',
    autoStartFrontend: process.env.AUTO_START_FRONTEND === 'true',
    backendProfile: process.env.BACKEND_PROFILE || 'local-it',
    backendProjectDir: process.env.BACKEND_PROJECT_DIR || 'drawing-board-backend',
    frontendProjectDir: process.env.FRONTEND_PROJECT_DIR || 'frontend'
  }

  for (let index = 2; index < argv.length; index += 1) {
    const arg = argv[index]
    if (arg === '--backend-url') {
      options.backendUrl = argv[index + 1] || options.backendUrl
      index += 1
      continue
    }
    if (arg === '--frontend-url') {
      options.frontendUrl = argv[index + 1] || options.frontendUrl
      index += 1
      continue
    }
    if (arg === '--output-dir') {
      options.outputDir = argv[index + 1] || options.outputDir
      index += 1
      continue
    }
    if (arg === '--skip-frontend-check') {
      options.skipFrontendCheck = true
      continue
    }
    if (arg === '--auto-start-backend') {
      options.autoStartBackend = true
      continue
    }
    if (arg === '--auto-start-frontend') {
      options.autoStartFrontend = true
      continue
    }
    if (arg === '--backend-profile') {
      options.backendProfile = argv[index + 1] || options.backendProfile
      index += 1
      continue
    }
    if (arg === '--backend-project-dir') {
      options.backendProjectDir = argv[index + 1] || options.backendProjectDir
      index += 1
      continue
    }
    if (arg === '--frontend-project-dir') {
      options.frontendProjectDir = argv[index + 1] || options.frontendProjectDir
      index += 1
    }
  }

  return options
}

function createTimeoutSignal(timeoutMs) {
  const controller = new AbortController()
  const timeoutId = setTimeout(() => controller.abort(), timeoutMs)
  return {
    signal: controller.signal,
    dispose: () => clearTimeout(timeoutId)
  }
}

async function requestJson(method, url, body, headers = {}, expectedStatus = [200]) {
  const timeout = createTimeoutSignal(20_000)
  try {
    const response = await fetch(url, {
      method,
      headers: {
        'Content-Type': 'application/json',
        ...headers
      },
      body: body ? JSON.stringify(body) : undefined,
      signal: timeout.signal
    })

    const contentType = response.headers.get('content-type') || ''
    const parsed = contentType.includes('application/json')
      ? await response.json()
      : await response.text()

    if (!expectedStatus.includes(response.status)) {
      throw new Error(`${method} ${url} -> ${response.status}: ${JSON.stringify(parsed)}`)
    }

    return { response, data: parsed }
  } finally {
    timeout.dispose()
  }
}

async function requestBinary(method, url, body, headers = {}, expectedStatus = [200]) {
  const timeout = createTimeoutSignal(20_000)
  try {
    const response = await fetch(url, {
      method,
      headers: {
        'Content-Type': 'application/json',
        ...headers
      },
      body: body ? JSON.stringify(body) : undefined,
      signal: timeout.signal
    })

    if (!expectedStatus.includes(response.status)) {
      const text = await response.text()
      throw new Error(`${method} ${url} -> ${response.status}: ${text}`)
    }

    const arrayBuffer = await response.arrayBuffer()
    return Buffer.from(arrayBuffer)
  } finally {
    timeout.dispose()
  }
}

async function waitForBackend(backendUrl, maxAttempts = 20) {
  const healthUrl = `${backendUrl}/actuator/health`
  for (let attempt = 1; attempt <= maxAttempts; attempt += 1) {
    try {
      const timeout = createTimeoutSignal(5_000)
      const response = await fetch(healthUrl, { signal: timeout.signal })
      timeout.dispose()
      if (response.ok) {
        return
      }
    } catch {
      // ignore and retry
    }

    await new Promise(resolve => setTimeout(resolve, 2_000))
  }

  throw new Error(`后端健康检查失败: ${healthUrl}`)
}

async function isBackendHealthy(backendUrl) {
  try {
    const timeout = createTimeoutSignal(4_000)
    const response = await fetch(`${backendUrl}/actuator/health`, { signal: timeout.signal })
    timeout.dispose()
    return response.ok
  } catch {
    return false
  }
}

async function startBackendProcess(options) {
  const backendDir = path.resolve(process.cwd(), options.backendProjectDir)
  const logPath = path.resolve(process.cwd(), 'tmp', 'integration-backend.log')
  await mkdir(path.dirname(logPath), { recursive: true })

  const logStream = createWriteStream(logPath, { flags: 'w' })
  const command = process.platform === 'win32' ? 'gradlew.bat' : './gradlew'
  const child = spawn(command, [':application:bootRun'], {
    cwd: backendDir,
    env: {
      ...process.env,
      SPRING_PROFILES_ACTIVE: options.backendProfile
    },
    shell: process.platform === 'win32'
  })

  child.stdout.pipe(logStream)
  child.stderr.pipe(logStream)

  return {
    child,
    logPath,
    logStream
  }
}

function stopProcess(processHandle) {
  if (!processHandle) {
    return
  }

  const { child, logStream } = processHandle
  if (logStream) {
    logStream.end()
  }

  if (!child || child.exitCode !== null) {
    return
  }

  try {
    if (process.platform === 'win32') {
      execFileSync('taskkill', ['/PID', String(child.pid), '/T', '/F'], { stdio: 'ignore' })
    } else {
      child.kill('SIGTERM')
    }
  } catch {
    // ignore cleanup failures
  }
}

function stopBackendProcess(backendHandle) {
  stopProcess(backendHandle)
}

function stopFrontendProcess(frontendHandle) {
  stopProcess(frontendHandle)
}

async function isFrontendHealthy(frontendUrl) {
  const timeout = createTimeoutSignal(5_000)
  try {
    const response = await fetch(frontendUrl, { signal: timeout.signal })
    if (!response.ok) {
      return false
    }
    const html = await response.text()
    return html.includes('id="app"')
  } catch {
    return false
  } finally {
    timeout.dispose()
  }
}

async function waitForFrontend(frontendUrl, maxAttempts = 30) {
  for (let attempt = 1; attempt <= maxAttempts; attempt += 1) {
    if (await isFrontendHealthy(frontendUrl)) {
      return
    }
    await new Promise(resolve => setTimeout(resolve, 2_000))
  }
  throw new Error(`前端健康检查失败: ${frontendUrl}`)
}

async function startFrontendProcess(options) {
  const frontendDir = path.resolve(process.cwd(), options.frontendProjectDir)
  const logPath = path.resolve(process.cwd(), 'tmp', 'integration-frontend.log')
  await mkdir(path.dirname(logPath), { recursive: true })

  const logStream = createWriteStream(logPath, { flags: 'w' })
  const command = process.platform === 'win32' ? 'npm' : 'npm'
  const child = spawn(command, ['run', 'dev', '--', '--host', '127.0.0.1', '--port', '3000'], {
    cwd: frontendDir,
    env: {
      ...process.env,
      NODE_ENV: 'development'
    },
    shell: process.platform === 'win32'
  })

  child.stdout.pipe(logStream)
  child.stderr.pipe(logStream)

  return {
    child,
    logPath,
    logStream
  }
}

function randomAccount() {
  const suffix = `${Date.now()}${Math.floor(Math.random() * 10_000)}`
  return {
    username: `it_user_${suffix}`,
    email: `it_${suffix}@example.test`,
    password: 'Passw0rd!123'
  }
}

async function run() {
  const options = parseArgs(process.argv)
  const backendApiBase = `${options.backendUrl}/api/v1`
  let backendHandle = null
  let frontendHandle = null

  try {
    if (options.autoStartBackend) {
      const alive = await isBackendHealthy(options.backendUrl)
      if (alive) {
        console.log('[1/11] 检测到后端已运行，跳过自动启动')
      } else {
        console.log('[1/11] 自动启动后端服务...')
        backendHandle = await startBackendProcess(options)
      }
    } else {
      console.log('[1/11] 使用外部后端服务...')
    }

    console.log('[2/11] 等待后端健康检查...')
    await waitForBackend(options.backendUrl, 40)

    if (!options.skipFrontendCheck) {
      if (options.autoStartFrontend) {
        const frontendAlive = await isFrontendHealthy(options.frontendUrl)
        if (frontendAlive) {
          console.log('[3/11] 检测到前端已运行，跳过自动启动')
        } else {
          console.log('[3/11] 自动启动前端服务...')
          frontendHandle = await startFrontendProcess(options)
        }
      } else {
        console.log('[3/11] 使用外部前端服务...')
      }

      console.log('[4/11] 检查前端可访问性...')
      await waitForFrontend(options.frontendUrl, 60)
    } else {
      console.log('[3/11] 跳过前端可访问性检查')
      console.log('[4/11] 已标记为无前端检查模式')
    }

    const account = randomAccount()

    console.log('[5/11] 注册测试账号...')
    await requestJson(
      'POST',
      `${backendApiBase}/auth/register`,
      account,
      {},
      [201]
    )

    console.log('[6/11] 登录并获取Token...')
    const login = await requestJson('POST', `${backendApiBase}/auth/login`, {
      email: account.email,
      password: account.password
    })
    const accessToken = login.data.accessToken
    const refreshToken = login.data.refreshToken

    const authHeaders = {
      Authorization: `Bearer ${accessToken}`
    }

    console.log('[7/11] 获取当前用户并创建画布...')
    const me = await requestJson('GET', `${backendApiBase}/users/me`, null, authHeaders)
    const createCanvas = await requestJson('POST', `${backendApiBase}/canvases`, {
      title: `Integration Canvas ${Date.now()}`,
      width: 800,
      height: 600,
      backgroundColor: '#ffffff'
    }, authHeaders, [201])

    const canvasId = createCanvas.data.id
    const createdLayers = createCanvas.data.layers || []
    const baseLayer = createdLayers[0]

    console.log('[8/11] 创建图层并写入绘图操作...')
    const createLayer = await requestJson('POST', `${backendApiBase}/canvases/${canvasId}/layers`, {
      name: 'Integration Layer',
      zIndex: 1
    }, authHeaders, [201])

    const layerId = createLayer.data.id || baseLayer?.id
    await requestJson('POST', `${backendApiBase}/canvases/${canvasId}/layers/${layerId}/drawing`, {
      type: 'path',
      properties: {
        strokeColor: '#1d4ed8',
        strokeWidth: 4,
        opacity: 1
      },
      pathData: 'M10,10 L220,120'
    }, authHeaders, [201])

    console.log('[9/11] 验证历史、撤销与重做...')
    const history = await requestJson('GET', `${backendApiBase}/canvases/${canvasId}/history?limit=10`, null, authHeaders)
    await requestJson('POST', `${backendApiBase}/canvases/${canvasId}/undo`, {}, authHeaders)
    await requestJson('POST', `${backendApiBase}/canvases/${canvasId}/redo`, {}, authHeaders)
    await requestJson('POST', `${backendApiBase}/auth/refresh`, { refreshToken })

    console.log('[10/11] 导出 PNG/JPEG/SVG...')
    const png = await requestBinary('POST', `${backendApiBase}/canvases/${canvasId}/export/png`, {
      scale: 1,
      quality: 0.9,
      includeBackground: true
    }, authHeaders)

    const jpeg = await requestBinary('POST', `${backendApiBase}/canvases/${canvasId}/export/jpeg`, {
      scale: 1,
      quality: 0.9,
      includeBackground: true
    }, authHeaders)

    const svg = await requestBinary('POST', `${backendApiBase}/canvases/${canvasId}/export/svg`, {
      includeMetadata: true
    }, authHeaders)

    const outputDir = path.resolve(process.cwd(), options.outputDir)
    await mkdir(outputDir, { recursive: true })
    await writeFile(path.join(outputDir, `${canvasId}.png`), png)
    await writeFile(path.join(outputDir, `${canvasId}.jpg`), jpeg)
    await writeFile(path.join(outputDir, `${canvasId}.svg`), svg)

    console.log('[11/11] 联调完成')
    console.log('----------------------------------------')
    console.log(`用户ID: ${me.data.id}`)
    console.log(`画布ID: ${canvasId}`)
    console.log(`历史条目数: ${(history.data.history || []).length}`)
    console.log(`导出目录: ${outputDir}`)
    console.log('状态: SUCCESS')
  } finally {
    stopFrontendProcess(frontendHandle)
    stopBackendProcess(backendHandle)
  }
}

run().catch(error => {
  console.error('联调失败:', error.message)
  process.exitCode = 1
})
