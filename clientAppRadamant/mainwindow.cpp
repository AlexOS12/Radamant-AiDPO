#include "mainwindow.h"
#include "ui_mainwindow.h"

#define LOGIN  "login"
#define PASS  "pass"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->authErrorLabel->hide();
    setWindowTitle("Радамант. Авторизация");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::endChange_status_received(int status)
{
    qDebug() << status;
}

void MainWindow::on_AuthBtn_clicked()
{
    QString login = ui->loginEdit->text();
    QString pass = ui->passEdit->text();

    if (LOGIN == login && PASS == pass) {
        ui->stackedWidget->setCurrentIndex(1);
        setWindowTitle("Радамант");
    } else {
        ui->authErrorLabel->setText("Неверный логин или пароль");
        ui->authErrorLabel->show();
    }
}


void MainWindow::on_passEdit_returnPressed()
{
    this->on_AuthBtn_clicked();
}

void MainWindow::on_endChangeBtn_clicked()
{
    ConfirmDialogForm *endChangeDialog = new ConfirmDialogForm(this, "Закрытие смены", "Вы уверены, что хотите закрыть смену?");
    QObject::connect(endChangeDialog, SIGNAL(endStatusSignal(int)), this, SLOT(endChange_status_received(int)));
    QObject::connect(endChangeDialog, SIGNAL(finished(int)), endChangeDialog, SLOT(deleteLater()));
    endChangeDialog->show();

}

void MainWindow::on_sosBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->sosPage->setStyleSheet("background-color: red; color: white;");
}

