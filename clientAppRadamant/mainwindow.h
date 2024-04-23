#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "confirmdialogform.h"

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
    void on_endChange_statusReceived(int status);

private slots:
    void on_AuthBtn_clicked();

    void on_passEdit_returnPressed();

    void on_endChangeBtn_clicked();

    void on_sosBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
