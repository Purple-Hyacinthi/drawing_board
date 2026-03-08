# Drawing Board Pro

一个面向中文用户的跨平台数字画板应用。当前前端采用极简画板模式，打开即绘制。

## 当前版本说明

### 前端界面
- **单页纯画板**: 无首页、无画廊、无导航栏
- **直接创作**: 进入应用后即可在画布上绘制
- **输入支持**: 支持鼠标与压感笔基础绘制
- **中文优先**: 对用户可见内容保持中文

### 后端能力
- **API保留**: 用户、画布、图层、历史与导出接口仍可用
- **联调可用**: 支持注册、登录、创建画布、导出等联调流程

### 技术栈
- **前端**: Vue 3 + TypeScript + Tailwind CSS
- **后端**: Java 21 + Spring Boot + Spring Modulith
- **数据库**: PostgreSQL
- **桌面封装**: QT 6.7 + WebEngine
- **构建工具**: Gradle (Kotlin DSL) + Vite

## 快速开始

### 环境要求
- **Java 21** (Temurin或OpenJDK)
- **Node.js 18+** (推荐20+)
- **PostgreSQL 15+**
- **Gradle 8.8+** (通过Wrapper提供)

### 开发环境设置

1. **克隆项目**
```bash
 git clone https://github.com/Purple-Hyacinthi/drawing_board.git
 cd drawing_board
```

2. **后端设置**
```bash
cd drawing-board-backend

# 复制环境配置
cp .env.example .env

# 使用Gradle Wrapper构建
./gradlew build

# 运行应用
./gradlew bootRun
```

3. **前端设置**
```bash
cd frontend

# 安装依赖
npm install

# 启动开发服务器
npm run dev
```

4. **数据库设置**
```sql
-- 创建数据库
CREATE DATABASE drawing_board;
```

### Docker开发环境
```bash
# 使用Docker Compose启动所有服务
docker-compose up -d

# 访问应用
# 前端: http://localhost:3000
# 后端API: http://localhost:8080
# 数据库: localhost:5432
```

## 项目结构

```
drawing-board/
├── drawing-board-backend/     # Spring Modulith后端
│   ├── application/          # 主应用模块
│   ├── user/                # 用户管理模块
│   ├── canvas/              # 画布管理模块
│   ├── drawing/             # 绘图操作模块
│   └── export/              # 导出功能模块
├── frontend/                # Vue 3前端
│   ├── src/
│   │   ├── App.vue          # 应用入口壳
│   │   ├── main.ts          # 启动文件
│   │   ├── assets/main.css  # 全局样式
│   │   ├── router/index.ts  # 单路由配置
│   │   ├── stores/canvas.ts # 画布状态
│   │   └── views/CanvasView.vue # 纯画板页面
│   └── vite.config.ts       # Vite配置
├── desktop/                 # QT桌面应用
├── docs/                   # 项目文档
├── database/               # 数据库脚本
└── docker/                 # Docker配置
```

## 开发指南

### 代码规范
- **Java**: Google Java Style + Spotless
- **TypeScript**: ESLint + Prettier + Vue风格指南
- **Git**: Conventional Commits提交规范

### 测试策略
- **TDD流程**: 红-绿-重构
- **测试覆盖**: >80% JaCoCo覆盖率
- **测试类型**: 单元测试、集成测试、E2E测试

### 构建与部署
```bash
# 完整构建
./scripts/build/build.sh

# 运行所有测试
./scripts/build/test.sh

# 一键启动应用（开发模式）
./scripts/dev/start-all.ps1

# 关闭一键启动的前后端进程
./scripts/dev/stop-all.ps1

# 本地前后端联调（自动拉起后端，注册 -> 创建画布 -> 导出）
./scripts/integration/integration.sh

# 自动拉起前后端并联调（需要已安装前端依赖）
./scripts/integration/integration.sh --auto-start-frontend

# 如果前端未启动，可先跳过前端可访问性检查
./scripts/integration/integration.sh --skip-frontend-check

# Windows PowerShell
./scripts/integration/integration.ps1

# Windows CMD
scripts\integration\integration.cmd

# 启动脚本（Windows CMD）
scripts\dev\start-all.cmd

# 停止脚本（Windows CMD）
scripts\dev\stop-all.cmd
```

联调脚本默认检查：
- 后端健康：`http://127.0.0.1:8080/actuator/health`
- 前端页面：`http://127.0.0.1:3000`

一键启动脚本默认行为：
- 自动启动后端（`SPRING_PROFILES_ACTIVE=local-it`）
- 自动启动前端开发服务器（Vite）
- 记录日志到 `tmp/start-backend.log` 与 `tmp/start-frontend.log`
- 启动完成后自动打开浏览器

`./scripts/integration/integration.sh` / `./scripts/integration/integration.ps1` / `scripts\integration\integration.cmd` 会自动使用后端 `local-it` 配置（H2内存库）拉起后端，避免依赖本机 PostgreSQL 凭据。

并执行完整 API 流程：注册、登录、创建画布、创建图层、提交绘图、历史查询、撤销重做、导出 PNG/JPEG/SVG。
导出文件默认输出到 `tmp/integration-artifacts/`。

## 文档

- [架构设计](./docs/ARCHITECTURE.md) - 系统架构和技术决策
- [开发规范](./docs/DEVELOPMENT.md) - 编码标准和开发流程
- [API文档](./docs/API.md) - REST API接口文档
- [部署指南](./docs/DEPLOYMENT.md) - 生产环境部署
- [用户指南](./docs/USER-GUIDE.md) - 最终用户手册

## 贡献指南

1. Fork项目仓库
2. 创建功能分支 (`git checkout -b feature/amazing-feature`)
3. 提交更改 (`git commit -m 'feat: add amazing feature'`)
4. 推送到分支 (`git push origin feature/amazing-feature`)
5. 开启Pull Request

请确保遵循项目的代码规范和测试要求。

## 许可证

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情。

## 联系方式

- **项目维护者**: [Purple-Hyacinthi](https://github.com/Purple-Hyacinthi)
- **问题反馈**: [GitHub Issues](https://github.com/Purple-Hyacinthi/drawing_board/issues)
- **功能建议**: [GitHub Discussions](https://github.com/Purple-Hyacinthi/drawing_board/discussions)

---

让创意自由流淌，绘制无限可能。
