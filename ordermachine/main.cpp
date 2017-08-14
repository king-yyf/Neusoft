#include "ordermachine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    QTextCodec *codec = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForLocale(codec);
    ordermachine w;
    w.show();

    return a.exec();
}
