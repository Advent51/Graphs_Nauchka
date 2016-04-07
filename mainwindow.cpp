#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphwidget.h"
#include "QTime"
#include "QTableWidget"
#include "form.h"
#include "QInputDialog"
#include "QString"
#include "QMessageBox"

int numbers=0;
int** arra;
int** arra2;
int** arra3;
QTableWidget* table;

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::VizualizationFunc()
{
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
   GraphWidget *widget = new GraphWidget;
   widget->show();
}

void MainWindow::CreationGraph()
{
   /*QTableWidget table1(3,3, NULL);

   //form.gameTable->setColumnCount(numbers);
   //form.gameTable->setRowCount(numbers);

   //table1.setGeometry(QRect(0,0,300,250));
  // table1.setItem(1,1,"50");*/

   table = new QTableWidget();

       //Set table row count 1 and column count 3
       table->setRowCount(numbers);
       table->setColumnCount(numbers);

       table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

       /*//Set Header Label Texts Here
       table->setHorizontalHeaderLabels(QString("HEADER 1;HEADER 2;HEADER 3").split(";"));

       //Add Table items here
       table->setItem(0,0,new QTableWidgetItem("ITEM 1"));
       table->setItem(0,1,new QTableWidgetItem("ITEM 2"));
       table->setItem(0,2,new QTableWidgetItem("ITEM 3"));*/

       //int arra = GetArra();

       for (int i = 0; i < numbers; ++i)
       {
           for (int j = 0; j < numbers; ++j)
           {
                      QTableWidgetItem * item = new QTableWidgetItem(QString::fromLocal8Bit("Твой текст"));
                      item->setText("0");
                      table->setItem(i, j, item);
           }
       }
       table->resizeColumnsToContents();
       table->show();
       ZapAr();

       QObject::connect(table, SIGNAL(itemChanged(QTableWidgetItem*)),
                            this, SLOT(ZapAr() ));
       //QTableWidgetItem* itm2;
      /*if ()
       {
           for(int i=0;i<numbers;i++)
               for(int j=0;j<numbers;j++)
               {
                   QTableWidgetItem* itm = table -> item(i,j);
                   arra[i][j] = itm -> text().toInt();
                   //out<<itmqstr;
               }
       }*/
}

void MainWindow::ZapAr()
{
   for(int i=0;i<numbers;i++)
       for(int j=0;j<numbers;j++)
       {
           QTableWidgetItem* itm = table -> item(i,j);
           arra[i][j] = itm -> text().toInt();
           //out<<itmqstr;
       }
}

/*int MainWindow::GetNumbers(int n)
{
   return numbers;
}

int MainWindow::GetArra()
{
   return **arra;
}*/

void MainWindow::on_pushButton_2_clicked()
{
   bool bOk;
   numbers = QInputDialog::getInt(0,"Задание количества вершин графа","Количество:",0,-2147483647,214783647,1,&bOk);

   //QFile filik;
  /* if(filik.open(QIODevice::ReadWrite|QIODevice::Truncate))
   {
           QTextStream data2(&filik);
           data2<<numbers;
           filik.close();
   }*/

   if (!bOk) {
       // Была нажата кнопка Cancel
       return;}
   if (numbers<=0) return;


   arra = new int*[numbers];
   for (int i = 0; i < numbers; i++) arra[i] = new int[numbers];

   CreationGraph();
   ui->pushButton_4->setEnabled(1);
   ui->pushButton_3->setEnabled(1);
}

void MainWindow::on_pushButton_clicked()
{
   VizualizationFunc();
}

void MainWindow::on_pushButton_5_clicked()
{
   close();
}

void MainWindow::on_pushButton_3_clicked()
{
   QString reshen1;
   int flag2[numbers];
   arra2 = new int*[numbers];
   for (int i = 0; i < numbers; i++) {arra2[i] = new int[numbers]; flag2[i]=0;}

   for(int i=0;i<numbers;i++)
       for(int j=0;j<numbers;j++)
       {
           arra2[i][j]=arra[i][j];
       }

   for(int i=0;i<numbers;i++)
   {
       for(int j=i;j<numbers;j++)
       {
           if (arra2[i][j]!=0)
           {
               if (flag2[i]==0)
               {
                   reshen1=(reshen1+"  "+QString::number(i+1));
                   flag2[i]=1;
               }
               if (flag2[j]==0)
               {
                   reshen1=(reshen1+"  "+QString::number(j+1));
                   flag2[j]=1;
               }
               for (int n=i;n<numbers;n++) arra2[n][j]=0;
               for (int n=j;n<numbers;n++) arra2[i][n]=0;
           }
       }
   }
   QMessageBox::information(0, tr("Покрывающее множество"), reshen1);
}

void MainWindow::on_pushButton_4_clicked()
{
   QString reshen2;
   int max[numbers];
   int maximum=0;
   int b=0;
   int flag=0;
   arra3 = new int*[numbers];
   for (int i = 0; i < numbers; i++) arra3[i] = new int[numbers];

   for(int i=0;i<numbers;i++)
   {
       for(int j=0;j<numbers;j++)
       {
           arra3[i][j]=arra[i][j];
           //arra3[j][i]=arra[i][j];//добавлено
       }
   }

   reshen2="";
   reshen2.clear();

   do {
       flag=0;
       for(int i=0;i<numbers;i++)
       {
           max[i]=0; maximum=0; b=0;
           for(int j=0;j<numbers;j++)//было j=i
           {
               //if (arra3[i][j]!=0) {max[i]++; flag++;}
               //if (arra3[j][i]!=0) {max[i]++; flag++;}
               max[i]=max[i]+arra3[i][j];
               max[i]=max[i]+arra3[j][i];
               if (max[i]!=0) flag++;
           }
       }

       for (int i=0; i<numbers; i++)
       {
           if (max[i]>maximum) {maximum=max[i]; b=i;}
       }

       if (flag!=0) reshen2=(reshen2+" "+QString::number(b+1));

       for (int n=0;n<numbers;n++) arra3[b][n]=0;
       for (int n=0;n<numbers;n++) arra3[n][b]=0;

   } while (flag>0);

   QMessageBox::information(0, tr("Покрывающее множество"), reshen2);
}

void MainWindow::on_actionAbout_triggered()
{
   QMessageBox::about(this, tr("About Nauchka"),
             tr("<h2>Created by Andrei Abramov <p> and"
             " Alexey McSimov <p>SSAU group 6310</h2>"
             "<p>Copyright &copy; 2014 Adventorium Inc."
             "<p>It is a small application that "
             "<p>demonstrates my professional skills "));
}
