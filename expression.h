#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QLabel>
#include <vector>

namespace M {

class Expression:public QLabel{

    Q_OBJECT

public:
    Expression(int diff, int mode, QWidget *parent=0);
    virtual ~Expression(){}
    int gValue1() { return Value1; }
    int gValue2() { return Value2; }
    int gValue_res() { return Value_res; }
    void setDifficulty(int a){ Difficulty=a; }
    void setMode(int a) { Mode=a; }
    QString getMode();
    void generate();


private:
    unsigned int Value1;
    unsigned int Value2;
    unsigned int Value_res;
    int Difficulty;
    int Mode;
};

} //M space
#endif // EXPRESSION_H
