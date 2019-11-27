#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QString>
#include <QDebug>
#include <session.h>

Dialog::Dialog(QWidget *parent, Session *s) :
    QDialog(parent),
    ui(new Ui::Dialog)

{
    ui->setupUi(this);
    s_ses = s;
    QString title = QString("Select CSV Files");
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

    // Connect button signal to appropriate slot
    QObject::connect(ui->pushButton, SIGNAL (released()), this, SLOT (handleButtonOne()));
    QObject::connect(ui->pushButton_2, SIGNAL (released()), this, SLOT (handleButtonTwo()));
    //QObject::connect(ui->pushButton_3, SIGNAL(released()), this, SLOT (onUpdatePressed()));
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT (onNewOkD1Pressed()));
    QObject::connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT (onNewCancelD1Pressed()));

    QObject::connect(this, SIGNAL(newTextOneEntered(const QString&)),
                     parent, SLOT(onNewTextOneEntered(const QString&)));
    QObject::connect(this, SIGNAL(newTextTwoEntered(const QString&)),
                     parent, SLOT(onNewTextTwoEntered(const QString&)));
    QObject::connect(this, SIGNAL(newUpdatePressed()),
                     parent, SLOT(onNewUpdatePressed()));

    filename_one = s_ses->getFileOnePath();
    filename_two = s_ses->getFileTwoPath();
    if (s_ses->getTablesLoaded() > 0)
    {
        if (filename_one != "")
        {
            ui->pushButton->setText("file currently selected");
            ui->plainTextEdit->insertPlainText(filename_one);
        }
        if (filename_two != "")
        {
            ui->pushButton_2->setText("file currently selected");
            ui->plainTextEdit_2->insertPlainText(filename_two);
        }
    }

    qDebug() << "connected signals on u_widget";
}

void Dialog::handleButtonOne()
{
   // change the text
   filename_one = QFileDialog::getOpenFileName(this, tr("Open CSV File"), "~/", tr("CSV Files (*.csv)"));
   qDebug() << filename_one;
   if (filename_one == "" && s_ses->getTablesLoaded() < 2)
   {
       ui->pushButton->setText("no file selected");
   }
   else if (filename_one == "" && s_ses->getTablesLoaded() == 2)
   {
       //do nothing
   }
   else
   {
       ui->pushButton->setText("file selected");
       ui->plainTextEdit->clear();
       ui->plainTextEdit->insertPlainText(filename_one);
       emit this->newTextOneEntered(ui->plainTextEdit->toPlainText());
   }
}

void Dialog::handleButtonTwo()
{
   filename_two = QFileDialog::getOpenFileName(this, tr("Open CSV File"), "~/", tr("CSV Files (*.csv)"));
   qDebug() << filename_two;
   if (filename_two == "" && s_ses->getTablesLoaded() < 2)
   {
       ui->pushButton_2->setText("no file selected");
   }
   else if (filename_one == "" && s_ses->getTablesLoaded() == 2)
   {
       //do nothing
   }
   else
   {
       ui->pushButton_2->setText("file selected");
       ui->plainTextEdit_2->clear();
       ui->plainTextEdit_2->insertPlainText(filename_two);
       emit this->newTextTwoEntered(ui->plainTextEdit_2->toPlainText());
   }
}

/*void Dialog::onUpdatePressed()
{
    emit this->newUpdatePressed();
} */

void Dialog::onNewOkD1Pressed()
{
    emit this->newUpdatePressed();
    accept();
}

void Dialog::onNewCancelD1Pressed()
{
    reject();
}


Dialog::~Dialog()
{
    delete ui;
}
