package com.drawingboard.canvas.domain;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import java.time.LocalDateTime;
import java.util.Objects;
import java.util.UUID;

@Entity
@Table(name = "canvases")
public class Canvas {

    @Id
    @Column(nullable = false, updatable = false)
    private UUID id;

    @Column(name = "user_id", nullable = false)
    private UUID userId;

    @Column(nullable = false)
    private String title;

    @Column(nullable = false)
    private int width;

    @Column(nullable = false)
    private int height;

    @Column(name = "background_color", nullable = false)
    private String backgroundColor;

    @Column(name = "created_at", nullable = false)
    private LocalDateTime createdAt;

    @Column(name = "updated_at", nullable = false)
    private LocalDateTime updatedAt;

    protected Canvas() {
    }

    private Canvas(UUID id, UUID userId, String title, int width, int height, String backgroundColor) {
        this.id = id;
        this.userId = userId;
        this.title = title;
        this.width = width;
        this.height = height;
        this.backgroundColor = backgroundColor;
        this.createdAt = LocalDateTime.now();
        this.updatedAt = LocalDateTime.now();
    }

    public static Canvas create(UUID userId, String title, int width, int height, String backgroundColor) {
        if (userId == null) {
            throw new IllegalArgumentException("用户ID不能为空");
        }
        validateTitle(title);
        validateSize(width, height);

        String normalizedColor = normalizeBackgroundColor(backgroundColor);
        return new Canvas(UUID.randomUUID(), userId, title, width, height, normalizedColor);
    }

    public void update(String newTitle, String newBackgroundColor) {
        if (newTitle != null && !newTitle.isBlank() && !Objects.equals(newTitle, this.title)) {
            validateTitle(newTitle);
            this.title = newTitle;
            this.updatedAt = LocalDateTime.now();
        }

        if (newBackgroundColor != null && !newBackgroundColor.isBlank()) {
            String normalizedColor = normalizeBackgroundColor(newBackgroundColor);
            if (!Objects.equals(normalizedColor, this.backgroundColor)) {
                this.backgroundColor = normalizedColor;
                this.updatedAt = LocalDateTime.now();
            }
        }
    }

    public UUID getId() {
        return id;
    }

    public UUID getUserId() {
        return userId;
    }

    public String getTitle() {
        return title;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public String getBackgroundColor() {
        return backgroundColor;
    }

    public LocalDateTime getCreatedAt() {
        return createdAt;
    }

    public LocalDateTime getUpdatedAt() {
        return updatedAt;
    }

    private static void validateTitle(String title) {
        if (title == null || title.isBlank()) {
            throw new IllegalArgumentException("画布标题不能为空");
        }
        if (title.length() > 255) {
            throw new IllegalArgumentException("画布标题长度不能超过255");
        }
    }

    private static void validateSize(int width, int height) {
        if (width <= 0 || height <= 0) {
            throw new IllegalArgumentException("画布宽高必须大于0");
        }
        if (width > 8000 || height > 8000) {
            throw new IllegalArgumentException("画布尺寸过大");
        }
    }

    private static String normalizeBackgroundColor(String value) {
        if (value == null || value.isBlank()) {
            return "#ffffff";
        }
        return value;
    }
}
