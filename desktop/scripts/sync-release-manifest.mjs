import { createHash, createPrivateKey, sign } from 'node:crypto'
import { existsSync, mkdirSync, readFileSync, writeFileSync } from 'node:fs'
import { dirname, resolve } from 'node:path'

const desktopRoot = process.cwd()
const manifestPath = resolve(desktopRoot, 'release/release-manifest.json')

function parseArgs() {
  const result = {
    privateKeyFile: process.env.DRAWING_BOARD_RELEASE_PRIVATE_KEY_FILE || '',
    version: process.env.DRAWING_BOARD_RELEASE_VERSION || '',
    builtAt: process.env.DRAWING_BOARD_RELEASE_BUILT_AT || '',
    strict: false
  }

  for (let index = 2; index < process.argv.length; index += 1) {
    const arg = process.argv[index]
    if (arg === '--private-key') {
      result.privateKeyFile = process.argv[index + 1] || ''
      index += 1
      continue
    }
    if (arg === '--version') {
      result.version = process.argv[index + 1] || ''
      index += 1
      continue
    }
    if (arg === '--built-at') {
      result.builtAt = process.argv[index + 1] || ''
      index += 1
      continue
    }
    if (arg === '--strict') {
      result.strict = true
    }
  }

  return result
}

function isIso8601(value) {
  if (!value) return false
  const time = Date.parse(value)
  if (Number.isNaN(time)) return false
  return /\d{4}-\d{2}-\d{2}T/gu.test(value)
}

function sha256Hex(filePath) {
  const content = readFileSync(filePath)
  return createHash('sha256').update(content).digest('hex')
}

function loadPrivateKey(privateKeyFile) {
  if (!privateKeyFile) return null
  const fullPath = resolve(desktopRoot, privateKeyFile)
  if (!existsSync(fullPath)) {
    throw new Error(`private key file not found: ${fullPath}`)
  }
  return createPrivateKey(readFileSync(fullPath, 'utf8'))
}

if (!existsSync(manifestPath)) {
  throw new Error(`manifest not found: ${manifestPath}`)
}

const options = parseArgs()
if (options.builtAt && !isIso8601(options.builtAt)) {
  throw new Error('built-at must be an ISO8601 datetime string')
}

const manifest = JSON.parse(readFileSync(manifestPath, 'utf8'))
if (!Array.isArray(manifest.artifacts)) {
  throw new Error('release-manifest artifacts must be an array')
}

const privateKey = loadPrivateKey(options.privateKeyFile)
const publicKeyOverride = (process.env.DRAWING_BOARD_RELEASE_PUBLIC_KEY || '').trim()
const missing = []

for (const artifact of manifest.artifacts) {
  if (!artifact || typeof artifact !== 'object') continue
  const file = String(artifact.file || '').trim()
  const signatureFile = String(artifact.signature_file || '').trim()

  if (options.version) {
    artifact.version = options.version
  }
  if (options.builtAt) {
    artifact.built_at = options.builtAt
  }

  if (!file) continue

  const filePath = resolve(desktopRoot, 'release', file)
  if (!existsSync(filePath)) {
    missing.push(file)
    continue
  }

  const hash = sha256Hex(filePath)
  artifact.sha256 = hash

  if (privateKey && signatureFile) {
    const signature = sign(null, Buffer.from(hash, 'utf8'), privateKey).toString('base64')
    const signaturePath = resolve(desktopRoot, 'release', signatureFile)
    mkdirSync(dirname(signaturePath), { recursive: true })
    writeFileSync(signaturePath, `${signature}\n`, 'utf8')
  }
}

manifest.generated_at = new Date().toISOString()
if (publicKeyOverride) {
  manifest.public_key = publicKeyOverride
}

writeFileSync(manifestPath, `${JSON.stringify(manifest, null, 2)}\n`, 'utf8')

console.log(`[ok] synced manifest: ${manifestPath}`)
if (privateKey) {
  console.log('[ok] signatures regenerated')
} else {
  console.log('[warn] no private key configured, signatures were not regenerated')
}

if (missing.length > 0) {
  console.log('[warn] missing artifacts:')
  for (const file of missing) {
    console.log(`  - ${file}`)
  }

  if (options.strict) {
    process.exit(1)
  }
}
