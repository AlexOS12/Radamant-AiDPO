#ifndef MANUALPASSDIALOG_H
#define MANUALPASSDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QString>

struct Person {
    QString lastname;
    QString passport;

    Person(QString lastname, QString passport) {
        this->lastname = lastname;
        this->passport = passport;
    }
};

namespace Ui {
class ManualPassDialog;
}

class ManualPassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManualPassDialog(QWidget *parent = nullptr);
    ~ManualPassDialog();

signals:
    void enteredPerson(Person person);

private slots:
    void on_passPersonBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::ManualPassDialog *ui;
};

#endif // MANUALPASSDIALOG_H
