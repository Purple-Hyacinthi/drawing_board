package com.drawingboard.canvas.api.dto;

import java.util.List;

public record CanvasListResponse(List<CanvasResponse> content, PageMeta page) {
}
