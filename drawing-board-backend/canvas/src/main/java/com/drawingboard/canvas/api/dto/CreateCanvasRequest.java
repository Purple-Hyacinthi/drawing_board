package com.drawingboard.canvas.api.dto;

import jakarta.validation.constraints.Max;
import jakarta.validation.constraints.Min;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Size;

public record CreateCanvasRequest(
    @NotBlank @Size(min = 1, max = 255) String title,
    @Min(1) @Max(8000) int width,
    @Min(1) @Max(8000) int height,
    String backgroundColor
) {
}
