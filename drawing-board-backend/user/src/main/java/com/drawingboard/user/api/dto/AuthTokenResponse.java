package com.drawingboard.user.api.dto;

public record AuthTokenResponse(
    String accessToken,
    String refreshToken,
    long expiresIn,
    UserProfileResponse user
) {
}
