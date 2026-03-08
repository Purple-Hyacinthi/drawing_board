package com.drawingboard.common.api;

import com.drawingboard.canvas.api.CanvasNotFoundException;
import com.drawingboard.canvas.api.CanvasPermissionDeniedException;
import com.drawingboard.canvas.api.LayerNotFoundException;
import com.drawingboard.user.internal.UserAuthenticationException;
import com.drawingboard.user.internal.UserConflictException;
import com.drawingboard.user.internal.UserNotFoundException;
import jakarta.servlet.http.HttpServletRequest;
import java.time.LocalDateTime;
import java.util.stream.Collectors;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

@RestControllerAdvice
public class GlobalExceptionHandler {

    @ExceptionHandler(MethodArgumentNotValidException.class)
    public ResponseEntity<ApiErrorResponse> handleValidationException(
        MethodArgumentNotValidException exception,
        HttpServletRequest request
    ) {
        String message = exception.getBindingResult()
            .getFieldErrors()
            .stream()
            .map(this::formatFieldError)
            .collect(Collectors.joining("; "));

        return buildResponse(HttpStatus.BAD_REQUEST, message, request.getRequestURI(), "VALIDATION_ERROR");
    }

    @ExceptionHandler(IllegalArgumentException.class)
    public ResponseEntity<ApiErrorResponse> handleIllegalArgumentException(
        IllegalArgumentException exception,
        HttpServletRequest request
    ) {
        return buildResponse(HttpStatus.BAD_REQUEST, exception.getMessage(), request.getRequestURI(), "VALIDATION_ERROR");
    }

    @ExceptionHandler(UserConflictException.class)
    public ResponseEntity<ApiErrorResponse> handleConflictException(
        UserConflictException exception,
        HttpServletRequest request
    ) {
        return buildResponse(HttpStatus.CONFLICT, exception.getMessage(), request.getRequestURI(), "CONFLICT");
    }

    @ExceptionHandler({UserAuthenticationException.class, AccessDeniedException.class})
    public ResponseEntity<ApiErrorResponse> handleAuthenticationException(
        RuntimeException exception,
        HttpServletRequest request
    ) {
        return buildResponse(HttpStatus.UNAUTHORIZED, exception.getMessage(), request.getRequestURI(), "UNAUTHORIZED");
    }

    @ExceptionHandler({CanvasPermissionDeniedException.class})
    public ResponseEntity<ApiErrorResponse> handleForbiddenException(
        CanvasPermissionDeniedException exception,
        HttpServletRequest request
    ) {
        return buildResponse(HttpStatus.FORBIDDEN, exception.getMessage(), request.getRequestURI(), "FORBIDDEN");
    }

    @ExceptionHandler({CanvasNotFoundException.class, LayerNotFoundException.class, UserNotFoundException.class})
    public ResponseEntity<ApiErrorResponse> handleNotFoundException(
        RuntimeException exception,
        HttpServletRequest request
    ) {
        return buildResponse(HttpStatus.NOT_FOUND, exception.getMessage(), request.getRequestURI(), "NOT_FOUND");
    }

    @ExceptionHandler(Exception.class)
    public ResponseEntity<ApiErrorResponse> handleUnexpectedException(
        Exception exception,
        HttpServletRequest request
    ) {
        return buildResponse(
            HttpStatus.INTERNAL_SERVER_ERROR,
            "服务器内部错误",
            request.getRequestURI(),
            "INTERNAL_SERVER_ERROR"
        );
    }

    private ResponseEntity<ApiErrorResponse> buildResponse(HttpStatus status, String message, String path, String code) {
        ApiErrorResponse response = new ApiErrorResponse(
            LocalDateTime.now(),
            status.value(),
            status.getReasonPhrase(),
            message,
            path,
            code
        );
        return ResponseEntity.status(status).body(response);
    }

    private String formatFieldError(FieldError fieldError) {
        return fieldError.getField() + " " + fieldError.getDefaultMessage();
    }
}
