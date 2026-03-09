import type { Ref, WritableComputedRef } from 'vue'

export type CanvasToolId = 'select' | 'brush' | 'pencil' | 'ink' | 'pen' | 'eraser' | 'eyedropper' | 'lasso' | 'fill' | 'shape' | 'text'

export function supportsColorControl(activeTool: CanvasToolId | string): boolean

export function getActiveToolColor(options: {
  activeTool: CanvasToolId | string
  brushColor: string
  textColor: string
}): string

export function getColorControlLabel(activeTool: CanvasToolId | string): string

export function getUpdatedToolColors(options: {
  activeTool: CanvasToolId | string
  nextColor: string
  brushColor: string
  textColor: string
}): {
  brushColor: string
  textColor: string
}

export function resolveBrushStampColor(tool: CanvasToolId | string, selectedColor: string): string

export function resolveLastColorTool(options: {
  nextTool: CanvasToolId
  previousTool: CanvasToolId
  lastColorTool: CanvasToolId
}): CanvasToolId

export function createActiveToolColorModel(options: {
  activeTool: Ref<CanvasToolId>
  brushColor: Ref<string>
  textStyle: { color: string }
}): WritableComputedRef<string>
