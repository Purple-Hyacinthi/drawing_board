import { readFileSync } from 'node:fs'
import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'
import { resolve } from 'path'

const packageJson = JSON.parse(readFileSync(resolve(__dirname, './package.json'), 'utf-8')) as { version?: string }
const appVersion = packageJson.version ?? '0.0.0'

export default defineConfig({
  base: './',
  define: {
    __APP_VERSION__: JSON.stringify(appVersion)
  },
  plugins: [vue()],
  resolve: {
    alias: {
      '@': resolve(__dirname, './src')
    }
  },
  server: {
    port: 3000,
    proxy: {
      '/api': {
        target: 'http://localhost:8080',
        changeOrigin: true
      }
    }
  },
  build: {
    outDir: 'dist',
    sourcemap: true,
    rollupOptions: {
      output: {
        manualChunks: {
          'vue-vendor': ['vue', 'vue-router', 'pinia']
        }
      }
    }
  }
})
