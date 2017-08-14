#include "ordermachine.h"
#include "ui_ordermachine.h"

ordermachine::ordermachine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ordermachine)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    isLeftPressDown = false;
    isMaxSize = false;
    changeDir = NONE;
    serial=1000;
    clientId=0;
    setMaximumWidth(QApplication::desktop()->width());
    setMaximumHeight(QApplication::desktop()->height());
    setMinimumHeight(480);
    setMinimumWidth(340);
    setMouseTracking(true);//追踪鼠标
    TcpServer=new QTcpServer();
   // pTcpSocket=new QTcpSocket*[4];
    TcpServer->listen(QHostAddress::Any,19999);
    connect(TcpServer,SIGNAL(newConnection()),this,SLOT(slotNewConnect()));
    ui->stackedWidget->setCurrentIndex(0);
    this->setFocusPolicy(Qt::ClickFocus);//主窗口设置鼠标点击焦点，
    connection=connectDBMS();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    startTimer(1000);
    initData();
    refreshMenu();
}

QString ordermachine::toString(int num){
    std::ostringstream oss;
    oss<<num;
    std::string s;
    s=oss.str();
    return QString(QString::fromLocal8Bit(s.c_str()));
}

void ordermachine::timerEvent(QTimerEvent *){
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}
bool ordermachine::connectDBMS(){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("ordersystem");
    db.setUserName("root");
    db.setPassword("123456");
    bool ok = db.open();
    if(!ok)
    {
        QMessageBox::critical(this,QObject::tr("failure"),
        db.lastError().text());
        return false;
    }
    else
    {
        return true;
    }
}

ordermachine::~ordermachine()
{
    delete ui;
}

void ordermachine::refreshMenu(){
        QSqlQuery query("SELECT * FROM dishes");
         bool okId,okPrice;
         dsNum=0;
         while (query.next()) {
            int id=query.value(0).toInt(&okId);
            int price=query.value(4).toInt(&okPrice);
            Dishes theDish(id,price,query.value(1).toString(),query.value(2).toString(),query.value(3).toString());
            dhs[dsNum++]=theDish;
        }
        ui->image1->setStyleSheet(dhs[0].getPath());
        ui->dish1->setText(dhs[0].getDpn());
        ui->image2->setStyleSheet(dhs[1].getPath());
        ui->dish2->setText(dhs[1].getDpn());
        ui->image3->setStyleSheet(dhs[2].getPath());
        ui->image4->setStyleSheet(dhs[3].getPath());
        ui->image5->setStyleSheet(dhs[4].getPath());
        ui->image6->setStyleSheet(dhs[5].getPath());
        ui->image7->setStyleSheet(dhs[6].getPath());
        //ui->image7->setStyleSheet("border-image: url(:/dish6.png)");
        ui->dish3->setText(dhs[2].getDpn());
        ui->dish4->setText(dhs[3].getDpn());
        ui->dish5->setText(dhs[4].getDpn());
        ui->dish6->setText(dhs[5].getDpn());
        ui->dish7->setText(dhs[6].getDpn());
        if(dsNum>=8){
            ui->image8->setStyleSheet(dhs[7].getPath());
            ui->dish8->setText(dhs[7].getDpn());
        }

}

void ordermachine::on_sendmsg_clicked()
{
    QString cmd="sig##"+toString(100)+"##"+toString(2)+"##";//
    qDebug()<<cmd;
    tcpSockets.at(1)->write(cmd.toLatin1());
}





void ordermachine::on_sendmsg_2_clicked()
{
    bool ok1,ok2;
    int dsId=ui->lineEdit->text().toInt(&ok1);
    int cNum=ui->lineEdit_2->text().toInt(&ok2);
    QString cmd="del##"+toString(dsId)+"##"+toString(cNum)+"##";//
   // qDebug()<<cmd;
    tcpSockets.at(1)->write(cmd.toLatin1());
}
