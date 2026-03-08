package com.drawingboard.canvas.domain;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;

import java.time.LocalDateTime;
import java.util.UUID;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName("Canvas领域对象")
class CanvasTest {

    @Test
    @DisplayName("创建画布时应设置默认背景色")
    void createCanvasShouldSetDefaultBackgroundColor() {
        Canvas canvas = Canvas.create(UUID.randomUUID(), "My Canvas", 800, 600, null);

        assertThat(canvas.getBackgroundColor()).isEqualTo("#ffffff");
        assertThat(canvas.getCreatedAt()).isBeforeOrEqualTo(LocalDateTime.now());
    }

    @Test
    @DisplayName("创建画布时宽高非法应失败")
    void createCanvasShouldFailWithInvalidSize() {
        assertThatThrownBy(() -> Canvas.create(UUID.randomUUID(), "My Canvas", 0, 600, "#fff"))
            .isInstanceOf(IllegalArgumentException.class)
            .hasMessageContaining("宽高");
    }

    @Test
    @DisplayName("更新标题应刷新更新时间")
    void updateTitleShouldTouchUpdatedAt() throws InterruptedException {
        Canvas canvas = Canvas.create(UUID.randomUUID(), "Old", 800, 600, "#ffffff");
        LocalDateTime oldUpdatedAt = canvas.getUpdatedAt();

        Thread.sleep(2);
        canvas.update("New", null);

        assertThat(canvas.getTitle()).isEqualTo("New");
        assertThat(canvas.getUpdatedAt()).isAfter(oldUpdatedAt);
    }
}
