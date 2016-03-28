#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>
#include <QMainWindow>
#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};




class ByteConverterDialog : public QDialog
{
 Q_OBJECT
public:
 ByteConverterDialog();
};

class ByteConverter : public QObject
{
 Q_OBJECT
public:
 ByteConverter(QObject* = 0);
//public slots:
 void setDec(const QString&);
 void setHex(const QString&);
 void setBin(const QString&);
signals:
 void decChanged(const QString&);
 void hexChanged(const QString&);
 void binChanged(const QString&);
};


#endif // MAINWINDOW_H
