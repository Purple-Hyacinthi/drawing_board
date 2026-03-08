param(
    [Parameter(ValueFromRemainingArguments = $true)]
    [string[]]$ArgsFromCaller
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$repoRoot = Split-Path -Parent (Split-Path -Parent $scriptDir)

Set-Location $repoRoot

$nodeArgs = @('scripts/integration/local-integration.mjs', '--auto-start-backend')
if ($ArgsFromCaller) {
    $nodeArgs += $ArgsFromCaller
}

& node @nodeArgs

$lastExit = Get-Variable -Name LASTEXITCODE -Scope Global -ErrorAction SilentlyContinue
if ($null -ne $lastExit) {
    exit $global:LASTEXITCODE
}

exit 0
