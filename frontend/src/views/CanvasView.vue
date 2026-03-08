<template>
  <div class="ps-app">
    <svg class="svg-defs" aria-hidden="true">
      <symbol id="icon-move" viewBox="0 0 24 24">
        <path d="M12 2l3 3h-2v5h5V8l3 3-3 3v-2h-5v5h2l-3 3-3-3h2v-5H5v2l-3-3 3-3v2h5V5H9z" />
      </symbol>
      <symbol id="icon-select" viewBox="0 0 24 24">
        <path d="M6 5h3v2H6v3H4V6a1 1 0 0 1 1-1h1zm9 0h4a1 1 0 0 1 1 1v4h-2V7h-3V5zM4 14h2v3h3v2H5a1 1 0 0 1-1-1v-4zm14 0h2v4a1 1 0 0 1-1 1h-4v-2h3v-3zM8 8h8v8H8z" />
      </symbol>
      <symbol id="icon-brush" viewBox="0 0 24 24">
        <path d="M14.8 4.2l5 5-8.6 8.6c-1.8 1.8-4.8 2-6.4.4-.8-.8-.8-2 0-2.8l4.2-4.2c1-.9 2.5-.9 3.5 0 .8.9 2.2 1 3 .2l5.3-5.3zM4.2 20.2c-1.1 1.1-1.1 2.9 0 4 1.1 1.1 2.9 1.1 4 0 .8-.8.8-2 0-2.8-.8-.8-2-.8-2.8 0-.3.3-.8.3-1.1 0-.3-.3-.3-.8 0-1.1z" />
      </symbol>
      <symbol id="icon-pencil" viewBox="0 0 24 24">
        <path d="M3 17.2V21h3.8L18.5 9.3l-3.8-3.8L3 17.2zM20.7 7.1c.4-.4.4-1 0-1.4l-2.4-2.4c-.4-.4-1-.4-1.4 0l-1.6 1.6 3.8 3.8 1.6-1.6z" />
      </symbol>
      <symbol id="icon-ink" viewBox="0 0 24 24">
        <path d="M12 2c2.8 3.1 6.5 7.1 6.5 11.1A6.5 6.5 0 1 1 5.5 13.1C5.5 9.1 9.2 5.1 12 2zm-4 13.8c0 1.9 1.6 3.4 3.6 3.4.5 0 .9-.4.9-.8s-.4-.8-.9-.8c-1.1 0-2-.8-2-1.8 0-.4-.4-.8-.8-.8s-.8.4-.8.8z" />
      </symbol>
      <symbol id="icon-eraser" viewBox="0 0 24 24">
        <path d="M16.3 3.7l4 4c.9.9.9 2.3 0 3.2l-7.9 7.9c-.6.6-1.4.9-2.3.9H4.9c-.5 0-.9-.4-.9-.9s.4-.9.9-.9h5.2c.4 0 .7-.1 1-.4l7.9-7.9c.2-.2.2-.6 0-.8l-4-4c-.2-.2-.6-.2-.8 0L6.3 12.7c-.2.2-.2.6 0 .8l2.2 2.2c.3.3.3.9 0 1.2-.3.3-.9.3-1.2 0l-2.2-2.2c-.9-.9-.9-2.3 0-3.2l7.9-7.9c.9-.9 2.3-.9 3.2 0z" />
      </symbol>
      <symbol id="icon-eyedropper" viewBox="0 0 24 24">
        <path d="M14.5 3.1a3.2 3.2 0 0 1 4.4 4.7l-1.4 1.4 1.2 1.2c.4.4.4 1 0 1.4l-2.4 2.4c-.4.4-1 .4-1.4 0l-1.2-1.2-6.3 6.3a2.7 2.7 0 0 1-1.9.8H3.4c-.5 0-.9-.4-.9-.9v-2.1c0-.7.3-1.4.8-1.9l6.3-6.3-1.2-1.2c-.4-.4-.4-1 0-1.4L10.8 4c.4-.4 1-.4 1.4 0l1.2 1.2 1.1-2.1zm1.8 4.5c.6-.6.6-1.5 0-2.1-.6-.6-1.5-.6-2.1 0L8.9 15.8h.4c.8 0 1.6.3 2.2.9l4.8-4.8-1.2-1.2c-.4-.4-.4-1 0-1.4l1.2-1.2z" />
      </symbol>
      <symbol id="icon-lasso" viewBox="0 0 24 24">
        <path
          d="M4.5 10.3c0-3.8 3.4-6.8 7.6-6.8s7.4 2.6 7.4 6.2c0 3-2.3 4.9-5.3 6.3-2.9 1.3-4.8 2.3-4.8 3.9 0 1.1.9 1.8 2.1 1.8 1.4 0 2.3-.8 2.3-1.8 0-.9-.8-1.5-2.1-1.5"
          fill="none"
          stroke-width="2"
          stroke-linecap="round"
          stroke-linejoin="round"
        />
      </symbol>
      <symbol id="icon-fill" viewBox="0 0 24 24">
        <path
          d="M7 13.1l5.2-5.2 4.8 4.8a2.1 2.1 0 0 1 0 3L14 18.7a2.1 2.1 0 0 1-3 0l-4-4a2.1 2.1 0 0 1 0-3z"
          fill="none"
          stroke-width="2"
          stroke-linecap="round"
          stroke-linejoin="round"
        />
        <path d="M15.2 5.7l2-2" fill="none" stroke-width="2" stroke-linecap="round" />
        <path d="M4 20h8" fill="none" stroke-width="2" stroke-linecap="round" />
        <path d="M18.6 16.7c1.1.8 1.8 1.8 1.8 2.9 0 1.3-1.1 2.4-2.4 2.4s-2.4-1.1-2.4-2.4c0-1.1.8-2.1 1.9-2.9" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-line" viewBox="0 0 24 24">
        <path d="M4 18l16-12" stroke-linecap="round" stroke-width="2.4" fill="none" />
      </symbol>
      <symbol id="icon-curve" viewBox="0 0 24 24">
        <path d="M4 18c4-9 12-9 16 0" stroke-linecap="round" stroke-width="2.2" fill="none" />
      </symbol>
      <symbol id="icon-rect" viewBox="0 0 24 24">
        <rect x="4" y="5" width="16" height="14" rx="1" ry="1" fill="none" stroke-width="2" />
      </symbol>
      <symbol id="icon-rounded-rect" viewBox="0 0 24 24">
        <rect x="4" y="5" width="16" height="14" rx="4" ry="4" fill="none" stroke-width="2" />
      </symbol>
      <symbol id="icon-ellipse" viewBox="0 0 24 24">
        <ellipse cx="12" cy="12" rx="8" ry="6" fill="none" stroke-width="2" />
      </symbol>
      <symbol id="icon-triangle" viewBox="0 0 24 24">
        <path d="M12 5l8 14H4z" fill="none" stroke-width="2" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-diamond" viewBox="0 0 24 24">
        <path d="M12 4l7 8-7 8-7-8z" fill="none" stroke-width="2" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-pentagon" viewBox="0 0 24 24">
        <path d="M12 4l7 5.1-2.6 8.4H7.6L5 9.1z" fill="none" stroke-width="2" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-hexagon" viewBox="0 0 24 24">
        <path d="M8 4h8l4 8-4 8H8l-4-8z" fill="none" stroke-width="2" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-arrow-right" viewBox="0 0 24 24">
        <path d="M4 12h12" stroke-width="2" fill="none" stroke-linecap="round" />
        <path d="M12 7l7 5-7 5" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-arrow-left" viewBox="0 0 24 24">
        <path d="M20 12H8" stroke-width="2" fill="none" stroke-linecap="round" />
        <path d="M12 7l-7 5 7 5" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-arrow-up" viewBox="0 0 24 24">
        <path d="M12 20V8" stroke-width="2" fill="none" stroke-linecap="round" />
        <path d="M7 12l5-7 5 7" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-arrow-down" viewBox="0 0 24 24">
        <path d="M12 4v12" stroke-width="2" fill="none" stroke-linecap="round" />
        <path d="M7 12l5 7 5-7" fill="none" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-star4" viewBox="0 0 24 24">
        <path d="M12 3l2.9 6.1L21 12l-6.1 2.9L12 21l-2.9-6.1L3 12l6.1-2.9z" fill="none" stroke-width="2" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-star5" viewBox="0 0 24 24">
        <path d="M12 3l2.7 5.6 6.2.9-4.4 4.3 1 6.2L12 17l-5.5 3 1-6.2L3 9.5l6.2-.9z" fill="none" stroke-width="2" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-chat-bubble" viewBox="0 0 24 24">
        <path d="M5 5h14a2 2 0 0 1 2 2v8a2 2 0 0 1-2 2h-8l-4 3v-3H5a2 2 0 0 1-2-2V7a2 2 0 0 1 2-2z" fill="none" stroke-width="2" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-heart" viewBox="0 0 24 24">
        <path d="M12 20s-7-4.7-7-10a4 4 0 0 1 7-2.2A4 4 0 0 1 19 10c0 5.3-7 10-7 10z" fill="none" stroke-width="2" stroke-linejoin="round" />
      </symbol>
      <symbol id="icon-eye" viewBox="0 0 24 24">
        <path d="M12 5c5.8 0 9.5 5.8 9.5 7s-3.7 7-9.5 7-9.5-5.8-9.5-7 3.7-7 9.5-7zm0 2c-4.2 0-7.1 3.9-7.4 5 .3 1.1 3.2 5 7.4 5s7.1-3.9 7.4-5c-.3-1.1-3.2-5-7.4-5zm0 2.2a2.8 2.8 0 1 1 0 5.6 2.8 2.8 0 0 1 0-5.6z" />
      </symbol>
      <symbol id="icon-lock" viewBox="0 0 24 24">
        <path d="M7.5 10V7.8A4.5 4.5 0 0 1 12 3.3a4.5 4.5 0 0 1 4.5 4.5V10h.8c.9 0 1.7.8 1.7 1.7v7c0 .9-.8 1.7-1.7 1.7H6.7c-.9 0-1.7-.8-1.7-1.7v-7c0-.9.8-1.7 1.7-1.7h.8zm1.8 0h5.4V7.8A2.7 2.7 0 0 0 12 5.1a2.7 2.7 0 0 0-2.7 2.7V10z" />
      </symbol>
      <symbol id="icon-text" viewBox="0 0 24 24">
        <path d="M5 5h14v3h-2V7h-4v10h2.5v2H8.5v-2H11V7H7v1H5z" />
      </symbol>
    </svg>

    <input ref="openFileInputRef" class="hidden-input" type="file" accept=".dbp,.json,image/*" @change="handleOpenLocalFile" />
    <input ref="importImageInputRef" class="hidden-input" type="file" accept="image/*" @change="handleImportImage" />

    <div v-if="showNewDocumentDialog" class="dialog-backdrop" @click.self="closeNewDocumentDialog">
      <section class="new-doc-dialog">
        <h2>新建文档</h2>

        <label class="dialog-field">
          <span>文档名称</span>
          <input v-model="newDocumentForm.name" class="dialog-input" placeholder="输入文档名称" />
        </label>

        <div class="dialog-size-row">
          <label class="dialog-field">
            <span>画布宽度</span>
            <input v-model.number="newDocumentForm.width" type="number" min="320" max="6000" class="dialog-input" />
          </label>

          <label class="dialog-field">
            <span>画布高度</span>
            <input v-model.number="newDocumentForm.height" type="number" min="240" max="6000" class="dialog-input" />
          </label>
        </div>

        <label class="dialog-field">
          <span>背景颜色</span>
          <input v-model="newDocumentForm.backgroundColor" type="color" class="dialog-color" />
        </label>

        <div class="dialog-actions">
          <button type="button" class="dialog-btn" @click="closeNewDocumentDialog">取消</button>
          <button type="button" class="dialog-btn dialog-btn-primary" @click="confirmCreateDocument">创建文档</button>
        </div>
      </section>
    </div>

    <div v-if="showHelpDialog" class="dialog-backdrop" @click.self="closeHelpDialog">
      <section class="help-dialog" @pointerdown.stop>
        <div class="help-header">
          <h2>帮助中心</h2>
          <button type="button" class="dialog-btn" @click="closeHelpDialog">关闭</button>
        </div>

        <div class="help-tabs">
          <button
            type="button"
            class="help-tab"
            :class="{ 'help-tab-active': activeHelpTab === 'usage' }"
            @click="activeHelpTab = 'usage'"
          >
            操作提示
          </button>
          <button
            type="button"
            class="help-tab"
            :class="{ 'help-tab-active': activeHelpTab === 'shortcuts' }"
            @click="activeHelpTab = 'shortcuts'"
          >
            快捷键
          </button>
          <button
            type="button"
            class="help-tab"
            :class="{ 'help-tab-active': activeHelpTab === 'menu' }"
            @click="activeHelpTab = 'menu'"
          >
            菜单说明
          </button>
          <button
            type="button"
            class="help-tab"
            :class="{ 'help-tab-active': activeHelpTab === 'about' }"
            @click="activeHelpTab = 'about'"
          >
            关于
          </button>
        </div>

        <div class="help-content" v-if="activeHelpTab === 'usage'">
          <ul class="help-list">
            <li v-for="tip in usageTips" :key="tip">{{ tip }}</li>
          </ul>
        </div>

        <div class="help-content" v-else-if="activeHelpTab === 'shortcuts'">
          <div class="help-shortcut-search">
            <input
              v-model="helpShortcutKeyword"
              type="search"
              class="help-search-input"
              placeholder="搜索快捷键或功能"
            />
            <span class="help-search-count">{{ filteredShortcutTips.length }} 项</span>
          </div>

          <ul class="help-shortcut-list">
            <li v-for="item in filteredShortcutTips" :key="item.key" class="help-shortcut-item">
              <strong v-html="highlightShortcutText(item.key)"></strong>
              <span v-html="highlightShortcutText(item.description)"></span>
            </li>
          </ul>
          <p v-if="filteredShortcutTips.length === 0" class="help-empty">未找到匹配的快捷键</p>
        </div>

        <div class="help-content" v-else-if="activeHelpTab === 'menu'">
          <section v-for="section in menuGuideSections" :key="section.title" class="help-section-card">
            <div class="help-section-header">
              <h3>{{ section.title }}</h3>
              <p>{{ section.description }}</p>
            </div>
            <ul class="help-list">
              <li v-for="item in section.items" :key="`${section.title}-${item}`">{{ item }}</li>
            </ul>
          </section>
        </div>

        <div class="help-content help-about" v-else>
          <section class="about-hero">
            <div>
              <p class="about-kicker">{{ runtimeModeLabel }}</p>
              <h3>{{ appDisplayName }}</h3>
              <p class="about-description">一个支持图层、选区、画笔、文字和滤镜的轻量绘图工具。</p>
            </div>
            <span class="about-version">v{{ appVersion }}</span>
          </section>

          <div class="about-facts">
            <article v-for="fact in aboutFacts" :key="fact.label" class="about-fact-card">
              <span>{{ fact.label }}</span>
              <strong>{{ fact.value }}</strong>
            </article>
          </div>

          <ul class="help-list">
            <li v-for="line in aboutLines" :key="line">{{ line }}</li>
          </ul>
        </div>
      </section>
    </div>

    <header class="menu-bar">
      <div class="menu-left">
        <div v-for="menu in menus" :key="menu" class="menu-wrap">
          <button
            type="button"
            class="menu-item"
            :class="{ 'menu-item-active': activeMenu === menu }"
            @pointerdown.stop.prevent="toggleMenu(menu)"
            @click.stop.prevent
          >
            {{ menu }}
          </button>

          <div v-if="activeMenu === menu" class="menu-popup" @pointerdown.stop>
            <button
              v-for="action in getMenuActions(menu)"
              :key="action.id"
              type="button"
              class="menu-popup-item"
              :disabled="isMenuActionDisabled(action)"
              @pointerdown.stop.prevent="runMenuAction(action)"
              @click.stop.prevent
            >
              <span>{{ action.label }}</span>
              <span v-if="action.shortcut" class="menu-popup-shortcut">{{ action.shortcut }}</span>
            </button>
          </div>
        </div>
      </div>
      <div class="menu-right">
        <span class="menu-version">v{{ appVersion }}</span>
        <button type="button" class="menu-action" @click="openNewDocumentDialog">新建</button>
        <button type="button" class="menu-action" @click="openLocalFile">打开</button>
        <button type="button" class="menu-action" @click="saveProject">保存项目</button>
        <button type="button" class="menu-action" @click="openImportImage">导入图片</button>
        <button type="button" class="menu-action" @click="exportPng">导出 PNG</button>
        <button type="button" class="menu-action" @click="exportSvg">导出 SVG</button>
      </div>
    </header>

    <div class="toolbar-bar">
      <div class="toolbar-group" v-if="showPresetControl">
        <span class="toolbar-label">笔刷类型</span>
        <div class="brush-type-strip" role="tablist" aria-label="笔刷类型">
          <button
            v-for="preset in brushPresetItems"
            :key="preset.id"
            type="button"
            class="brush-type-btn"
            :class="{ 'brush-type-btn-active': brushPresetId === preset.id && activeTool === preset.tool }"
            @click="handleBrushPresetClick(preset.id)"
          >
            {{ preset.label }}
          </button>
        </div>
      </div>

      <div class="toolbar-group" v-if="activeTool === 'eraser'">
        <span class="toolbar-label">橡皮模式</span>
        <select v-model="eraserMode" class="toolbar-select toolbar-select-short">
          <option value="normal">普通擦除</option>
          <option value="stroke">笔画擦除</option>
        </select>
      </div>

      <div class="toolbar-group" v-if="activeTool === 'shape'">
        <span class="toolbar-label">形状</span>
        <div class="shape-strip" role="listbox" aria-label="形状工具">
          <button
            v-for="item in shapeItems"
            :key="item.value"
            type="button"
            class="shape-strip-btn"
            :class="{ 'shape-strip-btn-active': shapeType === item.value }"
            :title="item.label"
            :aria-label="item.label"
            @click="shapeType = item.value"
          >
            <svg class="shape-strip-icon" viewBox="0 0 24 24" aria-hidden="true">
              <use :href="`#${item.icon}`" />
            </svg>
          </button>
        </div>
        <span class="toolbar-chip">{{ activeShapeLabel }}</span>
      </div>

      <div class="toolbar-group" v-if="activeTool === 'text'">
        <span class="toolbar-label">字体</span>
        <select v-model="textStyle.fontFamily" class="toolbar-select">
          <option v-for="font in fontOptions" :key="font.value" :value="font.value">{{ font.label }}</option>
        </select>
      </div>

      <div class="toolbar-group" v-if="activeTool === 'text'">
        <span class="toolbar-label">字号</span>
        <input v-model.number="textStyle.size" type="number" min="8" max="360" class="toolbar-number" />
      </div>

      <div class="toolbar-group" v-if="activeTool === 'text'">
        <span class="toolbar-label">文字颜色</span>
        <input v-model="textStyle.color" type="color" class="toolbar-color" />
      </div>

      <div class="toolbar-group" v-if="activeTool === 'text'">
        <span class="toolbar-label">样式</span>
        <button
          type="button"
          class="toolbar-toggle"
          :class="{ 'toolbar-toggle-active': textStyle.bold }"
          @click="textStyle.bold = !textStyle.bold"
        >
          粗体
        </button>
        <button
          type="button"
          class="toolbar-toggle"
          :class="{ 'toolbar-toggle-active': textStyle.italic }"
          @click="textStyle.italic = !textStyle.italic"
        >
          斜体
        </button>
      </div>

      <div class="toolbar-group" v-if="activeTool === 'text'">
        <span class="toolbar-label">对齐</span>
        <button
          type="button"
          class="toolbar-toggle"
          :class="{ 'toolbar-toggle-active': textStyle.align === 'left' }"
          @click="textStyle.align = 'left'"
        >
          左对齐
        </button>
        <button
          type="button"
          class="toolbar-toggle"
          :class="{ 'toolbar-toggle-active': textStyle.align === 'center' }"
          @click="textStyle.align = 'center'"
        >
          居中
        </button>
        <button
          type="button"
          class="toolbar-toggle"
          :class="{ 'toolbar-toggle-active': textStyle.align === 'right' }"
          @click="textStyle.align = 'right'"
        >
          右对齐
        </button>
      </div>

      <div class="toolbar-group" v-if="activeTool === 'text'">
        <span class="toolbar-label">行距</span>
        <input v-model.number="textStyle.lineHeight" type="number" min="1" max="3" step="0.05" class="toolbar-number" />
      </div>

      <div class="toolbar-group" v-if="activeTool === 'text'">
        <span class="toolbar-label">字距</span>
        <input v-model.number="textStyle.letterSpacing" type="number" min="-8" max="40" step="0.5" class="toolbar-number" />
      </div>

      <div class="toolbar-group" v-if="showColorControl">
        <span class="toolbar-label">颜色</span>
        <input v-model="brushColor" type="color" class="toolbar-color" />
      </div>

      <div class="toolbar-group" v-if="showSizeControl">
        <span class="toolbar-label">大小</span>
        <input v-model.number="brushSize" type="range" min="1" max="180" class="toolbar-range" />
        <strong>{{ brushSize }} px</strong>
      </div>

      <div class="toolbar-group" v-if="showOpacityControl">
        <span class="toolbar-label">不透明度</span>
        <input v-model.number="brushOpacity" type="range" min="1" max="100" class="toolbar-range" />
        <strong>{{ brushOpacity }}%</strong>
      </div>

      <div class="toolbar-group">
        <span class="toolbar-label">滤镜强度</span>
        <input v-model.number="filterIntensity" type="range" min="1" max="100" class="toolbar-range" />
        <strong>{{ filterIntensity }}%</strong>
      </div>

      <label class="toolbar-check" v-if="showPressureControl">
        <input v-model="pressureEnabled" type="checkbox" />
        <span>压感</span>
      </label>

      <button type="button" class="toolbar-action" :disabled="!canUndo" @click="undo">撤销</button>
      <button type="button" class="toolbar-action" :disabled="!canRedo" @click="redo">重做</button>
      <button type="button" class="toolbar-action" @click="clearActiveLayer">清空当前层</button>
      <button type="button" class="toolbar-action" @click="fitCanvasToViewport">适应窗口</button>
      <button type="button" class="toolbar-action" @click="zoomOut">缩小</button>
      <button type="button" class="toolbar-zoom">{{ zoomLabel }}</button>
      <button type="button" class="toolbar-action" @click="zoomIn">放大</button>

      <div class="toolbar-group" v-if="hasFloatingSelection">
        <button type="button" class="toolbar-action" @click="commitFloatingSelection(true)">应用选区</button>
        <button type="button" class="toolbar-action" @click="clearFloatingSelectionAndRender">取消选区</button>
      </div>

      <div class="toolbar-group toolbar-size-group">
        <span class="toolbar-label">画布</span>
        <input v-model.number="canvasSizeDraft.width" type="number" min="320" max="6000" class="toolbar-number" />
        <span class="toolbar-multiply">×</span>
        <input v-model.number="canvasSizeDraft.height" type="number" min="240" max="6000" class="toolbar-number" />
        <button type="button" class="toolbar-action" @click="applyCanvasSize">应用尺寸</button>
      </div>
    </div>

    <main class="workspace" :class="{ 'workspace-no-side': !sidePanelVisible }">
      <aside class="tools-panel">
        <button
          v-for="tool in tools"
          :key="tool.id"
          type="button"
          class="tool-btn"
          :class="{ 'tool-btn-active': activeTool === tool.id }"
          :title="tool.label"
            @click="handleToolSelection(tool.id)"
          >
          <svg v-if="tool.iconType === 'symbol'" class="tool-icon" viewBox="0 0 24 24" aria-hidden="true">
            <use :href="`#${tool.id === 'shape' ? activeShapeIcon : tool.icon}`" />
          </svg>
          <img v-else :src="tool.icon" :alt="`${tool.label} 图标`" class="tool-icon-image" />
          <span class="tool-text">{{ tool.label }}</span>
        </button>
      </aside>

      <section class="canvas-panel">
        <div class="canvas-top-status">
          <span>文档 {{ documentName }}</span>
          <span>画布 {{ canvasWidth }} × {{ canvasHeight }}</span>
          <span>当前工具 {{ activeToolLabel }}</span>
          <span>移动方式 中键拖动</span>
          <span>当前力度 {{ pressureEnabled ? pressureLabel : '100%' }}</span>
        </div>

        <div ref="viewportRef" class="canvas-viewport" @wheel.prevent="handleViewportWheel">
          <div
            ref="stageRef"
            class="canvas-stage"
            :style="{ ...stageStyle, cursor: stageCursor }"
            @contextmenu.prevent
            @pointerdown="handlePointerDown"
            @dblclick="handleStageDoubleClick"
            @pointermove="handlePointerMove"
            @pointerup="handlePointerUp"
            @pointercancel="handlePointerCancel"
            @pointerleave="handlePointerLeave"
          >
            <canvas ref="compositeCanvasRef" class="stage-canvas" :width="canvasWidth" :height="canvasHeight" />
            <canvas ref="previewCanvasRef" class="stage-canvas stage-preview" :width="canvasWidth" :height="canvasHeight" />
            <div v-if="textEditor.active" class="canvas-text-editor" @pointerdown.stop>
              <textarea
                ref="textEditorInputRef"
                v-model="textEditor.text"
                class="canvas-text-editor-input"
                :style="textEditorStyle"
                placeholder="输入文字内容"
                @pointerdown.stop
              />
              <div class="canvas-text-editor-toolbar" :style="textEditorToolbarStyle" @pointerdown.stop>
                <button type="button" class="canvas-text-editor-btn" @pointerdown.stop.prevent="startTextEditorMove">
                  移动
                </button>
                <button type="button" class="canvas-text-editor-btn canvas-text-editor-btn-primary" @click="applyTextEditor">
                  应用
                </button>
                <button type="button" class="canvas-text-editor-btn" @click="cancelTextEditor">取消</button>
                <span class="canvas-text-editor-hint">Ctrl+Enter 应用，Esc 取消</span>
              </div>
              <button
                v-for="handle in textResizeHandles"
                :key="handle"
                type="button"
                class="canvas-text-editor-resize"
                :style="getTextEditorHandleStyle(handle)"
                @pointerdown.stop.prevent="startTextEditorResize(handle, $event)"
                :aria-label="`调整文字框大小-${handle}`"
              ></button>
            </div>
          </div>
        </div>
      </section>

      <aside v-if="sidePanelVisible" class="side-panel">
        <section class="panel-card">
          <h3>颜色和拾色器</h3>
          <div class="color-row">
            <input v-model="brushColor" type="color" class="panel-color" />
            <button type="button" class="panel-btn" @click="setActiveTool('eyedropper')">拾色器</button>
          </div>
          <div class="swatch-grid">
            <button
              v-for="preset in colorPresets"
              :key="preset"
              type="button"
              class="swatch"
              :style="{ backgroundColor: preset }"
              @click="brushColor = preset"
            ></button>
          </div>
        </section>

        <section class="panel-card" v-if="showBrushStylePanel">
          <h3>{{ brushPanelCopy.title }}</h3>
          <label class="field">
            <span>{{ brushPanelCopy.nameLabel }}</span>
            <input v-model="brushName" class="field-input" />
          </label>

          <label class="field">
            <span>{{ brushPanelCopy.angleLabel }} {{ brushStyle.angle }}°</span>
            <input v-model.number="brushStyle.angle" type="range" min="0" max="180" class="field-range" />
          </label>

          <label class="field">
            <span>{{ brushPanelCopy.roundnessLabel }} {{ brushStyle.roundness }}%</span>
            <input v-model.number="brushStyle.roundness" type="range" min="10" max="100" class="field-range" />
          </label>

          <label class="field">
            <span>{{ brushPanelCopy.spacingLabel }} {{ brushStyle.spacing }}%</span>
            <input v-model.number="brushStyle.spacing" type="range" min="1" max="80" class="field-range" />
          </label>

          <label class="field">
            <span>{{ brushPanelCopy.hardnessLabel }} {{ brushStyle.hardness }}%</span>
            <input v-model.number="brushStyle.hardness" type="range" min="1" max="100" class="field-range" />
          </label>

          <label class="field">
            <span>{{ brushPanelCopy.flowLabel }} {{ brushStyle.flow }}%</span>
            <input v-model.number="brushStyle.flow" type="range" min="1" max="100" class="field-range" />
          </label>

          <label class="field">
            <span>{{ brushPanelCopy.sizeModeLabel }}</span>
            <select v-model="brushStyle.sizeMode" class="field-select">
              <option value="fixed">固定</option>
              <option value="random">随机</option>
              <option value="pressure">压力</option>
            </select>
          </label>

          <label class="field" :class="{ 'field-disabled': brushStyle.sizeMode !== 'random' }">
            <span>{{ brushPanelCopy.jitterLabel }} {{ brushStyle.sizeJitter }}%</span>
            <input
              v-model.number="brushStyle.sizeJitter"
              :disabled="brushStyle.sizeMode !== 'random'"
              type="range"
              min="0"
              max="80"
              class="field-range"
            />
          </label>
          <p class="panel-tip">{{ brushPanelCopy.tip }}</p>
        </section>

        <section class="panel-card" v-if="activeTool === 'eraser'">
          <h3>橡皮设置</h3>
          <label class="field">
            <span>擦除模式</span>
            <select v-model="eraserMode" class="field-select">
              <option value="normal">普通擦除</option>
              <option value="stroke">笔画擦除</option>
            </select>
          </label>
          <p class="panel-tip">普通擦除会按笔触连续擦除</p>
          <p class="panel-tip">笔画擦除会删除当前点击到的整段笔画区域</p>
        </section>

        <section class="panel-card">
          <div class="layer-head">
            <h3>图层</h3>
            <button type="button" class="panel-btn" @click="addLayer">新建</button>
          </div>

          <label class="field">
            <span>搜索图层</span>
            <input v-model="layerSearchKeyword" class="field-input" placeholder="输入图层名称" />
          </label>

          <div class="layer-list">
            <article
              v-for="layer in filteredPanelLayers"
              :key="layer.id"
              class="layer-row"
              :class="{ 'layer-row-active': layer.id === activeLayerId }"
            >
              <button type="button" class="layer-main" @click="setActiveLayer(layer.id)">
                <img v-if="layer.thumbnail" :src="layer.thumbnail" class="layer-thumb" :alt="`${layer.name} 缩略图`" />
                <span v-else class="layer-thumb-empty">空</span>
                <span class="layer-text">
                  <span class="layer-name">{{ layer.name }}</span>
                  <span class="layer-meta">{{ layer.visible ? '可见' : '隐藏' }} · {{ layer.locked ? '锁定' : '可编辑' }}</span>
                </span>
              </button>

              <div class="layer-actions">
                <button type="button" class="icon-btn" @click.stop="toggleLayerVisible(layer.id)">
                  <svg viewBox="0 0 24 24"><use href="#icon-eye" /></svg>
                </button>
                <button type="button" class="icon-btn" @click.stop="toggleLayerLocked(layer.id)">
                  <svg viewBox="0 0 24 24"><use href="#icon-lock" /></svg>
                </button>
              </div>
            </article>
          </div>

          <div class="layer-ops">
            <button type="button" class="panel-btn" @click="duplicateActiveLayer">复制</button>
            <button type="button" class="panel-btn" :disabled="layers.length <= 1" @click="removeActiveLayer">删除</button>
            <button type="button" class="panel-btn" @click="moveLayer('up')">上移</button>
            <button type="button" class="panel-btn" @click="moveLayer('down')">下移</button>
          </div>

          <label class="field" v-if="activeLayer">
            <span>当前图层名称</span>
            <input
              v-model="layerNameInput"
              class="field-input"
              @keydown.enter.prevent="commitLayerName"
              @blur="commitLayerName"
            />
          </label>

          <label class="field" v-if="activeLayer">
            <span>不透明度 {{ Math.round(activeLayer.opacity * 100) }}%</span>
            <input
              type="range"
              min="0"
              max="100"
              :value="Math.round(activeLayer.opacity * 100)"
              class="field-range"
              @input="handleActiveLayerOpacityInput"
              @change="commitLayerAppearance"
            />
          </label>

          <label class="field" v-if="activeLayer">
            <span>混合模式</span>
            <select :value="activeLayer.blendMode" class="field-select" @change="handleActiveLayerBlendChange">
              <option v-for="mode in blendModeOptions" :key="mode.value" :value="mode.value">{{ mode.label }}</option>
            </select>
          </label>
        </section>
      </aside>
    </main>
  </div>
</template>

