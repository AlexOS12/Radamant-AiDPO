#include "confirmdialogform.h"
#include "ui_confirmdialogform.h"

ConfirmDialogForm::ConfirmDialogForm(QWidget *parent, QString title, QString description)
    : QDialog(parent)
    , ui(new Ui::ConfirmDialogForm)
{
    ui->setupUi(this);
    setWindowTitle(title);
    ui->title->setText(title);
    ui->desctiption->setText(description);
}

ConfirmDialogForm::~ConfirmDialogForm()
{
    delete ui;
}


void ConfirmDialogForm::on_confirmBtn_clicked()
{
    emit endStatusSignal(1);
    this->~ConfirmDialogForm();
}


void ConfirmDialogForm::on_declineBtn_clicked()
{
    emit endStatusSignal(0);
    this->close();
    this->~ConfirmDialogForm();
}

