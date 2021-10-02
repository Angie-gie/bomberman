#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::movimiento_automatico()
{
    int x=globo->x(),y=globo->y();
        bool ableToMove = false;

//        if(sqrt((x-prota->x())*(x-prota->x())+(y-prota->y())*(y-prota->y())) <= tam){
//            scene->removeItem(prota);
//            time_muerte->start(100);
//        }
        int count_notMov = 0;
        int moves[4] = {0};
        while(ableToMove == false){
            if(last_eval == 1){
                if((m->get_value(((y+tam-1+5)/tam)-2,(x+tam-1)/tam)==8 && m->get_value(((y+tam-1+5)/tam)-2,x/tam)==8)){
                    globo->cambio_imagen_mov('s');
                    globo->setY(globo->y()+5);
                    last_eval = 1;
                    ableToMove = true;
                }else{
                    last_eval = 1 + rand()%(5-1);
                    if(moves[0]!=1){
                        count_notMov++;
                        moves[0]=1;
                    }
                }
            }
            if(last_eval == 2){
                if((m->get_value(((y-5)/tam)-2,x/tam)==8 && m->get_value(((y-5)/tam)-2,(x+tam-1)/tam)==8)){
                    globo->cambio_imagen_mov('w');
                    globo->setY(globo->y()-5);
                    last_eval = 2;
                    ableToMove = true;
                }else{
                    last_eval = 1 + rand()%(5-1);
                    if(moves[1]!=2){
                        count_notMov++;
                        moves[1]=2;
                    }
                }
            }
            if(last_eval == 3){
                if((m->get_value((y/tam)-2,(x-5)/tam)==8 && m->get_value(((y+tam-1)/tam)-2,(x-5)/tam)==8)){
                    globo->cambio_imagen_mov('d');
                    globo->setX(globo->x()-5);
                    last_eval = 3;
                    ableToMove = true;
                }else{
                    last_eval = 1 + rand()%(5-1);
                    if(moves[2]!=3){
                        count_notMov++;
                        moves[2]=3;
                    }
                }
            }
            if(last_eval == 4){
                if((m->get_value((y/tam)-2,(x+tam-1+5)/tam)==8 && m->get_value(((y+tam-1)/tam)-2,(x+tam-1+5)/tam)==8)){
                    globo->cambio_imagen_mov('a');
                    globo->setX(globo->x()+5);
                    last_eval = 4;
                    ableToMove = true;
                }else{
                    last_eval = 1 + rand()%(5-1);
                    if(moves[3]!=4){
                        count_notMov++;
                        moves[3]=4;
                    }
                }
            }
            if(count_notMov==4){
                ableToMove = true;
                globo->cambio_imagen_mov('s');
            }
        }
}

void MainWindow::pal()
{
    bomba->cambio_imagen();
}
void MainWindow::delete_bomb()
{
    time_palp->stop();
    time_bomb->stop();
    posx_bomb=bomba->x();posy_bomb=bomba->y();
    scene->removeItem(bomba);
    time_exp->start(200);
}

void MainWindow::llamado_explosion()
{
    explosion(posx_bomb,posy_bomb);
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    int x=prota->x(),y=prota->y();
    if(accept){
        if(i->key()==Qt::Key_S && m->get_value(((y+tam-1+5)/tam)-2,(x+tam-1)/tam)==8 && m->get_value(((y+tam-1+5)/tam)-2,x/tam)==8){
            prota->cambio_imagen_caminar('s');
            prota->setY(prota->y()+5);
        }else if(i->key()==Qt::Key_W && m->get_value(((y-5)/tam)-2,x/tam)==8 && m->get_value(((y-5)/tam)-2,(x+tam-1)/tam)==8){
            prota->cambio_imagen_caminar('w');
            prota->setY(prota->y()-5);
        }else if(i->key()==Qt::Key_A && m->get_value((y/tam)-2,(x-5)/tam)==8 && m->get_value(((y+tam-1)/tam)-2,(x-5)/tam)==8){
            prota->cambio_imagen_caminar('a');
            prota->setX(prota->x()-5);
        }else if(i->key()==Qt::Key_D && m->get_value((y/tam)-2,(x+tam-1+5)/tam)==8 && m->get_value(((y+tam-1)/tam)-2,(x+tam-1+5)/tam)==8){
            prota->cambio_imagen_caminar('d');
            prota->setX(prota->x()+5);
        }else if(i->key()==Qt::Key_F){
            bomba->setImagen(0,0);
            if(x%tam <= tam/2 && y%tam <= tam/2) bomba->setPos(x-x%tam,y-y%tam);
            else if(x%tam <= tam/2 && y%tam > tam/2) bomba->setPos(x-x%tam,y-y%tam+tam);
            else if(x%tam > tam/2 && y%tam <= tam/2) bomba->setPos(x-x%tam+tam,y-y%tam);
            else if(x%tam > tam/2 && y%tam > tam/2) bomba->setPos(x-x%tam+tam,y-y%tam);
            scene->addItem(bomba);
            time_palp->start(100);
            time_bomb->start(2000);
        }
    }
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_window();
    prota= new personaje;
    bomba= new Bomba;
    globo= new Enemigo;
    centro=new Bomba;
    izq= new Bomba;
    der= new Bomba;
    up= new Bomba;
    down= new Bomba;

    time_palp=new QTimer;
    time_bomb = new QTimer;
    time_exp=new QTimer;
    time_muerte=new QTimer;
    time_enemy=new QTimer;
    connect(time_palp,SIGNAL(timeout()),this,SLOT(pal()));
    connect(time_enemy,SIGNAL(timeout()),this,SLOT(movimiento_automatico()));
    connect(time_bomb,SIGNAL(timeout()),this,SLOT(delete_bomb()));
    connect(time_exp,SIGNAL(timeout()),this,SLOT(llamado_explosion()));
    connect(time_muerte,SIGNAL(timeout()),this,SLOT(anim_muerte()));

    globo->set_imagen(0);
    globo->setPos(385,140);
    scene->addItem(globo);
    time_enemy->start(100);
}


