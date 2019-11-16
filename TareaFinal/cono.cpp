#include "cono.h"
#include "ui_cono.h"
#include <QPainter>
#include <QMessageBox>
#include <math.h>

cono::cono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cono)
{
    ui->setupUi(this);
    centroX = width()/2;
    centroY = height()/2;
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
}

cono::~cono()
{
    delete ui;
}


void cono::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pointPen(Qt::blue);
    pointPen.setWidth(3);
    painter.setPen(pointPen);
    if (draw){
        QString h = ui->boxAltura->toPlainText();
        if(!h.isEmpty()) {
            altura = h.toInt();
            for(int i=0; i<qVecTrans.size(); ++i){
                painter.setTransform(qVecTrans[i],true);
                drawCono(painter,altura);
            }
        }else {
            QMessageBox msgBox;
            msgBox.setText("Favor de elegir altura del cono");
            msgBox.exec();
        }
    }
}

void cono::drawCono(QPainter &painter, int altura){
    painter.drawEllipse(-50,-25,100,50);
    painter.drawLine(0,altura,50,0);
    painter.drawLine(0,altura,-50,0);
}

void cono::on_pushButton_clicked()
{
    qVecTrans.clear();
    QString h = ui->boxAltura->toPlainText();
     if(!h.isEmpty()) {
       QTransform centro;
       centro.translate(centroX,centroY);
       qVecTrans.push_back(centro);
       draw = !draw;
     } else {
       QMessageBox msgBox;
       msgBox.setText("Favor de elegir altura");
       msgBox.exec();
     }
     update();
}

void cono::on_pushButton_2_clicked()
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

void cono::on_pushButton_4_clicked()
{
    QTransform zIn;
    zIn.scale(2,2);
    qVecTrans.push_back(zIn);
    update();
}

void cono::on_pushButton_5_clicked()
{
    QTransform zOut;
    zOut.scale(0.5,0.5);
    qVecTrans.push_back(zOut);
    update();
}

void cono::on_pushButton_3_clicked()
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

void cono::on_pushButton_7_clicked()
{
    QTransform rv;
    rv.scale(1,-1);
    qVecTrans.push_back(rv);
    update();
}

void cono::on_pushButton_6_clicked()
{
    QTransform rh;
    rh.scale(-1,1);
    qVecTrans.push_back(rh);
    update();
}
