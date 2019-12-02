#include "results.h"
#include "ui_results.h"
#include <QTableWidgetItem>
#include <QDebug>
#include <QFileDialog>

Results::Results(QWidget *parent, Session *s) :
    QDialog(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);
    QString title = QString("View Results");
    this->setWindowTitle(title);

    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        this->setStyleSheet(ts.readAll());
    }

    r_ses = s;
    diffOneModel = new QStandardItemModel(this);
    ui->tableView->setModel(diffOneModel);
    diffTwoModel = new QStandardItemModel(this);
    ui->tableView_4->setModel(diffTwoModel);
    extrasModel_one = new QStandardItemModel(this);
    ui->tableView_2->setModel(extrasModel_one);
    extrasModel_two = new QStandardItemModel(this);
    ui->tableView_3->setModel(extrasModel_two);

    ui->tabWidget->setTabText(0,"Changed Rows");
    ui->tabWidget->setTabText(1, "Extra Rows");

}

void Results::onNewUpdateResultsExtras(int one_or_two, QList<QStandardItem *> items)
{
    if (one_or_two == 1)   //if extra row is in table one
    {                                            //add row to tableView_2
       // qDebug() << "RESULTS: row is in table one";
        extrasModel_one->insertRow(extrasModel_one->rowCount(), items);
       // qDebug() << "RESULTS: added TABLE ONE row to extras model";
    }
    else   //extra row is in table two
    {
       // qDebug() << "RESULTS: row is in table two";
        extrasModel_two->insertRow(extrasModel_two->rowCount(), items);  //add row to tableView_3
       // qDebug() << "RESULTS: added TABLE TWO row to extras model";
    }
}

void Results::onNewUpdateResultsChanged(QList<QStandardItem *> itemsOne, QList<QStandardItem *> itemsTwo,
                    int row_one, int row_two, int col_one, int col_two, QStandardItem &item_one,
                QStandardItem &item_two, QString &text1, QString &text2)
{
        if (!checked_one.contains(row_one))
        {
             diffOneModel->insertRow(diffOneModel->rowCount(), itemsOne);
             checked_one.insert(row_one);
        }

        if (!checked_two.contains(row_two))
        {
             diffTwoModel->insertRow(diffTwoModel->rowCount(), itemsTwo);
             checked_two.insert(row_two);
        }

        for (QString col : r_ses->returnColOne_to_name())
        {
            int colnum_one = r_ses->getColNum_one(col);
            diffOneModel->setHeaderData(colnum_one, Qt::Horizontal, col );
            extrasModel_one->setHeaderData(colnum_one, Qt::Horizontal, col );

        }
        for (QString col : r_ses->returnColTwo_to_name())
        {
             int colnum_two = r_ses->getColNum_two(col);
             diffTwoModel->setHeaderData(colnum_two, Qt::Horizontal, col );
             extrasModel_two->setHeaderData(colnum_two, Qt::Horizontal, col );
        }


        extrasModel_two->setHeaderData(23, Qt::Horizontal, tr("ROW"));
        extrasModel_one->setHeaderData(23, Qt::Horizontal, tr("ROW"));
        diffOneModel->setHeaderData(23, Qt::Horizontal, tr("ROW"));
        diffTwoModel->setHeaderData(23, Qt::Horizontal, tr("ROW"));
      //  qDebug() << "finished inserting into results changed table";
}


Results::~Results()
{
    delete ui;
    delete r_ses;
    delete diffOneModel;
    delete diffTwoModel;
    delete extrasModel_one;
    delete extrasModel_two;
}
