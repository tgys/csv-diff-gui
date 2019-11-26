#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "session.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "dialog2.h"
#include "u_widget.h"
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
    ses->clearCols_one();
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
        csvModelOne->clear();
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
        if (ses->getTablesLoaded() == 2)
        {
            ses->clearEquivalent();
            updateEquivalents();
        }
        file.close();
    }
}

void MainWindow::updateTableTwo()
{
    QFile file(ses->getFileTwoPath());
    numrows_two = 0;
    ses->clearCols_two();
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
        csvModelTwo->clear();
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
        if (ses->getTablesLoaded() == 2)
        {
            ses->clearEquivalent();
            updateEquivalents();
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

void MainWindow::updateEquivalents()
{
     //int first = 1;
     for (QString colOne : ses->returnCols_one())
     {                                                    //set default pairings
         if (ses->returnCols_two().contains(colOne))
         {
             qDebug() << "equivalent found";
             ses->setEquivalent(colOne, colOne);
      //       QString none = "NONE";
      //       if (first) { ses->setModified(none, none); first = 0; }
         }
         else
         {
             qDebug() << "no matches found";
             QString q = "NO MATCHES";
             ses->setEquivalent(colOne, q);
         }
     }
}

void MainWindow::onNewUpdatePressed()
{
    qDebug() << ses->getTablesLoaded();
    if (ses->getTablesLoaded() == 2)
    {
        updateEquivalents();
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
        u_widget *ukeys;
        ukeys = new u_widget(this,ses);
        QObject::connect(ukeys, SIGNAL(newOkKeys()), this, SLOT(onNewOkKeys()));

        qDebug() << "main window created ukeys";
        ukeys->show();
    }
}

void MainWindow::onNewOkKeys()
{
    qDebug() << "on new ok keys";
    Results *res;
    res = new Results(this,ses);

    QObject::connect(this, SIGNAL(newUpdateResultsChanged(QList<QStandardItem *>, QList<QStandardItem *>,
              int, int, int, int, QStandardItem &, QStandardItem &, QString &, QString &)), res,
                     SLOT(onNewUpdateResultsChanged(QList<QStandardItem *>, QList<QStandardItem *>, int, int, int, int, QStandardItem &,
                       QStandardItem &, QString &, QString &)));
    QObject::connect(this, SIGNAL(newUpdateResultsExtras(int, QList<QStandardItem *>)), res,
                     SLOT(onNewUpdateResultsExtras(int, QList<QStandardItem *>)));
    qDebug() << "main window created results";
    res->show();

    for (int i = 1; i <= numrows_one; i++)     // for each row in the first table
    {
        qDebug() << "FIRST TABLE: looking at row in table one, inside first loop";
        int rowsSkipped = 0;
        for (int j = 0; j < numrows_two; j++)    //for each row, check each row in 2nd table
        {
            qDebug() << "FIRST TABLE: looking at row in table two, inside second loop";
            int skipRow = 0;
            for (QString uniqueCol : ses->returnUniqueKeys())  //check entries in uniquekey columns
            {
                qDebug() << "FIRST TABLE: inside uniquekeys loop, checking unique keys";
                QString uniqueCol_two = ses->getEquivalent(uniqueCol);  //find matching column in 2nd table
                int ucol_num_one = ses->getColNum_one(uniqueCol);
                int ucol_num_two = ses->getColNum_two(uniqueCol_two);
                QStandardItem *uitemOne = csvModelOne->item(i, ucol_num_one);
                QStandardItem *uitemTwo = csvModelTwo->item(i, ucol_num_two);
                QString utextOne = uitemOne->text();             // get text from matched entries
                QString utextTwo = uitemTwo->text();

                if (utextOne != utextTwo)    //if the entries do not match
                {
                    qDebug() << "FIRST TABLE: found non matching uniquekeys";
                    skipRow = 1;
                    rowsSkipped++;    //keep count of skipped rows in 2nd table
                    break;            //skip checking other uniquecolumns
                }
             }

            if (skipRow) { continue; }     //skip row if not all uniquecolumns match
            qDebug() << "FIRST TABLE: not skipping row, checking other columns";


            for (QString colName_one : ses->returnCols_one())      //if all uniquecolumns match
            {
                if (!ses->inUniqueKeys(colName_one))            //check the remaining columns
                {
                    qDebug() << "FIRST TABLE: checking remaining columns";
                    QString colName_two = ses->getEquivalent(colName_one);
                    int col_num_one = ses->getColNum_one(colName_one);
                    int col_num_two = ses->getColNum_two(colName_two);
                    QStandardItem *itemOne = csvModelOne->item(i, col_num_one);
                    QStandardItem *itemTwo = csvModelTwo->item(i, col_num_two);
                    QString textOne = itemOne->text();
                    QString textTwo = itemTwo->text();

                    if (textOne != textTwo)                   //if there is a non-matching entry in any of the remaining columns
                    {
                        qDebug() << "FIRST TABLE: found non matching entry in remaining columns";
                        QList<QStandardItem *> changedItems_one;
                        for (QString q : ses->returnColOne_to_name())
                        {
                            int qcol = ses->getColNum_one(q);
                            QStandardItem *itm = csvModelOne->item(i, qcol);

                            QStandardItem *itm_prev = csvModelOne->item(i-1, qcol);
                            QStandardItem *itm_next = csvModelOne->item(i+1, qcol);

                            QString teststring = QString("Milestone Date");
                            int milestone_col = ses->getColNum_one(teststring);
                            qDebug() << "column number of milestone date: " << milestone_col;
                            //QStandardItem *itm_mile = csvModelOne->item(i, milestone_col);
                            //qDebug() << "item in milestone date: " << itm_mile->text();


                            qDebug() << "item before: " << itm_prev->text() << "  item after: " << itm_next->text();
                            QString txt = itm->text();
                            changedItems_one.append(new QStandardItem(txt));   //add item in the first row
                            qDebug() << "FIRST TABLE: added item to ROW of changedItems_ONE";
                            qDebug() << "FIRST TABLE: item added was " << txt << "IN COLUMN" << ses->getColOnetoName(qcol) << "NUMBER" << qcol;
                        }
                        qDebug() << "FIRST TABLE: before appending row number to CHANGEDITEMS_ONE";
                        changedItems_one.append(new QStandardItem(QString::number(i)));

                        qDebug() << "FIRST TABLE: after appending row number to CHANGEDITEMS_ONE";

                        QList<QStandardItem *> changedItems_two;
                        for (QString q : ses->returnColTwo_to_name())
                        {
                            int qcol = ses->getColNum_two(q);
                            QStandardItem *itm = csvModelOne->item(i, qcol);
                            QString txt = itm->text();
                            changedItems_two.append(new QStandardItem(txt));   //add item in the first row
                            qDebug() << "FIRST TABLE: added item to ROW of changedItems_TWO";
                            qDebug() << "FIRST TABLE: item added was " << txt << "IN COLUMN" << ses->getColTwotoName(qcol) << "NUMBER" << qcol;
                        }
                        qDebug() << "FIRST TABLE: before appending row number to CHANGEDITEMS_TWO";
                        changedItems_two.append(new QStandardItem(QString::number(i)));

                        qDebug() << "FIRST TABLE: BEFORE emitting CHANGED signal";
                        emit this->newUpdateResultsChanged(changedItems_one, changedItems_two, i, j, col_num_one, col_num_two,
                                                                           *itemOne, *itemTwo, textOne, textTwo);
                        qDebug() << "FIRST TABLE: emitted CHANGED signal";

                    }   //add entry to list of changed tables
                }

            }
        }

        qDebug() << "FIRST TABLE: before checking if row is not in table two";
        if (rowsSkipped == numrows_two){                //if all rows in the second table were skipped
            qDebug() << "FIRST TABLE: all rows in table two were skipped ROW IN TABLE ONE IS AN EXTRA ROW";
            QList<QStandardItem *> skippedRowItems;     //the row in the first table (i) is an extra row
            skippedRowItems.append(new QStandardItem(QString::number(i)));
            for (QString q : ses->returnColOne_to_name())
            {
                int qcol = ses->getColNum_one(q);
                QStandardItem *itm = csvModelOne->item(i, qcol);
                QString txt = itm->text();
                skippedRowItems.append(new QStandardItem(txt));   //add item in the first row
                qDebug() << "FIRST TABLE: added item to ROW of EXTRA items ONE";
                qDebug() << "FIRST TABLE: item added was " << txt << "IN COLUMN" << qcol;
            }
            emit this->newUpdateResultsExtras(1, skippedRowItems);     //add row to extras model
            qDebug() << "FIRST TABLE: emitted EXTRAS_ONE signal";

        }
     }

    QList<QString> uniqueKeysTwo = QList<QString>();
    QHash<QString, QString> reverseEquivalent = QHash<QString, QString>();
    qDebug() << "initialized uniqueKeysTwo and reverseEquivalent hash maps";
    for (QString fir : ses->returnUniqueKeys())   //get uniquekey columns in 2nd table
    {                                             //and reverse equivalents list
        QString sec = ses->getEquivalent(fir);
        uniqueKeysTwo.append(sec);
        reverseEquivalent[sec] = fir;
    }
    qDebug() << "updated reverseEquivalent hash map";

    for (int i = 0; i < numrows_two; i++)          //for each row in the second table
    {
         qDebug() << "SECOND TABLE: inside first loop, checking row of second table";
         int rowsSkipped = 0;
         for (int j = 0; j < numrows_one; j++)
         {
             qDebug() << "SECOND TABLE: inside second loop, checking row of first table";
             for (QString uniqueCol : uniqueKeysTwo)  //check entries in uniquekey columns
             {
                 qDebug() << "SECOND TABLE: inside uniquekeys loop, checking unique keys";
                 QString uniqueCol_two = reverseEquivalent[uniqueCol];  //find matching column in 1st table
                 int ucol_num_one = ses->getColNum_one(uniqueCol);
                 int ucol_num_two = ses->getColNum_two(uniqueCol_two);
                 QStandardItem *uitemOne = csvModelOne->item(i, ucol_num_one);
                 QStandardItem *uitemTwo = csvModelTwo->item(i, ucol_num_two);
                 QString utextOne = uitemOne->text();             // get text from matched entries
                 QString utextTwo = uitemTwo->text();

                 if (utextOne != utextTwo)    //if the entries do not match
                 {
                     qDebug() << "SECOND TABLE: found non matching uniquekeys";
                     rowsSkipped++;    //keep count of skipped rows in 1st table
                     break;            //skip checking other uniquecolumns
                 }
              }               //if entries match, continue loop and check other columns

         }

         if (rowsSkipped == numrows_one){                //if all rows in the first table were skipped
            qDebug() << "SECOND TABLE: skipped all rows in table one, this row is an EXTRA ROW IN TABLE TWO";
            QList<QStandardItem *> skippedRowTwoItems;     //the row in the second table (i) is an extra row
            skippedRowTwoItems.append(new QStandardItem(QString::number(i)));
            for (QString q : ses->returnColTwo_to_name())
            {
                int qcol = ses->getColNum_two(q);
                QStandardItem *itm2 = csvModelTwo->item(i, qcol);
                QString txt = itm2->text();
                skippedRowTwoItems.append(new QStandardItem(txt));   //add item in the first row
            }
            emit this->newUpdateResultsExtras(2, skippedRowTwoItems);     //add row to extras model
            qDebug() << "FIRST TABLE: emitted EXTRAS_ONE signal";
        }

    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

