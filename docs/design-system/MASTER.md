# Drawing Board Pro - 设计系统

## 概述

Drawing Board Pro的设计系统旨在提供一致、直观且美观的用户体验。本设计系统基于以下核心原则：

1. **功能优先**: 设计服务于功能，不牺牲可用性
2. **一致性**: 跨平台、跨组件的一致体验
3. **可访问性**: 确保所有用户都能使用
4. **性能**: 轻量、快速、响应迅速

## 1. 设计原则

### 1.1 核心原则
- **简洁明了**: 减少认知负荷，直观操作
- **反馈及时**: 操作有明确视觉反馈
- **容错设计**: 支持撤消、重做和恢复
- **渐进披露**: 复杂功能逐步呈现

### 1.2 用户体验原则
- **首屏体验**: 3秒内加载完成，立即可用
- **操作效率**: 常用功能一键可达
- **学习曲线**: 新手友好，专家高效
- **个性化**: 支持界面和功能定制

## 2. 颜色系统

### 2.1 品牌色彩
| 名称 | HEX | RGB | 使用场景 |
|------|-----|-----|----------|
| 主蓝 | #3b82f6 | rgb(59, 130, 246) | 主要按钮、重要操作 |
| 辅助蓝 | #60a5fa | rgb(96, 165, 250) | 次要按钮、悬停状态 |
| 成功绿 | #10b981 | rgb(16, 185, 129) | 成功状态、完成操作 |
| 警告黄 | #f59e0b | rgb(245, 158, 11) | 警告提示、需要注意 |
| 错误红 | #ef4444 | rgb(239, 68, 68) | 错误状态、危险操作 |
| 中性灰 | #6b7280 | rgb(107, 114, 128) | 文本、边框、禁用状态 |

### 2.2 中性色板
```css
/* 文本颜色 */
--text-primary: #111827;    /* 主要文本 */
--text-secondary: #6b7280;  /* 次要文本 */
--text-tertiary: #9ca3af;   /* 辅助文本 */
--text-disabled: #d1d5db;   /* 禁用文本 */

/* 背景颜色 */
--bg-primary: #ffffff;      /* 主要背景 */
--bg-secondary: #f9fafb;    /* 次要背景 */
--bg-tertiary: #f3f4f6;     /* 三级背景 */
--bg-overlay: rgba(0,0,0,0.5); /* 遮罩层 */

/* 边框颜色 */
--border-light: #e5e7eb;    /* 浅色边框 */
--border-medium: #d1d5db;   /* 中等边框 */
--border-dark: #9ca3af;     /* 深色边框 */
```

### 2.3 功能色板
```css
/* 画布颜色 */
--canvas-bg: #ffffff;       /* 画布背景 */
--canvas-grid: #f0f0f0;     /* 网格线 */
--canvas-guide: #3b82f6;    /* 参考线 */

/* 工具状态 */
--tool-active: #3b82f6;     /* 活动工具 */
--tool-hover: #93c5fd;      /* 悬停状态 */
--tool-selected: #dbeafe;   /* 选中状态 */

/* 图层状态 */
--layer-active: #10b981;    /* 活动图层 */
--layer-locked: #ef4444;    /* 锁定图层 */
--layer-hidden: #9ca3af;    /* 隐藏图层 */
```

### 2.4 可访问性要求
- **文本对比度**: 最小4.5:1 (WCAG AA)
- **非文本对比度**: 最小3:1
- **颜色不单独传达信息**: 结合图标或文字
- **色盲友好**: 通过形状、纹理区分

## 3. 排版系统

### 3.1 字体家族
```css
/* 主要字体 */
font-family: 'Inter', system-ui, -apple-system, sans-serif;

/* 等宽字体 */
font-family: 'JetBrains Mono', 'Menlo', 'Monaco', monospace;

/* 备用字体 */
font-family: system-ui, -apple-system, 'Segoe UI', Roboto, sans-serif;
```

### 3.2 字体缩放
| 名称 | 大小 | 行高 | 字重 | 使用场景 |
|------|------|------|------|----------|
| 超大标题 | 48px | 56px | 700 | 营销页面标题 |
| 大标题 | 36px | 44px | 700 | 页面标题 |
| 中标题 | 30px | 38px | 600 | 主要分区标题 |
| 小标题 | 24px | 32px | 600 | 次要分区标题 |
| 正文大 | 20px | 28px | 400 | 重要正文 |
| 正文 | 16px | 24px | 400 | 主要正文 |
| 正文小 | 14px | 20px | 400 | 辅助文本 |
| 标签 | 12px | 16px | 500 | 标签、说明 |
| 代码 | 14px | 20px | 400 | 代码显示 |

### 3.3 排版规则
- **行长限制**: 正文每行45-75字符
- **段落间距**: 段落间1.5倍行高
- **标题层次**: 清晰的视觉层次
- **对齐方式**: 左对齐为主，特殊用途居中对齐

## 4. 间距系统

### 4.1 间距比例
基于8px为基准单位的间距系统：

