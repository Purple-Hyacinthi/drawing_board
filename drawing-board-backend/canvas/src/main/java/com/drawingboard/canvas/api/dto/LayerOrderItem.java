package com.drawingboard.canvas.api.dto;

import jakarta.validation.constraints.NotNull;
import java.util.UUID;

public record LayerOrderItem(@NotNull UUID layerId, @NotNull Integer zIndex) {
}
