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

        using namespace std;

/// muestra el numero del dado en forma grafica
    void mostrarDados(int&nDeCara){

            rlutil::setColor(rlutil::WHITE);
            switch(nDeCara){
                case 1:
                         cout<<"+-------+"<<endl<<"|       |"<<endl<<"|   x   |"<<endl<<"|       |"<<endl<<"+-------+"<<endl;
                        break;
                case 2:
                         cout<<"+-------+"<<endl<<"| x     |"<<endl<<"|       |"<<endl<<"|     x |"<<endl<<"+-------+"<<endl;
                         break;
                case 3:
                         cout<<"+-------+"<<endl<<"| x     |"<<endl<<"|   x   |"<<endl<<"|     x |"<<endl<<"+-------+"<<endl;
                    break;
                case 4:
                         cout<<"+-------+"<<endl<<"| x   x |"<<endl<<"|       |"<<endl<<"| x   x |"<<endl<<"+-------+"<<endl;
                    break;
                case 5:
                        cout<<"+-------+"<<endl<<"| x   x |"<<endl<<"|   x   |"<<endl<<"| x   x |"<<endl<<"+-------+"<<endl;
                    break;
                case 6:
                         cout<<"+-------+"<<endl<<"| x   x |"<<endl<<"| x   x |"<<endl<<"| x   x |"<<endl<<"+-------+"<<endl;
                    break;
                        }
            rlutil::setColor(rlutil::LIGHTMAGENTA);
    }


/// dibuja la linea superior de la tabla principal
 void mostrarTablaBordeSuperior(){

     char A=201, B= 205, C= 187;
      cout<< A<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B;
      cout<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B;
      cout<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B;
      cout<<B<<B<<B<<B<<B<<B<<B<<B<<C;
 }

 /// dibuja la linea inferior de la tabla principal

    void mostrarTablaBordeInferior(){
      char A = 200;
      char B = 205;
      char C = 188;
      cout<< A<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B;
      cout<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B;
      cout<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B;
      cout<<B<<B<<B<<B<<B<<B<<B<<B<<C;
    }

    /// dibuja la linea derecha de la tabla principal
    void mostrarTablaBordeLateralDerecho(){

        char a = 186;
        char B = 185;

        cout<<a<<endl;
          rlutil::locate(78,2);
        cout<<a<<endl;
          rlutil::locate(78,3);
        cout<<a<<endl;
          rlutil::locate(78,4);
        cout<<a<<endl;
          rlutil::locate(78,5);
        cout<<B<<endl;
          rlutil::locate(78,6);
        cout<<a<<endl;
          rlutil::locate(78,7);
        cout<<a<<endl;
          rlutil::locate(78,8);
        cout<<a<<endl;
          rlutil::locate(78,9);
        cout<<B<<endl;
          rlutil::locate(78,10);
        cout<<a<<endl;
          rlutil::locate(78,11);
        cout<<a<<endl;
          rlutil::locate(78,12);
        cout<<a<<endl;
          rlutil::locate(78,13);
        cout<<B<<endl;
          rlutil::locate(78,14);
        cout<<a<<endl;
         rlutil::locate(78,15);
        cout<<a<<endl;
         rlutil::locate(78,16);
        cout<<a<<endl;
         rlutil::locate(78,17);
        cout<<B<<endl;
         rlutil::locate(78,18);
        cout<<a<<endl;
         rlutil::locate(78,19);
        cout<<a<<endl;
         rlutil::locate(78,20);
        cout<<a<<endl;
    }

    /// dibuja la linea izquierda de la tabla principal
        void mostrarTablaBordeLateral(){
            char a = 186;
            char b = 204;

            cout<<a<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
            cout<<a<<endl;
        }

/// dibuja la linea divisora de la tabla principal
    void mostrarRayaDivisora(){

        char a = 205;
        cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
        cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
        cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
        cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
    }

    /// dibuja la linea de las estadisticas
    void hacerBarra(){
            char B = 205;
            char C= 204;
            char A = 185;

        rlutil::setColor(rlutil::YELLOW);
        cout<<C<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<B<<A<<endl;
        rlutil::setColor(rlutil::LIGHTMAGENTA);
    }

    ///MUESTRA CERDITOS
    void mostrarCerditos(){

        char a= 92;
        rlutil::locate(7,10);
        rlutil::setColor(rlutil::WHITE);
        cout<<"LUDMILA BELEN BOFFO    -     Legajo 25.822"<<endl;

    rlutil::setColor(rlutil::LIGHTMAGENTA);
        cout<<endl<<endl;


cout<<"                          ,.  "<<endl;
cout<<"                          (_|,."<<endl;
cout<<"                         ,' /, )_______"<<endl;
cout<<"                      __j o``-'        `.'-)'"<<endl;
cout<<"                     ('')                 "<<a<<"'"<<endl;
cout<<"                      `-j                |"<<endl;
cout<<"                        `-._(           /"<<endl;
cout<<"                           |_"<<a<<"  |--^.  /"<<endl;
cout<<"                          /_]'|_| /_)_/"<<endl;
cout<<"                             /_]'  /_]'"<<endl;





        cout<<endl<<endl;
         rlutil::setColor(rlutil::LIGHTRED);
        cout<<endl<<"     PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU PRINCIPAL"<<endl;
         rlutil::setColor(rlutil::LIGHTMAGENTA);
        rlutil::anykey();
    }


