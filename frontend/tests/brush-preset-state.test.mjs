import test from 'node:test'
import assert from 'node:assert/strict'

import { applyBrushPresetState } from '../src/utils/brush-preset-state.js'

const brushPreset = {
  color: '#000000',
  size: 12,
  opacity: 60,
  style: {
    angle: 0,
    roundness: 100,
    spacing: 10,
    hardness: 42,
    flow: 82,
    sizeMode: 'pressure',
    sizeJitter: 0
  }
}

test('preserves custom color when switching paint presets', () => {
  const result = applyBrushPresetState({
    currentColor: '#ff5500',
    preset: brushPreset
  })

  assert.equal(result.color, '#ff5500')
  assert.equal(result.size, 12)
  assert.equal(result.opacity, 60)
  assert.deepEqual(result.style, brushPreset.style)
})

test('falls back to preset color when current color is invalid', () => {
  const result = applyBrushPresetState({
    currentColor: 'invalid',
    preset: brushPreset
  })

  assert.equal(result.color, '#000000')
})

test('uses next preset default color when current color still matches previous preset', () => {
  const result = applyBrushPresetState({
    currentColor: '#000000',
    currentPresetColor: '#000000',
    preset: {
      ...brushPreset,
      color: '#555555'
    }
  })

  assert.equal(result.color, '#555555')
})
