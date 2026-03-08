import { createHash, createPublicKey, verify } from 'node:crypto'
import { existsSync, readFileSync, statSync } from 'node:fs'
import { resolve } from 'node:path'

const desktopRoot = process.cwd()
const releaseRoot = resolve(desktopRoot, 'release')
const manifestPath = resolve(releaseRoot, 'release-manifest.json')

const requiredTargets = ['windows-x64', 'macos-x64', 'linux-x64']
const placeholderMarkers = ['placeholder', '__replace_with', '<replace-with']

let hasError = false
let warningCount = 0

function logOk(message) {
  console.log(`[ok] ${message}`)
}

function logWarn(message) {
  warningCount += 1
  console.warn(`[warn] ${message}`)
}

function logError(message) {
  hasError = true
  console.error(`[error] ${message}`)
}

function fileBuffer(relativePath) {
  const fullPath = resolve(releaseRoot, relativePath)
  if (!existsSync(fullPath)) {
    logError(`${relativePath} is missing`)
    return null
  }

  const stat = statSync(fullPath)
  if (!stat.isFile()) {
    logError(`${relativePath} is not a file`)
    return null
  }
  if (stat.size === 0) {
    logError(`${relativePath} is empty`)
    return null
  }

  return readFileSync(fullPath)
}

function normalizeHex(value) {
  const text = String(value || '').trim().toLowerCase()
  if (!/^[0-9a-f]{64}$/u.test(text)) {
    return null
  }
  return text
}

function parseHexOrBase64Bytes(value) {
  const text = String(value || '').trim()
  if (!text) return null

  const compact = text.replace(/\s+/gu, '')
  if (/^[0-9a-fA-F]+$/u.test(compact) && compact.length % 2 === 0) {
    try {
      return Buffer.from(compact, 'hex')
    } catch {
      return null
    }
  }

  if (!/^[A-Za-z0-9+/=]+$/u.test(compact) || compact.length % 4 !== 0) {
    return null
  }

  try {
    const bytes = Buffer.from(compact, 'base64')
    return bytes.length > 0 ? bytes : null
  } catch {
    return null
  }
}

function sha256Hex(buf) {
  return createHash('sha256').update(buf).digest('hex')
}

function parseManifest() {
  if (!existsSync(manifestPath)) {
    logError('release-manifest.json is missing')
    return null
  }

  let parsed
  try {
    parsed = JSON.parse(readFileSync(manifestPath, 'utf8'))
  } catch (error) {
    logError(`release-manifest.json is invalid JSON: ${error instanceof Error ? error.message : String(error)}`)
    return null
  }

  if (!Array.isArray(parsed.artifacts) || parsed.artifacts.length === 0) {
    logError('release-manifest artifacts must be a non-empty array')
    return null
  }

  return parsed
}

function parsePublicKey(manifest) {
  const raw = process.env.DRAWING_BOARD_RELEASE_PUBLIC_KEY || manifest.public_key || ''
  const bytes = parseHexOrBase64Bytes(raw)
  if (!bytes) {
    logWarn('public key missing; cryptographic signature verification skipped')
    return null
  }

  if (bytes.length !== 32) {
    logError('release public key must be 32 bytes (hex/base64)')
    return null
  }

  try {
    const spkiPrefix = Buffer.from('302a300506032b6570032100', 'hex')
    return createPublicKey({
      key: Buffer.concat([spkiPrefix, bytes]),
      format: 'der',
      type: 'spki'
    })
  } catch (error) {
    logError(`failed to parse release public key: ${error instanceof Error ? error.message : String(error)}`)
    return null
  }
}

function verifyTargetMatrix(artifacts) {
  const targets = new Set(
    artifacts
      .map(item => (item && typeof item === 'object' ? String(item.target || '').trim() : ''))
      .filter(Boolean)
  )

  for (const requiredTarget of requiredTargets) {
    if (!targets.has(requiredTarget)) {
      logError(`release-manifest missing target entry: ${requiredTarget}`)
    }
  }
}

function hasPlaceholder(text) {
  const lower = text.toLowerCase()
  return placeholderMarkers.some(marker => lower.includes(marker))
}

function verifyArtifact(entry, index, publicKeyObject) {
  if (!entry || typeof entry !== 'object') {
    logError(`artifacts[${index}] must be an object`)
    return
  }

  const target = String(entry.target || '').trim()
  const file = String(entry.file || '').trim()
  const signatureFile = String(entry.signature_file || '').trim()
  const expectedSha = normalizeHex(entry.sha256)

  if (!target || !file || !signatureFile) {
    logError(`artifacts[${index}] target/file/signature_file are required`)
    return
  }
  if (!expectedSha) {
    logError(`artifacts[${index}] sha256 must be 64-char hex`)
  }

  const artifactBuf = fileBuffer(file)
  if (!artifactBuf) {
    return
  }

  const preview = artifactBuf.slice(0, Math.min(artifactBuf.length, 4096)).toString('utf8')
  if (hasPlaceholder(preview)) {
    logError(`${file} contains placeholder marker`)
  }

  const actualSha = sha256Hex(artifactBuf)
  if (expectedSha && actualSha !== expectedSha) {
    logError(`${target} sha256 mismatch: expected ${expectedSha}, actual ${actualSha}`)
  } else {
    logOk(`${target} sha256 verified`)
  }

  const signatureBuf = fileBuffer(signatureFile)
  if (!signatureBuf) {
    return
  }

  const signatureText = signatureBuf.toString('utf8').trim()
  if (!signatureText || hasPlaceholder(signatureText)) {
    logError(`${signatureFile} is empty or placeholder`)
    return
  }

  const signatureBytes = parseHexOrBase64Bytes(signatureText)
  if (!signatureBytes || signatureBytes.length !== 64) {
    logError(`${signatureFile} must contain a 64-byte Ed25519 signature`) 
    return
  }

  if (!publicKeyObject) {
    logWarn(`${target} signature format valid, cryptographic verify skipped`)
    return
  }

  const verified = verify(null, Buffer.from(actualSha, 'utf8'), publicKeyObject, signatureBytes)
  if (!verified) {
    logError(`${target} signature verification failed`)
    return
  }

  logOk(`${target} signature verified`)
}

const manifest = parseManifest()
if (manifest) {
  verifyTargetMatrix(manifest.artifacts)
  const publicKeyObject = parsePublicKey(manifest)
  for (let index = 0; index < manifest.artifacts.length; index += 1) {
    verifyArtifact(manifest.artifacts[index], index, publicKeyObject)
  }
}

if (hasError) {
  console.error('\nDesktop release asset verification failed.')
  process.exit(1)
}

if (warningCount > 0) {
  console.warn(`\nDesktop release verification passed with ${warningCount} warning(s).`)
} else {
  console.log('\nDesktop release verification passed.')
}
