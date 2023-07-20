#ifndef MAPA_H
#define MAPA_H
#include <iostream>
#include <allegro.h>
/**
    Clase Base para la creación de tableros.
    Se definen todos los componentes que un Tablero podría contener.
*/
class Mapa
{
    private:
        ///Define el número de filas y columnas del Tablero
        size_t filas;
        size_t columnas;
    protected:
        ///Se crea un arreglo de carácteres para la base del mapa
        char **mapa;
    public:
        ///Contructor y destructor
        Mapa(size_t, size_t);
        virtual ~Mapa();

        ///Carácteres estáticos que definen el tipo de objeto
        ///que imprimirá en los tableros
        char obstaculo{'X'};
        static constexpr char comida{'o'};
        static constexpr char cristal{'c'};
        static constexpr char moneda{'m'};
        static constexpr char portal{'p'};
        ///Funciones para obtener y dar valores a los atributos privados
        inline void setFilas(size_t filas){this->filas=filas;}
        inline size_t getFilas(){return filas;}
        inline void setColumnas(size_t columnas){this->columnas=columnas;}
        inline size_t getColumnas(){return columnas;}
        ///Funciones para obtener y asignar carácteres a una determinada
        ///posición del tablero.
        virtual void setXY(size_t x,size_t y,char c)=0;
        virtual char getXY(size_t x, size_t y)=0;
};

#endif // MAPA_H