```css
--space-1: 4px;    /* 微小间距 */
--space-2: 8px;    /* 小间距 */
--space-3: 12px;   /* 中等偏小 */
--space-4: 16px;   /* 基准间距 */
--space-5: 24px;   /* 中等间距 */
--space-6: 32px;   /* 大间距 */
--space-7: 48px;   /* 超大间距 */
--space-8: 64px;   /* 巨大间距 */
```

### 4.2 应用规则
```css
/* 内边距 */
.padding-small { padding: var(--space-2); }
.padding-medium { padding: var(--space-4); }
.padding-large { padding: var(--space-6); }

/* 外边距 */
.margin-small { margin: var(--space-2); }
.margin-medium { margin: var(--space-4); }
.margin-large { margin: var(--space-6); }

/* 间距组件 */
.gap-small { gap: var(--space-2); }
.gap-medium { gap: var(--space-4); }
.gap-large { gap: var(--space-6); }
```

### 4.3 布局间距
| 场景 | 水平间距 | 垂直间距 |
|------|----------|----------|
| 页面容器 | 24px | 32px |
| 卡片内部 | 16px | 16px |
| 表单字段 | 8px | 12px |
| 按钮组 | 8px | 8px |
| 工具栏 | 4px | 4px |

## 5. 圆角系统

### 5.1 圆角等级
```css
--radius-none: 0;      /* 无圆角 */
--radius-sm: 4px;      /* 小圆角 */
--radius-md: 8px;      /* 中等圆角 */
--radius-lg: 12px;     /* 大圆角 */
--radius-xl: 16px;     /* 超大圆角 */
--radius-full: 9999px; /* 完全圆角 */
```

### 5.2 应用场景
| 组件 | 圆角大小 | 说明 |
|------|----------|------|
| 按钮 | --radius-md | 中等圆角，友好触感 |
| 卡片 | --radius-lg | 大圆角，柔和外观 |
| 输入框 | --radius-md | 中等圆角，一致体验 |
| 模态框 | --radius-lg | 大圆角，突出焦点 |
| 头像 | --radius-full | 圆形，视觉重点 |
| 标签 | --radius-sm | 小圆角，紧凑标签 |

## 6. 阴影系统

### 6.1 阴影等级
```css
/* 基础阴影 */
--shadow-sm: 0 1px 2px 0 rgba(0, 0, 0, 0.05);
--shadow-md: 0 4px 6px -1px rgba(0, 0, 0, 0.1);
--shadow-lg: 0 10px 15px -3px rgba(0, 0, 0, 0.1);
--shadow-xl: 0 20px 25px -5px rgba(0, 0, 0, 0.1);

/* 特殊阴影 */
--shadow-inner: inset 0 2px 4px 0 rgba(0, 0, 0, 0.06);
--shadow-focus: 0 0 0 3px rgba(59, 130, 246, 0.5);
--shadow-tooltip: 0 4px 20px rgba(0, 0, 0, 0.15);
```

### 6.2 应用场景
| 组件 | 阴影 | 说明 |
|------|------|------|
| 卡片 | --shadow-md | 中等阴影，轻度立体感 |
| 模态框 | --shadow-xl | 强烈阴影，突出层级 |
| 工具栏 | --shadow-sm | 轻微阴影，表示可交互 |
| 按钮悬停 | --shadow-md | 悬停时增强立体感 |
| 输入框焦点 | --shadow-focus | 焦点状态，蓝色发光 |
| 工具提示 | --shadow-tooltip | 柔和阴影，不干扰内容 |

## 7. 动效系统

### 7.1 缓动函数
```css
/* 标准缓动 */
--ease-linear: cubic-bezier(0, 0, 1, 1);
--ease-in: cubic-bezier(0.4, 0, 1, 1);
--ease-out: cubic-bezier(0, 0, 0.2, 1);
--ease-in-out: cubic-bezier(0.4, 0, 0.2, 1);

/* 自定义缓动 */
--ease-bounce: cubic-bezier(0.68, -0.55, 0.265, 1.55);
--ease-elastic: cubic-bezier(0.68, -0.55, 0.265, 1.55);
```

### 7.2 持续时间
```css
--duration-instant: 0ms;    /* 即时 */
--duration-fast: 100ms;     /* 快速 */
--duration-normal: 200ms;   /* 标准 */
--duration-slow: 300ms;     /* 慢速 */
--duration-deliberate: 500ms; /* 刻意慢速 */
```

### 7.3 动画模式
| 场景 | 持续时间 | 缓动函数 | 说明 |
|------|----------|----------|------|
| 悬停效果 | 150ms | ease-out | 快速响应 |
| 状态切换 | 200ms | ease-in-out | 平滑过渡 |
| 页面切换 | 300ms | ease-in-out | 明显但不唐突 |
| 加载动画 | 600ms | ease-in-out | 明显等待 |
| 成功反馈 | 400ms | ease-bounce | 愉悦反馈 |

## 8. 图标系统

### 8.1 图标库
使用 **Lucide Icons** 作为主要图标库，备用 **Heroicons**。

