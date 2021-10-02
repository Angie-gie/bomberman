#include "personaje.h"

personaje::personaje()
{
    original.load(":/Bomberman/personaje/personaje_mov.png");
    original1.load(":/Bomberman/personaje/personaje2_mov.png");
    original2.load(":/Bomberman/personaje/muerte_personaje.png");
    movimiento[0]=3;movimiento[1]=3;movimiento[2]=0;movimiento[3]=0;
}
void personaje::set_imagen(int a, char m)
{
    if(m=='m'){
        img=original2.copy(16*a,0,16,16);
    }else if(m=='i' || m=='a'){
        img=original.copy(16*a,0,16,16);
    }else if(m=='d' || m=='u'){
        img=original1.copy(16*a,0,16,16);
    }
    setPixmap(img.scaled(scalex,scaley));
}

void personaje::set_scale(int a, int b)
{
    scalex=a;
    scaley=b;
}

void personaje::cambio_imagen_caminar(short a)
{
    switch (a) {

    case 's':
    {
        if(movimiento[0]==5) dir[0]=false;
        else if(movimiento[0]==3) dir[0]=true;
        movimiento[0]+=(2*dir[0]-1);
        set_imagen(movimiento[0],'a');
        break;
    }
    case 'w':{
        if(movimiento[1]==5) dir[1]=false;
        else if(movimiento[1]==3) dir[1]=true;
        movimiento[1]+=(2*dir[1]-1);
        set_imagen(movimiento[1],'u');
        break;
    }
    case 'a':{
        if(movimiento[2]==2) dir[2]=false;
        else if(movimiento[2]==0) dir[2]=true;
        movimiento[2]+=(2*dir[2]-1);
        set_imagen(movimiento[2],'i');
        break;
    }
    case 'd':{
        if(movimiento[3]==2) dir[3]=false;
        else if(movimiento[3]==0) dir[3]=true;
        movimiento[3]+=(2*dir[3]-1);
        set_imagen(movimiento[3],'d');
        break;
    }
    }

}

int personaje::get_muerte()
{
    return numMuerte;
}

void personaje::set_muerte(int muerte)
{
    numMuerte = muerte;
}
