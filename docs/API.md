# Drawing Board Pro - API文档

## 概述

Drawing Board Pro 提供RESTful API用于画板应用的前后端交互。所有API均遵循以下规范：

- **基础URL**: `/api/v1`
- **认证**: JWT Bearer Token
- **媒体类型**: `application/json`
- **错误响应**: 统一错误格式
- **版本控制**: URL路径版本控制

## 认证

### JWT认证
所有受保护的API都需要在请求头中包含有效的JWT令牌：

```
Authorization: Bearer <jwt-token>
```

### 刷新令牌
访问令牌过期后，可以使用刷新令牌获取新的访问令牌。

## API端点

### 认证相关

#### 用户注册
```http
POST /api/v1/auth/register
Content-Type: application/json

{
  "username": "string (3-50字符)",
  "email": "string (有效邮箱)",
  "password": "string (最少8字符)"
}
```

**响应**:
```json
{
  "userId": "uuid",
  "username": "string",
  "email": "string",
  "createdAt": "iso8601-timestamp"
}
```

#### 用户登录
```http
POST /api/v1/auth/login
Content-Type: application/json

{
  "email": "string",
  "password": "string"
}
```

**响应**:
```json
{
  "accessToken": "jwt-token",
  "refreshToken": "jwt-refresh-token",
  "expiresIn": 86400,
  "user": {
    "id": "uuid",
    "username": "string",
    "email": "string"
  }
}
```

#### 刷新令牌
```http
POST /api/v1/auth/refresh
Content-Type: application/json

{
  "refreshToken": "jwt-refresh-token"
}
```

**响应**: 同登录响应

### 用户管理

#### 获取当前用户信息
```http
GET /api/v1/users/me
Authorization: Bearer <token>
```

**响应**:
```json
{
  "id": "uuid",
  "username": "string",
  "email": "string",
  "createdAt": "iso8601-timestamp",
  "updatedAt": "iso8601-timestamp"
}
```

#### 更新用户信息
```http
PUT /api/v1/users/me
Authorization: Bearer <token>
Content-Type: application/json

{
  "username": "string (可选)",
  "email": "string (可选)"
}
```

### 画布管理

#### 获取画布列表
```http
GET /api/v1/canvases
Authorization: Bearer <token>
Query Parameters:
  page: integer (可选, 默认0)
  size: integer (可选, 默认20)
  sort: string (可选, 例如: "createdAt,desc")
```

**响应**:
```json
{
  "content": [
    {
      "id": "uuid",
      "title": "string",
      "width": 800,
      "height": 600,
      "createdAt": "iso8601-timestamp",
      "updatedAt": "iso8601-timestamp",
      "thumbnailUrl": "string (可选)"
    }
  ],
  "page": {
    "number": 0,
    "size": 20,
    "totalElements": 100,
    "totalPages": 5
  }
}
```

#### 创建画布
```http
POST /api/v1/canvases
Authorization: Bearer <token>
Content-Type: application/json

{
  "title": "string (1-255字符)",
  "width": 800,
  "height": 600,
  "backgroundColor": "string (可选, hex颜色)"
}
```

**响应**:
```json
{
  "id": "uuid",
  "title": "string",
  "width": 800,
  "height": 600,
  "backgroundColor": "#ffffff",
  "createdAt": "iso8601-timestamp",
  "updatedAt": "iso8601-timestamp",
  "layers": [
    {
      "id": "uuid",
      "name": "Background",
      "zIndex": 0,
      "visible": true,
      "locked": false
    }
  ]
}
```

#### 获取画布详情
```http
GET /api/v1/canvases/{canvasId}
Authorization: Bearer <token>
```

**响应**:
```json
{
  "id": "uuid",
  "title": "string",
  "width": 800,
  "height": 600,
  "backgroundColor": "#ffffff",
  "createdAt": "iso8601-timestamp",
  "updatedAt": "iso8601-timestamp",
  "layers": [
    {
      "id": "uuid",
      "name": "string",
      "zIndex": 0,
      "visible": true,
      "locked": false,
      "drawingData": {
        "type": "object",
        "paths": []
      }
    }
  ]
}
```

#### 更新画布
```http
PUT /api/v1/canvases/{canvasId}
Authorization: Bearer <token>
Content-Type: application/json

{
  "title": "string (可选)",
  "backgroundColor": "string (可选)"
}
```

#### 删除画布
```http
DELETE /api/v1/canvases/{canvasId}
Authorization: Bearer <token>
```

### 图层管理

#### 创建图层
```http
POST /api/v1/canvases/{canvasId}/layers
Authorization: Bearer <token>
Content-Type: application/json

{
  "name": "string (1-100字符)",
  "zIndex": 0
}
```

**响应**:
```json
{
  "id": "uuid",
  "name": "string",
  "zIndex": 0,
  "visible": true,
  "locked": false,
  "createdAt": "iso8601-timestamp"
}
```

#### 更新图层
```http
PUT /api/v1/canvases/{canvasId}/layers/{layerId}
Authorization: Bearer <token>
Content-Type: application/json

{
  "name": "string (可选)",
  "zIndex": "integer (可选)",
  "visible": "boolean (可选)",
  "locked": "boolean (可选)"
}
```

#### 删除图层
```http
DELETE /api/v1/canvases/{canvasId}/layers/{layerId}
Authorization: Bearer <token>
```

