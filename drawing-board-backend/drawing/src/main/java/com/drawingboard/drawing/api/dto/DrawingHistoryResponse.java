package com.drawingboard.drawing.api.dto;

import java.util.List;

public record DrawingHistoryResponse(List<DrawingHistoryItemResponse> history) {
}
