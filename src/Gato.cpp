#include "Gato.h"

Gato::Gato():Personaje{14*30,11*30}
{
    ///Construye al personaje gato inicializando su posición en el tablero
}

Gato::~Gato()
{
    ///Destructor
}

void Gato::creandoBitmap()
{
    cat=create_bitmap(33,33);
    catbmp=load_bitmap("cat.bmp",NULL);
}
/**
    Método con el que se asigna memoria en la pantalla para
    mostrar el personaje en sus diferentes direcciones dependiendo
    de la tecla presionada.
*/
void Gato::direcciones()
{
    if(key[KEY_RIGHT]) {
        blit(catbmp,cat,0,33,0,0,33,33);
        dir = 1;
    }else if(key[KEY_LEFT]){
        blit(catbmp,cat,0,99,0,0,33,33);
        dir = 0;
    }else if(key[KEY_UP]){
        blit(catbmp,cat,0,66,0,0,33,33);
        dir = 2;
    }else if(key[KEY_DOWN]){
        blit(catbmp,cat,0,0,0,0,33,33);
        dir = 3;
    } else{
        blit(catbmp,cat,66,0,0,0,33,33);
        dir=8;
    }
}
/**
    Método que se encarga de mover al personaje por el mapa
    dependiendo al valor de su dirección.
*/
void Gato::mover()
{
        if(dir==1) {
                setPx(getPx()+30);
        }
        else if(dir==0){
                setPx(getPx()-30);
        }
        else if(dir==2){
                setPy(getPy()-30);
        }
        else if(dir==3){
                setPy(getPy()+30);
        }
}
void Gato::limpiarPersonaje()
{
        clear(cat);
}
