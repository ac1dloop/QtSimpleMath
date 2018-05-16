#include "expression.h"

#include <QRandomGenerator>
#include <QLabel>
#include <QString>
#include <QDateTime>

namespace M {

Expression::Expression(int diff=100, int mode=0, QWidget *parent)
{
    Difficulty=diff;
    Mode=mode;
    QDateTime time = QDateTime::currentDateTime();
    qsrand(time.toTime_t());

    setStyleSheet("background: white");
    Value1=qrand()%Difficulty;
    Value2=qrand()%Difficulty;
    Value_res=Value1+Value2;
    setText(QString::number(Value1)+" + " + QString::number(Value2)+" = ?");
}
void Expression::generate()
{
    Value1=qrand()%Difficulty;
    Value2=qrand()%Difficulty;
    if (Mode==0)
        Value_res=Value1+Value2;
    else if (Mode==1)
        Value_res=Value1-Value2;
    else if (Mode==2)
        Value_res=Value1*Value2;
    else Value_res=Value1/Value2;
    setText(QString::number(Value1)+getMode()+QString::number(Value2)+" = ?");
}
QString Expression::getMode()
{
    if (Mode==0)
        return " + ";
    if (Mode==1)
        return " - ";
    if (Mode==2)
        return " * ";
    if (Mode==3)
        return " / ";
}
} //M space
