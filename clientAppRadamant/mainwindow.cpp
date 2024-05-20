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
    readFile();

    server.setHost(this->host);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::endChange_status_received(int status)
{
    if (status == 1) {
        this->ui->stackedWidget->setCurrentIndex(0);
        this->currentStaffID = -1;
    }
    qDebug() << status;
}

void MainWindow::wicketPerson_received(Person person, int wicketId)
{
    if (server.ManualPass(&person, wicketId)) {
        logger("Успешный ручной пропуск " + person.lastname + " через турникет " + QString::number(wicketId));
    } else {
        logger("Не выполнен ручной пропуск " + person.lastname + " через турникет " + QString::number(wicketId));
    }
    qDebug() << person.lastname << "\n" << person.passport;
}

void MainWindow::on_AuthBtn_clicked()
{
    QString login = ui->loginEdit->text();
    QString pass = ui->passEdit->text();

    // if (LOGIN == login && PASS == pass) {
    int serverAnswer = server.Authorize(login, pass);
    if (serverAnswer != -1) {
        this->currentStaffID = serverAnswer;
        ui->stackedWidget->setCurrentIndex(1);
        setWindowTitle("Радамант");
        logger("Успешная авторизации под именем: " + ui->loginEdit->text());
        writeFile(this->ui->remLogChkBx->isChecked(), this->ui->loginEdit->text());
    } else {
        ui->authErrorLabel->setText("Неверный логин или пароль");
        ui->authErrorLabel->show();
    }
    ui->passEdit->clear();
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

    server.SOS(1);

}


void MainWindow::on_openWicketA_clicked()
{
    ManualPassDialog *manualPassDialog = new ManualPassDialog(1);
    QObject::connect(manualPassDialog, SIGNAL(enteredPerson(Person, int)), this, SLOT(wicketPerson_received(Person, int)));
    manualPassDialog->show();
}


void MainWindow::on_openWicketB_clicked()
{
    ManualPassDialog *manualPassDialog = new ManualPassDialog(2);
    QObject::connect(manualPassDialog, SIGNAL(enteredPerson(Person, int)), this, SLOT(wicketPerson_received(Person, int)));
    manualPassDialog->show();
}

bool MainWindow::readFile()
{
    QFile file;
    file.setFileName(QDir::homePath() + "\\RadamantSettings.rsts");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        file.close();
    } else {
        try {
            int autoLoginStatus =  file.readLine().toInt();
            QString login = file.readLine().trimmed();
            QString hostAddr = file.readLine().trimmed();
            if (autoLoginStatus) {
                ui->remLogChkBx->setChecked(true);
                ui->loginEdit->setText(login);
            } else{
                ui->remLogChkBx->setChecked(false);
            }
            this->host = hostAddr;
        } catch (...) {
            qDebug() << "Failed to read file";
        }
    }
}

bool MainWindow::writeFile(int autoLogin, QString login)
{
    QFile file;
    file.setFileName(QDir::homePath() + "\\RadamantSettings.rsts");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.close();
    } else {
        QString data = QString::number(autoLogin) + "\n" + login + "\n" + this->host;
        file.write(data.toUtf8());
    }
}

void MainWindow::logger(QString message)
{

    ui->listWidget->addItem("[" + QDate::currentDate().toString() + " " +  QTime::currentTime().toString() + "] " + message);
}

