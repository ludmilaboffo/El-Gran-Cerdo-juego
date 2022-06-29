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
#include "cerditosGraficos.h"
///////////////// INICIO FUNCIONES

                using namespace std;


     /// REALIZA LA JUGADA C DOS DADOS. RETORNA TRUE SI SE DEBE CAMBIAR A TRES

     bool jugarDosDados(int numeroRonda, int puntajePrimerJugador[ ],int tamPrimero, int puntajeSegundoJugador[ ],int tamSegundo, string primerJugador, string segundoJugador) {

                bool turnoJugadorDos=false;
                bool oink = false, terceraOp = false, primerOp = false, cerdoAlBarro = false;
                bool  tresDados=false;
                int puntaje = 0, primerDado, segundoDado, puntajeDos =0;
                int cantidadDeLanzamientos = 0,  puntajeDeLaRonda = 0;
                int contadorPrimoUno=0, contadorPrimoDos=0;
                bool banderaPrimo=false, banderaPrimerLanzamiento=false, CarasPrimo=false;

                do {

                    rlutil::locate(3,6);
                    cout<<"------------------------------------------------------------------------"<<endl;
                    cout<<" CERDOS:              "<<primerJugador<<"                     "<<segundoJugador<<endl;
                    cout<<" TRUFAS TOTALES:        "<<puntajePrimerJugador[0]<<"                      "<<puntajeSegundoJugador[0]<<endl;
                    cout<<endl<<endl;
                    hacerBarra();
                    cout<<"  CANTIDAD DE DADOS: 2"<<endl;
                    hacerBarra();
                    cout<<"  CERDITO   "<<primerJugador<<endl;
                    hacerBarra();
                    cout<<"  RONDAS # "<<numeroRonda<<endl;
                    hacerBarra();
                    cout<<"  TRUFAS RONDA: "<<puntajeDeLaRonda<<endl;
                    hacerBarra();
                    cout<<"  LANZAMIENTOS: "<<cantidadDeLanzamientos<<endl;
                    hacerBarra();
                    cout<<"             LANZAMIENTO #"<<cantidadDeLanzamientos+1<<endl;


                        cout<<endl<<endl;
                        primerDado=tirarDado();
                        cout<<"PUNTAJE DADO 1: "<<primerDado<<endl;
                        mostrarDados(primerDado);
                        cout<<endl<<endl;
                        segundoDado=tirarDado();
                        cout<<"PUNTAJE DADO 2: "<<segundoDado<<endl;
                        mostrarDados(segundoDado);


                        cantidadDeLanzamientos++;
                        if (cantidadDeLanzamientos > puntajePrimerJugador[2]) {
                            puntajePrimerJugador[2]=cantidadDeLanzamientos;
                        }


                             for(int i=1; i<=primerDado; i++){
                                if(primerDado%2!=0){
                                    contadorPrimoUno++;
                                }
                             }


                             for(int i=1; i<=segundoDado; i++){
                                if(segundoDado%2!=0){
                                    contadorPrimoDos++;
                                }
                             }

                             if((contadorPrimoUno==2) && (contadorPrimoDos==2)){
                                CarasPrimo=true;
                             }

                             if(!banderaPrimerLanzamiento){
                                if(!banderaPrimo && CarasPrimo==true){
                                    puntajePrimerJugador[3]=5;
                                    banderaPrimo=true;
                                    banderaPrimerLanzamiento=true;
                                }
                                else{
                                    if(banderaPrimo){
                                        puntajePrimerJugador[3]=0;
                                        banderaPrimerLanzamiento=false;
                                    }
                                }
                             } //FIN IF


                        primerOp=realizarPrimerOportunidad(primerDado, segundoDado);
                        if(primerOp){
                            puntaje=primerDado+segundoDado;
                            cout<<"TRUFAS TOTALES: "<<puntaje<<endl;
                            turnoJugadorDos=preguntarLanzada();
                            puntajeDeLaRonda+=puntaje;
                            puntajePrimerJugador[0]+=puntaje;
                        }

                        oink=realizarUltimaOportunidad(primerDado, segundoDado);
                        if(oink){
                            puntajeDos=(primerDado+segundoDado)*2;
                            cout<<"TRUFAS ACUMULADAS EN LA LANZADA: "<<puntajeDos<<endl;
                            cout<<"HICISTE UN OINK!!!"<<endl;
                            cout<<"TRUFAS TOTALES: "<<puntajeDos;
                            puntajeDeLaRonda+=puntajeDos;
                            puntajePrimerJugador[0]+=puntajeDos;
                            puntajePrimerJugador[1]++;
                            rlutil::anykey();
                        }

                    terceraOp=realizarTerceraComparacion(primerDado,segundoDado);
                    if(terceraOp){
                        cout<<"¡UPS! PERDISTE LAS TRUFAS DE ESTA RONDA."<<endl;
                        cout<<" MEJOR SUERTE LA PROXIMA. "<<endl;
                        cout<<"TRUFAS TOTALES: 0"<<endl;

                            puntajePrimerJugador[0]=puntajePrimerJugador[0]-puntajeDeLaRonda;
                            puntajeDeLaRonda=0;

                        turnoJugadorDos=true;
                        rlutil::anykey();
                    }


                    cerdoAlBarro=realizarSegundaComparacion(primerDado,segundoDado);
                    if(cerdoAlBarro){
                        cout<<"CERDO AL BARRO"<<endl;
                        cout<<"PERDISTE TU TURNO, "<<primerJugador<<" MEJOR SUERTE LA PROXIMA!"<<endl;
                        cout<<"TE QUEDAS SIN TRUFAS. TOTAL: 0"<<endl;
                        puntajePrimerJugador[0]=0;
                        rlutil::anykey();
                        tresDados=true;
                        turnoJugadorDos=true; // CAMBIA A TRUE Y SE EMPIEZA A JUGAR CON TRES DADOS
                    }

                    rlutil::cls();

                  } while(!turnoJugadorDos && !tresDados);

                    if(puntajePrimerJugador[0]>10 && puntajeSegundoJugador[0]>10){
                        tresDados=true;
                    }

                    CarasPrimo=false;
                    puntajeDeLaRonda = 0;
                    cantidadDeLanzamientos = 0;
                    contadorPrimoUno=0;
                    contadorPrimoDos=0;

            while(turnoJugadorDos && !tresDados)
            {

                    rlutil::locate(3,6);
                    cout<<"------------------------------------------------------------------------"<<endl;
                    cout<<" CERDOS:              "<<primerJugador<<"                      "<<segundoJugador<<endl;
                    cout<<" TRUFAS TOTALES:        "<<puntajePrimerJugador[0]<<"                       "<<puntajeSegundoJugador[0]<<endl;
                    cout<<endl<<endl;
                    hacerBarra();
                    cout<<" CERDITO:    "<<segundoJugador<<endl;
                    hacerBarra();
                    cout<<" CANTIDAD DE DADOS: 2"<<endl;
                    hacerBarra();
                    cout<<" RONDAS # "<<numeroRonda<<endl;
                    hacerBarra();
                    cout<<" TRUFAS RONDA: "<<puntajeDeLaRonda<<endl;
                    hacerBarra();
                    cout<<" LANZAMIENTOS: "<<cantidadDeLanzamientos<<endl;
                    hacerBarra();
                    cout<<"             LANZAMIENTO #"<<cantidadDeLanzamientos+1<<endl;
                    cout<<endl<<endl;

                        primerDado=tirarDado();
                        cout<<"PUNTAJE DADO 1: "<<primerDado<<endl;
                        mostrarDados(primerDado);
                        segundoDado=tirarDado();
                        cout<<endl<<endl;
                        cout<<"PUNTAJE DADO 2: "<<segundoDado<<endl;
                        mostrarDados(segundoDado);


                             for(int i = 1; i<=primerDado; i++){
                                if(primerDado%i==0){
                                    contadorPrimoUno++;
                                }
                             }


                             for(int i= 1; i<=segundoDado; i++){
                                if(segundoDado%i==0){
                                    contadorPrimoDos++;
                                }
                             }

                             if((contadorPrimoUno==2) && (contadorPrimoDos==2)){
                                CarasPrimo=true;
                             }

                             if(!banderaPrimerLanzamiento){
                                if(!banderaPrimo && CarasPrimo==true){
                                    puntajeSegundoJugador[3]=5;
                                    banderaPrimo=true;
                                    banderaPrimerLanzamiento=true;
                                }
                                else{
                                    if(banderaPrimo){
                                        puntajeSegundoJugador[3]=0;
                                        banderaPrimerLanzamiento=false;
                                    }
                                }
                             } //FIN IF



                            cantidadDeLanzamientos++;
                            if (cantidadDeLanzamientos > puntajeSegundoJugador[2]) {
                                puntajeSegundoJugador[2]=cantidadDeLanzamientos;
                            }



                        primerOp=realizarPrimerOportunidad(primerDado, segundoDado);
                        if(primerOp){
                            puntaje=primerDado+segundoDado;
                            cout<<"TRUFAS TOTALES: "<<puntaje<<endl;
                            turnoJugadorDos=preguntarLanzadaDos();
                            puntajeDeLaRonda+=puntaje;
                            puntajeSegundoJugador[0]+=puntaje;
                        }

                        oink=realizarUltimaOportunidad(primerDado, segundoDado);
                        if(oink){
                            puntajeDos=(primerDado+segundoDado)*2;
                            cout<<"TRUFAS ACUMULADAS EN LA LANZADA: "<<puntajeDos<<endl;
                            cout<<"HICISTE UN OINK!!! "<<endl;
                            cout<<"TRUFAS TOTALES: "<<puntajeDos;
                            puntajeDeLaRonda+=puntajeDos;
                            puntajeSegundoJugador[0]+=puntajeDos;
                            puntajeSegundoJugador[1]++;
                            rlutil::anykey();
                        }

                    terceraOp=realizarTerceraComparacion(primerDado,segundoDado);
                    if(terceraOp){
                        cout<<"¡UPS! PERDISTE LAS TRUFAS DE ESTA RONDA." <<endl;
                        cout<<" MEJOR SUERTE LA PROXIMA. "<<endl;
                        cout<<"TRUFAS TOTALES: 0"<<endl;

                       puntajeSegundoJugador[0]=puntajeSegundoJugador[0]-puntajeDeLaRonda;
                       puntajeDeLaRonda=0;
                        /*if(puntajeSegundoJugador[0]>puntajeDeLaRonda){

                            puntajeSegundoJugador[0]=puntajeSegundoJugador[0]-puntajeDeLaRonda;
                            puntajeDeLaRonda=0;
                        }
                        else{
                            puntajeSegundoJugador[0]=0;
                            puntajeDeLaRonda=0;
                        }*/
                        turnoJugadorDos=false;
                        rlutil::anykey();
                    }


                    cerdoAlBarro=realizarSegundaComparacion(primerDado,segundoDado);
                    if(cerdoAlBarro){
                        cout<<"CERDO AL BARRO"<<endl;
                        cout<<"PERDISTE TU TURNO, "<<segundoJugador<<" MEJOR SUERTE LA PROXIMA!"<<endl;
                        cout<<"TE QUEDASTE SIN TRUFAS. TOTAL: 0"<<endl;
                        puntajeSegundoJugador[0]=0;
                        rlutil::anykey();
                        tresDados=true;
                        turnoJugadorDos=false; // CAMBIA A TRUE Y SE EMPIEZA A JUGAR CON TRES DADOS
                    }

                    if(puntajePrimerJugador[0]>=10 && puntajeSegundoJugador[0]>=10){
                        tresDados=true;
                    }

                    rlutil::cls();
                }

                cantidadDeLanzamientos=0;
                puntajeDeLaRonda=0;
                CarasPrimo=false;
                contadorPrimoUno=0;
                contadorPrimoDos=0;
                return tresDados;
        }

        /// REALIZA LA JUGADA CON TRES DADOS
        void jugarTresDados(int numeroRonda, int puntajeJugadorUno[ ],int tamPrimero, int puntajeJugadorDos[ ],int tamSegundo, string jugadorUno, string jugadorDos) {

                bool turnoJugadorDos=false;
                bool oink = false, terceraOp = false, primerOp = false, cerdoAlBarro = false;
                int puntaje = 0, primerDado, segundoDado, puntajeDos =0, tercerDado;
                int cantidadDeLanzamientos = 1,  puntajeDeLaRonda = 0;
                bool banderaPrimerLanzamiento=false, banderaPrimo=false, CarasPrimo=false;
                int contadorPrimoUno=0, contadorPrimoDos=0, contadorPrimoTres=0;

                do{
                        rlutil::locate(3,6);
                        cout<<"------------------------------------------------------------------------"<<endl;
                        cout<<" CERDO:              "<<jugadorUno<<"                     "<<jugadorDos<<endl;
                        cout<<" TRUFAS TOTALES:          "<<puntajeJugadorUno[0]<<"                  "<<puntajeJugadorDos[0]<<endl;
                        cout<<endl<<endl;
                        hacerBarra();
                        cout<<"  CANTIDAD DE DADOS: 3"<<endl;
                        hacerBarra();
                        cout<<"  CERDITO   "<<jugadorUno<<endl;
                        hacerBarra();
                        cout<<"  RONDAS # "<<numeroRonda<<endl;
                        hacerBarra();
                        cout<<"  TRUFAS RONDA: "<<puntajeDeLaRonda<<endl;
                        hacerBarra();
                        cout<<"  LANZAMIENTOS: "<<cantidadDeLanzamientos<<endl;
                        hacerBarra();
                        cout<<"                  LANZAMIENTO #"<<cantidadDeLanzamientos+1<<endl;

                            primerDado=tirarDado();
                            cout<<"PUNTAJE DADO 1: "<<primerDado<<endl;
                            cout<<endl<<endl;
                            mostrarDados(primerDado);
                            segundoDado=tirarDado();
                            cout<<"PUNTAJE DADO 2: "<<segundoDado<<endl;
                            cout<<endl<<endl;
                            mostrarDados(segundoDado);
                            tercerDado=tirarDado();
                            cout<<endl<<endl;
                            cout<<"PUNTAJE DADO 3: "<<tercerDado<<endl;
                            mostrarDados(tercerDado);


                             for(int i =1; i<=primerDado; i++){
                                if(primerDado%i==0){
                                    contadorPrimoUno++;
                                }
                             }


                             for(int i = 1; i<=segundoDado; i++){
                                if(segundoDado%i==0){
                                    contadorPrimoDos++;
                                }
                             }

                             for(int i = 1; i<=tercerDado; i++){
                                  if(tercerDado%i==0){
                                    contadorPrimoTres++;
                                }

                             }

                             if((contadorPrimoUno==2) && (contadorPrimoDos==2) && (contadorPrimoTres==2)){
                                CarasPrimo=true;
                             }

                             if(!banderaPrimerLanzamiento){
                                if(!banderaPrimo && CarasPrimo==true){
                                    puntajeJugadorUno[3]=7;
                                    banderaPrimo=true;
                                    banderaPrimerLanzamiento=true;
                                }
                                else{
                                    if(banderaPrimo){
                                        puntajeJugadorUno[3]=0;
                                        banderaPrimerLanzamiento=false;
                                    }
                                }
                             } //FIN IF


                            cantidadDeLanzamientos++;
                            if (cantidadDeLanzamientos > puntajeJugadorUno[2]){
                                puntajeJugadorUno[2]=cantidadDeLanzamientos;
                            }


                            primerOp=realizarPrimerOportunidadTresDados(primerDado,segundoDado,tercerDado);
                            if(primerOp){
                                puntaje=primerDado+segundoDado+tercerDado;
                                cout<<"TRUFAS TOTALES: "<<puntaje<<endl;
                                turnoJugadorDos=preguntarLanzada();
                                puntajeDeLaRonda+=puntaje;
                                puntajeJugadorUno[0]+=puntaje;
                            }

                            oink=realizarUltimaOportunidadTresDados(primerDado, segundoDado,tercerDado);
                            if(oink){
                                puntajeDos=(primerDado+segundoDado+tercerDado)*2;
                                cout<<"TRUFAS ACUMULADAS: "<<puntajeDos<<endl;
                                cout<<"UST HIZO UN OINK: "<<endl;
                                cout<<"TRUFAS TOTALES: "<<puntajeDos;
                                puntajeDeLaRonda+=puntajeDos;
                                puntajeJugadorUno[0]+=puntajeDos;
                                puntajeJugadorUno[1]++;
                                rlutil::anykey();
                            }

                        terceraOp=realizarTerceraComparacionTresDados(primerDado, segundoDado,tercerDado);
                        if(terceraOp){
                            cout<<"¡UPS! PERDISTE LAS TRUFAS DE ESTA RONDA." <<endl<<" MEJOR SUERTE LA PROXIMA. "<<endl;
                            cout<<"TRUFAS TOTALES: 0"<<endl;
                            puntajeJugadorUno[0]=puntajeJugadorUno[0]-puntajeDeLaRonda;
                            puntajeDeLaRonda=0;
                        /*    if(puntajeDeLaRonda<puntajeJugadorUno[0]){
                                puntajeJugadorUno[0]=puntajeJugadorUno[0]-puntajeDeLaRonda;
                                puntajeDeLaRonda=0;
                            }
                            else{
                                puntajeJugadorUno[0]=0;
                                puntajeDeLaRonda=0;
                            } */

                            turnoJugadorDos=true;
                            rlutil::anykey();
                        }


                        cerdoAlBarro=realizarSegundaComparacionTresDados(primerDado, segundoDado,tercerDado);
                        if(cerdoAlBarro){
                            cout<<"CERDO AL BARRO"<<endl;
                            turnoJugadorDos=true;
                            cout<<"PERDISTE TU TURNO, "<<jugadorUno<<" MEJOR SUERTE LA PROXIMA!"<<endl;
                            cout<<endl<<endl;
                            cout<<"Tus trufas pasan a "<<jugadorDos<<": (Total hasta el momento: "<<puntajeJugadorUno[0]<<")"<<endl;
                            puntajeJugadorDos[0]+=puntajeJugadorUno[0];
                            puntajeJugadorUno[0]=0;
                            rlutil::anykey();
                        }

                        rlutil::cls();

                    } while(!turnoJugadorDos); // DO

                    puntajeDeLaRonda = 0;
                    cantidadDeLanzamientos = 0;
                    CarasPrimo=false;
                    contadorPrimoUno=0;
                    contadorPrimoDos=0;
                    contadorPrimoTres=0;

                do{
                        rlutil::locate(3,6);

                        cout<<"------------------------------------------------------------------------"<<endl;
                        cout<<" CERDO:              "<<jugadorUno<<"                     "<<jugadorDos<<endl;
                        cout<<" TRUFAS TOTALES:             "<<puntajeJugadorUno[0]<<"                   "<<puntajeJugadorDos[0]<<endl;
                        cout<<endl<<endl;
                        hacerBarra();
                        cout<<" CANTIDAD DE DADOS: 3"<<endl;
                        hacerBarra();
                        cout<<" CERDITO   "<<jugadorDos<<endl;
                        hacerBarra();
                        cout<<" RONDAS # "<<numeroRonda<<endl;
                        hacerBarra();
                        cout<<" TRUFAS RONDA: "<<puntajeDeLaRonda<<endl;
                        hacerBarra();
                        cout<<" LANZAMIENTOS: "<<cantidadDeLanzamientos<<endl;
                        hacerBarra();
                        cout<<"                 LANZAMIENTO #"<<cantidadDeLanzamientos+1<<endl;

                            primerDado=tirarDado();
                            cout<<"PUNTAJE DADO 1: "<<primerDado<<endl;
                            mostrarDados(primerDado);
                            cout<<endl<<endl;
                            segundoDado=tirarDado();
                            cout<<"PUNTAJE DADO 2: "<<segundoDado<<endl;
                            mostrarDados(segundoDado);
                            cout<<endl<<endl;
                            tercerDado=tirarDado();
                            cout<<"PUNTAJE DADO 3: "<<tercerDado<<endl;
                            mostrarDados(tercerDado);


                       for(int i =1; i<=primerDado; i++){
                                if(primerDado%i==0){
                                    contadorPrimoUno++;
                                }
                             }


                             for(int i = 1; i<=segundoDado; i++){
                                if(segundoDado%i==0){
                                    contadorPrimoDos++;
                                }
                             }

                             for(int i = 1; i<=tercerDado; i++){
                                  if(tercerDado%i==0){
                                    contadorPrimoTres++;
                                }

                             }

                             if((contadorPrimoUno==2) && (contadorPrimoDos==2) && (contadorPrimoTres==2)){
                                CarasPrimo=true;
                             }

                             if(!banderaPrimerLanzamiento){
                                if(!banderaPrimo && CarasPrimo==true){
                                    puntajeJugadorDos[3]=7;
                                    banderaPrimo=true;
                                    banderaPrimerLanzamiento=true;
                                }
                                else{
                                    if(banderaPrimo){
                                        puntajeJugadorDos[3]=0;
                                        banderaPrimerLanzamiento=false;
                                    }
                                }
                             } //FIN IF




                            cantidadDeLanzamientos++;
                            if (cantidadDeLanzamientos > puntajeJugadorDos[2]) {
                                puntajeJugadorDos[2]=cantidadDeLanzamientos;
                            }

                            primerOp=realizarPrimerOportunidadTresDados(primerDado,segundoDado,tercerDado);
                            if(primerOp){
                                puntaje=primerDado+segundoDado+tercerDado;
                                cout<<"TRUFAS TOTALES: "<<puntaje<<endl;
                                turnoJugadorDos=preguntarLanzadaDos();
                                puntajeDeLaRonda+=puntaje;
                                puntajeJugadorDos[0]+=puntaje;
                            }

                            oink=realizarUltimaOportunidadTresDados(primerDado, segundoDado,tercerDado);
                            if(oink){
                                puntajeDos=(primerDado+segundoDado+tercerDado)*2;
                                cout<<"TRUFAS ACUMULADAS: "<<puntajeDos<<endl;
                                cout<<"UST HIZO UN OINK: "<<endl;
                                cout<<"TRUFAS TOTALES: "<<puntajeDos;
                                puntajeDeLaRonda+=puntajeDos;
                                puntajeJugadorDos[0]+=puntajeDos;
                                puntajeJugadorDos[1]++;
                                rlutil::anykey();
                            }

                        terceraOp=realizarTerceraComparacionTresDados(primerDado, segundoDado,tercerDado);
                        if(terceraOp){
                            cout<<"¡UPS! PERDISTE LAS TRUFAS DE ESTA RONDA." <<endl<<" MEJOR SUERTE LA PROXIMA. "<<endl;
                            cout<<"TRUFAS TOTALES: 0"<<endl;
                            puntajeJugadorDos[0]=puntajeJugadorDos[0]-puntajeDeLaRonda;
                            puntajeDeLaRonda=0;
                            /*if(puntajeDeLaRonda<puntajeJugadorDos[0]){
                                puntajeJugadorDos[0]=puntajeJugadorDos[0]-puntajeDeLaRonda;
                                puntajeDeLaRonda=0;
                            }
                            else{
                                puntajeJugadorDos[0]=0;
                                puntajeDeLaRonda=0;
                            }*/
                            turnoJugadorDos=false;
                            rlutil::anykey();
                        }


                        cerdoAlBarro=realizarSegundaComparacionTresDados(primerDado, segundoDado,tercerDado);
                        if(cerdoAlBarro){
                            cout<<"CERDO AL BARRO"<<endl;
                            turnoJugadorDos=false;
                            cout<<"PERDISTE TU TURNO, "<<jugadorDos<<" MEJOR SUERTE LA PROXIMA!"<<endl;
                            cout<<endl<<endl;
                            cout<<"Tus trufas pasan a "<<jugadorUno<<": (Total hasta el momento: "<<puntajeJugadorDos[0]<<")"<<endl;
                            puntajeJugadorUno[0]+=puntajeJugadorDos[0];
                            puntajeJugadorDos[0]=0;
                            rlutil::anykey();
                        }
                        rlutil::cls();

                    } while(turnoJugadorDos);

                    puntajeDeLaRonda = 0;
                    cantidadDeLanzamientos = 0;
                    CarasPrimo=false;
                    contadorPrimoUno=0;
                    contadorPrimoDos=0;
                    contadorPrimoTres=0;
        }


