export interface BrushPresetStyleState {
  angle: number
  roundness: number
  spacing: number
  hardness: number
  flow: number
  sizeMode: 'fixed' | 'random' | 'pressure'
  sizeJitter: number
}

export interface BrushPresetStateInput {
  currentColor: string
  currentPresetColor?: string
  preset: {
    color: string
    size: number
    opacity: number
    style: BrushPresetStyleState
  }
}

export interface BrushPresetStateResult {
  color: string
  size: number
  opacity: number
  style: BrushPresetStyleState
}

export function applyBrushPresetState(input: BrushPresetStateInput): BrushPresetStateResult
