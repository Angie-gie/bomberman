#ifndef BLOQUES_H
#define BLOQUES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class bloques : public QObject, public QGraphicsPixmapItem
{
public:
    bloques();
    void set_imagen(int a);
    void set_scale(int a, int b);
private:
    QPixmap original, img;
    int scalex=1, scaley=1;
};

#endif // BLOQUES_H
