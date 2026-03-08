# Drawing Board Pro - 部署指南

## 概述

本文档提供Drawing Board Pro应用的生产环境部署指南。支持多种部署方式：
1. **传统部署** - 直接在服务器上部署
2. **Docker部署** - 使用容器化部署
3. **Kubernetes部署** - 云原生部署
4. **桌面应用部署** - 各平台桌面应用打包

## 1. 系统要求

### 1.1 服务器要求
- **操作系统**: Linux (Ubuntu 22.04+, CentOS 8+), Windows Server 2019+, macOS 12+
- **CPU**: 2核以上 (推荐4核)
- **内存**: 4GB以上 (推荐8GB)
- **存储**: 50GB以上可用空间
- **网络**: 公网IP，开放80/443端口

### 1.2 软件依赖
- **Java**: OpenJDK 21
- **Node.js**: 20+ (仅前端构建需要)
- **PostgreSQL**: 15+
- **Redis**: 7+ (可选，用于缓存)
- **Nginx**: 1.20+ (反向代理)
- **Docker**: 20.10+ (容器化部署)

## 2. 环境配置

### 2.1 环境变量
创建环境配置文件 `.env.production`:

```bash
# 应用配置
APP_NAME="Drawing Board Pro"
APP_ENV=production
APP_DEBUG=false

# 数据库配置
DB_HOST=localhost
DB_PORT=5432
DB_NAME=drawing_board_prod
DB_USER=drawing_board_user
DB_PASSWORD=<change-this-database-password>

# JWT配置
JWT_SECRET=<generate-a-random-secret-at-least-32-chars>
JWT_EXPIRATION=86400
JWT_REFRESH_EXPIRATION=604800

# 存储配置
STORAGE_TYPE=local # local, s3, azure
STORAGE_PATH=/var/lib/drawing-board/uploads
STORAGE_MAX_SIZE=104857600 # 100MB

# 邮件配置 (可选)
SMTP_HOST=smtp.gmail.com
SMTP_PORT=587
SMTP_USERNAME=smtp-user@example.com
SMTP_PASSWORD=<smtp-app-password>
SMTP_FROM=noreply@drawingboard.com

# 前端配置
VITE_API_BASE_URL=https://api.drawing-board.example.com
VITE_APP_NAME=Drawing Board Pro
```

### 2.2 安全配置
```bash
# 生成安全的JWT密钥
openssl rand -base64 64 | tr -d '\n' | head -c 64

# 生成数据库密码
openssl rand -base64 32
```

## 3. 数据库部署

### 3.1 PostgreSQL安装与配置
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install postgresql-15 postgresql-contrib-15

# CentOS/RHEL
sudo dnf install postgresql15-server postgresql15-contrib
sudo /usr/pgsql-15/bin/postgresql-15-setup initdb
sudo systemctl enable postgresql-15
sudo systemctl start postgresql-15
```

### 3.2 数据库初始化
```sql
-- 创建数据库和用户
CREATE DATABASE drawing_board_prod;
CREATE USER drawing_board_user WITH ENCRYPTED PASSWORD '<change-this-database-password>';
GRANT ALL PRIVILEGES ON DATABASE drawing_board_prod TO drawing_board_user;

-- 连接数据库
\c drawing_board_prod

-- 创建扩展
CREATE EXTENSION IF NOT EXISTS "uuid-ossp";
CREATE EXTENSION IF NOT EXISTS "pgcrypto";

-- 设置连接参数
ALTER DATABASE drawing_board_prod SET timezone TO 'UTC';
ALTER DATABASE drawing_board_prod SET default_transaction_isolation TO 'read committed';
```

### 3.3 数据库优化
```bash
# 调整PostgreSQL配置 (postgresql.conf)
shared_buffers = 1GB          # 25% of RAM
effective_cache_size = 3GB    # 75% of RAM
work_mem = 64MB
maintenance_work_mem = 256MB
max_connections = 200
wal_level = replica
max_wal_size = 2GB
min_wal_size = 1GB

# 重启PostgreSQL
sudo systemctl restart postgresql-15
```

## 4. 应用部署

### 4.1 传统部署 (直接部署)

#### 后端部署
```bash
# 克隆代码
 git clone https://github.com/Purple-Hyacinthi/drawing_board.git
 cd drawing_board

# 构建后端
cd drawing-board-backend
./gradlew clean build -x test
cd ..

# 创建部署目录
sudo mkdir -p /opt/drawing-board
sudo cp drawing-board-backend/application/build/libs/drawing-board-backend.jar /opt/drawing-board/
sudo cp .env.production /opt/drawing-board/.env

