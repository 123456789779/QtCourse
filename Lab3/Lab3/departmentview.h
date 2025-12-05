#ifndef DEPARTMENTVIEW_H
#define DEPARTMENTVIEW_H

#include <QWidget>

namespace Ui {
class Department;
}

class Department : public QWidget
{
    Q_OBJECT

public:
    explicit Department(QWidget *parent = nullptr);
    ~Department();

private:
    Ui::Department *ui;
};

#endif // DEPARTMENTVIEW_H
