#include "dialog.h"
#include "ui_dialog.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QDebug>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
   // QString = ui->lineEdit->text();
    QStringList list;
    list.append(ui->lineEdit->text());
    list.append(ui->lineEdit_2->text());
    list.append(ui->lineEdit_3->text());
    emit sendText(list);
    //qDebug() << list[0] << " " << list[1];
    //table->setItem(0,0,item);
}
