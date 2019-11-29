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
    keyModel = new QStandardItemModel(this);
    ui->listView->setModel(keyModel);
    keyAddModel = new QStandardItemModel(this);
    ui->listView_2->setModel(keyAddModel);
    keyModel->clear();
    for (QString item : k_ses->returnUniqueKeys()) {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(item));
        keyModel->insertRow(keyModel->rowCount(), rowItems);
    }

    num_instances++;
    this->setWindowFlags(Qt::FramelessWindowHint| Qt::Dialog);
    qDebug() << "setting window flags on u_widget";
    QObject::connect(ui->pushButton, SIGNAL(released()), this, SLOT (onNewKeyUpdate()));
    QObject::connect(ui->pushButton_2, SIGNAL(released()), this, SLOT (onNewKeyRemove()));
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

void u_widget::onNewBoxActivated(const QString &col)
{
    currentCol = col;
    qDebug() << "number of instances of uniquekeys " << num_instances;
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
