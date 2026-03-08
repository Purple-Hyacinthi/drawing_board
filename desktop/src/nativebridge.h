#pragma once

#include <QObject>
#include <QString>

class NativeBridge : public QObject {
    Q_OBJECT

public:
    explicit NativeBridge(QObject* parent = nullptr);

public slots:
    QString openFileDialog();
    QString saveFileDialog(const QString& suggestedName);
    QString readFileAsBase64(const QString& filePath);
    bool writeFile(const QString& filePath, const QString& base64Content);
};
