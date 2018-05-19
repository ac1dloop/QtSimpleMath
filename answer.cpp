#include "answer.h"

#include <QDebug>
#include <QFont>

namespace M {

Answer::Answer(QWidget *parent)
{
    QFont font("Arial", 40, QFont::Bold);
    setFont(font);
    setInputMask("0000;_");
    setStyleSheet("background: white");
}
} //M space
