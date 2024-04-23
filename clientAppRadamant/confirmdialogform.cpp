#include "confirmdialogform.h"
#include "ui_confirmdialogform.h"

ConfirmDialogForm::ConfirmDialogForm(QWidget *parent, QString title, QString description)
    : QDialog(parent)
    , ui(new Ui::ConfirmDialogForm)
{
    ui->setupUi(this);
    ui->title->setText(title);
    ui->desctiption->setText(description);
}

ConfirmDialogForm::~ConfirmDialogForm()
{
    delete ui;
}


void ConfirmDialogForm::on_confirmBtn_clicked()
{
    endStatusSignal(1);
}


void ConfirmDialogForm::on_declineBtn_clicked()
{
    endStatusSignal(0);
}

