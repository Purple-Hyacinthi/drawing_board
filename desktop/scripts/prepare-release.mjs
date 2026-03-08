import { execFileSync } from 'node:child_process'
import { resolve } from 'node:path'

function parseArgs() {
  const result = {
    privateKeyFile: process.env.DRAWING_BOARD_RELEASE_PRIVATE_KEY_FILE || '',
    publicKey: process.env.DRAWING_BOARD_RELEASE_PUBLIC_KEY || '',
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
    if (arg === '--public-key') {
      result.publicKey = process.argv[index + 1] || ''
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

function runOrExit(command, args, env, label) {
  try {
    execFileSync(command, args, { stdio: 'inherit', env })
  } catch (error) {
    const code = typeof error?.status === 'number' ? error.status : 1
    console.error(`\n[error] ${label} failed (exit code: ${code})`)
    process.exit(code)
  }
}

const options = parseArgs()
const desktopRoot = process.cwd()
const syncScript = resolve(desktopRoot, 'scripts/sync-release-manifest.mjs')
const verifyScript = resolve(desktopRoot, 'scripts/verify-release-assets.mjs')

const syncArgs = [syncScript]
if (options.privateKeyFile) {
  syncArgs.push('--private-key', options.privateKeyFile)
}
if (options.version) {
  syncArgs.push('--version', options.version)
}
if (options.builtAt) {
  syncArgs.push('--built-at', options.builtAt)
}
if (options.strict) {
  syncArgs.push('--strict')
}

const env = {
  ...process.env,
  DRAWING_BOARD_RELEASE_PRIVATE_KEY_FILE: options.privateKeyFile,
  DRAWING_BOARD_RELEASE_PUBLIC_KEY: options.publicKey
}

runOrExit('node', syncArgs, env, 'manifest sync')
runOrExit('node', [verifyScript], env, 'asset verification')

console.log('\n[ok] desktop release assets are synced and verified.')