#### 更新图层顺序
```http
PATCH /api/v1/canvases/{canvasId}/layers/order
Authorization: Bearer <token>
Content-Type: application/json

{
  "layerOrders": [
    {"layerId": "uuid", "zIndex": 0},
    {"layerId": "uuid", "zIndex": 1}
  ]
}
```

### 绘图操作

#### 保存绘图数据
```http
POST /api/v1/canvases/{canvasId}/layers/{layerId}/drawing
Authorization: Bearer <token>
Content-Type: application/json

{
  "type": "path|rectangle|circle|line|text",
  "properties": {
    // 根据type不同而不同
  },
  "pathData": "svg-path-string (可选)"
}
```

**绘图类型示例**:

1. **路径 (path)**:
```json
{
  "type": "path",
  "properties": {
    "strokeColor": "#3b82f6",
    "strokeWidth": 5,
    "fillColor": null,
    "opacity": 1
  },
  "pathData": "M10,10 L100,100"
}
```

2. **矩形 (rectangle)**:
```json
{
  "type": "rectangle",
  "properties": {
    "x": 50,
    "y": 50,
    "width": 200,
    "height": 100,
    "strokeColor": "#3b82f6",
    "strokeWidth": 2,
    "fillColor": "#93c5fd",
    "opacity": 0.8
  }
}
```

3. **文本 (text)**:
```json
{
  "type": "text",
  "properties": {
    "x": 100,
    "y": 100,
    "text": "Hello World",
    "fontSize": 24,
    "fontFamily": "Arial",
    "color": "#000000"
  }
}
```

#### 获取绘图历史
```http
GET /api/v1/canvases/{canvasId}/history
Authorization: Bearer <token>
Query Parameters:
  limit: integer (可选, 默认50)
```

**响应**:
```json
{
  "history": [
    {
      "id": "uuid",
      "type": "draw|layer-create|layer-update",
      "description": "string",
      "timestamp": "iso8601-timestamp",
      "data": {}
    }
  ]
}
```

#### 撤消操作
```http
POST /api/v1/canvases/{canvasId}/undo
Authorization: Bearer <token>
```

#### 重做操作
```http
POST /api/v1/canvases/{canvasId}/redo
Authorization: Bearer <token>
```

### 导出功能

#### 导出为PNG
```http
POST /api/v1/canvases/{canvasId}/export/png
Authorization: Bearer <token>
Content-Type: application/json

{
  "scale": 1.0,
  "quality": 0.9,
  "includeBackground": true
}
```

**响应**: PNG二进制数据，Content-Type: `image/png`

#### 导出为JPEG
```http
POST /api/v1/canvases/{canvasId}/export/jpeg
Authorization: Bearer <token>
Content-Type: application/json

{
  "scale": 1.0,
  "quality": 0.8,
  "includeBackground": true
}
```

**响应**: JPEG二进制数据，Content-Type: `image/jpeg`

#### 导出为SVG
```http
POST /api/v1/canvases/{canvasId}/export/svg
Authorization: Bearer <token>
Content-Type: application/json

{
  "includeMetadata": true
}
```

**响应**: SVG XML数据，Content-Type: `image/svg+xml`

### 实时协作说明

当前版本（MVP）**不包含** WebSocket 实时协作接口。
如后续开启协作功能，会在此处补充连接端点与消息协议定义。

## 错误处理

### 错误响应格式
```json
{
  "timestamp": "iso8601-timestamp",
  "status": 400,
  "error": "Bad Request",
  "message": "详细错误信息",
  "path": "/api/v1/canvases",
  "code": "VALIDATION_ERROR"
}
```

### 常见错误码

| 状态码 | 错误码 | 描述 |
|--------|--------|------|
| 400 | VALIDATION_ERROR | 请求参数验证失败 |
| 401 | UNAUTHORIZED | 未认证或Token无效 |
| 403 | FORBIDDEN | 无权限访问资源 |
| 404 | NOT_FOUND | 资源不存在 |
| 409 | CONFLICT | 资源冲突（如用户名重复） |
| 422 | UNPROCESSABLE_ENTITY | 业务逻辑错误 |
| 429 | RATE_LIMIT_EXCEEDED | 请求频率限制 |
| 500 | INTERNAL_SERVER_ERROR | 服务器内部错误 |

## 速率限制

API请求受到速率限制：
- 认证API: 每分钟10次
- 其他API: 每分钟100次
- WebSocket连接: 每IP最多10个并发连接

超过限制将返回429状态码。

## 数据格式

### 日期时间
所有日期时间字段均使用ISO 8601格式：
```
YYYY-MM-DDTHH:mm:ss.SSSZ
```

### UUID
所有ID字段均使用UUID v4格式。

### 颜色格式
颜色值使用以下格式之一：
- 十六进制: `#3b82f6`
- RGB: `rgb(59, 130, 246)`
- RGBA: `rgba(59, 130, 246, 0.8)`

## 分页和排序

### 分页参数
- `page`: 页码，从0开始
- `size`: 每页大小，默认20，最大100
- `sort`: 排序字段，格式：`field,asc|desc`

### 排序示例
```
GET /api/v1/canvases?page=0&size=20&sort=createdAt,desc&sort=title,asc
```

## 版本兼容性

API版本通过URL路径控制。当前版本为v1。未来版本将保持向后兼容性，不兼容的更改将发布新版本。

---

*文档版本: 1.0.0*
*最后更新: 2025-03-05*
