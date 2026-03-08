package com.drawingboard.canvas.domain;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;

import java.util.UUID;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName("Layer领域对象")
class LayerTest {

    @Test
    @DisplayName("创建图层时默认可见且未锁定")
    void createLayerShouldUseDefaultFlags() {
        Layer layer = Layer.create(UUID.randomUUID(), "Layer 1", 0);

        assertThat(layer.isVisible()).isTrue();
        assertThat(layer.isLocked()).isFalse();
        assertThat(layer.getDrawingData()).contains("operations");
    }

    @Test
    @DisplayName("创建图层名称为空应失败")
    void createLayerShouldFailWithBlankName() {
        assertThatThrownBy(() -> Layer.create(UUID.randomUUID(), " ", 0))
            .isInstanceOf(IllegalArgumentException.class)
            .hasMessageContaining("图层名称");
    }
}
