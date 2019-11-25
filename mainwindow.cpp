#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "session.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "dialog2.h"
#include "uniquekeys.h"
#include "results.h"

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
    numrows_one = 0;
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
            numrows_one++;
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
    numrows_two = 0;
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
            numrows_two++;
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
        int first = 1;
        for (QString colOne : ses->returnCols_one())
        {                                                    //set default pairings
            if (ses->returnCols_two().contains(colOne))
            {
                qDebug() << "equivalent found";
                ses->setEquivalent(colOne, colOne);
                QString none = "NONE";
                if (first) { ses->setModified(none, none); first = 0; }
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
        QObject::connect(dialog2, SIGNAL(newOkColumns()), this, SLOT(onNewOkColumns()));
        dialog2->setModal(true);

        qDebug() << "main window created dialog2";
        dialog2->show();
    }
}

void MainWindow::onNewOkColumns()
{
    qDebug() << "on new ok columns";
    if (ses->getTablesLoaded() == 2){
        UniqueKeys *ukeys;
        ukeys = new UniqueKeys(this,ses);
        QObject::connect(ukeys, SIGNAL(newOkKeys()), this, SLOT(onNewOkKeys()));
        ukeys->setModal(true);

        qDebug() << "main window created ukeys";
        ukeys->show();
    }
}

void MainWindow::onNewOkKeys()
{
    qDebug() << "on new ok keys";
    Results *res;
    res = new Results(this,ses);
    QObject::connect(this, SIGNAL(newUpdateResultsChanged(int, int, int, int, QStandardItem *,
                       QStandardItem *, QString &, QString &)), res, SLOT(onNewUpdateResultsChanged(int, int, int, int, QStandardItem *,
                       QStandardItem *, QString &, QString &)));
    QObject::connect(this, SIGNAL(newUpdateResultsExtras(int, int, QList<QStandardItem *>)), res,
                     SLOT(onNewUpdateResultsExtras(int, int, QList<QStandardItem *>)));
    qDebug() << "main window created results";
   // res->show();

    for (int i = 0; i < numrows_one; i++)     // for each row in the first table
    {
        int rowsSkipped = 0;
        for (int j = 0; j < numrows_two; j++)    //for each row, check each row in 2nd table
        {

            int skipRow = 0;
            for (QString uniqueCol : ses->returnUniqueKeys())  //check entries in uniquekey columns
            {
                QString uniqueCol_two = ses->getEquivalent(uniqueCol);  //find matching column in 2nd table
                int ucol_num_one = ses->getColNum_one(uniqueCol);
                int ucol_num_two = ses->getColNum_two(uniqueCol_two);
                QStandardItem *uitemOne = csvModelOne->item(i, ucol_num_one);
                QStandardItem *uitemTwo = csvModelTwo->item(i, ucol_num_two);
                QString utextOne = uitemOne->text();             // get text from matched entries
                QString utextTwo = uitemTwo->text();

                if (utextOne != utextTwo)    //if the entries do not match
                {
                    skipRow = 1;
                    rowsSkipped++;    //keep count of skipped rows in 2nd table
                    break;            //skip checking other uniquecolumns
                }
             }

            if (skipRow) { continue; }     //skip row if not all uniquecolumns match

            for (QString colName_one : ses->returnCols_one())      //if all uniquecolumns match
            {
                if (!ses->inUniqueKeys(colName_one))            //check the remaining columns
                {
                    QString colName_two = ses->getEquivalent(colName_one);
                    int col_num_one = ses->getColNum_one(colName_one);
                    int col_num_two = ses->getColNum_two(colName_two);
                    QStandardItem *itemOne = csvModelOne->item(i, col_num_one);
                    QStandardItem *itemTwo = csvModelTwo->item(i, col_num_two);
                    QString textOne = itemOne->text();
                    QString textTwo = itemTwo->text();

                    if (textOne != textTwo)                   //if there is a non-matching entry in any of the remaining columns
                    {
                        emit this->newUpdateResultsChanged(i, j, col_num_one, col_num_two, itemOne, itemTwo, textOne, textTwo);
                    }                                         //add entry to list of changed tables
                }

            }
        }

        if (rowsSkipped == numrows_two){                //if all rows in the second table were skipped
            QList<QStandardItem *> skippedRowItems;     //the row in the first table (i) is an extra row
            for (QString q : ses->returnCols_one())
            {
                int qcol = ses->getColNum_one(q);
                QStandardItem *itm = csvModelOne->item(i, qcol);
                QString txt = itm->text();
                skippedRowItems.append(new QStandardItem(txt));   //add item in the first row
            }
            emit this->newUpdateResultsExtras(i, 1, skippedRowItems);     //add row to extras model
        }
     }

    QList<QString> uniqueKeysTwo = QList<QString>();
    QHash<QString, QString> reverseEquivalent = QHash<QString, QString>();
    for (QString fir : ses->returnUniqueKeys())   //get uniquekey columns in 2nd table
    {                                             //and reverse equivalents list
        QString sec = ses->getEquivalent(fir);
        uniqueKeysTwo.append(sec);
        reverseEquivalent[sec] = fir;
    }

    for (int i = 0; i < numrows_two; i++)          //for each row in the second table
    {
         int rowsSkipped = 0;
         for (int j = 0; j < numrows_one; j++)
         {
             for (QString uniqueCol : uniqueKeysTwo)  //check entries in uniquekey columns
             {
                 QString uniqueCol_two = reverseEquivalent[uniqueCol];  //find matching column in 1st table
                 int ucol_num_one = ses->getColNum_one(uniqueCol);
                 int ucol_num_two = ses->getColNum_two(uniqueCol_two);
                 QStandardItem *uitemOne = csvModelOne->item(i, ucol_num_one);
                 QStandardItem *uitemTwo = csvModelTwo->item(i, ucol_num_two);
                 QString utextOne = uitemOne->text();             // get text from matched entries
                 QString utextTwo = uitemTwo->text();

                 if (utextOne != utextTwo)    //if the entries do not match
                 {
                     rowsSkipped++;    //keep count of skipped rows in 1st table
                     break;            //skip checking other uniquecolumns
                 }
              }               //if entries match, continue loop and check other columns

         }

         if (rowsSkipped == numrows_one){                //if all rows in the first table were skipped
            QList<QStandardItem *> skippedRowTwoItems;     //the row in the second table (i) is an extra row
            for (QString q : ses->returnCols_two())
            {
                int qcol = ses->getColNum_two(q);
                QStandardItem *itm2 = csvModelTwo->item(i, qcol);
                QString txt = itm2->text();
                skippedRowTwoItems.append(new QStandardItem(txt));   //add item in the first row
            }
            emit this->newUpdateResultsExtras(i, 2, skippedRowTwoItems);     //add row to extras model
        }

    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

