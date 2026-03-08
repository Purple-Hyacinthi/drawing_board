package com.drawingboard.user.internal;

import com.drawingboard.user.domain.User;
import io.jsonwebtoken.Claims;
import io.jsonwebtoken.Jws;
import io.jsonwebtoken.JwtException;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.security.Keys;
import java.nio.charset.StandardCharsets;
import java.time.Instant;
import java.util.Date;
import java.util.UUID;
import javax.crypto.SecretKey;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
public class JwtTokenProvider {

    private static final String CLAIM_TYPE = "type";
    private static final String CLAIM_USERNAME = "username";
    private static final String TYPE_ACCESS = "access";
    private static final String TYPE_REFRESH = "refresh";

    private final SecretKey key;
    private final long accessTokenExpirationSeconds;
    private final long refreshTokenExpirationSeconds;

    public JwtTokenProvider(
        @Value("${security.jwt.secret}") String secret,
        @Value("${security.jwt.access-expiration-seconds:86400}") long accessTokenExpirationSeconds,
        @Value("${security.jwt.refresh-expiration-seconds:604800}") long refreshTokenExpirationSeconds
    ) {
        this.key = Keys.hmacShaKeyFor(secret.getBytes(StandardCharsets.UTF_8));
        this.accessTokenExpirationSeconds = accessTokenExpirationSeconds;
        this.refreshTokenExpirationSeconds = refreshTokenExpirationSeconds;
    }

    public String createAccessToken(User user) {
        return createToken(user, TYPE_ACCESS, accessTokenExpirationSeconds);
    }

    public String createRefreshToken(User user) {
        return createToken(user, TYPE_REFRESH, refreshTokenExpirationSeconds);
    }

    public TokenPayload parseToken(String token) {
        try {
            Jws<Claims> parsed = Jwts.parser()
                .verifyWith(key)
                .build()
                .parseSignedClaims(token);
            Claims claims = parsed.getPayload();

            String userId = claims.getSubject();
            String username = claims.get(CLAIM_USERNAME, String.class);
            String type = claims.get(CLAIM_TYPE, String.class);
            Date expiration = claims.getExpiration();

            if (userId == null || username == null || type == null || expiration == null) {
                throw new UserAuthenticationException("无效的Token声明");
            }

            return new TokenPayload(UUID.fromString(userId), username, type, expiration.toInstant());
        } catch (JwtException | IllegalArgumentException exception) {
            throw new UserAuthenticationException("Token无效或已过期");
        }
    }

    public boolean isAccessToken(TokenPayload tokenPayload) {
        return TYPE_ACCESS.equals(tokenPayload.type());
    }

    public boolean isRefreshToken(TokenPayload tokenPayload) {
        return TYPE_REFRESH.equals(tokenPayload.type());
    }

    public long getAccessTokenExpirationSeconds() {
        return accessTokenExpirationSeconds;
    }

    private String createToken(User user, String type, long expirationSeconds) {
        Instant now = Instant.now();
        Instant expiresAt = now.plusSeconds(expirationSeconds);

        return Jwts.builder()
            .subject(user.getId().toString())
            .claim(CLAIM_USERNAME, user.getUsername())
            .claim(CLAIM_TYPE, type)
            .issuedAt(Date.from(now))
            .expiration(Date.from(expiresAt))
            .signWith(key)
            .compact();
    }

    public record TokenPayload(UUID userId, String username, String type, Instant expiresAt) {
    }
}
