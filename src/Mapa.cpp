#include "Mapa.h"
#include <iostream>
#include <allegro.h>

using namespace std;
/**
    Constructor de dos argumentos, con los que se define la dimensión
    del arreglo base para el tablero.
    Se crea un arreglo de carácteres.
*/
Mapa::Mapa(size_t filas, size_t columnas):filas(filas),columnas(columnas){
    mapa = new char*[filas];
        for (size_t i = 0; i < filas; i++) {
            mapa[i] = new char[columnas];
        }
}
/**
    Destructor del arreglo para el tablero.
*/
Mapa::~Mapa()
{
    for (size_t i = 0; i < filas; i++) {
        delete[] mapa[i];
    }
    delete[] mapa;

}

