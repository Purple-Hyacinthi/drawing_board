# Drawing Board Desktop

## 运行行为

- 默认优先加载应用目录下的 `frontend/index.html`
- 可通过环境变量 `DRAWING_BOARD_FRONTEND_URL` 覆盖为远程地址，便于开发调试

## 本地构建

```bash
mkdir -p build
cd build
cmake ..
cmake --build . --config Release
```

## Windows 安装包

### 前置条件

- Qt 6.7.3 `msvc2019_64`（包含 `qtwebengine` 与 `qtwebchannel`）
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
