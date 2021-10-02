#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class Enemigo :public QObject, public QGraphicsPixmapItem
{
public:
    Enemigo();
    void set_imagen(int a);
    void set_scale(int a, int b);
    void logica_movimientos(int **m,int tam);
    void cambio_imagen_mov(short a);
private:
    QPixmap img,original;
    int scalex=1, scaley=1;
    short movimiento[2];
    bool dir[4];

};

#endif // ENEMIGO_H
