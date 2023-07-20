#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <allegro.h>
#include <string>
/**
    Clase base para la creaci�n de personajes.
*/
class Personaje
{
    private:
        int px; ///posici�n del personaje en el eje x
        int py; ///posici�n del personaje en el eje y
    protected:
        int dir; /// define la direcci�n del personaje
        int antesPx;  ///Guardan la posici�n anterior del personaje.
        int antesPy;
    public:
        Personaje(int,int);///Constructor de dos argumentos para personaje usuario
        Personaje(int,int,int); ///Constructor de tres argumentos para personajes autom�ticos
        virtual ~Personaje();///Destructor

        ///M�todos para obtener y asignar los valores de los atributos privados y protegidos
        inline void setDir(int dir){this->dir=dir;}
        inline int getDir(){return dir;}
        inline void setPx(int px){this->px=px;}
        inline int getPx(){return px;}
        inline void setPy(int py){this->py=py;}
        inline int getPy(){return py;}
        inline void setAntesPx(int antesPx){this->antesPx=antesPx;}
        inline int getAntesPx(){return antesPx;}
        inline void setAntesPy(int antesPy){this->antesPx=antesPx;}
        inline int getAntesPy(){return antesPx;}

        ///M�todos virtuales puros.
        virtual void creandoBitmap()=0;
        virtual void direcciones()=0;
        virtual void mover()=0;
        virtual void limpiarPersonaje()=0;

};

#endif // PERSONAJE_H
