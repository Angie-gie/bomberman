#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class personaje: public QObject, public QGraphicsPixmapItem
{
public:
    personaje();
    void set_imagen(int a,char m);
    void set_scale(int a, int b);
    void cambio_imagen_caminar(short a);
    void set_muerte(int muerte);
    int get_muerte();
private:
    QPixmap original,original1,original2, img;
    int scalex=1, scaley=1,numMuerte=0;
    short movimiento[4];
    bool dir[4];
};

#endif // PERSONAJE_H
