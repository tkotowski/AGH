#include "mainwindow.h"
#include <QApplication>

#include <QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
QApplication a(argc, argv);
QLabel label("\n  Hello World \n  Testuje możliwości budowania Qt Widgets \n  Jakie klasy zostały włączone, dlaczego? Jaka jest hierarchia klas w QT? \n"
             "  Zostały włączone klasy MainWindow i QMainWindow, w celu obsługi interface'u, to jest okna dialogowego\n"
             "  Klasą bazową jest QMainWindow, po której prywatnie dziedziczy MainWindow \n"
             "  Zostały zawarte biblioteki mainwindow.h oraz ui_mainwindow.h \n"
             "  Korzystam z opcji budowania Release, jako, że ukończyłem projekt \n");
label.setAlignment(Qt::AlignCenter);
label.show();
return a.exec();
}
