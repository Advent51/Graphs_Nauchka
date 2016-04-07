#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QBuffer"
#include "QFile"

//переменные для матрицы смежности

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void VizualizationFunc();
    void CreationGraph();

    /*int GetNumbers(int n);
    int GetArra();*/
    //int numbers=0;
    //int **arra;
    //QBuffer buffer(&numbers);

public slots:
    void ZapAr();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
