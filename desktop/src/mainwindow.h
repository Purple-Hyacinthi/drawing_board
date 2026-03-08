#pragma once

#include <QMainWindow>
#include <QString>
#include <QUrl>

class QWebEngineView;
class QWebChannel;
class NativeBridge;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private:
    void initializeWebView();
    QUrl resolveFrontendUrl() const;
    void showStartupErrorPage(const QString& detail);

    QWebEngineView* webView;
    QWebChannel* webChannel;
    NativeBridge* nativeBridge;
};
