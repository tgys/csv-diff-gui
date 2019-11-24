#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QString>
#include <QDebug>
#include <session.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)

{
    ui->setupUi(this);
    // Connect button signal to appropriate slot
    connect(ui->pushButton, SIGNAL (released()), this, SLOT (handleButtonOne()));
    connect(ui->pushButton_2, SIGNAL (released()), this, SLOT (handleButtonTwo()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT (onUpdatePressed()));
}

void Dialog::handleButtonOne()
{
   // change the text
   filename_one = QFileDialog::getOpenFileName(this, tr("Open CSV File"), "~/", tr("CSV Files (*.csv)"));
   qDebug() << filename_one;
   ui->pushButton->setText("file selected");
   ui->plainTextEdit->clear();
   ui->plainTextEdit->insertPlainText(filename_one);
   emit this->newTextOneEntered(ui->plainTextEdit->toPlainText());
}

void Dialog::handleButtonTwo()
{
   filename_two = QFileDialog::getOpenFileName(this, tr("Open CSV File"), "~/", tr("CSV Files (*.csv)"));
   qDebug() << filename_two;
   ui->pushButton_2->setText("file selected");
   ui->plainTextEdit_2->clear();
   ui->plainTextEdit_2->insertPlainText(filename_two);
   emit this->newTextTwoEntered(ui->plainTextEdit_2->toPlainText());
}

void Dialog::onUpdatePressed()
{
    emit this->newUpdatePressed();
}


Dialog::~Dialog()
{
    delete ui;
}
