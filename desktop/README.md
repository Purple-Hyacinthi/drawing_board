# Drawing Board Desktop

## 运行行为

- 桌面端已完全切换为原生 Qt Widgets，不再依赖 `frontend/index.html`
- 中央视图、工具、图层、文件与导出链路均在桌面端原生实现

## 本地构建

```bash
mkdir -p build
cd build
cmake ..
```

Windows 下推荐直接使用仓库内脚本自动进入 Visual Studio Developer Shell 后再构建：

```bash
cd desktop
npm run build:desktop
```

等价 PowerShell 命令：

```powershell
powershell -ExecutionPolicy Bypass -File desktop/scripts/build-desktop-devshell.ps1
```

如果直接执行 `cmake --build . --config Release`，可能因为未加载 MSVC Developer Shell 环境而报错找不到标准库头（例如 `type_traits`）。

## Windows 安装包

### 前置条件

- Qt 6.7.3 `msvc2019_64`
- Inno Setup 6

### 一键生成

```bash
cd desktop
npm run build:windows-installer
```

产物输出：

- `desktop/release/artifacts/DrawingBoardDesktop-windows-x64.zip`
- `desktop/release/artifacts/DrawingBoardPro-Setup-<version>.exe`

可选参数（PowerShell）：

```powershell
powershell -ExecutionPolicy Bypass -File desktop/scripts/build-windows-installer.ps1 `
  -QtRoot "C:\path\to\Qt\6.7.3\msvc2019_64" `
  -InnoCompiler "C:\path\to\ISCC.exe" `
  -Version "1.0.0"
```

## 发布签名 Ed25519

签名流程借鉴 `agentic-web` 的发布资产签名设计，适用于跨平台产物完整性校验。

### 1 生成签名密钥

```bash
cd desktop
npm run sign:keygen
```

命令会打印 `DRAWING_BOARD_RELEASE_PUBLIC_KEY`，请保存到 CI secret。

### 2 放置发布产物

将构建产物放入以下路径（可按需调整 `release/release-manifest.json`）：

- `release/artifacts/DrawingBoardDesktop-windows-x64.zip`
- `release/artifacts/DrawingBoardDesktop-macos-x64.tar.gz`
- `release/artifacts/DrawingBoardDesktop-linux-x64.tar.gz`

### 3 生成签名并校验

```bash
cd desktop
DRAWING_BOARD_RELEASE_PRIVATE_KEY_FILE=release/keys/private.pem \
DRAWING_BOARD_RELEASE_PUBLIC_KEY=<base64-public-key-from-keygen> \
npm run release:prepare -- --strict
```

该命令会：

1. 计算每个产物 `sha256`
2. 生成 `*.sig` 签名文件
3. 校验签名与清单一致性
