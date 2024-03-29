#include "u_widget.h"
#include "ui_u_widget.h"
#include <QDebug>
#include <QFileDialog>

u_widget::u_widget(QWidget *parent, Session *s) :
    QDialog(parent),
    ui(new Ui::u_widget)
{
    ui->setupUi(this);
    QString title = QString("Set Primary keys");
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

    k_ses = s;
    ui->comboBox->addItems(k_ses->returnCols_one());
    ui->comboBox_2->addItems(k_ses->returnCols_one());

    keyModel = new QStandardItemModel(this);
    ui->listView->setModel(keyModel);
    keyAddModel = new QStandardItemModel(this);
    ui->listView_2->setModel(keyAddModel);
    exModel = new QStandardItemModel(this);
    ui->listView_3->setModel(exModel);
    exAddModel = new QStandardItemModel(this);
    ui->listView_4->setModel(exAddModel);

    currentCol = ui->comboBox->itemText(ui->comboBox->currentIndex());
    currExCol = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());

    keyModel->clear();
    for (QString item : k_ses->returnUniqueKeys()) {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(item));
        keyModel->insertRow(keyModel->rowCount(), rowItems);
    }

    exModel->clear();
    for (QString item : k_ses->returnExcludeKeys()) {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(item));
        exModel->insertRow(exModel->rowCount(), rowItems);
    }

    num_instances++;
    this->setWindowFlags(Qt::FramelessWindowHint| Qt::Dialog);
    qDebug() << "setting window flags on u_widget";
    QObject::connect(ui->pushButton, SIGNAL(released()), this, SLOT (onNewKeyUpdate()));
    QObject::connect(ui->pushButton_2, SIGNAL(released()), this, SLOT (onNewKeyRemove()));
    QObject::connect(ui->pushButton_3, SIGNAL(released()), this, SLOT (onNewExUpdate()));
    QObject::connect(ui->pushButton_4, SIGNAL(released()), this, SLOT (onNewExRemove()));
    QObject::connect(ui->comboBox_2, SIGNAL(activated(const QString &)),
                     this, SLOT(onNewBoxTwoActivated(const QString &)));
    QObject::connect(ui->comboBox, SIGNAL(activated(const QString &)),
                     this, SLOT(onNewBoxActivated(const QString &)));
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT (onNewOkPressed()));
    QObject::connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT (onNewCancelKeysPressed()));
    qDebug() << "connected signals on u_widget";
}

void u_widget::updateAddList()
{
    for (QString item : keylist) {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(item));
        keyAddModel->insertRow(keyAddModel->rowCount(), rowItems);
       // keyModel->insertRow(keyModel->rowCount(), rowItems);
    }
}


void u_widget::updateExAddList()
{
   for (QString item : exlist) {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(item));
        exAddModel->insertRow(exAddModel->rowCount(), rowItems);
    }
}

void u_widget::onNewBoxActivated(const QString &col)
{
    currentCol = col;
    qDebug() << "number of instances of uniquekeys " << num_instances;
}

void u_widget::onNewBoxTwoActivated(const QString &col)
{
    currExCol = col;
}

void u_widget::onNewExUpdate()
{
    if (currExCol != "")
    {
        exlist.append(currExCol);
        qDebug() << "added to exclude list " << currExCol;
        exAddModel->clear();
        updateExAddList();
    }
}

void u_widget::onNewExRemove()
{
    exlist.removeAll(currExCol);
    qDebug() << "removed from exclude list " << currExCol;
    exAddModel->clear();
    updateExAddList();
}

void u_widget::onNewKeyUpdate()
{
    if (currentCol != "")
    {
        keylist.append(currentCol);
        qDebug() << "added to primary keys list " << currentCol;
        keyAddModel->clear();
        updateAddList();
    }
}

void u_widget::onNewKeyRemove()
{
    keylist.removeAll(currentCol);
    qDebug() << "removed from primary keys list " << currentCol;
    keyAddModel->clear();
    updateAddList();
}

void u_widget::onNewOkPressed()
{
     k_ses->clearUniqueKeys();
     for (QString item : keylist)
     {
         if (!k_ses->inUniqueKeys(item)) { k_ses->addUniqueKey(item); }
         if (!k_ses->inExcludeKeys(item)) { k_ses->addExcludeKey(item); }
         qDebug() << "setting uniquekeys from keylist";
     }
     emit this->newOkKeys();
     accept();
}

void u_widget::onNewCancelKeysPressed()
{
    qDebug() << "on cancel keys slot";
    reject();
}



u_widget::~u_widget()
{
    delete ui;
    delete k_ses;
    delete keyAddModel;
    delete keyModel;
}
