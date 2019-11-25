#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "session.h"
#include "uniquekeys.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void onNewTextOneEntered(const QString &text);
    void onNewTextTwoEntered(const QString &text);
    void onNewUpdatePressed();
    void onNewOkColumns();
    void onNewOkKeys();

signals:
    void newUpdateResultsChanged(int row_one, int row_two, int col_one, int col_two, QStandardItem *item_one,
                       QStandardItem *item_two, QString &text1, QString &text2);
    void newUpdateResultsExtras(int row, int one_or_two, QList<QStandardItem *> items);

public:
    MainWindow(QWidget *parent = nullptr);
    void updateTableOne();
    void updateTableTwo();
    void getDiffs();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Session *ses;
    QStandardItemModel *csvModelOne;
    QStandardItemModel *csvModelTwo;

    int numrows_one;
    int numrows_two;
};
#endif // MAINWINDOW_H
