package com.drawingboard.canvas.api.dto;

import jakarta.validation.constraints.Size;

public record UpdateLayerRequest(
    @Size(min = 1, max = 100) String name,
    Integer zIndex,
    Boolean visible,
    Boolean locked
) {
}
