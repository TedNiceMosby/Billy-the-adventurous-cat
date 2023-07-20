#ifndef MENU_H
#define MENU_H
#include <allegro.h>
/**
    Esta clase se encarga de presentar la pantalla de inicio del juego
    dando la indicación de presionar ENTER para iniciar el juego
*/
class Menu
{
    private:
        BITMAP* portada;
        int parpadeo{0};    ///Valor que ayuda a cambiar la posición de los BITMAP's
        bool salida=false;  ///Nos permite salir del bucle
    public:
        ///Constructor y destructor de la clase
        Menu();
        virtual ~Menu();

        ///Funciones para obtener y dar valores a las variables privadas.
        inline void setParpadeo(int parpadeo){this->parpadeo=parpadeo;}
        inline int getParpadeo(){return parpadeo;}
        inline void setSalida(bool salida){this->salida=salida;}
        inline bool getSalida(){return salida;}


        void comenzarPortada();
        void cargandoBitmap();

};

#endif // MENU_H
