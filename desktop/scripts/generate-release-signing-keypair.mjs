import { generateKeyPairSync } from 'node:crypto'
import { mkdirSync, writeFileSync } from 'node:fs'
import { dirname, resolve } from 'node:path'

function base64UrlToBase64(value) {
  const normalized = value.replace(/-/gu, '+').replace(/_/gu, '/')
  const pad = normalized.length % 4
  if (pad === 0) return normalized
  return `${normalized}${'='.repeat(4 - pad)}`
}

function parseArgs() {
  const result = {
    privateOut: '',
    publicOut: ''
  }

  for (let index = 2; index < process.argv.length; index += 1) {
    const arg = process.argv[index]
    if (arg === '--private-out') {
      result.privateOut = process.argv[index + 1] || ''
      index += 1
      continue
    }
    if (arg === '--public-out') {
      result.publicOut = process.argv[index + 1] || ''
      index += 1
    }
  }

  return result
}

const args = parseArgs()
const { privateKey, publicKey } = generateKeyPairSync('ed25519')

const privatePem = privateKey.export({ format: 'pem', type: 'pkcs8' })
const publicPem = publicKey.export({ format: 'pem', type: 'spki' })
const publicJwk = publicKey.export({ format: 'jwk' })

if (!publicJwk?.x) {
  throw new Error('failed to export public key material')
}

const publicKeyBase64 = base64UrlToBase64(publicJwk.x)

if (args.privateOut) {
  const privatePath = resolve(process.cwd(), args.privateOut)
  mkdirSync(dirname(privatePath), { recursive: true })
  writeFileSync(privatePath, privatePem)
  console.log(`[ok] private key: ${privatePath}`)
}

if (args.publicOut) {
  const publicPath = resolve(process.cwd(), args.publicOut)
  mkdirSync(dirname(publicPath), { recursive: true })
  writeFileSync(publicPath, publicPem)
  console.log(`[ok] public key pem: ${publicPath}`)
}

console.log('\nUse this value for CI secret and manifest:')
console.log(`DRAWING_BOARD_RELEASE_PUBLIC_KEY=${publicKeyBase64}`)
