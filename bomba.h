#ifndef BOMBA_H
#define BOMBA_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <string>
#include <QTimer>

using namespace std;

class Bomba: public QObject, public QGraphicsPixmapItem
{
public slots:
    void cambio_imagen_explosion(string b);
public:
    void setBomba();
    Bomba();
    void activar_explosion(string a);
    void setImagen(int a,int b);
    void cambio_imagen();
    bool validar();
private:
    QPixmap bomb,original, explosion1,explosion2,explosion3,explosion4,
    explosion5,explosion6,explosion7,explosion8;
    int scalex=35, scaley=35;
    int cont=0,ex=4,ey=8;
    bool dir=true,estado=true,direxp=false;
    QTimer *time;
};

#endif // BOMBA_H
