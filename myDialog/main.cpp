#include<QApplication>
#include"mydialog.h"

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    MyDialog genius;
    genius.show();
    return app.exec();

}

