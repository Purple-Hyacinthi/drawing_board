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

        <div class="help-content" v-else>
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
            @click.stop="toggleMenu(menu)"
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
              @click="runMenuAction(action)"
            >
              <span>{{ action.label }}</span>
              <span v-if="action.shortcut" class="menu-popup-shortcut">{{ action.shortcut }}</span>
            </button>
          </div>
        </div>
      </div>
      <div class="menu-right">
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
        <span class="toolbar-label">工具预设</span>
        <select v-model="brushPresetId" class="toolbar-select" @change="handleBrushPresetChange">
          <option v-for="preset in brushPresetItems" :key="preset.id" :value="preset.id">{{ preset.label }}</option>
        </select>
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
        <span class="toolbar-label">文字</span>
        <input v-model="textDraft" class="toolbar-text-input" placeholder="输入文字后点击画布" />
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
          @click="setActiveTool(tool.id)"
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
            @pointermove="handlePointerMove"
            @pointerup="handlePointerUp"
            @pointercancel="handlePointerCancel"
            @pointerleave="handlePointerLeave"
          >
            <canvas ref="compositeCanvasRef" class="stage-canvas" :width="canvasWidth" :height="canvasHeight" />
            <canvas ref="previewCanvasRef" class="stage-canvas stage-preview" :width="canvasWidth" :height="canvasHeight" />
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
          <h3>画笔样式</h3>
          <label class="field">
            <span>名称</span>
            <input v-model="brushName" class="field-input" />
          </label>

          <label class="field">
            <span>角度 {{ brushStyle.angle }}°</span>
            <input v-model.number="brushStyle.angle" type="range" min="0" max="180" class="field-range" />
          </label>

          <label class="field">
            <span>圆度 {{ brushStyle.roundness }}%</span>
            <input v-model.number="brushStyle.roundness" type="range" min="10" max="100" class="field-range" />
          </label>

          <label class="field">
            <span>间距 {{ brushStyle.spacing }}%</span>
            <input v-model.number="brushStyle.spacing" type="range" min="1" max="80" class="field-range" />
          </label>

          <label class="field">
            <span>硬度 {{ brushStyle.hardness }}%</span>
            <input v-model.number="brushStyle.hardness" type="range" min="1" max="100" class="field-range" />
          </label>

          <label class="field">
            <span>流量 {{ brushStyle.flow }}%</span>
            <input v-model.number="brushStyle.flow" type="range" min="1" max="100" class="field-range" />
          </label>

          <label class="field">
            <span>大小控制</span>
            <select v-model="brushStyle.sizeMode" class="field-select">
              <option value="fixed">固定</option>
              <option value="random">随机</option>
              <option value="pressure">压力</option>
            </select>
          </label>

          <label class="field" :class="{ 'field-disabled': brushStyle.sizeMode !== 'random' }">
            <span>随机变量 {{ brushStyle.sizeJitter }}%</span>
            <input
              v-model.number="brushStyle.sizeJitter"
              :disabled="brushStyle.sizeMode !== 'random'"
              type="range"
              min="0"
              max="80"
              class="field-range"
            />
          </label>
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

type ToolId = 'select' | 'brush' | 'pencil' | 'ink' | 'eraser' | 'eyedropper' | 'lasso' | 'fill' | 'shape' | 'text'
type SizeMode = 'fixed' | 'random' | 'pressure'
type LayerBlendMode = 'source-over' | 'multiply' | 'screen' | 'overlay' | 'darken' | 'lighten'
type EraserMode = 'normal' | 'stroke'
type SelectionKind = 'rect' | 'lasso'
type HelpTab = 'usage' | 'shortcuts' | 'about'
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
}

interface HistorySnapshot {
  width: number
  height: number
  documentName: string
  activeLayerId: string | null
  layers: LayerSnapshot[]
}

