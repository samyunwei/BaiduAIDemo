#include <iostream>
#include <QApplication>
#include <QWidget>
#include "InputWidget.h"
#include "speech.h"


int main(int argc,char* argv[]){
    QApplication a(argc,argv);
    InputWidget w(nullptr);
    w.show();
    std::string app_id = "你的 App ID";
    std::string api_key = "你的 Api key";
    std::string secret_key = "你的 Secret Key";
    aip::Speech client(app_id, api_key, secret_key);
    return a.exec();
}