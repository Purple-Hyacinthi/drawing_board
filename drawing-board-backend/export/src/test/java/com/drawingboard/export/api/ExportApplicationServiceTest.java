package com.drawingboard.export.api;

import static org.assertj.core.api.Assertions.assertThat;
import static org.mockito.Mockito.when;

import com.drawingboard.canvas.api.CanvasApplicationService;
import com.drawingboard.canvas.domain.Canvas;
import com.drawingboard.canvas.domain.Layer;
import java.lang.reflect.Constructor;
import java.util.List;
import java.util.UUID;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

@ExtendWith(MockitoExtension.class)
@DisplayName("ExportApplicationService")
class ExportApplicationServiceTest {

    @Mock
    private CanvasApplicationService canvasApplicationService;

    private ExportApplicationService exportApplicationService;

    @BeforeEach
    void setUp() {
        exportApplicationService = new ExportApplicationService(canvasApplicationService);
    }

    @Test
    @DisplayName("导出SVG应包含svg根标签")
    void exportSvgShouldContainRootElement() throws Exception {
        UUID userId = UUID.randomUUID();
        UUID canvasId = UUID.randomUUID();
        Canvas canvas = newCanvas(canvasId, userId, "Test", 800, 600, "#ffffff");
        Layer layer = Layer.create(canvasId, "L1", 0);

        when(canvasApplicationService.getOwnedCanvas(userId, canvasId)).thenReturn(canvas);
        when(canvasApplicationService.listLayers(userId, canvasId)).thenReturn(List.of(layer));

        byte[] bytes = exportApplicationService.exportSvg(userId, canvasId, true);

        String svg = new String(bytes);
        assertThat(svg).contains("<svg");
        assertThat(svg).contains("metadata");
    }

    private Canvas newCanvas(UUID canvasId, UUID userId, String title, int width, int height, String backgroundColor)
        throws Exception {
        Constructor<Canvas> constructor = Canvas.class.getDeclaredConstructor(
            UUID.class,
            UUID.class,
            String.class,
            int.class,
            int.class,
            String.class
        );
        constructor.setAccessible(true);
        return constructor.newInstance(canvasId, userId, title, width, height, backgroundColor);
    }
}
