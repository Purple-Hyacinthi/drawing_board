package com.drawingboard.export.api;

import com.drawingboard.export.api.dto.ExportImageRequest;
import com.drawingboard.export.api.dto.ExportSvgRequest;
import com.drawingboard.user.internal.AuthenticatedUser;
import java.util.UUID;
import org.springframework.http.ContentDisposition;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/api/v1/canvases")
public class ExportController {

    private final ExportApplicationService exportApplicationService;

    public ExportController(ExportApplicationService exportApplicationService) {
        this.exportApplicationService = exportApplicationService;
    }

    @PostMapping("/{canvasId}/export/png")
    public ResponseEntity<byte[]> exportPng(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId,
        @RequestBody(required = false) ExportImageRequest request
    ) {
        double scale = request == null || request.scale() == null ? 1.0d : request.scale();
        boolean includeBackground = request == null || request.includeBackground() == null || request.includeBackground();
        byte[] data = exportApplicationService.exportPng(authenticatedUser.userId(), canvasId, scale, includeBackground);
        return imageResponse(data, MediaType.IMAGE_PNG, "canvas-" + canvasId + ".png");
    }

    @PostMapping("/{canvasId}/export/jpeg")
    public ResponseEntity<byte[]> exportJpeg(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId,
        @RequestBody(required = false) ExportImageRequest request
    ) {
        double scale = request == null || request.scale() == null ? 1.0d : request.scale();
        boolean includeBackground = request == null || request.includeBackground() == null || request.includeBackground();
        byte[] data = exportApplicationService.exportJpeg(authenticatedUser.userId(), canvasId, scale, includeBackground);
        return imageResponse(data, MediaType.IMAGE_JPEG, "canvas-" + canvasId + ".jpg");
    }

    @PostMapping("/{canvasId}/export/svg")
    public ResponseEntity<byte[]> exportSvg(
        @AuthenticationPrincipal AuthenticatedUser authenticatedUser,
        @PathVariable UUID canvasId,
        @RequestBody(required = false) ExportSvgRequest request
    ) {
        boolean includeMetadata = request != null && request.includeMetadata() != null && request.includeMetadata();
        byte[] data = exportApplicationService.exportSvg(authenticatedUser.userId(), canvasId, includeMetadata);
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.valueOf("image/svg+xml"));
        headers.setContentDisposition(ContentDisposition.attachment().filename("canvas-" + canvasId + ".svg").build());
        return ResponseEntity.ok().headers(headers).body(data);
    }

    private ResponseEntity<byte[]> imageResponse(byte[] data, MediaType contentType, String filename) {
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(contentType);
        headers.setContentDisposition(ContentDisposition.attachment().filename(filename).build());
        return ResponseEntity.ok().headers(headers).body(data);
    }
}