<script setup lang="ts">
import { computed, nextTick, onBeforeUnmount, onMounted, reactive, ref, watch } from 'vue'
import iconBrush from '@/assets/tool-icons-svg/brush.svg'
import iconPencil from '@/assets/tool-icons-svg/pencil.svg'
import iconInk from '@/assets/tool-icons-svg/ink.svg'
import iconPen from '@/assets/tool-icons-svg/pen.svg'
import iconEraser from '@/assets/tool-icons-svg/eraser.svg'
import iconEyedropper from '@/assets/tool-icons-svg/eyedropper.svg'
import iconLasso from '@/assets/tool-icons-svg/lasso.svg'
import iconFill from '@/assets/tool-icons-svg/fill.svg'

interface DesktopNativeBridge {
  openFileDialog(callback: (filePath: string) => void): void
  saveFileDialog(suggestedName: string, callback: (filePath: string) => void): void
  readFileAsBase64(filePath: string, callback: (base64Content: string) => void): void
  writeFile(filePath: string, base64Content: string, callback: (success: boolean) => void): void
}

interface DesktopWebChannel {
  objects?: {
    nativeBridge?: DesktopNativeBridge
  }
}

declare global {
  interface Window {
    qt?: {
      webChannelTransport?: unknown
    }
    QWebChannel?: new (transport: unknown, callback: (channel: DesktopWebChannel) => void) => unknown
  }
}

type ToolId = 'select' | 'brush' | 'pencil' | 'ink' | 'pen' | 'eraser' | 'eyedropper' | 'lasso' | 'fill' | 'shape' | 'text'
type SizeMode = 'fixed' | 'random' | 'pressure'
type LayerBlendMode = 'source-over' | 'multiply' | 'screen' | 'overlay' | 'darken' | 'lighten'
type EraserMode = 'normal' | 'stroke'
type SelectionKind = 'rect' | 'lasso'
type HelpTab = 'usage' | 'shortcuts' | 'menu' | 'about'
type PaintToolId = 'brush' | 'pencil' | 'ink' | 'pen'
type TextAlignMode = 'left' | 'center' | 'right'
type ShapeType =
  | 'line'
  | 'curve'
  | 'ellipse'
  | 'rectangle'
  | 'rounded-rectangle'
  | 'triangle'
  | 'diamond'
  | 'pentagon'
  | 'hexagon'
  | 'right-arrow'
  | 'left-arrow'
  | 'up-arrow'
  | 'down-arrow'
  | 'star4'
  | 'star5'
  | 'chat-bubble'
  | 'heart'

interface Point {
  x: number
  y: number
}

interface Rect {
  x: number
  y: number
  width: number
  height: number
}

interface ToolItem {
  id: ToolId
  label: string
  iconType: 'symbol' | 'image'
  icon: string
}

interface LayerModel {
  id: string
  name: string
  visible: boolean
  locked: boolean
  opacity: number
  blendMode: LayerBlendMode
  thumbnail: string
}

interface LayerSnapshot {
  id: string
  name: string
  visible: boolean
  locked: boolean
  opacity: number
  blendMode: LayerBlendMode
  image: string
  strokeHistory?: SerializedLayerStrokeHistory
  textElements?: SerializedTextElement[]
}

interface HistorySnapshot {
  width: number
  height: number
  documentName: string
  activeLayerId: string | null
  layers: LayerSnapshot[]
}

interface ProjectFile {
  version: 1 | 2 | 3
  width: number
  height: number
  documentName: string
  layers: LayerSnapshot[]
}

interface TextStyleSnapshot {
  fontFamily: string
  size: number
  color: string
  bold: boolean
  italic: boolean
  align: TextAlignMode
  lineHeight: number
  letterSpacing: number
}

interface TextElementModel {
  id: string
  x: number
  y: number
  width: number
  height: number
  text: string
  style: TextStyleSnapshot
}

interface SerializedTextElement {
  id: string
  x: number
  y: number
  width: number
  height: number
  text: string
  style: TextStyleSnapshot
}

interface SerializedBrushRenderConfig {
  color: string
  size: number
  opacity: number
  style: BrushStyleState
  pressureEnabled: boolean
}

interface SerializedBrushStrokeRecord {
  id: string
  tool: RecordablePaintTool
  config: SerializedBrushRenderConfig
  points: StrokePointSample[]
  maxRadius: number
  bounds: {
    minX: number
    minY: number
    maxX: number
    maxY: number
  }
}

interface SerializedLayerStrokeHistory {
  baseImage: string
  strokes: SerializedBrushStrokeRecord[]
}

interface BrushStyleState {
  angle: number
  roundness: number
  spacing: number
  hardness: number
  flow: number
  sizeMode: SizeMode
  sizeJitter: number
}

type RecordablePaintTool = PaintToolId | 'eraser'

interface BrushRenderConfig {
  color: string
  size: number
  opacity: number
  style: BrushStyleState
  pressureEnabled: boolean
}

interface StrokePointSample {
  x: number
  y: number
  pressure: number
  size: number
}

interface BrushStrokeRecord {
  id: string
  layerId: string
  tool: RecordablePaintTool
  config: BrushRenderConfig
  points: StrokePointSample[]
  maxRadius: number
  bounds: {
    minX: number
    minY: number
    maxX: number
    maxY: number
  }
}

interface LayerStrokeHistory {
  baseRaster: HTMLCanvasElement | null
  strokes: BrushStrokeRecord[]
  strokeOrder: Map<string, number>
  spatialIndex: Map<string, string[]>
}

interface StrokeHitMatch {
  history: LayerStrokeHistory
  stroke: BrushStrokeRecord
  index: number
}

type BrushPresetId = PaintToolId

interface BrushPreset {
  id: BrushPresetId
  label: string
  tool: ToolId
  color: string
  size: number
  opacity: number
  style: BrushStyleState
}

interface ShapeItem {
  value: ShapeType
  label: string
  icon: string
}

interface ShortcutTipItem {
  key: string
  description: string
}

const menus = ['文件', '编辑', '图像', '图层', '文字', '滤镜', '视图', '窗口', '帮助'] as const
type MenuName = (typeof menus)[number]

interface MenuActionItem {
  id: string
  label: string
  shortcut?: string
  run: () => void
  disabled?: () => boolean
}

const tools: ToolItem[] = [
  { id: 'lasso', label: '套索选择', iconType: 'image', icon: iconLasso },
  { id: 'brush', label: '画笔', iconType: 'image', icon: iconBrush },
  { id: 'pencil', label: '铅笔', iconType: 'image', icon: iconPencil },
  { id: 'ink', label: '毛笔', iconType: 'image', icon: iconInk },
  { id: 'pen', label: '钢笔', iconType: 'image', icon: iconPen },
  { id: 'eraser', label: '橡皮', iconType: 'image', icon: iconEraser },
  { id: 'fill', label: '填充', iconType: 'image', icon: iconFill },
  { id: 'eyedropper', label: '拾色器', iconType: 'image', icon: iconEyedropper },
  { id: 'shape', label: '形状', iconType: 'symbol', icon: 'icon-rect' },
  { id: 'text', label: '文字', iconType: 'symbol', icon: 'icon-text' }
]

const shapeItems: ShapeItem[] = [
  { value: 'line', label: '直线', icon: 'icon-line' },
  { value: 'curve', label: '曲线', icon: 'icon-curve' },
  { value: 'rectangle', label: '矩形', icon: 'icon-rect' },
  { value: 'rounded-rectangle', label: '圆角矩形', icon: 'icon-rounded-rect' },
  { value: 'ellipse', label: '圆形', icon: 'icon-ellipse' },
  { value: 'triangle', label: '三角形', icon: 'icon-triangle' },
  { value: 'diamond', label: '菱形', icon: 'icon-diamond' },
  { value: 'pentagon', label: '五边形', icon: 'icon-pentagon' },
  { value: 'hexagon', label: '六边形', icon: 'icon-hexagon' },
  { value: 'right-arrow', label: '右箭头', icon: 'icon-arrow-right' },
  { value: 'left-arrow', label: '左箭头', icon: 'icon-arrow-left' },
  { value: 'up-arrow', label: '上箭头', icon: 'icon-arrow-up' },
  { value: 'down-arrow', label: '下箭头', icon: 'icon-arrow-down' },
  { value: 'star4', label: '四角星', icon: 'icon-star4' },
  { value: 'star5', label: '五角星', icon: 'icon-star5' },
  { value: 'chat-bubble', label: '对话框', icon: 'icon-chat-bubble' },
  { value: 'heart', label: '爱心', icon: 'icon-heart' }
]

const brushPresetItems: BrushPreset[] = [
  {
    id: 'brush',
    label: '画笔',
    tool: 'brush',
    color: '#000000',
    size: 12,
    opacity: 60,
    style: {
      angle: 0,
      roundness: 100,
      spacing: 10,
      hardness: 42,
      flow: 82,
      sizeMode: 'pressure',
      sizeJitter: 0
    }
  },
  {
    id: 'pencil',
    label: '铅笔',
    tool: 'pencil',
    color: '#555555',
    size: 2,
    opacity: 76,
    style: {
      angle: 0,
      roundness: 100,
      spacing: 16,
      hardness: 86,
      flow: 100,
      sizeMode: 'fixed',
      sizeJitter: 0
    }
  },
  {
    id: 'ink',
    label: '毛笔',
    tool: 'ink',
    color: '#000000',
    size: 14,
    opacity: 100,
    style: {
      angle: 18,
      roundness: 88,
      spacing: 8,
      hardness: 88,
      flow: 100,
      sizeMode: 'pressure',
      sizeJitter: 0
    }
  },
  {
    id: 'pen',
    label: '钢笔',
    tool: 'pen',
    color: '#000000',
    size: 4,
    opacity: 100,
    style: {
      angle: 0,
      roundness: 100,
      spacing: 7,
      hardness: 100,
      flow: 100,
      sizeMode: 'pressure',
      sizeJitter: 0
    }
  }
]

const blendModeOptions: Array<{ value: LayerBlendMode; label: string }> = [
  { value: 'source-over', label: '正常' },
  { value: 'multiply', label: '正片叠底' },
  { value: 'screen', label: '滤色' },
  { value: 'overlay', label: '叠加' },
  { value: 'darken', label: '变暗' },
  { value: 'lighten', label: '变亮' }
]

const colorPresets = ['#101114', '#f97316', '#ef4444', '#f59e0b', '#16a34a', '#06b6d4', '#2563eb', '#7c3aed', '#f8fafc']

const openFileInputRef = ref<HTMLInputElement | null>(null)
const importImageInputRef = ref<HTMLInputElement | null>(null)
const viewportRef = ref<HTMLDivElement | null>(null)
const stageRef = ref<HTMLDivElement | null>(null)
const compositeCanvasRef = ref<HTMLCanvasElement | null>(null)
const previewCanvasRef = ref<HTMLCanvasElement | null>(null)
const textEditorInputRef = ref<HTMLTextAreaElement | null>(null)

let desktopNativeBridge: DesktopNativeBridge | null = null
let nativeBridgeLoading: Promise<DesktopNativeBridge | null> | null = null

const canvasWidth = ref(1600)
const canvasHeight = ref(980)
const documentName = ref('未命名 1')
const canvasSizeDraft = reactive({ width: 1600, height: 980 })
const documentBackgroundColor = ref('#ffffff')

const showNewDocumentDialog = ref(false)
const showHelpDialog = ref(false)
const activeHelpTab = ref<HelpTab>('usage')
const helpShortcutKeyword = ref('')
const activeMenu = ref<MenuName | null>(null)
const sidePanelVisible = ref(true)
const newDocumentForm = reactive({
  name: '未命名 1',
  width: 1600,
  height: 980,
  backgroundColor: '#ffffff'
})

const activeTool = ref<ToolId>('brush')
const lastPaintTool = ref<ToolId>('brush')
const brushPresetId = ref<BrushPresetId>('brush')
const brushName = ref('画笔')
const brushColor = ref('#000000')
const brushSize = ref(12)
const brushOpacity = ref(60)
const eraserMode = ref<EraserMode>('normal')
const shapeType = ref<ShapeType>('line')
const textStyle = reactive({
  fontFamily: 'MiSans',
  size: 48,
  color: '#101114',
  bold: false,
  italic: false,
  align: 'left' as TextAlignMode,
  lineHeight: 1.35,
  letterSpacing: 0
})
const filterIntensity = ref(60)
const pressureEnabled = ref(true)
const pressureDetected = ref(false)
const currentPressure = ref(1)

const fontOptions = [
  { label: 'MiSans（内置）', value: 'MiSans' },
  { label: 'OPPOSans（内置）', value: 'OPPOSans' },
  { label: '思源黑体 Noto Sans SC', value: 'Noto Sans SC' },
  { label: '思源宋体 Noto Serif SC', value: 'Noto Serif SC' },
  { label: '思源黑体 Source Han Sans SC', value: 'Source Han Sans SC' },
  { label: '思源宋体 Source Han Serif SC', value: 'Source Han Serif SC' },
  { label: '霞鹜文楷 LXGW WenKai', value: 'LXGW WenKai' },
  { label: '阿里巴巴普惠体 3.0', value: 'Alibaba PuHuiTi 3.0' },
  { label: 'MiSans', value: 'MiSans' },
  { label: 'HarmonyOS Sans SC', value: 'HarmonyOS Sans SC' },
  { label: 'OPPOSans', value: 'OPPOSans' }
] as const

const textEditorStyle = computed(() => ({
  left: `${textEditor.x}px`,
  top: `${textEditor.y}px`,
  width: `${textEditor.width}px`,
  height: `${textEditor.height}px`,
  fontFamily: `"${textStyle.fontFamily}", "MiSans", "OPPOSans", "Noto Sans SC", "Microsoft YaHei", sans-serif`,
  fontSize: `${clamp(Math.round(textStyle.size), 8, 360)}px`,
  fontWeight: textStyle.bold ? '700' : '400',
  fontStyle: textStyle.italic ? 'italic' : 'normal',
  color: textStyle.color,
  lineHeight: String(textStyle.lineHeight),
  textAlign: textStyle.align,
  letterSpacing: `${textStyle.letterSpacing}px`
}))

const textEditorToolbarStyle = computed(() => ({
  left: `${textEditor.x}px`,
  top: `${Math.min(canvasHeight.value - 36, textEditor.y + textEditor.height + 8)}px`
}))

function getTextEditorHandleStyle(handle: TextResizeHandle) {
  const half = 8
  const centerX = textEditor.x + textEditor.width / 2
  const centerY = textEditor.y + textEditor.height / 2
  const left = textEditor.x
  const right = textEditor.x + textEditor.width
  const top = textEditor.y
  const bottom = textEditor.y + textEditor.height

  const positionMap: Record<TextResizeHandle, { left: number; top: number; cursor: string }> = {
    nw: { left: left - half, top: top - half, cursor: 'nwse-resize' },
    n: { left: centerX - half, top: top - half, cursor: 'ns-resize' },
    ne: { left: right - half, top: top - half, cursor: 'nesw-resize' },
    e: { left: right - half, top: centerY - half, cursor: 'ew-resize' },
    se: { left: right - half, top: bottom - half, cursor: 'nwse-resize' },
    s: { left: centerX - half, top: bottom - half, cursor: 'ns-resize' },
    sw: { left: left - half, top: bottom - half, cursor: 'nesw-resize' },
    w: { left: left - half, top: centerY - half, cursor: 'ew-resize' }
  }

  const item = positionMap[handle]
  return {
    left: `${item.left}px`,
    top: `${item.top}px`,
    cursor: item.cursor
  }
}

const usageTips = [
  '画布移动默认使用鼠标中键拖动，按住空格可临时拖动。',
  '套索选择支持两种方式：拖拽可自由圈选，单击可直接点选画笔笔迹或文本框。',
  '出现浮动选区后，可继续拖动移动位置，再用“应用选区”或“取消选区”完成处理。',
  '文字工具可用 Ctrl+B 与 Ctrl+I 切换粗体和斜体。',
  '滤镜会作用于当前活动图层，可先用“滤镜强度”调节结果。',
  '套索选择、图层合并与滤镜操作都会写入历史，可用 Ctrl+Z 撤销。'
] as const

const appDisplayName = computed(() => import.meta.env.VITE_APP_NAME || 'Drawing Board Pro')
const appVersion = __APP_VERSION__
const runtimeModeLabel = computed(() => (isDesktopRuntime() ? '桌面版运行环境' : '浏览器运行环境'))

const menuGuideSections = [
  {
    title: '文件',
    description: '负责文档创建、打开、保存与导出。',
    items: ['新建文档快速初始化画布尺寸和背景色。', '支持导入本地图片，并导出 PNG 或 SVG 结果。']
  },
  {
    title: '编辑',
    description: '围绕当前编辑状态进行撤销，以及套索选择后的处理。',
    items: ['撤销与重做会记录图层绘制、套索选择、滤镜与合并操作。', '套索选择生成浮动选区后，可应用回图层，也可一键取消。']
  },
  {
    title: '图像',
    description: '用于整体画布适配，以及当前图层的旋转翻转。',
    items: ['适应窗口会重新计算缩放，让画布完整显示。', '旋转与翻转仅对当前可编辑图层生效。']
  },
  {
    title: '图层',
    description: '管理多图层结构、顺序与合并流程。',
    items: ['支持新建、复制、删除、上移和下移图层。', '可向下合并或直接合并所有可见图层。']
  },
  {
    title: '文字 / 滤镜',
    description: '补充版式表达和后期效果。',
    items: ['文字菜单可切换文字工具并快速调整字号、粗斜体。', '滤镜菜单提供黑白、棕褐、反相、模糊和锐化等效果。']
  },
  {
    title: '视图 / 窗口 / 帮助',
    description: '聚焦工作区显示控制与使用说明。',
    items: ['视图菜单支持缩放、适应窗口和重置视图。', '窗口菜单可控制右侧面板并重置工作区布局，帮助菜单集中展示提示、快捷键与版本信息。']
  }
] as const

const aboutFacts = computed(() => [
  { label: '应用名称', value: appDisplayName.value },
  { label: 'App 版本', value: `v${appVersion}` },
  { label: '运行环境', value: runtimeModeLabel.value },
  { label: '核心能力', value: '图层 / 套索选择 / 文字 / 滤镜' }
])

const aboutLines = [
  '内置多图层绘制、套索选择、文字排版与滤镜处理能力。',
  '菜单栏已按文件、编辑、图像、图层、文字、滤镜、视图、窗口、帮助进行分组。',
  '帮助中心会同步展示当前 App 版本、运行环境，以及套索选择相关提示。'
] as const

const brushStyle = reactive<BrushStyleState>({
  angle: 0,
  roundness: 100,
  spacing: 12,
  hardness: 78,
  flow: 90,
  sizeMode: 'pressure',
  sizeJitter: 16
})

const layers = ref<LayerModel[]>([])
const activeLayerId = ref<string | null>(null)
const layerNameInput = ref('')
const layerSearchKeyword = ref('')

const fitScale = ref(1)
const zoomFactor = ref(1)
const panX = ref(0)
const panY = ref(0)

const historySnapshots = ref<HistorySnapshot[]>([])
const historyIndex = ref(-1)
const maxHistory = 80
const restoringHistory = ref(false)
const lastSnapshotMarker = ref('')

const spacePressed = ref(false)

const drawState = reactive({
  pointerId: null as number | null,
  drawing: false,
  panning: false,
  movingSelection: false,
  selectingBox: false,
  textBoxSelecting: false,
  lassoSelecting: false,
  lassoPoints: [] as Point[],
  strokeEraseChanged: false,
  lastStrokeErasePoint: null as Point | null,
  lastPoint: null as Point | null,
  startPoint: null as Point | null,
  lastPressure: 1,
  lastStrokeSize: 0,
  lastTimestamp: 0,
  panStartX: 0,
  panStartY: 0,
  pointerStartX: 0,
  pointerStartY: 0
})

const selectionState = reactive({
  active: false,
  kind: 'rect' as SelectionKind,
  x: 0,
  y: 0,
  width: 0,
  height: 0,
  lassoPath: [] as Point[],
  offsetX: 0,
  offsetY: 0,
  moveStartX: 0,
  moveStartY: 0,
  moveBaseOffsetX: 0,
  moveBaseOffsetY: 0,
  boxStartX: 0,
  boxStartY: 0,
  boxEndX: 0,
  boxEndY: 0
})

type TextEditorMode = 'create' | 'edit'
type TextEditorInteraction = 'idle' | 'move' | 'resize'
type TextResizeHandle = 'n' | 'ne' | 'e' | 'se' | 's' | 'sw' | 'w' | 'nw'

const textResizeHandles: TextResizeHandle[] = ['nw', 'n', 'ne', 'e', 'se', 's', 'sw', 'w']

const textEditor = reactive({
  active: false,
  layerId: null as string | null,
  textId: null as string | null,
  mode: 'create' as TextEditorMode,
  interaction: 'idle' as TextEditorInteraction,
  x: 0,
  y: 0,
  width: 260,
  height: 120,
  text: '',
  pointerId: null as number | null,
  resizeHandle: 'se' as TextResizeHandle,
  anchorX: 0,
  anchorY: 0,
  startX: 0,
  startY: 0,
  startWidth: 0,
  startHeight: 0
})

const layerRasterMap = new Map<string, HTMLCanvasElement>()
const layerStrokeHistoryMap = new Map<string, LayerStrokeHistory>()
const layerTextMap = new Map<string, TextElementModel[]>()
let selectionRaster: HTMLCanvasElement | null = null
let activeRecordedStroke: BrushStrokeRecord | null = null
const hoverStrokePreviewId = ref<string | null>(null)

const activeLayer = computed(() => layers.value.find((layer) => layer.id === activeLayerId.value) ?? null)
const hasEditableActiveLayer = computed(() => Boolean(activeLayer.value && !activeLayer.value.locked))
const visibleLayerCount = computed(() => {
  return layers.value.reduce((count, layer) => (layer.visible ? count + 1 : count), 0)
})
const canMergeActiveLayerDown = computed(() => {
  if (!activeLayerId.value || layers.value.length <= 1) {
    return false
  }

  const index = layers.value.findIndex((layer) => layer.id === activeLayerId.value)
  if (index <= 0) {
    return false
  }

  const current = layers.value[index]
  const target = layers.value[index - 1]
  return Boolean(current && !current.locked && target && !target.locked)
})
const panelLayers = computed(() => [...layers.value].reverse())
const filteredPanelLayers = computed(() => {
  const keyword = layerSearchKeyword.value.trim().toLocaleLowerCase()
  if (!keyword) {
    return panelLayers.value
  }

  return panelLayers.value.filter((layer) => layer.name.toLocaleLowerCase().includes(keyword))
})
const canUndo = computed(() => historyIndex.value > 0)
const canRedo = computed(() => historyIndex.value >= 0 && historyIndex.value < historySnapshots.value.length - 1)
const viewScale = computed(() => fitScale.value * zoomFactor.value)
const zoomLabel = computed(() => `${Math.round(viewScale.value * 100)}%`)
const pressureLabel = computed(() => `${Math.round(currentPressure.value * 100)}%`)
const hasFloatingSelection = computed(() => selectionState.active && !!selectionRaster && selectionState.width > 0 && selectionState.height > 0)
const activeToolLabel = computed(() => tools.find((tool) => tool.id === activeTool.value)?.label ?? '画笔')
const activeShapeItem = computed(() => shapeItems.find((item) => item.value === shapeType.value) ?? shapeItems[0])
const activeShapeLabel = computed(() => activeShapeItem.value?.label ?? '直线')
const activeShapeIcon = computed(() => activeShapeItem.value?.icon ?? 'icon-line')
const showPresetControl = computed(() => activeTool.value === 'brush' || activeTool.value === 'pencil' || activeTool.value === 'ink' || activeTool.value === 'pen')
const showColorControl = computed(() => {
  return activeTool.value === 'brush' || activeTool.value === 'pencil' || activeTool.value === 'ink' || activeTool.value === 'pen' || activeTool.value === 'shape' || activeTool.value === 'fill'
})
const showSizeControl = computed(() => {
  if (activeTool.value === 'select' || activeTool.value === 'lasso' || activeTool.value === 'fill' || activeTool.value === 'text') {
    return false
  }

  if (activeTool.value === 'eraser') {
    return eraserMode.value === 'normal'
  }

  return activeTool.value !== 'eyedropper'
})
const showOpacityControl = computed(() => {
  if (activeTool.value === 'select' || activeTool.value === 'lasso' || activeTool.value === 'fill' || activeTool.value === 'text') {
    return false
  }

  if (activeTool.value === 'eraser') {
    return eraserMode.value === 'normal'
  }

  return activeTool.value !== 'eyedropper'
})
const showPressureControl = computed(() => {
  if (activeTool.value === 'eraser') {
    return eraserMode.value === 'normal'
  }

  return activeTool.value === 'brush' || activeTool.value === 'pencil' || activeTool.value === 'ink' || activeTool.value === 'pen'
})
const showBrushStylePanel = computed(() => activeTool.value === 'brush' || activeTool.value === 'pencil' || activeTool.value === 'ink' || activeTool.value === 'pen')
const brushPanelCopy = computed(() => {
  if (activeTool.value === 'pencil') {
    return {
      title: '铅笔设置',
      nameLabel: '笔刷名称',
      angleLabel: '笔锋角度',
      roundnessLabel: '线芯圆度',
      spacingLabel: '颗粒密度',
      hardnessLabel: '纸面摩擦',
      flowLabel: '上色浓度',
      sizeModeLabel: '线宽控制',
      jitterLabel: '颗粒扰动',
      tip: '铅笔保持细线和半透明，颗粒感主要由间距与纸面摩擦共同影响。'
    }
  }

  if (activeTool.value === 'ink') {
    return {
      title: '毛笔设置',
      nameLabel: '笔刷名称',
      angleLabel: '笔锋角度',
      roundnessLabel: '笔腹饱满度',
      spacingLabel: '落笔密度',
      hardnessLabel: '墨边凝聚',
      flowLabel: '出墨量',
      sizeModeLabel: '笔锋控制',
      jitterLabel: '飞白扰动',
      tip: '毛笔会随速度显著变细，快速拖动时会带一点轻微枯笔和飞白感。'
    }
  }

  if (activeTool.value === 'pen') {
    return {
      title: '钢笔设置',
      nameLabel: '笔刷名称',
      angleLabel: '笔尖角度',
      roundnessLabel: '笔尖圆润',
      spacingLabel: '走墨密度',
      hardnessLabel: '硬边强度',
      flowLabel: '出墨稳定度',
      sizeModeLabel: '压力映射',
      jitterLabel: '笔锋扰动',
      tip: '钢笔保持利落硬边，速度只做轻微粗细变化，收笔会略微加重。'
    }
  }

  return {
    title: '画笔设置',
    nameLabel: '笔刷名称',
    angleLabel: '笔触角度',
    roundnessLabel: '软刷圆度',
    spacingLabel: '叠色密度',
    hardnessLabel: '边缘柔化',
    flowLabel: '颜料流量',
    sizeModeLabel: '粗细控制',
    jitterLabel: '边缘扰动',
    tip: '画笔笔触更软、羽化更重，慢速会更厚实，快速会更轻盈。'
  }
})
const stageCursor = computed(() => {
  if (drawState.panning) {
    return 'grabbing'
  }

  if (spacePressed.value) {
    return 'grab'
  }

  if ((activeTool.value === 'select' || activeTool.value === 'lasso') && hasFloatingSelection.value) {
    return 'move'
  }

  if (activeTool.value === 'text') {
    return 'text'
  }

  if (activeTool.value === 'fill') {
    return 'cell'
  }

  if (activeTool.value === 'eyedropper') {
    return 'copy'
  }

  return 'crosshair'
})

const menuActions = computed<Record<MenuName, MenuActionItem[]>>(() => ({
  文件: [
    { id: 'new-doc', label: '新建文档', shortcut: 'Ctrl+N', run: openNewDocumentDialog },
    { id: 'open-file', label: '打开文件', shortcut: 'Ctrl+O', run: () => { void openLocalFile() } },
    { id: 'save-project', label: '保存项目', shortcut: 'Ctrl+S', run: () => { void saveProject() } },
    { id: 'import-image', label: '导入图片', run: () => { void openImportImage() } },
    { id: 'export-png', label: '导出 PNG', run: () => { void exportPng() } },
    { id: 'export-svg', label: '导出 SVG', run: () => { void exportSvg() } }
  ],
  编辑: [
    { id: 'undo', label: '撤销', shortcut: 'Ctrl+Z', run: () => { void undo() }, disabled: () => !canUndo.value },
    { id: 'redo', label: '重做', shortcut: 'Ctrl+Shift+Z', run: () => { void redo() }, disabled: () => !canRedo.value },
    { id: 'clear-layer', label: '清空当前层', run: clearActiveLayer, disabled: () => !activeLayer.value || activeLayer.value.locked },
    { id: 'apply-selection', label: '应用浮动选区', run: () => { commitFloatingSelection(true) }, disabled: () => !hasFloatingSelection.value },
    { id: 'cancel-selection', label: '取消浮动选区', run: clearFloatingSelectionAndRender, disabled: () => !hasFloatingSelection.value }
  ],
  图像: [
    { id: 'fit-canvas', label: '适应窗口', run: fitCanvasToViewport },
    { id: 'apply-canvas-size', label: '应用画布尺寸', run: applyCanvasSize },
    {
      id: 'rotate-layer-cw',
      label: '当前层顺时针旋转 90°',
      shortcut: 'Ctrl+Shift+]',
      run: () => rotateActiveLayer(90),
      disabled: () => !hasEditableActiveLayer.value
    },
    {
      id: 'rotate-layer-ccw',
      label: '当前层逆时针旋转 90°',
      shortcut: 'Ctrl+Shift+[',
      run: () => rotateActiveLayer(-90),
      disabled: () => !hasEditableActiveLayer.value
    },
    {
      id: 'flip-layer-horizontal',
      label: '当前层水平翻转',
      shortcut: 'Ctrl+Shift+H',
      run: () => flipActiveLayer('horizontal'),
      disabled: () => !hasEditableActiveLayer.value
    },
    {
      id: 'flip-layer-vertical',
      label: '当前层垂直翻转',
      shortcut: 'Ctrl+Shift+V',
      run: () => flipActiveLayer('vertical'),
      disabled: () => !hasEditableActiveLayer.value
    }
  ],
  图层: [
    { id: 'add-layer', label: '新建图层', run: addLayer },
    { id: 'duplicate-layer', label: '复制图层', run: duplicateActiveLayer, disabled: () => !activeLayer.value },
    { id: 'remove-layer', label: '删除图层', run: removeActiveLayer, disabled: () => layers.value.length <= 1 },
    {
      id: 'move-layer-up',
      label: '图层上移',
      run: () => moveLayer('up'),
      disabled: () => {
        if (!activeLayerId.value) {
          return true
        }
        const index = layers.value.findIndex((layer) => layer.id === activeLayerId.value)
        return index < 0 || index >= layers.value.length - 1
      }
    },
    {
      id: 'move-layer-down',
      label: '图层下移',
      run: () => moveLayer('down'),
      disabled: () => {
        if (!activeLayerId.value) {
          return true
        }
        const index = layers.value.findIndex((layer) => layer.id === activeLayerId.value)
        return index <= 0
      }
    },
    {
      id: 'merge-down',
      label: '向下合并图层',
      shortcut: 'Ctrl+E',
      run: mergeActiveLayerDown,
      disabled: () => !canMergeActiveLayerDown.value
    },
    {
      id: 'merge-visible',
      label: '合并可见图层',
      shortcut: 'Ctrl+Shift+E',
      run: mergeVisibleLayers,
      disabled: () => visibleLayerCount.value <= 1
    }
  ],
  文字: [
    { id: 'tool-text', label: '切换文字工具', shortcut: 'T', run: () => setActiveTool('text') },
    { id: 'text-size-up', label: '文字字号 +2', shortcut: 'Ctrl+Alt+Up', run: () => adjustTextSize(2) },
    { id: 'text-size-down', label: '文字字号 -2', shortcut: 'Ctrl+Alt+Down', run: () => adjustTextSize(-2) },
    { id: 'text-bold', label: '切换粗体', shortcut: 'Ctrl+B', run: toggleTextBold },
    { id: 'text-italic', label: '切换斜体', shortcut: 'Ctrl+I', run: toggleTextItalic }
  ],
  滤镜: [
    { id: 'filter-grayscale', label: '黑白', shortcut: 'Ctrl+Shift+1', run: applyGrayscaleFilter, disabled: () => !hasEditableActiveLayer.value },
    { id: 'filter-sepia', label: '棕褐', shortcut: 'Ctrl+Shift+2', run: applySepiaFilter, disabled: () => !hasEditableActiveLayer.value },
    { id: 'filter-invert', label: '反相', shortcut: 'Ctrl+Shift+3', run: applyInvertFilter, disabled: () => !hasEditableActiveLayer.value },
    { id: 'filter-blur', label: '高斯模糊', shortcut: 'Ctrl+Shift+4', run: applySoftBlurFilter, disabled: () => !hasEditableActiveLayer.value },
    { id: 'filter-sharpen', label: '锐化', shortcut: 'Ctrl+Shift+5', run: applySharpenFilter, disabled: () => !hasEditableActiveLayer.value }
  ],
  视图: [
    { id: 'zoom-in', label: '放大', shortcut: 'Ctrl++', run: zoomIn },
    { id: 'zoom-out', label: '缩小', shortcut: 'Ctrl+-', run: zoomOut },
    { id: 'fit-view', label: '适应窗口', shortcut: 'Ctrl+0', run: fitCanvasToViewport },
    { id: 'view-reset', label: '重置视图', shortcut: 'Ctrl+Shift+0', run: resetView }
  ],
  窗口: [
    {
      id: 'toggle-side-panel',
      label: sidePanelVisible.value ? '隐藏右侧面板' : '显示右侧面板',
      run: () => {
        sidePanelVisible.value = !sidePanelVisible.value
      }
    },
    { id: 'reset-workspace', label: '重置工作区布局', shortcut: 'Ctrl+\\', run: resetWorkspaceLayout }
  ],
  帮助: [
    {
      id: 'usage-tip',
      label: '查看操作提示',
      shortcut: 'F1',
      run: showUsageTip
    },
    {
      id: 'shortcut-tip',
      label: '查看快捷键',
      shortcut: 'Shift+F1',
      run: showShortcutTip
    },
    {
      id: 'about-app',
      label: '关于 Drawing Board Pro',
      shortcut: 'Ctrl+F1',
      run: showAboutDialog
    }
  ]
}))

