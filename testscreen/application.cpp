#include "application.h"
#include "screensaver.h"
Application::Application(int &argc, char **argv):
    QApplication(argc,argv)
{
   _screensaver=new screensaver;
}
bool Application::notify(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseMove||
            e->type() == QEvent::KeyPress||
            e->type() ==QEvent::MouseButtonPress )
    {
        if(_screensaver->timeisactive())
        {
            _screensaver->timestart();
        }
        else
        {
            _screensaver->screensaverstop();
        }
    }
    return QApplication::notify(obj,e);
}
screensaver* Application::send()
{
    return _screensaver;
}



