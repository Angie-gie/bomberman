#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "bloques.h"
#include "matriz.h"
#include "personaje.h"
#include "enemigo.h"
#include "bomba.h"
#include <QKeyEvent>
#include <QTimer>
#include <math.h>


#define fil 13
#define col 31
#define tam 35

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void movimiento_automatico();
    void pal();
    void delete_bomb();
    void llamado_explosion();
    void anim_muerte();
public:
    void keyPressEvent(QKeyEvent *i);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_window();
    void explosion(int a, int b);
private:
    void generar_mapa();
    void inicializar();

    Ui::MainWindow *ui;
    bloques *puntaje, ***mapa;
    personaje *prota,*dead;
    QGraphicsScene *scene;
    Matriz *m;
    int **mat,cont=1,posx_bomb,posy_bomb,last_eval = 1;
    bool dir[4],accept = true,first=true;
    QTimer *time_palp,*time_bomb,*time_exp,*time_muerte,*time_enemy;
    Enemigo *globo;
    Bomba *bomba,*centro,*izq,*der,*up,*down;
};
#endif // MAINWINDOW_H
