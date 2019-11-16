#include "poligononlados.h"
#include "ui_poligononlados.h"
#include <math.h>
#include <QPainter>
#include <QMessageBox>
void drawPoligono(int lados, int rad, QPainter &painter);
poligononlados::poligononlados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::poligononlados)
{
    ui->setupUi(this);
    centroX = width()/2;
    centroY = height()/2;
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
}

poligononlados::~poligononlados()
{
    delete ui;
}

void poligononlados::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pointPen(Qt::blue);
    pointPen.setWidth(3);
    painter.setPen(pointPen);
    if (draw){
        QString nS = ui->boxLados->toPlainText();

        if(!nS.isEmpty()) {
            lados = nS.toInt();
            for(int i=0; i<qVecTrans.size(); ++i){
                painter.setTransform(qVecTrans[i],true);
                drawPoligono(lados, radio ,painter);
            }
        }else {
            QMessageBox msgBox;
            msgBox.setText("Favor de elegir numero de lados");
            msgBox.exec();
        }
    }
}

void poligononlados::drawPoligono(int lados, int radio,QPainter &painter){
    radio=80;
      double ang = (double)360.0/(double)lados,  v = 3.141592 / 180, centX = 0.0, centY = 0.0;
      int xi,yi,xf,yf;
      ang *= v;
      for(int a=1; a<=lados; a++) {
        xi = centX + (radio * cos(ang*a));
        yi = centY + (radio * sin(ang*a));

        xf = centX + (radio * cos(ang*(a+1)));
        yf = centY + (radio * sin(ang*(a+1)));

        painter.drawLine(xi, yi, xf, yf);
      }
}

void poligononlados::on_pushButton_clicked()
{
    qVecTrans.clear();
    QString n = ui->boxLados->toPlainText();
     if(!n.isEmpty()) {

       QTransform centro;
       centro.translate(centroX,centroY);
       qVecTrans.push_back(centro);
       draw = !draw;
     } else {
       QMessageBox msgBox;
       msgBox.setText("Favor de elegir numero de lados");
       msgBox.exec();
     }
     update();
}

void poligononlados::on_pushButton_2_clicked()
{
    //Trasladar
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

void poligononlados::on_pushButton_4_clicked()
{
    QTransform zIn;
    zIn.scale(2,2);
    qVecTrans.push_back(zIn);
    update();

}

void poligononlados::on_pushButton_5_clicked()
{
    QTransform zOut;
    zOut.scale(0.5,0.5);
    qVecTrans.push_back(zOut);
    update();

}

void poligononlados::on_pushButton_3_clicked()
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

void poligononlados::on_pushButton_7_clicked()
{
    QTransform rv;
    rv.scale(1,-1);
    qVecTrans.push_back(rv);
    update();

}

void poligononlados::on_pushButton_6_clicked()
{
    QTransform rh;
    rh.scale(-1,1);
    qVecTrans.push_back(rh);
    update();

}
