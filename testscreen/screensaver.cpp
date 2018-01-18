#include "screensaver.h"
#include <QApplication>
#include <QDesktopWidget>
screensaver::screensaver(QWidget *parent)
    : QWidget(parent)
{
    screenWidthM = qApp->desktop()->size().width();
    screenHeightM = qApp->desktop()->size().height();
    background=new QLabel(this);
    background->setScaledContents (true);
    //background->setPixmap(QPixmap(screensaverpicture));
    background->setGeometry(0,0,screenWidthM,screenHeightM);
    background->raise();
    setpicture();
    backtimer=new QTimer(this);
    connect(backtimer,SIGNAL(timeout()),this,SLOT(screensaverstart()));
    settime();
    timestart();
}
screensaver::~screensaver()
{
    delete backtimer;
    delete background;
}
void screensaver::timestart()
{
    backtimer->start(time);
}
bool screensaver::timeisactive()
{
    return backtimer->isActive();
}
void screensaver::timestop()
{
    backtimer->stop();
}
void screensaver::settime(qint64 minute)
{
    time=minute*6000;
}
void screensaver::setpicture(const QString &picturepath)
{
    background->setPixmap(QPixmap(picturepath));
}
void screensaver::screensaverstart()//change picture
{
    timestop();
    background->setWindowFlags (Qt::Window| Qt::FramelessWindowHint);
    background->setCursor(Qt::BlankCursor);
    background->showFullScreen();
}
void screensaver::screensaverstop()//change picture
{
    timestart();
    background->close();
}