const shortcutTips = computed<ShortcutTipItem[]>(() => {
  const results: ShortcutTipItem[] = []
  const seen = new Set<string>()

  for (const menu of menus) {
    const actions = menuActions.value[menu] ?? []
    for (const action of actions) {
      if (!action.shortcut) {
        continue
      }

      if (seen.has(action.shortcut)) {
        continue
      }

      seen.add(action.shortcut)
      results.push({ key: action.shortcut, description: action.label })
    }
  }

  const extraShortcuts: ShortcutTipItem[] = [
    { key: 'Ctrl+Y', description: '重做（兼容快捷键）' },
    { key: 'B / P / E / I / G / L / U / T / M / V', description: '快速切换工具，M / V 可直接切到套索选择并执行圈选或点选' },
    { key: 'Space', description: '临时拖动画布' }
  ]

  for (const item of extraShortcuts) {
    if (seen.has(item.key)) {
      continue
    }
    seen.add(item.key)
    results.push(item)
  }

  return results
})

const filteredShortcutTips = computed<ShortcutTipItem[]>(() => {
  const keyword = helpShortcutKeyword.value.trim().toLocaleLowerCase()
  if (!keyword) {
    return shortcutTips.value
  }

  return shortcutTips.value.filter((item) => {
    return item.key.toLocaleLowerCase().includes(keyword) || item.description.toLocaleLowerCase().includes(keyword)
  })
})

function escapeHtml(text: string) {
  return text
    .replace(/&/g, '&amp;')
    .replace(/</g, '&lt;')
    .replace(/>/g, '&gt;')
    .replace(/"/g, '&quot;')
    .replace(/'/g, '&#39;')
}

function highlightShortcutText(text: string) {
  const keyword = helpShortcutKeyword.value.trim()
  if (!keyword) {
    return escapeHtml(text)
  }

  const lowerText = text.toLocaleLowerCase()
  const lowerKeyword = keyword.toLocaleLowerCase()
  const keywordLength = keyword.length

  let index = 0
  let html = ''
  while (index < text.length) {
    const matchIndex = lowerText.indexOf(lowerKeyword, index)
    if (matchIndex < 0) {
      html += escapeHtml(text.slice(index))
      break
    }

    html += escapeHtml(text.slice(index, matchIndex))
    html += `<mark class="help-mark">${escapeHtml(text.slice(matchIndex, matchIndex + keywordLength))}</mark>`
    index = matchIndex + keywordLength
  }

  return html
}

const stageStyle = computed(() => ({
  width: `${canvasWidth.value}px`,
  height: `${canvasHeight.value}px`,
  transform: `translate(${panX.value}px, ${panY.value}px) scale(${viewScale.value})`
}))

watch(activeLayer, (layer) => {
  layerNameInput.value = layer?.name ?? ''
}, { immediate: true })

watch([canvasWidth, canvasHeight], ([width, height]) => {
  canvasSizeDraft.width = width
  canvasSizeDraft.height = height
}, { immediate: true })

watch(() => textStyle.lineHeight, (value) => {
  const numericValue = Number(value)
  const nextValue = Number.isFinite(numericValue) ? clamp(numericValue, 1, 3) : 1.35
  if (nextValue !== value) {
    textStyle.lineHeight = nextValue
  }
})

watch(() => textStyle.letterSpacing, (value) => {
  const numericValue = Number(value)
  const nextValue = Number.isFinite(numericValue) ? clamp(numericValue, -8, 40) : 0
  if (nextValue !== value) {
    textStyle.letterSpacing = nextValue
  }
})

watch(sidePanelVisible, () => {
  nextTick(() => {
    fitCanvasToViewport()
  })
})

function toggleMenu(menu: MenuName) {
  activeMenu.value = activeMenu.value === menu ? null : menu
}

function closeMenu() {
  activeMenu.value = null
}

function getMenuActions(menu: MenuName) {
  return menuActions.value[menu] ?? []
}

function isMenuActionDisabled(action: MenuActionItem) {
  return action.disabled ? action.disabled() : false
}

function runMenuAction(action: MenuActionItem) {
  if (isMenuActionDisabled(action)) {
    return
  }

  closeMenu()
  action.run()
}

function handleGlobalPointerDown(event: PointerEvent) {
  const target = event.target as HTMLElement | null
  if (!target?.closest('.menu-wrap')) {
    closeMenu()
  }
}

function handleStageDoubleClick(event: MouseEvent) {
  const point = toCanvasPoint(event)
  if (!point) {
    return
  }

  const hit = findTopEditableTextHit(point)
  if (!hit) {
    return
  }

  setActiveTool('text')
  setActiveLayer(hit.layer.id)
  openTextEditor(hit.textElement, hit.textElement.text, {
    layerId: hit.layer.id,
    textId: hit.textElement.id,
    style: hit.textElement.style,
    mode: 'edit'
  })
}

function handleWindowPointerMove(event: PointerEvent) {
  handleTextEditorPointerMove(event)
}

function handleWindowPointerUp(event: PointerEvent) {
  stopTextEditorInteraction(event)
}

function createId() {
  if (typeof crypto !== 'undefined' && typeof crypto.randomUUID === 'function') {
    return crypto.randomUUID()
  }

  return `${Date.now()}-${Math.random().toString(36).slice(2, 10)}`
}

function clamp(value: number, min: number, max: number) {
  return Math.min(max, Math.max(min, value))
}

function lerp(from: number, to: number, amount: number) {
  return from + (to - from) * amount
}

void lerp

function cloneTextStyleSnapshot(style: TextStyleSnapshot): TextStyleSnapshot {
  return {
    fontFamily: style.fontFamily,
    size: clamp(Math.round(style.size), 8, 360),
    color: style.color,
    bold: style.bold,
    italic: style.italic,
    align: style.align === 'center' || style.align === 'right' ? style.align : 'left',
    lineHeight: clamp(Number(style.lineHeight ?? 1.35), 1, 3),
    letterSpacing: clamp(Number(style.letterSpacing ?? 0), -8, 40)
  }
}

function captureCurrentTextStyle(): TextStyleSnapshot {
  return cloneTextStyleSnapshot({
    fontFamily: textStyle.fontFamily || 'MiSans',
    size: textStyle.size,
    color: textStyle.color,
    bold: textStyle.bold,
    italic: textStyle.italic,
    align: textStyle.align,
    lineHeight: textStyle.lineHeight,
    letterSpacing: textStyle.letterSpacing
  })
}

function applyTextStyleSnapshot(style: TextStyleSnapshot) {
  textStyle.fontFamily = style.fontFamily || 'MiSans'
  textStyle.size = clamp(Math.round(style.size), 8, 360)
  textStyle.color = style.color || '#101114'
  textStyle.bold = style.bold === true
  textStyle.italic = style.italic === true
  textStyle.align = style.align === 'center' || style.align === 'right' ? style.align : 'left'
  textStyle.lineHeight = clamp(Number(style.lineHeight ?? 1.35), 1, 3)
  textStyle.letterSpacing = clamp(Number(style.letterSpacing ?? 0), -8, 40)
}

function getLayerTextElements(layerId: string) {
  let items = layerTextMap.get(layerId)
  if (!items) {
    items = []
    layerTextMap.set(layerId, items)
  }
  return items
}

function cloneTextElement(element: TextElementModel): TextElementModel {
  return {
    id: element.id,
    x: element.x,
    y: element.y,
    width: element.width,
    height: element.height,
    text: element.text,
    style: cloneTextStyleSnapshot(element.style)
  }
}

function serializeLayerTextElements(layerId: string) {
  return getLayerTextElements(layerId).map((item) => cloneTextElement(item))
}

function restoreLayerTextElements(layerId: string, items?: SerializedTextElement[]) {
  const nextItems = Array.isArray(items)
    ? items
        .filter((item) => item && typeof item.text === 'string')
        .map((item) => ({
          id: typeof item.id === 'string' && item.id ? item.id : createId(),
          x: clamp(Number(item.x ?? 0), 0, canvasWidth.value),
          y: clamp(Number(item.y ?? 0), 0, canvasHeight.value),
          width: clamp(Number(item.width ?? 240), 120, canvasWidth.value),
          height: clamp(Number(item.height ?? 96), 56, canvasHeight.value),
          text: item.text,
          style: cloneTextStyleSnapshot(item.style ?? captureCurrentTextStyle())
        }))
    : []

  layerTextMap.set(layerId, nextItems)
}

function loadImage(dataUrl: string): Promise<HTMLImageElement> {
  return new Promise((resolve, reject) => {
    const image = new Image()
    image.onload = () => resolve(image)
    image.onerror = () => reject(new Error('加载图片失败'))
    image.src = dataUrl
  })
}

function isDesktopRuntime() {
  return typeof window !== 'undefined' && Boolean(window.qt?.webChannelTransport)
}

function loadQWebChannelScript(): Promise<void> {
  return new Promise((resolve, reject) => {
    if (window.QWebChannel) {
      resolve()
      return
    }

    const existing = document.querySelector('script[data-qt-webchannel="1"]') as HTMLScriptElement | null
    if (existing) {
      existing.addEventListener('load', () => resolve(), { once: true })
      existing.addEventListener('error', () => reject(new Error('加载 QWebChannel 脚本失败')), { once: true })
      return
    }

    const script = document.createElement('script')
    script.setAttribute('data-qt-webchannel', '1')
    script.src = 'qrc:///qtwebchannel/qwebchannel.js'
    script.onload = () => resolve()
    script.onerror = () => reject(new Error('加载 QWebChannel 脚本失败'))
    document.head.appendChild(script)
  })
}

async function getDesktopNativeBridge(): Promise<DesktopNativeBridge | null> {
  if (!isDesktopRuntime()) {
    return null
  }

  if (desktopNativeBridge) {
    return desktopNativeBridge
  }

  if (nativeBridgeLoading) {
    return nativeBridgeLoading
  }

  nativeBridgeLoading = (async () => {
    try {
      await loadQWebChannelScript()
    } catch {
      return null
    }

    const qWebChannelConstructor = window.QWebChannel
    const transport = window.qt?.webChannelTransport
    if (!qWebChannelConstructor || !transport) {
      return null
    }

    return await new Promise<DesktopNativeBridge | null>((resolve) => {
      try {
        new qWebChannelConstructor(transport, (channel) => {
          const bridge = channel.objects?.nativeBridge ?? null
          desktopNativeBridge = bridge
          resolve(bridge)
        })
      } catch {
        resolve(null)
      }
    })
  })()

  const result = await nativeBridgeLoading
  nativeBridgeLoading = null
  return result
}

function callBridgeSaveFileDialog(bridge: DesktopNativeBridge, suggestedName: string): Promise<string> {
  return new Promise((resolve) => {
    try {
      bridge.saveFileDialog(suggestedName, (filePath) => {
        resolve(typeof filePath === 'string' ? filePath : '')
      })
    } catch {
      resolve('')
    }
  })
}

function callBridgeOpenFileDialog(bridge: DesktopNativeBridge): Promise<string> {
  return new Promise((resolve) => {
    try {
      bridge.openFileDialog((filePath) => {
        resolve(typeof filePath === 'string' ? filePath : '')
      })
    } catch {
      resolve('')
    }
  })
}

function callBridgeReadFileAsBase64(bridge: DesktopNativeBridge, filePath: string): Promise<string> {
  return new Promise((resolve) => {
    try {
      bridge.readFileAsBase64(filePath, (base64Content) => {
        resolve(typeof base64Content === 'string' ? base64Content : '')
      })
    } catch {
      resolve('')
    }
  })
}

function callBridgeWriteFile(bridge: DesktopNativeBridge, filePath: string, base64Content: string): Promise<boolean> {
  return new Promise((resolve) => {
    try {
      bridge.writeFile(filePath, base64Content, (success) => {
        resolve(Boolean(success))
      })
    } catch {
      resolve(false)
    }
  })
}

function blobToBase64Payload(blob: Blob): Promise<string> {
  return new Promise((resolve, reject) => {
    const reader = new FileReader()
    reader.onload = () => {
      const result = typeof reader.result === 'string' ? reader.result : ''
      const splitIndex = result.indexOf(',')
      resolve(splitIndex >= 0 ? result.slice(splitIndex + 1) : '')
    }
    reader.onerror = () => reject(new Error('转换导出数据失败'))
    reader.readAsDataURL(blob)
  })
}

function canvasToBlob(canvas: HTMLCanvasElement, type: string, quality?: number): Promise<Blob | null> {
  return new Promise((resolve) => {
    canvas.toBlob((blob) => resolve(blob), type, quality)
  })
}

function getCanvas2DContext(canvas: HTMLCanvasElement | null, willReadFrequently = false) {
  if (!canvas) {
    return null
  }

  return willReadFrequently
    ? canvas.getContext('2d', { willReadFrequently: true })
    : canvas.getContext('2d')
}

function createLayerRaster(width: number, height: number, fillColor: string | null = null) {
  const canvas = document.createElement('canvas')
  canvas.width = width
  canvas.height = height

  if (fillColor) {
    const context = getCanvas2DContext(canvas, true)
    if (context) {
      context.save()
      context.fillStyle = fillColor
      context.fillRect(0, 0, width, height)
      context.restore()
    }
  }

  return canvas
}

function cloneRaster(source: HTMLCanvasElement) {
  const clone = createLayerRaster(source.width, source.height)
  const context = getCanvas2DContext(clone, true)
  if (context) {
    context.drawImage(source, 0, 0)
  }
  return clone
}

function syncDisplayCanvasSize() {
  const composite = compositeCanvasRef.value
  const preview = previewCanvasRef.value

  if (composite) {
    composite.width = canvasWidth.value
    composite.height = canvasHeight.value
  }

  if (preview) {
    preview.width = canvasWidth.value
    preview.height = canvasHeight.value
  }
}

function getCompositeContext() {
  return getCanvas2DContext(compositeCanvasRef.value, true)
}

function getPreviewContext() {
  return getCanvas2DContext(previewCanvasRef.value)
}

function getLayerRaster(layerId: string) {
  return layerRasterMap.get(layerId) ?? null
}

function getLayerContext(layerId: string) {
  return getCanvas2DContext(getLayerRaster(layerId), true)
}

function cloneBrushStyleState(style: BrushStyleState): BrushStyleState {
  return {
    angle: style.angle,
    roundness: style.roundness,
    spacing: style.spacing,
    hardness: style.hardness,
    flow: style.flow,
    sizeMode: style.sizeMode,
    sizeJitter: style.sizeJitter
  }
}

function createBrushRenderConfig(): BrushRenderConfig {
  return {
    color: brushColor.value,
    size: brushSize.value,
    opacity: brushOpacity.value,
    style: cloneBrushStyleState(brushStyle),
    pressureEnabled: pressureEnabled.value
  }
}

function isPaintTool(tool: ToolId): tool is PaintToolId {
  return tool === 'brush' || tool === 'pencil' || tool === 'ink' || tool === 'pen'
}

function isRecordablePaintTool(tool: ToolId): tool is RecordablePaintTool {
  return isPaintTool(tool) || tool === 'eraser'
}
void isRecordablePaintTool

function isRecordableDrawableStroke(tool: RecordablePaintTool) {
  return tool !== 'eraser'
}
void isRecordableDrawableStroke

const strokeSpatialCellSize = 96

function getStrokeSearchPadding(stroke: BrushStrokeRecord) {
  return Math.ceil(Math.max(3, stroke.maxRadius * 0.25))
}

function getStrokeSpatialKey(cellX: number, cellY: number) {
  return `${cellX}:${cellY}`
}

function forEachStrokeSpatialCell(left: number, top: number, right: number, bottom: number, visit: (key: string) => void) {
  const normalizedLeft = Math.max(0, Math.min(left, right))
  const normalizedTop = Math.max(0, Math.min(top, bottom))
  const normalizedRight = Math.max(normalizedLeft, Math.max(left, right))
  const normalizedBottom = Math.max(normalizedTop, Math.max(top, bottom))
  const startCellX = Math.floor(normalizedLeft / strokeSpatialCellSize)
  const endCellX = Math.floor(normalizedRight / strokeSpatialCellSize)
  const startCellY = Math.floor(normalizedTop / strokeSpatialCellSize)
  const endCellY = Math.floor(normalizedBottom / strokeSpatialCellSize)

  for (let cellY = startCellY; cellY <= endCellY; cellY += 1) {
    for (let cellX = startCellX; cellX <= endCellX; cellX += 1) {
      visit(getStrokeSpatialKey(cellX, cellY))
    }
  }
}

function addStrokeToSpatialIndex(history: LayerStrokeHistory, stroke: BrushStrokeRecord) {
  const padding = getStrokeSearchPadding(stroke)
  forEachStrokeSpatialCell(
    stroke.bounds.minX - padding,
    stroke.bounds.minY - padding,
    stroke.bounds.maxX + padding,
    stroke.bounds.maxY + padding,
    (key) => {
      const ids = history.spatialIndex.get(key)
      if (ids) {
        ids.push(stroke.id)
        return
      }
      history.spatialIndex.set(key, [stroke.id])
    }
  )
}

function removeStrokeFromSpatialIndex(history: LayerStrokeHistory, stroke: BrushStrokeRecord) {
  const padding = getStrokeSearchPadding(stroke)
  forEachStrokeSpatialCell(
    stroke.bounds.minX - padding,
    stroke.bounds.minY - padding,
    stroke.bounds.maxX + padding,
    stroke.bounds.maxY + padding,
    (key) => {
      const ids = history.spatialIndex.get(key)
      if (!ids) {
        return
      }

      const nextIds = ids.filter((id) => id !== stroke.id)
      if (nextIds.length === 0) {
        history.spatialIndex.delete(key)
        return
      }
      history.spatialIndex.set(key, nextIds)
    }
  )
}

function appendStrokeToHistory(history: LayerStrokeHistory, stroke: BrushStrokeRecord) {
  const nextIndex = history.strokes.length
  history.strokes.push(stroke)
  history.strokeOrder.set(stroke.id, nextIndex)
  addStrokeToSpatialIndex(history, stroke)
}

function removeStrokeFromHistory(history: LayerStrokeHistory, index: number) {
  const removed = history.strokes[index]
  if (!removed) {
    return null
  }

  history.strokes.splice(index, 1)
  history.strokeOrder.delete(removed.id)
  removeStrokeFromSpatialIndex(history, removed)

  for (let nextIndex = index; nextIndex < history.strokes.length; nextIndex += 1) {
    history.strokeOrder.set(history.strokes[nextIndex]!.id, nextIndex)
  }

  return removed
}

function createLayerStrokeHistory(baseRaster: HTMLCanvasElement | null, strokes: BrushStrokeRecord[] = []) {
  const history: LayerStrokeHistory = {
    baseRaster,
    strokes: [],
    strokeOrder: new Map(),
    spatialIndex: new Map()
  }

  for (const stroke of strokes) {
    appendStrokeToHistory(history, stroke)
  }

  return history
}

function getLayerStrokeHistory(layerId: string) {
  let history = layerStrokeHistoryMap.get(layerId)
  if (!history) {
    history = createLayerStrokeHistory(null)
    layerStrokeHistoryMap.set(layerId, history)
  }
  return history
}
void getLayerStrokeHistory

function resetLayerStrokeHistoryFromCurrent(layerId: string) {
  const raster = getLayerRaster(layerId)
  layerStrokeHistoryMap.set(layerId, createLayerStrokeHistory(raster ? cloneRaster(raster) : null))
}
void resetLayerStrokeHistoryFromCurrent

function clearAllLayerStrokeHistories() {
  layerStrokeHistoryMap.clear()
  activeRecordedStroke = null
}

function serializeBrushRenderConfig(config: BrushRenderConfig): SerializedBrushRenderConfig {
  return {
    color: config.color,
    size: config.size,
    opacity: config.opacity,
    style: cloneBrushStyleState(config.style),
    pressureEnabled: config.pressureEnabled
  }
}

function parseBrushRenderConfig(raw: unknown): BrushRenderConfig | null {
  if (!raw || typeof raw !== 'object') {
    return null
  }

  const value = raw as Partial<SerializedBrushRenderConfig>
  if (typeof value.color !== 'string') {
    return null
  }

  return {
    color: value.color,
    size: clamp(Number(value.size ?? 1), 1, 180),
    opacity: clamp(Number(value.opacity ?? 100), 1, 100),
    style: cloneBrushStyleState({
      angle: clamp(Number(value.style?.angle ?? 0), 0, 180),
      roundness: clamp(Number(value.style?.roundness ?? 100), 10, 100),
      spacing: clamp(Number(value.style?.spacing ?? 12), 1, 80),
      hardness: clamp(Number(value.style?.hardness ?? 100), 1, 100),
      flow: clamp(Number(value.style?.flow ?? 100), 1, 100),
      sizeMode: value.style?.sizeMode === 'random' || value.style?.sizeMode === 'pressure' ? value.style.sizeMode : 'fixed',
      sizeJitter: clamp(Number(value.style?.sizeJitter ?? 0), 0, 100)
    }),
    pressureEnabled: value.pressureEnabled !== false
  }
}

function serializeLayerStrokeHistory(layerId: string): SerializedLayerStrokeHistory | null {
  const history = layerStrokeHistoryMap.get(layerId)
  if (!history) {
    return null
  }

  return {
    baseImage: history.baseRaster?.toDataURL('image/png') ?? '',
    strokes: history.strokes.map((stroke) => ({
      id: stroke.id,
      tool: stroke.tool,
      config: serializeBrushRenderConfig(stroke.config),
      points: stroke.points.map((point) => ({ x: point.x, y: point.y, pressure: point.pressure, size: point.size })),
      maxRadius: stroke.maxRadius,
      bounds: { ...stroke.bounds }
    }))
  }
}

async function restoreLayerStrokeHistory(layerId: string, serialized?: SerializedLayerStrokeHistory | null) {
  if (!serialized) {
    resetLayerStrokeHistoryFromCurrent(layerId)
    return
  }

  const baseRaster = serialized.baseImage ? createLayerRaster(canvasWidth.value, canvasHeight.value) : null
  if (baseRaster && serialized.baseImage) {
    try {
      const image = await loadImage(serialized.baseImage)
      const context = getCanvas2DContext(baseRaster, true)
      context?.drawImage(image, 0, 0, canvasWidth.value, canvasHeight.value)
    } catch {
    }
  }

  const strokes: BrushStrokeRecord[] = []
  for (const rawStroke of serialized.strokes ?? []) {
    const config = parseBrushRenderConfig(rawStroke.config)
    if (!config || !Array.isArray(rawStroke.points) || rawStroke.points.length === 0) {
      continue
    }

    strokes.push({
      id: typeof rawStroke.id === 'string' && rawStroke.id ? rawStroke.id : createId(),
      layerId,
      tool: rawStroke.tool === 'eraser' || rawStroke.tool === 'pencil' || rawStroke.tool === 'ink' || rawStroke.tool === 'pen'
        ? rawStroke.tool
        : 'brush',
      config,
      points: rawStroke.points
        .map((point) => ({
          x: Number(point.x),
          y: Number(point.y),
          pressure: clamp(Number(point.pressure ?? 1), 0.05, 1),
          size: Math.max(0.45, Number(point.size ?? 1))
        }))
        .filter((point) => Number.isFinite(point.x) && Number.isFinite(point.y)),
      maxRadius: Math.max(0.45, Number(rawStroke.maxRadius ?? 1)),
      bounds: {
        minX: Number(rawStroke.bounds?.minX ?? 0),
        minY: Number(rawStroke.bounds?.minY ?? 0),
        maxX: Number(rawStroke.bounds?.maxX ?? 0),
        maxY: Number(rawStroke.bounds?.maxY ?? 0)
      }
    })
  }

  layerStrokeHistoryMap.set(layerId, createLayerStrokeHistory(baseRaster, strokes.filter((stroke) => stroke.points.length > 0)))
}
void clearAllLayerStrokeHistories

function rebuildLayerFromStrokeHistory(layerId: string) {
  const history = layerStrokeHistoryMap.get(layerId)
  const context = getLayerContext(layerId)
  if (!history || !context) {
    return false
  }

  context.clearRect(0, 0, canvasWidth.value, canvasHeight.value)
  if (history.baseRaster) {
    context.drawImage(history.baseRaster, 0, 0)
  }

  for (const stroke of history.strokes) {
    replayBrushStroke(context, stroke)
  }

  return true
}
void rebuildLayerFromStrokeHistory

function createLayer(name: string, fillColor: string | null = null): LayerModel {
  const layer: LayerModel = {
    id: createId(),
    name,
    visible: true,
    locked: false,
    opacity: 1,
    blendMode: 'source-over',
    thumbnail: ''
  }

  layerRasterMap.set(layer.id, createLayerRaster(canvasWidth.value, canvasHeight.value, fillColor))
  layerTextMap.set(layer.id, [])
  resetLayerStrokeHistoryFromCurrent(layer.id)
  return layer
}

function clearPreviewCanvas() {
  const context = getPreviewContext()
  if (!context) {
    return
  }

  context.clearRect(0, 0, canvasWidth.value, canvasHeight.value)
}

function renderComposite() {
  const context = getCompositeContext()
  if (!context) {
    return
  }

  context.save()
  context.clearRect(0, 0, canvasWidth.value, canvasHeight.value)
  context.fillStyle = '#ffffff'
  context.fillRect(0, 0, canvasWidth.value, canvasHeight.value)

  for (const layer of layers.value) {
    if (!layer.visible) {
      continue
    }

    const raster = getLayerRaster(layer.id)
    if (!raster) {
      continue
    }

    context.save()
    context.globalAlpha = clamp(layer.opacity, 0, 1)
    context.globalCompositeOperation = layer.blendMode
    context.drawImage(raster, 0, 0)
    renderLayerTextElements(context, layer.id, clamp(layer.opacity, 0, 1))
    context.restore()
  }

  drawFloatingSelectionOverlay(context)

  context.restore()
}

function refreshLayerThumbnail(layerId: string) {
  const layer = layers.value.find((item) => item.id === layerId)
  const raster = getLayerRaster(layerId)
  if (!layer || !raster) {
    return
  }

  const thumbWidth = 78
  const thumbHeight = 52
  const thumbCanvas = document.createElement('canvas')
  thumbCanvas.width = thumbWidth
  thumbCanvas.height = thumbHeight
  const thumbContext = getCanvas2DContext(thumbCanvas)
  if (!thumbContext) {
    return
  }

  thumbContext.fillStyle = '#f8fafc'
  thumbContext.fillRect(0, 0, thumbWidth, thumbHeight)

  const cell = 6
  thumbContext.fillStyle = '#e2e8f0'
  for (let y = 0; y < thumbHeight; y += cell) {
    for (let x = 0; x < thumbWidth; x += cell) {
      if (((x / cell) + (y / cell)) % 2 === 0) {
        thumbContext.fillRect(x, y, cell, cell)
      }
    }
  }

  const scale = Math.min(thumbWidth / canvasWidth.value, thumbHeight / canvasHeight.value)
  const drawWidth = canvasWidth.value * scale
  const drawHeight = canvasHeight.value * scale
  const offsetX = (thumbWidth - drawWidth) / 2
  const offsetY = (thumbHeight - drawHeight) / 2

  thumbContext.drawImage(raster, offsetX, offsetY, drawWidth, drawHeight)

  if (getLayerTextElements(layerId).length > 0) {
    thumbContext.save()
    thumbContext.translate(offsetX, offsetY)
    thumbContext.scale(scale, scale)
    renderLayerTextElements(thumbContext, layerId, clamp(layer.opacity, 0, 1))
    thumbContext.restore()
  }

  thumbContext.strokeStyle = '#94a3b8'
  thumbContext.strokeRect(0.5, 0.5, thumbWidth - 1, thumbHeight - 1)
  layer.thumbnail = thumbCanvas.toDataURL('image/png')
}

function refreshAllLayerThumbnails() {
  for (const layer of layers.value) {
    refreshLayerThumbnail(layer.id)
  }
}

function createLayerDisplayRaster(layerId: string) {
  const raster = getLayerRaster(layerId)
  if (!raster) {
    return null
  }

  if (getLayerTextElements(layerId).length === 0) {
    return raster
  }

  const canvas = createLayerRaster(canvasWidth.value, canvasHeight.value)
  const context = getCanvas2DContext(canvas, true)
  if (!context) {
    return raster
  }

  context.drawImage(raster, 0, 0)
  renderLayerTextElements(context, layerId, 1)
  return canvas
}

function makeSnapshotMarker(snapshot: HistorySnapshot) {
  return [
    snapshot.width,
    snapshot.height,
    snapshot.activeLayerId ?? 'none',
    snapshot.layers
      .map((layer) => `${layer.id}:${layer.visible ? 1 : 0}:${layer.locked ? 1 : 0}:${Math.round(layer.opacity * 100)}:${layer.blendMode}:${layer.image.length}:${layer.textElements?.length ?? 0}`)
      .join('|')
  ].join('::')
}

function captureSnapshot(): HistorySnapshot {
  return {
    width: canvasWidth.value,
    height: canvasHeight.value,
    documentName: documentName.value,
    activeLayerId: activeLayerId.value,
    layers: layers.value.map((layer) => ({
      id: layer.id,
      name: layer.name,
      visible: layer.visible,
      locked: layer.locked,
      opacity: layer.opacity,
      blendMode: layer.blendMode,
      image: getLayerRaster(layer.id)?.toDataURL('image/png') ?? '',
      textElements: serializeLayerTextElements(layer.id)
    }))
  }
}

function resetHistory() {
  historySnapshots.value = []
  historyIndex.value = -1
  lastSnapshotMarker.value = ''
}

function pushHistorySnapshot() {
  if (restoringHistory.value) {
    return
  }

  const snapshot = captureSnapshot()
  const marker = makeSnapshotMarker(snapshot)
  if (marker === lastSnapshotMarker.value) {
    return
  }

  if (historyIndex.value < historySnapshots.value.length - 1) {
    historySnapshots.value = historySnapshots.value.slice(0, historyIndex.value + 1)
  }

  historySnapshots.value.push(snapshot)
  if (historySnapshots.value.length > maxHistory) {
    historySnapshots.value.shift()
  }

  historyIndex.value = historySnapshots.value.length - 1
  lastSnapshotMarker.value = marker
}

async function restoreSnapshot(snapshot: HistorySnapshot) {
  restoringHistory.value = true
  cancelTextEditor()
  clearFloatingSelection()
  clearPreviewCanvas()
  clearAllLayerStrokeHistories()
  layerTextMap.clear()

  canvasWidth.value = snapshot.width
  canvasHeight.value = snapshot.height
  documentName.value = snapshot.documentName || '未命名 1'
  syncDisplayCanvasSize()

  layers.value = snapshot.layers.map((item) => ({
    id: item.id,
    name: item.name,
    visible: item.visible,
    locked: item.locked,
    opacity: item.opacity,
    blendMode: item.blendMode,
    thumbnail: ''
  }))

  layerRasterMap.clear()
  for (const layer of snapshot.layers) {
    const raster = createLayerRaster(snapshot.width, snapshot.height)
    layerRasterMap.set(layer.id, raster)

    if (layer.image) {
      try {
        const image = await loadImage(layer.image)
        const context = getCanvas2DContext(raster, true)
        if (context) {
          context.drawImage(image, 0, 0, snapshot.width, snapshot.height)
        }
      } catch {
      }
    }

    restoreLayerTextElements(layer.id, layer.textElements)
  }

  activeLayerId.value = snapshot.activeLayerId && layers.value.some((layer) => layer.id === snapshot.activeLayerId)
    ? snapshot.activeLayerId
    : layers.value[layers.value.length - 1]?.id ?? null

  renderComposite()
  refreshAllLayerThumbnails()
  await nextTick()
  fitCanvasToViewport()

  restoringHistory.value = false
}

async function undo() {
  if (!canUndo.value) {
    return
  }

  historyIndex.value -= 1
  const snapshot = historySnapshots.value[historyIndex.value]
  if (!snapshot) {
    return
  }

  await restoreSnapshot(snapshot)
  lastSnapshotMarker.value = makeSnapshotMarker(snapshot)
}

async function redo() {
  if (!canRedo.value) {
    return
  }

  historyIndex.value += 1
  const snapshot = historySnapshots.value[historyIndex.value]
  if (!snapshot) {
    return
  }

  await restoreSnapshot(snapshot)
  lastSnapshotMarker.value = makeSnapshotMarker(snapshot)
}

function toCanvasPoint(event: { clientX: number; clientY: number }): Point | null {
  const stage = stageRef.value
  const scale = viewScale.value
  if (!stage || scale <= 0) {
    return null
  }

  const rect = stage.getBoundingClientRect()
  if (rect.width <= 0 || rect.height <= 0) {
    return null
  }

  return {
    x: clamp((event.clientX - rect.left) / scale, 0, canvasWidth.value),
    y: clamp((event.clientY - rect.top) / scale, 0, canvasHeight.value)
  }
}

function normalizePressure(event: PointerEvent) {
  let pressure = event.pressure
  if (!Number.isFinite(pressure) || pressure <= 0) {
    pressure = event.pointerType === 'mouse' ? 0.62 : 0.5
  }

  return clamp(pressure, 0.05, 1)
}

function isShapeTool(tool: ToolId) {
  return tool === 'shape'
}

function isBrushTool(tool: ToolId) {
  return isPaintTool(tool) || tool === 'eraser'
}

function drawRegularPolygon(context: CanvasRenderingContext2D, centerX: number, centerY: number, radius: number, sides: number, rotation = -Math.PI / 2) {
  if (sides < 3) {
    return
  }

  context.beginPath()
  for (let index = 0; index < sides; index += 1) {
    const angle = rotation + (Math.PI * 2 * index) / sides
    const x = centerX + Math.cos(angle) * radius
    const y = centerY + Math.sin(angle) * radius
    if (index === 0) {
      context.moveTo(x, y)
    } else {
      context.lineTo(x, y)
    }
  }
  context.closePath()
}

function drawArrowShape(context: CanvasRenderingContext2D, x: number, y: number, width: number, height: number, direction: 'left' | 'right' | 'up' | 'down') {
  const safeWidth = Math.max(6, width)
  const safeHeight = Math.max(6, height)
  const shaft = Math.min(safeWidth, safeHeight) * 0.34
  const points: Point[] = []

  if (direction === 'right') {
    points.push(
      { x, y: y + safeHeight * 0.35 },
      { x: x + safeWidth * 0.62, y: y + safeHeight * 0.35 },
      { x: x + safeWidth * 0.62, y },
      { x: x + safeWidth, y: y + safeHeight * 0.5 },
      { x: x + safeWidth * 0.62, y: y + safeHeight },
      { x: x + safeWidth * 0.62, y: y + safeHeight * 0.65 },
      { x, y: y + safeHeight * 0.65 }
    )
  } else if (direction === 'left') {
    points.push(
      { x: x + safeWidth, y: y + safeHeight * 0.35 },
      { x: x + safeWidth * 0.38, y: y + safeHeight * 0.35 },
      { x: x + safeWidth * 0.38, y },
      { x, y: y + safeHeight * 0.5 },
      { x: x + safeWidth * 0.38, y: y + safeHeight },
      { x: x + safeWidth * 0.38, y: y + safeHeight * 0.65 },
      { x: x + safeWidth, y: y + safeHeight * 0.65 }
    )
  } else if (direction === 'up') {
    points.push(
      { x: x + safeWidth * 0.35, y: y + safeHeight },
      { x: x + safeWidth * 0.35, y: y + safeHeight * 0.38 },
      { x, y: y + safeHeight * 0.38 },
      { x: x + safeWidth * 0.5, y },
      { x: x + safeWidth, y: y + safeHeight * 0.38 },
      { x: x + safeWidth * 0.65, y: y + safeHeight * 0.38 },
      { x: x + safeWidth * 0.65, y: y + safeHeight }
    )
  } else {
    points.push(
      { x: x + safeWidth * 0.35, y },
      { x: x + safeWidth * 0.35, y: y + safeHeight * 0.62 },
      { x, y: y + safeHeight * 0.62 },
      { x: x + safeWidth * 0.5, y: y + safeHeight },
      { x: x + safeWidth, y: y + safeHeight * 0.62 },
      { x: x + safeWidth * 0.65, y: y + safeHeight * 0.62 },
      { x: x + safeWidth * 0.65, y }
    )
  }

  context.beginPath()
  points.forEach((point, index) => {
    if (index === 0) {
      context.moveTo(point.x, point.y)
    } else {
      context.lineTo(point.x, point.y)
    }
  })
  context.closePath()
  context.lineWidth = Math.max(context.lineWidth, shaft * 0.15)
}

function drawStar(context: CanvasRenderingContext2D, centerX: number, centerY: number, outerRadius: number, innerRadius: number, points: number, rotation = -Math.PI / 2) {
  context.beginPath()
  const total = points * 2
  for (let index = 0; index < total; index += 1) {
    const radius = index % 2 === 0 ? outerRadius : innerRadius
    const angle = rotation + (Math.PI * index) / points
    const x = centerX + Math.cos(angle) * radius
    const y = centerY + Math.sin(angle) * radius
    if (index === 0) {
      context.moveTo(x, y)
    } else {
      context.lineTo(x, y)
    }
  }
  context.closePath()
}

function drawHeartPath(context: CanvasRenderingContext2D, x: number, y: number, width: number, height: number) {
  const w = Math.max(4, width)
  const h = Math.max(4, height)
  context.beginPath()
  context.moveTo(x + w * 0.5, y + h * 0.92)
  context.bezierCurveTo(x + w * 0.12, y + h * 0.68, x, y + h * 0.4, x + w * 0.22, y + h * 0.22)
  context.bezierCurveTo(x + w * 0.36, y + h * 0.08, x + w * 0.5, y + h * 0.16, x + w * 0.5, y + h * 0.28)
  context.bezierCurveTo(x + w * 0.5, y + h * 0.16, x + w * 0.64, y + h * 0.08, x + w * 0.78, y + h * 0.22)
  context.bezierCurveTo(x + w, y + h * 0.4, x + w * 0.88, y + h * 0.68, x + w * 0.5, y + h * 0.92)
  context.closePath()
}

function getBrushWidthRange(tool: ToolId, config?: BrushRenderConfig) {
  const renderConfig = config ?? createBrushRenderConfig()
  const size = Math.max(1, renderConfig.size)

  if (tool === 'pencil') {
    return { min: size, max: size }
  }

  if (tool === 'pen') {
    const min = Math.max(2, size * 0.5)
    return { min, max: Math.max(min + 0.4, size) }
  }

  if (tool === 'ink') {
    const min = Math.max(2.8, size * 0.38)
    return { min, max: Math.max(min + 1.2, size * 1.08) }
  }

  const min = Math.max(3, size * 0.24)
  return { min, max: Math.max(min + 2.2, size * 1.1) }
}

function resolveStrokeWidth(
  tool: ToolId,
  point: Point,
  pressure: number,
  timestamp: number,
  previousPoint: Point | null,
  previousWidth: number,
  previousTimestamp: number,
  config?: BrushRenderConfig
) {
  const renderConfig = config ?? createBrushRenderConfig()
  const range = getBrushWidthRange(tool, renderConfig)

  if (tool === 'pencil') {
    return range.max
  }

  const distance = previousPoint ? Math.hypot(point.x - previousPoint.x, point.y - previousPoint.y) : 0
  const deltaTime = previousTimestamp > 0 ? Math.max(1, timestamp - previousTimestamp) : 16
  const speed = distance / deltaTime

  let speedCeiling = 1.25
  let speedExponent = 0.7
  let smoothing = 0.36
  let entryBoost = 1

  if (tool === 'ink') {
    speedCeiling = 1
    speedExponent = 0.58
    smoothing = 0.34
    entryBoost = 1.14
  } else if (tool === 'brush') {
    speedCeiling = 1.65
    speedExponent = 0.86
    smoothing = 0.24
    entryBoost = 1.03
  } else if (tool === 'pen') {
    speedCeiling = 1.8
    speedExponent = 0.9
    smoothing = 0.42
    entryBoost = 1.08
  }

  const normalizedSpeed = clamp(speed / speedCeiling, 0, 1)
  let width = range.max - (range.max - range.min) * Math.pow(normalizedSpeed, speedExponent)

  if (renderConfig.pressureEnabled && renderConfig.style.sizeMode === 'pressure') {
    const pressureGain = tool === 'pen' ? 0.18 : 0.26
    width *= 1 - pressureGain + pressure * pressureGain
  }

  if (previousWidth > 0) {
    width = lerp(previousWidth, width, smoothing)
  } else {
    width *= entryBoost
  }

  return clamp(width, range.min, range.max)
}

function getSpacing(tool: ToolId, config?: BrushRenderConfig) {
  const renderConfig = config ?? createBrushRenderConfig()
  if (tool === 'pencil') {
    return 0.75
  }

  if (tool === 'pen') {
    return Math.max(0.7, renderConfig.size * 0.12)
  }

  return Math.max(0.8, (renderConfig.size * renderConfig.style.spacing) / 120)
}

function drawBrushStamp(context: CanvasRenderingContext2D, point: Point, width: number, tool: ToolId, config?: BrushRenderConfig) {
  const renderConfig = config ?? createBrushRenderConfig()
  const radius = Math.max(0.45, width / 2)
  const widthRange = getBrushWidthRange(tool, renderConfig)
  const roundness = clamp(renderConfig.style.roundness / 100, 0.1, 1)
  const angle = (renderConfig.style.angle * Math.PI) / 180

  context.save()

  if (tool === 'eraser') {
    context.globalCompositeOperation = 'destination-out'
    context.fillStyle = '#000000'
    context.globalAlpha = clamp((renderConfig.opacity / 100) * (renderConfig.style.flow / 100), 0.02, 1)
  } else {
    context.globalCompositeOperation = 'source-over'
    context.fillStyle = renderConfig.color
  }

  const hardness = clamp(renderConfig.style.hardness / 100, 0.03, 1)

  context.translate(point.x, point.y)
  context.rotate(angle)
  context.scale(1, roundness)

  if (tool === 'pencil') {
    context.fillStyle = '#555555'
    context.globalAlpha = clamp(renderConfig.opacity / 100, 0.7, 0.8)
    context.beginPath()
    context.arc(0, 0, radius, 0, Math.PI * 2)
    context.fill()

    for (let index = 0; index < 6; index += 1) {
      const seed = Math.sin(point.x * 12.9898 + point.y * 78.233 + index * 37.719)
      const angleOffset = seed * Math.PI * 2
      const distance = radius * (0.2 + Math.abs(seed) * 0.7)
      context.globalAlpha = 0.05 + (index % 3) * 0.015
      context.beginPath()
      context.arc(
        Math.cos(angleOffset) * distance,
        Math.sin(angleOffset) * distance,
        Math.max(0.18, radius * 0.32),
        0,
        Math.PI * 2
      )
      context.fill()
    }
  } else if (tool === 'brush') {
    context.fillStyle = '#000000'
    context.globalAlpha = clamp((renderConfig.opacity / 100) * 0.7, 0.18, 0.56)
    context.shadowColor = 'rgba(0, 0, 0, 0.2)'
    context.shadowBlur = Math.max(5, radius * 2.4)
    context.beginPath()
    context.arc(0, 0, radius, 0, Math.PI * 2)
    context.fill()
    context.shadowBlur = 0
    context.globalAlpha = clamp((renderConfig.opacity / 100) * 0.22, 0.08, 0.24)
    context.beginPath()
    context.arc(0, 0, radius * 1.45, 0, Math.PI * 2)
    context.fill()
    context.globalAlpha = clamp((renderConfig.opacity / 100) * 0.1, 0.04, 0.12)
    context.beginPath()
    context.arc(0, 0, radius * 1.9, 0, Math.PI * 2)
    context.fill()
  } else {
    context.fillStyle = '#000000'
    context.globalAlpha = tool === 'ink' ? 1 : clamp(renderConfig.opacity / 100, 0.02, 1)
    context.beginPath()
    context.arc(0, 0, radius, 0, Math.PI * 2)
    context.fill()

    if (tool === 'ink' && hardness < 0.97) {
      context.globalAlpha = clamp((1 - hardness) * 0.11, 0.015, 0.08)
      context.beginPath()
      context.arc(0, 0, radius * 1.16, 0, Math.PI * 2)
      context.fill()
    }

    if (tool === 'ink') {
      context.globalAlpha = 0.08
      context.beginPath()
      context.arc(-radius * 0.16, -radius * 0.12, radius * 0.72, 0, Math.PI * 2)
      context.fill()

      const dryRatio = clamp((widthRange.max - width) / Math.max(0.001, widthRange.max - widthRange.min), 0, 1)
      if (dryRatio > 0.32) {
        context.globalCompositeOperation = 'destination-out'
        context.globalAlpha = 0.035 + dryRatio * 0.05
        const notchCount = 2 + Math.round(dryRatio * 3)
        for (let index = 0; index < notchCount; index += 1) {
          const seed = Math.sin(point.x * 8.123 + point.y * 5.371 + index * 19.17)
          const sweep = Math.cos(seed * Math.PI * 2)
          context.beginPath()
          context.arc(
            sweep * radius * (0.28 + dryRatio * 0.35),
            seed * radius * 0.32,
            radius * (0.09 + dryRatio * 0.12),
            0,
            Math.PI * 2
          )
          context.fill()
        }
      }
    }
  }

  context.restore()
}

function drawBrushSegment(
  context: CanvasRenderingContext2D,
  from: StrokePointSample,
  to: StrokePointSample,
  tool: ToolId,
  config?: BrushRenderConfig
) {
  const distance = Math.hypot(to.x - from.x, to.y - from.y)
  if (distance < 0.001) {
    drawBrushStamp(context, to, to.size, tool, config)
    return
  }

  const step = getSpacing(tool, config)
  const count = Math.max(1, Math.ceil(distance / step))
  for (let index = 0; index <= count; index += 1) {
    const t = count === 0 ? 1 : index / count
    const point: Point = {
      x: from.x + (to.x - from.x) * t,
      y: from.y + (to.y - from.y) * t
    }
    const width = from.size + (to.size - from.size) * t
    drawBrushStamp(context, point, width, tool, config)
  }
}

function replayBrushStroke(context: CanvasRenderingContext2D, stroke: BrushStrokeRecord) {
  if (stroke.points.length === 0) {
    return
  }

  if (stroke.points.length === 1) {
    const point = stroke.points[0]!
    drawBrushStamp(context, point, point.size, stroke.tool, stroke.config)
    return
  }

  for (let index = 1; index < stroke.points.length; index += 1) {
    const from = stroke.points[index - 1]!
    const to = stroke.points[index]!
    drawBrushSegment(context, from, to, stroke.tool, stroke.config)
  }
}

function beginRecordedStroke(layerId: string, tool: RecordablePaintTool, point: Point, pressure: number, size: number) {
  const history = getLayerStrokeHistory(layerId)
  if (!history.baseRaster && history.strokes.length === 0) {
    const raster = getLayerRaster(layerId)
    history.baseRaster = raster ? cloneRaster(raster) : null
  }

  const config = createBrushRenderConfig()
  const radius = Math.max(0.45, size / 2)
  activeRecordedStroke = {
    id: createId(),
    layerId,
    tool,
    config,
    points: [{ x: point.x, y: point.y, pressure, size }],
    maxRadius: radius,
    bounds: {
      minX: point.x - radius,
      minY: point.y - radius,
      maxX: point.x + radius,
      maxY: point.y + radius
    }
  }
}

function appendRecordedStrokePoint(point: Point, pressure: number, size: number) {
  if (!activeRecordedStroke) {
    return
  }

  const points = activeRecordedStroke.points
  const lastPoint = points[points.length - 1]
  if (
    lastPoint &&
    Math.hypot(point.x - lastPoint.x, point.y - lastPoint.y) < 0.35 &&
    Math.abs(pressure - lastPoint.pressure) < 0.01 &&
    Math.abs(size - lastPoint.size) < 0.01
  ) {
    return
  }

  const radius = Math.max(0.45, size / 2)
  activeRecordedStroke.maxRadius = Math.max(activeRecordedStroke.maxRadius, radius)
  activeRecordedStroke.bounds.minX = Math.min(activeRecordedStroke.bounds.minX, point.x - radius)
  activeRecordedStroke.bounds.minY = Math.min(activeRecordedStroke.bounds.minY, point.y - radius)
  activeRecordedStroke.bounds.maxX = Math.max(activeRecordedStroke.bounds.maxX, point.x + radius)
  activeRecordedStroke.bounds.maxY = Math.max(activeRecordedStroke.bounds.maxY, point.y + radius)
  points.push({ x: point.x, y: point.y, pressure, size })
}

function applyPenTerminalAccent() {
  if (activeTool.value !== 'pen' || !activeRecordedStroke || !drawState.lastPoint) {
    return
  }

  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return
  }

  const context = getLayerContext(layer.id)
  if (!context) {
    return
  }

  const accentSize = clamp(drawState.lastStrokeSize * 1.14, 2.2, 4.4)
  appendRecordedStrokePoint(drawState.lastPoint, drawState.lastPressure, accentSize)
  drawBrushStamp(context, drawState.lastPoint, accentSize, 'pen')
}

function commitRecordedStroke() {
  if (!activeRecordedStroke || activeRecordedStroke.points.length === 0) {
    activeRecordedStroke = null
    return
  }

  const history = getLayerStrokeHistory(activeRecordedStroke.layerId)
  appendStrokeToHistory(history, activeRecordedStroke)
  activeRecordedStroke = null
}

function discardRecordedStroke() {
  activeRecordedStroke = null
}

function getStrokeEraserRadius() {
  if (activeTool.value !== 'eraser' || eraserMode.value !== 'stroke') {
    return 0
  }

  return Math.max(2, brushSize.value / 2)
}

function getStrokeHitPadding(stroke: BrushStrokeRecord) {
  return getStrokeSearchPadding(stroke) + getStrokeEraserRadius()
}

function getPointDistanceSquared(fromX: number, fromY: number, toX: number, toY: number) {
  const dx = fromX - toX
  const dy = fromY - toY
  return dx * dx + dy * dy
}

function measurePointToSegmentDistanceSquared(point: Point, from: StrokePointSample, to: StrokePointSample) {
  const dx = to.x - from.x
  const dy = to.y - from.y
  const lengthSquared = dx * dx + dy * dy

  if (lengthSquared <= 0.0001) {
    return {
      distanceSquared: getPointDistanceSquared(point.x, point.y, from.x, from.y),
      t: 0
    }
  }

  const t = clamp(((point.x - from.x) * dx + (point.y - from.y) * dy) / lengthSquared, 0, 1)
  const closestX = from.x + dx * t
  const closestY = from.y + dy * t
  return {
    distanceSquared: getPointDistanceSquared(point.x, point.y, closestX, closestY),
    t
  }
}

function measureStrokeHitScore(stroke: BrushStrokeRecord, point: Point) {
  const padding = getStrokeHitPadding(stroke)

  if (
    point.x < stroke.bounds.minX - padding ||
    point.x > stroke.bounds.maxX + padding ||
    point.y < stroke.bounds.minY - padding ||
    point.y > stroke.bounds.maxY + padding
  ) {
    return 0
  }

  const points = stroke.points
  if (points.length === 0) {
    return 0
  }

  if (points.length === 1) {
    const target = points[0]!
    const radius = Math.max(0.45, target.size / 2) + padding
    const score = radius * radius - getPointDistanceSquared(point.x, point.y, target.x, target.y)
    return score > 0 ? score : 0
  }

  let bestScore = 0
  for (let index = 1; index < points.length; index += 1) {
    const from = points[index - 1]!
    const to = points[index]!
    const segmentRadius = Math.max(from.size, to.size) / 2 + padding

    if (
      point.x < Math.min(from.x, to.x) - segmentRadius ||
      point.x > Math.max(from.x, to.x) + segmentRadius ||
      point.y < Math.min(from.y, to.y) - segmentRadius ||
      point.y > Math.max(from.y, to.y) + segmentRadius
    ) {
      continue
    }

    const hit = measurePointToSegmentDistanceSquared(point, from, to)
    const localSize = from.size + (to.size - from.size) * hit.t
    const localRadius = Math.max(0.45, localSize / 2) + padding
    const score = localRadius * localRadius - hit.distanceSquared
    if (score > bestScore) {
      bestScore = score
    }
  }

  return bestScore
}

function collectStrokeHitCandidates(history: LayerStrokeHistory, point: Point) {
  const eraserRadius = getStrokeEraserRadius()
  const candidateIds = new Set<string>()
  const candidates: StrokeHitMatch[] = []

  forEachStrokeSpatialCell(
    point.x - eraserRadius,
    point.y - eraserRadius,
    point.x + eraserRadius,
    point.y + eraserRadius,
    (key) => {
      const ids = history.spatialIndex.get(key)
      if (!ids) {
        return
      }

      for (let index = ids.length - 1; index >= 0; index -= 1) {
        const strokeId = ids[index]!
        if (candidateIds.has(strokeId)) {
          continue
        }

        candidateIds.add(strokeId)
        const strokeIndex = history.strokeOrder.get(strokeId)
        if (strokeIndex == null) {
          continue
        }

        const stroke = history.strokes[strokeIndex]
        if (!stroke) {
          continue
        }

        candidates.push({
          history,
          stroke,
          index: strokeIndex
        })
      }
    }
  )

  candidates.sort((left, right) => right.index - left.index)
  return candidates
}

function boundsOverlap(
  left: { minX: number; minY: number; maxX: number; maxY: number },
  right: { minX: number; minY: number; maxX: number; maxY: number },
  padding = 0
) {
  return !(
    left.maxX + padding < right.minX ||
    right.maxX + padding < left.minX ||
    left.maxY + padding < right.minY ||
    right.maxY + padding < left.minY
  )
}

function hasLaterEraserAffectingStroke(history: LayerStrokeHistory, index: number, stroke: BrushStrokeRecord) {
  const padding = Math.max(getStrokeSearchPadding(stroke), stroke.maxRadius)
  for (let nextIndex = index + 1; nextIndex < history.strokes.length; nextIndex += 1) {
    const nextStroke = history.strokes[nextIndex]
    if (!nextStroke || nextStroke.tool !== 'eraser') {
      continue
    }

    if (boundsOverlap(stroke.bounds, nextStroke.bounds, padding + nextStroke.maxRadius)) {
      return true
    }
  }

  return false
}

function findRecordedStrokeMatchAtPoint(point: Point): StrokeHitMatch | null {
  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return null
  }

  const history = layerStrokeHistoryMap.get(layer.id)
  if (!history || history.strokes.length === 0) {
    return null
  }

  for (const candidate of collectStrokeHitCandidates(history, point)) {
    if (!isRecordableDrawableStroke(candidate.stroke.tool)) {
      continue
    }

    const score = measureStrokeHitScore(candidate.stroke, point)
    if (score > 0) {
      return candidate
    }
  }

  return null
}

