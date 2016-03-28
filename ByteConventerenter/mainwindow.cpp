#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   using namespace std;
    ui->setupUi(this);
    string d,e;
}

MainWindow::~MainWindow()
{
    delete ui;
}


