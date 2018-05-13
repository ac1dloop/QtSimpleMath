#include "expression.h"

#include <QRandomGenerator>
#include <QLabel>
#include <QString>

namespace M {

Expression::Expression(QWidget *parent)
{
    Value1=qrand()%100;
    Value2=qrand()%100;

    Value_res=Value1+Value2;
    setText(QString::number(Value1)+" + " + QString::number(Value2)+" = ?");
}
void Expression::generate()
{
    Value1=qrand()%100;
    Value2=qrand()%100;
    Value_res=Value1+Value2;
    setText(QString::number(Value1)+" + " + QString::number(Value2)+" = ?");
}
} //M space
