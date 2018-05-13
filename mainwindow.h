#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFrame>
#include <QLineEdit>
#include <QAction>
#include <QString>

namespace M {

class Clock;
class Expression;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QFrame *m_Frame;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLineEdit *m_Answer;
    int m_Input;
    int m_Res;
    Clock *m_Clock;
    Expression *m_Expression;

public slots:
    void ok_clicked();
    void hit_enter();

};

} //M space

#endif // MAINWINDOW_H
