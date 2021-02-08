#include "authdialog.h"
#include "ui_authdialog.h"
#include <QSettings>
#include <QMessageBox>

AuthDialog::AuthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthDialog)
{
    ui->setupUi(this);

    gotUserName = "";

}

AuthDialog::~AuthDialog()
{
    delete ui;
}

void AuthDialog::on_OKButton_clicked()
{
    if (ui->loginEdit->text()=="") ui->loginEdit->setFocus();
    else if (ui->passEdit->text()=="") ui->passEdit->setFocus();
        else {

        // открываем иник(формат "login=password")
        QSettings userData("users.ini", QSettings::IniFormat);

        // если введенные логи ни пароль совпадают
        if (userData.value(ui->loginEdit->text()).toString()==ui->passEdit->text()) {
            gotUserName = ui->loginEdit->text();
            this->close();
        }
        else {
            QMessageBox::warning(this,"Ошибка","Логин или пароль введены неверно!");
        }
    }
}

void AuthDialog::on_cancelButton_clicked()
{
    this->close();
}
