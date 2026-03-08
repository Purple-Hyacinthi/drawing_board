package com.drawingboard.canvas.api;

import com.drawingboard.canvas.api.dto.CanvasListResponse;
import com.drawingboard.canvas.api.dto.CanvasResponse;
import com.drawingboard.canvas.api.dto.CreateCanvasRequest;
import com.drawingboard.canvas.api.dto.CreateLayerRequest;
import com.drawingboard.canvas.api.dto.LayerResponse;
import com.drawingboard.canvas.api.dto.PageMeta;
import com.drawingboard.canvas.api.dto.ReorderLayersRequest;
import com.drawingboard.canvas.api.dto.UpdateCanvasRequest;
import com.drawingboard.canvas.api.dto.UpdateLayerRequest;
import com.drawingboard.canvas.domain.Canvas;
import com.drawingboard.canvas.domain.Layer;
import com.drawingboard.user.internal.AuthenticatedUser;
import jakarta.validation.Valid;
import java.util.List;
import java.util.UUID;
import org.springframework.data.domain.Page;
import org.springframework.http.HttpStatus;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/v1/canvases")
public class CanvasController {

    private final CanvasApplicationService canvasApplicationService;

    public CanvasController(CanvasApplicationService canvasApplicationService) {
        this.canvasApplicationService = canvasApplicationService;
    }

    @GetMapping
    public CanvasListResponse listCanvases(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @RequestParam(defaultValue = "0") int page,
        @RequestParam(defaultValue = "20") int size,
        @RequestParam(required = false) String sort
    ) {
        Page<Canvas> result = canvasApplicationService.listCanvases(authenticatedUser.userId(), page, size, sort);
        List<CanvasResponse> content = result.getContent().stream().map(this::toCanvasSummaryResponse).toList();
        PageMeta pageMeta = new PageMeta(
            result.getNumber(),
            result.getSize(),
            result.getTotalElements(),
            result.getTotalPages()
        );
        return new CanvasListResponse(content, pageMeta);
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public CanvasResponse createCanvas(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @Valid @RequestBody CreateCanvasRequest request
    ) {
        Canvas canvas = canvasApplicationService.createCanvas(authenticatedUser.userId(), request);
        List<Layer> layers = canvasApplicationService.listLayers(authenticatedUser.userId(), canvas.getId());
        return toCanvasResponse(canvas, layers);
    }

    @GetMapping("/{canvasId}")
    public CanvasResponse getCanvas(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId
    ) {
        Canvas canvas = canvasApplicationService.getOwnedCanvas(authenticatedUser.userId(), canvasId);
        List<Layer> layers = canvasApplicationService.listLayers(authenticatedUser.userId(), canvasId);
        return toCanvasResponse(canvas, layers);
    }

    @PutMapping("/{canvasId}")
    public CanvasResponse updateCanvas(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId,
        @Valid @RequestBody UpdateCanvasRequest request
    ) {
        Canvas canvas = canvasApplicationService.updateCanvas(authenticatedUser.userId(), canvasId, request);
        List<Layer> layers = canvasApplicationService.listLayers(authenticatedUser.userId(), canvasId);
        return toCanvasResponse(canvas, layers);
    }

    @DeleteMapping("/{canvasId}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void deleteCanvas(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId
    ) {
        canvasApplicationService.deleteCanvas(authenticatedUser.userId(), canvasId);
    }

    @PostMapping("/{canvasId}/layers")
    @ResponseStatus(HttpStatus.CREATED)
    public LayerResponse createLayer(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId,
        @Valid @RequestBody CreateLayerRequest request
    ) {
        Layer layer = canvasApplicationService.createLayer(authenticatedUser.userId(), canvasId, request);
        return toLayerResponse(layer);
    }

    @PutMapping("/{canvasId}/layers/{layerId}")
    public LayerResponse updateLayer(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId,
        @PathVariable UUID layerId,
        @Valid @RequestBody UpdateLayerRequest request
    ) {
        Layer layer = canvasApplicationService.updateLayer(authenticatedUser.userId(), canvasId, layerId, request);
        return toLayerResponse(layer);
    }

    @DeleteMapping("/{canvasId}/layers/{layerId}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void deleteLayer(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId,
        @PathVariable UUID layerId
    ) {
        canvasApplicationService.deleteLayer(authenticatedUser.userId(), canvasId, layerId);
    }

    @PatchMapping("/{canvasId}/layers/order")
    public List<LayerResponse> reorderLayers(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId,
        @Valid @RequestBody ReorderLayersRequest request
    ) {
        List<Layer> layers = canvasApplicationService.reorderLayers(
            authenticatedUser.userId(),
            canvasId,
            request.layerOrders()
        );
        return layers.stream().map(this::toLayerResponse).toList();
    }

    private CanvasResponse toCanvasSummaryResponse(Canvas canvas) {
        return new CanvasResponse(
            canvas.getId(),
            canvas.getTitle(),
            canvas.getWidth(),
            canvas.getHeight(),
            canvas.getBackgroundColor(),
            canvas.getCreatedAt(),
            canvas.getUpdatedAt(),
            List.of()
        );
    }

    private CanvasResponse toCanvasResponse(Canvas canvas, List<Layer> layers) {
        List<LayerResponse> layerResponses = layers.stream().map(this::toLayerResponse).toList();
        return new CanvasResponse(
            canvas.getId(),
            canvas.getTitle(),
            canvas.getWidth(),
            canvas.getHeight(),
            canvas.getBackgroundColor(),
            canvas.getCreatedAt(),
            canvas.getUpdatedAt(),
            layerResponses
        );
    }

    private LayerResponse toLayerResponse(Layer layer) {
        return new LayerResponse(
            layer.getId(),
            layer.getName(),
            layer.getZIndex(),
            layer.isVisible(),
            layer.isLocked(),
            layer.getDrawingData(),
            layer.getCreatedAt(),
            layer.getUpdatedAt()
        );
    }
}
