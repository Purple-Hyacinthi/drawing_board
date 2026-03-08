package com.drawingboard.canvas.api.dto;

import jakarta.validation.constraints.Size;

public record UpdateCanvasRequest(
    @Size(min = 1, max = 255) String title,
    String backgroundColor
) {
}
