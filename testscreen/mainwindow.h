#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "screensaver.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void get(screensaver *f);
private slots:
    void on_setpicture_clicked();

    void on_settime_clicked();

private:
    Ui::MainWindow *ui;
    screensaver *m_screensaver;
};

#endif // MAINWINDOW_H
