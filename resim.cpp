#include "resim.h"
#include <math.h>
resim::resim(QWidget *parent) : QLabel(parent)
{
    renk = qRgb(255,255,0);
    QImage arkaplan(600,600,QImage::Format_A2BGR30_Premultiplied);
    setPixmap(QPixmap::fromImage(arkaplan));
    ortam = arkaplan;
    kontrol =0;


}

void resim::cizDDa()
{
    double dx = sonnokta.x() - ilknokta.x();
    double dy = sonnokta.y() - ilknokta.y();
    double Xfark;
    double Yfark;
    double x;
    double y;
    double pixselsayi;
    if(fabs(dx)>fabs(dy)){

        pixselsayi= dx;


    }else{

        pixselsayi = dy;
    }
    Xfark=dx/pixselsayi;
    Yfark=dy/pixselsayi;
    x=ilknokta.x();
    y=ilknokta.y();

    for (int i=0;i<pixselsayi ;i++ ) {
        x+= Xfark;
        y+= Yfark;
        ortam.setPixel(round(x),round(y),renk);

    }
    setPixmap(QPixmap::fromImage(ortam));

}

void resim::Bresenham()
{
    double x,y,dx,dy;
        double s1,s2;

        x=ilknokta.x();
        y=ilknokta.y();
        dx=fabs(sonnokta.x() - ilknokta.x());
        dy=fabs(sonnokta.y() - ilknokta.y()) ;

        s1 =getSign(sonnokta.x() - ilknokta.x());
        s2 =getSign(sonnokta.y() - ilknokta.y());

        double interchange;

        if(dy > dx){
            int temp = dy;
            dy=dx;
            dx=temp;
            interchange=1;
        }

        double err=2*dy-dx;

        for (int i=0;i<(dx-1);++i) {
            if(err>0){
                if(interchange == 1) x+=s1;
                else y+=s2;
                err -=2*dx;
            }
            if(interchange==1)y+=s2;
            else x+=s1;

            err+=2*dy;
            ortam.setPixel(round(x),round(y),renk);
            setPixmap(QPixmap::fromImage(ortam));
        }
}

int resim::getSign(int x)
{
    if (x < 0) return -1;
      return 1;
}

void resim::mousePressEvent(QMouseEvent *event)
{
    if(kontrol % 2 == 0){

        ilknokta=event->pos();
        kontrol++;
    }else{

        sonnokta=event->pos();
        kontrol++;
        Bresenham();
    }




}
