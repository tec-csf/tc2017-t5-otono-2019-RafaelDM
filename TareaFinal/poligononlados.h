#ifndef POLIGONONLADOS_H
#define POLIGONONLADOS_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
namespace Ui {
class poligononlados;
}

class poligononlados : public QDialog
{
    Q_OBJECT

public:
    explicit poligononlados(QWidget *parent = 0);
    ~poligononlados();

protected:
     void paintEvent(QPaintEvent *e);
     void drawPoligono(int lados, int rad,QPainter &painter);

private:
    Ui::poligononlados *ui;
    bool draw = false;
    int lados, radio;
    double centroX, centroY;
    QVector<QTransform> qVecTrans;

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_6_clicked();
};

#endif // POLIGONONLADOS_H
