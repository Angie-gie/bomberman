#include "matriz.h"

Matriz::Matriz(int a, int b)
{
    fil=a;
    col=b;
    m = new int* [fil];
    for (int f=0;f<fil;f++) {
        m[f] = new int[col];
    }
    srand(time(NULL));
}

void Matriz::generar_mapa()
{
    for(int f=0;f<fil;f++){
        for(int c=0;c<col;c++){
            if(f*c==0 || f==fil-1 || c==col-1 || (f%2==0 && c%2==0)){
                m[f][c]=0;
            }else if((f==1 && c==1) || (f==1 && c==2) || (f==2 && c==1)){
                m[f][c]=8;
            }else if(aleatorio()) {
                m[f][c]=1;
            }else{
                m[f][c]=8;
            }
        }
    }
}

bool Matriz::aleatorio()
{
    int n;float x;
    x=diff*(RAND_MAX+1)-1;
    n=rand();
    return n<=x;

}

int **Matriz::get_matriz()
{
    return m;
}

int Matriz::get_value(int fila, int columna)
{
    return m[fila][columna];
}

Matriz::~Matriz()
{
    delete m;
}
