#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    Q_INVOKABLE QString getFileOne(){
        return QFileDialog::getOpenFileName(nullptr, "Choose your first file", "", "csv files (*.csv)");
    }
    Q_INVOKABLE QString getFileTwo(){
        return QFileDialog::getOpenFileName(nullptr, "Choose your second file", "", "csv files (*.csv)");
    }
private slots:
   void handleButtonOne();
   void handleButtonTwo();
   void onUpdatePressed();

signals:
  void newTextOneEntered(const QString &text);
  void newTextTwoEntered(const QString &text);
  void newUpdatePressed();

private:
    Ui::Dialog *ui;
    QString filename_one;
    QString filename_two;
};

#endif // DIALOG_H
