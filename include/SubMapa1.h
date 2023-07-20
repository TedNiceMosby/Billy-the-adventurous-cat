#ifndef SUBMAPA1_H
#define SUBMAPA1_H
#include "Mapa.h"
#include <iostream>
#include <allegro.h>

/**
    Clase derivada de la clase Mapa.
    En esta se da forma y se especializa el tablero,
*/
class SubMapa1: public Mapa
{
    private:
        ///Creamos los BITMAP's de los objetos que componen al tablero.
        BITMAP *roca;
        BITMAP *pastel;
        BITMAP *cristal;
        BITMAP *moneda;
        BITMAP *pasto;
        BITMAP *portal;
        BITMAP *corazon;
    public:
        ///Constructor y destructor
        SubMapa1();
        ~SubMapa1();

        ///Métodos sobreescritos derivados de la clase padre.
        ///Definen y obtienen el carácter de un elemento del tablero.
        void setXY(size_t x,size_t y,char c) override;
        char getXY(size_t x, size_t y) override;

        ///Métodos con los que se obtienen los mapas de bits de los elementos que componen al tablero.
        inline BITMAP *getCristal(){return cristal;}
        inline BITMAP *getRoca(){return roca;}
        inline BITMAP *getPastel(){return pastel;}
        inline BITMAP *getMoneda(){return moneda;}
        inline BITMAP *getPasto(){return pasto;}
        inline BITMAP *getPortal(){return portal;}
        inline BITMAP *getCorazon(){return corazon;}


        void dibujarMapa();
        void mostrarMapa();
        void crearBitmap();
        void limpiarPasto();
        void cargarPasto();

};
#endif // SUBMAPA1_H
