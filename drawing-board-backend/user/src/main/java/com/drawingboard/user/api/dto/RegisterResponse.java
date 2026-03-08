package com.drawingboard.user.api.dto;

import java.time.LocalDateTime;
import java.util.UUID;

public record RegisterResponse(
    UUID userId,
    String username,
    String email,
    LocalDateTime createdAt
) {
}
