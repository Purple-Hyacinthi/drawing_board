import { defineStore } from 'pinia'
import { ref, computed } from 'vue'

export interface Canvas {
  id: string
  title: string
  width: number
  height: number
  createdAt: Date
  updatedAt: Date
}

export type DrawingToolType = 'brush' | 'pencil' | 'eraser' | 'rectangle' | 'circle' | 'line'

export interface DrawingTool {
  type: 'brush' | 'pencil' | 'eraser' | 'rectangle' | 'circle' | 'line'
  color: string
  size: number
}

export interface HistoryEntry {
  dataUrl: string
  createdAt: number
}

export const useCanvasStore = defineStore('canvas', () => {
  // 当前画布
  const currentCanvas = ref<Canvas | null>(null)
  
  // 画布列表
  const canvases = ref<Canvas[]>([])
  
  // 当前工具
  const currentTool = ref<DrawingTool>({
    type: 'brush',
    color: '#3b82f6',
    size: 5
  })

  // 操作历史
  const history = ref<HistoryEntry[]>([])
  const historyIndex = ref(-1)
  const maxHistoryLength = 50

  // 计算属性
  const canUndo = computed(() => historyIndex.value > 0)
  const canRedo = computed(() => historyIndex.value < history.value.length - 1)
  
  // 动作
  function createCanvas(title: string, width: number, height: number) {
    const canvas: Canvas = {
      id: crypto.randomUUID(),
      title,
      width,
      height,
      createdAt: new Date(),
      updatedAt: new Date()
    }
    
    canvases.value.push(canvas)
    currentCanvas.value = canvas
    
    return canvas
  }
  
  function updateCanvas(id: string, updates: Partial<Canvas>) {
    const canvas = canvases.value.find(c => c.id === id)
    if (canvas) {
      Object.assign(canvas, updates, { updatedAt: new Date() })
    }
  }
  
  function setTool(tool: Partial<DrawingTool>) {
    Object.assign(currentTool.value, tool)
  }

  function setToolType(type: DrawingToolType) {
    currentTool.value.type = type
  }

  function addSnapshot(dataUrl: string) {
    if (!dataUrl) {
      return
    }

    // 如果不在历史记录末尾，移除后面的记录
    if (historyIndex.value < history.value.length - 1) {
      history.value = history.value.slice(0, historyIndex.value + 1)
    }

    history.value.push({
      dataUrl,
      createdAt: Date.now()
    })

    if (history.value.length > maxHistoryLength) {
      history.value.shift()
    }

    historyIndex.value = history.value.length - 1
  }

  function getUndoSnapshot() {
    if (canUndo.value) {
      historyIndex.value--
      return history.value[historyIndex.value]?.dataUrl ?? null
    }

    return null
  }

  function getRedoSnapshot() {
    if (canRedo.value) {
      historyIndex.value++
      return history.value[historyIndex.value]?.dataUrl ?? null
    }

    return null
  }

  function clearHistory() {
    history.value = []
    historyIndex.value = -1
  }

  return {
    currentCanvas,
    canvases,
    currentTool,
    history,
    canUndo,
    canRedo,
    
    createCanvas,
    updateCanvas,
    setTool,
    setToolType,
    addSnapshot,
    getUndoSnapshot,
    getRedoSnapshot,
    clearHistory
  }
})
