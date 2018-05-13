#ifndef APP_H
#define APP_H

#include <QApplication>

namespace M {

class App:public QApplication{

    Q_OBJECT

public:
    App(int argc, char *argv[]);
    virtual ~App(){}

};
}


#endif // APP_H
