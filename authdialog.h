#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>

namespace Ui {
class AuthDialog; // класс окошка авторизации
}

class AuthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AuthDialog(QWidget *parent = nullptr);
    ~AuthDialog();

    // полученное имя пользователя(в конструкторе инициализировано как ""), тогда если авторизация неудачна, то переменная будет пуста
    QString gotUserName;

private slots:

    void on_OKButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AuthDialog *ui;
};

#endif // AUTHDIALOG_H
