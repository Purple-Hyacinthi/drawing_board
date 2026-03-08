package com.drawingboard.canvas.internal;

import com.drawingboard.canvas.domain.Canvas;
import java.util.Optional;
import java.util.UUID;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;

public interface CanvasRepository extends JpaRepository<Canvas, UUID> {

    Page<Canvas> findByUserId(UUID userId, Pageable pageable);

    Optional<Canvas> findByIdAndUserId(UUID id, UUID userId);
}
