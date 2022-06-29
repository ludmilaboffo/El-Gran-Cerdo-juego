#include <string>
#include <windows.h>
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
///////////////// INICIO FUNCIONES

                using namespace std;


    ///DESPLIEGA EL MENU PPAL Y RETORNA LA OPCION ELEGIDA;
    int mostrarMenu(){

        int opcion;
        rlutil::locate(5,5);
    cout<<" GRAN CERDO"<<endl;
        rlutil::locate(5,7);
    cout<<"---------------------"<<endl;
        rlutil::locate(5,8);
    cout<<"1"<<char(196)<<" JUGAR"<<endl;
        rlutil::locate(5,9);
    cout<<"2"<<char(196)<<" ESTAD"<<char(161)<<"STICAS"<<endl;
        rlutil::locate(5,10);
    cout<<"3"<<char(196)<<" CERDITOS"<<endl;
        rlutil::locate(5,11);
    cout<<"---------------------"<<endl;
        rlutil::locate(5,12);
    cout<<"0 "<<char(196)<<" SALIR"<<endl;
        rlutil::locate(5,15);
    rlutil::setColor(rlutil::WHITE);
    cout<<" OPC : ";
    cin>>opcion;
    cin.ignore();
    rlutil::setColor(rlutil::LIGHTMAGENTA);
        return opcion;
    }

