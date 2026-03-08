package com.drawingboard.canvas.api.dto;

import java.time.LocalDateTime;
import java.util.UUID;

public record LayerResponse(
    UUID id,
    String name,
    int zIndex,
    boolean visible,
    boolean locked,
    String drawingData,
    LocalDateTime createdAt,
    LocalDateTime updatedAt
) {
}
