#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <QStandardItemModel>
#include "session.h"

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr, Session *s = nullptr);
    void updateEquivalents();
    ~Dialog2();

public slots:
    void onNewColOneEntered(const QString &col1);
    void onNewColTwoEntered(const QString &col2);

private:
    Ui::Dialog2 *ui;
    QStandardItemModel *eqvModel;
    QStandardItemModel *modModel;
};

#endif // DIALOG2_H
