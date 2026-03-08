package com.drawingboard.drawing.internal;

import com.drawingboard.drawing.domain.CanvasVersion;
import java.util.List;
import java.util.UUID;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;

public interface CanvasVersionRepository extends JpaRepository<CanvasVersion, UUID> {

    List<CanvasVersion> findByCanvasIdOrderByCreatedAtDesc(UUID canvasId, Pageable pageable);

    List<CanvasVersion> findByCanvasIdOrderByCreatedAtDesc(UUID canvasId);
}
