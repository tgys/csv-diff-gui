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
    Dialog dialog;

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

    QObject::connect(&dialog, SIGNAL(newTextOneEntered(const QString&)),
                     &w, SLOT(onNewTextOneEntered(const QString&)));
    QObject::connect(&dialog, SIGNAL(newTextTwoEntered(const QString&)),
                     &w, SLOT(onNewTextTwoEntered(const QString&)));
    QObject::connect(&dialog, SIGNAL(newUpdatePressed()),
                     &w, SLOT(onNewUpdatePressed()));
    //dialog.setFileMode(QFileDialog::Directory);
  //  dialog.setOption(QFileDialog::ShowDirsOnly);
    dialog.show();
    w.show();
    return a.exec();
}
