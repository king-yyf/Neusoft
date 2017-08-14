#ifndef ORDERMACHINE_H
#define ORDERMACHINE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTextCodec>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QMap>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMapIterator>
#include <QTest>
#include <sstream>
#include <QDate>
#include <QList>
#include "dishes.h"
#define PADDING 4
#define DISH_CNT 20
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    LEFTTOP,
    LEFTBOTTOM,
    RIGHTBOTTOM,
    RIGHTTOP,
    NONE
};
namespace Ui {
class ordermachine;
}

class ordermachine : public QMainWindow
{
    Q_OBJECT

public:
    explicit ordermachine(QWidget *parent = 0);
    ~ordermachine();
    QTcpServer * TcpServer;
    QList<QTcpSocket *> tcpSockets;

    void toOrderDish();
    void findConsume();
    void updataDesk();
    bool connectDBMS();
    void initData();
    void refreshMenu();
    QString toString(int num);
    QString showOrder();
protected:
    bool isMaxSize;
    bool isLeftPressDown;//判断左键是否按下
    QPoint dragPosition;//窗口移动拖动时需要记住的点
    Direction changeDir;//窗口大小改变时，记录改变方向
private slots:

    void on_obQuit_clicked();
    void on_pbClose_clicked();
    void on_changeDesk_clicked();
    void on_orderDish_clicked();
    void on_delDish_clicked();
    void on_queryDish_clicked();
    void on_queryInfo_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_12_clicked();
    void on_pbLogin_clicked();
    void on_pbReset_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_17_clicked();
 //   void on_pushButton_13_clicked();
    void on_dish1_clicked();
    void on_dish2_clicked();
    void on_dish3_clicked();
    void on_dish4_clicked();
    void on_dish5_clicked();
    void on_dish6_clicked();
    void on_dish7_clicked();
    void on_dish8_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pbLogin_2_clicked();

    void on_sendmsg_clicked();
    void sendFreeDesk();
    void on_dish1_pressed();

    void on_dish1_released();

    void on_dish2_pressed();

    void on_dish2_released();

    void on_dish3_pressed();

    void on_dish3_released();

    void on_dish4_pressed();

    void on_dish4_released();

    void on_dish5_pressed();

    void on_dish5_released();

    void on_dish6_pressed();

    void on_dish6_released();

    void on_dish7_pressed();

    void on_dish7_released();

    void on_dish8_pressed();

    void on_dish8_released();

    void on_sendmsg_2_clicked();

public slots:
    void timerEvent(QTimerEvent *);
    void loseMouse();//当鼠标焦点被子组件获取时，需要还原鼠标形状和changeDir。
    void setMaxSize();
    void slotNewConnect();
    void slotReadCounter();
    void slotReadFood();
    void slotReadKithen();
private:
    Ui::ordermachine *ui;
    void region(const QPoint &cursorGlobalPoint);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QString userName;
    bool connection;
    QSqlDatabase db;
    int deskId;
    Dishes dhs[DISH_CNT];
    int serial;
    int dsNum;
    int clientId;
    QMap<int,int> dishMap;
};

#endif // ORDERMACHINE_H
