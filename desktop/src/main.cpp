#include <QApplication>
#include <QIcon>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QApplication::setApplicationName("Drawing Board Pro");
    QApplication::setOrganizationName("DrawingBoard");
    app.setWindowIcon(QIcon(QStringLiteral(":/icons/app-icon.ico")));

    MainWindow window;
    window.setWindowIcon(app.windowIcon());
    window.show();

    return app.exec();
}
