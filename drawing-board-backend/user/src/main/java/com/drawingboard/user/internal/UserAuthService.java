package com.drawingboard.user.internal;

import com.drawingboard.user.domain.User;
import java.util.UUID;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
public class UserAuthService {

    private final UserRepository userRepository;
    private final PasswordEncoder passwordEncoder;
    private final JwtTokenProvider jwtTokenProvider;

    public UserAuthService(
        UserRepository userRepository,
        PasswordEncoder passwordEncoder,
        JwtTokenProvider jwtTokenProvider
    ) {
        this.userRepository = userRepository;
        this.passwordEncoder = passwordEncoder;
        this.jwtTokenProvider = jwtTokenProvider;
    }

    @Transactional
    public User register(String username, String email, String password) {
        if (password == null || password.length() < 8) {
            throw new IllegalArgumentException("密码长度至少8位");
        }
        if (userRepository.existsByUsername(username)) {
            throw new UserConflictException("用户名已存在");
        }
        if (userRepository.existsByEmail(email)) {
            throw new UserConflictException("邮箱已存在");
        }

        String passwordHash = passwordEncoder.encode(password);
        User user = User.create(username, email, passwordHash);
        return userRepository.save(user);
    }

    @Transactional(readOnly = true)
    public AuthResult login(String email, String password) {
        User user = userRepository.findByEmail(email)
            .orElseThrow(() -> new UserAuthenticationException("邮箱或密码错误"));

        if (!passwordEncoder.matches(password, user.getPasswordHash())) {
            throw new UserAuthenticationException("邮箱或密码错误");
        }

        return issueTokens(user);
    }

    @Transactional(readOnly = true)
    public AuthResult refresh(String refreshToken) {
        JwtTokenProvider.TokenPayload payload = jwtTokenProvider.parseToken(refreshToken);
        if (!jwtTokenProvider.isRefreshToken(payload)) {
            throw new UserAuthenticationException("刷新令牌类型不正确");
        }

        User user = userRepository.findById(payload.userId())
            .orElseThrow(() -> new UserAuthenticationException("用户不存在或已被删除"));

        return issueTokens(user);
    }

    @Transactional(readOnly = true)
    public User getById(UUID userId) {
        return userRepository.findById(userId)
            .orElseThrow(() -> new UserNotFoundException("用户不存在"));
    }

    @Transactional
    public User updateProfile(UUID userId, String username, String email) {
        User user = userRepository.findById(userId)
            .orElseThrow(() -> new UserNotFoundException("用户不存在"));

        if (username != null && !username.isBlank()) {
            boolean usedByOther = userRepository.existsByUsername(username)
                && !username.equals(user.getUsername());
            if (usedByOther) {
                throw new UserConflictException("用户名已存在");
            }
            user.updateUsername(username);
        }

        if (email != null && !email.isBlank()) {
            boolean usedByOther = userRepository.existsByEmail(email)
                && !email.equals(user.getEmail());
            if (usedByOther) {
                throw new UserConflictException("邮箱已存在");
            }
            user.updateEmail(email);
        }

        return user;
    }

    private AuthResult issueTokens(User user) {
        String accessToken = jwtTokenProvider.createAccessToken(user);
        String refreshToken = jwtTokenProvider.createRefreshToken(user);
        return new AuthResult(
            accessToken,
            refreshToken,
            jwtTokenProvider.getAccessTokenExpirationSeconds(),
            user
        );
    }

    public record AuthResult(String accessToken, String refreshToken, long expiresIn, User user) {
    }
}
