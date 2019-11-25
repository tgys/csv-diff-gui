#include "results.h"
#include "ui_results.h"
#include <QTableWidgetItem>

Results::Results(QWidget *parent, Session *s) :
    QDialog(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);
    r_ses = s;

    diffModel = new QStandardItemModel(this);
    ui->tableView->setModel(diffModel);
    extrasModel_one = new QStandardItemModel(this);
    ui->tableView_2->setModel(extrasModel_one);
    extrasModel_two = new QStandardItemModel(this);
    ui->tableView_3->setModel(extrasModel_two);

    for (QString col : r_ses->returnCols_one())
    {
        int colnum_one = r_ses->getColNum_one(col);
        diffModel->setHeaderData(colnum_one, Qt::Horizontal, col );
        extrasModel_one->setHeaderData(colnum_one, Qt::Horizontal, col );
    }

    extrasModel_one->setHeaderData(0, Qt::Horizontal, tr("ROW"));
    diffModel->setHeaderData(0, Qt::Horizontal, tr("ROW"));

    for (QString col : r_ses->returnCols_two())
    {
        int colnum_two = r_ses->getColNum_two(col);
        extrasModel_two->setHeaderData(colnum_two, Qt::Horizontal, col );
    }

    extrasModel_two->setHeaderData(0, Qt::Horizontal, tr("ROW"));

}

void Results::onNewUpdateResultsExtras(int one_or_two, QList<QStandardItem *> items)
{
    if (one_or_two == 1)   //if extra row is in table one
    {                                            //add row to tableView_2
        extrasModel_one->insertRow(extrasModel_one->rowCount(), items);
    }
    else   //extra row is in table two
    {
        extrasModel_two->insertRow(extrasModel_two->rowCount(), items);  //add row to tableView_3
    }
}

void Results::onNewUpdateResultsChanged(QList<QStandardItem *> itemsOne, QList<QStandardItem *> itemsTwo,
                    int row_one, int row_two, int col_one, int col_two, QStandardItem *item_one,
                QStandardItem *item_two, QString &text1, QString &text2)
{
        diffModel->insertRow(diffModel->rowCount(), itemsOne);
        diffModel->insertRow(diffModel->rowCount(), itemsTwo);
}


Results::~Results()
{
    delete ui;
}
