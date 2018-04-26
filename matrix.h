#ifndef MATRIX_H
#define MATRIX_H

#include <QDialog>

namespace Ui {
class Matrix;
}

class Matrix : public QDialog
{
    Q_OBJECT

public:
    explicit Matrix(QWidget *parent = 0);
    int size;
    ~Matrix();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Matrix *ui;
};

#endif // MATRIX_H
