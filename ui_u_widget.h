/********************************************************************************
** Form generated from reading UI file 'u_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_U_WIDGET_H
#define UI_U_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_u_widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QListView *listView;
    QListView *listView_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QListView *listView_3;
    QListView *listView_4;
    QComboBox *comboBox_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;

    void setupUi(QDialog *u_widget)
    {
        if (u_widget->objectName().isEmpty())
            u_widget->setObjectName(QString::fromUtf8("u_widget"));
        u_widget->resize(537, 597);
        gridLayout = new QGridLayout(u_widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(u_widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(u_widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 2);

        listView = new QListView(u_widget);
        listView->setObjectName(QString::fromUtf8("listView"));

        gridLayout->addWidget(listView, 1, 0, 1, 1);

        listView_2 = new QListView(u_widget);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));

        gridLayout->addWidget(listView_2, 1, 1, 1, 2);

        comboBox = new QComboBox(u_widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 0, 1, 2);

        pushButton = new QPushButton(u_widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(u_widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 0, 1, 1);

        label_4 = new QLabel(u_widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label_5 = new QLabel(u_widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 1, 1, 2);

        listView_3 = new QListView(u_widget);
        listView_3->setObjectName(QString::fromUtf8("listView_3"));

        gridLayout->addWidget(listView_3, 6, 0, 1, 1);

        listView_4 = new QListView(u_widget);
        listView_4->setObjectName(QString::fromUtf8("listView_4"));

        gridLayout->addWidget(listView_4, 6, 1, 1, 2);

        comboBox_2 = new QComboBox(u_widget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 7, 0, 1, 2);

        pushButton_3 = new QPushButton(u_widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 8, 0, 1, 1);

        pushButton_4 = new QPushButton(u_widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 9, 0, 1, 1);

        buttonBox = new QDialogButtonBox(u_widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 9, 1, 1, 2);

        label_2 = new QLabel(u_widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 8, 2, 1, 1);


        retranslateUi(u_widget);

        QMetaObject::connectSlotsByName(u_widget);
    } // setupUi

    void retranslateUi(QDialog *u_widget)
    {
        u_widget->setWindowTitle(QCoreApplication::translate("u_widget", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("u_widget", "current primary keys", nullptr));
        label_3->setText(QCoreApplication::translate("u_widget", "keys to add", nullptr));
        pushButton->setText(QCoreApplication::translate("u_widget", "add primary key", nullptr));
        pushButton_2->setText(QCoreApplication::translate("u_widget", "remove primary key", nullptr));
        label_4->setText(QCoreApplication::translate("u_widget", "excluded keys", nullptr));
        label_5->setText(QCoreApplication::translate("u_widget", "keys to exclude", nullptr));
        pushButton_3->setText(QCoreApplication::translate("u_widget", "add to exclude list", nullptr));
        pushButton_4->setText(QCoreApplication::translate("u_widget", "remove from exclude list", nullptr));
        label_2->setText(QCoreApplication::translate("u_widget", "   Start Diff?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class u_widget: public Ui_u_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_U_WIDGET_H
