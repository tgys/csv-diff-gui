#ifndef RESULTS_H
#define RESULTS_H

#include <QDialog>
#include <QStandardItemModel>
#include "session.h"

namespace Ui {
class Results;
}

class Results : public QDialog
{
    Q_OBJECT

public:
    explicit Results(QWidget *parent = nullptr, Session *s = nullptr);
    ~Results();

public slots:
    void onNewUpdateResultsChanged(QList<QStandardItem *> itemsOne, QList<QStandardItem *> itemsTwo,
               int row_one, int row_two, int col_one, int col_two, QStandardItem &item_one,
                       QStandardItem &item_two, QString &text1, QString &text2);
    void onNewUpdateResultsExtras(int one_or_two, QList<QStandardItem *> items);

private:
    Ui::Results *ui;
    Session *r_ses;
    QStandardItemModel *diffModel;
    QStandardItemModel *extrasModel_one;
    QStandardItemModel *extrasModel_two;
};

#endif // RESULTS_H
