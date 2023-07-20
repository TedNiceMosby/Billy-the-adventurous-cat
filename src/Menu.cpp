#include "Menu.h"
#include <allegro.h>
Menu::Menu()
{
    //ctor
}
Menu::~Menu()
{
    //dtor
}
/**
    Buble infinito que como principal función tiene mostrar la pantalla de
    inicio mostrando un parpadeo debido al cambio de BITMAP's en un determinado
    tiempo. Este termina hasta que el usuario presione ENTER
*/
void Menu::comenzarPortada()
{

    while(!salida){
        if(parpadeo<25){
                blit(portada,screen,0,0,0,0,840,600);
        }else {
            blit(portada,screen,840,0,0,0,840,600);
        }
         if(key[KEY_ENTER]){
            salida=true;
         }
        rest(5);
         if(++parpadeo==50) {
                parpadeo=0;
         }
    }
    clear_to_color(screen,0x000000);

}

void Menu::cargandoBitmap()
{
    portada=load_bitmap("Portada.bmp",NULL);
}
