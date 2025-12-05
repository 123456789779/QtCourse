#ifndef PATIENTEDITVIEW_H
#define PATIENTEDITVIEW_H

#include <QWidget>

namespace Ui {
class PatientEdit;
}

class PatientEdit : public QWidget
{
    Q_OBJECT

public:
    explicit PatientEdit(QWidget *parent = nullptr);
    ~PatientEdit();

private:
    Ui::PatientEdit *ui;
};

#endif // PATIENTEDITVIEW_H
