#include "Personaje.h"
#include <iostream>
#include <allegro.h>
using namespace std;
Personaje::Personaje(int px, int py):px(px), py(py)
{
    ///ctor de dos argumentos para personaje controlado por el usuario

}
Personaje::Personaje(int px, int py, int dir):px(px), py(py), dir(dir)
{
    ///ctor de tres argumentos para personaje automático
    ///*este tipo de personajes necesita que se le defina una dirección de inicio.
}
Personaje::~Personaje()
{
    ///dtor
}