function createStrokeSelectionRaster(stroke: BrushStrokeRecord) {
  const rect = buildRectFromPoints(stroke.bounds.minX, stroke.bounds.minY, stroke.bounds.maxX, stroke.bounds.maxY)
  if (rect.width <= 1 || rect.height <= 1) {
    return null
  }

  const floating = document.createElement('canvas')
  floating.width = rect.width
  floating.height = rect.height
  const floatingContext = getCanvas2DContext(floating)
  if (!floatingContext) {
    return null
  }

  floatingContext.save()
  floatingContext.translate(-rect.x, -rect.y)
  replayBrushStroke(floatingContext, stroke)
  floatingContext.restore()

  return { floating, rect }
}

function captureRecordedStrokeSelection(match: StrokeHitMatch) {
  const layer = activeLayer.value
  if (!layer || hasLaterEraserAffectingStroke(match.history, match.index, match.stroke)) {
    return false
  }

  const selection = createStrokeSelectionRaster(match.stroke)
  if (!selection) {
    return false
  }

  removeStrokeFromHistory(match.history, match.index)
  const rebuilt = rebuildLayerFromStrokeHistory(layer.id)
  if (!rebuilt) {
    appendStrokeToHistory(match.history, match.stroke)
    rebuildLayerFromStrokeHistory(layer.id)
    return false
  }

  setFloatingSelection(selection.floating, selection.rect, 'rect', [])
  renderComposite()
  refreshLayerThumbnail(layer.id)
  return true
}

function collectRasterStrokeRegionAtPoint(point: Point) {
  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return null
  }

  const context = getLayerContext(layer.id)
  const raster = getLayerRaster(layer.id)
  if (!context || !raster) {
    return null
  }

  const width = raster.width
  const height = raster.height
  const startX = clamp(Math.floor(point.x), 0, width - 1)
  const startY = clamp(Math.floor(point.y), 0, height - 1)
  const imageData = context.getImageData(0, 0, width, height)
  const data = imageData.data
  const startIndex = startY * width + startX
  const startOffset = startIndex * 4
  const seedAlpha = data[startOffset + 3]
  if (seedAlpha <= 10) {
    return null
  }

  const seed: [number, number, number] = [
    normalizePremultipliedChannel(data[startOffset], seedAlpha),
    normalizePremultipliedChannel(data[startOffset + 1], seedAlpha),
    normalizePremultipliedChannel(data[startOffset + 2], seedAlpha)
  ]
  const toleranceSquared = 95 * 95
  const bridgeToleranceSquared = 120 * 120
  const bridgePadding = 12
  const visited = new Uint8Array(width * height)
  const mask = new Uint8Array(width * height)
  let minX = width
  let minY = height
  let maxX = -1
  let maxY = -1

  const floodRegion = (seedIndex: number, nextToleranceSquared: number) => {
    const stack: number[] = [seedIndex]
    visited[seedIndex] = 1

    while (stack.length > 0) {
      const pixelIndex = stack.pop()
      if (pixelIndex == null) {
        continue
      }

      const offset = pixelIndex * 4
      const alpha = data[offset + 3]
      if (alpha <= 2 || colorDistanceSquaredUnpremultiplied(data, offset, seed) > nextToleranceSquared) {
        continue
      }

      mask[pixelIndex] = 1
      const x = pixelIndex % width
      const y = Math.floor(pixelIndex / width)
      minX = Math.min(minX, x)
      minY = Math.min(minY, y)
      maxX = Math.max(maxX, x)
      maxY = Math.max(maxY, y)

      for (let deltaY = -2; deltaY <= 2; deltaY += 1) {
        const nextY = y + deltaY
        if (nextY < 0 || nextY >= height) {
          continue
        }

        for (let deltaX = -2; deltaX <= 2; deltaX += 1) {
          if ((deltaX === 0 && deltaY === 0) || deltaX * deltaX + deltaY * deltaY > 5) {
            continue
          }

          const nextX = x + deltaX
          if (nextX < 0 || nextX >= width) {
            continue
          }

          const nextIndex = nextY * width + nextX
          if (visited[nextIndex] === 1) {
            continue
          }

          visited[nextIndex] = 1
          stack.push(nextIndex)
        }
      }
    }
  }

  floodRegion(startIndex, toleranceSquared)

  if (maxX >= minX && maxY >= minY) {
    for (let pass = 0; pass < 4; pass += 1) {
      let expanded = false
      const searchMinX = Math.max(0, minX - bridgePadding)
      const searchMinY = Math.max(0, minY - bridgePadding)
      const searchMaxX = Math.min(width - 1, maxX + bridgePadding)
      const searchMaxY = Math.min(height - 1, maxY + bridgePadding)

      for (let y = searchMinY; y <= searchMaxY; y += 1) {
        for (let x = searchMinX; x <= searchMaxX; x += 1) {
          if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
            continue
          }

          const pixelIndex = y * width + x
          if (visited[pixelIndex] === 1) {
            continue
          }

          const offset = pixelIndex * 4
          const alpha = data[offset + 3]
          if (alpha <= 2 || colorDistanceSquaredUnpremultiplied(data, offset, seed) > bridgeToleranceSquared) {
            continue
          }

          floodRegion(pixelIndex, bridgeToleranceSquared)
          expanded = true
        }
      }

      if (!expanded) {
        break
      }
    }
  }

  if (maxX < minX || maxY < minY) {
    return null
  }

  return {
    width,
    height,
    mask,
    bounds: { minX, minY, maxX, maxY }
  }
}

function captureRasterRegionSelection(region: NonNullable<ReturnType<typeof collectRasterStrokeRegionAtPoint>>) {
  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return false
  }

  const context = getLayerContext(layer.id)
  if (!context) {
    return false
  }

  const rect = buildRectFromPoints(region.bounds.minX, region.bounds.minY, region.bounds.maxX, region.bounds.maxY)
  if (rect.width <= 1 || rect.height <= 1) {
    return false
  }

  const floating = document.createElement('canvas')
  floating.width = rect.width
  floating.height = rect.height
  const floatingContext = getCanvas2DContext(floating)
  if (!floatingContext) {
    return false
  }

  const imageData = context.getImageData(rect.x, rect.y, rect.width, rect.height)
  const sourcePixels = imageData.data
  const floatingImage = floatingContext.createImageData(rect.width, rect.height)
  const floatingPixels = floatingImage.data
  let hasOpaquePixel = false

  for (let localY = 0; localY < rect.height; localY += 1) {
    for (let localX = 0; localX < rect.width; localX += 1) {
      const globalX = rect.x + localX
      const globalY = rect.y + localY
      const sourceIndex = localY * rect.width + localX
      const globalIndex = globalY * region.width + globalX
      if (region.mask[globalIndex] !== 1) {
        continue
      }

      const offset = sourceIndex * 4
      floatingPixels[offset] = sourcePixels[offset]
      floatingPixels[offset + 1] = sourcePixels[offset + 1]
      floatingPixels[offset + 2] = sourcePixels[offset + 2]
      floatingPixels[offset + 3] = sourcePixels[offset + 3]
      sourcePixels[offset] = 0
      sourcePixels[offset + 1] = 0
      sourcePixels[offset + 2] = 0
      sourcePixels[offset + 3] = 0
      hasOpaquePixel = hasOpaquePixel || floatingPixels[offset + 3] > 8
    }
  }

  if (!hasOpaquePixel) {
    return false
  }

  floatingContext.putImageData(floatingImage, 0, 0)
  context.putImageData(imageData, rect.x, rect.y)
  resetLayerStrokeHistoryFromCurrent(layer.id)
  setFloatingSelection(floating, rect, 'rect', [])
  renderComposite()
  refreshLayerThumbnail(layer.id)
  return true
}

function trySelectObjectAtPoint(point: Point) {
  const strokeMatch = findRecordedStrokeMatchAtPoint(point)
  if (strokeMatch && captureRecordedStrokeSelection(strokeMatch)) {
    return true
  }

  const region = collectRasterStrokeRegionAtPoint(point)
  if (region && captureRasterRegionSelection(region)) {
    return true
  }

  return false
}

function drawHoverBounds(
  preview: CanvasRenderingContext2D,
  bounds: { minX: number; minY: number; maxX: number; maxY: number },
  padding = 1.5
) {
  const x = Math.floor(bounds.minX - padding) + 0.5
  const y = Math.floor(bounds.minY - padding) + 0.5
  const width = Math.max(1, Math.ceil(bounds.maxX - bounds.minX + padding * 2))
  const height = Math.max(1, Math.ceil(bounds.maxY - bounds.minY + padding * 2))

  preview.save()
  preview.globalCompositeOperation = 'source-over'
  preview.shadowColor = 'rgba(56, 189, 248, 0.28)'
  preview.shadowBlur = 8
  preview.strokeStyle = 'rgba(56, 189, 248, 0.65)'
  preview.lineWidth = 1
  preview.strokeRect(x, y, width, height)
  preview.shadowBlur = 0
  preview.strokeStyle = 'rgba(255,255,255,0.75)'
  preview.lineWidth = 1
  preview.setLineDash([4, 3])
  preview.strokeRect(x, y, width, height)
  preview.restore()
}

function drawStrokeHoverPreview(stroke: BrushStrokeRecord) {
  const preview = getPreviewContext()
  if (!preview) {
    return
  }

  clearPreviewCanvas()
  preview.save()
  preview.globalCompositeOperation = 'source-over'
  preview.globalAlpha = 0.82
  replayBrushStroke(preview, {
    ...stroke,
    config: {
      ...stroke.config,
      color: '#38bdf8',
      opacity: 74,
      style: {
        ...stroke.config.style,
        flow: 82,
        hardness: Math.max(stroke.config.style.hardness, 88),
        sizeMode: 'fixed',
        sizeJitter: 0
      },
      pressureEnabled: false
    }
  })
  preview.restore()
  drawHoverBounds(preview, stroke.bounds)
}

