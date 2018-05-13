#ifndef ANSWER_H
#define ANSWER_H

#include <QLineEdit>

namespace M {

class Answer:public QLineEdit
{
public:
    Answer(QWidget *parent=0);
    virtual ~Answer(){}

};
} //M space

#endif // ANSWER_H
