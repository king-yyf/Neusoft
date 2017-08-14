#ifndef DISHES_H
#define DISHES_H
#include<QString>
class Dishes{
private:
    int dishId;
    int price;
    QString path;
    QString dpn;
    QString sort;
public:
    Dishes();
    Dishes(int id,int price,QString path,QString dpn,QString sort);
    QString getPath();
    void setPath(QString path)

    ;
    int getDishID();
    void setDishID(int id);
    int getPrice();
    void setPrice(int price);
    QString getDpn();
    void setDpn(QString arg);
    QString getSort();
    void setSort(QString sort);
};
class Desk{
public:
    int id;
    int size;
};
class Consume{
public:
    int id;
    int countOfDish;
    double money;
    double total;
    int size;
};

#endif // DISHES_H
