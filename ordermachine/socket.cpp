#include "ordermachine.h"
#include "ui_ordermachine.h"

void ordermachine::sendFreeDesk(){
    QSqlQuery query("select deskId from desk where free=1");
    int size=query.size();
    Desk* a=new Desk[size];
    a[0].size=size;
    int i=0;
    while(query.next()){
        bool ok;
        a[i].id=query.value(0).toInt(&ok);
        if(ok){
            tcpSockets.at(0)->write((char*)&a[i],sizeof(a[i]));
            i++;qDebug()<<i;
        }
    }
}
void ordermachine::toOrderDish(){
    QString t="ok";
    tcpSockets.at(0)->write(t.toStdString().c_str(),strlen(t.toStdString().c_str()));
    tcpSockets.at(0)->waitForReadyRead(-1);
    QByteArray result=tcpSockets.at(0)->readAll();
    QString desk=QVariant(result).toString();
    ui->dIdMsg->setText(desk);
    QSqlQuery query("update desk set free =0 where deskId="+desk);
    deskId=desk.toInt();
}
void ordermachine::findConsume(){
    QString sql="ok";
    tcpSockets.at(0)->write(sql.toStdString().c_str(),strlen(sql.toStdString().c_str()));
    tcpSockets.at(0)->waitForReadyRead(-1);
    QByteArray result=tcpSockets.at(0)->readAll();
    QString desk=QVariant(result).toString();
    ui->dIdMsg->setText(desk);
    int cnt=dishMap.size(),j=0;
    Consume* a=new Consume[cnt];
    a[0].size=cnt;a[0].total=0;
    QMap<int, int>::const_iterator i = dishMap.constBegin();
    while (i != dishMap.constEnd()) {
        a[j].id=i.key();
        a[j].countOfDish=i.value();
        for(int k=0;k<dsNum;++k){
            if(dhs[k].getDishID()==i.key()){
                 a[j].money=a[j].countOfDish*dhs[k].getPrice();
            }
         }
            a[0].total+=a[j].money;
            ++i;++j;
    }
    dsNum=a[0].total;
    for(int i=0;i<cnt;++i){
        tcpSockets.at(0)->write((char*)&a[i],sizeof(a[i]));
    }
}
void ordermachine::updataDesk(){
    QString sql="ok";
    tcpSockets.at(0)->write(sql.toStdString().c_str(),strlen(sql.toStdString().c_str()));
    tcpSockets.at(0)->waitForReadyRead(-1);
    QByteArray result=tcpSockets.at(0)->readAll();
    QString desk=QVariant(result).toString();
   QSqlQuery query("update desk set free =1 where deskId="+desk);
   QString date=(QDate::currentDate()).toString("yyyy-MM-dd");
   qDebug()<<date;
   query.prepare("INSERT INTO sales (serialId, salesDate, money,userName,deskId) "
                       "VALUES (?, ?, ? ,?,?)");
   query.bindValue(0, serial);
   query.bindValue(1, date);
   query.bindValue(2, dsNum);
   query.bindValue(3, userName);
   query.bindValue(4, deskId);
   query.exec();
   serial+=1;
   dsNum=0;
   dishMap.clear();
}

void ordermachine::slotReadCounter(){
    QByteArray qba=tcpSockets.at(0)->readAll();
    QString ss=QVariant(qba).toString();
    qDebug()<<ss;
    if(ss.operator ==("findFreeDesk")){
        sendFreeDesk();
    }
    if(ss.operator ==("updateOccupyDesk")){
        toOrderDish();
    }
    if(ss.operator ==("findConsume")){
        findConsume();
    }
    if(ss.operator ==("updateFreeDesk")){
        updataDesk();
    }
}
void ordermachine::slotReadFood(){
    qDebug()<<"food entered";
    QByteArray qba=tcpSockets.at(2)->readAll();
    QString ss=QVariant(qba).toString();
    qDebug()<<ss;
    refreshMenu();
    initData();
}
void ordermachine::slotReadKithen(){
    qDebug()<<"kithen entered";
    QByteArray qba=tcpSockets.at(1)->readAll();
    QString ss=QVariant(qba).toString();
    qDebug()<<ss;
   // refreshMenu();
}
void ordermachine::slotNewConnect(){
    QTcpSocket * pTst=TcpServer->nextPendingConnection();
  //  pTcpSocket[clientId]=TcpServer->nextPendingConnection();
    tcpSockets.append(pTst);
    if(tcpSockets.count()==1){
        this->connect(tcpSockets.at(0),SIGNAL(readyRead()),this,SLOT(slotReadCounter()));
    }else if(tcpSockets.count()==2){
        this->connect(tcpSockets.at(1),SIGNAL(readyRead()),this,SLOT(slotReadKithen()));
    }else{
        this->connect(tcpSockets.at(tcpSockets.count()-1),SIGNAL(readyRead()),this,SLOT(slotReadFood()));
    }
}
