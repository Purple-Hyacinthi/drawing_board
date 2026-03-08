package com.drawingboard.canvas.api;

import java.util.UUID;

public record LayerSnapshot(
    UUID id,
    UUID canvasId,
    String name,
    int zIndex,
    boolean visible,
    boolean locked,
    String drawingData
) {
}
