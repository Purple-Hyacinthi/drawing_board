package com.drawingboard.drawing.api;

import com.drawingboard.canvas.api.CanvasApplicationService;
import com.drawingboard.canvas.api.LayerSnapshot;
import com.drawingboard.canvas.domain.Layer;
import com.drawingboard.drawing.api.dto.DrawingHistoryItemResponse;
import com.drawingboard.drawing.api.dto.DrawingHistoryResponse;
import com.drawingboard.drawing.api.dto.DrawingOperationRequest;
import com.drawingboard.drawing.domain.CanvasVersion;
import com.drawingboard.drawing.internal.CanvasVersionRepository;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.node.ArrayNode;
import com.fasterxml.jackson.databind.node.ObjectNode;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.Map;
import java.util.UUID;
import java.util.concurrent.ConcurrentHashMap;
import org.springframework.data.domain.PageRequest;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
public class DrawingApplicationService {

    private static final TypeReference<List<LayerSnapshot>> LAYER_SNAPSHOT_TYPE = new TypeReference<>() {
    };

    private final CanvasApplicationService canvasApplicationService;
    private final CanvasVersionRepository canvasVersionRepository;
    private final ObjectMapper objectMapper;

    private final Map<UUID, Deque<String>> redoStacks = new ConcurrentHashMap<>();

    public DrawingApplicationService(
        CanvasApplicationService canvasApplicationService,
        CanvasVersionRepository canvasVersionRepository,
        ObjectMapper objectMapper
    ) {
        this.canvasApplicationService = canvasApplicationService;
        this.canvasVersionRepository = canvasVersionRepository;
        this.objectMapper = objectMapper;
    }

    @Transactional
    public String saveOperation(UUID userId, UUID canvasId, UUID layerId, DrawingOperationRequest request) {
        Layer layer = canvasApplicationService.listLayers(userId, canvasId)
            .stream()
            .filter(item -> item.getId().equals(layerId))
            .findFirst()
            .orElseThrow(() -> new IllegalArgumentException("图层不存在"));

        String currentDrawingData = layer.getDrawingData();
        String mergedDrawingData = appendOperation(currentDrawingData, request);
        canvasApplicationService.updateLayerDrawingData(userId, canvasId, layerId, mergedDrawingData);

        persistSnapshot(userId, canvasId);
        redoStacks.remove(canvasId);

        return mergedDrawingData;
    }

    @Transactional(readOnly = true)
    public DrawingHistoryResponse getHistory(UUID userId, UUID canvasId, int limit) {
        canvasApplicationService.getOwnedCanvas(userId, canvasId);
        int boundedLimit = Math.max(1, Math.min(limit, 200));
        List<CanvasVersion> versions = canvasVersionRepository.findByCanvasIdOrderByCreatedAtDesc(
            canvasId,
            PageRequest.of(0, boundedLimit)
        );

        List<DrawingHistoryItemResponse> items = new ArrayList<>();
        for (CanvasVersion version : versions) {
            items.add(new DrawingHistoryItemResponse(
                version.getId(),
                "draw",
                "画布快照",
                version.getCreatedAt(),
                version.getSnapshotData()
            ));
        }
        return new DrawingHistoryResponse(items);
    }

    @Transactional
    public boolean undo(UUID userId, UUID canvasId) {
        List<CanvasVersion> versions = canvasVersionRepository.findByCanvasIdOrderByCreatedAtDesc(canvasId);
        if (versions.size() < 2) {
            return false;
        }

        CanvasVersion current = versions.get(0);
        CanvasVersion previous = versions.get(1);
        redoStacks.computeIfAbsent(canvasId, id -> new ArrayDeque<>()).push(current.getSnapshotData());

        restoreSnapshot(userId, canvasId, previous.getSnapshotData());
        canvasVersionRepository.save(CanvasVersion.create(canvasId, previous.getSnapshotData()));
        return true;
    }

    @Transactional
    public boolean redo(UUID userId, UUID canvasId) {
        Deque<String> redoStack = redoStacks.computeIfAbsent(canvasId, id -> new ArrayDeque<>());
        if (redoStack.isEmpty()) {
            return false;
        }
        String snapshotData = redoStack.pop();

        restoreSnapshot(userId, canvasId, snapshotData);
        canvasVersionRepository.save(CanvasVersion.create(canvasId, snapshotData));
        return true;
    }

    @Transactional
    public void initializeHistory(UUID userId, UUID canvasId) {
        List<CanvasVersion> versions = canvasVersionRepository.findByCanvasIdOrderByCreatedAtDesc(canvasId);
        if (!versions.isEmpty()) {
            return;
        }
        persistSnapshot(userId, canvasId);
    }

    private String appendOperation(String currentDrawingData, DrawingOperationRequest request) {
        try {
            JsonNode root;
            if (currentDrawingData == null || currentDrawingData.isBlank()) {
                root = objectMapper.createObjectNode();
            } else {
                root = objectMapper.readTree(currentDrawingData);
            }

            ObjectNode rootObject;
            if (root.isObject()) {
                rootObject = (ObjectNode) root;
            } else {
                rootObject = objectMapper.createObjectNode();
            }

            ArrayNode operations = rootObject.withArray("operations");
            ObjectNode operationNode = objectMapper.createObjectNode();
            operationNode.put("type", request.type());
            if (request.properties() != null) {
                operationNode.set("properties", request.properties());
            } else {
                operationNode.set("properties", objectMapper.createObjectNode());
            }
            if (request.pathData() != null) {
                operationNode.put("pathData", request.pathData());
            }
            operations.add(operationNode);
            return objectMapper.writeValueAsString(rootObject);
        } catch (JsonProcessingException exception) {
            throw new IllegalArgumentException("绘图数据序列化失败", exception);
        }
    }

    private void persistSnapshot(UUID userId, UUID canvasId) {
        try {
            List<LayerSnapshot> snapshots = canvasApplicationService.snapshotLayers(userId, canvasId);
            String snapshotData = objectMapper.writeValueAsString(snapshots);
            canvasVersionRepository.save(CanvasVersion.create(canvasId, snapshotData));
        } catch (JsonProcessingException exception) {
            throw new IllegalStateException("快照序列化失败", exception);
        }
    }

    private void restoreSnapshot(UUID userId, UUID canvasId, String snapshotData) {
        try {
            List<LayerSnapshot> snapshots = objectMapper.readValue(snapshotData, LAYER_SNAPSHOT_TYPE);
            canvasApplicationService.restoreLayers(userId, canvasId, snapshots);
        } catch (JsonProcessingException exception) {
            throw new IllegalStateException("快照反序列化失败", exception);
        }
    }
}
