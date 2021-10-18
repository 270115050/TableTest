#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = ui->tableWidget;
    table->setEditTriggers(false);
    for(int i = 0; i < 5; i++){
       ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
    }
}
//https://programmer.help/blogs/qt-development-cross-window-signal-slot-communication.html
void MainWindow::receiveMsg(QStringList str)
{
    if(row == ui->tableWidget->rowCount())
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    // receive msg in the slot
    for(int i = 0; i < 3; i++){
        qDebug() << row;
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(str[i]);
        table->setItem(row,i,item);
    }
    row++;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tableWidgetDisplay(){
   // QTableWidget *table = new QTableWidget(this);
    //table.set
}


void MainWindow::on_pushButton_clicked()
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int x = 0; x < ui->tableWidget->columnCount(); x++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText("Jay");
            table->setItem(i,x,item);
        }
    }
    QString str = ui->lineEdit->text();
    ui->lineEdit_2->setText(str);

    QStringList list;

    list.append(str);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    row--;
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->editItem(ui->tableWidget->currentItem());
}


void MainWindow::on_pushButton_4_clicked()
{
    // open sub window and connect
        Dialog *subwindow = new Dialog(this);
        connect(subwindow, SIGNAL(sendText(QStringList)), this, SLOT(receiveMsg(QStringList)));
        subwindow->show();
}

