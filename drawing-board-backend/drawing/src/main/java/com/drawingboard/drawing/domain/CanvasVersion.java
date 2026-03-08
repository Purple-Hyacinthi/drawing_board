package com.drawingboard.drawing.domain;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import java.time.LocalDateTime;
import java.util.UUID;

@Entity
@Table(name = "canvas_versions")
public class CanvasVersion {

    @Id
    @Column(nullable = false, updatable = false)
    private UUID id;

    @Column(name = "canvas_id", nullable = false)
    private UUID canvasId;

    @Column(name = "snapshot_data", nullable = false, columnDefinition = "jsonb")
    private String snapshotData;

    @Column(name = "created_at", nullable = false)
    private LocalDateTime createdAt;

    protected CanvasVersion() {
    }

    private CanvasVersion(UUID id, UUID canvasId, String snapshotData) {
        this.id = id;
        this.canvasId = canvasId;
        this.snapshotData = snapshotData;
        this.createdAt = LocalDateTime.now();
    }

    public static CanvasVersion create(UUID canvasId, String snapshotData) {
        if (canvasId == null) {
            throw new IllegalArgumentException("画布ID不能为空");
        }
        if (snapshotData == null || snapshotData.isBlank()) {
            throw new IllegalArgumentException("快照数据不能为空");
        }
        return new CanvasVersion(UUID.randomUUID(), canvasId, snapshotData);
    }

    public UUID getId() {
        return id;
    }

    public UUID getCanvasId() {
        return canvasId;
    }

    public String getSnapshotData() {
        return snapshotData;
    }

    public LocalDateTime getCreatedAt() {
        return createdAt;
    }
}
