#include "mainwindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;

    QVBoxLayout* mainLayout = new QVBoxLayout(&window);
    QLabel* label1 = new QLabel("One        Two");
    QLabel* label2 = new QLabel("Three     Four");
    QLabel* label3 = new QLabel("Five         Six");
    mainLayout->addWidget(label1);
    mainLayout->addWidget(label2);
    mainLayout->addWidget(label3);
    window.show();
    return a.exec();
}
