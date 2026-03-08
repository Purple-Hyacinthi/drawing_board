#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
PID_FILE="$REPO_ROOT/tmp/start-all-pids.json"

if [[ ! -f "$PID_FILE" ]]; then
  echo "[info] 未找到运行中的start-all进程记录。"
  exit 0
fi

BACKEND_PID="$(node -e "const fs=require('fs');const j=JSON.parse(fs.readFileSync(process.argv[1],'utf8'));process.stdout.write(String(j.backendPid||''));" "$PID_FILE")"
FRONTEND_PID="$(node -e "const fs=require('fs');const j=JSON.parse(fs.readFileSync(process.argv[1],'utf8'));process.stdout.write(String(j.frontendPid||''));" "$PID_FILE")"

kill_pid_tree() {
  local pid="$1"
  if [[ -z "$pid" ]]; then
    return 0
  fi

  if command -v taskkill >/dev/null 2>&1; then
    taskkill //PID "$pid" //T //F >/dev/null 2>&1 || true
    return 0
  fi

  kill "$pid" >/dev/null 2>&1 || true
}

if [[ -n "$BACKEND_PID" ]]; then
  kill_pid_tree "$BACKEND_PID"
fi

if [[ -n "$FRONTEND_PID" ]]; then
  kill_pid_tree "$FRONTEND_PID"
fi

if command -v powershell >/dev/null 2>&1; then
  powershell -NoProfile -Command '$ports = @(8080,3000); foreach($port in $ports){ $c = Get-NetTCPConnection -LocalPort $port -State Listen -ErrorAction SilentlyContinue | Select-Object -First 1; if($c){ Stop-Process -Id $c.OwningProcess -Force -ErrorAction SilentlyContinue } }' >/dev/null 2>&1 || true
fi

if command -v lsof >/dev/null 2>&1; then
  for port in 8080 3000; do
    pids="$(lsof -ti tcp:"$port" 2>/dev/null || true)"
    if [[ -n "$pids" ]]; then
      kill $pids >/dev/null 2>&1 || true
    fi
  done
fi

rm -f "$PID_FILE"

echo "[ok] 已停止一键启动脚本拉起的服务进程（若仍存在请手动结束）。"
