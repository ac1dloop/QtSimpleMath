#include "mainwindow.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>

#include "clock.h"
#include "expression.h"
#include "answer.h"

namespace M {

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){

    m_Frame = new QFrame(this);
    m_Frame->setStyleSheet("background: #A4A4A4");

    m_Clock = new Clock(this);

    m_Expression = new Expression(this);
    m_Res = m_Expression->gValue_res();

    m_Answer = new Answer(this);

    QPushButton *button_ok = new QPushButton(this);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_Clock, 0, 0);
    layout->addWidget(m_Expression, 1, 0);
    layout->addWidget(m_Answer, 2, 0);
    layout->addWidget(button_ok, 3 ,0);
    layout->setMargin(0);

    m_Frame->setLayout(layout);

    connect(button_ok, SIGNAL(clicked()), this, SLOT(ok_clicked()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(ok_clicked()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(hit_enter()));
    connect(m_Answer, SIGNAL(returnPressed()), this, SLOT(ok_clicked()));
    connect(m_Answer, SIGNAL(returnPressed()), this, SLOT(hit_enter()));

    setCentralWidget(m_Frame);
    m_Answer->setFocus(Qt::OtherFocusReason);
}

MainWindow::~MainWindow()
{
}

void MainWindow::ok_clicked()
{
    m_Res = m_Expression->gValue_res();
    QString t = m_Answer->text().simplified();
    m_Input = t.toInt();
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

} //M space
