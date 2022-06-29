#include <iostream>
#include <string>
#include <conio.h>
#include <cctype>
#include <stdio.h>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "bibliotecaOink.h"

///////////////// INICIO FUNCIONES EXCLUSIVAMENTE JUGADA

                using namespace std;

 /// REALIZA LA JUGADA C DOS DADOS. RETORNA TRUE SI SE DEBE CAMBIAR A TRES

 bool jugarDosDados(int numeroRonda, int puntajeJugadorUno[ ],int tamPrimero, int puntajeJugadorDos[ ],int tamSegundo, string primerJugador, string segundoJugador) {

            bool turnoJugadorDos=false;
            bool oink = false, terceraOp = false, primerOp = false, cerdoAlBarro = false;
            bool  tresDados;
            int puntaje = 0, primerDado, segundoDado, puntajeDos =0;
            int cantidadDeLanzamientos = 0,  puntajeDeLaRonda = 0;


                    cantidadDeLanzamientos=0;
                    puntajeDeLaRonda=0;

                    rlutil::cls();
                cout<<"------------------------------------------------------------------------"<<endl;
                cout<<" CERDO:              "<<primerJugador<<"                     "<<segundoJugador<<endl;
                cout<<"TRUFAS TOTALES:            "<<puntajeJugadorUno[0]<<"                 "<<puntajeJugadorDos[0]<<endl;
            do {

                rlutil::locate(3,6);
                cout<<" CERDITO     "<<primerJugador<<endl;
                cout<<"+--------------------------+"<<endl;
                cout<<"| RONDAS # "<<numeroRonda<<"               |"<<endl;
                cout<<"| TRUFAS RONDA: "<<puntajeDeLaRonda<<"          |"<<endl;
                cout<<"| LANZAMIENTOS: "<<cantidadDeLanzamientos<<"          |"<<endl;
                cout<<"+--------------------------+"<<endl;
                cout<<"   LANZAMIENTO #"<<cantidadDeLanzamientos+1<<endl;

                    primerDado=tirarDado();
                    cout<<"PUNTAJE DADO 1: "<<primerDado<<endl;
                    mostrarDados(primerDado);
                    segundoDado=tirarDado();
                    cout<<"PUNTAJE DADO 2: "<<segundoDado<<endl;
                    mostrarDados(segundoDado);

                    primerOp=realizarPrimerOportunidad(primerDado, segundoDado);
                    if(primerOp){
                        puntaje=primerDado+segundoDado;
                        turnoJugadorDos=preguntarLanzada();
                        cout<<"TRUFAS TOTALES: "<<puntaje;
                        puntajeDeLaRonda+=puntaje;
                        puntajeJugadorUno[0]+=puntajeDeLaRonda;
                    }

                    oink=realizarUltimaOportunidad(primerDado, segundoDado);
                    if(oink){
                        puntajeDos=(primerDado+segundoDado)*2;
                        cout<<"TRUFAS ACUMULADAS: "<<puntajeDos<<endl;
                        cout<<"UST HIZO UN OINK: "<<endl;
                        cout<<"TRUFAS TOTALES: "<<puntajeDos;
                        puntajeDeLaRonda+=puntajeDos;
                        puntajeJugadorUno[0]+=puntajeDeLaRonda;
                        puntajeJugadorUno[1]++;
                        rlutil::anykey();
                    }

                terceraOp=realizarTerceraComparacion(primerDado,segundoDado);
                if(terceraOp){
                    cout<<"¡UPS! PERDISTE LAS TRUFAS DE ESTA RONDA." <<endl<<" MEJOR SUERTE LA PROXIMA. "<<endl;
                    cout<<"TRUFAS TOTALES: 0"<<endl;
                    puntajeDeLaRonda=0;
                    puntajeJugadorUno[0]= puntajeJugadorUno[0]-puntajeDeLaRonda;
                    turnoJugadorDos=true;
                    rlutil::anykey();
                }


                cerdoAlBarro=realizarSegundaComparacion(primerDado,segundoDado);
                if(cerdoAlBarro){
                    cout<<"CERDO AL BARRO"<<endl;
                    cout<<"PERDISTE TU TURNO, "<<primerJugador<<" MEJOR SUERTE LA PROXIMA!"<<endl;
                    cout<<"PERDISTE TUS TRUFAS!!!"<<endl;
                    puntajeJugadorUno[0]=0;
                    rlutil::anykey();
                    tresDados=true;
                    turnoJugadorDos=true; // CAMBIA A TRUE Y SE EMPIEZA A JUGAR CON TRES DADOS
                }

              } while(!turnoJugadorDos && !tresDados);

            do{

                rlutil::locate(3,6);
                cout<<" CERDITO:    "<<segundoJugador<<endl;
                cout<<"+--------------------------+"<<endl;
                cout<<"| RONDAS # "<<numeroRonda<<"               |"<<endl;
                cout<<"| TRUFAS RONDA: "<<puntajeDeLaRonda<<"          |"<<endl;
                cout<<"| LANZAMIENTOS: "<<cantidadDeLanzamientos<<"          |"<<endl;
                cout<<"+--------------------------+"<<endl;
                cout<<"   LANZAMIENTO #"<<cantidadDeLanzamientos+1<<endl;

                    primerDado=tirarDado();
                    cout<<"PUNTAJE DADO 1: "<<primerDado<<endl;
                    mostrarDados(primerDado);
                    segundoDado=tirarDado();
                    cout<<"PUNTAJE DADO 2: "<<segundoDado<<endl;
                    mostrarDados(segundoDado);

                if (cantidadDeLanzamientos > puntajeJugadorDos[2]) {
                    puntajeJugadorDos[2]+=cantidadDeLanzamientos;
                }


                    primerOp=realizarPrimerOportunidad(primerDado, segundoDado);
                    if(primerOp){
                        puntaje=primerDado+segundoDado;
                        turnoJugadorDos=preguntarLanzada();
                        cout<<"TRUFAS TOTALES: "<<puntaje;
                        puntajeDeLaRonda+=puntaje;
                        puntajeJugadorDos[0]+=puntajeDeLaRonda;
                    }

                    oink=realizarUltimaOportunidad(primerDado, segundoDado);
                    if(oink){
                        puntajeDos=(primerDado+segundoDado)*2;
                        cout<<"TRUFAS ACUMULADAS: "<<puntajeDos<<endl;
                        cout<<"UST HIZO UN OINK: "<<endl;
                        cout<<"TRUFAS TOTALES: "<<puntajeDos;
                        puntajeDeLaRonda+=puntajeDos;
                        puntajeJugadorDos[0]+=puntajeDeLaRonda;
                        puntajeJugadorDos[1]++;
                        rlutil::anykey();
                    }

                terceraOp=realizarTerceraComparacion(primerDado,segundoDado);
                if(terceraOp){
                    cout<<"¡UPS! PERDISTE LAS TRUFAS DE ESTA RONDA." <<endl<<" MEJOR SUERTE LA PROXIMA. "<<endl;
                    cout<<"TRUFAS TOTALES: 0"<<endl;
                    puntajeDeLaRonda=0;
                    puntajeJugadorDos[0]=puntajeJugadorDos[0]-puntajeDeLaRonda;
                    turnoJugadorDos=false;
                    rlutil::anykey();
                }


                cerdoAlBarro=realizarSegundaComparacion(primerDado,segundoDado);
                if(cerdoAlBarro){
                    cout<<"CERDO AL BARRO"<<endl;
                    cout<<"PERDISTE TU TURNO, "<<segundoJugador<<" MEJOR SUERTE LA PROXIMA!"<<endl;
                    cout<<"PERDISTE TUS TRUFAS!!!"<<endl;
                    puntajeJugadorDos[0]=0;
                    rlutil::anykey();
                    tresDados=true;
                    turnoJugadorDos=false; // CAMBIA A TRUE Y SE EMPIEZA A JUGAR CON TRES DADOS
                }

            }while(!turnoJugadorDos && !tresDados);

            return tresDados;
    }

    /// REALIZA LA JUGADA CON TRES DADOS
    void jugarTresDados(int numeroRonda, int puntajeJugadorUno[ ],int tamPrimero, int puntajeJugadorDos[ ],int tamSegundo, string jugadorUno, string jugadorDos) {

            bool turnoJugadorDos=false;
            bool oink = false, terceraOp = false, primerOp = false, cerdoAlBarro = false;
            int puntaje = 0, primerDado, segundoDado, puntajeDos =0, tercerDado;
            int cantidadDeLanzamientos = 0,  puntajeDeLaRonda = 0;

                    cantidadDeLanzamientos = 0;
                    puntajeDeLaRonda = 0;
            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<" CERDO:              "<<jugadorUno<<"                     "<<jugadorDos<<endl;
            cout<<"TRUFAS TOTALES:            "<<puntajeJugadorUno[0]<<"                 "<<puntajeJugadorDos[0]<<endl;

            do{
                    rlutil::locate(3,6);
                    cout<<" CERDITO   "<<jugadorUno<<endl;
                    cout<<"+-------------------------+"<<endl;
                    cout<<"| RONDAS # "<<numeroRonda<<"              |"<<endl;
                    cout<<"| TRUFAS RONDA: "<<puntajeDeLaRonda<<"         |"<<endl;
                    cout<<"| LANZAMIENTOS: "<<cantidadDeLanzamientos<<"         |"<<endl;
                    cout<<"+-------------------------+"<<endl;
                    cout<<"   LANZAMIENTO #"<<cantidadDeLanzamientos+1<<endl;

                        primerDado=tirarDado();
                        cout<<"PUNTAJE DADO 1: "<<primerDado<<endl;
                        cout<<endl<<endl;
                        mostrarDados(primerDado);
                        segundoDado=tirarDado();
                        cout<<"PUNTAJE DADO 2: "<<segundoDado<<endl;
                        cout<<endl<<endl;
                        mostrarDados(segundoDado);
                        tercerDado=tirarDado();
                        cout<<"PUNTAJE DADO 3: "<<tercerDado<<endl;
                        cout<<endl<<endl;
                        mostrarDados(tercerDado);

                        primerOp=realizarPrimerOportunidadTresDados(primerDado,segundoDado,tercerDado);
                        if(primerOp){
                            puntaje=primerDado+segundoDado+tercerDado;
                            turnoJugadorDos=preguntarLanzada();
                            cout<<"TRUFAS TOTALES: "<<puntaje;
                            puntajeDeLaRonda+=puntaje;
                            puntajeJugadorUno[0]+=puntajeDeLaRonda;
                        }

                        oink=realizarUltimaOportunidadTresDados(primerDado, segundoDado,tercerDado);
                        if(oink){
                            puntajeDos=(primerDado+segundoDado+tercerDado)*2;
                            cout<<"TRUFAS ACUMULADAS: "<<puntajeDos<<endl;
                            cout<<"UST HIZO UN OINK: "<<endl;
                            cout<<"TRUFAS TOTALES: "<<puntajeDos;
                            puntajeDeLaRonda+=puntajeDos;
                            puntajeJugadorUno[0]+=puntajeDeLaRonda;
                            puntajeJugadorUno[1]++;
                            rlutil::anykey();
                        }

                    terceraOp=realizarTerceraComparacionTresDados(primerDado, segundoDado,tercerDado);
                    if(terceraOp){
                        cout<<"¡UPS! PERDISTE LAS TRUFAS DE ESTA RONDA." <<endl<<" MEJOR SUERTE LA PROXIMA. "<<endl;
                        cout<<"TRUFAS TOTALES: 0"<<endl;
                        puntajeJugadorUno[0]=puntajeJugadorUno[0]-puntajeDeLaRonda;
                        turnoJugadorDos=true;
                        rlutil::anykey();
                    }


                    cerdoAlBarro=realizarSegundaComparacionTresDados(primerDado, segundoDado,tercerDado);
                    if(cerdoAlBarro){
                        cout<<"CERDO AL BARRO"<<endl;
                        turnoJugadorDos=true;
                        cout<<"PERDISTE TU TURNO, "<<jugadorUno<<" MEJOR SUERTE LA PROXIMA!"<<endl;
                        cout<<"Tus trufas pasan al siguiente jugador: (Total hasta el momento: "<<puntajeJugadorUno[0]<<")"<<endl;
                        puntajeJugadorDos[0]+=puntajeJugadorUno[0];
                        puntajeJugadorUno[0]=0;
                        rlutil::anykey();
                    }

                    rlutil::cls();
                    cantidadDeLanzamientos++;
                    if (cantidadDeLanzamientos > puntajeJugadorUno[2]) {
                        puntajeJugadorUno[2]=cantidadDeLanzamientos;
                    }
                } while(!turnoJugadorDos); // DO


            do{

                    rlutil::locate(3,6);
                    cout<<" CERDITO "<<jugadorDos<<endl;
                    cout<<"+-------------------------+"<<endl;
                    cout<<"| RONDAS # "<<numeroRonda<<"              |"<<endl;
                    cout<<"| TRUFAS RONDA: "<<puntajeDeLaRonda<<"         |"<<endl;
                    cout<<"| LANZAMIENTOS: "<<cantidadDeLanzamientos<<"         |"<<endl;
                    cout<<"+-------------------------+"<<endl;
                    cout<<"   LANZAMIENTO #"<<cantidadDeLanzamientos+1<<endl;

                        primerDado=tirarDado();
                        cout<<"PUNTAJE DADO 1: "<<primerDado<<endl;
                        cout<<endl<<endl;
                        mostrarDados(primerDado);
                        segundoDado=tirarDado();
                        cout<<"PUNTAJE DADO 2: "<<segundoDado<<endl;
                        cout<<endl<<endl;
                        mostrarDados(segundoDado);
                        tercerDado=tirarDado();
                        cout<<"PUNTAJE DADO 3: "<<tercerDado<<endl;
                        cout<<endl<<endl;
                        mostrarDados(tercerDado);

                        primerOp=realizarPrimerOportunidadTresDados(primerDado,segundoDado,tercerDado);
                        if(primerOp){
                            puntaje=primerDado+segundoDado+tercerDado;
                            turnoJugadorDos=preguntarLanzada();
                            cout<<"TRUFAS TOTALES: "<<puntaje;
                            puntajeDeLaRonda+=puntaje;
                            puntajeJugadorDos[0]+=puntajeDeLaRonda;
                        }

                        oink=realizarUltimaOportunidadTresDados(primerDado, segundoDado,tercerDado);
                        if(oink){
                            puntajeDos=(primerDado+segundoDado+tercerDado)*2;
                            cout<<"TRUFAS ACUMULADAS: "<<puntajeDos<<endl;
                            cout<<"UST HIZO UN OINK: "<<endl;
                            cout<<"TRUFAS TOTALES: "<<puntajeDos;
                            puntajeDeLaRonda+=puntajeDos;
                            puntajeJugadorDos[0]+=puntajeDeLaRonda;
                            puntajeJugadorDos[1]++;
                            rlutil::anykey();
                        }

                    terceraOp=realizarTerceraComparacionTresDados(primerDado, segundoDado,tercerDado);
                    if(terceraOp){
                        cout<<"¡UPS! PERDISTE LAS TRUFAS DE ESTA RONDA." <<endl<<" MEJOR SUERTE LA PROXIMA. "<<endl;
                        cout<<"TRUFAS TOTALES: 0"<<endl;
                        puntajeJugadorDos[0]=puntajeJugadorDos[0]-puntajeDeLaRonda;
                        turnoJugadorDos=false;
                        rlutil::anykey();
                    }


                    cerdoAlBarro=realizarSegundaComparacionTresDados(primerDado, segundoDado,tercerDado);
                    if(cerdoAlBarro){
                        cout<<"CERDO AL BARRO"<<endl;
                        turnoJugadorDos=false;
                        cout<<"PERDISTE TU TURNO, "<<jugadorDos<<" MEJOR SUERTE LA PROXIMA!"<<endl;
                        cout<<"Tus trufas pasan al siguiente jugador: (Total hasta el momento: "<<puntajeJugadorDos[0]<<")"<<endl;
                        puntajeJugadorUno[0]+=puntajeJugadorDos[0];
                        puntajeJugadorDos[0]=0;
                        rlutil::anykey();
                    }

                    rlutil::cls();
                    cantidadDeLanzamientos++;
                    if (cantidadDeLanzamientos > puntajeJugadorUno[2]) {
                        puntajeJugadorDos[2]=cantidadDeLanzamientos;
                    }
                } while(turnoJugadorDos);
    }
