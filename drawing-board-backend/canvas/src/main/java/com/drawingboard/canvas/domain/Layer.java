package com.drawingboard.canvas.domain;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import java.time.LocalDateTime;
import java.util.Objects;
import java.util.UUID;

@Entity
@Table(name = "layers")
public class Layer {

    @Id
    @Column(nullable = false, updatable = false)
    private UUID id;

    @Column(name = "canvas_id", nullable = false)
    private UUID canvasId;

    @Column(nullable = false)
    private String name;

    @Column(name = "z_index", nullable = false)
    private int zIndex;

    @Column(nullable = false)
    private boolean visible;

    @Column(nullable = false)
    private boolean locked;

    @Column(name = "drawing_data", columnDefinition = "jsonb")
    private String drawingData;

    @Column(name = "created_at", nullable = false)
    private LocalDateTime createdAt;

    @Column(name = "updated_at", nullable = false)
    private LocalDateTime updatedAt;

    protected Layer() {
    }

    private Layer(UUID id, UUID canvasId, String name, int zIndex) {
        this.id = id;
        this.canvasId = canvasId;
        this.name = name;
        this.zIndex = zIndex;
        this.visible = true;
        this.locked = false;
        this.drawingData = "{\"operations\":[]}";
        this.createdAt = LocalDateTime.now();
        this.updatedAt = LocalDateTime.now();
    }

    public static Layer create(UUID canvasId, String name, int zIndex) {
        if (canvasId == null) {
            throw new IllegalArgumentException("画布ID不能为空");
        }
        if (name == null || name.isBlank()) {
            throw new IllegalArgumentException("图层名称不能为空");
        }
        if (name.length() > 100) {
            throw new IllegalArgumentException("图层名称长度不能超过100");
        }
        return new Layer(UUID.randomUUID(), canvasId, name, zIndex);
    }

    public void update(String name, Integer zIndex, Boolean visible, Boolean locked) {
        boolean changed = false;
        if (name != null && !name.isBlank() && !Objects.equals(name, this.name)) {
            if (name.length() > 100) {
                throw new IllegalArgumentException("图层名称长度不能超过100");
            }
            this.name = name;
            changed = true;
        }
        if (zIndex != null && zIndex != this.zIndex) {
            this.zIndex = zIndex;
            changed = true;
        }
        if (visible != null && visible != this.visible) {
            this.visible = visible;
            changed = true;
        }
        if (locked != null && locked != this.locked) {
            this.locked = locked;
            changed = true;
        }
        if (changed) {
            this.updatedAt = LocalDateTime.now();
        }
    }

    public void setDrawingData(String drawingData) {
        this.drawingData = drawingData == null ? "{\"operations\":[]}" : drawingData;
        this.updatedAt = LocalDateTime.now();
    }

    public UUID getId() {
        return id;
    }

    public UUID getCanvasId() {
        return canvasId;
    }

    public String getName() {
        return name;
    }

    public int getZIndex() {
        return zIndex;
    }

    public boolean isVisible() {
        return visible;
    }

    public boolean isLocked() {
        return locked;
    }

    public String getDrawingData() {
        return drawingData;
    }

    public LocalDateTime getCreatedAt() {
        return createdAt;
    }

    public LocalDateTime getUpdatedAt() {
        return updatedAt;
    }
}
