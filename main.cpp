#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QFileDialog>
#include <dialog.h>
#include <dialog2.h>
#include <session.h>

int main(int argc, char *argv[])
{
    /*Session *ses = new Session();
    QFileInfo fi_one("/home/tei/Downloads/DRun/4.3/D1/ConditionIndices.csv");
    QString fileName_one = fi_one.fileName();
    QString fpath_one = fi_one.path();
    ses->setFileOnePath(fpath_one);

    QFileInfo fi_two("/home/tei/Downloads/DRun/4.4/D1/ConditionIndices.csv");
    QString fileName_two = fi_two.fileName();
    QString fpath_two = fi_two.path();
    ses->setFileTwoPath(fpath_two);

    QString p1 = ses->getFileOnePath();
    QString p2 = ses->getFileTwoPath();

    qDebug() << p1;
    qDebug() << p2;

    */
    QApplication a(argc, argv);
    MainWindow w;
    Dialog dialog;
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
