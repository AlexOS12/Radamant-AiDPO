#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QFile>
#include <QDir>
#include <QDate>
#include <QTime>
#include "confirmdialogform.h"
#include "manualpassdialog.h"
#include "serverconnector.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void endChange_status_received(int status);
    void wicketPerson_received(Person person, int wicketId);

private slots:
    void on_AuthBtn_clicked();

    void on_passEdit_returnPressed();

    void on_endChangeBtn_clicked();

    void on_sosBtn_clicked();

    void on_openWicketA_clicked();

    void on_openWicketB_clicked();



private:
    QString host;

    bool readFile();
    bool writeFile(int autoLogin, QString login);

    void logger(QString message);

    int currentStaffID = -1;
    ServerConnector server;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
