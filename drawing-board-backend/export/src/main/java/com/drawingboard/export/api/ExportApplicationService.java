package com.drawingboard.export.api;

import com.drawingboard.canvas.api.CanvasApplicationService;
import com.drawingboard.canvas.domain.Canvas;
import com.drawingboard.canvas.domain.Layer;
import java.awt.AlphaComposite;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.List;
import java.util.UUID;
import javax.imageio.ImageIO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
public class ExportApplicationService {

    private final CanvasApplicationService canvasApplicationService;

    public ExportApplicationService(CanvasApplicationService canvasApplicationService) {
        this.canvasApplicationService = canvasApplicationService;
    }

    @Transactional(readOnly = true)
    public byte[] exportPng(UUID userId, UUID canvasId, double scale, boolean includeBackground) {
        return exportRaster(userId, canvasId, normalizeScale(scale), includeBackground, "png");
    }

    @Transactional(readOnly = true)
    public byte[] exportJpeg(UUID userId, UUID canvasId, double scale, boolean includeBackground) {
        return exportRaster(userId, canvasId, normalizeScale(scale), includeBackground, "jpg");
    }

    @Transactional(readOnly = true)
    public byte[] exportSvg(UUID userId, UUID canvasId, boolean includeMetadata) {
        Canvas canvas = canvasApplicationService.getOwnedCanvas(userId, canvasId);
        List<Layer> layers = canvasApplicationService.listLayers(userId, canvasId);

        StringBuilder svg = new StringBuilder();
        svg.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
        svg.append("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"")
            .append(canvas.getWidth())
            .append("\" height=\"")
            .append(canvas.getHeight())
            .append("\" viewBox=\"0 0 ")
            .append(canvas.getWidth())
            .append(' ')
            .append(canvas.getHeight())
            .append("\">\n");

        svg.append("  <rect x=\"0\" y=\"0\" width=\"100%\" height=\"100%\" fill=\"")
            .append(escapeXml(canvas.getBackgroundColor()))
            .append("\"/>\n");

        for (Layer layer : layers) {
            if (!layer.isVisible()) {
                continue;
            }
            svg.append("  <g id=\"layer-")
                .append(layer.getId())
                .append("\" data-name=\"")
                .append(escapeXml(layer.getName()))
                .append("\">\n");
            svg.append("    <desc>")
                .append(escapeXml(layer.getDrawingData()))
                .append("</desc>\n");
            svg.append("  </g>\n");
        }

        if (includeMetadata) {
            svg.append("  <metadata>")
                .append("Exported by Drawing Board Pro")
                .append("</metadata>\n");
        }

        svg.append("</svg>\n");
        return svg.toString().getBytes(StandardCharsets.UTF_8);
    }

    private byte[] exportRaster(UUID userId, UUID canvasId, double scale, boolean includeBackground, String format) {
        Canvas canvas = canvasApplicationService.getOwnedCanvas(userId, canvasId);
        List<Layer> layers = canvasApplicationService.listLayers(userId, canvasId);

        int outputWidth = (int) Math.round(canvas.getWidth() * scale);
        int outputHeight = (int) Math.round(canvas.getHeight() * scale);
        int imageType = "jpg".equals(format) ? BufferedImage.TYPE_INT_RGB : BufferedImage.TYPE_INT_ARGB;
        BufferedImage image = new BufferedImage(outputWidth, outputHeight, imageType);
        Graphics2D g2d = image.createGraphics();
        try {
            g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2d.scale(scale, scale);

            if (includeBackground || "jpg".equals(format)) {
                g2d.setColor(parseColor(canvas.getBackgroundColor()));
                g2d.fillRect(0, 0, canvas.getWidth(), canvas.getHeight());
            } else {
                g2d.setComposite(AlphaComposite.Clear);
                g2d.fillRect(0, 0, canvas.getWidth(), canvas.getHeight());
                g2d.setComposite(AlphaComposite.SrcOver);
            }

            g2d.setColor(new Color(33, 37, 41));
            g2d.setFont(new Font("SansSerif", Font.PLAIN, 12));
            int textY = 20;
            for (Layer layer : layers) {
                if (!layer.isVisible()) {
                    continue;
                }
                g2d.drawString("Layer: " + layer.getName(), 12, textY);
                textY += 16;
            }

            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
            ImageIO.write(image, format, outputStream);
            return outputStream.toByteArray();
        } catch (IOException exception) {
            throw new IllegalStateException("导出图片失败", exception);
        } finally {
            g2d.dispose();
        }
    }

    private double normalizeScale(double scale) {
        if (Double.isNaN(scale) || Double.isInfinite(scale)) {
            return 1.0d;
        }
        return Math.max(0.1d, Math.min(scale, 5.0d));
    }

    private Color parseColor(String color) {
        try {
            return Color.decode(color);
        } catch (Exception ignored) {
            return Color.WHITE;
        }
    }

    private String escapeXml(String value) {
        if (value == null) {
            return "";
        }
        return value
            .replace("&", "&amp;")
            .replace("<", "&lt;")
            .replace(">", "&gt;")
            .replace("\"", "&quot;")
            .replace("'", "&apos;");
    }
}
