package com.drawingboard.drawing.api;

import com.drawingboard.drawing.api.dto.DrawingHistoryResponse;
import com.drawingboard.drawing.api.dto.DrawingOperationRequest;
import com.drawingboard.user.internal.AuthenticatedUser;
import jakarta.validation.Valid;
import java.util.Map;
import java.util.UUID;
import org.springframework.http.HttpStatus;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/v1/canvases")
public class DrawingController {

    private final DrawingApplicationService drawingApplicationService;

    public DrawingController(DrawingApplicationService drawingApplicationService) {
        this.drawingApplicationService = drawingApplicationService;
    }

    @PostMapping("/{canvasId}/layers/{layerId}/drawing")
    @ResponseStatus(HttpStatus.CREATED)
    public Map<String, Object> saveDrawing(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId,
        @PathVariable UUID layerId,
        @Valid @RequestBody DrawingOperationRequest request
    ) {
        String drawingData = drawingApplicationService.saveOperation(
            authenticatedUser.userId(),
            canvasId,
            layerId,
            request
        );
        return Map.of(
            "canvasId", canvasId,
            "layerId", layerId,
            "drawingData", drawingData
        );
    }

    @GetMapping("/{canvasId}/history")
    public DrawingHistoryResponse getHistory(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId,
        @RequestParam(defaultValue = "50") int limit
    ) {
        return drawingApplicationService.getHistory(authenticatedUser.userId(), canvasId, limit);
    }

    @PostMapping("/{canvasId}/undo")
    public Map<String, Object> undo(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId
    ) {
        boolean done = drawingApplicationService.undo(authenticatedUser.userId(), canvasId);
        return Map.of("canvasId", canvasId, "undone", done);
    }

    @PostMapping("/{canvasId}/redo")
    public Map<String, Object> redo(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId
    ) {
        boolean done = drawingApplicationService.redo(authenticatedUser.userId(), canvasId);
        return Map.of("canvasId", canvasId, "redone", done);
    }
}
