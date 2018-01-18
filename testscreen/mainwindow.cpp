#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_screensaver;
}

void MainWindow::on_setpicture_clicked()
{
    m_screensaver->setpicture(QString::fromUtf8 (":/images/timg"));
}

void MainWindow::on_settime_clicked()
{
    m_screensaver->settime(2);
}
void MainWindow::get(screensaver *f)
{
    m_screensaver=f;
}

