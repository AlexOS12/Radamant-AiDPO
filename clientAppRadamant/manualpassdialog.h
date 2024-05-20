#ifndef MANUALPASSDIALOG_H
#define MANUALPASSDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include "Person.h"

namespace Ui {
class ManualPassDialog;
}

class ManualPassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManualPassDialog(int wicketId, QWidget *parent = nullptr);
    ~ManualPassDialog();

signals:
    void enteredPerson(Person person, int wicketId);

private slots:
    void on_passPersonBtn_clicked();

    void on_cancelBtn_clicked();

private:
    int wicketId;
    Ui::ManualPassDialog *ui;
};

#endif // MANUALPASSDIALOG_H
