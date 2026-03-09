param(
    [ValidateSet('Debug', 'Release', 'RelWithDebInfo', 'MinSizeRel')]
    [string]$Config = 'Release',
    [string]$BuildDir = (Join-Path $PSScriptRoot '..\build'),
    [string]$VsInstanceId,
    [string[]]$BuildArguments = @()
)

$ErrorActionPreference = 'Stop'

function Get-VsSetupInstance {
    param(
        [string]$InstanceId
    )

    $vswherePath = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
    if (-not (Test-Path $vswherePath -PathType Leaf)) {
        throw "未找到 vswhere.exe: $vswherePath"
    }

    $arguments = @('-format', 'json', '-requires', 'Microsoft.VisualStudio.Component.VC.Tools.x86.x64')
    if ([string]::IsNullOrWhiteSpace($InstanceId)) {
        $arguments += '-latest'
    }
    else {
        $arguments += @('-all', '-prerelease')
    }

    $json = & $vswherePath @arguments
    if (-not $json) {
        throw 'vswhere 未返回任何 Visual Studio 实例信息'
    }

    $instances = $json | ConvertFrom-Json
    if ($instances -isnot [System.Array]) {
        $instances = @($instances)
    }

    if ([string]::IsNullOrWhiteSpace($InstanceId)) {
        $instance = $instances | Select-Object -First 1
    }
    else {
        $instance = $instances | Where-Object { $_.instanceId -eq $InstanceId } | Select-Object -First 1
    }

    if (-not $instance) {
        if ([string]::IsNullOrWhiteSpace($InstanceId)) {
            throw '未找到可用的 Visual Studio 实例'
        }

        throw "未找到 instanceId 为 '$InstanceId' 的 Visual Studio 实例"
    }

    return $instance
}

$instance = Get-VsSetupInstance -InstanceId $VsInstanceId
$devShellModulePath = Join-Path $instance.installationPath 'Common7\Tools\Microsoft.VisualStudio.DevShell.dll'
if (-not (Test-Path $devShellModulePath -PathType Leaf)) {
    throw "未找到 Developer Shell 模块: $devShellModulePath"
}

Import-Module $devShellModulePath
Enter-VsDevShell -VsInstanceId $instance.instanceId -Arch amd64 -HostArch amd64 | Out-Null

if (-not (Get-Command cl -ErrorAction SilentlyContinue)) {
    throw 'Developer Shell 初始化后仍未找到 cl.exe，请检查 Visual Studio C++ 工作负载是否完整'
}

if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    throw 'Developer Shell 初始化后仍未找到 cmake，请确认 CMake 已安装并可用'
}

$resolvedBuildDir = [System.IO.Path]::GetFullPath($BuildDir)
if (-not (Test-Path $resolvedBuildDir -PathType Container)) {
    throw "构建目录不存在: $resolvedBuildDir"
}

Set-Location $resolvedBuildDir

if (-not (Test-Path (Join-Path $resolvedBuildDir 'CMakeCache.txt') -PathType Leaf)) {
    throw "构建目录中缺少 CMakeCache.txt，请先在 $resolvedBuildDir 执行 CMake 配置"
}

Write-Host "[build-desktop-devshell] Using Visual Studio instance: $($instance.instanceId)" -ForegroundColor Cyan
Write-Host "[build-desktop-devshell] Build directory: $resolvedBuildDir" -ForegroundColor Cyan
Write-Host "[build-desktop-devshell] Configuration: $Config" -ForegroundColor Cyan
if ($BuildArguments.Count -gt 0) {
    Write-Host "[build-desktop-devshell] Extra build arguments: $($BuildArguments -join ' ')" -ForegroundColor Cyan
}

& cmake --build . --config $Config @BuildArguments
