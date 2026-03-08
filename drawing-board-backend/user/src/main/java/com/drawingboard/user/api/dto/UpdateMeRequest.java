package com.drawingboard.user.api.dto;

import jakarta.validation.constraints.Email;
import jakarta.validation.constraints.Size;

public record UpdateMeRequest(
    @Size(min = 3, max = 50) String username,
    @Email String email
) {
}
