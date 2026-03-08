# Drawing Board Pro

一个面向中文用户的跨平台数字画板项目，包含 Vue Web 前端、Spring Boot 后端，以及 Qt 桌面封装能力。

打开即绘制，当前聚焦纯画板体验，并提供后端 API、桌面壳、发布脚本和完整项目文档。

## 快速入口

- **在线代码**: `main` 分支维护当前版本
- **发布下载**: [v1.0.0 - Workspace Baseline](./releases/tag/v1.0.0)
- **Windows 安装包**: `DrawingBoardPro-Setup-1.0.0.exe`
- **Windows 便携版**: `DrawingBoardDesktop-windows-x64.zip`
- **桌面打包说明**: `desktop/README.md`

## 项目亮点

- **前端体验**: 单页纯画板模式，打开即绘制
- **核心能力**: 图层、文字、套索选择、滤镜、导出
- **后端接口**: 用户、画布、图层、历史与导出 API
- **桌面封装**: 基于 Qt WebEngine 的桌面壳与 Windows 打包脚本
- **开发支持**: 提供 Docker、CI、联调脚本与项目文档

## 技术栈

- **前端**: Vue 3 + TypeScript + Tailwind CSS
- **后端**: Java 21 + Spring Boot + Spring Modulith
- **数据库**: PostgreSQL
- **桌面封装**: Qt 6.7 + WebEngine
- **构建工具**: Gradle (Kotlin DSL) + Vite + CMake

## 快速开始

### 环境要求
- **Java 21** (Temurin或OpenJDK)
- **Node.js 18+** (推荐20+)
- **PostgreSQL 15+**
- **Gradle 8.8+** (通过Wrapper提供)

### 本地开发

后端和前端建议分别在两个终端中启动：

```bash
git clone https://github.com/Purple-Hyacinthi/drawing_board.git
cd drawing_board

# 终端 1：后端
cd drawing-board-backend
cp .env.example .env
./gradlew build
./gradlew bootRun
```

```bash
# 终端 2：前端
cd frontend
npm install
npm run dev
```

- 后端默认运行在 `http://127.0.0.1:8080`
- 前端开发服务器默认运行在 `http://127.0.0.1:3000`
- 数据库默认使用 PostgreSQL，联调脚本可切换到后端 `local-it` 配置

### Docker开发环境

```bash
docker-compose up -d
```

- 前端: `http://localhost:3000`
- 后端 API: `http://localhost:8080`
- 数据库: `localhost:5432`

## 项目结构

```
drawing_board/
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
├── docs/                    # 项目文档
├── database/                # 数据库脚本
├── scripts/                 # 开发与联调脚本
└── docker-compose.yml       # Docker开发编排
```

## 开发指南

### 常用命令

```bash
# 后端测试
cd drawing-board-backend && ./gradlew test

# 前端构建
cd frontend && npm run build

# 本地联调
./scripts/integration/integration.sh
```

### 开发约定

- **Java**: Google Java Style + Spotless
- **TypeScript**: ESLint + Prettier + Vue 风格指南
- **Git**: Conventional Commits
- **TDD流程**: 红-绿-重构
- **测试重点**: 核心领域逻辑、模块边界、关键联调流程
- **测试类型**: 单元测试、集成测试、E2E测试

- 更多脚本、联调方式和部署信息见 `docs/DEVELOPMENT.md`、`docs/DEPLOYMENT.md`、`desktop/README.md`

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
