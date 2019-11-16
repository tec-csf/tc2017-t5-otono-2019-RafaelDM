#ifndef PRISMABASETRIAN_H
#define PRISMABASETRIAN_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
namespace Ui {
class prismabasetrian;
}

class prismabasetrian : public QDialog
{
    Q_OBJECT

public:
    explicit prismabasetrian(QWidget *parent = 0);
    ~prismabasetrian();

protected:
     void paintEvent(QPaintEvent *e);
     void drawPrismaBaseTrian(QPainter &painter);


private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_6_clicked();

private:
    Ui::prismabasetrian *ui;
    bool draw = false;
    double centroX, centroY;
    QVector<QTransform> qVecTrans;
};

#endif // PRISMABASETRIAN_H
