#ifndef UNIQUEKEYS_H
#define UNIQUEKEYS_H

#include <QDialog>
#include <QStandardItemModel>
#include "session.h"

namespace Ui {
class UniqueKeys;
}

class UniqueKeys : public QDialog
{
    Q_OBJECT

public:
    explicit UniqueKeys(QWidget *parent = nullptr, Session *ses = nullptr);
    void updateList();
    ~UniqueKeys();

private slots:
    void onNewBoxActivated(const QString &text);
    void onNewKeyUpdate();
    void onNewKeyRemove();
    void onNewOkPressed();

signals:
    void newOkKeys();

private:
    Ui::UniqueKeys *ui;
    Session *k_ses;
    QStandardItemModel *keyModel;
    QList<QString> keylist;
    QString currentCol;
};

#endif // UNIQUEKEYS_H