function drawRasterStrokeHoverPreview(region: NonNullable<ReturnType<typeof collectRasterStrokeRegionAtPoint>>) {
  const preview = getPreviewContext()
  if (!preview) {
    return
  }

  clearPreviewCanvas()

  const { width, mask, bounds } = region
  const previewImage = preview.createImageData(width, region.height)
  for (let pixelIndex = 0; pixelIndex < mask.length; pixelIndex += 1) {
    if (mask[pixelIndex] !== 1) {
      continue
    }

    const offset = pixelIndex * 4
    previewImage.data[offset] = 56
    previewImage.data[offset + 1] = 189
    previewImage.data[offset + 2] = 248
    previewImage.data[offset + 3] = 132
  }

  preview.putImageData(previewImage, 0, 0)
  drawHoverBounds(preview, bounds, 1)
}

function updateStrokeHoverPreview(point: Point | null) {
  if (!point || drawState.drawing || drawState.selectingBox || drawState.lassoSelecting || drawState.movingSelection || drawState.panning) {
    if (hoverStrokePreviewId.value) {
      hoverStrokePreviewId.value = null
      clearPreviewCanvas()
    }
    return
  }

  if (activeTool.value !== 'eraser' || eraserMode.value !== 'stroke') {
    if (hoverStrokePreviewId.value) {
      hoverStrokePreviewId.value = null
      clearPreviewCanvas()
    }
    return
  }

  const match = findRecordedStrokeMatchAtPoint(point)
  if (!match) {
    if (hoverStrokePreviewId.value) {
      hoverStrokePreviewId.value = null
      clearPreviewCanvas()
    }
    return
  }

  if (hasLaterEraserAffectingStroke(match.history, match.index, match.stroke)) {
    const region = collectRasterStrokeRegionAtPoint(point)
    if (!region) {
      if (hoverStrokePreviewId.value) {
        hoverStrokePreviewId.value = null
        clearPreviewCanvas()
      }
      return
    }

    const regionKey = `${match.stroke.id}:${region.bounds.minX}:${region.bounds.minY}:${region.bounds.maxX}:${region.bounds.maxY}`
    if (hoverStrokePreviewId.value === regionKey) {
      return
    }

    hoverStrokePreviewId.value = regionKey
    drawRasterStrokeHoverPreview(region)
    return
  }

  if (hoverStrokePreviewId.value === match.stroke.id) {
    return
  }

  hoverStrokePreviewId.value = match.stroke.id
  drawStrokeHoverPreview(match.stroke)
}

function eraseRecordedStrokeAtPoint(point: Point) {
  const layer = activeLayer.value
  const match = findRecordedStrokeMatchAtPoint(point)
  if (!layer || !match) {
    return false
  }

  if (hasLaterEraserAffectingStroke(match.history, match.index, match.stroke)) {
    return false
  }

  removeStrokeFromHistory(match.history, match.index)
  hoverStrokePreviewId.value = null
  clearPreviewCanvas()
  return rebuildLayerFromStrokeHistory(layer.id)
}

function drawShape(context: CanvasRenderingContext2D, start: Point, end: Point, shape: ShapeType) {
  context.save()
  context.globalCompositeOperation = 'source-over'
  context.globalAlpha = brushOpacity.value / 100
  context.strokeStyle = brushColor.value
  context.lineWidth = Math.max(1, brushSize.value)
  context.lineCap = 'round'
  context.lineJoin = 'round'

  if (shape === 'line') {
    context.beginPath()
    context.moveTo(start.x, start.y)
    context.lineTo(end.x, end.y)
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'curve') {
    const controlX = (start.x + end.x) / 2
    const controlY = Math.min(start.y, end.y) - Math.abs(end.x - start.x) * 0.35
    context.beginPath()
    context.moveTo(start.x, start.y)
    context.quadraticCurveTo(controlX, controlY, end.x, end.y)
    context.stroke()
    context.restore()
    return
  }

  const x = Math.min(start.x, end.x)
  const y = Math.min(start.y, end.y)
  const width = Math.max(2, Math.abs(end.x - start.x))
  const height = Math.max(2, Math.abs(end.y - start.y))
  const centerX = x + width / 2
  const centerY = y + height / 2
  const radius = Math.min(width, height) / 2

  if (shape === 'rectangle') {
    context.strokeRect(x, y, width, height)
    context.restore()
    return
  }

  if (shape === 'rounded-rectangle') {
    const radiusX = Math.min(width * 0.18, 28)
    const radiusY = Math.min(height * 0.18, 28)
    context.beginPath()
    context.moveTo(x + radiusX, y)
    context.lineTo(x + width - radiusX, y)
    context.quadraticCurveTo(x + width, y, x + width, y + radiusY)
    context.lineTo(x + width, y + height - radiusY)
    context.quadraticCurveTo(x + width, y + height, x + width - radiusX, y + height)
    context.lineTo(x + radiusX, y + height)
    context.quadraticCurveTo(x, y + height, x, y + height - radiusY)
    context.lineTo(x, y + radiusY)
    context.quadraticCurveTo(x, y, x + radiusX, y)
    context.closePath()
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'ellipse') {
    context.beginPath()
    context.ellipse(centerX, centerY, width / 2, height / 2, 0, 0, Math.PI * 2)
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'triangle') {
    context.beginPath()
    context.moveTo(centerX, y)
    context.lineTo(x + width, y + height)
    context.lineTo(x, y + height)
    context.closePath()
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'diamond') {
    context.beginPath()
    context.moveTo(centerX, y)
    context.lineTo(x + width, centerY)
    context.lineTo(centerX, y + height)
    context.lineTo(x, centerY)
    context.closePath()
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'pentagon') {
    drawRegularPolygon(context, centerX, centerY, radius, 5)
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'hexagon') {
    drawRegularPolygon(context, centerX, centerY, radius, 6)
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'right-arrow') {
    drawArrowShape(context, x, y, width, height, 'right')
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'left-arrow') {
    drawArrowShape(context, x, y, width, height, 'left')
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'up-arrow') {
    drawArrowShape(context, x, y, width, height, 'up')
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'down-arrow') {
    drawArrowShape(context, x, y, width, height, 'down')
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'star4') {
    drawStar(context, centerX, centerY, radius, radius * 0.42, 4)
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'star5') {
    drawStar(context, centerX, centerY, radius, radius * 0.46, 5)
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'chat-bubble') {
    const roundRadius = Math.min(width * 0.15, 18)
    context.beginPath()
    context.moveTo(x + roundRadius, y)
    context.lineTo(x + width - roundRadius, y)
    context.quadraticCurveTo(x + width, y, x + width, y + roundRadius)
    context.lineTo(x + width, y + height - roundRadius)
    context.quadraticCurveTo(x + width, y + height, x + width - roundRadius, y + height)
    context.lineTo(x + width * 0.56, y + height)
    context.lineTo(x + width * 0.42, y + height + Math.max(8, height * 0.2))
    context.lineTo(x + width * 0.42, y + height)
    context.lineTo(x + roundRadius, y + height)
    context.quadraticCurveTo(x, y + height, x, y + height - roundRadius)
    context.lineTo(x, y + roundRadius)
    context.quadraticCurveTo(x, y, x + roundRadius, y)
    context.closePath()
    context.stroke()
    context.restore()
    return
  }

  if (shape === 'heart') {
    drawHeartPath(context, x, y, width, height)
    context.stroke()
    context.restore()
    return
  }

  context.strokeRect(x, y, width, height)
  context.restore()
}

function drawShapePreview(start: Point, end: Point) {
  const context = getPreviewContext()
  if (!context) {
    return
  }

  context.clearRect(0, 0, canvasWidth.value, canvasHeight.value)
  drawShape(context, start, end, shapeType.value)
}

function commitShape(start: Point, end: Point) {
  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return
  }

  const context = getLayerContext(layer.id)
  if (!context) {
    return
  }

  drawShape(context, start, end, shapeType.value)
  resetLayerStrokeHistoryFromCurrent(layer.id)
}

function rgbToHex(r: number, g: number, b: number) {
  const values = [r, g, b].map((value) => clamp(Math.round(value), 0, 255).toString(16).padStart(2, '0'))
  return `#${values.join('')}`
}

function pickColor(point: Point) {
  renderComposite()
  const context = getCompositeContext()
  if (!context) {
    return
  }

  const x = clamp(Math.floor(point.x), 0, canvasWidth.value - 1)
  const y = clamp(Math.floor(point.y), 0, canvasHeight.value - 1)
  const data = context.getImageData(x, y, 1, 1).data
  if (!data || data.length < 3) {
    return
  }

  brushColor.value = rgbToHex(data[0], data[1], data[2])
  activeTool.value = lastPaintTool.value
}

function hexToRgba(hex: string, alpha = 255): [number, number, number, number] {
  const normalized = hex.replace('#', '').trim()
  if (normalized.length !== 6) {
    return [0, 0, 0, alpha]
  }

  const r = Number.parseInt(normalized.slice(0, 2), 16)
  const g = Number.parseInt(normalized.slice(2, 4), 16)
  const b = Number.parseInt(normalized.slice(4, 6), 16)
  return [r, g, b, alpha]
}

function floodFill(point: Point) {
  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return false
  }

  const context = getLayerContext(layer.id)
  const raster = getLayerRaster(layer.id)
  if (!context || !raster) {
    return false
  }

  const width = raster.width
  const height = raster.height
  const startX = clamp(Math.floor(point.x), 0, width - 1)
  const startY = clamp(Math.floor(point.y), 0, height - 1)
  const imageData = context.getImageData(0, 0, width, height)
  const data = imageData.data

  const startIndex = (startY * width + startX) * 4
  const targetR = data[startIndex]
  const targetG = data[startIndex + 1]
  const targetB = data[startIndex + 2]
  const targetA = data[startIndex + 3]

  const fillAlpha = Math.round((brushOpacity.value / 100) * 255)
  const [fillR, fillG, fillB, fillA] = hexToRgba(brushColor.value, fillAlpha)

  if (targetR === fillR && targetG === fillG && targetB === fillB && targetA === fillA) {
    return false
  }

  const tolerance = 34
  const toleranceSquared = tolerance * tolerance
  const targetSeed: [number, number, number] = [targetR, targetG, targetB]
  const visited = new Uint8Array(width * height)
  const stack: number[] = [startY * width + startX]
  visited[startY * width + startX] = 1

  let changed = false
  while (stack.length > 0) {
    const pixelIndex = stack.pop()
    if (pixelIndex == null) {
      continue
    }

    const offset = pixelIndex * 4
    const alpha = data[offset + 3]
    if (alpha === 0 && targetA !== 0) {
      continue
    }

    const distance = colorDistanceSquared(data, offset, targetSeed)
    if (distance > toleranceSquared || Math.abs(alpha - targetA) > 80) {
      continue
    }

    data[offset] = fillR
    data[offset + 1] = fillG
    data[offset + 2] = fillB
    data[offset + 3] = fillA
    changed = true

    const x = pixelIndex % width
    const y = Math.floor(pixelIndex / width)
    const neighbors = [
      y > 0 ? pixelIndex - width : -1,
      y < height - 1 ? pixelIndex + width : -1,
      x > 0 ? pixelIndex - 1 : -1,
      x < width - 1 ? pixelIndex + 1 : -1
    ]

    for (const nextIndex of neighbors) {
      if (nextIndex < 0 || visited[nextIndex] === 1) {
        continue
      }
      visited[nextIndex] = 1
      stack.push(nextIndex)
    }
  }

  if (!changed) {
    return false
  }

  context.putImageData(imageData, 0, 0)
  resetLayerStrokeHistoryFromCurrent(layer.id)
  return true
}

async function ensureTextFontReady(family: string, weight: string, size: number) {
  if (typeof document === 'undefined' || typeof document.fonts?.load !== 'function') {
    return
  }

  try {
    await document.fonts.load(`${weight} ${size}px "${family}"`)
  } catch {
    // ignore font loading failures and keep fallback fonts available
  }
}

function normalizeTextRect(rect: Rect) {
  const width = clamp(Math.round(rect.width), 120, canvasWidth.value)
  const height = clamp(Math.round(rect.height), 56, canvasHeight.value)
  const x = clamp(Math.round(rect.x), 0, Math.max(0, canvasWidth.value - width))
  const y = clamp(Math.round(rect.y), 0, Math.max(0, canvasHeight.value - height))

  return { x, y, width, height }
}

function focusTextEditor() {
  nextTick(() => {
    const input = textEditorInputRef.value
    if (!input) {
      return
    }

    input.focus()
    input.select()
  })
}

function getTextCanvasFont(style: TextStyleSnapshot) {
  const weight = style.bold ? '700' : '400'
  const italic = style.italic ? 'italic' : 'normal'
  const size = clamp(Math.round(style.size), 8, 360)
  const family = style.fontFamily || 'MiSans'

  return {
    weight,
    italic,
    size,
    family,
    font: `${italic} ${weight} ${size}px "${family}", "Noto Sans SC", "Microsoft YaHei", sans-serif`
  }
}

function getTextLineHeightPx(style: TextStyleSnapshot) {
  return Math.max(12, Math.round(clamp(Number(style.size), 8, 360) * clamp(Number(style.lineHeight ?? 1.35), 1, 3)))
}

function measureTextLine(context: CanvasRenderingContext2D, text: string, letterSpacing: number) {
  if (!text) {
    return 0
  }

  if (letterSpacing === 0 || text.length <= 1) {
    return context.measureText(text).width
  }

  let width = 0
  for (let index = 0; index < text.length; index += 1) {
    width += context.measureText(text[index] ?? '').width
    if (index < text.length - 1) {
      width += letterSpacing
    }
  }
  return width
}

function drawTextLine(context: CanvasRenderingContext2D, text: string, startX: number, startY: number, letterSpacing: number) {
  if (!text) {
    return
  }

  if (letterSpacing === 0 || text.length <= 1) {
    context.fillText(text, startX, startY)
    return
  }

  let cursorX = startX
  for (let index = 0; index < text.length; index += 1) {
    const char = text[index] ?? ''
    context.fillText(char, cursorX, startY)
    cursorX += context.measureText(char).width
    if (index < text.length - 1) {
      cursorX += letterSpacing
    }
  }
}

function getTextLineStartX(rect: Rect, paddingX: number, availableWidth: number, lineWidth: number, align: TextAlignMode) {
  if (align === 'center') {
    return rect.x + paddingX + Math.max(0, (availableWidth - lineWidth) / 2)
  }

  if (align === 'right') {
    return rect.x + paddingX + Math.max(0, availableWidth - lineWidth)
  }

  return rect.x + paddingX
}

function renderTextElement(context: CanvasRenderingContext2D, element: TextElementModel, alpha = 1) {
  const content = element.text.trim()
  if (!content) {
    return
  }

  const rect = normalizeTextRect(element)
  const style = cloneTextStyleSnapshot(element.style)
  const { weight, size, family, font } = getTextCanvasFont(style)
  const lineHeight = getTextLineHeightPx(style)
  const paddingX = Math.max(6, Math.round(size * 0.25))
  const paddingY = Math.max(4, Math.round(size * 0.2))
  const textWidth = Math.max(20, rect.width - paddingX * 2)
  const letterSpacing = clamp(style.letterSpacing, -8, 40)

  void ensureTextFontReady(family, weight, size)

  context.save()
  context.globalCompositeOperation = 'source-over'
  context.globalAlpha = clamp(alpha, 0, 1)
  context.fillStyle = style.color
  context.textBaseline = 'top'
  context.font = font
  context.beginPath()
  context.rect(rect.x, rect.y, rect.width, rect.height)
  context.clip()

  const lines = getWrappedTextLines(context, content, textWidth, letterSpacing)
  let cursorY = rect.y + paddingY
  for (const line of lines) {
    if (cursorY + lineHeight > rect.y + rect.height) {
      break
    }

    const lineWidth = measureTextLine(context, line || ' ', letterSpacing)
    const startX = getTextLineStartX(rect, paddingX, textWidth, lineWidth, style.align)
    drawTextLine(context, line || ' ', startX, cursorY, letterSpacing)
    cursorY += lineHeight
  }
  context.restore()
}

function renderLayerTextElements(context: CanvasRenderingContext2D, layerId: string, alpha = 1) {
  for (const element of getLayerTextElements(layerId)) {
    if (textEditor.active && textEditor.mode === 'edit' && textEditor.layerId === layerId && textEditor.textId === element.id) {
      continue
    }
    renderTextElement(context, element, alpha)
  }
}

function openTextEditor(rect: Rect, content = '', options?: { layerId?: string | null; textId?: string | null; style?: TextStyleSnapshot; mode?: TextEditorMode }) {
  const nextRect = normalizeTextRect(rect)
  const style = options?.style ? cloneTextStyleSnapshot(options.style) : captureCurrentTextStyle()
  applyTextStyleSnapshot(style)
  textEditor.active = true
  textEditor.layerId = options?.layerId ?? activeLayerId.value
  textEditor.textId = options?.textId ?? null
  textEditor.mode = options?.mode ?? (options?.textId ? 'edit' : 'create')
  textEditor.interaction = 'idle'
  textEditor.x = nextRect.x
  textEditor.y = nextRect.y
  textEditor.width = nextRect.width
  textEditor.height = nextRect.height
  textEditor.text = content
  textEditor.pointerId = null
  clearPreviewCanvas()
  renderComposite()
  focusTextEditor()
}

function startTextEditorMove(event: PointerEvent) {
  if (!textEditor.active) {
    return
  }

  textEditor.interaction = 'move'
  textEditor.pointerId = event.pointerId
  textEditor.anchorX = event.clientX
  textEditor.anchorY = event.clientY
  textEditor.startX = textEditor.x
  textEditor.startY = textEditor.y
}

function startTextEditorResize(handle: TextResizeHandle, event: PointerEvent) {
  if (!textEditor.active) {
    return
  }

  textEditor.interaction = 'resize'
  textEditor.pointerId = event.pointerId
  textEditor.resizeHandle = handle
  textEditor.anchorX = event.clientX
  textEditor.anchorY = event.clientY
  textEditor.startX = textEditor.x
  textEditor.startY = textEditor.y
  textEditor.startWidth = textEditor.width
  textEditor.startHeight = textEditor.height
}

function handleTextEditorPointerMove(event: PointerEvent) {
  if (!textEditor.active || textEditor.pointerId !== event.pointerId) {
    return
  }

  const deltaX = event.clientX - textEditor.anchorX
  const deltaY = event.clientY - textEditor.anchorY

  if (textEditor.interaction === 'move') {
    const nextX = clamp(Math.round(textEditor.startX + deltaX), 0, Math.max(0, canvasWidth.value - textEditor.width))
    const nextY = clamp(Math.round(textEditor.startY + deltaY), 0, Math.max(0, canvasHeight.value - textEditor.height))
    textEditor.x = nextX
    textEditor.y = nextY
    return
  }

  if (textEditor.interaction === 'resize') {
    const minWidth = 120
    const minHeight = 56
    const startLeft = textEditor.startX
    const startTop = textEditor.startY
    const startRight = textEditor.startX + textEditor.startWidth
    const startBottom = textEditor.startY + textEditor.startHeight
    let nextLeft = startLeft
    let nextTop = startTop
    let nextRight = startRight
    let nextBottom = startBottom

    if (textEditor.resizeHandle.includes('w')) {
      nextLeft = clamp(Math.round(startLeft + deltaX), 0, startRight - minWidth)
    }
    if (textEditor.resizeHandle.includes('e')) {
      nextRight = clamp(Math.round(startRight + deltaX), startLeft + minWidth, canvasWidth.value)
    }
    if (textEditor.resizeHandle.includes('n')) {
      nextTop = clamp(Math.round(startTop + deltaY), 0, startBottom - minHeight)
    }
    if (textEditor.resizeHandle.includes('s')) {
      nextBottom = clamp(Math.round(startBottom + deltaY), startTop + minHeight, canvasHeight.value)
    }

    textEditor.x = nextLeft
    textEditor.y = nextTop
    textEditor.width = nextRight - nextLeft
    textEditor.height = nextBottom - nextTop
  }
}

function stopTextEditorInteraction(event: PointerEvent) {
  if (textEditor.pointerId !== event.pointerId) {
    return
  }

  textEditor.pointerId = null
  textEditor.interaction = 'idle'
  textEditor.resizeHandle = 'se'
  focusTextEditor()
}

function cancelTextEditor() {
  const shouldRefresh = textEditor.active && textEditor.mode === 'edit'
  textEditor.active = false
  textEditor.layerId = null
  textEditor.textId = null
  textEditor.mode = 'create'
  textEditor.interaction = 'idle'
  textEditor.text = ''
  textEditor.pointerId = null
  textEditor.resizeHandle = 'se'
  if (shouldRefresh) {
    renderComposite()
  }
}

function findTextElementAtPoint(point: Point, layerId: string) {
  const items = getLayerTextElements(layerId)
  for (let index = items.length - 1; index >= 0; index -= 1) {
    const item = items[index]
    if (!item) {
      continue
    }

    const rect = normalizeTextRect(item)
    if (point.x >= rect.x && point.x <= rect.x + rect.width && point.y >= rect.y && point.y <= rect.y + rect.height) {
      return item
    }
  }

  return null
}

function findTopEditableTextHit(point: Point) {
  for (let index = layers.value.length - 1; index >= 0; index -= 1) {
    const layer = layers.value[index]
    if (!layer || !layer.visible || layer.locked) {
      continue
    }

    const textElement = findTextElementAtPoint(point, layer.id)
    if (textElement) {
      return { layer, textElement }
    }
  }

  return null
}

function wrapTextLine(context: CanvasRenderingContext2D, text: string, maxWidth: number, letterSpacing = 0) {
  if (!text) {
    return ['']
  }

  const lines: string[] = []
  let current = ''

  for (const char of Array.from(text)) {
    const next = `${current}${char}`
    if (current && measureTextLine(context, next, letterSpacing) > maxWidth) {
      lines.push(current)
      current = char
      continue
    }

    current = next
  }

  lines.push(current)
  return lines
}

function getWrappedTextLines(context: CanvasRenderingContext2D, content: string, maxWidth: number, letterSpacing = 0) {
  const paragraphs = content.replace(/\r\n/g, '\n').split('\n')
  const lines: string[] = []

  for (const paragraph of paragraphs) {
    lines.push(...wrapTextLine(context, paragraph, maxWidth, letterSpacing))
  }

  return lines
}

function drawTextBoxPreview(rect: Rect) {
  const preview = getPreviewContext()
  if (!preview) {
    return
  }

  clearPreviewCanvas()
  preview.save()
  preview.setLineDash([8, 6])
  preview.lineWidth = 1
  preview.strokeStyle = 'rgba(96, 165, 250, 0.95)'
  preview.fillStyle = 'rgba(96, 165, 250, 0.12)'
  preview.fillRect(rect.x + 0.5, rect.y + 0.5, rect.width, rect.height)
  preview.strokeRect(rect.x + 0.5, rect.y + 0.5, rect.width, rect.height)
  preview.restore()
}

function finalizeTextEditor(pushSnapshot = true) {
  if (!textEditor.active) {
    return false
  }

  const content = textEditor.text.trim()
  if (!content) {
    cancelTextEditor()
    return false
  }

  const layerId = textEditor.layerId ?? activeLayerId.value
  const layer = layerId ? layers.value.find((item) => item.id === layerId) ?? null : null
  if (!layer || layer.locked) {
    cancelTextEditor()
    return false
  }

  const items = getLayerTextElements(layer.id)
  const style = captureCurrentTextStyle()
  const rect = normalizeTextRect({ x: textEditor.x, y: textEditor.y, width: textEditor.width, height: textEditor.height })

  if (textEditor.mode === 'edit' && textEditor.textId) {
    const current = items.find((item) => item.id === textEditor.textId)
    if (current) {
      current.x = rect.x
      current.y = rect.y
      current.width = rect.width
      current.height = rect.height
      current.text = textEditor.text
      current.style = style
    }
  } else {
    items.push({
      id: createId(),
      x: rect.x,
      y: rect.y,
      width: rect.width,
      height: rect.height,
      text: textEditor.text,
      style
    })
  }

  cancelTextEditor()

  renderComposite()
  refreshLayerThumbnail(layer.id)
  if (pushSnapshot) {
    pushHistorySnapshot()
  }
  return true
}

function applyTextEditor() {
  finalizeTextEditor(true)
}

function buildRectFromPoints(startX: number, startY: number, endX: number, endY: number) {
  const left = Math.floor(Math.min(startX, endX))
  const top = Math.floor(Math.min(startY, endY))
  const right = Math.ceil(Math.max(startX, endX))
  const bottom = Math.ceil(Math.max(startY, endY))

  const x = clamp(left, 0, canvasWidth.value)
  const y = clamp(top, 0, canvasHeight.value)
  const maxRight = clamp(right, 0, canvasWidth.value)
  const maxBottom = clamp(bottom, 0, canvasHeight.value)

  return {
    x,
    y,
    width: Math.max(0, maxRight - x),
    height: Math.max(0, maxBottom - y)
  }
}

function clearFloatingSelection() {
  selectionState.active = false
  selectionState.kind = 'rect'
  selectionState.x = 0
  selectionState.y = 0
  selectionState.width = 0
  selectionState.height = 0
  selectionState.lassoPath = []
  selectionState.offsetX = 0
  selectionState.offsetY = 0
  selectionState.moveStartX = 0
  selectionState.moveStartY = 0
  selectionState.moveBaseOffsetX = 0
  selectionState.moveBaseOffsetY = 0
  selectionState.boxStartX = 0
  selectionState.boxStartY = 0
  selectionState.boxEndX = 0
  selectionState.boxEndY = 0
  selectionRaster = null
}

function drawSelectionBoxPreview(rect: { x: number; y: number; width: number; height: number }) {
  const preview = getPreviewContext()
  if (!preview) {
    return
  }

  preview.clearRect(0, 0, canvasWidth.value, canvasHeight.value)
  if (rect.width <= 1 || rect.height <= 1) {
    return
  }

  preview.save()
  preview.setLineDash([7, 5])
  preview.lineWidth = 1
  preview.strokeStyle = 'rgba(255, 255, 255, 0.95)'
  preview.strokeRect(rect.x + 0.5, rect.y + 0.5, rect.width - 1, rect.height - 1)
  preview.setLineDash([7, 5])
  preview.lineDashOffset = 6
  preview.strokeStyle = 'rgba(0, 0, 0, 0.7)'
  preview.strokeRect(rect.x + 0.5, rect.y + 0.5, rect.width - 1, rect.height - 1)
  preview.restore()
}

function drawLassoPreview(points: Point[], closePath = false) {
  const preview = getPreviewContext()
  if (!preview) {
    return
  }

  preview.clearRect(0, 0, canvasWidth.value, canvasHeight.value)
  if (points.length < 2) {
    return
  }

  preview.save()
  preview.setLineDash([7, 5])
  preview.lineWidth = 1
  preview.strokeStyle = 'rgba(255, 255, 255, 0.95)'
  preview.beginPath()
  preview.moveTo(points[0]!.x, points[0]!.y)
  for (let index = 1; index < points.length; index += 1) {
    preview.lineTo(points[index]!.x, points[index]!.y)
  }
  if (closePath && points.length >= 3) {
    preview.closePath()
  }
  preview.stroke()
  preview.setLineDash([7, 5])
  preview.lineDashOffset = 6
  preview.strokeStyle = 'rgba(0, 0, 0, 0.7)'
  preview.stroke()
  preview.restore()
}

function setFloatingSelection(
  raster: HTMLCanvasElement,
  rect: { x: number; y: number; width: number; height: number },
  kind: SelectionKind = 'rect',
  lassoPath: Point[] = []
) {
  selectionRaster = raster
  selectionState.active = true
  selectionState.kind = kind
  selectionState.x = rect.x
  selectionState.y = rect.y
  selectionState.width = rect.width
  selectionState.height = rect.height
  selectionState.lassoPath = lassoPath
  selectionState.offsetX = 0
  selectionState.offsetY = 0
}

function getFloatingSelectionRect() {
  return {
    x: selectionState.x + selectionState.offsetX,
    y: selectionState.y + selectionState.offsetY,
    width: selectionState.width,
    height: selectionState.height
  }
}

function isPointInFloatingSelection(point: Point) {
  if (!hasFloatingSelection.value || !selectionRaster) {
    return false
  }

  const rect = getFloatingSelectionRect()
  if (
    point.x < rect.x ||
    point.y < rect.y ||
    point.x > rect.x + rect.width ||
    point.y > rect.y + rect.height
  ) {
    return false
  }

  if (selectionState.kind === 'rect') {
    return true
  }

  const localX = Math.floor(point.x - rect.x)
  const localY = Math.floor(point.y - rect.y)
  if (localX < 0 || localY < 0 || localX >= selectionRaster.width || localY >= selectionRaster.height) {
    return false
  }

  const rasterContext = getCanvas2DContext(selectionRaster, true)
  if (!rasterContext) {
    return false
  }

  const pixel = rasterContext.getImageData(localX, localY, 1, 1).data
  return pixel[3] > 8
}

function drawFloatingSelectionOverlay(context: CanvasRenderingContext2D) {
  if (!hasFloatingSelection.value || !selectionRaster) {
    return
  }

  const rect = getFloatingSelectionRect()
  context.save()
  context.globalCompositeOperation = 'source-over'
  context.globalAlpha = 1
  context.drawImage(selectionRaster, rect.x, rect.y)

  const drawOverlayPath = () => {
    if (selectionState.kind === 'lasso' && selectionState.lassoPath.length >= 3) {
      context.beginPath()
      const first = selectionState.lassoPath[0]!
      context.moveTo(rect.x + first.x, rect.y + first.y)
      for (let index = 1; index < selectionState.lassoPath.length; index += 1) {
        const point = selectionState.lassoPath[index]!
        context.lineTo(rect.x + point.x, rect.y + point.y)
      }
      context.closePath()
      return
    }

    context.beginPath()
    context.rect(rect.x + 0.5, rect.y + 0.5, rect.width - 1, rect.height - 1)
  }

  context.setLineDash([7, 5])
  context.lineWidth = 1
  context.strokeStyle = 'rgba(255, 255, 255, 0.95)'
  drawOverlayPath()
  context.stroke()
  context.setLineDash([7, 5])
  context.lineDashOffset = 6
  context.strokeStyle = 'rgba(0, 0, 0, 0.7)'
  drawOverlayPath()
  context.stroke()
  context.restore()
}

function commitFloatingSelection(pushSnapshot = true) {
  if (!hasFloatingSelection.value || !selectionRaster) {
    return false
  }

  const layer = activeLayer.value
  if (!layer || layer.locked) {
    clearFloatingSelection()
    renderComposite()
    return false
  }

  const context = getLayerContext(layer.id)
  if (!context) {
    clearFloatingSelection()
    renderComposite()
    return false
  }

  const rect = getFloatingSelectionRect()
  context.save()
  context.globalCompositeOperation = 'source-over'
  context.globalAlpha = 1
  context.drawImage(selectionRaster, Math.round(rect.x), Math.round(rect.y))
  context.restore()
  resetLayerStrokeHistoryFromCurrent(layer.id)

  clearFloatingSelection()
  clearPreviewCanvas()
  renderComposite()
  refreshLayerThumbnail(layer.id)
  if (pushSnapshot) {
    pushHistorySnapshot()
  }
  return true
}

function clearFloatingSelectionAndRender() {
  if (hasFloatingSelection.value && selectionRaster) {
    const layer = activeLayer.value
    const context = layer ? getLayerContext(layer.id) : null
    if (layer && context && !layer.locked) {
      context.save()
      context.globalCompositeOperation = 'source-over'
      context.globalAlpha = 1
      context.drawImage(selectionRaster, Math.round(selectionState.x), Math.round(selectionState.y))
      context.restore()
      resetLayerStrokeHistoryFromCurrent(layer.id)
      refreshLayerThumbnail(layer.id)
      pushHistorySnapshot()
    }
  }

  clearFloatingSelection()
  clearPreviewCanvas()
  renderComposite()
}

function finalizeFloatingSelection() {
  finalizeTextEditor(true)

  if (!hasFloatingSelection.value) {
    return
  }

  commitFloatingSelection(true)
}

