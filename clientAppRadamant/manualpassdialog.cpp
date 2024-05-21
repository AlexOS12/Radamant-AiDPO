#include "manualpassdialog.h"
#include "ui_manualpassdialog.h"

ManualPassDialog::ManualPassDialog(int wicketId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManualPassDialog)
{
    ui->setupUi(this);
    this->wicketId = wicketId;
    setWindowTitle("Ручное открытие турникета " + QString::number(wicketId));
}

ManualPassDialog::~ManualPassDialog()
{
    delete ui;
}

void ManualPassDialog::on_passPersonBtn_clicked()
{
    QString lastname = ui->lastnameEdit->text();
    QString passport = ui->passEdit->text();

    emit enteredPerson(Person(lastname, passport), wicketId);
    this->~ManualPassDialog();
}


void ManualPassDialog::on_cancelBtn_clicked()
{
    this->~ManualPassDialog();
}

