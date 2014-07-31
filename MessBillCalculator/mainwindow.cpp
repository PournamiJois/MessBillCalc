#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qtablewidget.h>

int rowNum=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString id= ui->lineEdit_2->text();
    QString name = ui->lineEdit_3->text();
    QString month = ui->comboBox->currentText();
    QString netamount = ui->lineEdit_5->text();
    QString status = "paid";

    if(ui->radioButton->isChecked())

    {
        status = ui->radioButton->text();
    }
else
    {
        status = ui->radioButton_2->text();
    }

    ui->tableWidget->setRowCount(rowNum+1);

      QTableWidgetItem *itab;
      itab = new QTableWidgetItem;
      itab ->setText(id);
      ui->tableWidget->setItem(rowNum,0,itab);


      QTableWidgetItem *itab1;
      itab1 = new QTableWidgetItem;
      itab1 ->setText(name);
      ui->tableWidget->setItem(rowNum,1,itab1);

      QTableWidgetItem *itab2;
      itab2 = new QTableWidgetItem;
      itab2 ->setText(month);
      ui->tableWidget->setItem(rowNum,2,itab2);

      QTableWidgetItem *itab3;
      itab3 = new QTableWidgetItem;
      itab3 ->setText(netamount);
      ui->tableWidget->setItem(rowNum,3,itab3);

      QTableWidgetItem *itab4;
      itab4 = new QTableWidgetItem;
      itab4 ->setText(status);
      ui->tableWidget->setItem(rowNum,4,itab4);

rowNum++;



    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit->setText("");
    ui->lineEdit_4->setText("");
    ui->comboBox->setCurrentIndex(0);

   ui->radioButton->setAutoExclusive(false);
   ui->radioButton_2->setAutoExclusive(false);

    ui->radioButton->setChecked(0);
    ui->radioButton_2->setChecked(0);

}



void MainWindow::on_pushButton_2_clicked()
{
    int totalrow = ui->tableWidget->rowCount();

    for(int i = totalrow-1 ; i > 0 ; --i)
    {
        ui->tableWidget->removeRow(i);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString operand_4_string= ui->lineEdit_4->text();
    QString operand_string= ui->lineEdit->text();

    float operand_4_float= operand_4_string.toFloat();
    float operand_float= operand_string.toFloat();

    float result_float= operand_4_float * operand_float;

    QString result_string= QString::number(result_float);

    ui->lineEdit_5->setText(result_string);
}
