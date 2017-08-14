#include "ordermachine.h"
#include "ui_ordermachine.h"

void ordermachine::on_obQuit_clicked()
{
    if(ui->stackedWidget->currentIndex()!=0){
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void ordermachine::on_pbClose_clicked()
{
    db.close();
    this->close();
}

void ordermachine::on_pbLogin_clicked()
{
        userName=ui->leName->text();
        QString psd=ui->lePsd->text();
        QString sql="SELECT userPsd FROM users WHERE userName ='"+userName+"'";
        QSqlQuery query(sql);
        query.next();
       if(query.value(0).toString()==psd){
           ui->stackedWidget->setCurrentIndex(1);
           ui->lwaiter->setText(userName);
       }else{
           QMessageBox::warning(this,"警告","用户名或密码错误!!!",
           QMessageBox::Yes);
       }
}

void ordermachine::on_pbReset_clicked()
{
    ui->leName->setText("");
    ui->lePsd->setText("");
}