# 创建系统服务
sudo tee /etc/systemd/system/drawing-board.service << EOF
[Unit]
Description=Drawing Board Pro Backend
After=network.target postgresql.service

[Service]
User=drawing-board
Group=drawing-board
WorkingDirectory=/opt/drawing-board
EnvironmentFile=/opt/drawing-board/.env
ExecStart=/usr/bin/java -jar -Xmx2g -Xms512m drawing-board-backend.jar
SuccessExitStatus=143
Restart=always
RestartSec=10

[Install]
WantedBy=multi-user.target
EOF

# 创建应用用户
sudo useradd -r -s /bin/false drawing-board
sudo chown -R drawing-board:drawing-board /opt/drawing-board

# 启动服务
sudo systemctl daemon-reload
sudo systemctl enable drawing-board
sudo systemctl start drawing-board
sudo systemctl status drawing-board
```

#### 前端部署
```bash
# 构建前端
cd frontend
npm ci
npm run build

# 部署到Nginx
sudo mkdir -p /var/www/drawing-board
sudo cp -r dist/* /var/www/drawing-board/

# 配置Nginx
sudo tee /etc/nginx/sites-available/drawing-board << EOF
server {
    listen 80;
    server_name drawing-board.example.com;
    root /var/www/drawing-board;
    index index.html;

    # 启用gzip压缩
    gzip on;
    gzip_vary on;
    gzip_min_length 1024;
    gzip_types text/plain text/css text/xml text/javascript application/javascript application/xml+rss application/json;

    # 安全头
    add_header X-Frame-Options "SAMEORIGIN" always;
    add_header X-Content-Type-Options "nosniff" always;
    add_header X-XSS-Protection "1; mode=block" always;

    # 静态资源缓存
    location /assets/ {
        expires 1y;
        add_header Cache-Control "public, immutable";
    }

    # 单页应用路由
    location / {
        try_files \$uri \$uri/ /index.html;
    }

    # API反向代理
    location /api/ {
        proxy_pass http://localhost:8080;
        proxy_set_header Host \$host;
        proxy_set_header X-Real-IP \$remote_addr;
        proxy_set_header X-Forwarded-For \$proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto \$scheme;
    }
}
EOF

# 启用站点
sudo ln -s /etc/nginx/sites-available/drawing-board /etc/nginx/sites-enabled/
sudo nginx -t
sudo systemctl reload nginx
```

### 4.2 Docker部署

#### Docker Compose部署
```yaml
# docker-compose.production.yml
version: '3.8'

services:
  postgres:
    image: postgres:15-alpine
    container_name: drawing-board-db-prod
    environment:
      POSTGRES_DB: drawing_board_prod
      POSTGRES_USER: drawing_board_user
      POSTGRES_PASSWORD: ${DB_PASSWORD}
    volumes:
      - postgres_data:/var/lib/postgresql/data
      - ./database/backup:/backup
    command: >
      postgres
      -c max_connections=200
      -c shared_buffers=1GB
      -c effective_cache_size=3GB
    restart: always
    healthcheck:
      test: ["CMD-SHELL", "pg_isready -U drawing_board_user"]
      interval: 30s
      timeout: 10s
      retries: 3

  redis:
    image: redis:7-alpine
    container_name: drawing-board-cache-prod
    command: redis-server --appendonly yes --requirepass ${REDIS_PASSWORD}
    volumes:
      - redis_data:/data
    restart: always

  backend:
    build:
      context: ./drawing-board-backend
      dockerfile: Dockerfile.production
    container_name: drawing-board-backend-prod
    depends_on:
      postgres:
        condition: service_healthy
    environment:
      SPRING_PROFILES_ACTIVE: production
      DB_HOST: postgres
      DB_PORT: 5432
      DB_NAME: drawing_board_prod
      DB_USER: drawing_board_user
      DB_PASSWORD: ${DB_PASSWORD}
      REDIS_HOST: redis
      REDIS_PORT: 6379
      REDIS_PASSWORD: ${REDIS_PASSWORD}
    ports:
      - "8080:8080"
    restart: always
    healthcheck:
      test: ["CMD", "curl", "-f", "http://localhost:8080/actuator/health"]
      interval: 30s
      timeout: 10s
      retries: 3

  frontend:
    build:
      context: ./frontend
      dockerfile: Dockerfile.production
    container_name: drawing-board-frontend-prod
    environment:
      NODE_ENV: production
      VITE_API_BASE_URL: /api
    ports:
      - "3000:80"
    depends_on:
      - backend
    restart: always

  nginx:
    image: nginx:alpine
    container_name: drawing-board-nginx-prod
    ports:
      - "80:80"
      - "443:443"
    volumes:
      - ./nginx/production.conf:/etc/nginx/nginx.conf
      - ./frontend/dist:/usr/share/nginx/html
      - ./ssl:/etc/nginx/ssl:ro
    depends_on:
      - frontend
      - backend
    restart: always

volumes:
  postgres_data:
  redis_data:
```

#### 部署命令
```bash
# 准备环境变量
cp .env.example .env.production
# 编辑 .env.production 文件

# 构建和启动
docker-compose -f docker-compose.production.yml build
docker-compose -f docker-compose.production.yml up -d

# 查看日志
docker-compose -f docker-compose.production.yml logs -f

# 停止服务
docker-compose -f docker-compose.production.yml down
```

### 4.3 Kubernetes部署

#### 命名空间配置
```yaml
# k8s/namespace.yaml
apiVersion: v1
kind: Namespace
metadata:
  name: drawing-board
  labels:
    name: drawing-board
```

#### PostgreSQL StatefulSet
```yaml
# k8s/postgres-statefulset.yaml
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: postgres
  namespace: drawing-board
spec:
  serviceName: postgres
  replicas: 1
  selector:
    matchLabels:
      app: postgres
  template:
    metadata:
      labels:
        app: postgres
    spec:
      containers:
      - name: postgres
        image: postgres:15-alpine
        env:
        - name: POSTGRES_DB
          valueFrom:
            secretKeyRef:
              name: drawing-board-secrets
              key: db-name
        - name: POSTGRES_USER
          valueFrom:
            secretKeyRef:
              name: drawing-board-secrets
              key: db-user
        - name: POSTGRES_PASSWORD
          valueFrom:
            secretKeyRef:
              name: drawing-board-secrets
              key: db-password
        ports:
        - containerPort: 5432
        volumeMounts:
        - name: postgres-data
          mountPath: /var/lib/postgresql/data
        resources:
          requests:
            memory: "1Gi"
            cpu: "500m"
          limits:
            memory: "2Gi"
            cpu: "1"
  volumeClaimTemplates:
  - metadata:
      name: postgres-data
    spec:
      accessModes: [ "ReadWriteOnce" ]
      resources:
        requests:
          storage: 20Gi
```

#### 后端Deployment
```yaml
# k8s/backend-deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: drawing-board-backend
  namespace: drawing-board
spec:
  replicas: 3
  selector:
    matchLabels:
      app: drawing-board-backend
  template:
    metadata:
      labels:
        app: drawing-board-backend
    spec:
      containers:
      - name: backend
        image: <container-registry>/drawing-board-backend:latest
        envFrom:
        - secretRef:
            name: drawing-board-secrets
        ports:
        - containerPort: 8080
        livenessProbe:
          httpGet:
            path: /actuator/health/liveness
            port: 8080
          initialDelaySeconds: 60
          periodSeconds: 10
        readinessProbe:
          httpGet:
            path: /actuator/health/readiness
            port: 8080
          initialDelaySeconds: 30
          periodSeconds: 5
        resources:
          requests:
            memory: "512Mi"
            cpu: "250m"
          limits:
            memory: "1Gi"
            cpu: "500m"
```

## 5. SSL/TLS配置

### 5.1 使用Let's Encrypt
```bash
# 安装Certbot
sudo apt install certbot python3-certbot-nginx

# 获取证书
sudo certbot --nginx -d drawing-board.example.com -d www.drawing-board.example.com

# 自动续期测试
sudo certbot renew --dry-run
```

### 5.2 Nginx SSL配置
```nginx
server {
    listen 443 ssl http2;
    server_name drawing-board.example.com;

    ssl_certificate /etc/letsencrypt/live/drawing-board.example.com/fullchain.pem;
    ssl_certificate_key /etc/letsencrypt/live/drawing-board.example.com/privkey.pem;
    
    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_ciphers ECDHE-RSA-AES256-GCM-SHA512:DHE-RSA-AES256-GCM-SHA512:ECDHE-RSA-AES256-GCM-SHA384:DHE-RSA-AES256-GCM-SHA384;
    ssl_prefer_server_ciphers off;
    
    ssl_session_cache shared:SSL:10m;
    ssl_session_timeout 10m;
    
    add_header Strict-Transport-Security "max-age=63072000" always;
    add_header X-Frame-Options DENY;
    add_header X-Content-Type-Options nosniff;
    
    # 其他配置...
}
```

## 6. 监控与日志

### 6.1 应用监控
```yaml
# Prometheus配置
spring:
  application:
    name: drawing-board-backend
  boot:
    admin:
      client:
        url: http://localhost:9090
management:
  endpoints:
    web:
      exposure:
        include: "health,info,metrics,prometheus"
  metrics:
    export:
      prometheus:
        enabled: true
  endpoint:
    health:
      show-details: always
```

### 6.2 日志配置
```yaml
# logback-spring.xml
<configuration>
    <property name="LOG_PATH" value="/var/log/drawing-board"/>
    
    <appender name="FILE" class="ch.qos.logback.core.rolling.RollingFileAppender">
        <file>${LOG_PATH}/application.log</file>
        <encoder class="ch.qos.logback.classic.encoder.PatternLayoutEncoder">
            <pattern>%d{yyyy-MM-dd HH:mm:ss.SSS} [%thread] %-5level %logger{36} - %msg%n</pattern>
        </encoder>
        <rollingPolicy class="ch.qos.logback.core.rolling.TimeBasedRollingPolicy">
            <fileNamePattern>${LOG_PATH}/application.%d{yyyy-MM-dd}.log</fileNamePattern>
            <maxHistory>30</maxHistory>
        </rollingPolicy>
    </appender>
    
    <root level="INFO">
        <appender-ref ref="FILE"/>
    </root>
</configuration>
```

## 7. 备份与恢复

### 7.1 数据库备份
```bash
#!/bin/bash
# backup.sh

BACKUP_DIR="/backup"
DATE=$(date +%Y%m%d_%H%M%S)
DB_NAME="drawing_board_prod"

# 创建全量备份
pg_dump -U drawing_board_user -h localhost -Fc $DB_NAME > $BACKUP_DIR/$DB_NAME_$DATE.dump

# 保留最近7天的备份
find $BACKUP_DIR -name "*.dump" -mtime +7 -delete

# 上传到云存储 (可选)
# aws s3 cp $BACKUP_DIR/$DB_NAME_$DATE.dump s3://<backup-bucket>/backups/
```

### 7.2 数据库恢复
```bash
# 停止应用
sudo systemctl stop drawing-board

# 恢复数据库
pg_restore -U drawing_board_user -h localhost -d drawing_board_prod --clean --if-exists backup_file.dump

# 启动应用
sudo systemctl start drawing-board
```

## 8. 性能调优

### 8.1 JVM调优
```bash
# JVM参数建议
JAVA_OPTS="-Xms2g -Xmx4g -XX:+UseG1GC \
-XX:MaxGCPauseMillis=200 \
-XX:ParallelGCThreads=4 \
-XX:ConcGCThreads=2 \
-XX:+HeapDumpOnOutOfMemoryError \
-XX:HeapDumpPath=/var/log/drawing-board/heapdump.hprof \
-XX:+UseStringDeduplication \
-Djava.security.egd=file:/dev/./urandom"
```

### 8.2 连接池配置
```yaml
spring:
  datasource:
    hikari:
      maximum-pool-size: 20
      minimum-idle: 10
      connection-timeout: 30000
      idle-timeout: 600000
      max-lifetime: 1800000
      pool-name: DrawingBoardHikariCP
```

## 9. 故障排除

### 9.1 常见问题
```bash
# 检查服务状态
sudo systemctl status drawing-board
sudo journalctl -u drawing-board -f

# 检查端口占用
sudo netstat -tlnp | grep :8080

# 检查数据库连接
psql -U drawing_board_user -h localhost -d drawing_board_prod -c "\dt"

# 查看应用日志
tail -f /var/log/drawing-board/application.log

# 检查磁盘空间
df -h
du -sh /var/lib/drawing-board/uploads/
```

### 9.2 健康检查端点
```
GET /actuator/health      # 应用健康状态
GET /actuator/info        # 应用信息
GET /actuator/metrics     # 应用指标
GET /actuator/env         # 环境变量
GET /actuator/loggers     # 日志配置
```

## 10. 升级指南

### 10.1 版本升级步骤
1. **备份数据和配置**
2. **停止当前服务**
3. **更新代码和依赖**
4. **运行数据库迁移**
5. **构建新版本**
6. **部署新版本**
7. **验证功能**
8. **回滚计划（如有问题）**

### 10.2 数据库迁移
```bash
# 使用Flyway进行数据库迁移
./gradlew flywayMigrate -Dspring.profiles.active=production

# 验证迁移
./gradlew flywayValidate -Dspring.profiles.active=production

# 修复迁移问题
./gradlew flywayRepair -Dspring.profiles.active=production
```

---

*文档版本: 1.0.0*
*最后更新: 2025-03-05*
