# Drawing Board Pro - 开发规范

## 1. 开发环境设置

### 1.1 系统要求
- **Java**: JDK 21 (Temurin或OpenJDK)
- **Node.js**: v18+ (推荐v20+)
- **npm**: v9+ 或 **pnpm**: v8+ 或 **yarn**: v1.22+
- **Gradle**: 8.8+ (通过Wrapper自动下载)
- **PostgreSQL**: 15+
- **Docker**: 20.10+ (可选，用于容器化开发)
- **QT**: 6.7+ (仅桌面开发需要)

### 1.2 环境变量配置
```bash
# 复制环境变量示例文件
cp .env.example .env.development

# 编辑环境变量
# 数据库配置
DB_HOST=localhost
DB_PORT=5432
DB_NAME=drawing_board
DB_USER=postgres
DB_PASSWORD=<set-a-local-database-password>

# JWT配置
JWT_SECRET=<generate-a-random-secret-at-least-32-chars>
JWT_EXPIRATION=86400

# 前端配置
VITE_API_BASE_URL=http://localhost:8080/api
```

## 2. 代码规范

### 2.1 Java代码规范 (Google Java Style)
- **命名约定**:
  - 类名: `PascalCase` (如 `CanvasService`)
  - 方法名: `camelCase` (如 `createCanvas`)
  - 常量: `UPPER_SNAKE_CASE` (如 `MAX_CANVAS_SIZE`)
  - 包名: `lowercase` (如 `com.drawingboard.user`)

- **格式化规则**:
  ```bash
  # 使用Spotless格式化
  ./gradlew spotlessApply
  
  # 检查格式化
  ./gradlew spotlessCheck
  ```

- **最佳实践**:
  - 使用`final`修饰不可变变量
  - 避免使用`null`，使用`Optional`
  - 遵循SOLID原则
  - 方法不超过20行，类不超过300行

### 2.2 TypeScript/Vue代码规范
- **命名约定**:
  - 组件: `PascalCase` (如 `DrawingBoard.vue`)
  - 组合式函数: `camelCase` (如 `useCanvas`)
  - 类型/接口: `PascalCase` (如 `CanvasData`)
  - 常量: `UPPER_SNAKE_CASE`

- **格式化规则**:
  ```bash
  # ESLint检查
  npm run lint
  
  # Prettier格式化
  npm run format
  ```

- **Vue最佳实践**:
  - 使用组合式API (`<script setup>`)
  - 组件 props 使用 TypeScript 类型定义
  - 避免在模板中使用复杂逻辑
  - 使用 `computed` 和 `watch` 处理响应式数据

## 3. TDD开发流程

### 3.1 红-绿-重构循环
1. **RED**: 编写一个失败的测试
2. **GREEN**: 编写最简单的代码使测试通过
3. **REFACTOR**: 重构代码，保持测试通过

### 3.2 测试层级
```java
// 单元测试 (单个类/方法)
@ExtendWith(MockitoExtension.class)
class CanvasServiceTest {
    @Test
    void givenValidCommand_whenCreateCanvas_thenCanvasIsCreated() {
        // 测试逻辑
    }
}

// 集成测试 (模块间)
@SpringBootTest
class CanvasIntegrationTest {
    @Test
    void givenUserExists_whenCreateCanvas_thenCanvasSaved() {
        // 测试逻辑
    }
}

// E2E测试 (完整流程)
@SpringBootTest(webEnvironment = WebEnvironment.RANDOM_PORT)
class CanvasE2ETest {
    @Test
    void userCanCreateAndExportCanvas() {
        // 完整用户流程测试
    }
}
```

### 3.3 测试覆盖率要求
- **单元测试**: 优先覆盖核心领域逻辑与关键应用服务
- **集成测试**: 覆盖主要模块边界与核心联调流程
- **E2E测试**: 关键用户流程

## 4. Git工作流

### 4.1 分支策略
```
main (受保护)
├── develop (主开发分支)
├── feature/ (功能分支)
├── bugfix/ (修复分支)
└── release/ (发布分支)
```

