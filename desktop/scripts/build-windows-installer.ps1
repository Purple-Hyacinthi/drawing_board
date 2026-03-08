param(
  [string]$QtRoot = "",
  [string]$InnoCompiler = "",
  [string]$Version = "1.0.0",
  [switch]$SkipFrontendBuild,
  [switch]$SkipDesktopBuild
)

$ErrorActionPreference = "Stop"

function Write-Step([string]$Message) {
  Write-Host "`n==> $Message" -ForegroundColor Cyan
}

function Assert-Exists([string]$Path, [string]$Name) {
  if (-not (Test-Path $Path)) {
    throw "$Name not found: $Path"
  }
}

function Invoke-DevCmd([string]$VsDevCmd, [string]$CommandLine) {
  $quotedVsDevCmd = '"{0}"' -f $VsDevCmd
  $full = "$quotedVsDevCmd -arch=x64 -host_arch=x64 && $CommandLine"
  cmd.exe /c $full
  if ($LASTEXITCODE -ne 0) {
    throw "Command failed with exit code ${LASTEXITCODE}: $CommandLine"
  }
}

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$desktopRoot = (Resolve-Path (Join-Path $scriptDir "..")).Path
$repoRoot = (Resolve-Path (Join-Path $desktopRoot "..")).Path
$frontendRoot = Join-Path $repoRoot "frontend"
$buildDir = Join-Path $desktopRoot "build"
$releaseRoot = Join-Path $desktopRoot "release"
$appRoot = Join-Path $releaseRoot "windows-app"
$artifactsDir = Join-Path $releaseRoot "artifacts"
$installerScript = Join-Path $releaseRoot "windows-installer.iss"

if ([string]::IsNullOrWhiteSpace($QtRoot)) {
  $QtRoot = Join-Path $repoRoot "Qt\6.7.3\msvc2019_64"
}
$QtRoot = (Resolve-Path $QtRoot).Path

$qtCmake = Join-Path $QtRoot "bin\qt-cmake.bat"
$windeployqt = Join-Path $QtRoot "bin\windeployqt.exe"
Assert-Exists $qtCmake "qt-cmake"
Assert-Exists $windeployqt "windeployqt"

$vsDevCmdCandidates = @(
  (Join-Path $env:ProgramFiles "Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat"),
  (Join-Path $env:ProgramFiles "Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"),
  (Join-Path $env:ProgramFiles "Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat")
)
$vsDevCmd = $vsDevCmdCandidates | Where-Object { Test-Path $_ } | Select-Object -First 1
if (-not $vsDevCmd) {
  throw "VsDevCmd.bat not found. Install Visual Studio Build Tools with C++ workload first."
}

if ([string]::IsNullOrWhiteSpace($InnoCompiler)) {
  $defaultInno = Join-Path $env:LOCALAPPDATA "Programs\Inno Setup 6\ISCC.exe"
  if (Test-Path $defaultInno) {
    $InnoCompiler = $defaultInno
  }
}
if ([string]::IsNullOrWhiteSpace($InnoCompiler)) {
  throw "ISCC.exe not found. Install Inno Setup 6 first."
}
Assert-Exists $InnoCompiler "ISCC.exe"
Assert-Exists $installerScript "Inno Setup script"

if (-not $SkipFrontendBuild) {
  Write-Step "Build frontend"
  Push-Location $frontendRoot
  npm run build
  Pop-Location
}

if (-not $SkipDesktopBuild) {
  if (Test-Path $buildDir) {
    Remove-Item $buildDir -Recurse -Force
  }

  Write-Step "Configure desktop project"
  $qtCmakeCmd = '"{0}" -S "{1}" -B "{2}" -G Ninja -DCMAKE_BUILD_TYPE=Release' -f $qtCmake, $desktopRoot, $buildDir
  Invoke-DevCmd -VsDevCmd $vsDevCmd -CommandLine $qtCmakeCmd

  Write-Step "Build desktop executable"
  $cmakeBuildCmd = 'cmake --build "{0}"' -f $buildDir
  Invoke-DevCmd -VsDevCmd $vsDevCmd -CommandLine $cmakeBuildCmd
}

$desktopExeCandidates = @(
  (Join-Path $buildDir "Release\DrawingBoardDesktop.exe"),
  (Join-Path $buildDir "DrawingBoardDesktop.exe")
)
$desktopExe = $desktopExeCandidates | Where-Object { Test-Path $_ } | Select-Object -First 1
if (-not $desktopExe) {
  throw "DrawingBoardDesktop.exe was not found in build output."
}

Write-Step "Prepare release directory"
if (Test-Path $appRoot) {
  Remove-Item $appRoot -Recurse -Force
}
New-Item -ItemType Directory -Path $appRoot | Out-Null
New-Item -ItemType Directory -Path $artifactsDir -Force | Out-Null

Copy-Item $desktopExe (Join-Path $appRoot "DrawingBoardDesktop.exe") -Force
Copy-Item (Join-Path $frontendRoot "dist") (Join-Path $appRoot "frontend") -Recurse -Force

Write-Step "Deploy Qt runtime files"
Push-Location $appRoot
& $windeployqt ".\DrawingBoardDesktop.exe" --release --compiler-runtime --no-translations
$deployExitCode = $LASTEXITCODE
Pop-Location
if ($deployExitCode -ne 0) {
  throw "windeployqt failed with exit code $deployExitCode"
}

$zipPath = Join-Path $artifactsDir "DrawingBoardDesktop-windows-x64.zip"
if (Test-Path $zipPath) {
  Remove-Item $zipPath -Force
}
Compress-Archive -Path (Join-Path $appRoot "*") -DestinationPath $zipPath -Force

Write-Step "Build installer"
$env:DRAWING_BOARD_APP_VERSION = $Version
Push-Location $releaseRoot
& $InnoCompiler $installerScript
$installerExitCode = $LASTEXITCODE
Pop-Location
if ($installerExitCode -ne 0) {
  throw "ISCC failed with exit code $installerExitCode"
}

$installerPath = Join-Path $artifactsDir ("DrawingBoardPro-Setup-{0}.exe" -f $Version)
if (-not (Test-Path $installerPath)) {
  $latestInstaller = Get-ChildItem -Path $artifactsDir -Filter "DrawingBoardPro-Setup-*.exe" |
    Sort-Object LastWriteTime -Descending |
    Select-Object -First 1

  if (-not $latestInstaller) {
    throw "Installer output not found in $artifactsDir"
  }

  $installerPath = $latestInstaller.FullName
}

Write-Host "`nDone" -ForegroundColor Green
Write-Host "Desktop app directory: $appRoot"
Write-Host "Zip artifact: $zipPath"
Write-Host "Installer: $installerPath"
