#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QFileDialog>
#include <dialog.h>
#include <dialog2.h>
#include <session.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        w.setStyleSheet(ts.readAll());
    }

    w.show();
    return a.exec();
}
