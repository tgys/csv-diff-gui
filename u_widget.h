#ifndef U_WIDGET_H
#define U_WIDGET_H

#include <QGroupBox>
#include <QDialog>
#include <QStandardItemModel>
#include "session.h"

namespace Ui {
class u_widget;
}

class u_widget : public QDialog
{
    Q_OBJECT

public:
    explicit u_widget(QWidget *parent = nullptr, Session *ses = nullptr);
    void updateAddList();
    void updateExAddList();
    void updateSesList();
    ~u_widget();

private slots:
    void onNewBoxActivated(const QString &text);
    void onNewKeyUpdate();
    void onNewKeyRemove();
    void onNewExUpdate();
    void onNewExRemove();
    void onNewBoxTwoActivated(const QString &text);
    void onNewOkPressed();
    void onNewCancelKeysPressed();

signals:
    void newOkKeys();

private:
    Ui::u_widget *ui;
    Session *k_ses;
    QStandardItemModel *keyModel;
    QStandardItemModel *keyAddModel;
    QStandardItemModel *exModel;
    QStandardItemModel *exAddModel;
    QList<QString> keylist = QList<QString>();
    QList<QString> exlist = QList<QString>();
    QString currentCol;
    QString currExCol;
    int num_instances = 0;
};

#endif // U_WIDGET_H
