# 贡献指南

感谢您有兴趣为Drawing Board Pro项目做出贡献！本指南将帮助您了解如何参与项目开发。

## 行为准则

本项目遵循[贡献者公约行为准则](https://www.contributor-covenant.org/)。请确保阅读并理解该准则。我们期望所有贡献者都能创造一个友好、包容的环境。

## 如何开始

### 1. 寻找贡献机会

#### 新手友好的任务
- 文档改进和翻译
- 代码注释和文档字符串
- 测试用例编写
- 界面文本校对
- 简单的bug修复

#### 功能开发
- 查看 [GitHub Issues](https://github.com/Purple-Hyacinthi/drawing_board/issues) 中的功能请求
- 寻找标有 `good-first-issue` 或 `help-wanted` 的标签
- 参与讨论，明确需求后再开始开发

#### Bug修复
- 重现bug并创建最小复现示例
- 查看现有issue，避免重复
- 提供详细的bug报告

### 2. 开发环境设置

#### 系统要求
- Java 21+ (推荐Temurin发行版)
- Node.js 18+ (推荐20+)
- PostgreSQL 15+
- Docker 20.10+ (可选)
- Git

#### 本地环境设置
```bash
# 1. 克隆仓库
 git clone https://github.com/Purple-Hyacinthi/drawing_board.git
 cd drawing_board

# 2. 安装前端依赖
cd frontend
npm install

# 3. 设置后端
cd ../drawing-board-backend
# Gradle Wrapper会自动下载Gradle

# 4. 配置环境变量
cp .env.example .env.development
# 编辑 .env.development 文件

# 5. 启动数据库
docker-compose up -d postgres

# 6. 启动应用
# 后端
./gradlew bootRun
# 前端 (另一个终端)
cd frontend
npm run dev
```

#### 使用Docker开发
```bash
# 使用Docker Compose启动完整开发环境
docker-compose up -d

# 查看日志
docker-compose logs -f
```

### 3. 项目结构

```
drawing-board/
├── drawing-board-backend/     # Spring Modulith后端
│   ├── application/          # 主应用模块
│   ├── user/                # 用户管理模块
│   ├── canvas/              # 画布管理模块
│   ├── drawing/             # 绘图操作模块
│   └── export/              # 导出功能模块
├── frontend/                # Vue 3前端
├── desktop/                 # QT桌面应用
├── docs/                    # 项目文档
└── scripts/                 # 构建和部署脚本
```

## 开发流程

### 1. 分支策略

```
main (受保护，只接受PR)
├── develop (主开发分支)
├── feature/* (功能分支)
├── bugfix/* (bug修复分支)
├── hotfix/* (紧急修复分支)
└── release/* (发布分支)
```

### 2. Git工作流

#### 创建功能分支
```bash
# 从develop分支创建新分支
git checkout develop
git pull origin develop
git checkout -b feature/your-feature-name

# 或修复bug
git checkout -b bugfix/issue-number-description
```

#### 提交规范
使用 [Conventional Commits](https://www.conventionalcommits.org/) 规范：

```
<type>(<scope>): <subject>

<body>

<footer>
```

**提交类型**:
- `feat`: 新功能
- `fix`: 修复bug
- `docs`: 文档更新
- `style`: 代码格式（不影响功能）
- `refactor`: 重构（不添加功能也不修复bug）
- `test`: 测试相关
- `chore`: 构建过程或辅助工具的变动

**示例**:
```bash
feat(canvas): add layer grouping functionality

- Add group creation and management API
- Implement UI for layer grouping
- Add tests for group operations

Closes #123
```

### 3. 代码规范

#### Java代码
- 遵循 [Google Java Style Guide](https://google.github.io/styleguide/javaguide.html)
- 使用Spotless进行代码格式化
- 方法不超过20行，类不超过300行
- 使用有意义的命名，避免缩写

```bash
# 格式化Java代码
./gradlew spotlessApply

# 检查格式
./gradlew spotlessCheck
```

#### TypeScript/Vue代码
- 使用ESLint和Prettier
- 遵循Vue官方风格指南
- 使用组合式API (`<script setup>`)

```bash
# 检查代码质量
npm run lint

# 格式化代码
npm run format
```

### 4. 测试要求

#### 测试驱动开发(TDD)
遵循红-绿-重构循环：
1. **RED**: 编写一个失败的测试
2. **GREEN**: 编写最简单的代码使测试通过
3. **REFACTOR**: 重构代码，保持测试通过

#### 测试覆盖率
- **单元测试**: >90% (JaCoCo强制要求)
- **集成测试**: 覆盖所有模块边界
- **E2E测试**: 关键用户流程

```bash
# 运行所有测试
./scripts/build/test.sh

# 生成测试报告
./gradlew jacocoTestReport
```

#### 编写测试示例
```java
// 后端测试示例
@ExtendWith(MockitoExtension.class)
class CanvasServiceTest {
    
    @Test
    void givenValidCanvasData_whenCreateCanvas_thenCanvasIsCreated() {
        // Arrange
        CanvasCreateCommand command = new CanvasCreateCommand("Test", 800, 600);
        
        // Act
        Canvas result = canvasService.createCanvas(command);
        
        // Assert
        assertThat(result).isNotNull();
        assertThat(result.getTitle()).isEqualTo("Test");
        assertThat(result.getWidth()).isEqualTo(800);
    }
}
```

```typescript
// 前端测试示例
describe('CanvasView', () => {
  it('should render drawing tools', () => {
    // 测试逻辑
  })
})
```

## Pull Request流程

### 1. 创建PR前检查
- [ ] 代码遵循项目规范
- [ ] 所有测试通过
- [ ] 添加或更新了相关测试
- [ ] 更新了相关文档
- [ ] 提交信息符合规范
- [ ] 没有引入新的警告或错误

### 2. PR模板
创建PR时请使用以下模板：

```markdown
## 描述
简要描述本次PR的内容和目的。

## 相关Issue
链接相关Issue，例如：Closes #123

## 变更类型
- [ ] Bug修复
- [ ] 新功能
- [ ] 重构
- [ ] 文档更新
- [ ] 其他（请说明）

## 测试
- [ ] 单元测试已添加/更新
- [ ] 集成测试已添加/更新
- [ ] 所有测试通过

## 清单
- [ ] 我的代码遵循项目的代码规范
- [ ] 我进行了自我代码审查
- [ ] 我添加了相关注释（如果需要）
- [ ] 文档已相应更新

## 截图（如果适用）
添加UI变更的截图。

## 额外说明
任何额外的说明或上下文。
```

### 3. 代码审查
- 至少需要一个核心成员的批准
- 审查意见必须被解决或讨论
- 保持专业和建设性的反馈

### 4. 合并后
- 删除功能分支
- 更新相关文档
- 通知相关方

## 架构指南

### 后端架构 (Spring Modulith)
- **模块划分**: 按业务功能划分模块
- **模块通信**: 通过接口和事件通信
- **依赖方向**: 高层模块不依赖低层模块

### 前端架构 (Vue 3)
- **组件设计**: 单一职责，可复用
- **状态管理**: 使用Pinia管理全局状态
- **代码组织**: 按功能组织代码

### 桌面应用 (QT)
- **Web集成**: 使用QT WebEngine嵌入前端
- **本地功能**: 通过桥接提供本地功能
- **跨平台**: 确保Windows/macOS/Linux兼容性

## 文档要求

### 代码文档
- 公共API必须有JavaDoc/TSDoc注释
- 复杂算法必须有解释性注释
- 避免显而易见的注释

### 项目文档
- 保持文档与代码同步
- 使用清晰、简洁的语言
- 包含示例代码和截图

### 更新文档
当修改以下内容时，必须更新相应文档：
- 公共API接口
- 配置选项
- 数据库架构
- 部署流程

## 发布流程

### 版本管理
使用语义化版本控制：
- **主版本**: 不兼容的API变更
- **次版本**: 向后兼容的功能添加
- **修订号**: 向后兼容的bug修复

### 发布检查清单
1. [ ] 所有测试通过
2. [ ] 文档已更新
3. [ ] CHANGELOG已更新
4. [ ] 版本号已更新
5. [ ] 发布分支已创建
6. [ ] 预发布测试已完成
7. [ ] 发布公告已准备

## 获取帮助

### 沟通渠道
- **GitHub Issues**: 报告bug和功能请求
- **GitHub Discussions**: 讨论想法和问题
- **Discord社区**: 实时交流和协作

### 寻求帮助
1. 先查看文档和现有issue
2. 提供详细的问题描述
3. 提供复现步骤和环境信息
4. 保持耐心和礼貌

## 致谢

感谢所有贡献者的时间和努力！您的贡献使这个项目变得更好。

---

*本贡献指南会根据项目发展进行更新。*
*最后更新: 2025-03-05*
