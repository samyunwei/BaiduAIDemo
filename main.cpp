#include <iostream>
#include <QApplication>
#include <QWidget>
#include "InputWidget.h"


int main(int argc,char* argv[]){
    QApplication a(argc,argv);
    InputWidget w(nullptr);
    w.show();
    return a.exec();
}