### 8.2 图标尺寸
```css
/* 标准尺寸 */
--icon-xs: 12px;    /* 超小图标 */
--icon-sm: 16px;    /* 小图标 */
--icon-md: 20px;    /* 中等图标 */
--icon-lg: 24px;    /* 大图标 */
--icon-xl: 32px;    /* 超大图标 */
```

### 8.3 图标使用规则
1. **一致性**: 相同功能使用相同图标
2. **清晰度**: 图标含义明确，避免歧义
3. **可访问性**: 重要图标提供文字标签
4. **状态表示**: 不同状态使用不同图标变体

## 9. 组件库

### 9.1 基础组件

#### 按钮 (Button)
```css
/* 按钮变体 */
.btn-primary {
  background-color: var(--color-primary);
  color: white;
}

.btn-secondary {
  background-color: var(--color-secondary);
  color: var(--text-primary);
}

.btn-ghost {
  background-color: transparent;
  border: 1px solid var(--border-light);
}

/* 按钮尺寸 */
.btn-sm { padding: var(--space-2) var(--space-3); }
.btn-md { padding: var(--space-3) var(--space-5); }
.btn-lg { padding: var(--space-4) var(--space-6); }
```

#### 输入框 (Input)
```css
.input-base {
  border: 1px solid var(--border-medium);
  border-radius: var(--radius-md);
  padding: var(--space-3) var(--space-4);
}

.input-focus {
  border-color: var(--color-primary);
  box-shadow: var(--shadow-focus);
}

.input-error {
  border-color: var(--color-error);
}
```

#### 卡片 (Card)
```css
.card-base {
  background-color: var(--bg-primary);
  border-radius: var(--radius-lg);
  box-shadow: var(--shadow-md);
  padding: var(--space-6);
}

.card-hover {
  box-shadow: var(--shadow-lg);
  transform: translateY(-2px);
}
```

### 9.2 专业组件

#### 颜色选择器 (ColorPicker)
- **显示模式**: 色环、色板、滑块
- **透明度支持**: 支持Alpha通道
- **预设管理**: 保存和加载颜色预设
- **历史记录**: 最近使用颜色

#### 图层面板 (LayerPanel)
- **层级显示**: 清晰显示图层堆叠
- **批量操作**: 多选图层操作
- **预览功能**: 缩略图预览
- **过滤搜索**: 按名称搜索图层

#### 工具栏 (Toolbar)
- **分组显示**: 相关工具分组
- **自定义布局**: 拖拽调整工具位置
- **工具提示**: 悬停显示工具说明
- **快捷键显示**: 显示对应快捷键

## 10. 布局系统

### 10.1 响应式断点
```css
/* 移动设备优先 */
--breakpoint-sm: 640px;   /* 小屏幕 */
--breakpoint-md: 768px;   /* 中等屏幕 */
--breakpoint-lg: 1024px;  /* 大屏幕 */
--breakpoint-xl: 1280px;  /* 超大屏幕 */
--breakpoint-2xl: 1536px; /* 2倍超大屏幕 */
```

### 10.2 网格系统
```css
/* 12列网格 */
.grid-12 {
  display: grid;
  grid-template-columns: repeat(12, 1fr);
  gap: var(--space-4);
}

/* 自适应网格 */
.grid-auto {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
  gap: var(--space-4);
}
```

### 10.3 布局容器
```css
/* 内容容器 */
.container-sm { max-width: 640px; }
.container-md { max-width: 768px; }
.container-lg { max-width: 1024px; }
.container-xl { max-width: 1280px; }
.container-fluid { max-width: 100%; }
```

## 11. 可访问性指南

### 11.1 键盘导航
- **Tab顺序**: 逻辑化Tab顺序
- **焦点样式**: 明显的焦点指示器
- **快捷键**: 常用功能提供快捷键
- **跳过导航**: 提供跳过重复内容的链接

### 11.2 屏幕阅读器支持
- **语义HTML**: 使用正确的HTML标签
- **ARIA属性**: 必要组件添加ARIA属性
- **替代文本**: 所有图像提供alt文本
- **动态内容**: 动态更新通知屏幕阅读器

### 11.3 运动偏好
```css
/* 尊重用户偏好 */
@media (prefers-reduced-motion: reduce) {
  * {
    animation-duration: 0.01ms !important;
    animation-iteration-count: 1 !important;
    transition-duration: 0.01ms !important;
  }
}
```

## 12. 设计令牌

### 12.1 设计变量
所有设计值都通过CSS变量定义，便于主题切换和维护。

### 12.2 主题切换
支持浅色和深色主题，自动跟随系统设置。

### 12.3 自定义主题
用户可自定义部分设计变量（如主色调）。

## 13. 实现指南

### 13.1 前端实现
使用 **Tailwind CSS** 作为主要CSS框架，辅以自定义CSS变量。

### 13.2 设计资产管理
所有设计资产（图标、图片、字体）集中管理，确保一致性。

### 13.3 设计评审
所有UI变更需经过设计评审，确保符合设计系统。

---

*设计系统版本: 1.0.0*
*最后更新: 2025-03-05*