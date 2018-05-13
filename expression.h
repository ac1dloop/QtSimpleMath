#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QLabel>

namespace M {

class Expression:public QLabel{

    Q_OBJECT

public:
    Expression(QWidget *parent=0);
    virtual ~Expression(){}
    int gValue1() { return Value1; }
    int gValue2() { return Value2; }
    int gValue_res() { return Value_res; }
    void generate();


private:
    int Value1;
    int Value2;
    int Value_res;
};

} //M space
#endif // EXPRESSION_H
