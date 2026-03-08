# 更新日志

本文件用于记录 Drawing Board Pro 的重要变更。

格式参考 [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)，
版本号遵循 [Semantic Versioning](https://semver.org/spec/v2.0.0.html)。

## [Unreleased]

### 新增
- 初始项目结构与架构设计
- 基础绘图工具 画笔 铅笔 橡皮 形状
- 图层管理系统
- 文件导出功能 PNG JPEG SVG
- 用户认证与鉴权
- 跨平台桌面应用框架
- 完整项目文档
- 前端纯画板页面 进入应用即绘制
- 基于 Pointer 事件的基础笔触绘制能力
- 面向中文用户的简化用户指南

### 变更
- 前端路由收敛为单页面模式 统一进入画板
- 应用壳移除首页 画廊 导航栏和底部信息
- 前端可见文案与说明文档优先使用中文
- 架构文档和开发文档已同步为纯画板实现

### 弃用
- 无 初始发布

### 移除
- 移除未使用页面 `HomeView.vue` 和 `GalleryView.vue`
- 移除旧版多页面前端描述与不匹配示例

### 修复
- 无 初始发布

### 安全
- 基于 JWT 的认证机制
- 使用 bcrypt 进行密码哈希
- 输入参数校验与清洗
- CORS 与安全响应头配置

---

## 发布说明

### 版本方案

本项目使用 [Semantic Versioning](https://semver.org/)：
- **MAJOR** 不兼容的 API 变更
- **MINOR** 向后兼容的功能新增
- **PATCH** 向后兼容的问题修复

### 发布流程
1. **开发** 在功能分支开发
2. **测试** 核心测试通过并完成发布前检查
3. **代码审查** 至少一名开发者完成 PR 审查
4. **合并** 审查通过后合并到 main
5. **发布准备** 从 main 创建发布标签或发布分支
6. **回归测试** 在发布分支执行完整回归
7. **文档更新** 同步更新相关文档
8. **发布** 合并到 main 并打标签
9. **部署** 发布到生产环境

### 升级说明

#### 从 Unreleased 到 1.0.0
这是当前仓库的首个公开整理版本 无需升级步骤。

### 已知问题
- 当前前端为纯画板模式 未提供实时协作界面
- 复杂形状场景下 部分 SVG 导出可能存在渲染偏差
- 桌面端发布流程目前主要覆盖 Windows 打包链路

### 弃用策略
- 功能会在一个主版本中标记为弃用
- 弃用功能将在下一个主版本移除
- 将提供对应迁移指南

---

## 致谢

### 贡献者
- Drawing Board Pro 开发团队
- 开源社区贡献者
- Beta 测试用户与早期体验者

### 使用技术
- [Spring Boot](https://spring.io/projects/spring-boot)
- [Vue.js](https://vuejs.org/)
- [PostgreSQL](https://www.postgresql.org/)
- [QT](https://www.qt.io/)
- [Tailwind CSS](https://tailwindcss.com/)
- 以及更多开源库

### 许可证

本项目采用 MIT 许可证，详见 [LICENSE](LICENSE)。

---

本更新日志由 Drawing Board Pro 开发团队维护。
如有问题或建议，请在 GitHub 提交 Issue。
