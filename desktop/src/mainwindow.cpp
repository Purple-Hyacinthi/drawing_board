#include "mainwindow.h"

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QWebChannel>
#include <QWebEnginePage>
#include <QWebEngineSettings>
#include <QWebEngineView>
#include <QUrl>

#include "nativebridge.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      webView(new QWebEngineView(this)),
      webChannel(new QWebChannel(this)),
      nativeBridge(new NativeBridge(this)) {
    setWindowTitle("Drawing Board Pro Desktop");
    resize(1440, 900);

    setCentralWidget(webView);
    initializeWebView();
}

MainWindow::~MainWindow() = default;

void MainWindow::initializeWebView() {
    webChannel->registerObject("nativeBridge", nativeBridge);
    webView->page()->setWebChannel(webChannel);

    webView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    webView->settings()->setAttribute(QWebEngineSettings::LocalStorageEnabled, true);
    webView->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessFileUrls, true);

    connect(webView, &QWebEngineView::loadFinished, this, [this](bool ok) {
        if (ok) {
            return;
        }

        const QString currentUrl = webView->url().toDisplayString();
        showStartupErrorPage(
            QStringLiteral("无法加载前端页面 当前地址 %1").arg(currentUrl.isEmpty() ? QStringLiteral("未知") : currentUrl)
        );
    });

    webView->load(resolveFrontendUrl());
}

QUrl MainWindow::resolveFrontendUrl() const {
    const QString appDirPath = QCoreApplication::applicationDirPath();
    const QDir appDir(appDirPath);
    const QStringList candidates = {
        appDir.filePath(QStringLiteral("frontend/index.html")),
        appDir.filePath(QStringLiteral("../frontend/index.html")),
        appDir.filePath(QStringLiteral("../../frontend/index.html")),
        appDir.filePath(QStringLiteral("../../../frontend/dist/index.html")),
        appDir.filePath(QStringLiteral("../../../../frontend/dist/index.html"))
    };

    for (const QString& candidate : candidates) {
        const QFileInfo fileInfo(candidate);
        if (fileInfo.exists() && fileInfo.isFile()) {
            return QUrl::fromLocalFile(fileInfo.absoluteFilePath());
        }
    }

    QByteArray envUrl = qgetenv("DRAWING_BOARD_FRONTEND_URL");
    const QString overrideUrl = QString::fromUtf8(envUrl).trimmed();
    if (!overrideUrl.isEmpty()) {
        return QUrl::fromUserInput(overrideUrl);
    }

    return QUrl(QStringLiteral("http://127.0.0.1:3000"));
}

void MainWindow::showStartupErrorPage(const QString& detail) {
    const QString html = QStringLiteral(R"(
<!doctype html>
<html lang='zh-CN'>
<head>
  <meta charset='utf-8'>
  <meta name='viewport' content='width=device-width, initial-scale=1'>
  <title>Drawing Board Pro</title>
  <style>
    body { margin: 0; font-family: "Microsoft YaHei", "PingFang SC", sans-serif; background: #e2e8f0; }
    .card { max-width: 780px; margin: 6vh auto; background: #ffffff; border: 1px solid #cbd5e1; border-radius: 12px; padding: 24px; box-shadow: 0 14px 30px rgba(15,23,42,.14); }
    h1 { margin: 0 0 12px; font-size: 24px; color: #0f172a; }
    p { margin: 8px 0; color: #334155; line-height: 1.6; }
    code { background: #f1f5f9; border: 1px solid #cbd5e1; border-radius: 6px; padding: 2px 6px; }
  </style>
</head>
<body>
  <div class='card'>
    <h1>应用启动失败</h1>
    <p>%1</p>
    <p>可选方案一：确认安装目录中存在 <code>frontend/index.html</code></p>
    <p>可选方案二：设置环境变量 <code>DRAWING_BOARD_FRONTEND_URL</code> 指向可访问地址</p>
  </div>
</body>
</html>
)");
    webView->setHtml(html.arg(detail), QUrl(QStringLiteral("about:blank")));
}
