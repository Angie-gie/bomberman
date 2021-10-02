#include "bloques.h"

bloques::bloques()
{
    original.load(":/Bomberman/Bloques/bloques.png");
}

void bloques::set_imagen(int a)
{
    if(a==8) {
        img=original.copy(126,14,1,1);
    }else if(a==9){
        img=original.copy(0,0,1,1);
    }else{
        img=original.copy(16*a,0,16,16);
    }
    setPixmap(img.scaled(scalex,scaley));
}

void bloques::set_scale(int a, int b)
{
    scalex=a;
    scaley=b;
}
