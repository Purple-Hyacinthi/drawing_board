#include "nativebridge.h"

#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>

NativeBridge::NativeBridge(QObject* parent)
    : QObject(parent) {
}

QString NativeBridge::openFileDialog() {
    return QFileDialog::getOpenFileName(
        nullptr,
        QStringLiteral("打开绘图文件"),
        QString(),
        QStringLiteral("绘图文件 (*.dbp *.json *.png *.jpg *.jpeg *.webp *.bmp *.gif *.svg)")
    );
}

QString NativeBridge::saveFileDialog(const QString& suggestedName) {
    return QFileDialog::getSaveFileName(
        nullptr,
        QStringLiteral("保存绘图文件"),
        suggestedName,
        QStringLiteral("绘图文件 (*.dbp);;PNG 文件 (*.png);;JPEG 文件 (*.jpg);;SVG 文件 (*.svg)")
    );
}

QString NativeBridge::readFileAsBase64(const QString& filePath) {
    const QString normalizedPath = filePath.trimmed();
    if (normalizedPath.isEmpty()) {
        return QString();
    }

    QFile file(normalizedPath);
    if (!file.open(QIODevice::ReadOnly)) {
        return QString();
    }

    const QByteArray content = file.readAll();
    file.close();
    return QString::fromUtf8(content.toBase64());
}

bool NativeBridge::writeFile(const QString& filePath, const QString& base64Content) {
    const QString normalizedPath = filePath.trimmed();
    if (normalizedPath.isEmpty()) {
        return false;
    }

    const QByteArray data = QByteArray::fromBase64(base64Content.toUtf8());
    QFileInfo fileInfo(normalizedPath);
    QDir directory = fileInfo.dir();
    if (!directory.exists() && !directory.mkpath(QStringLiteral("."))) {
        return false;
    }

    QFile file(fileInfo.absoluteFilePath());
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    const qint64 bytesWritten = file.write(data);
    file.close();
    return bytesWritten == data.size();
}
