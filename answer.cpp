#include "answer.h"

#include <QDebug>

namespace M {

Answer::Answer(QWidget *parent)
{
    setInputMask("0000;_");
    setStyleSheet("background: white");
}
} //M space
