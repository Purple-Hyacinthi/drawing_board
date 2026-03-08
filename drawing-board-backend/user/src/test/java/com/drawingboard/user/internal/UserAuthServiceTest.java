package com.drawingboard.user.internal;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.never;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import com.drawingboard.user.domain.User;
import java.util.Optional;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.security.crypto.password.PasswordEncoder;

@ExtendWith(MockitoExtension.class)
@DisplayName("UserAuthService")
class UserAuthServiceTest {

    @Mock
    private UserRepository userRepository;

    @Mock
    private PasswordEncoder passwordEncoder;

    @Mock
    private JwtTokenProvider jwtTokenProvider;

    private UserAuthService userAuthService;

    @BeforeEach
    void setUp() {
        userAuthService = new UserAuthService(userRepository, passwordEncoder, jwtTokenProvider);
    }

    @Test
    @DisplayName("用户名冲突时注册失败")
    void registerShouldFailWhenUsernameExists() {
        when(userRepository.existsByUsername("alice")).thenReturn(true);

        assertThatThrownBy(() -> userAuthService.register("alice", "alice@example.com", "password123"))
            .isInstanceOf(UserConflictException.class);

        verify(userRepository, never()).save(any(User.class));
    }

    @Test
    @DisplayName("邮箱密码正确时可登录")
    void loginShouldReturnTokensWhenPasswordMatches() {
        User user = User.create("alice", "alice@example.com", "encoded");
        when(userRepository.findByEmail("alice@example.com")).thenReturn(Optional.of(user));
        when(passwordEncoder.matches("password123", "encoded")).thenReturn(true);
        when(jwtTokenProvider.createAccessToken(user)).thenReturn("access");
        when(jwtTokenProvider.createRefreshToken(user)).thenReturn("refresh");
        when(jwtTokenProvider.getAccessTokenExpirationSeconds()).thenReturn(86400L);

        UserAuthService.AuthResult result = userAuthService.login("alice@example.com", "password123");

        assertThat(result.accessToken()).isEqualTo("access");
        assertThat(result.refreshToken()).isEqualTo("refresh");
        assertThat(result.user().getUsername()).isEqualTo("alice");
    }
}
