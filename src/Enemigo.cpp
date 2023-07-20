#include "Enemigo.h"
#include <allegro.h>
Enemigo::Enemigo():Personaje{13*30,13*30,rand()%4}
{
        ///Construye al personaje enemigo inicializando su posición en el tablero, y la dirección inicial
        ///dada aleatoriamente por números del 0-3
}

Enemigo::~Enemigo()
{
    ///dtor
}

void Enemigo::creandoBitmap()
{
    enemigo=create_bitmap(30,30);
    enemy_bmp=load_bitmap("EnemigoPac.bmp",NULL);
}
/**
    Método en el que se crea un motor de números aleatorios.
*/
int Enemigo::motorAleatorios(){
    unsigned int semilla=chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motor(semilla);

    return motor();
}
/**
    Método con el que se asigna memoria en la pantalla para
    mostrar el personaje en sus diferentes direcciones dependiendo
    de la dirección correspondiente.
*/
void Enemigo::direcciones()
{
        if (dir==0){
            blit(enemy_bmp,enemigo,33,0,0,0,30,30);
            rest(50);
        }
        if (dir==1){
            blit(enemy_bmp,enemigo,66,0,0,0,30,30);
            rest(50);
        }
        if (dir==2){
            blit(enemy_bmp,enemigo,99,0,0,0,30,30);
            rest(50);
        }
        if (dir==3){
            blit(enemy_bmp,enemigo,0,0,0,0,30,30);
            rest(50);
        }
}

void Enemigo::mover()
{

}

void Enemigo::limpiarPersonaje()
{
    clear(enemigo);
}