function captureFloatingSelection(rect: { x: number; y: number; width: number; height: number }) {
  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return false
  }

  const context = getLayerContext(layer.id)
  if (!context) {
    return false
  }

  if (rect.width <= 1 || rect.height <= 1) {
    return false
  }

  const imageData = context.getImageData(rect.x, rect.y, rect.width, rect.height)
  const pixels = imageData.data
  let hasOpaquePixel = false
  for (let index = 3; index < pixels.length; index += 4) {
    if (pixels[index] > 8) {
      hasOpaquePixel = true
      break
    }
  }

  if (!hasOpaquePixel) {
    return false
  }

  const floating = document.createElement('canvas')
  floating.width = rect.width
  floating.height = rect.height
  const floatingContext = getCanvas2DContext(floating)
  if (!floatingContext) {
    return false
  }

  floatingContext.putImageData(imageData, 0, 0)
  context.clearRect(rect.x, rect.y, rect.width, rect.height)
  resetLayerStrokeHistoryFromCurrent(layer.id)
  setFloatingSelection(floating, rect, 'rect', [])

  renderComposite()
  return true
}

function updateSelectionBox(point: Point) {
  selectionState.boxEndX = point.x
  selectionState.boxEndY = point.y
  drawSelectionBoxPreview(buildRectFromPoints(selectionState.boxStartX, selectionState.boxStartY, point.x, point.y))
}

function finalizeSelectionBox() {
  const rect = buildRectFromPoints(
    selectionState.boxStartX,
    selectionState.boxStartY,
    selectionState.boxEndX,
    selectionState.boxEndY
  )

  drawState.selectingBox = false
  clearPreviewCanvas()

  if (rect.width <= 1 || rect.height <= 1) {
    return false
  }

  return captureFloatingSelection(rect)
}

function finalizeLassoSelection(points: Point[]) {
  const layer = activeLayer.value
  if (!layer || layer.locked || points.length < 3) {
    return false
  }

  const context = getLayerContext(layer.id)
  if (!context) {
    return false
  }

  const closedPoints = [...points]
  const firstPoint = closedPoints[0]!
  const lastPoint = closedPoints[closedPoints.length - 1]!
  if (Math.hypot(firstPoint.x - lastPoint.x, firstPoint.y - lastPoint.y) > 2) {
    closedPoints.push({ x: firstPoint.x, y: firstPoint.y })
  }

  const minX = closedPoints.reduce((acc, point) => Math.min(acc, point.x), closedPoints[0]!.x)
  const minY = closedPoints.reduce((acc, point) => Math.min(acc, point.y), closedPoints[0]!.y)
  const maxX = closedPoints.reduce((acc, point) => Math.max(acc, point.x), closedPoints[0]!.x)
  const maxY = closedPoints.reduce((acc, point) => Math.max(acc, point.y), closedPoints[0]!.y)
  const rect = buildRectFromPoints(minX, minY, maxX, maxY)
  if (rect.width <= 1 || rect.height <= 1) {
    return false
  }

  const sourceImage = context.getImageData(rect.x, rect.y, rect.width, rect.height)
  const floating = document.createElement('canvas')
  floating.width = rect.width
  floating.height = rect.height
  const floatingContext = getCanvas2DContext(floating)
  if (!floatingContext) {
    return false
  }

  const maskCanvas = document.createElement('canvas')
  maskCanvas.width = rect.width
  maskCanvas.height = rect.height
  const maskContext = getCanvas2DContext(maskCanvas, true)
  if (!maskContext) {
    return false
  }

  maskContext.clearRect(0, 0, rect.width, rect.height)
  maskContext.beginPath()
  maskContext.moveTo(closedPoints[0]!.x - rect.x, closedPoints[0]!.y - rect.y)
  for (let index = 1; index < closedPoints.length; index += 1) {
    maskContext.lineTo(closedPoints[index]!.x - rect.x, closedPoints[index]!.y - rect.y)
  }
  maskContext.closePath()
  maskContext.fillStyle = '#000000'
  maskContext.fill()

  const maskData = maskContext.getImageData(0, 0, rect.width, rect.height).data
  const pixels = sourceImage.data
  let hasOpaque = false

  for (let index = 0; index < pixels.length; index += 4) {
    if (maskData[index + 3] <= 0) {
      pixels[index + 3] = 0
      continue
    }

    if (pixels[index + 3] > 8) {
      hasOpaque = true
    }
  }

  if (!hasOpaque) {
    return false
  }

  floatingContext.putImageData(sourceImage, 0, 0)

  context.save()
  context.globalCompositeOperation = 'destination-out'
  context.beginPath()
  context.moveTo(closedPoints[0]!.x, closedPoints[0]!.y)
  for (let index = 1; index < closedPoints.length; index += 1) {
    context.lineTo(closedPoints[index]!.x, closedPoints[index]!.y)
  }
  context.closePath()
  context.fill()
  context.restore()
  resetLayerStrokeHistoryFromCurrent(layer.id)

  const localPath = closedPoints.map((point) => ({
    x: point.x - rect.x,
    y: point.y - rect.y
  }))

  setFloatingSelection(floating, rect, 'lasso', localPath)
  renderComposite()
  refreshLayerThumbnail(layer.id)
  return true
}

function startSelectionMove(point: Point) {
  drawState.movingSelection = true
  selectionState.moveStartX = point.x
  selectionState.moveStartY = point.y
  selectionState.moveBaseOffsetX = selectionState.offsetX
  selectionState.moveBaseOffsetY = selectionState.offsetY
}

function updateSelectionMove(point: Point) {
  const deltaX = point.x - selectionState.moveStartX
  const deltaY = point.y - selectionState.moveStartY
  selectionState.offsetX = selectionState.moveBaseOffsetX + deltaX
  selectionState.offsetY = selectionState.moveBaseOffsetY + deltaY
  renderComposite()
}

function eraseStrokeAlongPath(from: Point, to: Point) {
  const distance = Math.hypot(to.x - from.x, to.y - from.y)
  const step = Math.max(4, brushSize.value * 0.45)
  const count = Math.max(1, Math.ceil(distance / step))

  let changed = false
  for (let index = 0; index <= count; index += 1) {
    const t = count === 0 ? 1 : index / count
    const point: Point = {
      x: from.x + (to.x - from.x) * t,
      y: from.y + (to.y - from.y) * t
    }
    if (eraseStrokeAtPoint(point)) {
      changed = true
    }
  }

  return changed
}

function colorDistanceSquared(data: Uint8ClampedArray, offset: number, seed: [number, number, number]) {
  const dr = data[offset] - seed[0]
  const dg = data[offset + 1] - seed[1]
  const db = data[offset + 2] - seed[2]
  return dr * dr + dg * dg + db * db
}

function normalizePremultipliedChannel(channel: number, alpha: number) {
  if (alpha <= 0) {
    return 0
  }

  return clamp(Math.round((channel * 255) / alpha), 0, 255)
}

function colorDistanceSquaredUnpremultiplied(data: Uint8ClampedArray, offset: number, seed: [number, number, number]) {
  const alpha = data[offset + 3]
  const r = normalizePremultipliedChannel(data[offset], alpha)
  const g = normalizePremultipliedChannel(data[offset + 1], alpha)
  const b = normalizePremultipliedChannel(data[offset + 2], alpha)
  const dr = r - seed[0]
  const dg = g - seed[1]
  const db = b - seed[2]
  return dr * dr + dg * dg + db * db
}

function eraseStrokeAtPoint(point: Point) {
  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return false
  }

  if (eraseRecordedStrokeAtPoint(point)) {
    return true
  }

  const context = getLayerContext(layer.id)
  const raster = getLayerRaster(layer.id)
  if (!context || !raster) {
    return false
  }

  const width = raster.width
  const height = raster.height
  const startX = clamp(Math.floor(point.x), 0, width - 1)
  const startY = clamp(Math.floor(point.y), 0, height - 1)

  const imageData = context.getImageData(0, 0, width, height)
  const data = imageData.data
  const startIndex = startY * width + startX
  const startOffset = startIndex * 4

  if (data[startOffset + 3] <= 10) {
    return false
  }

  const seedAlpha = data[startOffset + 3]
  const seed: [number, number, number] = [
    normalizePremultipliedChannel(data[startOffset], seedAlpha),
    normalizePremultipliedChannel(data[startOffset + 1], seedAlpha),
    normalizePremultipliedChannel(data[startOffset + 2], seedAlpha)
  ]
  const toleranceSquared = 95 * 95
  const fringeToleranceSquared = 160 * 160
  const eraseMask = new Uint8Array(width * height)
  const visited = new Uint8Array(width * height)
  const stack: number[] = [startIndex]
  visited[startIndex] = 1
  let minErasedX = width
  let minErasedY = height
  let maxErasedX = -1
  let maxErasedY = -1

  let changed = false
  while (stack.length > 0) {
    const pixelIndex = stack.pop()
    if (pixelIndex == null) {
      continue
    }

    const offset = pixelIndex * 4
    const alpha = data[offset + 3]
    if (alpha <= 2 || colorDistanceSquaredUnpremultiplied(data, offset, seed) > toleranceSquared) {
      continue
    }

    eraseMask[pixelIndex] = 1
    changed = true

    const x = pixelIndex % width
    const y = Math.floor(pixelIndex / width)
    minErasedX = Math.min(minErasedX, x)
    minErasedY = Math.min(minErasedY, y)
    maxErasedX = Math.max(maxErasedX, x)
    maxErasedY = Math.max(maxErasedY, y)

    for (let deltaY = -2; deltaY <= 2; deltaY += 1) {
      const nextY = y + deltaY
      if (nextY < 0 || nextY >= height) {
        continue
      }

      for (let deltaX = -2; deltaX <= 2; deltaX += 1) {
        if ((deltaX === 0 && deltaY === 0) || deltaX * deltaX + deltaY * deltaY > 5) {
          continue
        }

        const nextX = x + deltaX
        if (nextX < 0 || nextX >= width) {
          continue
        }

        const nextIndex = nextY * width + nextX
        if (visited[nextIndex] === 1) {
          continue
        }

        visited[nextIndex] = 1
        stack.push(nextIndex)
      }
    }
  }

  if (!changed) {
    return false
  }

  const erasedPixels: number[] = []
  for (let pixelIndex = 0; pixelIndex < eraseMask.length; pixelIndex += 1) {
    if (eraseMask[pixelIndex] !== 1) {
      continue
    }

    const offset = pixelIndex * 4
    data[offset] = 0
    data[offset + 1] = 0
    data[offset + 2] = 0
    data[offset + 3] = 0
    erasedPixels.push(pixelIndex)
  }

  for (const pixelIndex of erasedPixels) {
    const x = pixelIndex % width
    const y = Math.floor(pixelIndex / width)

    for (let deltaY = -3; deltaY <= 3; deltaY += 1) {
      const nextY = y + deltaY
      if (nextY < 0 || nextY >= height) {
        continue
      }

      for (let deltaX = -3; deltaX <= 3; deltaX += 1) {
        if (deltaX * deltaX + deltaY * deltaY > 9) {
          continue
        }

        const nextX = x + deltaX
        if (nextX < 0 || nextX >= width) {
          continue
        }

        const nextIndex = nextY * width + nextX
        if (eraseMask[nextIndex] === 1) {
          continue
        }

        const offset = nextIndex * 4
        const alpha = data[offset + 3]
        if (alpha <= 0) {
          continue
        }

        const closeToSeed = colorDistanceSquaredUnpremultiplied(data, offset, seed) <= fringeToleranceSquared
        if (closeToSeed) {
          data[offset] = 0
          data[offset + 1] = 0
          data[offset + 2] = 0
          data[offset + 3] = 0
        }
      }
    }
  }

  if (maxErasedX >= minErasedX && maxErasedY >= minErasedY) {
    const sweepPadding = 6
    const sweepMinX = Math.max(0, minErasedX - sweepPadding)
    const sweepMinY = Math.max(0, minErasedY - sweepPadding)
    const sweepMaxX = Math.min(width - 1, maxErasedX + sweepPadding)
    const sweepMaxY = Math.min(height - 1, maxErasedY + sweepPadding)

    for (let y = sweepMinY; y <= sweepMaxY; y += 1) {
      for (let x = sweepMinX; x <= sweepMaxX; x += 1) {
        const pixelIndex = y * width + x
        const offset = pixelIndex * 4
        const alpha = data[offset + 3]
        if (alpha <= 0) {
          continue
        }

        if (colorDistanceSquaredUnpremultiplied(data, offset, seed) <= fringeToleranceSquared) {
          data[offset] = 0
          data[offset + 1] = 0
          data[offset + 2] = 0
          data[offset + 3] = 0
        }
      }
    }

    const sparseToleranceSquared = 190 * 190
    const sparseBridgePadding = Math.max(12, Math.round(brushSize.value * 1.8))
    let sweepBounds = {
      minX: minErasedX,
      minY: minErasedY,
      maxX: maxErasedX,
      maxY: maxErasedY
    }

    for (let pass = 0; pass < 12; pass += 1) {
      const searchMinX = Math.max(0, sweepBounds.minX - sparseBridgePadding)
      const searchMinY = Math.max(0, sweepBounds.minY - sparseBridgePadding)
      const searchMaxX = Math.min(width - 1, sweepBounds.maxX + sparseBridgePadding)
      const searchMaxY = Math.min(height - 1, sweepBounds.maxY + sparseBridgePadding)

      let foundSparseMatch = false
      let nextBounds = { ...sweepBounds }

      for (let y = searchMinY; y <= searchMaxY; y += 1) {
        for (let x = searchMinX; x <= searchMaxX; x += 1) {
          if (x >= sweepBounds.minX && x <= sweepBounds.maxX && y >= sweepBounds.minY && y <= sweepBounds.maxY) {
            continue
          }

          const pixelIndex = y * width + x
          const offset = pixelIndex * 4
          const alpha = data[offset + 3]
          if (alpha <= 0) {
            continue
          }

          if (colorDistanceSquaredUnpremultiplied(data, offset, seed) > sparseToleranceSquared) {
            continue
          }

          data[offset] = 0
          data[offset + 1] = 0
          data[offset + 2] = 0
          data[offset + 3] = 0
          foundSparseMatch = true
          nextBounds.minX = Math.min(nextBounds.minX, x)
          nextBounds.minY = Math.min(nextBounds.minY, y)
          nextBounds.maxX = Math.max(nextBounds.maxX, x)
          nextBounds.maxY = Math.max(nextBounds.maxY, y)
        }
      }

      if (!foundSparseMatch) {
        break
      }

      sweepBounds = nextBounds
    }
  }

  context.putImageData(imageData, 0, 0)
  return true
}

function setActiveTool(tool: ToolId) {
  const previousTool = activeTool.value
  if (previousTool !== tool) {
    finalizeTextEditor(true)
  }

  if (hasFloatingSelection.value && previousTool !== tool && tool !== 'lasso') {
    commitFloatingSelection(true)
  }

  activeTool.value = tool
  hoverStrokePreviewId.value = null
  clearPreviewCanvas()
  if (isBrushTool(tool) || isShapeTool(tool)) {
    lastPaintTool.value = tool
  }
}

function getBrushPresetByTool(tool: PaintToolId) {
  return brushPresetItems.find((item) => item.tool === tool) ?? null
}

function handleToolSelection(tool: ToolId) {
  if (isPaintTool(tool)) {
    const preset = getBrushPresetByTool(tool)
    if (preset) {
      applyBrushPreset(preset.id)
      return
    }
  }

  setActiveTool(tool)
}

function startPan(event: PointerEvent) {
  drawState.panning = true
  drawState.pointerId = event.pointerId
  drawState.pointerStartX = event.clientX
  drawState.pointerStartY = event.clientY
  drawState.panStartX = panX.value
  drawState.panStartY = panY.value

  const host = event.currentTarget as HTMLElement | null
  host?.setPointerCapture(event.pointerId)
}

function updatePan(event: PointerEvent) {
  const dx = event.clientX - drawState.pointerStartX
  const dy = event.clientY - drawState.pointerStartY
  panX.value = drawState.panStartX + dx
  panY.value = drawState.panStartY + dy
}

function stopPointerTracking(event: PointerEvent) {
  const host = event.currentTarget as HTMLElement | null
  if (host?.hasPointerCapture(event.pointerId)) {
    host.releasePointerCapture(event.pointerId)
  }

  drawState.pointerId = null
  drawState.drawing = false
  drawState.panning = false
  drawState.movingSelection = false
  drawState.selectingBox = false
  drawState.textBoxSelecting = false
  drawState.lassoSelecting = false
  drawState.lassoPoints = []
  drawState.strokeEraseChanged = false
  drawState.lastStrokeErasePoint = null
  drawState.lastPoint = null
  drawState.startPoint = null
  drawState.lastStrokeSize = 0
  drawState.lastTimestamp = 0
  discardRecordedStroke()
}

function updateTextBoxSelection(point: Point) {
  if (!drawState.startPoint) {
    return
  }

  drawState.lastPoint = point
  drawTextBoxPreview(buildRectFromPoints(drawState.startPoint.x, drawState.startPoint.y, point.x, point.y))
}

function finalizeTextBoxSelection(event: PointerEvent) {
  const start = drawState.startPoint
  if (!start) {
    return
  }

  const end = toCanvasPoint(event) ?? start
  const previewRect = buildRectFromPoints(start.x, start.y, end.x, end.y)
  const isClick = previewRect.width < 12 && previewRect.height < 12
  const defaultWidth = clamp(Math.max(220, Math.round(textStyle.size * 6)), 120, canvasWidth.value)
  const defaultHeight = clamp(Math.max(88, Math.round(textStyle.size * 3.4)), 56, canvasHeight.value)
  const rect = isClick
    ? normalizeTextRect({ x: start.x, y: start.y, width: defaultWidth, height: defaultHeight })
    : normalizeTextRect(previewRect)

  openTextEditor(rect)
}

async function handlePointerDown(event: PointerEvent) {
  if (event.pointerType === 'mouse' && event.button === 1) {
    event.preventDefault()
    startPan(event)
    return
  }

  if (event.pointerType === 'mouse' && event.button !== 0) {
    event.preventDefault()
    return
  }

  const point = toCanvasPoint(event)

  if (spacePressed.value && point && isPointInFloatingSelection(point)) {
    drawState.pointerId = event.pointerId
    drawState.drawing = true
    startSelectionMove(point)

    const host = event.currentTarget as HTMLElement | null
    host?.setPointerCapture(event.pointerId)
    return
  }

  if (spacePressed.value) {
    startPan(event)
    return
  }

  if (!point) {
    return
  }

  if (activeTool.value === 'text') {
    if (hasFloatingSelection.value) {
      commitFloatingSelection(true)
    }

    if (textEditor.active) {
      finalizeTextEditor(true)
    }

    const layer = activeLayer.value
    if (layer && !layer.locked) {
      const hitText = findTextElementAtPoint(point, layer.id)
      if (hitText) {
        openTextEditor(hitText, hitText.text, {
          layerId: layer.id,
          textId: hitText.id,
          style: hitText.style,
          mode: 'edit'
        })
        return
      }
    }

    drawState.pointerId = event.pointerId
    drawState.drawing = true
    drawState.startPoint = point
    drawState.lastPoint = point
    drawState.textBoxSelecting = true

    const host = event.currentTarget as HTMLElement | null
    host?.setPointerCapture(event.pointerId)

    drawTextBoxPreview({ x: point.x, y: point.y, width: 1, height: 1 })
    return
  }

  if (activeTool.value === 'lasso' && hasFloatingSelection.value && isPointInFloatingSelection(point)) {
    drawState.pointerId = event.pointerId
    drawState.drawing = true
    startSelectionMove(point)

    const host = event.currentTarget as HTMLElement | null
    host?.setPointerCapture(event.pointerId)
    return
  }

  if (activeTool.value === 'lasso') {
    if (hasFloatingSelection.value) {
      commitFloatingSelection(true)
    }

    drawState.pointerId = event.pointerId
    drawState.drawing = true
    drawState.lassoSelecting = true
    drawState.lassoPoints = [point]
    drawState.startPoint = point

    const host = event.currentTarget as HTMLElement | null
    host?.setPointerCapture(event.pointerId)

    clearPreviewCanvas()
    return
  }

  if (activeTool.value === 'fill') {
    if (hasFloatingSelection.value) {
      commitFloatingSelection(true)
    }

    const filled = floodFill(point)
    if (filled) {
      renderComposite()
      if (activeLayerId.value) {
        refreshLayerThumbnail(activeLayerId.value)
      }
      pushHistorySnapshot()
    }
    return
  }

  if (hasFloatingSelection.value) {
    commitFloatingSelection(true)
  }

  const pressure = normalizePressure(event)
  currentPressure.value = pressure
  if (event.pointerType !== 'mouse' && event.pressure > 0) {
    pressureDetected.value = true
  }

  if (activeTool.value === 'eyedropper') {
    pickColor(point)
    return
  }

  if (activeTool.value === 'eraser' && eraserMode.value === 'stroke') {
    const layer = activeLayer.value
    if (!layer || layer.locked) {
      return
    }

    hoverStrokePreviewId.value = null
    clearPreviewCanvas()

    drawState.pointerId = event.pointerId
    drawState.drawing = true
    drawState.lastPoint = point
    drawState.lastStrokeErasePoint = point
    drawState.strokeEraseChanged = false

    const host = event.currentTarget as HTMLElement | null
    host?.setPointerCapture(event.pointerId)

    const erased = eraseStrokeAtPoint(point)
    if (erased) {
      drawState.strokeEraseChanged = true
      renderComposite()
    }
    return
  }

  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return
  }

  drawState.pointerId = event.pointerId
  drawState.drawing = true
  drawState.lastPoint = point
  drawState.startPoint = point
  drawState.lastPressure = pressure
  drawState.lastTimestamp = event.timeStamp

  const host = event.currentTarget as HTMLElement | null
  host?.setPointerCapture(event.pointerId)

  if (isShapeTool(activeTool.value)) {
    drawShapePreview(point, point)
    return
  }

  const context = getLayerContext(layer.id)
  if (!context) {
    return
  }

  const strokeSize = resolveStrokeWidth(activeTool.value, point, pressure, event.timeStamp, null, 0, 0)
  drawState.lastStrokeSize = strokeSize

  if (isRecordablePaintTool(activeTool.value)) {
    beginRecordedStroke(layer.id, activeTool.value, point, pressure, strokeSize)
  }

  drawBrushSegment(
    context,
    { x: point.x, y: point.y, pressure, size: strokeSize },
    { x: point.x, y: point.y, pressure, size: strokeSize },
    activeTool.value
  )
  renderComposite()
}

function handlePointerMove(event: PointerEvent) {
  if (drawState.panning && drawState.pointerId === event.pointerId) {
    updatePan(event)
    return
  }

  if (drawState.movingSelection && drawState.pointerId === event.pointerId) {
    const point = toCanvasPoint(event)
    if (!point) {
      return
    }

    updateSelectionMove(point)
    return
  }

  if (drawState.selectingBox && drawState.pointerId === event.pointerId) {
    const point = toCanvasPoint(event)
    if (!point) {
      return
    }

    updateSelectionBox(point)
    return
  }

  if (drawState.textBoxSelecting && drawState.pointerId === event.pointerId) {
    const point = toCanvasPoint(event)
    if (!point) {
      return
    }

    updateTextBoxSelection(point)
    return
  }

  if (drawState.lassoSelecting && drawState.pointerId === event.pointerId) {
    const point = toCanvasPoint(event)
    if (!point) {
      return
    }

    const points = drawState.lassoPoints
    const last = points[points.length - 1]
    if (!last || Math.hypot(point.x - last.x, point.y - last.y) >= 1.5) {
      points.push(point)
      drawLassoPreview(points, false)
    }
    return
  }

  if (!drawState.drawing || drawState.pointerId !== event.pointerId) {
    updateStrokeHoverPreview(toCanvasPoint(event))
    return
  }

  const point = toCanvasPoint(event)
  if (!point) {
    return
  }

  const pressure = normalizePressure(event)
  currentPressure.value = pressure
  if (event.pointerType !== 'mouse' && event.pressure > 0) {
    pressureDetected.value = true
  }

  if (activeTool.value === 'eraser' && eraserMode.value === 'stroke') {
    const from = drawState.lastStrokeErasePoint ?? drawState.lastPoint ?? point
    const changed = eraseStrokeAlongPath(from, point)
    drawState.lastStrokeErasePoint = point
    drawState.lastPoint = point
    if (changed) {
      drawState.strokeEraseChanged = true
      renderComposite()
    }
    return
  }

  if (isShapeTool(activeTool.value) && drawState.startPoint) {
    drawShapePreview(drawState.startPoint, point)
    drawState.lastPoint = point
    drawState.lastPressure = pressure
    drawState.lastTimestamp = event.timeStamp
    return
  }

  const layer = activeLayer.value
  const from = drawState.lastPoint
  if (!layer || layer.locked || !from) {
    return
  }

  const context = getLayerContext(layer.id)
  if (!context) {
    return
  }

  const strokeSize = resolveStrokeWidth(
    activeTool.value,
    point,
    pressure,
    event.timeStamp,
    from,
    drawState.lastStrokeSize,
    drawState.lastTimestamp
  )

  if (isRecordablePaintTool(activeTool.value)) {
    appendRecordedStrokePoint(point, pressure, strokeSize)
  }

  drawBrushSegment(
    context,
    { x: from.x, y: from.y, pressure: drawState.lastPressure, size: drawState.lastStrokeSize },
    { x: point.x, y: point.y, pressure, size: strokeSize },
    activeTool.value
  )
  drawState.lastPoint = point
  drawState.lastPressure = pressure
  drawState.lastStrokeSize = strokeSize
  drawState.lastTimestamp = event.timeStamp
  renderComposite()
}

function finishDrawing(event: PointerEvent) {
  if (drawState.panning && drawState.pointerId === event.pointerId) {
    stopPointerTracking(event)
    return
  }

  if (drawState.movingSelection && drawState.pointerId === event.pointerId) {
    stopPointerTracking(event)
    renderComposite()
    return
  }

  if (drawState.selectingBox && drawState.pointerId === event.pointerId) {
    finalizeSelectionBox()
    stopPointerTracking(event)
    return
  }

  if (drawState.textBoxSelecting && drawState.pointerId === event.pointerId) {
    finalizeTextBoxSelection(event)
    stopPointerTracking(event)
    return
  }

  if (drawState.lassoSelecting && drawState.pointerId === event.pointerId) {
    const points = [...drawState.lassoPoints]
    const start = points[0] ?? drawState.startPoint
    const end = toCanvasPoint(event) ?? points[points.length - 1] ?? start
    const clickDistance = start && end ? Math.hypot(end.x - start.x, end.y - start.y) : Number.POSITIVE_INFINITY
    const isClickSelection = points.length < 3 || clickDistance <= 4

    if (isClickSelection && start) {
      trySelectObjectAtPoint(start)
    } else if (points.length >= 3) {
      const first = points[0]!
      const last = points[points.length - 1]!
      if (Math.hypot(first.x - last.x, first.y - last.y) > 2) {
        points.push({ x: first.x, y: first.y })
      }
      drawLassoPreview(points, true)
      finalizeLassoSelection(points)
    }

    clearPreviewCanvas()

    stopPointerTracking(event)
    return
  }

  if (!drawState.drawing || drawState.pointerId !== event.pointerId) {
    return
  }

  if (activeTool.value === 'eraser' && eraserMode.value === 'stroke') {
    if (drawState.strokeEraseChanged) {
      if (activeLayerId.value) {
        refreshLayerThumbnail(activeLayerId.value)
      }
      pushHistorySnapshot()
    }
    stopPointerTracking(event)
    return
  }

  if (isRecordablePaintTool(activeTool.value)) {
    applyPenTerminalAccent()
    commitRecordedStroke()
  }

  if (isShapeTool(activeTool.value) && drawState.startPoint) {
    const end = toCanvasPoint(event) ?? drawState.startPoint
    commitShape(drawState.startPoint, end)
    clearPreviewCanvas()
    renderComposite()
  }

  if (activeLayerId.value) {
    refreshLayerThumbnail(activeLayerId.value)
  }
  pushHistorySnapshot()
  stopPointerTracking(event)
}

function handlePointerUp(event: PointerEvent) {
  finishDrawing(event)
}

function handlePointerCancel(event: PointerEvent) {
  finishDrawing(event)
}

function handlePointerLeave(event: PointerEvent) {
  const host = event.currentTarget as HTMLElement | null
  if (host?.hasPointerCapture(event.pointerId)) {
    return
  }

  hoverStrokePreviewId.value = null
  clearPreviewCanvas()
  finishDrawing(event)
}

function fitCanvasToViewport() {
  const viewport = viewportRef.value
  if (!viewport) {
    return
  }

  const padding = 64
  const availableWidth = Math.max(120, viewport.clientWidth - padding)
  const availableHeight = Math.max(120, viewport.clientHeight - padding)
  const nextFit = Math.min(availableWidth / canvasWidth.value, availableHeight / canvasHeight.value)
  fitScale.value = clamp(nextFit, 0.05, 4)
  zoomFactor.value = 1

  panX.value = Math.round((viewport.clientWidth - canvasWidth.value * fitScale.value) / 2)
  panY.value = Math.round((viewport.clientHeight - canvasHeight.value * fitScale.value) / 2)
}

function zoomIn() {
  setZoomFactor(zoomFactor.value * 1.15)
}

function zoomOut() {
  setZoomFactor(zoomFactor.value / 1.15)
}

function setZoomFactor(nextValue: number) {
  const viewport = viewportRef.value
  if (!viewport) {
    return
  }

  const oldScale = viewScale.value
  const nextZoom = clamp(nextValue, 0.2, 8)
  const nextScale = fitScale.value * nextZoom

  const centerX = viewport.clientWidth / 2
  const centerY = viewport.clientHeight / 2
  const worldX = (centerX - panX.value) / oldScale
  const worldY = (centerY - panY.value) / oldScale

  zoomFactor.value = nextZoom
  panX.value = centerX - worldX * nextScale
  panY.value = centerY - worldY * nextScale
}

function handleViewportWheel(event: WheelEvent) {
  if (event.ctrlKey || event.metaKey) {
    const factor = event.deltaY < 0 ? 1.08 : 0.92
    setZoomFactor(zoomFactor.value * factor)
    return
  }

  if (spacePressed.value) {
    panX.value -= event.deltaX
    panY.value -= event.deltaY
  }
}

function resizeCanvasPreserveContent(nextWidth: number, nextHeight: number) {
  finalizeFloatingSelection()
  clearAllLayerStrokeHistories()

  const clampedWidth = clamp(Math.round(nextWidth), 320, 6000)
  const clampedHeight = clamp(Math.round(nextHeight), 240, 6000)

  if (clampedWidth === canvasWidth.value && clampedHeight === canvasHeight.value) {
    fitCanvasToViewport()
    return
  }

  const nextRasters = new Map<string, HTMLCanvasElement>()
  for (const layer of layers.value) {
    const previous = getLayerRaster(layer.id)
    const raster = createLayerRaster(clampedWidth, clampedHeight)
    const context = getCanvas2DContext(raster, true)
    if (context && previous) {
      context.drawImage(previous, 0, 0)
    }
    nextRasters.set(layer.id, raster)
  }

  canvasWidth.value = clampedWidth
  canvasHeight.value = clampedHeight
  syncDisplayCanvasSize()

  layerRasterMap.clear()
  for (const [layerId, raster] of nextRasters.entries()) {
    layerRasterMap.set(layerId, raster)
  }

  renderComposite()
  refreshAllLayerThumbnails()
  pushHistorySnapshot()

  nextTick(() => {
    fitCanvasToViewport()
  })
}

function applyCanvasSize() {
  resizeCanvasPreserveContent(canvasSizeDraft.width, canvasSizeDraft.height)
}

function initializeDocument(width: number, height: number, backgroundColor = '#ffffff') {
  cancelTextEditor()
  clearFloatingSelection()
  clearAllLayerStrokeHistories()
  layerTextMap.clear()

  canvasWidth.value = clamp(Math.round(width), 320, 6000)
  canvasHeight.value = clamp(Math.round(height), 240, 6000)
  documentBackgroundColor.value = backgroundColor
  syncDisplayCanvasSize()

  layers.value = []
  layerRasterMap.clear()

  const baseLayer = createLayer('背景', backgroundColor)
  layers.value.push(baseLayer)
  activeLayerId.value = baseLayer.id

  renderComposite()
  refreshAllLayerThumbnails()
  resetHistory()
  pushHistorySnapshot()

  nextTick(() => {
    fitCanvasToViewport()
  })
}

function addLayer() {
  finalizeFloatingSelection()

  const layer = createLayer(`图层 ${layers.value.length + 1}`)
  layers.value.push(layer)
  activeLayerId.value = layer.id
  renderComposite()
  refreshLayerThumbnail(layer.id)
  pushHistorySnapshot()
}

