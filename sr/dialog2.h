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
    void updateTable();
    void updateMods();
    void updateEquivalents();
    ~Dialog2();

private slots:
    void onBoxOneActivated(const QString &text);
    void onBoxTwoActivated(const QString &text);
    void onNewColumnUpdate();
    void onNewOkPressed();

signals:
    void newOkColumns();

private:
    Ui::Dialog2 *ui;
    QStandardItemModel *eqvModel;
    QStandardItemModel *modModel;
    QHash<QString, QString> modified;
    Session *d_ses;
    QString currentColOne;
    QString currentColTwo;
};

#endif // DIALOG2_H
