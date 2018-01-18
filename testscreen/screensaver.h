#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <QtGui>
#include <QLabel>
#include <QWidget>
class screensaver:public QWidget
{
    Q_OBJECT
public:
    screensaver(QWidget *parent = 0);
    ~screensaver();
    bool timeisactive();
    void screensaverstop();
    void settime(qint64 minute=1);
    void setpicture(const QString &picturepath=QString::fromUtf8 (":/images/timg1"));

private:
    QLabel *background;
    QTimer *backtimer;
    qint64  time;
    int screenWidthM;
    int screenHeightM;
public slots:
    void timestart();
    void timestop();
    void screensaverstart();
};

#endif // SCREENSAVER_H
