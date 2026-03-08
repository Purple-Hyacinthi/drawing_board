package com.drawingboard.drawing.api.dto;

import java.time.LocalDateTime;
import java.util.UUID;

public record DrawingHistoryItemResponse(
    UUID id,
    String type,
    String description,
    LocalDateTime timestamp,
    String data
) {
}
