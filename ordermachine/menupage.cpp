#include "ordermachine.h"
#include "ui_ordermachine.h"

void ordermachine::on_changeDesk_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void ordermachine::on_orderDish_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void ordermachine::on_delDish_clicked()
{
   // display=showOrder();
    ui->plainTextEdit->setPlainText(showOrder());
    ui->stackedWidget->setCurrentIndex(4);
}

void ordermachine::on_queryDish_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void ordermachine::on_queryInfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void ordermachine::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ordermachine::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
