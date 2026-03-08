package com.drawingboard.user.api;

import com.drawingboard.user.api.dto.UpdateMeRequest;
import com.drawingboard.user.api.dto.UserProfileResponse;
import com.drawingboard.user.domain.User;
import com.drawingboard.user.internal.AuthenticatedUser;
import com.drawingboard.user.internal.UserAuthService;
import jakarta.validation.Valid;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/v1/users")
public class UserController {

    private final UserAuthService userAuthService;

    public UserController(UserAuthService userAuthService) {
        this.userAuthService = userAuthService;
    }

    @GetMapping("/me")
    public UserProfileResponse getCurrentUser(@AuthenticationPrincipal AuthenticatedUser authenticatedUser) {
        User user = userAuthService.getById(authenticatedUser.userId());
        return toResponse(user);
    }

    @PutMapping("/me")
    public UserProfileResponse updateCurrentUser(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @Valid @RequestBody UpdateMeRequest request
    ) {
        User user = userAuthService.updateProfile(authenticatedUser.userId(), request.username(), request.email());
        return toResponse(user);
    }

    private UserProfileResponse toResponse(User user) {
        return new UserProfileResponse(
            user.getId(),
            user.getUsername(),
            user.getEmail(),
            user.getCreatedAt(),
            user.getUpdatedAt()
        );
    }
}