void MainWindow::explosion(int a, int b)
{
    centro->activar_explosion("centro");
    centro->setPos(a,b);
    scene->addItem(centro);


    if(m->get_value((b/tam)-2,(a+tam-1+5)/tam) == 8 && m->get_value(((b+tam-1)/tam)-2, (a+tam-1+5)/tam) == 8){
        der->activar_explosion("derecha");
        der->setPos(a+tam,b);
        scene->addItem(der);
        if(cont==7) scene->removeItem(der);
//        mapa[y/tam][x/tam+1];
    }
    if(m->get_value((b/tam)-2,(a-5)/tam) == 8 && m->get_value(((b+tam-1)/tam)-2, (a+5)/tam) == 8){
        izq->activar_explosion("izquierda");
        izq->setPos(a-tam,b);
        scene->addItem(izq);
        if(cont==7) scene->removeItem(izq);
//        mapa[y/tam][x/tam-1];
    }
    if(m->get_value(((b-5)/tam)-2,a/tam) == 8 && m->get_value(((b-5)/tam)-2, (a+tam-1)/tam) == 8){
        up->activar_explosion("arriba");
        up->setPos(a,b-tam);
        scene->addItem(up);
        if(cont==7) scene->removeItem(up);
//        mapa[y/tam+1][x/tam];
    }
    if(m->get_value(((b+tam-1+5)/tam)-2,(a+tam-1)/tam) == 8 && m->get_value(((b+tam-1+5)/tam)-2, a/tam) == 8){
        down->activar_explosion("abajo");
        down->setPos(a,b+tam);
        scene->addItem(down);
        if(cont==7) scene->removeItem(down);
//        mapa[y/tam-1][x/tam];
    }
    if(cont==7) {
        time_exp->stop();
        scene->removeItem(centro);
        cont=1;
    }
    cont++;
}

void MainWindow::generar_mapa()
{
    m= new Matriz(fil,col);
    puntaje = new bloques;
    puntaje->set_scale(tam*col,2*tam);
    puntaje->set_imagen(9);
    puntaje->setPos(0,0);

    inicializar();
    m->generar_mapa();
    mat=m->get_matriz();


    for (int f=0;f<fil;f++) {
        for (int c=0;c<col;c++) {
            mapa[f][c]->set_scale(tam,tam);
            mapa[f][c]->setPos(c*tam,(2+f)*tam);
            mapa[f][c]->set_imagen(mat[f][c]);
            scene->addItem(mapa[f][c]);
        }
    }
    scene->addItem(puntaje);

    prota->set_scale(tam,tam);
    prota->set_imagen(4,'a');
    prota->setPos(tam,3*tam);
    scene->addItem(prota);

    globo->set_imagen(0);
    globo->set_scale(tam,tam);
    globo->setPos(350,140);
    scene->addItem(globo);


}

void MainWindow::inicializar()
{
    mapa = new bloques** [fil];
    for (int f=0;f<fil;f++) {
        mapa[f] = new bloques* [col];
        for (int c=0;c<col;c++) {
            mapa[f][c]=new bloques;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete mapa;
    delete mat;
    delete m;
    delete prota;
    delete globo;
    delete time_palp;
    delete time_bomb;
    delete time_exp;
    delete time_muerte;
}

void MainWindow::set_window()
{
    scene=new QGraphicsScene;
    ui->graphicsView->setGeometry(0,0,tam*col+2,tam*(fil+2)+2);
    scene->setSceneRect(0,0,tam*col,tam*(fil+2));
    ui->graphicsView->setScene(scene);
    setFixedSize(tam*col+2,tam*(fil+2)+2);
    setWindowTitle("Bomberman");

}

void MainWindow::anim_muerte()
{
    bool mod = false;
    if(first){
        dead = new personaje;
        first = false;
    }
    if(dead->get_muerte()==0){
        accept = false;
        dead->set_scale(tam,tam);
        dead->setPos(prota->x(),prota->y());
        dead->set_imagen(dead->get_muerte(),'m');
        scene->addItem(dead);
    }
    if(dead->get_muerte()==6){
        time_muerte->stop();
        prota->set_scale(tam,tam);
        prota->set_imagen(4,'a');
        prota->setPos(tam,3*tam);
        scene->addItem(prota);
        scene->removeItem(dead);
        accept = true;
        mod = true;
    }
    dead->set_imagen(dead->get_muerte(),'m');
    dead->set_muerte(dead->get_muerte()+1);
    if(mod) dead->set_muerte(0);
}
