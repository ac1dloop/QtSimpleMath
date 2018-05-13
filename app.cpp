#include "app.h"
#include <QApplication>

namespace M {

App::App(int argc, char *argv[]):QApplication(argc,argv) {
    setApplicationName("huy");
    setApplicationDisplayName(tr("Pizda"));
}

} //M space