interface ProjectFile {
  version: 1
  width: number
  height: number
  documentName: string
  layers: LayerSnapshot[]
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

type BrushPresetId = 'soft-round' | 'pencil' | 'calligraphy' | 'marker'

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
  { id: 'lasso', label: '套索', iconType: 'image', icon: iconLasso },
  { id: 'brush', label: '画笔', iconType: 'image', icon: iconBrush },
  { id: 'pencil', label: '铅笔', iconType: 'image', icon: iconPencil },
  { id: 'ink', label: '毛笔', iconType: 'image', icon: iconInk },
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
    id: 'soft-round',
    label: '软圆画笔',
    tool: 'brush',
    color: '#101114',
    size: 18,
    opacity: 95,
    style: {
      angle: 0,
      roundness: 100,
      spacing: 12,
      hardness: 78,
      flow: 90,
      sizeMode: 'pressure',
      sizeJitter: 16
    }
  },
  {
    id: 'pencil',
    label: '工程铅笔',
    tool: 'pencil',
    color: '#1f2937',
    size: 6,
    opacity: 100,
    style: {
      angle: 0,
      roundness: 100,
      spacing: 6,
      hardness: 100,
      flow: 100,
      sizeMode: 'fixed',
      sizeJitter: 0
    }
  },
  {
    id: 'calligraphy',
    label: '书法毛笔',
    tool: 'ink',
    color: '#0f172a',
    size: 24,
    opacity: 88,
    style: {
      angle: 38,
      roundness: 42,
      spacing: 18,
      hardness: 86,
      flow: 74,
      sizeMode: 'pressure',
      sizeJitter: 10
    }
  },
  {
    id: 'marker',
    label: '马克笔',
    tool: 'brush',
    color: '#0ea5e9',
    size: 20,
    opacity: 82,
    style: {
      angle: 0,
      roundness: 72,
      spacing: 22,
      hardness: 62,
      flow: 64,
      sizeMode: 'fixed',
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
const brushPresetId = ref<BrushPresetId>('soft-round')
const brushName = ref('软圆画笔')
const brushColor = ref('#101114')
const brushSize = ref(18)
const brushOpacity = ref(95)
const eraserMode = ref<EraserMode>('normal')
const shapeType = ref<ShapeType>('line')
const textDraft = ref('示例文字')
const textStyle = reactive({
  fontFamily: 'Noto Sans SC',
  size: 48,
  color: '#101114',
  bold: false,
  italic: false
})
const filterIntensity = ref(60)
const pressureEnabled = ref(true)
const pressureDetected = ref(false)
const currentPressure = ref(1)

const fontOptions = [
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

const usageTips = [
  '画布移动默认使用鼠标中键拖动，按住空格可临时拖动。',
  '文字工具可用 Ctrl+B 与 Ctrl+I 切换粗体和斜体。',
  '滤镜会作用于当前活动图层，可先用“滤镜强度”调节结果。',
  '图层合并与滤镜操作都会写入历史，可用 Ctrl+Z 撤销。'
] as const

const aboutLines = [
  'Drawing Board Pro',
  '一个支持图层、选区、画笔和滤镜的轻量绘图工具。',
  '当前版本: 1.0.0'
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
  lassoSelecting: false,
  lassoPoints: [] as Point[],
  strokeEraseChanged: false,
  lastStrokeErasePoint: null as Point | null,
  lastPoint: null as Point | null,
  startPoint: null as Point | null,
  lastPressure: 1,
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

const layerRasterMap = new Map<string, HTMLCanvasElement>()
let selectionRaster: HTMLCanvasElement | null = null

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
const showPresetControl = computed(() => activeTool.value === 'brush' || activeTool.value === 'pencil' || activeTool.value === 'ink')
const showColorControl = computed(() => {
  return activeTool.value === 'brush' || activeTool.value === 'pencil' || activeTool.value === 'ink' || activeTool.value === 'shape' || activeTool.value === 'fill'
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

  return activeTool.value === 'brush' || activeTool.value === 'pencil' || activeTool.value === 'ink'
})
const showBrushStylePanel = computed(() => activeTool.value === 'brush' || activeTool.value === 'pencil' || activeTool.value === 'ink')
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
    { key: 'B / P / E / I / G / L / U / T / M / V', description: '快速切换工具' },
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

function createId() {
  if (typeof crypto !== 'undefined' && typeof crypto.randomUUID === 'function') {
    return crypto.randomUUID()
  }

  return `${Date.now()}-${Math.random().toString(36).slice(2, 10)}`
}

function clamp(value: number, min: number, max: number) {
  return Math.min(max, Math.max(min, value))
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

function createLayerRaster(width: number, height: number, fillColor: string | null = null) {
  const canvas = document.createElement('canvas')
  canvas.width = width
  canvas.height = height

  if (fillColor) {
    const context = canvas.getContext('2d')
    if (context) {
      context.save()
      context.fillStyle = fillColor
      context.fillRect(0, 0, width, height)
      context.restore()
    }
  }

  return canvas
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
  return compositeCanvasRef.value?.getContext('2d') ?? null
}

function getPreviewContext() {
  return previewCanvasRef.value?.getContext('2d') ?? null
}

function getLayerRaster(layerId: string) {
  return layerRasterMap.get(layerId) ?? null
}

function getLayerContext(layerId: string) {
  return getLayerRaster(layerId)?.getContext('2d') ?? null
}

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
  const thumbContext = thumbCanvas.getContext('2d')
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
  thumbContext.strokeStyle = '#94a3b8'
  thumbContext.strokeRect(0.5, 0.5, thumbWidth - 1, thumbHeight - 1)
  layer.thumbnail = thumbCanvas.toDataURL('image/png')
}

function refreshAllLayerThumbnails() {
  for (const layer of layers.value) {
    refreshLayerThumbnail(layer.id)
  }
}

function makeSnapshotMarker(snapshot: HistorySnapshot) {
  return [
    snapshot.width,
    snapshot.height,
    snapshot.activeLayerId ?? 'none',
    snapshot.layers
      .map((layer) => `${layer.id}:${layer.visible ? 1 : 0}:${layer.locked ? 1 : 0}:${Math.round(layer.opacity * 100)}:${layer.blendMode}:${layer.image.length}`)
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
      image: getLayerRaster(layer.id)?.toDataURL('image/png') ?? ''
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
  clearFloatingSelection()
  clearPreviewCanvas()

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
        const context = raster.getContext('2d')
        if (context) {
          context.drawImage(image, 0, 0, snapshot.width, snapshot.height)
        }
      } catch {
      }
    }
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

function toCanvasPoint(event: PointerEvent): Point | null {
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
  return tool === 'brush' || tool === 'pencil' || tool === 'ink' || tool === 'eraser'
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

function getBrushRadius(pressure: number, tool: ToolId) {
  let size = brushSize.value

  if (tool === 'pencil') {
    size *= 0.74
  }
  if (tool === 'ink') {
    size *= 1.15
  }

  if (brushStyle.sizeMode === 'pressure' && pressureEnabled.value) {
    size *= 0.35 + pressure * 0.9
  } else if (brushStyle.sizeMode === 'random') {
    const jitter = brushStyle.sizeJitter / 100
    size *= 1 - jitter + Math.random() * jitter * 2
  }

  return Math.max(0.45, size / 2)
}

function getSpacing(tool: ToolId) {
  if (tool === 'pencil') {
    return Math.max(0.8, brushSize.value * 0.05)
  }

  return Math.max(0.8, (brushSize.value * brushStyle.spacing) / 100)
}

function drawBrushStamp(context: CanvasRenderingContext2D, point: Point, pressure: number, tool: ToolId) {
  const radius = getBrushRadius(pressure, tool)
  const roundness = clamp(brushStyle.roundness / 100, 0.1, 1)
  const angle = (brushStyle.angle * Math.PI) / 180

  let alpha = (brushOpacity.value / 100) * (brushStyle.flow / 100)
  if (tool === 'pencil') {
    alpha = brushOpacity.value / 100
  }

  context.save()

  if (tool === 'eraser') {
    context.globalCompositeOperation = 'destination-out'
    context.fillStyle = '#000000'
    context.globalAlpha = clamp(alpha, 0.02, 1)
  } else {
    context.globalCompositeOperation = 'source-over'
    context.fillStyle = brushColor.value
    context.globalAlpha = clamp(alpha, 0.02, 1)
  }

  const hardness = clamp(brushStyle.hardness / 100, 0.03, 1)

  context.translate(point.x, point.y)
  context.rotate(angle)
  context.scale(1, roundness)
  context.beginPath()
  context.arc(0, 0, radius, 0, Math.PI * 2)
  context.fill()

  if (tool !== 'pencil' && hardness < 0.97) {
    context.globalAlpha = clamp(alpha * (1 - hardness) * 0.32, 0.01, 0.22)
    context.beginPath()
    context.arc(0, 0, radius * 1.38, 0, Math.PI * 2)
    context.fill()
  }

  context.restore()
}

function drawBrushSegment(context: CanvasRenderingContext2D, from: Point, to: Point, fromPressure: number, toPressure: number, tool: ToolId) {
  const distance = Math.hypot(to.x - from.x, to.y - from.y)
  if (distance < 0.001) {
    drawBrushStamp(context, to, toPressure, tool)
    return
  }

  const step = getSpacing(tool)
  const count = Math.max(1, Math.ceil(distance / step))
  for (let index = 0; index <= count; index += 1) {
    const t = count === 0 ? 1 : index / count
    const point: Point = {
      x: from.x + (to.x - from.x) * t,
      y: from.y + (to.y - from.y) * t
    }
    const pressure = fromPressure + (toPressure - fromPressure) * t
    drawBrushStamp(context, point, pressure, tool)
  }
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
  return true
}

function drawTextAtPoint(point: Point) {
  const layer = activeLayer.value
  if (!layer || layer.locked) {
    return false
  }

  const context = getLayerContext(layer.id)
  if (!context) {
    return false
  }

  const content = textDraft.value.trim()
  if (!content) {
    return false
  }

  const weight = textStyle.bold ? '700' : '400'
  const italic = textStyle.italic ? 'italic' : 'normal'
  const size = clamp(Math.round(textStyle.size), 8, 360)
  const family = textStyle.fontFamily || 'Noto Sans SC'
  const lines = content.split(/\r?\n/u)
  const lineHeight = Math.max(12, Math.round(size * 1.35))

  context.save()
  context.globalCompositeOperation = 'source-over'
  context.globalAlpha = brushOpacity.value / 100
  context.fillStyle = textStyle.color
  context.textBaseline = 'top'
  context.font = `${italic} ${weight} ${size}px "${family}", "Noto Sans SC", "Microsoft YaHei", sans-serif`

  for (let index = 0; index < lines.length; index += 1) {
    const line = lines[index]
    context.fillText(line || ' ', point.x, point.y + index * lineHeight)
  }

  context.restore()
  return true
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

  const rasterContext = selectionRaster.getContext('2d')
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
      refreshLayerThumbnail(layer.id)
      pushHistorySnapshot()
    }
  }

  clearFloatingSelection()
  clearPreviewCanvas()
  renderComposite()
}

function finalizeFloatingSelection() {
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
  const floatingContext = floating.getContext('2d')
  if (!floatingContext) {
    return false
  }

  floatingContext.putImageData(imageData, 0, 0)
  context.clearRect(rect.x, rect.y, rect.width, rect.height)
  setFloatingSelection(floating, rect, 'rect', [])

  renderComposite()
  return true
}

function beginSelectionBox(point: Point) {
  if (hasFloatingSelection.value) {
    commitFloatingSelection(true)
  }

  drawState.selectingBox = true
  selectionState.boxStartX = point.x
  selectionState.boxStartY = point.y
  selectionState.boxEndX = point.x
  selectionState.boxEndY = point.y
  drawSelectionBoxPreview(buildRectFromPoints(point.x, point.y, point.x, point.y))
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
  const floatingContext = floating.getContext('2d')
  if (!floatingContext) {
    return false
  }

  const maskCanvas = document.createElement('canvas')
  maskCanvas.width = rect.width
  maskCanvas.height = rect.height
  const maskContext = maskCanvas.getContext('2d')
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
  const fringeToleranceSquared = 140 * 140
  const eraseMask = new Uint8Array(width * height)
  const visited = new Uint8Array(width * height)
  const stack: number[] = [startIndex]
  visited[startIndex] = 1

  let changed = false
  while (stack.length > 0) {
    const pixelIndex = stack.pop()
    if (pixelIndex == null) {
      continue
    }

    const offset = pixelIndex * 4
    if (data[offset + 3] <= 2 || colorDistanceSquaredUnpremultiplied(data, offset, seed) > toleranceSquared) {
      continue
    }

    eraseMask[pixelIndex] = 1
    changed = true

    const x = pixelIndex % width
    const y = Math.floor(pixelIndex / width)

    const neighbors = [
      y > 0 ? pixelIndex - width : -1,
      y < height - 1 ? pixelIndex + width : -1,
      x > 0 ? pixelIndex - 1 : -1,
      x < width - 1 ? pixelIndex + 1 : -1,
      y > 0 && x > 0 ? pixelIndex - width - 1 : -1,
      y > 0 && x < width - 1 ? pixelIndex - width + 1 : -1,
      y < height - 1 && x > 0 ? pixelIndex + width - 1 : -1,
      y < height - 1 && x < width - 1 ? pixelIndex + width + 1 : -1
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

    for (let deltaY = -2; deltaY <= 2; deltaY += 1) {
      const nextY = y + deltaY
      if (nextY < 0 || nextY >= height) {
        continue
      }

      for (let deltaX = -2; deltaX <= 2; deltaX += 1) {
        if (deltaX * deltaX + deltaY * deltaY > 4) {
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
        if (closeToSeed && alpha <= 252) {
          data[offset] = 0
          data[offset + 1] = 0
          data[offset + 2] = 0
          data[offset + 3] = 0
        }
      }
    }
  }

  context.putImageData(imageData, 0, 0)
  return true
}

function setActiveTool(tool: ToolId) {
  const previousTool = activeTool.value
  if (hasFloatingSelection.value && previousTool !== tool && tool !== 'select') {
    commitFloatingSelection(true)
  }

  activeTool.value = tool
  if (isBrushTool(tool) || isShapeTool(tool)) {
    lastPaintTool.value = tool
  }
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
  drawState.lassoSelecting = false
  drawState.lassoPoints = []
  drawState.strokeEraseChanged = false
  drawState.lastStrokeErasePoint = null
  drawState.lastPoint = null
  drawState.startPoint = null
}

function handlePointerDown(event: PointerEvent) {
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

  if (activeTool.value === 'select' && hasFloatingSelection.value && isPointInFloatingSelection(point)) {
    drawState.pointerId = event.pointerId
    drawState.drawing = true
    startSelectionMove(point)

    const host = event.currentTarget as HTMLElement | null
    host?.setPointerCapture(event.pointerId)
    return
  }

  if (activeTool.value === 'select') {
    drawState.pointerId = event.pointerId
    drawState.drawing = true
    beginSelectionBox(point)

    const host = event.currentTarget as HTMLElement | null
    host?.setPointerCapture(event.pointerId)
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

  if (activeTool.value === 'text') {
    if (hasFloatingSelection.value) {
      commitFloatingSelection(true)
    }

    const inserted = drawTextAtPoint(point)
    if (inserted) {
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

  drawBrushSegment(context, point, point, pressure, pressure, activeTool.value)
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

  drawBrushSegment(context, from, point, drawState.lastPressure, pressure, activeTool.value)
  drawState.lastPoint = point
  drawState.lastPressure = pressure
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

  if (drawState.lassoSelecting && drawState.pointerId === event.pointerId) {
    const points = [...drawState.lassoPoints]
    if (points.length >= 3) {
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
    const context = raster.getContext('2d')
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
  clearFloatingSelection()

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
  renderComposite()
  refreshLayerThumbnail(layer.id)
  pushHistorySnapshot()
}

function commitLayerMutation(layerId: string, refreshAll = false) {
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

  const source = createLayerRaster(canvasWidth.value, canvasHeight.value)
  const sourceContext = source.getContext('2d')
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

  targetContext.save()
  targetContext.globalAlpha = clamp(sourceLayer.opacity, 0, 1)
  targetContext.globalCompositeOperation = sourceLayer.blendMode
  targetContext.drawImage(sourceRaster, 0, 0)
  targetContext.restore()

  layers.value.splice(index, 1)
  layerRasterMap.delete(sourceLayer.id)
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
    version: 1,
    width,
    height,
    documentName: typeof value.documentName === 'string' && value.documentName.trim() ? value.documentName : '未命名 1',
    layers: value.layers
      .map((layer) => {
        const item = layer as Partial<LayerSnapshot>
        const blend = blendModeOptions.find((mode) => mode.value === item.blendMode)?.value ?? 'source-over'
        return {
          id: typeof item.id === 'string' && item.id ? item.id : createId(),
          name: typeof item.name === 'string' && item.name ? item.name : `图层 ${Math.floor(Math.random() * 100)}`,
          visible: item.visible !== false,
          locked: item.locked === true,
          opacity: clamp(Number(item.opacity ?? 1), 0, 1),
          blendMode: blend,
          image: typeof item.image === 'string' ? item.image : ''
        } as LayerSnapshot
      })
  }
}

async function openProject(project: ProjectFile) {
  clearFloatingSelection()

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
        const context = raster.getContext('2d')
        if (context) {
          context.drawImage(image, 0, 0, canvasWidth.value, canvasHeight.value)
        }
      } catch {
      }
    }
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
    version: 1,
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
      image: getLayerRaster(layer.id)?.toDataURL('image/png') ?? ''
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

    const image = getLayerRaster(layer.id)?.toDataURL('image/png')
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

function applyBrushPreset(presetId: BrushPresetId) {
  finalizeFloatingSelection()

  const preset = brushPresetItems.find((item) => item.id === presetId)
  if (!preset) {
    return
  }

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
    setActiveTool('select')
    return
  }

  if (key === 'v') {
    setActiveTool('select')
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
  applyBrushPreset('soft-round')
  initializeDocument(canvasWidth.value, canvasHeight.value, documentBackgroundColor.value)
  window.addEventListener('keydown', handleKeydown)
  window.addEventListener('keyup', handleKeyup)
  window.addEventListener('resize', handleResize)
  window.addEventListener('pointerdown', handleGlobalPointerDown)
})

onBeforeUnmount(() => {
  window.removeEventListener('keydown', handleKeydown)
  window.removeEventListener('keyup', handleKeyup)
  window.removeEventListener('resize', handleResize)
  window.removeEventListener('pointerdown', handleGlobalPointerDown)
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
  display: flex;
  align-items: center;
  justify-content: space-between;
  gap: 10px;
  padding: 0 10px;
}

.menu-left,
.menu-right {
  display: flex;
  align-items: center;
  gap: 4px;
  flex-wrap: nowrap;
  overflow-x: auto;
  overflow-y: hidden;
  min-width: 0;
  scrollbar-width: thin;
}

.menu-left {
  flex: 1;
}

.menu-right {
  flex: 1;
  justify-content: flex-end;
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
  z-index: 20;
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

.toolbar-text-input {
  width: 170px;
  height: 28px;
  border: 1px solid #5c606b;
  border-radius: 6px;
  background: #50545d;
  color: #f8fafc;
  font-size: 12px;
  padding: 0 8px;
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
.toolbar-text-input:focus-visible,
.toolbar-action:focus-visible,
.toolbar-toggle:focus-visible,
.toolbar-color:focus-visible,
.toolbar-number:focus-visible,
.shape-strip-btn:focus-visible,
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
