#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <iostream>
#include <allegro.h>
#include <random>
#include <chrono>
#include "Personaje.h"
using namespace std;
/**
    Clase derivada de "Personaje". Se encarga de crear un personaje
    antagonista controlado automáticamente.
*/
class Enemigo: public Personaje
{
    private:
        ///Se definen los mapas de bits para la plantilla del personaje.
        BITMAP *enemigo;
        BITMAP *enemy_bmp;


    public:
        ///Constructor y destructor
        Enemigo();
        ~Enemigo();
        ///Métodos que retornan los mapas de bits privados.
        inline BITMAP *getEnemy(){return enemigo;}
        inline BITMAP *getEnemyBmp(){return enemy_bmp;}
        ///Motor de números aleatorios para los movimientos del personaje.
        int motorAleatorios();
        ///Métodos sobrescritos de la clase base.
        void creandoBitmap()override;
        void direcciones()override;
        void mover()override;
        void limpiarPersonaje()override;


};

#endif // ENEMIGO_H
