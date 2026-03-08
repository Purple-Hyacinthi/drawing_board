@echo off
setlocal

set REPO_ROOT=%~dp0..\..
cd /d "%REPO_ROOT%"

node scripts\integration\local-integration.mjs --auto-start-backend %*
exit /b %ERRORLEVEL%
