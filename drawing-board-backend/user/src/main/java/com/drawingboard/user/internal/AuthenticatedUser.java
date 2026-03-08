package com.drawingboard.user.internal;

import java.util.UUID;

public record AuthenticatedUser(UUID userId, String username) {
}
