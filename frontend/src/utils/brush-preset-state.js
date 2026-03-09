function isHexColor(value) {
  return /^#(?:[\da-fA-F]{3}|[\da-fA-F]{6})$/.test(value.trim())
}

function normalizeHexColor(value) {
  return isHexColor(value) ? value.trim().toLowerCase() : ''
}

export function applyBrushPresetState({ currentColor, currentPresetColor = '', preset }) {
  const normalizedCurrentColor = normalizeHexColor(currentColor)
  const normalizedCurrentPresetColor = normalizeHexColor(currentPresetColor)
  const keepCustomColor = Boolean(normalizedCurrentColor) && (!normalizedCurrentPresetColor || normalizedCurrentColor !== normalizedCurrentPresetColor)
  const nextColor = keepCustomColor ? normalizedCurrentColor : preset.color

  return {
    color: nextColor,
    size: preset.size,
    opacity: preset.opacity,
    style: {
      angle: preset.style.angle,
      roundness: preset.style.roundness,
      spacing: preset.style.spacing,
      hardness: preset.style.hardness,
      flow: preset.style.flow,
      sizeMode: preset.style.sizeMode,
      sizeJitter: preset.style.sizeJitter
    }
  }
}
