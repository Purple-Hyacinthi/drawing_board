package com.drawingboard.canvas.api.dto;

import java.time.LocalDateTime;
import java.util.List;
import java.util.UUID;

public record CanvasResponse(
    UUID id,
    String title,
    int width,
    int height,
    String backgroundColor,
    LocalDateTime createdAt,
    LocalDateTime updatedAt,
    List<LayerResponse> layers
) {
}
