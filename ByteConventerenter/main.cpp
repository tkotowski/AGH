#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    using namespace std;
    string b,c;
    MainWindow w;

    w.show();

    return a.exec();
}
