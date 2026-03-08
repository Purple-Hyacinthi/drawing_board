Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$repoRoot = Split-Path -Parent (Split-Path -Parent $scriptDir)
$pidFile = Join-Path $repoRoot 'tmp\start-all-pids.json'

function Stop-ProcessTree {
    param(
        [int]$ProcessId
    )

    if ($ProcessId -le 0) {
        return $false
    }

    $exists = Get-Process -Id $ProcessId -ErrorAction SilentlyContinue
    if (-not $exists) {
        return $false
    }

    & taskkill /PID $ProcessId /T /F | Out-Null
    return $true
}

function Stop-PortOwner {
    param(
        [int]$Port
    )

    $connection = Get-NetTCPConnection -LocalPort $Port -State Listen -ErrorAction SilentlyContinue |
        Select-Object -First 1

    if ($null -eq $connection) {
        return $false
    }

    return Stop-ProcessTree -ProcessId ([int]$connection.OwningProcess)
}

if (-not (Test-Path $pidFile)) {
    Write-Host '[info] 未找到运行中的start-all进程记录。'
    exit 0
}

$pidInfo = Get-Content -Path $pidFile -Raw | ConvertFrom-Json

$backendStopped = $false
$frontendStopped = $false

if ($pidInfo.backendPid) {
    $backendStopped = Stop-ProcessTree -ProcessId ([int]$pidInfo.backendPid)
}

if ($pidInfo.frontendPid) {
    $frontendStopped = Stop-ProcessTree -ProcessId ([int]$pidInfo.frontendPid)
}

$backendStopped = (Stop-PortOwner -Port 8080) -or $backendStopped
$frontendStopped = (Stop-PortOwner -Port 3000) -or $frontendStopped

Remove-Item -Path $pidFile -Force -ErrorAction SilentlyContinue

if ($backendStopped -or $frontendStopped) {
    Write-Host '[ok] 已停止一键启动脚本拉起的服务进程。'
} else {
    Write-Host '[info] 进程已不在运行，仅清理了PID记录文件。'
}
