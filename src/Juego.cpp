#include "Juego.h"
#include <iostream>
#include <allegro.h>
#include <cstdlib>
#include "SubMapa1.h"
#include "Personaje.h"
#include "Enemigo.h"
Juego::Juego()
{

}

Juego::~Juego()
{
    //dtor
}
///Métodos que dibujan a los personajes en el tablero.
void Juego::dibujarGato(Gato &gato, SubMapa1 &tablero){
    draw_sprite(tablero.getPasto(),gato.getCat(),gato.getPx(),gato.getPy());
}
void Juego::dibujarEnemigo(Enemigo &enemigo, SubMapa1 &tablero){
    draw_sprite(tablero.getPasto(),enemigo.getEnemy(),enemigo.getPx(),enemigo.getPy());
}
/**
    Cuenta el número de puntos que va ganando el usuario.
    Recorre todo el tablero y reconoce cuando el usuario pasa por los pasteles para
    después poner un espacio vacio simulando que recolectó los panques.
*/
void Juego::ganarPuntos(Gato &gato, SubMapa1 &tablero){
    for(int i=0; i<20; i++){
        for( int j=0; j<29 ; j++){
            if(tablero.getXY(i,j) == 'o'){
                draw_sprite(tablero.getPasto(),tablero.getPastel(),j*30 ,i*30);
                if((gato.getPy())/30== i && (gato.getPx())/30 == j){
                    tablero.setXY(i,j,' ');
                    puntos++;
                }
            }
        }
    }
}
/**
    Cuenta el número de puntos que va ganando el personaje automático.
*/
void Juego::ganarPuntosE(Enemigo &enemigo, SubMapa1 &tablero)
{
    for(int i=0; i<20; i++){
        for( int j=0; j<29 ; j++){
            if(tablero.getXY(i,j) == 'o'){
                draw_sprite(tablero.getPasto(),tablero.getPastel(),j*30 ,i*30);
                if((enemigo.getPy())/30== i && (enemigo.getPx())/30 == j){
                    tablero.setXY(i,j,' ');
                    puntosEnemigo ++;
                }
            }
        }
    }
}
/**
    Métodos encargados de revisar si el personaje está rodeado por algún
    obstáculo y bloquearle el paso.
*/
void Juego::reconocerparedes_Gato(Gato &gato, SubMapa1 &tablero)
{
        if(gato.getDir()==1) {
            if(tablero.getXY(gato.getPy()/30,(gato.getPx()+30)/30) != 'X'){
                gato.direcciones();
            }else gato.setDir(8);
        }
        else if(gato.getDir()==0){
            if(tablero.getXY(gato.getPy()/30,(gato.getPx()-30)/30) != 'X'){
                gato.direcciones();
            }else gato.setDir(8);
        }
        else if(gato.getDir()==2){
            if(tablero.getXY((gato.getPy()-30)/30,gato.getPx()/30) != 'X'){
               gato.direcciones();
            }else gato.setDir(8);
        }
        else if(gato.getDir()==3){
           if(tablero.getXY((gato.getPy()+30)/30,gato.getPx()/30) != 'X'){
               gato.direcciones();
            }else gato.setDir(8);
        }else{
            gato.getPx();
            gato.getPy();
        }
}
void Juego::reconocerparedes_Enemigo(Gato &gato,Enemigo &enemigo, SubMapa1 &tablero)
{
        choque(gato, enemigo,tablero);
        if (enemigo.getDir()==0){
            if(tablero.getXY(enemigo.getPy()/30,(enemigo.getPx()-30)/30) != 'X'){
                enemigo.setPx(enemigo.getPx()-30);
            }else enemigo.setDir(motorAleatorios()%4);
        }
        if (enemigo.getDir()==1){
            if(tablero.getXY(enemigo.getPy()/30,(enemigo.getPx()+30)/30) != 'X'){
                enemigo.setPx(enemigo.getPx()+30);
            }else enemigo.setDir(motorAleatorios()%4);
        }
        if (enemigo.getDir()==2){
            if(tablero.getXY((enemigo.getPy()-30)/30,enemigo.getPx()/30) != 'X'){
                enemigo.setPy(enemigo.getPy()-30);
            }else enemigo.setDir(motorAleatorios()%4);
        }
        if (enemigo.getDir()==3){
           if(tablero.getXY((enemigo.getPy()+30)/30,enemigo.getPx()/30) != 'X'){
                enemigo.setPy(enemigo.getPy()+30);
            }else enemigo.setDir(motorAleatorios()%4);
    }
    dibujarEnemigo(enemigo, tablero);
}
/**
        Método encargado de reconocer cuando el usuario muere a causa
        de chocar con un personaje enemigo.
*/
void Juego::choque(Gato &gato, Enemigo &enemigo, SubMapa1 &tablero)
{
    if ((gato.getPy()==enemigo.getPy() && gato.getPx()==enemigo.getPx()) ||(gato.getAntesPy()==enemigo.getPy() && gato.getAntesPx()==enemigo.getPx())){
        for(int i{0}; i<=5; i++){
            gato.limpiarPersonaje();
            tablero.limpiarPasto();
            tablero.dibujarMapa();
            blit(gato.getCatbmp(),gato.getCat(),i*33,132,0,0,33,33);
            dibujarGato(gato,tablero);
            tablero.mostrarMapa();
            rest(80);
        }
        gato.setPx(14*30);
        gato.setPy(10*30);
        perderVidas();
    }
}
/**
    Determina si un personaje entra a un portal del tablero y lo hace aparecer de forma aleatoria
    en uno de los otros portales
*/
void Juego::atajos(Personaje &personaje, SubMapa1 &tablero)
{
    int atajo=motorAleatorios()%8;

        if (tablero.getXY(personaje.getPy()/30,personaje.getPx()/30) == 'p'){
            switch (atajo){
                case 1:
                    personaje.setPx(1*30);
                    personaje.setPy(1*30);
                    break;
                case 2:
                    personaje.setPx(26*30);
                    personaje.setPy(1*30);
                    break;
                case 3:
                    personaje.setPx(14*30);
                    personaje.setPy(18*30);
                    break;
                case 4:
                    personaje.setPx(7*30);
                    personaje.setPy(12*30);
                    break;
                case 5:
                    personaje.setPx(20*30);
                    personaje.setPy(12*30);
                    break;
                case 6:
                    personaje.setPx(1*30);
                    personaje.setPy(18*30);
                    break;
                case 7:
                    personaje.setPx(26*30);
                    personaje.setPy(18*30);
                    break;

            };
        }

}
/**
    Método que retorna números aleatorios para que cuando un personaje
    entra a un portal este salga por uno distinto de forma aleatoria.
*/
int Juego::motorAleatorios()
{
    unsigned int semilla=chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motor(semilla);

    return motor();
}
/**
    Cuenta si los personajes han terminado de recoger los panques
    y determina si el usuario pierde o gana.
*/
void Juego::gameOver()
{
    if(puntosEnemigo + puntos == 110){
        if(puntosEnemigo>puntos){
            clear_to_color(screen,0x000000);
            textout_ex(screen,font,"HAS PERDIDO :(",370,300,0xFF0000,0x000000);
            rest(3000);
            exit(0);
        }else{

            clear_to_color(screen,0x000000);
            textout_ex(screen,font,"HAS GANADO!!",370,300,0xFF0000,0x000000);
            rest(3000);
            exit(0);
        }
    }
}
/**
    Métodos que muestran en la pantalla el puntaje de los personajes.
*/
void Juego::dibujar_puntos(SubMapa1 &tablero)
{
    std::stringstream ss; //objeto ss es como un cout para guardar texto
    ss<<"TU PUNTAJE: " <<puntos;
    std::string p=ss.str();
    char puntaje[20];
    strcpy(puntaje,p.c_str()); //

    textout_ex(tablero.getPasto(), font, puntaje, 370, 300, 0xFFFFFF, 0xFF5733);

}
void Juego::dibujar_puntosEnemigo(SubMapa1 &tablero)
{
    std::stringstream ss; //objeto ss es como un cout para guardar texto
    ss<<"PUNTAJE ENEMIGO: " <<puntosEnemigo;
    std::string p=ss.str();
    char puntajeEnemigo[20];
    strcpy(puntajeEnemigo,p.c_str()); //

    textout_ex(tablero.getPasto(), font, puntajeEnemigo, 350, 320, 0xFFFFFF, 0xFF5733);

}

/**
    Método que muestra las vidas del personaje en la pantalla.
*/
void Juego::dibujarVidas(SubMapa1 &tablero)
{
    for(int i=0; i<VIDAS; i++){
        draw_sprite(tablero.getPasto(),tablero.getCorazon(),i*45+360,340);
    }
}
/**
    Método que muestra en pantalla cuando se ha perdido una vida
    y si ha perdido todas acaba el juego.
*/
void Juego::perderVidas()
{
    VIDAS--;
    if(VIDAS >0){
        clear_to_color(screen,0x000000);
        textout_ex(screen,font,"Has perdido una vida",350,300,0xFFFFFF,0x000000);
        rest(1000);
    } else{
        clear_to_color(screen,0x000000);
        textout_ex(screen,font,"Has perdido :(",350,300,0xFF2D00,0x000000);
        rest(3000);
        exit(0);
    }
}

