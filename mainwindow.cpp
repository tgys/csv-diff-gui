#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "session.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "dialog2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ses = new Session();

    csvModelOne = new QStandardItemModel(this);
    ui->tableView->setModel(csvModelOne);

    csvModelTwo = new QStandardItemModel(this);
    ui->tableView_2->setModel(csvModelTwo);

    QFileInfo fi_one("/foo/bar");
    QString fileName_one = fi_one.fileName();
    QString fpath_one = fi_one.path();
    ses->setFileOnePath(fpath_one);

    QFileInfo fi_two("/bar/foo");
    QString fileName_two = fi_two.fileName();
    QString fpath_two = fi_two.path();
    ses->setFileTwoPath(fpath_two);

    QString p1 = ses->getFileOnePath();
    QString p2 = ses->getFileTwoPath();

    qDebug() << p1;
    qDebug() << p2;

}

void MainWindow::getDiffs()
{

}

void MainWindow::updateTableOne()
{
    QFile file(ses->getFileOnePath());
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File does not exist";
    } else {
        ses->incTablesLoaded();
        QTextStream in(&file);
        QString firstline = in.readLine();
        int colCount = 1;
        for (QString item : firstline.split(",")) {
                //qDebug() << item;
                ses->addCol_one(item,colCount);
                qDebug() << item;
                qDebug() << ses->getColNum_one(item);
                colCount++;
            }
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QList<QStandardItem *> rowItems;
            for (QString item : line.split(",")) {
                rowItems.append(new QStandardItem(item));
            }
            csvModelOne->insertRow(csvModelOne->rowCount(), rowItems);
        }
        file.close();
    }
}

void MainWindow::updateTableTwo()
{
    QFile file(ses->getFileTwoPath());
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File does not exist";
    } else {
        ses->incTablesLoaded();
        QTextStream in(&file);
        QString firstline = in.readLine();
        int colCount = 1;
        for (QString item : firstline.split(",")) {
                ses->addCol_two(item,colCount);
                qDebug() << item;
                qDebug() << ses->getColNum_two(item);
                colCount++;
            }
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QList<QStandardItem *> rowItems;
            for (QString item : line.split(",")) {
                rowItems.append(new QStandardItem(item));
            }
            csvModelTwo->insertRow(csvModelTwo->rowCount(), rowItems);
        }
        file.close();
    }
}


void MainWindow::onNewTextOneEntered(const QString &text)
{
    ui->label->setText("entries in " + text);
    ses->setFileOnePath(text);
    qDebug() << ses->getFileOnePath();
    updateTableOne();
  //  Dialog2 dialog2;
  // dialog2.show();
}

void MainWindow::onNewTextTwoEntered(const QString &text)
{
    ui->label_2->setText("entries in " + text);
    ses->setFileTwoPath(text);
    qDebug() << ses->getFileTwoPath();
    updateTableTwo();
}

void MainWindow::onNewUpdatePressed()
{
    qDebug() << ses->getTablesLoaded();
    if (ses->getTablesLoaded() == 2)
    {
        for (QString colOne : ses->returnCols_one()) { //set default pairings
            if (ses->returnCols_two().contains(colOne))
            {
                qDebug() << "equivalent found";
                ses->setEquivalent(colOne, colOne);
            }
            else
            {
                qDebug() << "no matches found";
                QString q = "NO MATCHES";
                ses->setEquivalent(colOne, q);
            }
        }

        Dialog2 *dialog2;
        dialog2 = new Dialog2(this,ses);
        dialog2->setModal(true);

        qDebug() << "ahh";
        dialog2->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

