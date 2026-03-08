package com.drawingboard.drawing.api.dto;

import com.fasterxml.jackson.databind.JsonNode;
import jakarta.validation.constraints.NotBlank;

public record DrawingOperationRequest(
    @NotBlank String type,
    JsonNode properties,
    String pathData
) {
}
