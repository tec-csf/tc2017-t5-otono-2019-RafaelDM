#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

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


void Dialog::on_pushButton_2_clicked()
{
    poligononlados pN;
    pN.setModal(true);
    pN.exec();
}

void Dialog::on_pushButton_3_clicked()
{
    cono c;
    c.setModal(true);
    c.exec();
}

void Dialog::on_pushButton_4_clicked()
{
    cubo cu;
    cu.setModal(true);
    cu.exec();
}

void Dialog::on_pushButton_5_clicked()
{
    prismabaserect pbr;
    pbr.setModal(true);
    pbr.exec();
}

void Dialog::on_pushButton_6_clicked()
{
    prismabasetrian pbt;
    pbt.setModal(true);
    pbt.exec();
}





