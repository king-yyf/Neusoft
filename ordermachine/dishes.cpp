#include "dishes.h"

Dishes::Dishes(){}
Dishes::Dishes(int id, int price, QString path, QString dpn,QString sort){
    this->dishId=id;
    this->price=price;
    this->path=path;
    this->dpn=dpn;
    this->sort=sort;
}

int Dishes::getDishID(){
    return dishId;
}

void Dishes::setDishID(int id){
    this->dishId=id;
}

int Dishes::getPrice(){
    return price;
}

void Dishes::setPrice(int price){
    this->price=price;
}

QString Dishes::getPath(){
    return path;
}

void Dishes::setPath(QString path){
    this->path=path;
}
QString Dishes::getDpn(){
    return dpn;
}
void Dishes::setDpn(QString arg){
    this->dpn=arg;
}
QString Dishes::getSort(){
    return sort;
}
void Dishes::setSort(QString sort){
    this->sort=sort;
}
