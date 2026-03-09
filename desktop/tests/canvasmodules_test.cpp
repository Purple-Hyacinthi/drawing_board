#include <QColor>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTemporaryDir>
#include <QtTest>

#define private public
#include "../src/canvaswidget.h"
#undef private

#include "../src/canvasfilecodec.h"
#include "../src/canvasfilters.h"

class CanvasModulesTest final : public QObject {
    Q_OBJECT

private slots:
    void roundTripPersistsDocumentFields();
    void rejectsUnsupportedProjectVersion();
    void convertsToArgb32BeforeFiltering();
    void preservesAlphaWhenApplyingFilters();
    void saveProjectFileDoesNotBakeEditableTextIntoRaster();
    void mergeActiveLayerDownRespectsLockedTarget();
};

void CanvasModulesTest::roundTripPersistsDocumentFields() {
    QTemporaryDir tempDir;
    QVERIFY(tempDir.isValid());

    CanvasTypes::DocumentState document;
    document.name = QStringLiteral("RoundTrip");
    document.width = 640;
    document.height = 360;
    document.backgroundColor = QColor(QStringLiteral("#123456"));
    document.activeLayerIndex = 0;

    CanvasTypes::LayerState layer;
    layer.name = QStringLiteral("图层 1");
    layer.visible = true;
    layer.locked = false;
    layer.opacity = 0.75;
    layer.blendMode = CanvasTypes::LayerBlendMode::Screen;
    layer.raster = QImage(document.width, document.height, QImage::Format_ARGB32_Premultiplied);
    layer.raster.fill(Qt::transparent);
    layer.raster.setPixelColor(10, 10, QColor(QStringLiteral("#ff5500")));

    CanvasTypes::TextElement text;
    text.id = QStringLiteral("text-1");
    text.rect = QRectF(24.0, 36.0, 220.0, 96.0);
    text.text = QStringLiteral("Hello Qt");
    text.style.fontFamily = QStringLiteral("MiSans");
    text.style.size = 28;
    text.style.color = QColor(QStringLiteral("#abcdef"));
    text.style.lineHeight = 1.8;
    text.style.letterSpacing = 1.5;
    layer.texts.append(text);

    document.layers.append(layer);

    const QString filePath = tempDir.filePath(QStringLiteral("roundtrip.dbp"));
    QString saveError;
    QVERIFY2(CanvasFileCodec::saveDocument(document, [](const CanvasTypes::LayerState& currentLayer) {
        return currentLayer.raster;
    }, filePath, &saveError), qPrintable(saveError));

    CanvasTypes::DocumentState loaded;
    QString loadError;
    QVERIFY2(CanvasFileCodec::loadDocument(filePath, &loaded, &loadError), qPrintable(loadError));

    QCOMPARE(loaded.name, document.name);
    QCOMPARE(loaded.width, document.width);
    QCOMPARE(loaded.height, document.height);
    QCOMPARE(loaded.backgroundColor, document.backgroundColor);
    QCOMPARE(loaded.activeLayerIndex, 0);
    QCOMPARE(loaded.layers.size(), 1);
    QCOMPARE(loaded.layers.first().blendMode, CanvasTypes::LayerBlendMode::Screen);
    QCOMPARE(loaded.layers.first().texts.size(), 1);
    QCOMPARE(loaded.layers.first().texts.first().style.lineHeight, 1.8);
    QCOMPARE(loaded.layers.first().texts.first().style.letterSpacing, 1.5);
}

void CanvasModulesTest::rejectsUnsupportedProjectVersion() {
    QTemporaryDir tempDir;
    QVERIFY(tempDir.isValid());

    const QString filePath = tempDir.filePath(QStringLiteral("invalid-version.dbp"));
    QFile file(filePath);
    QVERIFY(file.open(QIODevice::WriteOnly | QIODevice::Truncate));

    QJsonObject root;
    root.insert(QStringLiteral("version"), 999);
    root.insert(QStringLiteral("width"), 320);
    root.insert(QStringLiteral("height"), 240);
    root.insert(QStringLiteral("documentName"), QStringLiteral("Invalid"));
    root.insert(QStringLiteral("layers"), QJsonArray());
    file.write(QJsonDocument(root).toJson(QJsonDocument::Compact));
    file.close();

    CanvasTypes::DocumentState loaded;
    QString errorMessage;
    QVERIFY(!CanvasFileCodec::loadDocument(filePath, &loaded, &errorMessage));
    QVERIFY(errorMessage.contains(QStringLiteral("不支持")));
}

