#include "enemigo.h"

Enemigo::Enemigo()
{
    original.load(":/Bomberman/Enemigo/globo.png");
    movimiento[0]=0;movimiento[1]=3;
    dir[0]=true;
}

void Enemigo::set_imagen(int a)
{
    img=original.copy(16*a,0,16,16);
    setPixmap(img.scaled(scalex,scaley));
}

void Enemigo::set_scale(int a, int b)
{
    scalex=a;
    scaley=b;
}

void Enemigo::cambio_imagen_mov(short a)
{
    if(a=='s' || a=='a'){
        if(movimiento[0]==2) dir[0]=false;
        else if(movimiento[0]==0) dir[0]=true;
        movimiento[0]+=(2*dir[0]-1);
        set_imagen(movimiento[0]);
    }else if(a=='w' || a=='d'){
        if(movimiento[1]==5) dir[1]=false;
        else if(movimiento[1]==3) dir[1]=true;
        movimiento[1]+=(2*dir[1]-1);
        set_imagen(movimiento[1]);
    }
}
