#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
TMP_DIR="$REPO_ROOT/tmp"

BACKEND_HOST="127.0.0.1"
BACKEND_PORT="8080"
FRONTEND_HOST="127.0.0.1"
FRONTEND_PORT="3000"
BACKEND_PROFILE="local-it"

NO_BROWSER="false"
SKIP_NPM_INSTALL="false"

while [[ $# -gt 0 ]]; do
  case "$1" in
    --no-browser)
      NO_BROWSER="true"
      shift
      ;;
    --skip-npm-install)
      SKIP_NPM_INSTALL="true"
      shift
      ;;
    --backend-profile)
      BACKEND_PROFILE="$2"
      shift 2
      ;;
    *)
      echo "Unknown option: $1"
      exit 1
      ;;
  esac
done

mkdir -p "$TMP_DIR"

BACKEND_LOG="$TMP_DIR/start-backend.log"
FRONTEND_LOG="$TMP_DIR/start-frontend.log"
PID_FILE="$TMP_DIR/start-all-pids.json"

wait_url_ready() {
  local name="$1"
  local url="$2"
  local max_attempts="${3:-90}"

  for ((i=1; i<=max_attempts; i++)); do
    if curl -sSf "$url" >/dev/null 2>&1; then
      echo "[ok] $name 已就绪: $url"
      return 0
    fi
    sleep 2
  done

  echo "[error] $name 启动超时: $url"
  return 1
}

if [[ -f "$PID_FILE" ]]; then
  bash "$SCRIPT_DIR/stop-all.sh" || true
fi

if [[ "$SKIP_NPM_INSTALL" != "true" ]]; then
  if [[ ! -d "$REPO_ROOT/frontend/node_modules" ]]; then
    echo "[step] 安装前端依赖..."
    (
      cd "$REPO_ROOT/frontend"
      npm install
    )
  else
    echo "[step] 检测到前端依赖已存在，跳过安装。"
  fi
fi

echo "[step] 启动后端服务..."
(
  cd "$REPO_ROOT/drawing-board-backend"
  SPRING_PROFILES_ACTIVE="$BACKEND_PROFILE" nohup ./gradlew :application:bootRun > "$BACKEND_LOG" 2>&1 &
  echo $! > "$TMP_DIR/.backend.pid"
)
BACKEND_PID="$(cat "$TMP_DIR/.backend.pid")"
rm -f "$TMP_DIR/.backend.pid"

echo "[step] 启动前端服务..."
(
  cd "$REPO_ROOT/frontend"
  nohup npm run dev -- --host "$FRONTEND_HOST" --port "$FRONTEND_PORT" > "$FRONTEND_LOG" 2>&1 &
  echo $! > "$TMP_DIR/.frontend.pid"
)
FRONTEND_PID="$(cat "$TMP_DIR/.frontend.pid")"
rm -f "$TMP_DIR/.frontend.pid"

if ! wait_url_ready "后端" "http://${BACKEND_HOST}:${BACKEND_PORT}/actuator/health" 90; then
  kill "$BACKEND_PID" "$FRONTEND_PID" >/dev/null 2>&1 || true
  exit 1
fi

if ! wait_url_ready "前端" "http://${FRONTEND_HOST}:${FRONTEND_PORT}" 90; then
  kill "$BACKEND_PID" "$FRONTEND_PID" >/dev/null 2>&1 || true
  exit 1
fi

cat > "$PID_FILE" <<EOF
{
  "backendPid": $BACKEND_PID,
  "frontendPid": $FRONTEND_PID,
  "backendLog": "$BACKEND_LOG",
  "frontendLog": "$FRONTEND_LOG",
  "startedAt": "$(date -u +"%Y-%m-%dT%H:%M:%SZ")"
}
EOF

if [[ "$NO_BROWSER" != "true" ]]; then
  if command -v xdg-open >/dev/null 2>&1; then
    xdg-open "http://${FRONTEND_HOST}:${FRONTEND_PORT}" >/dev/null 2>&1 || true
  elif command -v open >/dev/null 2>&1; then
    open "http://${FRONTEND_HOST}:${FRONTEND_PORT}" >/dev/null 2>&1 || true
  fi
fi

echo
echo "[ok] 一键启动完成"
echo "前端地址: http://${FRONTEND_HOST}:${FRONTEND_PORT}"
echo "后端健康: http://${BACKEND_HOST}:${BACKEND_PORT}/actuator/health"
echo "后端日志: $BACKEND_LOG"
echo "前端日志: $FRONTEND_LOG"
echo "停止命令: ./scripts/dev/stop-all.sh"