void CanvasModulesTest::convertsToArgb32BeforeFiltering() {
    QImage image(2, 2, QImage::Format_RGB16);
    image.fill(QColor(QStringLiteral("#123456")));

    CanvasFilters::apply(&image, CanvasTypes::FilterType::Invert, 100);

    QCOMPARE(image.format(), QImage::Format_ARGB32);
    QVERIFY(image.pixelColor(0, 0) != QColor(QStringLiteral("#123456")));
}

void CanvasModulesTest::preservesAlphaWhenApplyingFilters() {
    QImage image(1, 1, QImage::Format_ARGB32);
    image.setPixelColor(0, 0, QColor(10, 20, 30, 128));

    CanvasFilters::apply(&image, CanvasTypes::FilterType::Invert, 100);

    QCOMPARE(image.pixelColor(0, 0).alpha(), 128);
}

void CanvasModulesTest::saveProjectFileDoesNotBakeEditableTextIntoRaster() {
    CanvasWidget widget;
    widget.createDocument(QStringLiteral("TextProject"), 320, 240, QColor(QStringLiteral("#ffffff")));
    widget.document_.layers.first().texts.clear();
    widget.document_.layers.first().raster.fill(Qt::transparent);

    CanvasTypes::TextElement text;
    text.id = QStringLiteral("editable-text");
    text.rect = QRectF(24.0, 32.0, 180.0, 72.0);
    text.text = QStringLiteral("Only Text");
    text.style.fontFamily = QStringLiteral("MiSans");
    text.style.size = 24;
    text.style.color = QColor(QStringLiteral("#222222"));
    widget.document_.layers.first().texts.append(text);

    QTemporaryDir tempDir;
    QVERIFY(tempDir.isValid());
    const QString filePath = tempDir.filePath(QStringLiteral("text-project.dbp"));
    QString saveError;
    QVERIFY2(widget.saveProjectFile(filePath, &saveError), qPrintable(saveError));

    CanvasTypes::DocumentState loaded;
    QString loadError;
    QVERIFY2(CanvasFileCodec::loadDocument(filePath, &loaded, &loadError), qPrintable(loadError));
    QCOMPARE(loaded.layers.first().texts.size(), 1);

    QImage transparent(loaded.width, loaded.height, QImage::Format_ARGB32_Premultiplied);
    transparent.fill(Qt::transparent);
    QCOMPARE(loaded.layers.first().raster, transparent);
}

void CanvasModulesTest::mergeActiveLayerDownRespectsLockedTarget() {
    CanvasWidget widget;
    widget.createDocument(QStringLiteral("MergeGuard"), 320, 240, QColor(QStringLiteral("#ffffff")));

    CanvasTypes::LayerState topLayer;
    topLayer.name = QStringLiteral("Top");
    topLayer.raster = QImage(320, 240, QImage::Format_ARGB32_Premultiplied);
    topLayer.raster.fill(Qt::transparent);
    topLayer.raster.setPixelColor(12, 18, QColor(QStringLiteral("#ff0000")));
    widget.document_.layers.append(topLayer);
    widget.document_.layers.first().locked = true;
    widget.document_.activeLayerIndex = 1;

    const QImage beforeLower = widget.document_.layers.first().raster;
    widget.mergeActiveLayerDown();

    QCOMPARE(widget.document_.layers.size(), 2);
    QCOMPARE(widget.document_.layers.first().raster, beforeLower);
    QCOMPARE(widget.document_.activeLayerIndex, 1);
}

QTEST_MAIN(CanvasModulesTest)

#include "canvasmodules_test.moc"
