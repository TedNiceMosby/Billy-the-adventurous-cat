#include "SubMapa1.h"
#include "Mapa.h"
#include <iostream>
#include <allegro.h>

/**
    Costructor con el que inicializamos las dimensiones del arreglo para el tablero y
    definimos las posiciones donde se colocaran los objetos por medio de su carácter.
*/
SubMapa1::SubMapa1():Mapa{20,29}
{
   for (size_t j = 0; j <20; j++) {
            mapa[j][0]=Mapa::obstaculo;
            mapa[j][27]=Mapa::obstaculo;
    }for(size_t i = 5; i <23; i++) {
            mapa[16][i]=Mapa::obstaculo;
    } for(size_t i = 10; i <18; i++) {
            mapa[4][i]=Mapa::obstaculo;
    } for(size_t i = 2; i <10; i++) {
            mapa[13][i]=Mapa::obstaculo;
    }for(size_t i = 17; i <26; i++) {
            mapa[13][i]=Mapa::obstaculo;
    }for(size_t i = 2; i <5; i++) {
            mapa[3][i]=Mapa::obstaculo;
    } for(size_t i = 23; i <26; i++) {
            mapa[3][i]=Mapa::obstaculo;
    } for(size_t i = 2; i <4; i++) {
            mapa[7][i]=Mapa::obstaculo;
    } for(size_t i = 24; i <26; i++) {
            mapa[7][i]=Mapa::obstaculo;
    }for(size_t i = 25; i <27; i++) {
            mapa[5][i]=Mapa::obstaculo;
    }for (size_t j = 1; j <3; j++) {
            mapa[j][2]=Mapa::obstaculo;
            mapa[j][25]=Mapa::obstaculo;
            mapa[5][j]=Mapa::obstaculo;
    }for (size_t j = 2; j <8; j++) {
            mapa[j][6]=Mapa::obstaculo;
            mapa[j][21]=Mapa::obstaculo;
    } for (size_t j = 6; j <12; j++) {
            mapa[j][10]=Mapa::obstaculo;
            mapa[j][17]=Mapa::obstaculo;
    } for (size_t j = 5; j <12; j++) {
            mapa[j][4]=Mapa::obstaculo;
            mapa[j][23]=Mapa::obstaculo;
    } for (size_t j = 9; j <13; j++) {
            mapa[j][2]=Mapa::obstaculo;
            mapa[j][25]=Mapa::obstaculo;
    } for (size_t j = 15; j <19; j++) {
            mapa[j][2]=Mapa::obstaculo;
            mapa[j][25]=Mapa::obstaculo;
    } for (size_t i = 0; i <27; i++) {
            mapa[19][i]=Mapa::obstaculo;
            mapa[0][i]=Mapa::obstaculo;
    }

    for (size_t j = 6; j <18; j++) {
            mapa[j][1]=Mapa::comida;
            mapa[j][26]=Mapa::comida;
    }for (size_t j = 2; j <13; j++) {
            mapa[j][8]=Mapa::comida;
            mapa[j][19]=Mapa::comida;
    }for (size_t i = 2; i <26; i++) {
            mapa[14][i]=Mapa::comida;
    }for(size_t i = 4; i <24; i++) {
            mapa[1][i]=Mapa::comida;
            mapa[17][i]=Mapa::comida;
    }for (size_t j = 7; j <9; j++) {
            mapa[j][13]=Mapa::cristal;
            mapa[j][14]=Mapa::cristal;
    }
            mapa[1][1]=Mapa::portal;
            mapa[1][26]=Mapa::portal;
            mapa[18][14]=Mapa::portal;
            mapa[12][7]=Mapa::portal;
            mapa[12][20]=Mapa::portal;
            mapa[18][1]=Mapa::portal;
            mapa[18][26]=Mapa::portal;
}

SubMapa1::~SubMapa1()
{
    //dtor
}
/**
    Métodos sobrescritos de la clase base con los que se asigna y se
    obtiene los valores de tipo char de determinada posición en el tablero.
*/
void SubMapa1::setXY(size_t x, size_t y, char c)
{
        mapa[x][y]=c;
}

char SubMapa1::getXY(size_t x, size_t y)
{
    return mapa[x][y];
}

/**
    Hacemos un recorrido por todo el arreglo principal del tablero
    y cuando se reconocen los objetos del tablero los dibuja en la pantalla.
*/
void SubMapa1::dibujarMapa()
{
    for(unsigned int i=0; i<20; i++){
        for(unsigned int j=0; j<29 ; j++){
            if(mapa[i][j] == 'X'){
                draw_sprite(pasto, roca , j*30 , i*30);
            } else  if(mapa[i][j] == 'o'){
                draw_sprite(pasto, pastel , j*30 , i*30);
            } else if(mapa[i][j] == 'c'){
                draw_sprite(pasto, cristal , j*30 , i*30);
            } else if(mapa[i][j] == 'm'){
                draw_sprite(pasto, moneda , j*30 , i*30);
            }else if(mapa[i][j] == 'p'){
                draw_sprite(pasto, portal , j*30 , i*30);
            }
        }
    }
}
/**
    Se reserva espacio de memoria para el bitmap de fondo y se copia a la pantalla.
*/
void SubMapa1::mostrarMapa()
{
    blit(pasto, screen, 0,0,0,0,840,600);

}
/**
    Función que carga todos los bitmap's al proyecto.
*/
void SubMapa1::crearBitmap()
{
    pasto=load_bitmap("Pastito.bmp",NULL);
    roca = load_bitmap("roca.bmp", NULL);
    pastel = load_bitmap("pastel.bmp", NULL);
    cristal = load_bitmap("Cristal1.bmp", NULL);
    moneda = load_bitmap("moneda.bmp", NULL);
    portal = load_bitmap("portal.bmp", NULL);
    corazon = load_bitmap("corazon.bmp",NULL);

}
///Limpia el BITMAP de fondo
void SubMapa1::limpiarPasto()
{
   clear(pasto);
}
///Carga el mapa de bits de fondo al proyecto.
void SubMapa1::cargarPasto()
{
    pasto=load_bitmap("Pastito.bmp",NULL);
}


