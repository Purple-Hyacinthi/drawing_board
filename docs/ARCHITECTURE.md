# Drawing Board Pro - 架构设计文档

## 1. 系统概述

Drawing Board Pro 是一个跨平台的数字画板应用，当前版本定位如下：
- 前端采用单页纯画板模式，进入即绘制
- 支持基础笔触绘制与压感输入
- 后端保留画布、图层、历史、导出等模块化 API 能力
- 支持跨平台桌面封装（Windows、macOS、Linux）

## 2. 技术栈

### 2.1 前端
- **框架**: Vue 3 + TypeScript
- **状态管理**: Pinia
- **路由**: Vue Router
- **构建工具**: Vite
- **UI库**: Tailwind CSS
- **渲染方式**: 原生 Canvas 自绘
- **代码质量**: ESLint + Prettier

### 2.2 后端
- **语言**: Java 21
- **框架**: Spring Boot 3.3 + Spring Modulith 1.2.x
- **构建工具**: Gradle 8.8+ (Kotlin DSL)
- **数据库**: PostgreSQL 15+
- **数据访问**: Spring Data JPA
- **安全**: Spring Security + JWT
- **测试**: JUnit 5 + Testcontainers
- **代码质量**: Checkstyle + Spotless

### 2.3 桌面封装
- **框架**: QT 6.7
- **Web引擎**: QT WebEngine
- **构建工具**: CMake
- **部署**: 各平台原生包

### 2.4 开发工具
- **版本控制**: Git + Conventional Commits
- **CI/CD**: GitHub Actions
- **容器化**: Docker
- **数据库迁移**: Flyway

## 3. 架构模式

### 3.1 整体架构
```
┌─────────────────────────────────────────────────────────┐
│                   桌面应用 (QT WebEngine)                  │
└─────────────────────────────────────────────────────────┘
                            │
┌─────────────────────────────────────────────────────────┐
│                 前端应用 (Vue 3 + Vite)                   │
└─────────────────────────────────────────────────────────┘
                            │ HTTP/WebSocket
┌─────────────────────────────────────────────────────────┐
│               后端API (Spring Boot + Modulith)            │
└─────────────────────────────────────────────────────────┘
                            │
┌─────────────────────────────────────────────────────────┐
│                   数据库 (PostgreSQL)                     │
└─────────────────────────────────────────────────────────┘
```

### 3.2 模块化架构 (Spring Modulith)
后端采用Spring Modulith实现模块化设计：

```
drawing-board-backend/
├── application/          # 主应用模块（聚合模块）
├── user/                # 用户管理模块
│   ├── domain/          # 领域模型
│   ├── api/             # 模块API（对外接口）
│   ├── internal/        # 内部实现
│   └── events/          # 模块事件
├── canvas/              # 画布管理模块
├── drawing/             # 绘图操作模块
└── export/              # 导出功能模块
```

### 3.3 模块通信规则
1. **API包模式**: 模块通过`*.api`包暴露接口
2. **事件驱动**: 模块间通过Spring事件解耦
3. **依赖方向**: 依赖指向更高层次的模块
4. **契约测试**: 模块接口提供契约测试

## 4. 数据模型

### 4.1 核心实体
```sql
-- 用户表
CREATE TABLE users (
    id UUID PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL
);

-- 画布表
CREATE TABLE canvases (
    id UUID PRIMARY KEY,
    user_id UUID REFERENCES users(id),
    title VARCHAR(255) NOT NULL,
    width INTEGER NOT NULL,
    height INTEGER NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL
);

-- 图层表
CREATE TABLE layers (
    id UUID PRIMARY KEY,
    canvas_id UUID REFERENCES canvases(id) ON DELETE CASCADE,
    name VARCHAR(100) NOT NULL,
    z_index INTEGER NOT NULL,
    visible BOOLEAN DEFAULT TRUE,
    locked BOOLEAN DEFAULT FALSE,
    drawing_data JSONB,  -- 存储绘图路径数据
    created_at TIMESTAMP NOT NULL
);

-- 操作历史表
CREATE TABLE canvas_versions (
    id UUID PRIMARY KEY,
    canvas_id UUID REFERENCES canvases(id) ON DELETE CASCADE,
    snapshot_data JSONB NOT NULL,
    created_at TIMESTAMP NOT NULL
);
```

