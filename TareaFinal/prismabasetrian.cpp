#include "prismabasetrian.h"
#include "ui_prismabasetrian.h"
#include <QPainter>
#include <QMessageBox>

prismabasetrian::prismabasetrian(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prismabasetrian)
{
    ui->setupUi(this);

    centroX = width()/2;
    centroY = height()/2;
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
}

prismabasetrian::~prismabasetrian()
{
    delete ui;
}

void prismabasetrian::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pointPen(Qt::blue);
    pointPen.setWidth(3);
    painter.setPen(pointPen);
    if (draw){
        for(int i=0; i<qVecTrans.size(); ++i){
            painter.setTransform(qVecTrans[i],true);
            drawPrismaBaseTrian(painter);
        }
    }
}
void prismabasetrian::drawPrismaBaseTrian(QPainter &painter){
        painter.drawLine(0,-100,-50,-140);
        painter.drawLine(0,-100,50,-140);
        painter.drawLine(-50,-140,50,-140);
        painter.drawLine(0,0,-50,-40);
        painter.drawLine(0,0,50,-40);
        painter.drawLine(-50,-40,50,-40);
        painter.drawLine(0,-100,0,0);
        painter.drawLine(-50,-140,-50,-40);
        painter.drawLine(50,-40,50,-140);
}

void prismabasetrian::on_pushButton_clicked()
{

    qVecTrans.clear();
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
    draw = !draw;
    update();
}

void prismabasetrian::on_pushButton_2_clicked()
{

    QString x = ui->boxXinicio->toPlainText();
    QString y = ui->boxYinicio->toPlainText();
     if(!x.isEmpty() && !y.isEmpty()) {
       int xS = x.toInt();
       int yS = y.toInt();
       QTransform t;
       t.translate(xS, yS);
       qVecTrans.push_back(t);
     } else {
       QMessageBox msgBox;
       msgBox.setText("Favor de elegir traslacion");
       msgBox.exec();
     }
     update();
}

void prismabasetrian::on_pushButton_4_clicked()
{

    QTransform zIn;
    zIn.scale(2,2);
    qVecTrans.push_back(zIn);
    update();
}

void prismabasetrian::on_pushButton_5_clicked()
{

    QTransform zOut;
    zOut.scale(0.5,0.5);
    qVecTrans.push_back(zOut);
    update();
}

void prismabasetrian::on_pushButton_3_clicked()
{
    QString r = ui->boxGrados->toPlainText();
      if(!r.isEmpty()) {
        int rS = r.toInt();
        QTransform r;
        r.rotate(rS);
        qVecTrans.push_back(r);
      } else {
        QMessageBox msgBox;
        msgBox.setText("Favor de elegir angulo");
        msgBox.exec();
      }
    update();
}

void prismabasetrian::on_pushButton_7_clicked()
{
    QTransform rv;
    rv.scale(1,-1);
    qVecTrans.push_back(rv);
    update();
}

void prismabasetrian::on_pushButton_6_clicked()
{
    QTransform rh;
    rh.scale(-1,1);
    qVecTrans.push_back(rh);
    update();
}