/// PIDE LOS NOMBRES


    string pedirNombre(){
        string jugador;

            rlutil::locate(2,4);
            cout<<"INGRESE JUGADOR: ";
            getline(cin,jugador);
            return jugador;
    }


    /// genera un numero aleatorio y lo devuelve como int
    int tirarDado (){
    int numero;
    numero = rand()% 6 + 1;
    return numero;
    }

    /// funcion que lanza los dos dados iniciales y otorga los turnos por puntaje


 void iniciarJuego(string &primerJugador, string &segundoJugador){
        int lanzadaUnoJU, lanzadaUnoJD, lanzadaDosJU, lanzadaDosJD;
        int primerLanzador, segundoLanzador;
        string auxiliarJugador;
        char respuestaInicio;

        do {
            rlutil::cls();
            rlutil::locate(3,5);
            cout<<"Es el turno de tirar de: "<<primerJugador<<" "<<(char)168<<"preparado? Pulse S "<<endl;
            cout<<endl<<endl;
            lanzadaUnoJU=tirarDado();
            cout<<"PUNTAJE DADO 1: "<<lanzadaUnoJU<<endl;
            mostrarDados(lanzadaUnoJU);
            lanzadaDosJU=tirarDado();
            cout<<"PUNTAJE DADO 2: "<<lanzadaDosJU<<endl;
            mostrarDados(lanzadaDosJU);
            primerLanzador=lanzadaUnoJU+lanzadaDosJU;
            cout<<endl;
            cout<<"TOTAL: "<<primerLanzador<<endl;

            rlutil::anykey();


            rlutil::cls();
            rlutil::locate(3,6);
            cout<<"Es el turno de tirar de: "<<segundoJugador<<" "<<(char)168<<"preparado?: Pulse S"<<endl;
            rlutil::anykey();
            cout<<endl<<endl;

            lanzadaUnoJD=tirarDado();
            cout<<"PUNTAJE DADO 1: "<<lanzadaUnoJD<<endl;
            mostrarDados(lanzadaUnoJD);
            lanzadaDosJD=tirarDado();
            cout<<"PUNTAJE DADO 2: "<<lanzadaDosJD<<endl;
            mostrarDados(lanzadaDosJD);
            segundoLanzador=lanzadaUnoJD+lanzadaDosJD;
            cout<<endl;
            cout<<"TOTAL: "<<segundoLanzador<<endl;
            cout<<endl;
            cout<<"Presione cualquier tecla para continuar: "<<endl;
            rlutil::anykey();
            rlutil::cls();

              if(primerLanzador>segundoLanzador){
                    cout<<"Va a comenzar..."<<endl;
                    rlutil::setColor(rlutil::YELLOW);
                    rlutil::locate(3,6);
                    cout<<primerJugador<<endl;
                    respuestaInicio='N';
                    rlutil::setColor(rlutil::LIGHTMAGENTA);
                }
                else{
                    if(primerLanzador<segundoLanzador){
                        cout<<"Va a comenzar..."<<endl;
                        rlutil::locate(3,6);
                        rlutil::setColor(rlutil::YELLOW);
                        cout<<segundoJugador<<endl;
                        auxiliarJugador=segundoJugador;
                        segundoJugador=primerJugador;
                        primerJugador=auxiliarJugador;
                        rlutil::setColor(rlutil::LIGHTMAGENTA);
                        respuestaInicio='N';
                    }
                    if(primerLanzador==segundoLanzador){
                        if(lanzadaUnoJU > lanzadaUnoJD || lanzadaDosJU > lanzadaDosJD){
                                cout<<"EMPATE PERO..."<<endl;
                                cout<<"LA CARA MAS GRANDE LA SACO: "<<primerJugador<<endl;
                                rlutil::locate(3,6);
                                rlutil::setColor(rlutil::YELLOW);
                                cout<<"COMIENZA: "<<primerJugador;
                                rlutil::setColor(rlutil::LIGHTMAGENTA);
                                respuestaInicio='N';
                        }
                        else{
                            if(lanzadaUnoJU < lanzadaUnoJD || lanzadaDosJU < lanzadaDosJD){
                                cout<<"EMPATE PERO..."<<endl;
                                cout<<"LA CARA MAS GRANDE LA SACO: "<<segundoJugador<<endl;
                                rlutil::locate(3,6);
                                rlutil::setColor(rlutil::YELLOW);
                                cout<<"COMIENZA: "<<segundoJugador;
                                auxiliarJugador=segundoJugador;
                                segundoJugador=primerJugador;
                                primerJugador=auxiliarJugador;
                                rlutil::setColor(rlutil::LIGHTMAGENTA);
                                respuestaInicio='N';
                            }
                            else{
                                if(lanzadaUnoJU == lanzadaUnoJD && lanzadaDosJU == lanzadaDosJD){
                                    rlutil::locate(3,6);
                                    cout<<"Tienen el mismo puntaje: VOLVEMOS A LANZAR"<<endl;
                                    respuestaInicio='S';
                                }
                            }
                        }
                    }
                }
            } while(respuestaInicio=='S'); // FINAL DE LA LANZADA PARA VER QUIEN INICIA
}




    /// evalua si los dos dados son distintos y uno es un AS

    bool realizarTerceraComparacion(int dadoA, int dadoB){

        if((dadoA!=dadoB) && (dadoA==1 || dadoB==1)){
                        return true;
            }
        else{
                return false;
            }
        }

        ///EVALUA SI TRES DADOS SON DISTINTOS PERO ALGUNO ES UN AS

    bool realizarTerceraComparacionTresDados(int dadoA, int dadoB, int dadoC){

        if((dadoA!=dadoB && (dadoA!=dadoC || dadoB!=dadoC)) && (dadoA==1 || dadoB==1 || dadoC==1)){
                        return true;
            }
        else{
                return false;
            }
        }


    /// Evalua si dos dados son ambos AS
    bool realizarSegundaComparacion (int dadoA, int dadoB){
        if((dadoA==dadoB) && (dadoA==1 && dadoB==1)){
                    return true;
        }
        else{
            return false;
        }
    }

    /// Evalua si los dados son los tres AS
    bool realizarSegundaComparacionTresDados (int dadoA, int dadoB, int dadoC){
        if((dadoA==dadoB && dadoA==dadoC) && (dadoA==1 && dadoB==1 && dadoC==1)){
                    return true;
        }
        else{
            return false;
        }
    }


    /// Evalua si dos dados son diferentes y NINGUNO es un AS
    bool realizarPrimerOportunidad(int dadoA, int dadoB){
        if((dadoA!=dadoB) && (dadoA!=1 && dadoB!=1)){
                        return true;
        }
        else{
            return false;
        }
    }

   /// Evalua si los tres dados son DOS IGUALES Y UNO DISTINTO O LOS TRES DISTINTOS PERO NINGUNO ES AS
    bool realizarPrimerOportunidadTresDados(int dadoA, int dadoB, int dadoC){
        if(((dadoA!=dadoB) && (dadoA!=dadoC || dadoB!=dadoC)) && (dadoA!=1 && dadoB!=1 && dadoC!=1)){
                        return true;
        }
        else{
            if(((dadoA==dadoB && dadoA!=dadoC) || (dadoB==dadoC && dadoB!=dadoA) || (dadoC==dadoA && dadoC!=dadoB)) && (dadoA!=1 && dadoB!=1 && dadoC!=1)){
                return true;
            }
            else{
                return false;
            }
        }
    }

    /// Evalua si dos dados son iguales y ninguno es un AS
    bool realizarUltimaOportunidad(int dadoA, int dadoB){
        if((dadoA==dadoB) && (dadoA!=1 && dadoB!=1)){
            return true;
        }
        else{
            return false;
        }
    }



    /// Evalua si los tres dados son iguales y ninguno es un AS
    bool realizarUltimaOportunidadTresDados(int dadoA, int dadoB, int dadoC){
        if((dadoA==dadoB && dadoA==dadoC) && (dadoA!=1 && dadoB!=1 && dadoC!=1)){
            return true;
        }
        else{
            return false;
        }
    }



    ///PREGUNTA SI DESEA VOLVER A LANZAR O NO. RETORNA UN BOOLEANO
    bool preguntarLanzada(){
        char respuesta;
        bool pasarDeTurno;
        cout<<" "<<(char)168<<"Desea volver a lanzar? S/N"<<endl;
        cout<<" RTA :  ";
        cin>>respuesta;

       if (toupper(respuesta) =='S'){
                 pasarDeTurno = false;
       }
        else{
                if (toupper(respuesta) =='N'){
                    pasarDeTurno = true;
                }
                else{
                        cout<<" RTA INCORRECTA. REINTENTE:  ";
                        cin>>respuesta;
                }
            }
            return pasarDeTurno;
        }

      bool preguntarLanzadaDos(){
        char respuesta;
        bool continuarJugando;

        cout<<" "<<(char)168<<"Desea volver a lanzar? S/N"<<endl;
        cout<<" RTA :  ";
        cin>>respuesta;

       if (toupper(respuesta) =='S'){
                continuarJugando = true;
       }
        else{
                if (toupper(respuesta) =='N'){
                     continuarJugando = false;
                }
                else{
                        cout<<" RTA INCORRECTA. REINTENTE:  ";
                        cin>>respuesta;
                }
            }
            return continuarJugando;
        }


   /// funcion que realiza la jugada principal


    void jugarCerdo(string&ganador, int&puntajeGanador){

    const int RONDAS = 5, RECOLECCION=4;
    int puntajePrimerJugador[RECOLECCION] = { }, puntajeSegundoJugador[RECOLECCION] = { };
    int puntajeFinalJugadorUno = 0, puntajeFinalJugadorDos = 0;
    bool tresDados=false;
    string primerJugador, segundoJugador, respuestaOink;



                rlutil::cls();
                primerJugador=pedirNombre();
                rlutil::cls();
                rlutil::locate(2,4);
                cout<<char(173)<<"SIGAMOS! Presione cualquier tecla: "<<endl;
                rlutil::anykey();
                rlutil::cls();
                segundoJugador=pedirNombre();

               //INICIO DEL JUEGO.
                rlutil::cls();
                rlutil::locate(3,5);
                cout <<char(173)<<"VAMOS A JUGAR!"<<endl;
                rlutil::locate(3,7);
                cout<<"Presione cualquier tecla: "<<endl;
                rlutil::anykey();
                rlutil::cls();
                    //INICIO DEL JUEGO
                iniciarJuego(primerJugador,segundoJugador);
                 rlutil::anykey();
                 rlutil::cls();

                   //INICIO DE LAS JUGADAS
            for(int ronda=1; ronda<=RONDAS;ronda++){

                if(!tresDados){
                    tresDados=jugarDosDados(ronda,puntajePrimerJugador,RECOLECCION,puntajeSegundoJugador,RECOLECCION,primerJugador,segundoJugador);
                }
                else{
                    if(tresDados){
                        jugarTresDados(ronda,puntajePrimerJugador,RECOLECCION,puntajeSegundoJugador,RECOLECCION,primerJugador,segundoJugador);
                    }
                }
            } //FIN DEL FOR //////

            cout<<endl<<endl;
            rlutil::locate(4,5);
            cout<<"GAME OVER :("<<endl;
            rlutil::locate(20,5);
            cout<<endl<<"Presione una tecla para continuar. "<<endl;
            rlutil::anykey();
            rlutil::cls();

            contarPuntosVictoria(puntajePrimerJugador,RECOLECCION,puntajeSegundoJugador,RECOLECCION,primerJugador,segundoJugador, puntajeFinalJugadorUno, puntajeFinalJugadorDos);

            cout<<endl<<endl;
            cout<<"     PUNTOS DE VICTORIA DE: "<<primerJugador<<": "<<puntajeFinalJugadorUno<<endl;
            cout<<endl<<"     --------------------------------"<<endl;
            cout<<"     PUNTOS DE VICTORIA DE: "<<segundoJugador<<": "<<puntajeFinalJugadorDos<<endl;

            if(puntajeFinalJugadorUno > puntajeFinalJugadorDos){
                rlutil::setColor(rlutil::YELLOW);
                cout<<endl<<endl;
                cout<<"GANADOR: "<<primerJugador<<" con "<<puntajeFinalJugadorUno<<" puntos de victoria."<<endl;
                ganador=primerJugador;
                puntajeGanador=puntajeFinalJugadorUno;
            }
            else{
                if(puntajeFinalJugadorUno < puntajeFinalJugadorDos){
                    cout<<endl<<endl;
                    rlutil::setColor(rlutil::YELLOW);
                    cout<<"GANADOR: "<<segundoJugador<<" con "<<puntajeFinalJugadorDos<<" puntos de victoria."<<endl;
                    ganador=segundoJugador;
                    puntajeGanador=puntajeFinalJugadorDos;
                }
                if(puntajeFinalJugadorUno == puntajeFinalJugadorDos){
                    cout<<endl<<endl;
                    rlutil::setColor(rlutil::YELLOW);
                    cout<<"AMBOS HAN EMPATADO"<<endl;
                    ganador="El ultimo juego fue un empate.";
                    puntajeGanador=puntajeFinalJugadorUno;
                    }
              }
                rlutil::setColor(rlutil::LIGHTMAGENTA);

                cout<<endl<<endl<<endl;
                cout<<"Ingrese cualquier tecla para continuar: "<<endl;
                    rlutil::anykey();
                cout<<endl<<endl<<endl;
                cout<<"OOOINK!";
        }


    /// HACE EL CONTEO Y ASIGNACIÓN DE PUNTOS:
 void contarPuntosVictoria(int primerJugador[],int tamUno,int segundoJugador[],int tamDos, std::string jugadorUno, std::string jugadorDos, int&finalJugUno, int&finalJugDos){

                const int HITOS = 5;
                int PDVJugUno [HITOS] = { }, PDVJugDos[HITOS]= { }; // Vectores para asingar los puntos de victoria

                /// PDV EN 0 = MAYOR CANT DE TRUFAS
                if(primerJugador[0] > segundoJugador[0]){
                    PDVJugUno[0]=5;
                    PDVJugDos[0]=0;
                }
                else{
                    if(primerJugador[0] < segundoJugador[0]){
                        PDVJugUno[0]=0;
                        PDVJugDos[0]=5;
                    }
                    if(primerJugador[0] == segundoJugador[0]){
                        PDVJugUno[0]=5;
                        PDVJugDos[0]=5;
                    }
                }

                /// PDV EN 1 = CANT DE OINKS
                if(primerJugador[1] > segundoJugador[1]){
                    PDVJugUno[1]=2*primerJugador[1];
                    PDVJugDos[1]=0;
                }
                else{
                    if(primerJugador[1] < segundoJugador[1]){
                        PDVJugUno[1]=0;
                        PDVJugDos[1]=2*segundoJugador[1];
                    }
                    if(primerJugador[1] == segundoJugador[1]){
                        PDVJugUno[1]=(2*primerJugador[1]);
                        PDVJugDos[1]=(2*segundoJugador[1]);
                    }
                }

                // CADA CINCUENTA TRUFAS: PDV 2

                if(primerJugador[0] >= 50)
                {
                    PDVJugUno[2]=primerJugador[0]/50;
                }
                else{
                    PDVJugUno[2]=0;
                }

                if(segundoJugador[0] >= 50)
                {
                    PDVJugDos[2]=segundoJugador[0]/50;
                }

                else{
                    PDVJugDos[2]=0;
                }
                //// MAYOR CANTIDAD DE LANZAMIENTOS: PDV 3

               if(primerJugador[2] > segundoJugador[2]){
                    PDVJugUno[3]=3;
               }
               else{
                    if(primerJugador[2] < segundoJugador[2]){
                        PDVJugDos[3]=3;
                    }
                    if(primerJugador[2] == segundoJugador[2]){
                        PDVJugUno[3]=3;
                        PDVJugDos[3]=3;
                    }
               }
               /// AGREGADO DEL EJERCICIO: NUMERO PRIMO:

                if(primerJugador[3] > segundoJugador[3]){
                    PDVJugUno[4]=primerJugador[3];
                    PDVJugDos[4]=0;
                }
                else{
                    if(primerJugador[3] < segundoJugador[3]){
                        PDVJugUno[4]=0;
                        PDVJugDos[4]=segundoJugador[3];
                    }
                }


        for(int i=0; i<HITOS; i++){
            finalJugUno+=PDVJugUno[i];
            finalJugDos+=PDVJugDos[i];
        }

////////////////////// TABLA:

          rlutil::setColor(rlutil::YELLOW);
          mostrarTablaBordeSuperior();
          rlutil::locate(1,2);
          mostrarTablaBordeLateral();

          rlutil::setColor(rlutil::WHITE);
          rlutil::locate(4,3);
          cout<<"HITO"<<endl;
          rlutil::setColor(rlutil::YELLOW);

          rlutil::setColor(rlutil::WHITE);
          rlutil::locate(24,3);
          cout<<jugadorUno<<endl;
          rlutil::setColor(rlutil::YELLOW);

          rlutil::setColor(rlutil::WHITE);
          rlutil::locate(54,3);
          cout<<jugadorDos<<endl;
          rlutil::setColor(rlutil::YELLOW);
          rlutil::locate(3,5);
          cout<<"M"<<char(160)<<"s trufas (total):"<<endl;
          rlutil::locate(3,6);
          mostrarRayaDivisora();
          rlutil::locate(3,10);
          cout<<"Oinks:"<<endl;
          rlutil::locate(3,11);
          mostrarRayaDivisora();
          rlutil::locate(3,14);
          cout<<"Cada 50 trufas:"<<endl;
          rlutil::locate(3,15);
          mostrarRayaDivisora();
          rlutil::locate(3,18);
          cout<<"Cerdo codicioso:"<<endl;
          rlutil::locate(3,19);
          mostrarRayaDivisora();
          rlutil::locate(3,21);
          cout<<"Humcerdo Primo:"<<endl;



          rlutil::locate(24,5);
          cout<<"PDV: "<<PDVJugUno[0]<<" (trufas: "<<primerJugador[0]<<")"<<endl;
          rlutil::locate(24,10);
          cout<<"PDV: "<<PDVJugUno[1]<<" (oinks: "<<primerJugador[1]<<")"<<endl;
          rlutil::locate(24,14);
          cout<<"PDV: "<<PDVJugUno[2]<<" (trufas: "<<primerJugador[0]<<")"<<endl;
          rlutil::locate(24,18);
          cout<<"PDV: "<<PDVJugUno[3]<<" (MAX: "<<primerJugador[2]<<")"<<endl;
          rlutil::locate(24,21);
          cout<<"PDV: "<<PDVJugUno[4]<<endl;

          rlutil::locate(52,5);
          cout<<"PDV: "<<PDVJugDos[0]<<" (trufas: "<<segundoJugador[0]<<")"<<endl;
          rlutil::locate(52,10);
          cout<<"PDV: "<<PDVJugDos[1]<<" (oinks: "<<segundoJugador[1]<<")"<<endl;
          rlutil::locate(52,14);
          cout<<"PDV: "<<PDVJugDos[0]<<" (trufas: "<<segundoJugador[0]<<")"<<endl;
          rlutil::locate(52,18);
          cout<<"PDV: "<<PDVJugDos[3]<<" (MAX: "<<segundoJugador[2]<<")"<<endl;
          rlutil::locate(52,21);
          cout<<"PDV: "<<PDVJugDos[4]<<endl;


          mostrarTablaBordeLateralDerecho();
          rlutil::locate(1,24);
          mostrarTablaBordeInferior();


    } // fin funcion



  void mostrarEstadisticas( int estadisticaPuntaje[], int tamU , string estadisticaNombre[], int tamDos){

    const int TAM =3;
    int auxiliar;
    string auxiliarNombre;

    for(int j=0; j<TAM; j++){
        for(int i=0; i<2; i++){
            if(estadisticaPuntaje[i]<estadisticaPuntaje[i+1]){
                auxiliar=estadisticaPuntaje[i+1];
                estadisticaPuntaje[i+1]=estadisticaPuntaje[i];
                estadisticaPuntaje[i]=auxiliar;

                auxiliarNombre=estadisticaNombre[i+1];
                estadisticaNombre[i+1]=estadisticaNombre[i];
                estadisticaNombre[i]=auxiliarNombre;
            }
        }
    }

        rlutil::locate(6,10);
        cout<<" ---------- ESTADISTICAS  ---------- "<<endl;
        cout<<endl<<endl;
    for (int mostrar=0; mostrar<TAM; mostrar++){
        cout<<"  "<<mostrar+1<<".   JUGADOR: "<<estadisticaNombre[mostrar]<<endl;
        cout<<"      PUNTAJE: "<<estadisticaPuntaje[mostrar]<<endl;
        hacerBarra();
    }

        cout<<"Presione cualquier tecla para volver al men"<<char(163)<<" principal."<<endl;
        rlutil::anykey();
        rlutil::cls();
 }