function duplicateActiveLayer() {
  finalizeFloatingSelection()

  const current = activeLayer.value
  if (!current) {
    return
  }

  const source = getLayerRaster(current.id)
  if (!source) {
    return
  }

  const duplicated = createLayer(`${current.name} 副本`)
  duplicated.visible = current.visible
  duplicated.locked = current.locked
  duplicated.opacity = current.opacity
  duplicated.blendMode = current.blendMode

  const target = getLayerContext(duplicated.id)
  if (target) {
    target.drawImage(source, 0, 0)
  }
  layerTextMap.set(duplicated.id, serializeLayerTextElements(current.id))
  resetLayerStrokeHistoryFromCurrent(duplicated.id)

  const index = layers.value.findIndex((layer) => layer.id === current.id)
  layers.value.splice(index + 1, 0, duplicated)
  activeLayerId.value = duplicated.id

  renderComposite()
  refreshLayerThumbnail(duplicated.id)
  pushHistorySnapshot()
}

function removeActiveLayer() {
  finalizeFloatingSelection()

  if (layers.value.length <= 1 || !activeLayerId.value) {
    return
  }

  const index = layers.value.findIndex((layer) => layer.id === activeLayerId.value)
  if (index < 0) {
    return
  }

  const removed = layers.value[index]
  layers.value.splice(index, 1)
  layerRasterMap.delete(removed.id)
  layerStrokeHistoryMap.delete(removed.id)
  layerTextMap.delete(removed.id)

  const next = layers.value[Math.min(index, layers.value.length - 1)]
  activeLayerId.value = next?.id ?? null

  renderComposite()
  refreshAllLayerThumbnails()
  pushHistorySnapshot()
}

function moveLayer(direction: 'up' | 'down') {
  finalizeFloatingSelection()

  if (!activeLayerId.value) {
    return
  }

  const index = layers.value.findIndex((layer) => layer.id === activeLayerId.value)
  if (index < 0) {
    return
  }

  const target = direction === 'up' ? index + 1 : index - 1
  if (target < 0 || target >= layers.value.length) {
    return
  }

  const currentLayer = layers.value[index]
  const targetLayer = layers.value[target]
  if (!currentLayer || !targetLayer) {
    return
  }

  layers.value[index] = targetLayer
  layers.value[target] = currentLayer

  renderComposite()
  refreshAllLayerThumbnails()
  pushHistorySnapshot()
}

function setActiveLayer(layerId: string) {
  if (textEditor.active && textEditor.layerId !== layerId) {
    finalizeTextEditor(true)
  }

  if (hasFloatingSelection.value && activeLayerId.value && activeLayerId.value !== layerId) {
    commitFloatingSelection(true)
  }

  activeLayerId.value = layerId
}

function toggleLayerVisible(layerId: string) {
  finalizeFloatingSelection()

  const layer = layers.value.find((item) => item.id === layerId)
  if (!layer) {
    return
  }

  layer.visible = !layer.visible
  renderComposite()
  refreshLayerThumbnail(layerId)
  pushHistorySnapshot()
}

function toggleLayerLocked(layerId: string) {
  finalizeFloatingSelection()

  const layer = layers.value.find((item) => item.id === layerId)
  if (!layer) {
    return
  }

  layer.locked = !layer.locked
  pushHistorySnapshot()
}

function commitLayerName() {
  const layer = activeLayer.value
  if (!layer) {
    return
  }

  const nextName = layerNameInput.value.trim()
  if (!nextName || nextName === layer.name) {
    layerNameInput.value = layer.name
    return
  }

  layer.name = nextName
  pushHistorySnapshot()
}

function handleActiveLayerOpacityInput(event: Event) {
  const layer = activeLayer.value
  if (!layer) {
    return
  }

  const target = event.target as HTMLInputElement
  const value = Number.parseFloat(target.value)
  if (!Number.isFinite(value)) {
    return
  }

  layer.opacity = clamp(value / 100, 0, 1)
  renderComposite()
}

function commitLayerAppearance() {
  if (activeLayerId.value) {
    refreshLayerThumbnail(activeLayerId.value)
  }
  pushHistorySnapshot()
}

function handleActiveLayerBlendChange(event: Event) {
  const layer = activeLayer.value
  if (!layer) {
    return
  }

  const target = event.target as HTMLSelectElement
  const nextMode = target.value as LayerBlendMode
  const found = blendModeOptions.find((item) => item.value === nextMode)
  if (!found) {
    return
  }

  layer.blendMode = nextMode
  renderComposite()
  refreshLayerThumbnail(layer.id)
  pushHistorySnapshot()
}

function clearActiveLayer() {
  finalizeFloatingSelection()

  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return
  }

  const context = getLayerContext(layer.id)
  if (!context) {
    return
  }

  context.clearRect(0, 0, canvasWidth.value, canvasHeight.value)
  layerTextMap.set(layer.id, [])
  resetLayerStrokeHistoryFromCurrent(layer.id)
  renderComposite()
  refreshLayerThumbnail(layer.id)
  pushHistorySnapshot()
}

function flattenLayerTextElements(layerId: string) {
  const raster = getLayerRaster(layerId)
  const context = getLayerContext(layerId)
  const items = getLayerTextElements(layerId)
  if (!raster || !context || items.length === 0) {
    return false
  }

  for (const item of items) {
    renderTextElement(context, item, 1)
  }

  layerTextMap.set(layerId, [])
  resetLayerStrokeHistoryFromCurrent(layerId)
  return true
}

function commitLayerMutation(layerId: string, refreshAll = false) {
  resetLayerStrokeHistoryFromCurrent(layerId)
  renderComposite()
  if (refreshAll) {
    refreshAllLayerThumbnails()
  } else {
    refreshLayerThumbnail(layerId)
  }
  pushHistorySnapshot()
}

function getEditableActiveLayerTarget() {
  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return null
  }

  const raster = getLayerRaster(layer.id)
  const context = getLayerContext(layer.id)
  if (!raster || !context) {
    return null
  }

  return { layer, raster, context }
}

function transformActiveLayer(transform: (context: CanvasRenderingContext2D, source: HTMLCanvasElement) => void) {
  finalizeFloatingSelection()

  const target = getEditableActiveLayerTarget()
  if (!target) {
    return
  }

  flattenLayerTextElements(target.layer.id)

  const source = createLayerRaster(canvasWidth.value, canvasHeight.value)
  const sourceContext = getCanvas2DContext(source, true)
  if (!sourceContext) {
    return
  }

  sourceContext.drawImage(target.raster, 0, 0)
  target.context.clearRect(0, 0, canvasWidth.value, canvasHeight.value)
  transform(target.context, source)
  commitLayerMutation(target.layer.id)
}

function mutateActiveLayerPixels(mutator: (data: Uint8ClampedArray, width: number, height: number) => void) {
  finalizeFloatingSelection()

  const target = getEditableActiveLayerTarget()
  if (!target) {
    return
  }

  flattenLayerTextElements(target.layer.id)

  const width = canvasWidth.value
  const height = canvasHeight.value
  const imageData = target.context.getImageData(0, 0, width, height)
  mutator(imageData.data, width, height)
  target.context.putImageData(imageData, 0, 0)
  commitLayerMutation(target.layer.id)
}

function applyConvolutionKernel(kernel: number[], divisor: number) {
  mutateActiveLayerPixels((data, width, height) => {
    const source = new Uint8ClampedArray(data)
    const safeDivisor = divisor === 0 ? 1 : divisor

    for (let y = 0; y < height; y += 1) {
      for (let x = 0; x < width; x += 1) {
        const targetIndex = (y * width + x) * 4
        const alpha = source[targetIndex + 3]
        if (alpha === 0) {
          continue
        }

        let red = 0
        let green = 0
        let blue = 0

        for (let kernelY = -1; kernelY <= 1; kernelY += 1) {
          const sampleY = clamp(y + kernelY, 0, height - 1)
          for (let kernelX = -1; kernelX <= 1; kernelX += 1) {
            const sampleX = clamp(x + kernelX, 0, width - 1)
            const sampleIndex = (sampleY * width + sampleX) * 4
            const kernelIndex = (kernelY + 1) * 3 + (kernelX + 1)
            const weight = kernel[kernelIndex] ?? 0

            red += source[sampleIndex] * weight
            green += source[sampleIndex + 1] * weight
            blue += source[sampleIndex + 2] * weight
          }
        }

        data[targetIndex] = clamp(Math.round(red / safeDivisor), 0, 255)
        data[targetIndex + 1] = clamp(Math.round(green / safeDivisor), 0, 255)
        data[targetIndex + 2] = clamp(Math.round(blue / safeDivisor), 0, 255)
      }
    }
  })
}

function rotateActiveLayer(degrees: number) {
  transformActiveLayer((context, source) => {
    context.save()
    context.translate(canvasWidth.value / 2, canvasHeight.value / 2)
    context.rotate((degrees * Math.PI) / 180)
    context.drawImage(source, -canvasWidth.value / 2, -canvasHeight.value / 2)
    context.restore()
  })
}

function flipActiveLayer(direction: 'horizontal' | 'vertical') {
  transformActiveLayer((context, source) => {
    context.save()
    if (direction === 'horizontal') {
      context.translate(canvasWidth.value, 0)
      context.scale(-1, 1)
    } else {
      context.translate(0, canvasHeight.value)
      context.scale(1, -1)
    }
    context.drawImage(source, 0, 0)
    context.restore()
  })
}

function applyGrayscaleFilter() {
  const ratio = clamp(filterIntensity.value, 1, 100) / 100
  mutateActiveLayerPixels((data) => {
    for (let index = 0; index < data.length; index += 4) {
      const alpha = data[index + 3]
      if (alpha === 0) {
        continue
      }

      const red = data[index]
      const green = data[index + 1]
      const blue = data[index + 2]
      const gray = Math.round(red * 0.299 + green * 0.587 + blue * 0.114)
      data[index] = clamp(Math.round(red + (gray - red) * ratio), 0, 255)
      data[index + 1] = clamp(Math.round(green + (gray - green) * ratio), 0, 255)
      data[index + 2] = clamp(Math.round(blue + (gray - blue) * ratio), 0, 255)
    }
  })
}

function applySepiaFilter() {
  const ratio = clamp(filterIntensity.value, 1, 100) / 100
  mutateActiveLayerPixels((data) => {
    for (let index = 0; index < data.length; index += 4) {
      const alpha = data[index + 3]
      if (alpha === 0) {
        continue
      }

      const red = data[index]
      const green = data[index + 1]
      const blue = data[index + 2]

      const sepiaRed = clamp(Math.round(red * 0.393 + green * 0.769 + blue * 0.189), 0, 255)
      const sepiaGreen = clamp(Math.round(red * 0.349 + green * 0.686 + blue * 0.168), 0, 255)
      const sepiaBlue = clamp(Math.round(red * 0.272 + green * 0.534 + blue * 0.131), 0, 255)

      data[index] = clamp(Math.round(red + (sepiaRed - red) * ratio), 0, 255)
      data[index + 1] = clamp(Math.round(green + (sepiaGreen - green) * ratio), 0, 255)
      data[index + 2] = clamp(Math.round(blue + (sepiaBlue - blue) * ratio), 0, 255)
    }
  })
}

function applyInvertFilter() {
  const ratio = clamp(filterIntensity.value, 1, 100) / 100
  mutateActiveLayerPixels((data) => {
    for (let index = 0; index < data.length; index += 4) {
      const alpha = data[index + 3]
      if (alpha === 0) {
        continue
      }

      const red = data[index]
      const green = data[index + 1]
      const blue = data[index + 2]

      data[index] = clamp(Math.round(red + ((255 - red) - red) * ratio), 0, 255)
      data[index + 1] = clamp(Math.round(green + ((255 - green) - green) * ratio), 0, 255)
      data[index + 2] = clamp(Math.round(blue + ((255 - blue) - blue) * ratio), 0, 255)
    }
  })
}

function applySoftBlurFilter() {
  const ratio = clamp(filterIntensity.value, 1, 100) / 100
  const blurRadius = 0.4 + ratio * 5.6
  transformActiveLayer((context, source) => {
    context.save()
    context.filter = `blur(${blurRadius.toFixed(2)}px)`
    context.drawImage(source, 0, 0)
    context.restore()
  })
}

function applySharpenFilter() {
  const ratio = clamp(filterIntensity.value, 1, 100) / 100
  const edgeWeight = 0.5 + ratio
  const centerWeight = 1 + edgeWeight * 4
  applyConvolutionKernel([
    0, -edgeWeight, 0,
    -edgeWeight, centerWeight, -edgeWeight,
    0, -edgeWeight, 0
  ], 1)
}

function mergeActiveLayerDown() {
  finalizeFloatingSelection()

  if (!activeLayerId.value || layers.value.length <= 1) {
    return
  }

  const index = layers.value.findIndex((layer) => layer.id === activeLayerId.value)
  if (index <= 0) {
    return
  }

  const sourceLayer = layers.value[index]
  const targetLayer = layers.value[index - 1]
  if (!sourceLayer || !targetLayer || sourceLayer.locked || targetLayer.locked) {
    return
  }

  const sourceRaster = getLayerRaster(sourceLayer.id)
  const targetContext = getLayerContext(targetLayer.id)
  if (!sourceRaster || !targetContext) {
    return
  }

  flattenLayerTextElements(targetLayer.id)

  targetContext.save()
  targetContext.globalAlpha = clamp(sourceLayer.opacity, 0, 1)
  targetContext.globalCompositeOperation = sourceLayer.blendMode
  targetContext.drawImage(sourceRaster, 0, 0)
  renderLayerTextElements(targetContext, sourceLayer.id, clamp(sourceLayer.opacity, 0, 1))
  targetContext.restore()

  layers.value.splice(index, 1)
  layerRasterMap.delete(sourceLayer.id)
  layerStrokeHistoryMap.delete(sourceLayer.id)
  layerTextMap.delete(sourceLayer.id)
  layerTextMap.set(targetLayer.id, [])
  activeLayerId.value = targetLayer.id
  commitLayerMutation(targetLayer.id, true)
}

function mergeVisibleLayers() {
  finalizeFloatingSelection()

  if (visibleLayerCount.value <= 1) {
    return
  }

  const visibleIndexes: number[] = []
  for (let index = 0; index < layers.value.length; index += 1) {
    if (layers.value[index]?.visible) {
      visibleIndexes.push(index)
    }
  }

  if (visibleIndexes.length <= 1) {
    return
  }

  const mergedLayer = createLayer('合并图层')
  const mergedContext = getLayerContext(mergedLayer.id)
  if (!mergedContext) {
    return
  }

  for (const index of visibleIndexes) {
    const layer = layers.value[index]
    if (!layer) {
      continue
    }

    const raster = getLayerRaster(layer.id)
    if (!raster) {
      continue
    }

    mergedContext.save()
    mergedContext.globalAlpha = clamp(layer.opacity, 0, 1)
    mergedContext.globalCompositeOperation = layer.blendMode
    mergedContext.drawImage(raster, 0, 0)
    renderLayerTextElements(mergedContext, layer.id, clamp(layer.opacity, 0, 1))
    mergedContext.restore()
  }

  const insertAt = visibleIndexes[visibleIndexes.length - 1] ?? layers.value.length - 1
  const nextLayers: LayerModel[] = []
  for (let index = 0; index < layers.value.length; index += 1) {
    const layer = layers.value[index]
    if (!layer) {
      continue
    }

    if (!layer.visible) {
      nextLayers.push(layer)
    } else {
      layerRasterMap.delete(layer.id)
      layerStrokeHistoryMap.delete(layer.id)
      layerTextMap.delete(layer.id)
    }

    if (index === insertAt) {
      nextLayers.push(mergedLayer)
    }
  }

  layers.value = nextLayers
  activeLayerId.value = mergedLayer.id
  commitLayerMutation(mergedLayer.id, true)
}

function adjustTextSize(step: number) {
  const nextSize = clamp(Math.round(textStyle.size + step), 8, 360)
  textStyle.size = nextSize
  if (activeTool.value !== 'text') {
    setActiveTool('text')
  }
}

function toggleTextBold() {
  textStyle.bold = !textStyle.bold
  if (activeTool.value !== 'text') {
    setActiveTool('text')
  }
}

function toggleTextItalic() {
  textStyle.italic = !textStyle.italic
  if (activeTool.value !== 'text') {
    setActiveTool('text')
  }
}

function resetView() {
  fitCanvasToViewport()
}

function resetWorkspaceLayout() {
  sidePanelVisible.value = true
  resetView()
}

function openHelpDialog(tab: HelpTab = 'usage') {
  activeHelpTab.value = tab
  helpShortcutKeyword.value = ''
  showHelpDialog.value = true
}

function closeHelpDialog() {
  showHelpDialog.value = false
  helpShortcutKeyword.value = ''
}

function showUsageTip() {
  openHelpDialog('usage')
}

function showShortcutTip() {
  openHelpDialog('shortcuts')
}

function showAboutDialog() {
  openHelpDialog('about')
}

function toCssBlendMode(mode: LayerBlendMode) {
  return mode === 'source-over' ? 'normal' : mode
}

async function openNativePath(bridge: DesktopNativeBridge, filePath: string) {
  clearFloatingSelection()

  const extension = getFileExtension(filePath)
  const base64Content = await callBridgeReadFileAsBase64(bridge, filePath)
  if (!base64Content) {
    return
  }

  if (isProjectExtension(extension)) {
    const text = base64ToText(base64Content)
    const parsed = JSON.parse(text)
    const project = parseProjectFile(parsed)
    if (!project) {
      return
    }

    await openProject(project)
    return
  }

  if (isImageExtension(extension)) {
    const mimeType = getMimeByExtension(extension)
    const dataUrl = `data:${mimeType};base64,${base64Content}`
    const layerName = pathBaseName(filePath).replace(/\.[^.]+$/u, '') || `图层 ${layers.value.length + 1}`
    await importImageDataUrl(dataUrl, layerName, true)
  }
}

async function openLocalFile() {
  clearFloatingSelection()

  const bridge = await getDesktopNativeBridge()
  if (bridge) {
    const filePath = (await callBridgeOpenFileDialog(bridge)).trim()
    if (!filePath) {
      return
    }

    try {
      await openNativePath(bridge, filePath)
    } catch {
    }
    return
  }

  if (!openFileInputRef.value) {
    return
  }

  openFileInputRef.value.value = ''
  openFileInputRef.value.click()
}

async function openImportImage() {
  finalizeFloatingSelection()

  const bridge = await getDesktopNativeBridge()
  if (bridge) {
    const filePath = (await callBridgeOpenFileDialog(bridge)).trim()
    if (!filePath) {
      return
    }

    const extension = getFileExtension(filePath)
    if (!isImageExtension(extension)) {
      return
    }

    try {
      await openNativePath(bridge, filePath)
    } catch {
    }
    return
  }

  if (!importImageInputRef.value) {
    return
  }

  importImageInputRef.value.value = ''
  importImageInputRef.value.click()
}

async function fileToDataUrl(file: File) {
  return await new Promise<string>((resolve, reject) => {
    const reader = new FileReader()
    reader.onload = () => {
      const result = typeof reader.result === 'string' ? reader.result : ''
      resolve(result)
    }
    reader.onerror = () => reject(new Error('读取文件失败'))
    reader.readAsDataURL(file)
  })
}

async function fileToText(file: File) {
  return await new Promise<string>((resolve, reject) => {
    const reader = new FileReader()
    reader.onload = () => {
      const result = typeof reader.result === 'string' ? reader.result : ''
      resolve(result)
    }
    reader.onerror = () => reject(new Error('读取文本失败'))
    reader.readAsText(file)
  })
}

function pathBaseName(filePath: string) {
  const normalized = filePath.replace(/\\/g, '/')
  const index = normalized.lastIndexOf('/')
  return index >= 0 ? normalized.slice(index + 1) : normalized
}

function getFileExtension(filePath: string) {
  const name = pathBaseName(filePath).toLocaleLowerCase()
  const index = name.lastIndexOf('.')
  return index >= 0 ? name.slice(index + 1) : ''
}

function isProjectExtension(extension: string) {
  return extension === 'dbp' || extension === 'json'
}

function isImageExtension(extension: string) {
  return ['png', 'jpg', 'jpeg', 'gif', 'bmp', 'webp', 'svg'].includes(extension)
}

function getMimeByExtension(extension: string) {
  if (extension === 'jpg' || extension === 'jpeg') {
    return 'image/jpeg'
  }

  if (extension === 'svg') {
    return 'image/svg+xml'
  }

  if (extension === 'gif') {
    return 'image/gif'
  }

  if (extension === 'bmp') {
    return 'image/bmp'
  }

  if (extension === 'webp') {
    return 'image/webp'
  }

  return 'image/png'
}

function base64ToText(base64Content: string) {
  const binary = atob(base64Content)
  const bytes = new Uint8Array(binary.length)
  for (let index = 0; index < binary.length; index += 1) {
    bytes[index] = binary.charCodeAt(index)
  }

  return new TextDecoder().decode(bytes)
}

function isImageFile(file: File) {
  return file.type.startsWith('image/') || /\.(png|jpe?g|gif|bmp|webp|svg)$/i.test(file.name)
}

async function importImageDataUrl(dataUrl: string, layerName: string, createNewLayer = true) {
  finalizeFloatingSelection()

  const image = await loadImage(dataUrl)

  let targetLayer = activeLayer.value
  if (createNewLayer || !targetLayer) {
    const layer = createLayer(layerName || `图层 ${layers.value.length + 1}`)
    layers.value.push(layer)
    activeLayerId.value = layer.id
    targetLayer = layer
  }

  if (!targetLayer || targetLayer.locked) {
    return
  }

  const context = getLayerContext(targetLayer.id)
  if (!context) {
    return
  }

  const scale = Math.min(
    (canvasWidth.value * 0.9) / image.width,
    (canvasHeight.value * 0.9) / image.height,
    1
  )

  const drawWidth = image.width * scale
  const drawHeight = image.height * scale
  const offsetX = (canvasWidth.value - drawWidth) / 2
  const offsetY = (canvasHeight.value - drawHeight) / 2
  context.drawImage(image, offsetX, offsetY, drawWidth, drawHeight)
  resetLayerStrokeHistoryFromCurrent(targetLayer.id)

  renderComposite()
  refreshLayerThumbnail(targetLayer.id)
  pushHistorySnapshot()
}

async function importImageFile(file: File, createNewLayer = true) {
  const dataUrl = await fileToDataUrl(file)
  const layerName = file.name.replace(/\.[^.]+$/u, '') || `图层 ${layers.value.length + 1}`
  await importImageDataUrl(dataUrl, layerName, createNewLayer)
}

async function handleImportImage(event: Event) {
  const input = event.target as HTMLInputElement
  const file = input.files?.[0]
  if (!file) {
    return
  }

  try {
    await importImageFile(file, true)
  } finally {
    input.value = ''
  }
}

function parseProjectFile(raw: unknown): ProjectFile | null {
  if (!raw || typeof raw !== 'object') {
    return null
  }

  const value = raw as Partial<ProjectFile>
  if (!Array.isArray(value.layers)) {
    return null
  }

  const width = Number(value.width)
  const height = Number(value.height)
  if (!Number.isFinite(width) || !Number.isFinite(height) || width <= 0 || height <= 0) {
    return null
  }

  return {
    version: value.version === 3 ? 3 : value.version === 2 ? 2 : 1,
    width,
    height,
    documentName: typeof value.documentName === 'string' && value.documentName.trim() ? value.documentName : '未命名 1',
    layers: value.layers
      .map((layer) => {
        const item = layer as Partial<LayerSnapshot>
        const blend = blendModeOptions.find((mode) => mode.value === item.blendMode)?.value ?? 'source-over'
        const strokeHistory = (() => {
          const rawHistory = item.strokeHistory
          if (!rawHistory || typeof rawHistory !== 'object') {
            return undefined
          }

          const historyValue = rawHistory as Partial<SerializedLayerStrokeHistory>
          return {
            baseImage: typeof historyValue.baseImage === 'string' ? historyValue.baseImage : '',
            strokes: Array.isArray(historyValue.strokes) ? historyValue.strokes as SerializedBrushStrokeRecord[] : []
          } satisfies SerializedLayerStrokeHistory
        })()
        const textElements = Array.isArray(item.textElements)
          ? item.textElements
              .filter((textItem) => textItem && typeof textItem === 'object')
              .map((textItem) => {
                const value = textItem as Partial<SerializedTextElement>
                return {
                  id: typeof value.id === 'string' && value.id ? value.id : createId(),
                  x: Number(value.x ?? 0),
                  y: Number(value.y ?? 0),
                  width: Number(value.width ?? 240),
                  height: Number(value.height ?? 96),
                  text: typeof value.text === 'string' ? value.text : '',
                  style: cloneTextStyleSnapshot(value.style ?? captureCurrentTextStyle())
                } satisfies SerializedTextElement
              })
          : []

        return {
          id: typeof item.id === 'string' && item.id ? item.id : createId(),
          name: typeof item.name === 'string' && item.name ? item.name : `图层 ${Math.floor(Math.random() * 100)}`,
          visible: item.visible !== false,
          locked: item.locked === true,
          opacity: clamp(Number(item.opacity ?? 1), 0, 1),
          blendMode: blend,
          image: typeof item.image === 'string' ? item.image : '',
          strokeHistory,
          textElements
        } as LayerSnapshot
      })
  }
}

async function openProject(project: ProjectFile) {
  cancelTextEditor()
  clearFloatingSelection()
  clearAllLayerStrokeHistories()
  layerTextMap.clear()

  canvasWidth.value = clamp(Math.round(project.width), 320, 6000)
  canvasHeight.value = clamp(Math.round(project.height), 240, 6000)
  documentName.value = project.documentName || '未命名 1'
  documentBackgroundColor.value = '#ffffff'
  syncDisplayCanvasSize()

  layers.value = []
  layerRasterMap.clear()

  for (const item of project.layers) {
    const layer: LayerModel = {
      id: item.id,
      name: item.name,
      visible: item.visible,
      locked: item.locked,
      opacity: item.opacity,
      blendMode: item.blendMode,
      thumbnail: ''
    }
    layers.value.push(layer)

    const raster = createLayerRaster(canvasWidth.value, canvasHeight.value)
    layerRasterMap.set(layer.id, raster)

    if (item.image) {
      try {
        const image = await loadImage(item.image)
        const context = getCanvas2DContext(raster, true)
        if (context) {
          context.drawImage(image, 0, 0, canvasWidth.value, canvasHeight.value)
        }
      } catch {
      }
    }

    await restoreLayerStrokeHistory(layer.id, item.strokeHistory)
    restoreLayerTextElements(layer.id, item.textElements)
  }

  if (layers.value.length === 0) {
    const fallback = createLayer('背景', '#ffffff')
    layers.value.push(fallback)
  }

  activeLayerId.value = layers.value[layers.value.length - 1]?.id ?? null
  renderComposite()
  refreshAllLayerThumbnails()
  resetHistory()
  pushHistorySnapshot()

  nextTick(() => {
    fitCanvasToViewport()
  })
}

async function handleOpenLocalFile(event: Event) {
  const input = event.target as HTMLInputElement
  const file = input.files?.[0]
  if (!file) {
    return
  }

  try {
    if (isImageFile(file)) {
      await importImageFile(file, true)
      return
    }

    const text = await fileToText(file)
    const parsed = JSON.parse(text)
    const project = parseProjectFile(parsed)
    if (!project) {
      return
    }

    await openProject(project)
  } catch {
  } finally {
    input.value = ''
  }
}

function downloadBlob(fileName: string, blob: Blob) {
  const url = URL.createObjectURL(blob)
  const link = document.createElement('a')
  link.href = url
  link.download = fileName
  link.click()
  URL.revokeObjectURL(url)
}

async function saveBlobByUserPath(defaultFileName: string, blob: Blob) {
  const bridge = await getDesktopNativeBridge()
  if (!bridge) {
    downloadBlob(defaultFileName, blob)
    return true
  }

  const selectedPath = (await callBridgeSaveFileDialog(bridge, defaultFileName)).trim()
  if (!selectedPath) {
    return false
  }

  try {
    const base64Payload = await blobToBase64Payload(blob)
    const writeSuccess = await callBridgeWriteFile(bridge, selectedPath, base64Payload)
    if (!writeSuccess) {
      downloadBlob(defaultFileName, blob)
    }
    return writeSuccess
  } catch {
    downloadBlob(defaultFileName, blob)
    return false
  }
}

async function saveProject() {
  finalizeFloatingSelection()

  const project: ProjectFile = {
    version: 3,
    width: canvasWidth.value,
    height: canvasHeight.value,
    documentName: documentName.value,
    layers: layers.value.map((layer) => ({
      id: layer.id,
      name: layer.name,
      visible: layer.visible,
      locked: layer.locked,
      opacity: layer.opacity,
      blendMode: layer.blendMode,
      image: getLayerRaster(layer.id)?.toDataURL('image/png') ?? '',
      strokeHistory: serializeLayerStrokeHistory(layer.id) ?? undefined,
      textElements: serializeLayerTextElements(layer.id)
    }))
  }

  const content = `${JSON.stringify(project, null, 2)}\n`
  await saveBlobByUserPath(
    `${documentName.value || '画板项目'}.dbp`,
    new Blob([content], { type: 'application/json;charset=utf-8' })
  )
}

async function exportPng() {
  finalizeFloatingSelection()

  renderComposite()
  const canvas = compositeCanvasRef.value
  if (!canvas) {
    return
  }

  const blob = await canvasToBlob(canvas, 'image/png')
  if (!blob) {
    return
  }

  await saveBlobByUserPath(`${documentName.value || '画板作品'}.png`, blob)
}

