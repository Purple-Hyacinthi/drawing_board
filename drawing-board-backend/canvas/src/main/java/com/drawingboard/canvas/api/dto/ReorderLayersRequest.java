package com.drawingboard.canvas.api.dto;

import jakarta.validation.Valid;
import jakarta.validation.constraints.NotEmpty;
import java.util.List;

public record ReorderLayersRequest(
    @NotEmpty List<@Valid LayerOrderItem> layerOrders
) {
}
