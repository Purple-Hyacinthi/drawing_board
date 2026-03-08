-- Source of truth for runtime migration is:
-- drawing-board-backend/application/src/main/resources/db/migration/V1__init_schema.sql
-- This copy is kept for DBA review in repository root.

CREATE TABLE users (
    id UUID PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    email VARCHAR(255) NOT NULL UNIQUE,
    password_hash VARCHAR(255) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL
);

CREATE TABLE canvases (
    id UUID PRIMARY KEY,
    user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
    title VARCHAR(255) NOT NULL,
    width INTEGER NOT NULL,
    height INTEGER NOT NULL,
    background_color VARCHAR(32) NOT NULL DEFAULT '#ffffff',
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL
);

CREATE TABLE layers (
    id UUID PRIMARY KEY,
    canvas_id UUID NOT NULL REFERENCES canvases(id) ON DELETE CASCADE,
    name VARCHAR(100) NOT NULL,
    z_index INTEGER NOT NULL,
    visible BOOLEAN NOT NULL DEFAULT TRUE,
    locked BOOLEAN NOT NULL DEFAULT FALSE,
    drawing_data JSONB,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL
);

CREATE TABLE canvas_versions (
    id UUID PRIMARY KEY,
    canvas_id UUID NOT NULL REFERENCES canvases(id) ON DELETE CASCADE,
    snapshot_data JSONB NOT NULL,
    created_at TIMESTAMP NOT NULL
);

CREATE INDEX idx_canvases_user_id ON canvases(user_id);
CREATE INDEX idx_canvases_updated_at ON canvases(updated_at DESC);
CREATE INDEX idx_layers_canvas_id ON layers(canvas_id);
CREATE INDEX idx_layers_canvas_zindex ON layers(canvas_id, z_index);
CREATE INDEX idx_canvas_versions_canvas_id ON canvas_versions(canvas_id);
CREATE INDEX idx_canvas_versions_created_at ON canvas_versions(created_at DESC);