function escapeXmlAttribute(text: string) {
  return text
    .replace(/&/g, '&amp;')
    .replace(/"/g, '&quot;')
    .replace(/'/g, '&apos;')
    .replace(/</g, '&lt;')
    .replace(/>/g, '&gt;')
}

async function exportSvg() {
  finalizeFloatingSelection()

  const width = canvasWidth.value
  const height = canvasHeight.value

  const lines: string[] = [
    '<?xml version="1.0" encoding="UTF-8"?>',
    `<svg xmlns="http://www.w3.org/2000/svg" width="${width}" height="${height}" viewBox="0 0 ${width} ${height}">`,
    `<rect x="0" y="0" width="${width}" height="${height}" fill="#ffffff"/>`
  ]

  for (const layer of layers.value) {
    if (!layer.visible) {
      continue
    }

    const image = createLayerDisplayRaster(layer.id)?.toDataURL('image/png')
    if (!image) {
      continue
    }

    const blend = toCssBlendMode(layer.blendMode)
    lines.push(`<g opacity="${layer.opacity.toFixed(4)}" style="mix-blend-mode:${blend}">`)
    lines.push(`<image href="${escapeXmlAttribute(image)}" x="0" y="0" width="${width}" height="${height}" preserveAspectRatio="none"/>`)
    lines.push('</g>')
  }

  lines.push('</svg>')
  await saveBlobByUserPath(
    `${documentName.value || '画板作品'}.svg`,
    new Blob([lines.join('\n')], { type: 'image/svg+xml;charset=utf-8' })
  )
}

function openNewDocumentDialog() {
  newDocumentForm.name = `未命名 ${Date.now().toString().slice(-4)}`
  newDocumentForm.width = canvasWidth.value
  newDocumentForm.height = canvasHeight.value
  newDocumentForm.backgroundColor = documentBackgroundColor.value
  showNewDocumentDialog.value = true
}

function closeNewDocumentDialog() {
  showNewDocumentDialog.value = false
}

function confirmCreateDocument() {
  clearFloatingSelection()

  const width = clamp(Math.round(newDocumentForm.width || canvasWidth.value), 320, 6000)
  const height = clamp(Math.round(newDocumentForm.height || canvasHeight.value), 240, 6000)
  const name = newDocumentForm.name.trim() || `未命名 ${Date.now().toString().slice(-4)}`
  const backgroundColor = newDocumentForm.backgroundColor || '#ffffff'

  documentName.value = name
  initializeDocument(width, height, backgroundColor)
  showNewDocumentDialog.value = false
}

function handleBrushPresetChange() {
  applyBrushPreset(brushPresetId.value)
}

function handleBrushPresetClick(presetId: BrushPresetId) {
  if (brushPresetId.value === presetId && activeTool.value === presetId) {
    return
  }

  brushPresetId.value = presetId
  handleBrushPresetChange()
}

function applyBrushPreset(presetId: BrushPresetId) {
  finalizeFloatingSelection()

  const preset = brushPresetItems.find((item) => item.id === presetId)
  if (!preset) {
    return
  }

  brushPresetId.value = presetId
  brushName.value = preset.label
  brushColor.value = preset.color
  brushSize.value = preset.size
  brushOpacity.value = preset.opacity

  brushStyle.angle = preset.style.angle
  brushStyle.roundness = preset.style.roundness
  brushStyle.spacing = preset.style.spacing
  brushStyle.hardness = preset.style.hardness
  brushStyle.flow = preset.style.flow
  brushStyle.sizeMode = preset.style.sizeMode
  brushStyle.sizeJitter = preset.style.sizeJitter

  setActiveTool(preset.tool)
}

function handleKeydown(event: KeyboardEvent) {
  const key = event.key.toLowerCase()
  const code = event.code
  const commandPressed = event.ctrlKey || event.metaKey
  const target = event.target as HTMLElement | null
  const isTypingTarget = Boolean(
    target &&
      (target.tagName === 'INPUT' || target.tagName === 'TEXTAREA' || target.tagName === 'SELECT' || target.isContentEditable)
  )

  if (showNewDocumentDialog.value) {
    if (event.key === 'Escape') {
      event.preventDefault()
      closeNewDocumentDialog()
      return
    }

    if (event.key === 'Enter') {
      event.preventDefault()
      confirmCreateDocument()
      return
    }

    return
  }

  if (showHelpDialog.value) {
    if (event.key === 'Escape') {
      event.preventDefault()
      closeHelpDialog()
    }
    return
  }

  if (event.key === 'F1') {
    event.preventDefault()
    if (commandPressed) {
      showAboutDialog()
      return
    }
    if (event.shiftKey) {
      showShortcutTip()
      return
    }
    showUsageTip()
    return
  }

  if (activeMenu.value && event.key === 'Escape') {
    event.preventDefault()
    closeMenu()
    return
  }

  if (textEditor.active) {
    if (event.key === 'Escape') {
      event.preventDefault()
      cancelTextEditor()
      return
    }

    if (commandPressed && event.key === 'Enter') {
      event.preventDefault()
      applyTextEditor()
      return
    }

    if (commandPressed && event.altKey && key === 'arrowup') {
      event.preventDefault()
      adjustTextSize(2)
      focusTextEditor()
      return
    }

    if (commandPressed && event.altKey && key === 'arrowdown') {
      event.preventDefault()
      adjustTextSize(-2)
      focusTextEditor()
      return
    }

    if (commandPressed && !event.altKey && !event.shiftKey && key === 'b') {
      event.preventDefault()
      toggleTextBold()
      focusTextEditor()
      return
    }

    if (commandPressed && !event.altKey && !event.shiftKey && key === 'i') {
      event.preventDefault()
      toggleTextItalic()
      focusTextEditor()
      return
    }
  }

  if (isTypingTarget) {
    return
  }

  if (hasFloatingSelection.value) {
    if (event.key === 'Enter') {
      event.preventDefault()
      commitFloatingSelection(true)
      return
    }

    if (event.key === 'Escape') {
      event.preventDefault()
      clearFloatingSelectionAndRender()
      return
    }
  }

  if (event.code === 'Space') {
    spacePressed.value = true
    return
  }

  if (commandPressed && event.shiftKey && code === 'BracketRight') {
    event.preventDefault()
    rotateActiveLayer(90)
    return
  }

  if (commandPressed && event.shiftKey && code === 'BracketLeft') {
    event.preventDefault()
    rotateActiveLayer(-90)
    return
  }

  if (commandPressed && event.shiftKey && key === 'h') {
    event.preventDefault()
    flipActiveLayer('horizontal')
    return
  }

  if (commandPressed && event.shiftKey && key === 'v') {
    event.preventDefault()
    flipActiveLayer('vertical')
    return
  }

  if (commandPressed && event.shiftKey && key === 'e') {
    event.preventDefault()
    mergeVisibleLayers()
    return
  }

  if (commandPressed && !event.shiftKey && key === 'e') {
    event.preventDefault()
    mergeActiveLayerDown()
    return
  }

  if (commandPressed && event.altKey && key === 'arrowup') {
    event.preventDefault()
    adjustTextSize(2)
    return
  }

  if (commandPressed && event.altKey && key === 'arrowdown') {
    event.preventDefault()
    adjustTextSize(-2)
    return
  }

  if (commandPressed && !event.altKey && !event.shiftKey && key === 'b') {
    event.preventDefault()
    toggleTextBold()
    return
  }

  if (commandPressed && !event.altKey && !event.shiftKey && key === 'i') {
    event.preventDefault()
    toggleTextItalic()
    return
  }

  if (commandPressed && event.shiftKey && code === 'Digit1') {
    event.preventDefault()
    applyGrayscaleFilter()
    return
  }

  if (commandPressed && event.shiftKey && code === 'Digit2') {
    event.preventDefault()
    applySepiaFilter()
    return
  }

  if (commandPressed && event.shiftKey && code === 'Digit3') {
    event.preventDefault()
    applyInvertFilter()
    return
  }

  if (commandPressed && event.shiftKey && code === 'Digit4') {
    event.preventDefault()
    applySoftBlurFilter()
    return
  }

  if (commandPressed && event.shiftKey && code === 'Digit5') {
    event.preventDefault()
    applySharpenFilter()
    return
  }

  if (commandPressed && event.shiftKey && code === 'Digit0') {
    event.preventDefault()
    resetView()
    return
  }

  if (commandPressed && code === 'Backslash') {
    event.preventDefault()
    resetWorkspaceLayout()
    return
  }

  if (commandPressed && (key === '=' || key === '+' || code === 'NumpadAdd')) {
    event.preventDefault()
    zoomIn()
    return
  }

  if (commandPressed && (key === '-' || code === 'NumpadSubtract')) {
    event.preventDefault()
    zoomOut()
    return
  }

  if (commandPressed && !event.shiftKey && code === 'Digit0') {
    event.preventDefault()
    fitCanvasToViewport()
    return
  }

  if (commandPressed && key === 'n') {
    event.preventDefault()
    openNewDocumentDialog()
    return
  }

  if (commandPressed && key === 'o') {
    event.preventDefault()
    void openLocalFile()
    return
  }

  if (commandPressed && key === 's') {
    event.preventDefault()
    void saveProject()
    return
  }

  if (commandPressed && !event.shiftKey && key === 'z') {
    event.preventDefault()
    void undo()
    return
  }

  if ((commandPressed && event.shiftKey && key === 'z') || (commandPressed && key === 'y')) {
    event.preventDefault()
    void redo()
    return
  }

  if (key === 'b') {
    setActiveTool('brush')
    return
  }

  if (key === 'p') {
    setActiveTool('pencil')
    return
  }

  if (key === 'e') {
    setActiveTool('eraser')
    return
  }

  if (key === 'i') {
    setActiveTool('eyedropper')
    return
  }

  if (key === 'g') {
    setActiveTool('fill')
    return
  }

  if (key === 'l') {
    setActiveTool('lasso')
    return
  }

  if (key === 'u') {
    setActiveTool('shape')
    return
  }

  if (key === 't') {
    setActiveTool('text')
    return
  }

  if (key === 'm') {
    setActiveTool('lasso')
    return
  }

  if (key === 'v') {
    setActiveTool('lasso')
  }
}

function handleKeyup(event: KeyboardEvent) {
  if (event.code === 'Space') {
    spacePressed.value = false
  }
}

function handleResize() {
  fitCanvasToViewport()
}

onMounted(() => {
  applyBrushPreset('brush')
  initializeDocument(canvasWidth.value, canvasHeight.value, documentBackgroundColor.value)
  window.addEventListener('keydown', handleKeydown)
  window.addEventListener('keyup', handleKeyup)
  window.addEventListener('resize', handleResize)
  window.addEventListener('pointerdown', handleGlobalPointerDown)
  window.addEventListener('pointermove', handleWindowPointerMove)
  window.addEventListener('pointerup', handleWindowPointerUp)
  window.addEventListener('pointercancel', handleWindowPointerUp)
})

onBeforeUnmount(() => {
  window.removeEventListener('keydown', handleKeydown)
  window.removeEventListener('keyup', handleKeyup)
  window.removeEventListener('resize', handleResize)
  window.removeEventListener('pointerdown', handleGlobalPointerDown)
  window.removeEventListener('pointermove', handleWindowPointerMove)
  window.removeEventListener('pointerup', handleWindowPointerUp)
  window.removeEventListener('pointercancel', handleWindowPointerUp)
})
</script>

<style scoped>
.ps-app {
  height: 100vh;
  overflow: hidden;
  background: #313338;
  color: #e2e8f0;
  display: flex;
  flex-direction: column;
  font-family: 'Noto Sans SC', 'Source Han Sans SC', 'Alibaba PuHuiTi 3.0', 'MiSans', sans-serif;
}

.svg-defs {
  position: absolute;
  width: 0;
  height: 0;
  overflow: hidden;
}

.hidden-input {
  display: none;
}

.dialog-backdrop {
  position: fixed;
  inset: 0;
  background: rgba(15, 23, 42, 0.5);
  backdrop-filter: blur(2px);
  display: flex;
  align-items: center;
  justify-content: center;
  z-index: 40;
}

.new-doc-dialog {
  width: min(560px, calc(100vw - 32px));
  border: 1px solid #5d636f;
  border-radius: 14px;
  background: #454950;
  box-shadow: 0 30px 45px rgba(0, 0, 0, 0.4);
  padding: 16px;
}

.new-doc-dialog h2 {
  margin: 0 0 12px;
  font-size: 18px;
  color: #f8fafc;
}

.dialog-field {
  display: flex;
  flex-direction: column;
  gap: 6px;
  margin-bottom: 10px;
}

.dialog-field span {
  font-size: 12px;
  color: #e2e8f0;
}

.dialog-size-row {
  display: grid;
  grid-template-columns: repeat(2, minmax(0, 1fr));
  gap: 8px;
}

.dialog-input {
  height: 34px;
  border: 1px solid #6a707d;
  border-radius: 8px;
  background: #565b66;
  color: #f8fafc;
  font-size: 13px;
  padding: 0 10px;
}

.dialog-color {
  width: 100%;
  height: 34px;
  border: 1px solid #6a707d;
  border-radius: 8px;
  background: transparent;
  cursor: pointer;
}

.dialog-actions {
  margin-top: 14px;
  display: flex;
  justify-content: flex-end;
  gap: 8px;
}

.dialog-btn {
  height: 34px;
  border: 1px solid #6a707d;
  border-radius: 8px;
  background: #5a5f69;
  color: #f8fafc;
  font-size: 13px;
  padding: 0 14px;
  cursor: pointer;
}

.dialog-btn-primary {
  border-color: #3b82f6;
  background: #3b82f6;
}

.help-dialog {
  width: min(720px, calc(100vw - 32px));
  max-height: min(80vh, 720px);
  border: 1px solid #5d636f;
  border-radius: 14px;
  background: #454950;
  box-shadow: 0 30px 45px rgba(0, 0, 0, 0.4);
  padding: 14px;
  display: flex;
  flex-direction: column;
  gap: 10px;
}

.help-header {
  display: flex;
  align-items: center;
  justify-content: space-between;
  gap: 10px;
}

.help-header h2 {
  margin: 0;
  font-size: 18px;
  color: #f8fafc;
}

.help-tabs {
  display: flex;
  align-items: center;
  gap: 8px;
}

.help-tab {
  height: 30px;
  border: 1px solid #646975;
  border-radius: 8px;
  background: #555a65;
  color: #e2e8f0;
  font-size: 12px;
  padding: 0 12px;
  cursor: pointer;
}

.help-tab-active {
  border-color: #96c8ff;
  background: #3f6ea9;
  color: #f8fafc;
}

.help-content {
  min-height: 0;
  overflow: auto;
  border: 1px solid #5f6571;
  border-radius: 10px;
  background: #3f434d;
  padding: 10px;
}

.help-about {
  display: flex;
  flex-direction: column;
  gap: 12px;
}

.help-section-card {
  border: 1px solid #5f6571;
  border-radius: 10px;
  background: #4a4f59;
  padding: 12px;
}

.help-section-card + .help-section-card {
  margin-top: 10px;
}

.help-section-header {
  margin-bottom: 10px;
}

.help-section-header h3 {
  margin: 0;
  font-size: 14px;
  color: #f8fafc;
}

.help-section-header p {
  margin: 4px 0 0;
  font-size: 12px;
  line-height: 1.5;
  color: #cbd5e1;
}

.about-hero {
  border: 1px solid #607086;
  border-radius: 12px;
  background: linear-gradient(135deg, rgba(59, 130, 246, 0.22), rgba(14, 165, 233, 0.08));
  padding: 14px;
  display: flex;
  align-items: flex-start;
  justify-content: space-between;
  gap: 12px;
}

.about-kicker {
  margin: 0 0 6px;
  color: #bfdbfe;
  font-size: 11px;
  letter-spacing: 0.08em;
  text-transform: uppercase;
}

.about-hero h3 {
  margin: 0;
  font-size: 20px;
  color: #f8fafc;
}

.about-description {
  margin: 8px 0 0;
  color: #dbeafe;
  font-size: 13px;
  line-height: 1.6;
}

.about-version {
  flex-shrink: 0;
  border: 1px solid rgba(191, 219, 254, 0.32);
  border-radius: 999px;
  background: rgba(15, 23, 42, 0.28);
  color: #eff6ff;
  font-size: 12px;
  font-weight: 600;
  padding: 6px 10px;
}

.about-facts {
  display: grid;
  grid-template-columns: repeat(2, minmax(0, 1fr));
  gap: 10px;
}

.about-fact-card {
  border: 1px solid #5f6571;
  border-radius: 10px;
  background: #4a4f59;
  padding: 10px 12px;
  display: flex;
  flex-direction: column;
  gap: 6px;
}

.about-fact-card span {
  color: #b6bfcc;
  font-size: 11px;
}

.about-fact-card strong {
  color: #f8fafc;
  font-size: 13px;
  line-height: 1.5;
}

.help-shortcut-search {
  display: flex;
  align-items: center;
  gap: 8px;
  margin-bottom: 10px;
}

.help-search-input {
  flex: 1;
  min-width: 0;
  height: 30px;
  border: 1px solid #646975;
  border-radius: 8px;
  background: #555a65;
  color: #f8fafc;
  font-size: 12px;
  padding: 0 10px;
}

.help-search-count {
  color: #cbd5e1;
  font-size: 12px;
  white-space: nowrap;
}

.help-list,
.help-shortcut-list {
  list-style: none;
  margin: 0;
  padding: 0;
  display: flex;
  flex-direction: column;
  gap: 8px;
}

.help-list li {
  border: 1px solid #5f6571;
  border-radius: 8px;
  background: #4d525d;
  color: #e2e8f0;
  font-size: 13px;
  line-height: 1.5;
  padding: 8px 10px;
}

.help-shortcut-item {
  border: 1px solid #5f6571;
  border-radius: 8px;
  background: #4d525d;
  padding: 8px 10px;
  display: grid;
  grid-template-columns: minmax(100px, 170px) minmax(0, 1fr);
  gap: 10px;
  align-items: center;
}

.help-shortcut-item strong {
  color: #bfdbfe;
  font-size: 12px;
}

.help-shortcut-item span {
  color: #e2e8f0;
  font-size: 12px;
}

.help-empty {
  margin: 10px 0 0;
  color: #cbd5e1;
  font-size: 12px;
}

.help-mark {
  background: rgba(250, 204, 21, 0.35);
  color: #fef3c7;
  border-radius: 3px;
  padding: 0 2px;
}

.menu-bar {
  height: 34px;
  flex-shrink: 0;
  border-bottom: 1px solid #46484d;
  background: #3a3c42;
  position: relative;
  z-index: 30;
  display: flex;
  align-items: center;
  justify-content: space-between;
  gap: 10px;
  padding: 0 10px;
  overflow: visible;
}

.menu-left,
.menu-right {
  display: flex;
  align-items: center;
  gap: 4px;
  flex-wrap: nowrap;
  overflow-x: visible;
  overflow-y: visible;
  min-width: 0;
  scrollbar-width: none;
}

.menu-left {
  flex: 1;
  position: relative;
}

.menu-right {
  flex: 1;
  justify-content: flex-end;
  position: relative;
}

.menu-version {
  flex-shrink: 0;
  border: 1px solid #5f6571;
  border-radius: 999px;
  background: #494d56;
  color: #cbd5e1;
  font-size: 11px;
  line-height: 1;
  padding: 6px 9px;
}

.menu-item,
.menu-action {
  flex-shrink: 0;
  height: 26px;
  border: 1px solid transparent;
  border-radius: 6px;
  padding: 0 9px;
  background: transparent;
  color: #e2e8f0;
  font-size: 12px;
  cursor: pointer;
}

.menu-wrap {
  position: relative;
  flex-shrink: 0;
}

.menu-item-active {
  border-color: #7f8797;
  background: #565c67;
}

.menu-popup {
  position: absolute;
  top: calc(100% + 4px);
  left: 0;
  z-index: 80;
  min-width: 220px;
  border: 1px solid #656c79;
  border-radius: 8px;
  background: #454952;
  box-shadow: 0 16px 24px rgba(0, 0, 0, 0.35);
  padding: 5px;
  display: flex;
  flex-direction: column;
  gap: 3px;
}

.menu-popup-item {
  width: 100%;
  height: 30px;
  border: 1px solid transparent;
  border-radius: 6px;
  background: transparent;
  color: #e2e8f0;
  padding: 0 9px;
  font-size: 12px;
  display: flex;
  align-items: center;
  justify-content: space-between;
  gap: 10px;
  cursor: pointer;
}

.menu-popup-item:hover {
  border-color: #6d7481;
  background: #59606c;
}

.menu-popup-item:disabled {
  opacity: 0.45;
  cursor: not-allowed;
}

.menu-popup-shortcut {
  color: #b6bfcc;
  font-size: 11px;
}

.menu-item:hover,
.menu-action:hover {
  border-color: #60646e;
  background: #4f535d;
}

.toolbar-bar {
  height: 44px;
  flex-shrink: 0;
  border-bottom: 1px solid #46484d;
  background: #3b3f47;
  display: flex;
  align-items: center;
  gap: 10px;
  flex-wrap: nowrap;
  overflow-x: auto;
  overflow-y: hidden;
  white-space: nowrap;
  padding: 6px 10px;
}

.toolbar-group {
  display: inline-flex;
  align-items: center;
  gap: 8px;
  flex-shrink: 0;
}

.toolbar-label {
  font-size: 12px;
  color: #e2e8f0;
}

.toolbar-chip {
  height: 26px;
  border: 1px solid #666b76;
  border-radius: 999px;
  background: #4f545d;
  color: #f8fafc;
  padding: 0 10px;
  display: inline-flex;
  align-items: center;
  font-size: 12px;
}

.toolbar-select,
.toolbar-action,
.toolbar-zoom {
  height: 28px;
  border: 1px solid #5c606b;
  border-radius: 6px;
  background: #50545d;
  color: #f8fafc;
  font-size: 12px;
  padding: 0 9px;
}

.toolbar-select {
  min-width: 132px;
}

.toolbar-select-short {
  min-width: 118px;
}

.toolbar-toggle {
  height: 28px;
  border: 1px solid #5c606b;
  border-radius: 6px;
  background: #50545d;
  color: #f8fafc;
  font-size: 12px;
  padding: 0 10px;
  cursor: pointer;
}

.toolbar-toggle-active {
  border-color: #96c8ff;
  background: #3f6ea9;
}

.toolbar-action,
.toolbar-zoom {
  flex-shrink: 0;
  cursor: pointer;
}

.toolbar-zoom {
  min-width: 64px;
}

.toolbar-action:disabled {
  cursor: not-allowed;
  opacity: 0.5;
}

.toolbar-range {
  flex-shrink: 0;
  width: 112px;
  accent-color: #60a5fa;
}

.toolbar-color {
  flex-shrink: 0;
  width: 34px;
  height: 28px;
  border: 1px solid #5c606b;
  border-radius: 6px;
  background: transparent;
  cursor: pointer;
}

.toolbar-number {
  flex-shrink: 0;
  width: 86px;
  height: 28px;
  border: 1px solid #5c606b;
  border-radius: 6px;
  background: #50545d;
  color: #f8fafc;
  font-size: 12px;
  padding: 0 8px;
}

.toolbar-size-group {
  gap: 6px;
}

.toolbar-multiply {
  font-size: 12px;
  color: #cbd5e1;
}

.toolbar-hint {
  max-width: 360px;
}

.toolbar-hint-text {
  max-width: 300px;
  color: #dbeafe;
  font-size: 12px;
  overflow: hidden;
  text-overflow: ellipsis;
  white-space: nowrap;
}

.toolbar-check {
  display: inline-flex;
  align-items: center;
  gap: 6px;
  font-size: 12px;
  flex-shrink: 0;
}

.brush-type-strip {
  display: inline-flex;
  align-items: center;
  gap: 6px;
}

.brush-type-btn {
  height: 28px;
  border: 1px solid #5c606b;
  border-radius: 999px;
  background: #50545d;
  color: #f8fafc;
  font-size: 12px;
  padding: 0 12px;
  cursor: pointer;
}

.brush-type-btn:hover {
  background: #5d6470;
}

.brush-type-btn-active {
  border-color: #96c8ff;
  background: #3f6ea9;
}

.shape-strip {
  max-width: min(70vw, 660px);
  display: inline-flex;
  align-items: center;
  gap: 6px;
  overflow-x: auto;
  overflow-y: hidden;
  padding-bottom: 2px;
}

.shape-strip-btn {
  width: 28px;
  height: 28px;
  border: 1px solid #5c606b;
  border-radius: 6px;
  background: #50545d;
  color: #f8fafc;
  display: inline-flex;
  align-items: center;
  justify-content: center;
  flex-shrink: 0;
  cursor: pointer;
}

.shape-strip-btn:hover {
  background: #5d6470;
}

.shape-strip-btn-active {
  border-color: #96c8ff;
  background: #3f6ea9;
}

.shape-strip-icon {
  width: 16px;
  height: 16px;
  fill: none;
  stroke: currentColor;
}

.workspace {
  flex: 1;
  height: 100%;
  min-height: 0;
  overflow: hidden;
  display: grid;
  grid-template-columns: 80px minmax(0, 1fr) 320px;
}

.workspace-no-side {
  grid-template-columns: 80px minmax(0, 1fr);
}

.tools-panel {
  min-height: 0;
  border-right: 1px solid #45474d;
  background: #3b3d43;
  padding: 9px 7px;
  display: flex;
  flex-direction: column;
  gap: 8px;
  overflow: auto;
}

.tool-btn {
  width: 64px;
  min-height: 58px;
  border: 1px solid #555962;
  border-radius: 9px;
  background: #4a4d55;
  color: #e2e8f0;
  display: inline-flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  gap: 4px;
  cursor: pointer;
}

.tool-btn:hover {
  background: #5a5f69;
}

.tool-btn-active {
  border-color: #90c2ff;
  background: #3f6ea9;
}

.tool-icon {
  width: 18px;
  height: 18px;
  fill: currentColor;
  stroke: currentColor;
}

.tool-icon-image {
  width: 20px;
  height: 20px;
  object-fit: contain;
}

.tool-text {
  font-size: 11px;
  line-height: 1;
  color: #e2e8f0;
}

.canvas-panel {
  min-width: 0;
  min-height: 0;
  background: #2a2d31;
  display: flex;
  flex-direction: column;
}

.canvas-top-status {
  min-height: 32px;
  flex-shrink: 0;
  border-bottom: 1px solid #43464d;
  display: flex;
  align-items: center;
  gap: 12px;
  padding: 0 12px;
  font-size: 12px;
  color: #cbd5e1;
  flex-wrap: nowrap;
  overflow-x: auto;
  overflow-y: hidden;
  white-space: nowrap;
}

.canvas-top-status span {
  flex-shrink: 0;
}

.canvas-viewport {
  flex: 1;
  min-height: 0;
  position: relative;
  overflow: hidden;
  background: linear-gradient(180deg, #24262b 0%, #1f2126 100%);
}

.canvas-stage {
  position: absolute;
  left: 0;
  top: 0;
  transform-origin: top left;
  border: 1px solid #575d66;
  box-shadow: 0 24px 40px rgba(0, 0, 0, 0.4);
  background: #fff;
  touch-action: none;
  user-select: none;
  cursor: crosshair;
}

.stage-canvas {
  position: absolute;
  inset: 0;
  width: 100%;
  height: 100%;
}

.stage-preview {
  pointer-events: none;
}

.canvas-text-editor {
  position: absolute;
  inset: 0;
  pointer-events: none;
}

.canvas-text-editor-input {
  position: absolute;
  padding: 8px 10px;
  border: 1px dashed rgba(96, 165, 250, 0.95);
  border-radius: 6px;
  background: rgba(255, 255, 255, 0.96);
  box-shadow: 0 0 0 1px rgba(255, 255, 255, 0.6), 0 10px 22px rgba(15, 23, 42, 0.14);
  resize: none;
  overflow: hidden;
  outline: none;
  pointer-events: auto;
}

.canvas-text-editor-toolbar {
  position: absolute;
  display: inline-flex;
  align-items: center;
  gap: 8px;
  padding: 6px 8px;
  border: 1px solid rgba(71, 85, 105, 0.35);
  border-radius: 999px;
  background: rgba(15, 23, 42, 0.92);
  box-shadow: 0 12px 20px rgba(15, 23, 42, 0.22);
  pointer-events: auto;
}

.canvas-text-editor-btn {
  height: 26px;
  border: 1px solid rgba(148, 163, 184, 0.35);
  border-radius: 999px;
  background: rgba(51, 65, 85, 0.9);
  color: #e2e8f0;
  font-size: 12px;
  padding: 0 10px;
  cursor: pointer;
}

.canvas-text-editor-btn-primary {
  border-color: rgba(96, 165, 250, 0.85);
  background: rgba(37, 99, 235, 0.95);
}

.canvas-text-editor-hint {
  color: rgba(226, 232, 240, 0.8);
  font-size: 11px;
  white-space: nowrap;
}

.canvas-text-editor-resize {
  position: absolute;
  width: 16px;
  height: 16px;
  border: 1px solid rgba(96, 165, 250, 0.95);
  border-radius: 4px;
  background: rgba(255, 255, 255, 0.96);
  box-shadow: 0 6px 12px rgba(15, 23, 42, 0.16);
  cursor: nwse-resize;
  pointer-events: auto;
}

.side-panel {
  min-height: 0;
  border-left: 1px solid #45474d;
  background: #3a3d45;
  padding: 10px;
  overflow: auto;
  display: flex;
  flex-direction: column;
  gap: 10px;
}

.menu-left::-webkit-scrollbar,
.menu-right::-webkit-scrollbar,
.toolbar-bar::-webkit-scrollbar,
.shape-strip::-webkit-scrollbar,
.canvas-top-status::-webkit-scrollbar {
  height: 6px;
}

.menu-left::-webkit-scrollbar-thumb,
.menu-right::-webkit-scrollbar-thumb,
.toolbar-bar::-webkit-scrollbar-thumb,
.shape-strip::-webkit-scrollbar-thumb,
.canvas-top-status::-webkit-scrollbar-thumb {
  background: #5f6470;
  border-radius: 999px;
}

.panel-card {
  border: 1px solid #555962;
  border-radius: 10px;
  background: #464a53;
  padding: 10px;
}

.panel-card h3 {
  margin: 0 0 8px;
  font-size: 13px;
  font-weight: 700;
  color: #f8fafc;
}

.color-row {
  display: flex;
  align-items: center;
  gap: 8px;
}

.panel-color {
  width: 72px;
  height: 34px;
  border: 1px solid #5c606b;
  border-radius: 6px;
  background: transparent;
  cursor: pointer;
}

.panel-btn {
  height: 30px;
  border: 1px solid #646975;
  border-radius: 7px;
  background: #5a5f69;
  color: #f1f5f9;
  font-size: 12px;
  padding: 0 10px;
  cursor: pointer;
}

.panel-btn:disabled {
  opacity: 0.45;
  cursor: not-allowed;
}

.swatch-grid {
  margin-top: 10px;
  display: grid;
  grid-template-columns: repeat(9, minmax(0, 1fr));
  gap: 6px;
}

.swatch {
  height: 18px;
  border-radius: 4px;
  border: 1px solid #6a6f7a;
  cursor: pointer;
}

.field {
  display: flex;
  flex-direction: column;
  gap: 6px;
  margin-bottom: 8px;
}

.field span {
  font-size: 12px;
  color: #e2e8f0;
}

.field-input,
.field-select {
  width: 100%;
  height: 30px;
  border: 1px solid #646975;
  border-radius: 7px;
  background: #565b66;
  color: #f8fafc;
  padding: 0 9px;
  font-size: 12px;
}

.field-range {
  width: 100%;
  accent-color: #60a5fa;
}

.field-disabled {
  opacity: 0.45;
}

.layer-head {
  display: flex;
  align-items: center;
  justify-content: space-between;
  margin-bottom: 8px;
}

.layer-list {
  max-height: 230px;
  overflow: auto;
  display: flex;
  flex-direction: column;
  gap: 6px;
  margin-bottom: 8px;
}

.layer-row {
  border: 1px solid #5f646f;
  border-radius: 8px;
  background: #565b66;
  overflow: hidden;
}

.layer-row-active {
  border-color: #93c5fd;
  background: #3f5f90;
}

.layer-main {
  width: 100%;
  border: 0;
  background: transparent;
  color: inherit;
  display: flex;
  align-items: center;
  gap: 8px;
  text-align: left;
  padding: 7px;
  cursor: pointer;
}

.layer-thumb {
  width: 52px;
  height: 34px;
  border-radius: 6px;
  border: 1px solid #7c8390;
  object-fit: cover;
}

.layer-thumb-empty {
  width: 52px;
  height: 34px;
  border-radius: 6px;
  border: 1px dashed #7c8390;
  display: inline-flex;
  align-items: center;
  justify-content: center;
  font-size: 11px;
  color: #e2e8f0;
}

.layer-text {
  min-width: 0;
  display: flex;
  flex-direction: column;
  gap: 2px;
  flex: 1;
}

.layer-name {
  font-size: 12px;
  font-weight: 700;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
}

.layer-meta {
  font-size: 11px;
  color: #dbeafe;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
}

.layer-actions {
  display: flex;
  align-items: center;
  justify-content: flex-end;
  gap: 4px;
  padding: 0 7px 7px;
}

.icon-btn {
  width: 26px;
  height: 26px;
  border: 1px solid #707683;
  border-radius: 6px;
  background: #4d525d;
  color: #eef2ff;
  display: inline-flex;
  align-items: center;
  justify-content: center;
  cursor: pointer;
}

.icon-btn svg {
  width: 14px;
  height: 14px;
  fill: currentColor;
  stroke: currentColor;
}

.layer-ops {
  display: grid;
  grid-template-columns: repeat(4, minmax(0, 1fr));
  gap: 6px;
  margin-bottom: 8px;
}

.menu-item:focus-visible,
.menu-action:focus-visible,
.menu-popup-item:focus-visible,
.toolbar-select:focus-visible,
.toolbar-action:focus-visible,
.toolbar-toggle:focus-visible,
.brush-type-btn:focus-visible,
.toolbar-color:focus-visible,
.toolbar-number:focus-visible,
.shape-strip-btn:focus-visible,
.canvas-text-editor-input:focus-visible,
.canvas-text-editor-btn:focus-visible,
.canvas-text-editor-resize:focus-visible,
.dialog-input:focus-visible,
.dialog-color:focus-visible,
.dialog-btn:focus-visible,
.tool-btn:focus-visible,
.panel-btn:focus-visible,
.help-tab:focus-visible,
.help-search-input:focus-visible,
.field-input:focus-visible,
.field-select:focus-visible,
.field-range:focus-visible,
.icon-btn:focus-visible,
.swatch:focus-visible {
  outline: 2px solid rgba(96, 165, 250, 0.65);
  outline-offset: 1px;
}

@media (max-width: 1200px) {
  .workspace {
    grid-template-columns: 72px minmax(0, 1fr) 280px;
  }
}

@media (max-width: 980px) {
  .workspace {
    grid-template-columns: 70px minmax(0, 1fr);
  }

  .workspace-no-side {
    grid-template-columns: 70px minmax(0, 1fr);
  }

  .side-panel {
    display: none;
  }
}

@media (max-width: 760px) {
  .menu-right,
  .toolbar-group strong {
    display: none;
  }

  .menu-left {
    overflow-x: auto;
    scrollbar-width: thin;
  }

  .help-dialog {
    width: calc(100vw - 20px);
    max-height: calc(100vh - 24px);
    padding: 10px;
  }

  .help-tabs {
    flex-wrap: wrap;
  }

  .help-shortcut-item {
    grid-template-columns: 1fr;
    gap: 4px;
  }

  .help-shortcut-search {
    flex-direction: column;
    align-items: stretch;
  }

  .about-hero {
    flex-direction: column;
  }

  .about-facts {
    grid-template-columns: 1fr;
  }

  .help-search-count {
    text-align: right;
  }

  .dialog-size-row {
    grid-template-columns: 1fr;
  }

  .toolbar-bar {
    gap: 8px;
    padding: 6px 8px;
  }

  .toolbar-range {
    width: 80px;
  }
}

@media (prefers-reduced-motion: reduce) {
  * {
    transition: none !important;
    animation: none !important;
  }
}
</style>
