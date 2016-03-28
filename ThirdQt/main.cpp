#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

 //   int window_width = QApplication::desktop()->width();
   // int window_height = QApplication::desktop()->height();

    MainWindow w;

    QPushButton * quit_btn = new QPushButton;
    quit_btn->setParent(w.centralWidget());
    //quit_btn->setGeometry(window_width-50,12,32,32);

    QObject::connect(quit_btn,SIGNAL(clicked()),qApp,SLOT(quit()));

   // w.resize(window_width,window_height);

    w.show();

    return a.exec();
}

