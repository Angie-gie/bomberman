#ifndef MATRIZ_H
#define MATRIZ_H

#include <cstdlib>
#include <time.h>

#define diff 0.2

class Matriz
{
public:
    Matriz(int a, int b);
    void generar_mapa();
    bool aleatorio();
    int **get_matriz();
    int get_value(int fila, int columna);
    ~Matriz();
private:
    int **m,fil, col;
};

#endif // MATRIZ_H
