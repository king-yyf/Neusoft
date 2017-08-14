#include "ordermachine.h"
#include "ui_ordermachine.h"

void ordermachine::on_pushButton_17_clicked()   //菜谱翻页
{
    int i=ui->stackedWidget_2->currentIndex();
    ui->stackedWidget_2->setCurrentIndex((i+1)%2);
}

void ordermachine::on_pushButton_18_clicked()   //确定点菜并发送给厨房
{
    ui->plainTextEdit->setPlainText(showOrder());
    ui->pushButton_19->setEnabled(false);
   // QString msg;
    QMapIterator<int,int> i(dishMap);
    while (i.hasNext()) {
          i.next();
          QString cmd="add##"+toString(i.key())+"##"+toString(i.value())+"##";
          qDebug()<<cmd;
          tcpSockets.at(1)->write(cmd.toLatin1());
    }
}

void ordermachine::on_dish1_clicked()
{
    int id=dhs[0].getDishID();
    if(dishMap.contains(id)){
        int cnt=dishMap.value(id)+1;
        dishMap.insert(id,cnt);
    }else{
        dishMap.insert(id,1);
    }
}

void ordermachine::on_dish2_clicked()
{
    int id=dhs[1].getDishID();
    if(dishMap.contains(id)){
        int cnt=dishMap.value(id)+1;
        dishMap.insert(id,cnt);
    }else{
        dishMap.insert(id,1);
    }
}

void ordermachine::on_dish3_clicked()
{
    int id=dhs[2].getDishID();
    if(dishMap.contains(id)){
        int cnt=dishMap.value(id)+1;
        dishMap.insert(id,cnt);
    }else{
        dishMap.insert(id,1);
    }
}

void ordermachine::on_dish4_clicked()
{
    int id=dhs[3].getDishID();
    if(dishMap.contains(id)){
        int cnt=dishMap.value(id)+1;
        dishMap.insert(id,cnt);
    }else{
        dishMap.insert(id,1);
    }
}

void ordermachine::on_dish5_clicked()
{
    int id=dhs[4].getDishID();
    if(dishMap.contains(id)){
        int cnt=dishMap.value(id)+1;
        dishMap.insert(id,cnt);
    }else{
        dishMap.insert(id,1);
    }
}

void ordermachine::on_dish6_clicked()
{
    int id=dhs[5].getDishID();
    if(dishMap.contains(id)){
        int cnt=dishMap.value(id)+1;
        dishMap.insert(id,cnt);
    }else{
        dishMap.insert(id,1);
    }
}

void ordermachine::on_dish7_clicked()
{
    int id=dhs[6].getDishID();
    if(dishMap.contains(id)){
        int cnt=dishMap.value(id)+1;
        dishMap.insert(id,cnt);
    }else{
        dishMap.insert(id,1);
    }
}

void ordermachine::on_dish8_clicked()
{
    if(dsNum>=8){
        int id=dhs[7].getDishID();
        if(dishMap.contains(id)){
            int cnt=dishMap.value(id)+1;
            dishMap.insert(id,cnt);
        }else{
            dishMap.insert(id,1);
        }
    }

}

void ordermachine::on_dish1_pressed()
{
    ui->dish1->setStyleSheet("border-image: url(:/show.png)");
}

void ordermachine::on_dish1_released()
{
    ui->dish1->setStyleSheet("border-image: url(:/input.png)");
}

void ordermachine::on_dish2_pressed()
{
    ui->dish2->setStyleSheet("border-image: url(:/show.png)");
}

void ordermachine::on_dish2_released()
{
    ui->dish2->setStyleSheet("border-image: url(:/input.png)");
}

void ordermachine::on_dish3_pressed()
{
    ui->dish3->setStyleSheet("border-image: url(:/show.png)");
}

void ordermachine::on_dish3_released()
{
    ui->dish3->setStyleSheet("border-image: url(:/input.png)");
}

void ordermachine::on_dish4_pressed()
{
    ui->dish4->setStyleSheet("border-image: url(:/show.png)");
}

void ordermachine::on_dish4_released()
{
    ui->dish4->setStyleSheet("border-image: url(:/input.png)");
}

void ordermachine::on_dish5_pressed()
{
    ui->dish5->setStyleSheet("border-image: url(:/show.png)");
}

void ordermachine::on_dish5_released()
{
    ui->dish5->setStyleSheet("border-image: url(:/input.png)");
}

void ordermachine::on_dish6_pressed()
{
    ui->dish6->setStyleSheet("border-image: url(:/show.png)");
}

void ordermachine::on_dish6_released()
{
    ui->dish6->setStyleSheet("border-image: url(:/input.png)");
}

void ordermachine::on_dish7_pressed()
{
    ui->dish7->setStyleSheet("border-image: url(:/show.png)");
}

void ordermachine::on_dish7_released()
{
    ui->dish7->setStyleSheet("border-image: url(:/input.png)");
}

void ordermachine::on_dish8_pressed()
{
    ui->dish8->setStyleSheet("border-image: url(:/show.png)");
}

void ordermachine::on_dish8_released()
{
    ui->dish8->setStyleSheet("border-image: url(:/input.png)");
}
