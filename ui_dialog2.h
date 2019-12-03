/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label_2;
    QTableView *tableView;
    QLabel *label;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QLabel *label_5;
    QTableView *tableView_2;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;
    QLabel *label_4;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName(QString::fromUtf8("Dialog2"));
        Dialog2->resize(958, 634);
        gridLayout = new QGridLayout(Dialog2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(Dialog2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 7, 1, 1, 1);

        label_2 = new QLabel(Dialog2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        tableView = new QTableView(Dialog2);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 1, 1, 1);

        label = new QLabel(Dialog2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 3, 1, 1);

        comboBox_2 = new QComboBox(Dialog2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 3, 4, 1, 1);

        label_3 = new QLabel(Dialog2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        label_5 = new QLabel(Dialog2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 4, 1, 1);

        tableView_2 = new QTableView(Dialog2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        gridLayout->addWidget(tableView_2, 1, 4, 1, 1);

        comboBox = new QComboBox(Dialog2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 3, 1, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog2);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 7, 4, 1, 1);

        label_4 = new QLabel(Dialog2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);


        retranslateUi(Dialog2);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog2, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog2, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QCoreApplication::translate("Dialog2", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog2", "update column pairs", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog2", "current pairs", nullptr));
        label->setText(QCoreApplication::translate("Dialog2", "=", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog2", "modified pairs", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog2", "column in table 2:", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog2", "column in table 1:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
