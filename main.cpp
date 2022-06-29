#include <string>
#include <iostream>
#include <conio.h>
#include <cctype>
#include <stdio.h>
#include <locale.h> // para que se vea en español
#include <cstdlib>
#include <ctime> // PARA EL RELOJ DEL DADO
#include "rlutil.h"
#include "bibliotecaOink.h"
#include "bibliotecaJugadas.h"
#include "cerditosGraficos.h"


using namespace std;

    int main(){

        const int TOP = 3;
        int jugadas;
        string cerdoGanador, ganador, vectorVictoriasNombre[TOP] = {"SIN DATOS", "SIN DATOS", "SIN DATOS"};
        int puntajeGanador, puntaje, vectorVictoriasPuntaje[TOP] = { };
        char respuestaFinal;
        bool salir=false;



            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::setColor(rlutil::LIGHTMAGENTA);
            rlutil::cls();
            srand (time(NULL));


            jugadas=0;
     do{
        rlutil::cls();
        switch(mostrarMenu()){
            case 1:
            jugarCerdo(ganador,puntaje);
            rlutil::cls();
            cerdoGanador=ganador;
            puntajeGanador=puntaje;
            vectorVictoriasPuntaje[jugadas]=puntajeGanador;
            vectorVictoriasNombre[jugadas]=cerdoGanador;
            jugadas++;
            if(jugadas >= 3){
                jugadas=0;
            }

                break;

            case 2:
            rlutil::cls();
            mostrarEstadisticas(vectorVictoriasPuntaje,TOP,vectorVictoriasNombre,TOP);
            break;
            case 3:
                rlutil::cls();
                mostrarCerditos();
                rlutil::cls();
                break;

            case 0:
                cout<<endl<<endl;
                rlutil::setColor(rlutil::LIGHTRED);
                cout<<"¿Está seguro que desea salir del juego? S/N"<<endl;
                cout<<" RTA: ";
                cin>>respuestaFinal;
                cin.ignore();
                if(toupper (respuestaFinal) == 'S'){
                   salir=true;
                }
                else{
                    if(toupper(respuestaFinal) == 'N'){
                        salir=false;
                    }
                }
                break;

            default:
                rlutil::setColor(rlutil::LIGHTRED);
                rlutil::locate(5,15);
                cout<<"OPCION INCORRECTA. VUELVA A INTENTAR. "<<endl;
                rlutil::anykey();
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                break;
            } // ESTRUCTURA PRINCIPAL DEL MENU
    } while(!salir);

    cout<<"¡GRACIAS POR JUGAR!"<<endl;
    cout<<endl<<endl;


    return 0;
}

