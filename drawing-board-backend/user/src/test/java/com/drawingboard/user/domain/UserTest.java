package com.drawingboard.user.domain;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;

import java.time.LocalDateTime;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName("User领域对象")
class UserTest {

    @Test
    @DisplayName("创建用户时应生成ID并写入时间戳")
    void createUserShouldInitializeIdentityAndTimestamps() {
        User user = User.create("alice", "alice@example.com", "hash");

        assertThat(user.getId()).isNotNull();
        assertThat(user.getUsername()).isEqualTo("alice");
        assertThat(user.getEmail()).isEqualTo("alice@example.com");
        assertThat(user.getCreatedAt()).isBeforeOrEqualTo(LocalDateTime.now());
        assertThat(user.getUpdatedAt()).isEqualTo(user.getCreatedAt());
    }

    @Test
    @DisplayName("创建用户时用户名为空应报错")
    void createUserWithBlankUsernameShouldFail() {
        assertThatThrownBy(() -> User.create(" ", "alice@example.com", "hash"))
            .isInstanceOf(IllegalArgumentException.class)
            .hasMessageContaining("用户名");
    }

    @Test
    @DisplayName("创建用户时邮箱格式不合法应报错")
    void createUserWithInvalidEmailShouldFail() {
        assertThatThrownBy(() -> User.create("alice", "invalid-email", "hash"))
            .isInstanceOf(IllegalArgumentException.class)
            .hasMessageContaining("邮箱格式");
    }

    @Test
    @DisplayName("更新邮箱时应刷新更新时间")
    void updateEmailShouldTouchUpdatedAt() throws InterruptedException {
        User user = User.create("alice", "old@example.com", "hash");
        LocalDateTime before = user.getUpdatedAt();

        Thread.sleep(2);
        user.updateEmail("new@example.com");

        assertThat(user.getEmail()).isEqualTo("new@example.com");
        assertThat(user.getUpdatedAt()).isAfter(before);
    }
}
