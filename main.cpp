#include <iostream>
#include <allegro.h>
#include "Mapa.h"
#include "SubMapa1.h"
#include "Personaje.h"
#include "Juego.h"
#include "Menu.h"
using namespace std;

void instrucciones();

int main(){
    setlocale(LC_ALL,"");
    system("Color 9F");
    /**
        Inicializa la biblioteca Allegro
    */
    allegro_init();
    install_keyboard(); ///Instala el teclado

    /**
        Funciones graficas
    */
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 840, 600, 0, 0); //iniciar la pantalla de allegro
    /**
        Desarrollo del juego.
    */
    Juego Juego1; /// Creamos un objeto Juego
    instrucciones(); ///Mostramos las instrucciones en la aplicación de pantalla.

    ///Creamos un objeto Menú y llamamos a la ejecución de la portada.
    Menu portada;
    portada.cargandoBitmap();
    portada.comenzarPortada();

    ///Creamos los objetos que componen el juego.
    SubMapa1 Tablero;
    Gato Gato1;
    Enemigo Enemigo1;
    Enemigo Enemigo2;
    Gato1.creandoBitmap();
    Tablero.crearBitmap();
    Enemigo1.creandoBitmap();
    Enemigo2.creandoBitmap();
    /**
        Dinámica del juego
    */
    while(!key[KEY_ESC]){
        Gato1.setAntesPx(Gato1.getPx());
        Gato1.setAntesPy(Gato1.getPy());

        Tablero.limpiarPasto();
        Tablero.cargarPasto();

        Juego1.choque(Gato1, Enemigo1, Tablero);
        Juego1.choque(Gato1, Enemigo2, Tablero);

        Juego1.atajos(Gato1, Tablero);
        Juego1.atajos(Enemigo1, Tablero);
        Juego1.atajos(Enemigo2, Tablero);

        Juego1.dibujar_puntos(Tablero);
        Juego1.dibujar_puntosEnemigo(Tablero);
        Juego1.dibujarVidas(Tablero);
        Juego1.gameOver();

        Tablero.dibujarMapa();

        Juego1.ganarPuntos(Gato1,Tablero);
        Juego1.ganarPuntosE(Enemigo1, Tablero);
        Juego1.ganarPuntosE(Enemigo2, Tablero);

        Gato1.direcciones();
        Juego1.reconocerparedes_Gato(Gato1, Tablero);
        Gato1.mover();

        Enemigo1.direcciones();
        Juego1.reconocerparedes_Enemigo(Gato1,Enemigo1, Tablero);

        Enemigo2.direcciones();
        Juego1.reconocerparedes_Enemigo(Gato1,Enemigo2, Tablero);

        Juego1.dibujarGato(Gato1, Tablero);
        Juego1.dibujarEnemigo(Enemigo1,Tablero);
        Juego1.dibujarEnemigo(Enemigo2,Tablero);

        Tablero.mostrarMapa();
        rest(100);
    }

    return 0;
}

END_OF_MAIN();

void instrucciones(){
    cout<<"\n\t\t\tBilly, the adventurous cat"<<endl;
    cout<<"\nINTRUCCIONES:"<<endl;
    cout<<"\t\tLos malvados BlueJelly se han apoderado del bosque"<<endl;
    cout<<"\t\t 'Catbithia' y están devorando los panques sagrados."<<endl;
    cout<<"\n\t ¡Ayuda a Billy en esta aventura recolectando mayor número de panques!"<<endl;
    cout<<"\n\tRecuerda: Solo tienes tres vidas para evitar perderlo todo, no dejes que te atrapen"<<endl;
    cout<<"\n\tAcompáñalo en esta aventura..."<<endl;

    cout<<"\n\n\t1. Muévete con las teclas de dirección"<<endl;
    cout<<"\t2. Cuando entres a un portal deja presionada una tecla"<<endl;
    cout<<"\t   de dirección para salir de él"<<endl;
    cout<<"\t3. Para salir en cualquier momento del juego presiona la tecla ESC"<<endl;
}

