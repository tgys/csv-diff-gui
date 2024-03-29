#include "dialog2.h"
#include "ui_dialog2.h"
#include <QDebug>
#include <QFileDialog>

Dialog2::Dialog2(QWidget *parent, Session *s) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    QString title = QString("Select Column Options");
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

    d_ses = s;
    ui->comboBox->addItems(d_ses->returnCols_one());
    ui->comboBox_2->addItems(d_ses->returnCols_two());
    eqvModel = new QStandardItemModel(this);
    ui->tableView->setModel(eqvModel);
    modModel = new QStandardItemModel(this);
    ui->tableView_2->setModel(modModel);
    modified = d_ses->returnModified();

    qDebug() << "currentIndex = " << ui->comboBox->currentIndex();
    qDebug() << "currentIndex = " << ui->comboBox_2->currentIndex();

    currentColOne = ui->comboBox->itemText(ui->comboBox->currentIndex());
    currentColTwo = ui->comboBox_2->itemText(ui->comboBox_2->currentIndex());

    QObject::connect(ui->comboBox, SIGNAL(activated(const QString &)),
                     this, SLOT(onBoxOneActivated(const QString &)));
    QObject::connect(ui->comboBox_2, SIGNAL(activated(const QString &)),
                     this, SLOT(onBoxTwoActivated(const QString &)));
    QObject::connect(ui->pushButton, SIGNAL(released()), this, SLOT (onNewColumnUpdate()));
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT (onNewOkPressed()));

    updateTable();
}

void Dialog2::updateTable()
{
    for (QString item : d_ses->returnColOne_to_name()) {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(item));
        int itemCol = d_ses->getColNum_one(item);
        qDebug() << "item column number: " << itemCol;
        rowItems.append(new QStandardItem(QString::number(itemCol)));
        QString eq = d_ses->getEquivalent(item);
        qDebug() << "equivalent is : " << eq;
        rowItems.append(new QStandardItem(eq));
        int eqCol = d_ses->getColNum_two(eq);
        qDebug() << "eq column number: " << eqCol;
        rowItems.append(new QStandardItem(QString::number(eqCol)));
        eqvModel->insertRow(eqvModel->rowCount(), rowItems);
    }
     eqvModel->setHeaderData(0, Qt::Horizontal, tr("First Table"));
    eqvModel->setHeaderData(1, Qt::Horizontal, tr("1st Columns"));
    eqvModel->setHeaderData(2, Qt::Horizontal, tr("Second Table"));
    eqvModel->setHeaderData(3, Qt::Horizontal, tr("2nd Columns"));
}

void Dialog2::updateMods()
{
    for (QString item : modified)
    {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(item));
        int itemCol = d_ses->getColNum_one(item);
        rowItems.append(new QStandardItem(QString::number(itemCol)));
        QString eq = (modified)[item];
        rowItems.append(new QStandardItem(eq));
        int eqCol = d_ses->getColNum_two(eq);
        rowItems.append(new QStandardItem(QString::number(eqCol)));
        modModel->insertRow(modModel->rowCount(), rowItems);
    }

}


void Dialog2::onBoxOneActivated(const QString &col)
{
      currentColOne = col;
      qDebug() << "current col one value: " << col;
}

void Dialog2::onBoxTwoActivated(const QString &col)
{
      currentColTwo = col;
      qDebug() << "current col two value: " << col;
}

void Dialog2::onNewColumnUpdate()
{
      d_ses->setEquivalent(currentColOne, currentColTwo);
      qDebug() << "set equivalents";
      modified[currentColOne] = currentColTwo;
      qDebug() << "set modified one";
     // d_ses->setModified(currentColOne, currentColTwo);
      if (d_ses->returnCols_one().contains(currentColTwo))
            {
                d_ses->setEquivalent(currentColTwo, currentColOne);
                //d_ses->setModified(currentColTwo, currentColOne);
                modified[currentColTwo] = currentColOne;
            }
      modModel->clear();
      updateMods();
      eqvModel->clear();
      updateTable();
      qDebug() << "current modified columns : " << currentColOne << " " << currentColTwo;
}

void Dialog2::onNewOkPressed()
{
     for (QString item : modified)
     {
         d_ses->setModified(item, (modified)[item]);
         qDebug() << "setting modified : " << item << d_ses->getModified(item);
     }
     emit this->newOkColumns();
     accept();
     qDebug() << "emitted newokColumns ";
}

Dialog2::~Dialog2()
{
    delete ui;
    delete d_ses;
    delete eqvModel;
    delete modModel;
}