### 4.2 数据访问策略
- **实体映射**: 使用JPA实体映射
- **值对象**: 使用`@Embeddable`或自定义类型
- **JSON存储**: 绘图数据使用PostgreSQL JSONB
- **索引优化**: 关键查询字段创建索引

## 5. API设计

### 5.1 REST API规范
- **版本**: `/api/v1/*`
- **认证**: JWT Bearer Token
- **媒体类型**: `application/json`
- **错误格式**: 统一错误响应

### 5.2 主要端点
```
# 用户认证
POST   /api/v1/auth/login
POST   /api/v1/auth/register
POST   /api/v1/auth/refresh

# 画布管理
GET    /api/v1/canvases
POST   /api/v1/canvases
GET    /api/v1/canvases/{id}
PUT    /api/v1/canvases/{id}
DELETE /api/v1/canvases/{id}

# 绘图操作
POST   /api/v1/canvases/{id}/draw
POST   /api/v1/canvases/{id}/layers
PUT    /api/v1/canvases/{id}/layers/{layerId}

# 导出功能
POST   /api/v1/canvases/{id}/export/png
POST   /api/v1/canvases/{id}/export/jpeg
POST   /api/v1/canvases/{id}/export/svg
```

## 6. 前端架构

### 6.1 组件结构
```
src/
├── App.vue             # 应用壳（仅 router-view）
├── main.ts             # 应用启动入口
├── assets/
│   └── main.css        # 全局样式
├── router/
│   └── index.ts        # 单路由，统一进入画板页
├── stores/
│   └── canvas.ts       # 画布状态
└── views/
    └── CanvasView.vue  # 纯画板页面
```

### 6.2 状态管理
- **全局状态**: Pinia store管理应用状态
- **本地状态**: Vue组件内部状态
- **默认配置**: 启动时初始化默认画布与笔触参数
- **扩展方式**: 后续可按需接入后端同步

## 7. 桌面封装架构

### 7.1 QT WebEngine集成
```
DrawingBoardDesktop/
├── src/
│   ├── mainwindow.cpp          # 主窗口
│   ├── webenginehandler.cpp    # WebEngine处理器
│   └── nativebridge.cpp        # QT-Web桥接
├── resources/
│   └── frontend/               # Vue构建产物
└── CMakeLists.txt
```

### 7.2 本地功能桥接
- **文件系统**: 通过QT桥接访问本地文件
- **系统对话框**: 原生文件保存/打开对话框
- **系统托盘**: 后台运行支持
- **快捷键**: 系统级快捷键支持

## 8. 部署架构

### 8.1 开发环境
- **本地开发**: Docker Compose（PostgreSQL）
- **热重载**: 前端Vite + 后端Spring DevTools
- **测试**: 本地Testcontainers

### 8.2 生产环境
- **容器化**: Docker多阶段构建
- **数据库**: PostgreSQL高可用集群
- **缓存**: Redis会话缓存
- **存储**: 对象存储（图片导出）

## 9. 质量保障

### 9.1 代码质量
- **测试覆盖**: >80% (JaCoCo)
- **静态分析**: Checkstyle + Spotless
- **代码审查**: PR模板 + 自动化检查

### 9.2 性能指标
- **API响应**: <100ms (P95)
- **前端加载**: <3s (首屏)
- **画板渲染**: 60fps
- **内存使用**: <500MB (桌面应用)

## 10. 安全设计

### 10.1 认证授权
- **认证**: JWT + 刷新令牌
- **授权**: RBAC权限控制
- **会话管理**: 安全Cookie + SameSite

### 10.2 数据安全
- **密码**: bcrypt哈希 + salt
- **传输**: HTTPS强制
- **输入验证**: 所有API参数验证
- **文件上传**: 类型限制 + 病毒扫描

## 11. 监控与日志

### 11.1 监控指标
- **应用指标**: 请求数、错误率、响应时间
- **系统指标**: CPU、内存、磁盘、网络
- **业务指标**: 活跃用户、画布创建数

### 11.2 日志策略
- **结构化日志**: JSON格式
- **日志级别**: DEBUG/INFO/WARN/ERROR
- **日志聚合**: ELK Stack
- **审计日志**: 关键操作记录

---

*最后更新: 2025-03-05*
*版本: 1.0.0*
