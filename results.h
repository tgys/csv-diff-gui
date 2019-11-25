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
    void updateChanged(int row_one, int row_two, int col_one, int col_two, QStandardItem *item_one,
                       QStandardItem *item_two, QString &text1, QString &text2);
    void updateExtras(int row, int one_or_two, QList<QStandardItem *> items);
    ~Results();

private:
    Ui::Results *ui;
    QStandardItemModel *diffModel;
    QStandardItemModel *extrasModel;
};

#endif // RESULTS_H
