#include "matrix.h"
#include "ui_matrix.h"
#include <vector>
#include <string>
#include "solution.h"
#include <ctype.h>
#include <iostream>
#include <QMessageBox>
#include <mainwindow.h>

using namespace std;

Matrix::Matrix(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Matrix), size(0)
{
    ui->setupUi(this);
}

Matrix::~Matrix()
{
    delete ui;
}

void Matrix::on_pushButton_clicked()
{
    QString matrix1 = ui->matrix1->toPlainText();
    QString matrix2 = ui->matrix2->toPlainText();
    vector< vector<int> > v;
    vector< vector<int> > w;
    vector<int> temp;
    vector<int> temp1;
    string line = matrix1.toStdString();
    string line1 = matrix2.toStdString();
    for(int i = 0;i < int(line.size());i++)
    {
      if(isdigit(line[i]))
      {
         int c = line[i] - '0';
         int c1 = line1[i] - '0';
         temp1.push_back(c1);
         temp.push_back(c);
         if(int(temp.size()) == size)
          {
           v.push_back(temp);
           temp.clear();
           w.push_back(temp1);
           temp1.clear();
          }
       }
    }

    Solution solution(v, w, size);
    solution.calculate();
    solution.print();
    QMessageBox *msgBox1 = new QMessageBox;
    msgBox1->setWindowTitle("Result");
    msgBox1->setIcon(QMessageBox::Information);
    msgBox1->setWindowModality(Qt::NonModal);
    if(solution.isIsomorphism())
    {
        QString str = QString::fromStdString(solution.getString());
        msgBox1->setText(str);
    }
    else{
        msgBox1->setText("Not Isomorphic!");
    }
    msgBox1->setStandardButtons(QMessageBox::Ok);
    int ret = msgBox1->exec();
    if(ret == QMessageBox::Ok)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "New calculation", "Restart?", QMessageBox::Yes | QMessageBox::No);
        if(QMessageBox::Yes == reply)
        {
            hide();
            MainWindow *window = new MainWindow(this);
            window->show();
        }
        else{
            QApplication::quit();
        }
    }
}
