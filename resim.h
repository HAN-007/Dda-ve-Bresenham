#ifndef RESIM_H
#define RESIM_H

#include <QLabel>
#include<QMouseEvent>
class resim : public QLabel
{
    Q_OBJECT
public:
    explicit resim(QWidget *parent = nullptr);
    void cizDDa();
    void Bresenham();
    int getSign(int x);
private:
    QRgb renk;
    QPoint ilknokta;
    QPoint sonnokta;
    QImage ortam;
    void mousePressEvent(QMouseEvent*);
    int kontrol;

signals:

};

#endif // RESIM_H
