#ifndef GATO_H
#define GATO_H
#include <iostream>
#include <allegro.h>
#include "Personaje.h"
/**
    Clase derivada de "Personaje". Se encarga de crear un personaje
    principal controlado por el usuario.
*/
class Gato: public Personaje
{
    private:
        ///Se definen los mapas de bits para la plantilla del personaje.
        BITMAP *cat;
        BITMAP *catbmp;

    public:
        ///Constructor y destructor
        Gato();
        ~Gato();
        ///Métodos que retornan los mapas de bits privados.
        inline BITMAP * getCat(){return cat;}
        inline BITMAP *getCatbmp(){return catbmp;}
        ///Métodos sobrescritos de la clase base.
        void creandoBitmap()override;
        void direcciones()override;
        void mover()override;
        void limpiarPersonaje()override;
};

#endif // GATO_H
