#include "mainwindow.h"
#include "app.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    M::App app(argc,argv);

    M::MainWindow mw;
    mw.show();

    app.setStyle(QStyleFactory::create("Fusion"));

    return app.exec();
}
