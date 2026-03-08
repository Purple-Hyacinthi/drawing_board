package com.drawingboard.user.api;

import com.drawingboard.user.api.dto.AuthTokenResponse;
import com.drawingboard.user.api.dto.LoginRequest;
import com.drawingboard.user.api.dto.RefreshTokenRequest;
import com.drawingboard.user.api.dto.RegisterRequest;
import com.drawingboard.user.api.dto.RegisterResponse;
import com.drawingboard.user.api.dto.UserProfileResponse;
import com.drawingboard.user.domain.User;
import com.drawingboard.user.internal.UserAuthService;
import jakarta.validation.Valid;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/v1/auth")
public class AuthController {

    private final UserAuthService userAuthService;

    public AuthController(UserAuthService userAuthService) {
        this.userAuthService = userAuthService;
    }

    @PostMapping("/register")
    @ResponseStatus(HttpStatus.CREATED)
    public RegisterResponse register(@Valid @RequestBody RegisterRequest request) {
        User user = userAuthService.register(request.username(), request.email(), request.password());
        return new RegisterResponse(
            user.getId(),
            user.getUsername(),
            user.getEmail(),
            user.getCreatedAt()
        );
    }

    @PostMapping("/login")
    public AuthTokenResponse login(@Valid @RequestBody LoginRequest request) {
        UserAuthService.AuthResult authResult = userAuthService.login(request.email(), request.password());
        return toAuthTokenResponse(authResult);
    }

    @PostMapping("/refresh")
    public AuthTokenResponse refresh(@Valid @RequestBody RefreshTokenRequest request) {
        UserAuthService.AuthResult authResult = userAuthService.refresh(request.refreshToken());
        return toAuthTokenResponse(authResult);
    }

    private AuthTokenResponse toAuthTokenResponse(UserAuthService.AuthResult authResult) {
        User user = authResult.user();
        UserProfileResponse userResponse = new UserProfileResponse(
            user.getId(),
            user.getUsername(),
            user.getEmail(),
            user.getCreatedAt(),
            user.getUpdatedAt()
        );

        return new AuthTokenResponse(
            authResult.accessToken(),
            authResult.refreshToken(),
            authResult.expiresIn(),
            userResponse
        );
    }
}
