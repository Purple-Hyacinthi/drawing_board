package com.drawingboard.canvas.api;

import com.drawingboard.canvas.api.dto.CreateCanvasRequest;
import com.drawingboard.canvas.api.dto.CreateLayerRequest;
import com.drawingboard.canvas.api.dto.LayerOrderItem;
import com.drawingboard.canvas.api.dto.UpdateCanvasRequest;
import com.drawingboard.canvas.api.dto.UpdateLayerRequest;
import com.drawingboard.canvas.domain.Canvas;
import com.drawingboard.canvas.domain.Layer;
import com.drawingboard.canvas.internal.CanvasRepository;
import com.drawingboard.canvas.internal.LayerRepository;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.UUID;
import java.util.function.Function;
import java.util.stream.Collectors;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
public class CanvasApplicationService {

    private final CanvasRepository canvasRepository;
    private final LayerRepository layerRepository;

    public CanvasApplicationService(CanvasRepository canvasRepository, LayerRepository layerRepository) {
        this.canvasRepository = canvasRepository;
        this.layerRepository = layerRepository;
    }

    @Transactional
    public Canvas createCanvas(UUID userId, CreateCanvasRequest request) {
        Canvas canvas = Canvas.create(
            userId,
            request.title(),
            request.width(),
            request.height(),
            request.backgroundColor()
        );
        Canvas savedCanvas = canvasRepository.save(canvas);

        Layer background = Layer.create(savedCanvas.getId(), "Background", 0);
        layerRepository.save(background);
        return savedCanvas;
    }

    @Transactional(readOnly = true)
    public Page<Canvas> listCanvases(UUID userId, int page, int size, String sort) {
        Sort sortOrder = resolveSort(sort);
        Pageable pageable = PageRequest.of(page, size, sortOrder);
        return canvasRepository.findByUserId(userId, pageable);
    }

    @Transactional(readOnly = true)
    public Canvas getOwnedCanvas(UUID userId, UUID canvasId) {
        Canvas canvas = canvasRepository.findById(canvasId)
            .orElseThrow(() -> new CanvasNotFoundException("画布不存在"));

        if (!canvas.getUserId().equals(userId)) {
            throw new CanvasPermissionDeniedException("无权限访问该画布");
        }

        return canvas;
    }

    @Transactional
    public Canvas updateCanvas(UUID userId, UUID canvasId, UpdateCanvasRequest request) {
        Canvas canvas = getOwnedCanvas(userId, canvasId);
        canvas.update(request.title(), request.backgroundColor());
        return canvas;
    }

    @Transactional
    public void deleteCanvas(UUID userId, UUID canvasId) {
        Canvas canvas = getOwnedCanvas(userId, canvasId);
        List<Layer> layers = layerRepository.findByCanvasIdOrderByZIndexAsc(canvas.getId());
        layerRepository.deleteAllInBatch(layers);
        canvasRepository.delete(canvas);
    }

    @Transactional(readOnly = true)
    public List<Layer> listLayers(UUID userId, UUID canvasId) {
        getOwnedCanvas(userId, canvasId);
        return layerRepository.findByCanvasIdOrderByZIndexAsc(canvasId);
    }

    @Transactional
    public Layer createLayer(UUID userId, UUID canvasId, CreateLayerRequest request) {
        getOwnedCanvas(userId, canvasId);
        List<Layer> existingLayers = layerRepository.findByCanvasIdOrderByZIndexAsc(canvasId);

        int zIndex = request.zIndex() == null ? existingLayers.size() : request.zIndex();
        Layer layer = Layer.create(canvasId, request.name(), zIndex);
        return layerRepository.save(layer);
    }

    @Transactional
    public Layer updateLayer(UUID userId, UUID canvasId, UUID layerId, UpdateLayerRequest request) {
        getOwnedCanvas(userId, canvasId);
        Layer layer = layerRepository.findByIdAndCanvasId(layerId, canvasId)
            .orElseThrow(() -> new LayerNotFoundException("图层不存在"));

        layer.update(request.name(), request.zIndex(), request.visible(), request.locked());
        return layer;
    }

    @Transactional
    public void deleteLayer(UUID userId, UUID canvasId, UUID layerId) {
        getOwnedCanvas(userId, canvasId);
        Layer layer = layerRepository.findByIdAndCanvasId(layerId, canvasId)
            .orElseThrow(() -> new LayerNotFoundException("图层不存在"));
        layerRepository.delete(layer);
    }

    @Transactional
    public List<Layer> reorderLayers(UUID userId, UUID canvasId, List<LayerOrderItem> layerOrders) {
        getOwnedCanvas(userId, canvasId);
        List<Layer> layers = layerRepository.findByCanvasIdOrderByZIndexAsc(canvasId);
        Map<UUID, Layer> layerMap = layers.stream().collect(Collectors.toMap(Layer::getId, Function.identity()));

        for (LayerOrderItem orderItem : layerOrders) {
            Layer layer = layerMap.get(orderItem.layerId());
            if (layer == null) {
                throw new LayerNotFoundException("图层不存在: " + orderItem.layerId());
            }
            layer.update(null, orderItem.zIndex(), null, null);
        }

        return layerMap.values().stream().sorted(Comparator.comparingInt(Layer::getZIndex)).toList();
    }

    @Transactional
    public Layer updateLayerDrawingData(UUID userId, UUID canvasId, UUID layerId, String drawingData) {
        getOwnedCanvas(userId, canvasId);
        Layer layer = layerRepository.findByIdAndCanvasId(layerId, canvasId)
            .orElseThrow(() -> new LayerNotFoundException("图层不存在"));
        layer.setDrawingData(drawingData);
        return layer;
    }

    @Transactional(readOnly = true)
    public List<LayerSnapshot> snapshotLayers(UUID userId, UUID canvasId) {
        List<Layer> layers = listLayers(userId, canvasId);
        List<LayerSnapshot> snapshots = new ArrayList<>();
        for (Layer layer : layers) {
            snapshots.add(toSnapshot(layer));
        }
        return snapshots;
    }

    @Transactional
    public void restoreLayers(UUID userId, UUID canvasId, List<LayerSnapshot> snapshots) {
        getOwnedCanvas(userId, canvasId);
        List<Layer> layers = layerRepository.findByCanvasIdOrderByZIndexAsc(canvasId);
        Map<UUID, Layer> layerMap = layers.stream().collect(Collectors.toMap(Layer::getId, Function.identity()));

        for (LayerSnapshot snapshot : snapshots) {
            Layer layer = layerMap.get(snapshot.id());
            if (layer == null) {
                continue;
            }
            layer.update(snapshot.name(), snapshot.zIndex(), snapshot.visible(), snapshot.locked());
            layer.setDrawingData(snapshot.drawingData());
        }
    }

    private LayerSnapshot toSnapshot(Layer layer) {
        return new LayerSnapshot(
            layer.getId(),
            layer.getCanvasId(),
            layer.getName(),
            layer.getZIndex(),
            layer.isVisible(),
            layer.isLocked(),
            layer.getDrawingData()
        );
    }

    private Sort resolveSort(String sort) {
        if (sort == null || sort.isBlank()) {
            return Sort.by(Sort.Direction.DESC, "updatedAt");
        }

        String[] segments = sort.split(",");
        String field = segments[0];
        Sort.Direction direction = segments.length > 1 && "asc".equalsIgnoreCase(segments[1])
            ? Sort.Direction.ASC
            : Sort.Direction.DESC;
        return Sort.by(direction, field);
    }
}
