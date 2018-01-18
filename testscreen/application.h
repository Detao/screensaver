#ifndef APPLICATION_H
#define APPLICATION_H


#include <QApplication>
#include <QDebug>
#include "screensaver.h"
class Application : public QApplication
{
public:
    Application(int & argc, char ** argv);
    bool notify(QObject *, QEvent *);
    screensaver* send();
private:
    screensaver *_screensaver;
};

#endif // APPLICATION_H