### 4.2 提交规范 (Conventional Commits)
```
<type>(<scope>): <subject>

<body>

<footer>
```

**提交类型**:
- `feat`: 新功能
- `fix`: 修复bug
- `docs`: 文档更新
- `style`: 代码格式
- `refactor`: 重构
- `test`: 测试相关
- `chore`: 构建/工具更新

**示例**:
```bash
feat(canvas): add layer management functionality

- Add layer creation API
- Implement layer reordering
- Add layer visibility toggle

Closes #123
```

### 4.3 PR流程
1. 从`develop`创建功能分支
2. 开发并提交代码
3. 创建Pull Request到`develop`
4. 代码审查 + CI检查
5. 合并到`develop`

## 5. 构建与部署

### 5.1 本地构建
```bash
# 一键启动前后端（推荐日常开发）
./scripts/dev/start-all.ps1

# 停止一键启动拉起的进程
./scripts/dev/stop-all.ps1

# 后端构建
cd drawing-board-backend
./gradlew build          # 完整构建
./gradlew bootRun        # 运行应用

# 前端构建
cd frontend
npm install              # 安装依赖
npm run dev              # 开发服务器
npm run build            # 生产构建

# 桌面应用构建 (需要QT)
cd desktop
mkdir build && cd build
cmake ..                 # 配置构建
cmake --build .          # 构建应用

# 回到仓库根目录执行前后端联调脚本
cd ../..
./scripts/integration/integration.sh
```

一键启动脚本说明：
- 默认使用后端 `local-it` 配置（H2 内存库）
- 默认启动前端 Vite 开发服务器
- 默认输出日志：`tmp/start-backend.log`、`tmp/start-frontend.log`
- Windows CMD 可用 `scripts\dev\start-all.cmd` 和 `scripts\dev\stop-all.cmd`

### 5.2 本地联调脚本说明

脚本入口：`scripts/integration/local-integration.mjs`

默认行为：
1. 可自动启动后端（`--auto-start-backend`，默认由 `scripts/integration/integration.sh` 启用）
2. 检查后端健康接口 `/actuator/health`
3. 可选自动启动前端（`--auto-start-frontend`）
4. 检查前端画板页是否可访问
5. 执行 `注册 -> 登录 -> 创建画布 -> 创建图层 -> 保存绘图 -> 查询历史 -> 撤销/重做 -> 导出`
6. 将导出文件写入 `tmp/integration-artifacts/`

自动启动后端时，默认使用 `SPRING_PROFILES_ACTIVE=local-it`，基于 H2 内存库，不依赖本地 PostgreSQL 账号密码。

常用参数：

```bash
# 使用包装脚本（自动启动后端）
./scripts/integration/integration.sh

# 自动启动后端 + 自动启动前端
./scripts/integration/integration.sh --auto-start-frontend

# 跳过前端可访问性检查（仅验证后端API链路）
./scripts/integration/integration.sh --skip-frontend-check

# Windows PowerShell
./scripts/integration/integration.ps1

# Windows CMD
scripts\integration\integration.cmd

# 直接调用Node脚本并指定后端profile
node scripts/integration/local-integration.mjs --auto-start-backend --backend-profile local-it

# 直接调用Node脚本并自动启动前端
node scripts/integration/local-integration.mjs --auto-start-backend --auto-start-frontend

# 指定后端/前端地址（使用外部已启动服务）
node scripts/integration/local-integration.mjs --backend-url http://127.0.0.1:8080 --frontend-url http://127.0.0.1:3000

# 指定导出目录
node scripts/integration/local-integration.mjs --output-dir tmp/custom-it-output
```

### 5.3 Docker构建
```bash
# 构建所有服务
docker-compose build

# 启动开发环境
docker-compose up -d

# 查看日志
docker-compose logs -f
```

## 6. 模块化开发指南

