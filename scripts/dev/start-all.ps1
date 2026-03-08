param(
    [switch]$NoBrowser,
    [switch]$SkipNpmInstall,
    [string]$BackendProfile = 'local-it',
    [string]$BackendHost = '127.0.0.1',
    [int]$BackendPort = 8080,
    [string]$FrontendHost = '127.0.0.1',
    [int]$FrontendPort = 3000
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$repoRoot = Split-Path -Parent (Split-Path -Parent $scriptDir)
$tmpDir = Join-Path $repoRoot 'tmp'
$backendLog = Join-Path $tmpDir 'start-backend.log'
$backendErrLog = Join-Path $tmpDir 'start-backend.err.log'
$frontendLog = Join-Path $tmpDir 'start-frontend.log'
$frontendErrLog = Join-Path $tmpDir 'start-frontend.err.log'
$pidFile = Join-Path $tmpDir 'start-all-pids.json'

New-Item -ItemType Directory -Path $tmpDir -Force | Out-Null

function Test-UrlReady {
    param(
        [Parameter(Mandatory = $true)][string]$Url
    )

    try {
        $response = Invoke-WebRequest -Uri $Url -UseBasicParsing -TimeoutSec 5
        return $response.StatusCode -ge 200 -and $response.StatusCode -lt 500
    }
    catch {
        return $false
    }
}

function Wait-UrlReady {
    param(
        [Parameter(Mandatory = $true)][string]$Name,
        [Parameter(Mandatory = $true)][string]$Url,
        [int]$MaxAttempts = 90,
        [int]$DelaySeconds = 2
    )

    for ($i = 1; $i -le $MaxAttempts; $i += 1) {
        if (Test-UrlReady -Url $Url) {
            Write-Host "[ok] $Name 已就绪: $Url"
            return
        }

        Start-Sleep -Seconds $DelaySeconds
    }

    throw "$Name 启动超时: $Url"
}

function Stop-ProcessTree {
    param(
        [int]$ProcessId
    )

    if ($ProcessId -le 0) {
        return
    }

    $exists = Get-Process -Id $ProcessId -ErrorAction SilentlyContinue
    if (-not $exists) {
        return
    }

    & taskkill /PID $ProcessId /T /F | Out-Null
}

if (Test-Path $pidFile) {
    try {
        $old = Get-Content -Path $pidFile -Raw | ConvertFrom-Json
        if ($old.backendPid) {
            Stop-ProcessTree -ProcessId ([int]$old.backendPid)
        }
        if ($old.frontendPid) {
            Stop-ProcessTree -ProcessId ([int]$old.frontendPid)
        }
    }
    catch {
    }

    Remove-Item -Path $pidFile -Force -ErrorAction SilentlyContinue
}

if (-not $SkipNpmInstall) {
    $nodeModulesDir = Join-Path $repoRoot 'frontend\node_modules'
    if (-not (Test-Path $nodeModulesDir)) {
        Write-Host '[step] 安装前端依赖...'
        Push-Location (Join-Path $repoRoot 'frontend')
        try {
            & npm install
            if ($LASTEXITCODE -ne 0) {
                throw 'npm install 失败'
            }
        }
        finally {
            Pop-Location
        }
    }
    else {
        Write-Host '[step] 检测到前端依赖已存在，跳过安装。'
    }
}

$backendCommand = "cd /d `"$repoRoot\drawing-board-backend`" && set SPRING_PROFILES_ACTIVE=$BackendProfile && gradlew.bat :application:bootRun"
$frontendCommand = "cd /d `"$repoRoot\frontend`" && npm run dev -- --host $FrontendHost --port $FrontendPort"

Write-Host '[step] 启动后端服务...'
$backendProcess = Start-Process -FilePath 'cmd.exe' -ArgumentList '/d', '/c', $backendCommand -RedirectStandardOutput $backendLog -RedirectStandardError $backendErrLog -PassThru

Write-Host '[step] 启动前端服务...'
$frontendProcess = Start-Process -FilePath 'cmd.exe' -ArgumentList '/d', '/c', $frontendCommand -RedirectStandardOutput $frontendLog -RedirectStandardError $frontendErrLog -PassThru

try {
    Wait-UrlReady -Name '后端' -Url "http://$BackendHost`:$BackendPort/actuator/health"
    Wait-UrlReady -Name '前端' -Url "http://$FrontendHost`:$FrontendPort"
}
catch {
    Stop-ProcessTree -ProcessId $backendProcess.Id
    Stop-ProcessTree -ProcessId $frontendProcess.Id
    throw
}

$pidContent = @{
    backendPid = $backendProcess.Id
    frontendPid = $frontendProcess.Id
    backendLog = $backendLog
    backendErrLog = $backendErrLog
    frontendLog = $frontendLog
    frontendErrLog = $frontendErrLog
    startedAt = (Get-Date).ToString('o')
} | ConvertTo-Json

Set-Content -Path $pidFile -Value $pidContent -Encoding UTF8

if (-not $NoBrowser) {
    Start-Process "http://$FrontendHost`:$FrontendPort"
}

Write-Host ''
Write-Host '[ok] 一键启动完成'
Write-Host "前端地址: http://$FrontendHost`:$FrontendPort"
Write-Host "后端健康: http://$BackendHost`:$BackendPort/actuator/health"
Write-Host "后端日志: $backendLog"
Write-Host "后端错误日志: $backendErrLog"
Write-Host "前端日志: $frontendLog"
Write-Host "前端错误日志: $frontendErrLog"
Write-Host "停止命令: ./scripts/dev/stop-all.ps1"
