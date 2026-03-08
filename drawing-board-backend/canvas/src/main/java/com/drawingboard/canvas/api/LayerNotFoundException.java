package com.drawingboard.canvas.api;

public class LayerNotFoundException extends RuntimeException {

    public LayerNotFoundException(String message) {
        super(message);
    }
}
