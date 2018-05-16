#include "mainwindow.h"
#include "clock.h"
#include "expression.h"
#include "answer.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>
#include <QFrame>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QActionGroup>

namespace M {

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){

    m_Frame = new QFrame(this);
    m_Frame->setStyleSheet("background: #A4A4A4");

    m_Clock = new Clock(this);

    m_Expression = new Expression(100, 0, this);
    m_Res = m_Expression->gValue_res();

    m_Answer = new Answer(this);

    QPushButton *button_ok = new QPushButton(this);
    button_ok->setText("GO!");
    button_ok->setStyleSheet("background: magenta");

    QGridLayout *layout = new QGridLayout;
    layout->setMargin(0);
    layout->addWidget(m_Clock, 0, 0);
    layout->addWidget(m_Expression, 1, 0);
    layout->addWidget(m_Answer, 2, 0);
    layout->addWidget(button_ok, 3 ,0);

    m_Frame->setLayout(layout);

    QMenu *settings = new QMenu(tr("Settings"), this);
    QMenu *help = new QMenu(tr("Help"), this);
    QMenu *difficulty = new QMenu(tr("Difficulty"), this);
    QMenu *mode = new QMenu(tr("Mode"), this);

    m_diff_1 = new QAction(this);
    m_diff_1->setText(tr("EASY"));
    m_diff_2 = new QAction(this);
    m_diff_2->setText(tr("MEDIUM"));
    m_diff_3 = new QAction(this);
    m_diff_3->setText(tr("HARD"));
    m_diff_ex = new QAction(this);
    m_diff_ex->setText(tr("EXTREME"));

    QActionGroup *difficulties = new QActionGroup(this);
    difficulties->setExclusive(true);
    difficulties->addAction(m_diff_1);
    difficulties->addAction(m_diff_2);
    difficulties->addAction(m_diff_3);
    difficulties->addAction(m_diff_ex);

    m_mode_1 = new QAction(this);
    m_mode_1->setText(tr("Addition"));
    m_mode_2 = new QAction(this);
    m_mode_2->setText(tr("Substraction"));
    m_mode_3 = new QAction(this);
    m_mode_3->setText(tr("Multiplication"));
    m_mode_4 = new QAction(this);
    m_mode_4->setText(tr("Division"));
    m_mode_rnd = new QAction(this);
    m_mode_rnd->setText(tr("Random mode"));

    QActionGroup *modes = new QActionGroup(this);
    modes->setExclusive(true);
    modes->addAction(m_mode_1);
    modes->addAction(m_mode_2);
    modes->addAction(m_mode_3);
    modes->addAction(m_mode_4);
    modes->addAction(m_mode_rnd);

    difficulty->addAction(m_diff_1);
    difficulty->addAction(m_diff_2);
    difficulty->addAction(m_diff_3);
    difficulty->addAction(m_diff_ex);

    mode->addAction(m_mode_1);
    mode->addAction(m_mode_2);
    mode->addAction(m_mode_3);
    mode->addAction(m_mode_4);
    mode->addAction(m_mode_rnd);

    settings->addMenu(difficulty);
    settings->addMenu(mode);

    menuBar()->addMenu(settings);
    menuBar()->addMenu(help);

    connect(button_ok, SIGNAL(clicked()), this, SLOT(hit_enter()));
    connect(m_Answer, SIGNAL(returnPressed()), this, SLOT(hit_enter()));
    connect(m_diff_1, SIGNAL(triggered()), this, SLOT(setDifficulty1()));
    connect(m_diff_2, SIGNAL(triggered()), this, SLOT(setDifficulty2()));
    connect(m_diff_3, SIGNAL(triggered()), this, SLOT(setDifficulty3()));
    connect(m_diff_ex, SIGNAL(triggered()), this, SLOT(setDifficultyEx()));

    setCentralWidget(m_Frame);
    m_Answer->setFocus(Qt::OtherFocusReason);
}

MainWindow::~MainWindow()
{
}
void MainWindow::hit_enter()
{
    m_Res = m_Expression->gValue_res();
    QString t = m_Answer->text().simplified();
    m_Input = t.toInt();

    if (m_Input==m_Res){
        m_Clock->addTime();
    }

    m_Expression->generate();

    m_Answer->setText("");
    m_Answer->setCursorPosition(0);
}
void MainWindow::setDifficulty1()
{
    m_Expression->setDifficulty(10);
    hit_enter();
}
void MainWindow::setDifficulty2()
{
    m_Expression->setDifficulty(100);
    hit_enter();
}
void MainWindow::setDifficulty3()
{
    m_Expression->setDifficulty(1000);
    hit_enter();
}
void MainWindow::setDifficultyEx()
{
    m_Expression->setDifficulty(10000);
    hit_enter();
}
void MainWindow::setMode1()
{
}
void MainWindow::setMode2()
{
}
void MainWindow::setMode3()
{
}
void MainWindow::setMode4()
{
}
void MainWindow::setModeRnd()
{
}

} //M space
