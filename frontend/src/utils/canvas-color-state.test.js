import test from 'node:test'
import assert from 'node:assert/strict'
import { reactive, ref } from 'vue'

import {
  createActiveToolColorModel,
  getActiveToolColor,
  getColorControlLabel,
  getUpdatedToolColors,
  resolveLastColorTool,
  resolveBrushStampColor,
  supportsColorControl
} from './canvas-color-state.js'

test('supportsColorControl includes text and paint tools only', () => {
  assert.equal(supportsColorControl('text'), true)
  assert.equal(supportsColorControl('brush'), true)
  assert.equal(supportsColorControl('shape'), true)
  assert.equal(supportsColorControl('fill'), true)
  assert.equal(supportsColorControl('select'), false)
  assert.equal(supportsColorControl('eyedropper'), false)
})

test('getActiveToolColor uses text color when text tool is active', () => {
  assert.equal(
    getActiveToolColor({
      activeTool: 'text',
      brushColor: '#000000',
      textColor: '#ff00aa'
    }),
    '#ff00aa'
  )

  assert.equal(
    getActiveToolColor({
      activeTool: 'brush',
      brushColor: '#12ab34',
      textColor: '#ff00aa'
    }),
    '#12ab34'
  )
})

test('getColorControlLabel matches the active tool color target', () => {
  assert.equal(getColorControlLabel('text'), '文字颜色')
  assert.equal(getColorControlLabel('brush'), '颜色')
})

test('getUpdatedToolColors only updates the active tool color target', () => {
  assert.deepEqual(
    getUpdatedToolColors({
      activeTool: 'text',
      nextColor: '#3366ff',
      brushColor: '#000000',
      textColor: '#111111'
    }),
    {
      brushColor: '#000000',
      textColor: '#3366ff'
    }
  )

  assert.deepEqual(
    getUpdatedToolColors({
      activeTool: 'brush',
      nextColor: '#22cc88',
      brushColor: '#000000',
      textColor: '#111111'
    }),
    {
      brushColor: '#22cc88',
      textColor: '#111111'
    }
  )
})

test('createActiveToolColorModel keeps text and brush colors in sync with active tool', () => {
  const activeTool = ref('text')
  const brushColor = ref('#000000')
  const textStyle = reactive({ color: '#111111' })
  const activeToolColor = createActiveToolColorModel({ activeTool, brushColor, textStyle })

  assert.equal(activeToolColor.value, '#111111')

  activeToolColor.value = '#3366ff'
  assert.equal(textStyle.color, '#3366ff')
  assert.equal(brushColor.value, '#000000')

  activeTool.value = 'brush'
  assert.equal(activeToolColor.value, '#000000')

  activeToolColor.value = '#ff5500'
  assert.equal(brushColor.value, '#ff5500')
  assert.equal(textStyle.color, '#3366ff')
})

test('resolveLastColorTool preserves the right return tool for the eyedropper flow', () => {
  assert.equal(
    resolveLastColorTool({
      nextTool: 'eyedropper',
      previousTool: 'text',
      lastColorTool: 'brush'
    }),
    'text'
  )

  assert.equal(
    resolveLastColorTool({
      nextTool: 'eyedropper',
      previousTool: 'select',
      lastColorTool: 'shape'
    }),
    'shape'
  )

  assert.equal(
    resolveLastColorTool({
      nextTool: 'fill',
      previousTool: 'brush',
      lastColorTool: 'brush'
    }),
    'fill'
  )
})

test('resolveBrushStampColor preserves the selected color for drawable tools', () => {
  assert.equal(resolveBrushStampColor('pencil', '#ff5500'), '#ff5500')
  assert.equal(resolveBrushStampColor('brush', '#3366ff'), '#3366ff')
  assert.equal(resolveBrushStampColor('ink', '#18aa55'), '#18aa55')
  assert.equal(resolveBrushStampColor('pen', '#9933ff'), '#9933ff')
  assert.equal(resolveBrushStampColor('eraser', '#9933ff'), '#000000')
})
