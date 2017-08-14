#include "ordermachine.h"
#include "ui_ordermachine.h"

QString ordermachine::showOrder(){
    QString tem="    菜号   数量\n";
    //tem=tem.right(4);
    QMapIterator<int,int> i(dishMap);
    while (i.hasNext()) {
          i.next();
          QString row="    "+toString(i.key())+"    "+toString(i.value())+"\n";
          tem.append(row);
    }
    return tem;
}

void ordermachine::on_pushButton_19_clicked()
{
    dishMap.clear();
   // display.clear();
}

void ordermachine::on_pbLogin_2_clicked()
{
    bool ok1,ok2;
    int dsId=ui->lineEdit->text().toInt(&ok1);
    int cNum=ui->lineEdit_2->text().toInt(&ok2);
    if(ok1&&ok2){
        if(dishMap.contains(dsId)){
            int t=dishMap.value(dsId);
            if(t>=cNum){
                if(t>cNum){
                    cNum=t-cNum;
                    dishMap.insert(dsId,cNum);
                }else{
                    dishMap.remove(dsId);
                }
            }else{
                QMessageBox::warning(this,"警告","你取消的数量大于点购"
                                               "数量，将按点够数量取消!!!",
                QMessageBox::Yes);
                dishMap.remove(dsId);
            }
            //display=showOrder();
            ui->plainTextEdit->setPlainText(showOrder());
        }else{
            QMessageBox::warning(this,"警告","您没有点此菜号!!!",
            QMessageBox::Yes);
        }
    }else{
        QMessageBox::warning(this,"警告","输入格式错误，请重新输入!!!",
        QMessageBox::Yes);
    }
}
