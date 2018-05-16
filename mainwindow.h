#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QLineEdit>
#include <QAction>

namespace M {

class QWidget;
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
    QAction *m_help;
    QAction *m_about;
    QAction *m_aboutQt;
    QAction *m_diff_1; //difficulty EASY
    QAction *m_diff_2;
    QAction *m_diff_3;
    QAction *m_diff_ex; //EXTREME
    QAction *m_mode_1; //mode +
    QAction *m_mode_2; //mode -
    QAction *m_mode_3; //mode /
    QAction *m_mode_4; //mode *
    QAction *m_mode_rnd; //mode random


public slots:
    void hit_enter();
    void setMode1();
    void setMode2();
    void setMode3();
    void setMode4();
    void setModeRnd();
    void setDifficulty1();
    void setDifficulty2();
    void setDifficulty3();
    void setDifficultyEx();

};

} //M space

#endif // MAINWINDOW_H
