package com.drawingboard.export.api.dto;

public record ExportImageRequest(
    Double scale,
    Double quality,
    Boolean includeBackground
) {
}
