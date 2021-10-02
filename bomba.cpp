#include "bomba.h"

Bomba::Bomba()
{
    original.load(":/Bomberman/bomba/still.png");
    explosion1.load(":/Bomberman/explosión/1.png");
    explosion2.load(":/Bomberman/explosión/2.png");
    explosion3.load(":/Bomberman/explosión/3.png");
    explosion4.load(":/Bomberman/explosión/4.png");
    explosion5.load(":/Bomberman/explosión/5.png");
    explosion6.load(":/Bomberman/explosión/6.png");
    explosion7.load(":/Bomberman/explosión/7.png");
    explosion8.load(":/Bomberman/explosión/8.png");

}

void Bomba::setImagen(int a,int b)
{
    if(b==0){
        bomb=original.copy(16*a,0,16,16);
    }else if(b==1){
        bomb=explosion1.copy(16*a,0,16,16);
    }else if(b==5){
        bomb=explosion2.copy(0,16*a,16,16);
    }else if(b==2){
        bomb=explosion3.copy(16*a,0,16,16);
    }else if(b==6){
        bomb=explosion4.copy(0,16*a,16,16);
    }else if(b==3){
        bomb=explosion5.copy(16*a,0,16,16);
    }else if(b==7){
        bomb=explosion6.copy(0,16*a,16,16);
    }else if(b==4){
        bomb=explosion7.copy(16*a,0,16,16);
    }else if(b==8){
        bomb=explosion8.copy(0,16*a,16,16);
    }
    setPixmap(bomb.scaled(scalex,scaley));
}

void Bomba::cambio_imagen()
{
    if(cont==2){
        dir=false;
    }else if(cont==0) dir=true;
    cont+=(2*dir-1);
    setImagen(cont,0);
}

void Bomba::activar_explosion(string a)
{
    cambio_imagen_explosion(a);
}

void Bomba::cambio_imagen_explosion(string b)
{

    if(b=="derecha"){
        setImagen(4,ex);
        if(ex==1)ex++;
        else ex--;
    }else if(b=="izquierda"){
        setImagen(0,ex);
        if(ex==1) ex++;
        else ex--;
    }else if(b=="arriba"){
        setImagen(0,ey);
        if(ey==5) ey++;
        else ey--;
    }else if(b=="abajo"){
        setImagen(4,ey);
        if(ey==5) ey++;
        else ey--;
    }else if(b=="centro"){
        setImagen(2,ex);
        if(ex==1)ex++;
        else ex--;
    }
}

bool Bomba::validar()
{
    return estado;
}

void Bomba::setBomba()
{
    cambio_imagen();
}
