#include "manualpassdialog.h"
#include "ui_manualpassdialog.h"

ManualPassDialog::ManualPassDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManualPassDialog)
{
    ui->setupUi(this);
    setWindowTitle("Ручное открытие турникета");
}

ManualPassDialog::~ManualPassDialog()
{
    delete ui;
}

void ManualPassDialog::on_passPersonBtn_clicked()
{
    QString lastname = ui->lastnameEdit->text();
    QString passport = ui->passEdit->text();

    emit enteredPerson(Person(lastname, passport));
}


void ManualPassDialog::on_cancelBtn_clicked()
{
    this->close();
}

