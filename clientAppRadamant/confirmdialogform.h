#ifndef CONFIRMDIALOGFORM_H
#define CONFIRMDIALOGFORM_H

#include <QWidget>
#include <QDialog>
#include <QString>

namespace Ui {
class ConfirmDialogForm;
}

class ConfirmDialogForm : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialogForm(QWidget *parent = nullptr, QString title = "Title", QString description = "Sample Description");
    ~ConfirmDialogForm();

signals:
    void endStatusSignal(int status);

private slots:
    void on_confirmBtn_clicked();

    void on_declineBtn_clicked();


private:
    Ui::ConfirmDialogForm *ui;
};

#endif // CONFIRMDIALOGFORM_H
