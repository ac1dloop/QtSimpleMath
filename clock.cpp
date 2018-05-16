#include "clock.h"

#include <QMessageBox>
#include <QTimer>

namespace M {

Clock::Clock(QWidget *parent)
{
    setStyleSheet("background: white");
    m_Time=30000;
    setSegmentStyle(Flat);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
    resize(200,200);
}

void Clock::showTime()
{
    display(m_Time/1000);
    if (m_Time<=0)
        QMessageBox::critical(this, "FINITO LA COMEDIA", "YOU DIED MOTHERFUCKER");
    else m_Time-=1000;
}
void Clock::addTime()
{
    m_Time+=5000;
}

} //M space
