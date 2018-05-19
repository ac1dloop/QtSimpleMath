#ifndef CLOCK_H
#define CLOCK_H

#include <QLCDNumber>
#include <QMessageBox>
#include <QApplication>

namespace M {

class Clock:public QLCDNumber{

        Q_OBJECT

public:
    Clock(QWidget *parent=0);
    virtual ~Clock(){}


private slots:
    void showTime();

public slots:
    void addTime();

private:
    int m_Time;
};

} //M space
#endif // CLOCK_H
