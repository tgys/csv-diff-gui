#include "uniquekeys.h"
#include "ui_uniquekeys.h"
#include <QDebug>

UniqueKeys::UniqueKeys(QWidget *parent, Session *s) :
    QDialog(parent),
    ui(new Ui::UniqueKeys)
{
    ui->setupUi(this);
    k_ses = s;
    ui->comboBox->addItems(k_ses->returnCols_one());
    keyModel = new QStandardItemModel(this);
    ui->listView->setModel(keyModel);
    num_instances++;

    QObject::connect(ui->pushButton, SIGNAL(released()), this, SLOT (onNewKeyUpdate()));
    QObject::connect(ui->pushButton_2, SIGNAL(released()), this, SLOT (onNewKeyRemove()));
    QObject::connect(ui->comboBox, SIGNAL(activated(const QString &)),
                     this, SLOT(onNewBoxActivated(const QString &)));
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT (onNewOkPressed()));

}


void UniqueKeys::updateList()
{
    for (QString item : keylist) {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(item));
        keyModel->insertRow(keyModel->rowCount(), rowItems);
    }
}

void UniqueKeys::onNewBoxActivated(const QString &col)
{
    currentCol = col;
    qDebug() << "number of instances of uniquekeys " << num_instances;
}

void UniqueKeys::onNewKeyUpdate()
{
    keylist.append(currentCol);
    qDebug() << "added unique key " << currentCol;
    keyModel->clear();
    updateList();
}

void UniqueKeys::onNewKeyRemove()
{
    keylist.removeAll(currentCol);
    qDebug() << "removed unique key " << currentCol;
    keyModel->clear();
    updateList();
}


void UniqueKeys::onNewOkPressed()
{
     k_ses->clearUniqueKeys();
     for (QString item : keylist)
     {
         k_ses->addUniqueKey(item);
         qDebug() << "setting uniquekeys from keylist";
         emit this->newOkKeys();
         accept();
     }
}

UniqueKeys::~UniqueKeys()
{
    delete ui;
}