### 6.1 Spring Modulith模块创建
1. 在`settings.gradle.kts`中添加模块
2. 创建模块目录和`build.gradle.kts`
3. 定义模块API (`*.api`包)
4. 实现模块功能 (`*.internal`包)
5. 编写模块测试

### 6.2 模块通信模式
```java
// 模块API定义
package com.drawingboard.user.api;

public interface UserApi {
    User findUserById(UserId userId);
    User createUser(CreateUserCommand command);
}

// 其他模块使用
@Service
public class CanvasService {
    private final UserApi userApi;
    
    public CanvasService(UserApi userApi) {
        this.userApi = userApi;
    }
    
    public Canvas createCanvas(UserId userId, String title) {
        User user = userApi.findUserById(userId);
        // 创建画布逻辑
    }
}
```

## 7. 前端开发指南

### 7.1 页面设计约束
- 当前版本前端采用**单页纯画板**模式
- `App.vue` 只保留 `router-view`
- 路由统一指向 `CanvasView.vue`
- 用户可见文案默认使用中文
- 功能扩展优先在不破坏纯画板体验的前提下进行

### 7.2 画板页面建议
- 事件处理使用 Pointer 事件（`pointerdown/move/up`）
- 坐标计算统一基于画布容器缩放比
- 画笔参数集中管理，避免模板层分散逻辑
- 样式保持极简，优先保证绘制区域占比

### 7.3 状态管理指南
- **全局状态**: 使用Pinia store
- **组件状态**: 使用`ref`/`reactive`
- **默认参数**: 在页面挂载时初始化画布与笔触
- **扩展同步**: 需要时再接入后端状态同步

## 8. 性能优化

### 8.1 后端优化
- **数据库**: 查询优化 + 索引
- **缓存**: Redis缓存热点数据
- **连接池**: HikariCP配置优化
- **垃圾回收**: JVM调优

### 8.2 前端优化
- **代码分割**: 以组件级分割为主
- **图片优化**: WebP格式 + 懒加载
- **Bundle优化**: Tree-shaking + 压缩
- **渲染优化**: Virtual DOM + 记忆化

## 9. 调试与问题排查

### 9.1 常见问题
```bash
# 端口冲突
lsof -i :8080  # 查找占用端口的进程

# 依赖问题
./gradlew --refresh-dependencies  # 刷新Gradle依赖
rm -rf node_modules && npm install # 重新安装npm包

# 数据库迁移
./gradlew flywayMigrate  # 应用数据库迁移
```

### 9.2 调试工具
- **后端**: Spring Boot Actuator + JMX
- **前端**: Vue DevTools + Browser DevTools
- **数据库**: pgAdmin + EXPLAIN ANALYZE
- **网络**: Wireshark + Charles Proxy

## 10. 代码审查清单

### 10.1 通用检查项
- [ ] 代码遵循项目规范
- [ ] 有意义的命名
- [ ] 适当的注释和文档
- [ ] 无安全漏洞
- [ ] 测试覆盖充分
- [ ] 性能考虑

### 10.2 后端特定检查
- [ ] SOLID原则遵循
- [ ] 异常处理恰当
- [ ] 事务边界正确
- [ ] 输入验证完整
- [ ] 日志记录适当

### 10.3 前端特定检查
- [ ] 响应式设计
- [ ] 无障碍访问
- [ ] 浏览器兼容性
- [ ] 内存泄漏检查
- [ ] 性能优化

## 11. 发布流程

### 11.1 版本管理 (Semantic Versioning)
- **主版本号**: 不兼容的API修改
- **次版本号**: 向下兼容的功能新增
- **修订号**: 向下兼容的问题修正

### 11.2 发布检查清单
1. [ ] 所有测试通过
2. [ ] 文档更新完成
3. [ ] 版本号更新
4. [ ] CHANGELOG编写
5. [ ] 发布分支创建
6. [ ] 预发布环境测试
7. [ ] 正式发布

---

*文档版本: 1.0.0*
*最后更新: 2025-03-05*
