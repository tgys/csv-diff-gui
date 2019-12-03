/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionview_modified_rows;
    QAction *actionchoose_new_files;
    QAction *actionchange_column_options;
    QAction *actionsave_session;
    QAction *actionsave_session_as;
    QAction *actionselect_new_tables;
    QAction *actionmanual;
    QAction *actionview_results;
    QAction *actionexport_to_file;
    QAction *actionadd_primary_keys;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QTableView *tableView_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menufile;
    QMenu *menuedit;
    QMenu *menutools;
    QMenu *menuhelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionview_modified_rows = new QAction(MainWindow);
        actionview_modified_rows->setObjectName(QString::fromUtf8("actionview_modified_rows"));
        actionchoose_new_files = new QAction(MainWindow);
        actionchoose_new_files->setObjectName(QString::fromUtf8("actionchoose_new_files"));
        actionchange_column_options = new QAction(MainWindow);
        actionchange_column_options->setObjectName(QString::fromUtf8("actionchange_column_options"));
        actionsave_session = new QAction(MainWindow);
        actionsave_session->setObjectName(QString::fromUtf8("actionsave_session"));
        actionsave_session_as = new QAction(MainWindow);
        actionsave_session_as->setObjectName(QString::fromUtf8("actionsave_session_as"));
        actionselect_new_tables = new QAction(MainWindow);
        actionselect_new_tables->setObjectName(QString::fromUtf8("actionselect_new_tables"));
        actionmanual = new QAction(MainWindow);
        actionmanual->setObjectName(QString::fromUtf8("actionmanual"));
        actionview_results = new QAction(MainWindow);
        actionview_results->setObjectName(QString::fromUtf8("actionview_results"));
        actionexport_to_file = new QAction(MainWindow);
        actionexport_to_file->setObjectName(QString::fromUtf8("actionexport_to_file"));
        actionadd_primary_keys = new QAction(MainWindow);
        actionadd_primary_keys->setObjectName(QString::fromUtf8("actionadd_primary_keys"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        gridLayout->addWidget(tableView_2, 1, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menufile = new QMenu(menubar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menuedit = new QMenu(menubar);
        menuedit->setObjectName(QString::fromUtf8("menuedit"));
        menutools = new QMenu(menubar);
        menutools->setObjectName(QString::fromUtf8("menutools"));
        menuhelp = new QMenu(menubar);
        menuhelp->setObjectName(QString::fromUtf8("menuhelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menufile->menuAction());
        menubar->addAction(menuedit->menuAction());
        menubar->addAction(menutools->menuAction());
        menubar->addAction(menuhelp->menuAction());
        menufile->addAction(actionsave_session);
        menufile->addAction(actionsave_session_as);
        menufile->addAction(actionexport_to_file);
        menuedit->addAction(actionchange_column_options);
        menuedit->addAction(actionselect_new_tables);
        menuedit->addAction(actionadd_primary_keys);
        menutools->addAction(actionview_results);
        menuhelp->addAction(actionmanual);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionview_modified_rows->setText(QCoreApplication::translate("MainWindow", "modified rows", nullptr));
#if QT_CONFIG(shortcut)
        actionview_modified_rows->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionchoose_new_files->setText(QCoreApplication::translate("MainWindow", "select new tables  <Ctrl+T>", nullptr));
#if QT_CONFIG(shortcut)
        actionchoose_new_files->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionchange_column_options->setText(QCoreApplication::translate("MainWindow", "column options", nullptr));
#if QT_CONFIG(shortcut)
        actionchange_column_options->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionsave_session->setText(QCoreApplication::translate("MainWindow", "save session", nullptr));
#if QT_CONFIG(shortcut)
        actionsave_session->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionsave_session_as->setText(QCoreApplication::translate("MainWindow", "save session as", nullptr));
#if QT_CONFIG(shortcut)
        actionsave_session_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionselect_new_tables->setText(QCoreApplication::translate("MainWindow", "select new tables", nullptr));
#if QT_CONFIG(shortcut)
        actionselect_new_tables->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionmanual->setText(QCoreApplication::translate("MainWindow", "manual", nullptr));
#if QT_CONFIG(shortcut)
        actionmanual->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionview_results->setText(QCoreApplication::translate("MainWindow", "view results", nullptr));
        actionexport_to_file->setText(QCoreApplication::translate("MainWindow", "export to file", nullptr));
        actionadd_primary_keys->setText(QCoreApplication::translate("MainWindow", "add primary keys", nullptr));
#if QT_CONFIG(shortcut)
        actionadd_primary_keys->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+P", nullptr));
#endif // QT_CONFIG(shortcut)
        label_2->setText(QCoreApplication::translate("MainWindow", "select a csv file for table two", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "number of rows in table one changed", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "number of rows in table two changed:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "select a csv file for table one", nullptr));
        menufile->setTitle(QCoreApplication::translate("MainWindow", "file", nullptr));
        menuedit->setTitle(QCoreApplication::translate("MainWindow", "edit", nullptr));
        menutools->setTitle(QCoreApplication::translate("MainWindow", "tools", nullptr));
        menuhelp->setTitle(QCoreApplication::translate("MainWindow", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
