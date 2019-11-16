#include "prismabaserect.h"
#include "ui_prismabaserect.h"
#include <QPainter>
#include <QMessageBox>

prismabaserect::prismabaserect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prismabaserect)
{
    ui->setupUi(this);
    centroX = width()/2;
    centroY = height()/2;
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
}

prismabaserect::~prismabaserect()
{
    delete ui;
}


void prismabaserect::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pointPen(Qt::blue);
    pointPen.setWidth(3);
    painter.setPen(pointPen);
    if (draw){
        for(int i=0; i<qVecTrans.size(); ++i){
            painter.setTransform(qVecTrans[i],true);
            drawPrismaBaseRect(painter);
        }
    }
}

void prismabaserect::drawPrismaBaseRect(QPainter &painter){
     painter.drawLine(0,100,60,0);
     painter.drawLine(60,0,160,0);
     painter.drawLine(60,-300,60,0);

     painter.drawLine(100,100,160,0);
     painter.drawLine(0,-200,60,-300);
     painter.drawLine(100,-200,160,-300);
     painter.drawLine(0,100,100,100);
     painter.drawLine(0,-200,100,-200);
     painter.drawLine(0,-200,0,100);
     painter.drawLine(100,-200,100,100);
     painter.drawLine(60,-300,160,-300);
     painter.drawLine(160,-300,160,0);

}
void prismabaserect::on_pushButton_clicked()
{
    qVecTrans.clear();
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
    draw = !draw;
    update();
}

void prismabaserect::on_pushButton_2_clicked()
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

void prismabaserect::on_pushButton_4_clicked()
{
    QTransform zIn;
    zIn.scale(2,2);
    qVecTrans.push_back(zIn);
    update();
}

void prismabaserect::on_pushButton_5_clicked()
{
    QTransform zOut;
    zOut.scale(0.5,0.5);
    qVecTrans.push_back(zOut);
    update();
}

void prismabaserect::on_pushButton_3_clicked()
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

void prismabaserect::on_pushButton_7_clicked()
{
    QTransform rv;
    rv.scale(1,-1);
    qVecTrans.push_back(rv);
    update();
}

void prismabaserect::on_pushButton_6_clicked()
{
    QTransform rh;
    rh.scale(-1,1);
    qVecTrans.push_back(rh);
    update();
}

