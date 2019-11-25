#ifndef U_WIDGET_H
#define U_WIDGET_H

#include <QGroupBox>
#include <QStandardItemModel>
#include "session.h"

namespace Ui {
class u_widget;
}

class u_widget : public QGroupBox
{
    Q_OBJECT

public:
    explicit u_widget(QWidget *parent = nullptr, Session *ses = nullptr);
    void updateList();
    ~u_widget();

private slots:
    void onNewBoxActivated(const QString &text);
    void onNewKeyUpdate();
    void onNewKeyRemove();
    void onNewOkPressed();

signals:
    void newOkKeys();

private:
    Ui::u_widget *ui;
    Session *k_ses;
    QStandardItemModel *keyModel;
    QList<QString> keylist = QList<QString>();
    QString currentCol;
    int num_instances = 0;
};

#endif // U_WIDGET_H
