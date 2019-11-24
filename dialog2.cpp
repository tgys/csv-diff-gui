#include "dialog2.h"
#include "ui_dialog2.h"
#include <QDebug>

Dialog2::Dialog2(QWidget *parent, Session *s) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    ui->comboBox->addItems(s->returnCols_one());
    ui->comboBox_2->addItems(s->returnCols_two());
    eqvModel = new QStandardItemModel(this);
    ui->tableView->setModel(eqvModel);
    modModel = new QStandardItemModel(this);
    ui->tableView_2->setModel(modModel);
    for (QString item : s->returnCols_one()) {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(item));
        QString eq = s->getEquivalent(item);
        qDebug() << "equivalent is : " << eq;
        rowItems.append(new QStandardItem(eq));
        eqvModel->insertRow(eqvModel->rowCount(), rowItems);
    }

    //qDebug() << s->returnCols_one().last();
  //  qDebug() <<
}


void Dialog2::onNewColOneEntered(const QString &col1)
{

}

void Dialog2::onNewColTwoEntered(const QString &col2)
{

}

Dialog2::~Dialog2()
{
    delete ui;
}
