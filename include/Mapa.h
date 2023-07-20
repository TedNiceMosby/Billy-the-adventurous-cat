#ifndef MAPA_H
#define MAPA_H
#include <iostream>
#include <allegro.h>
/**
    Clase Base para la creaci�n de tableros.
    Se definen todos los componentes que un Tablero podr�a contener.
*/
class Mapa
{
    private:
        ///Define el n�mero de filas y columnas del Tablero
        size_t filas;
        size_t columnas;
    protected:
        ///Se crea un arreglo de car�cteres para la base del mapa
        char **mapa;
    public:
        ///Contructor y destructor
        Mapa(size_t, size_t);
        virtual ~Mapa();

        ///Car�cteres est�ticos que definen el tipo de objeto
        ///que imprimir� en los tableros
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
        ///Funciones para obtener y asignar car�cteres a una determinada
        ///posici�n del tablero.
        virtual void setXY(size_t x,size_t y,char c)=0;
        virtual char getXY(size_t x, size_t y)=0;
};

#endif // MAPA_H
