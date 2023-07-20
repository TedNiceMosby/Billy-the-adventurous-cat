#ifndef JUEGO_H
#define JUEGO_H
#include <allegro.h>
#include <random>
#include <iostream>
#include <chrono>
#include <sstream>
#include "SubMapa1.h"
#include "Gato.h"
#include "Enemigo.h"

using namespace std;
/**
    Clase donde se desarrolla la dinámica del juego.
*/
class Juego
{
    private:
        int puntos{0};///Contador de puntaje del usuario
        int puntosEnemigo{0};///Contador de puntaje enemigo
        int VIDAS{3};///Definimos el número de vidas para el usuario
    public:
        ///Constructor y destructor
        Juego();
        ~Juego();

        /**
            Métodos encargados de la dinámica del juego y la relación entre clases.
        */

        int motorAleatorios();

        void dibujarGato(Gato &gato, SubMapa1 &tablero);
        void dibujarEnemigo(Enemigo &enemigo, SubMapa1 &tablero);

        void ganarPuntos(Gato &gato, SubMapa1 &tablero);
        void ganarPuntosE(Enemigo &enemigo, SubMapa1 &tablero);

        void reconocerparedes_Enemigo(Gato &gato,Enemigo &enemigo, SubMapa1 &tablero);
        void reconocerparedes_Gato(Gato &gato, SubMapa1 &tablero);

        void choque(Gato &gato, Enemigo &enemigo, SubMapa1 &tablero);

        void atajos(Personaje &personaje,SubMapa1 &tablero);

        void gameOver();

        void dibujar_puntos(SubMapa1 &tablero);
        void dibujar_puntosEnemigo(SubMapa1 &tablero);

        void dibujarVidas(SubMapa1 &tablero);
        void perderVidas();
};

#endif // JUEGO_H
