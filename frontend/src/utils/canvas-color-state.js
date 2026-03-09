import { computed } from 'vue'

const COLOR_TOOLS = new Set(['brush', 'pencil', 'ink', 'pen', 'shape', 'fill', 'text'])

export function supportsColorControl(activeTool) {
  return COLOR_TOOLS.has(activeTool)
}

export function getActiveToolColor({ activeTool, brushColor, textColor }) {
  return activeTool === 'text' ? textColor : brushColor
}

export function getColorControlLabel(activeTool) {
  return activeTool === 'text' ? '文字颜色' : '颜色'
}

export function getUpdatedToolColors({ activeTool, nextColor, brushColor, textColor }) {
  if (activeTool === 'text') {
    return {
      brushColor,
      textColor: nextColor
    }
  }

  return {
    brushColor: nextColor,
    textColor
  }
}

export function resolveBrushStampColor(tool, selectedColor) {
  return tool === 'eraser' ? '#000000' : selectedColor
}

export function resolveLastColorTool({ nextTool, previousTool, lastColorTool }) {
  if (nextTool === 'eyedropper') {
    return supportsColorControl(previousTool) ? previousTool : lastColorTool
  }

  return supportsColorControl(nextTool) ? nextTool : lastColorTool
}

export function createActiveToolColorModel({ activeTool, brushColor, textStyle }) {
  return computed({
    get: () =>
      getActiveToolColor({
        activeTool: activeTool.value,
        brushColor: brushColor.value,
        textColor: textStyle.color
      }),
    set: (nextColor) => {
      const nextColors = getUpdatedToolColors({
        activeTool: activeTool.value,
        nextColor,
        brushColor: brushColor.value,
        textColor: textStyle.color
      })

      brushColor.value = nextColors.brushColor
      textStyle.color = nextColors.textColor
    }
  })
}
