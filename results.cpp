#include "results.h"
#include "ui_results.h"

Results::Results(QWidget *parent, Session *s) :
    QDialog(parent),
    ui(new Ui::Results)
{
    ui->setupUi(this);

    diffModel = new QStandardItemModel(this);
    ui->tableView->setModel(diffModel);
    extrasModel = new QStandardItemModel(this);
    ui->tableView_2->setModel(extrasModel);

}

void Results::onNewUpdateResultsExtras(int row, int one_or_two, QList<QStandardItem *> items)
{

}

void Results::onNewUpdateResultsChanged(int row_one, int row_two, int col_one, int col_two, QStandardItem *item_one,
                       QStandardItem *item_two, QString &text1, QString &text2)
{

}


Results::~Results()
{
    delete ui;
}
