package com.drawingboard.canvas.internal;

import com.drawingboard.canvas.domain.Layer;
import java.util.List;
import java.util.Optional;
import java.util.UUID;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

public interface LayerRepository extends JpaRepository<Layer, UUID> {

    @Query("select layer from Layer layer where layer.canvasId = :canvasId order by layer.zIndex asc")
    List<Layer> findByCanvasIdOrderByZIndexAsc(@Param("canvasId") UUID canvasId);

    @Query("select layer from Layer layer where layer.id = :id and layer.canvasId = :canvasId")
    Optional<Layer> findByIdAndCanvasId(@Param("id") UUID id, @Param("canvasId") UUID canvasId);
}
