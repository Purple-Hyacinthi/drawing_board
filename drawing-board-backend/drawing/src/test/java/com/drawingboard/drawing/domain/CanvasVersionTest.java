package com.drawingboard.drawing.domain;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;

import java.util.UUID;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName("CanvasVersion领域对象")
class CanvasVersionTest {

    @Test
    @DisplayName("创建快照应成功")
    void createVersionShouldSucceed() {
        CanvasVersion version = CanvasVersion.create(UUID.randomUUID(), "[]");

        assertThat(version.getId()).isNotNull();
        assertThat(version.getSnapshotData()).isEqualTo("[]");
    }

    @Test
    @DisplayName("空快照应失败")
    void createVersionShouldFailWhenSnapshotBlank() {
        assertThatThrownBy(() -> CanvasVersion.create(UUID.randomUUID(), " "))
            .isInstanceOf(IllegalArgumentException.class)
            .hasMessageContaining("快照");
    }
}
