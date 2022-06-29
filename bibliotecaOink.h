#ifndef BIBLIOTECAOINK_H_INCLUDED
#define BIBLIOTECAOINK_H_INCLUDED

 int mostrarMenu();
// PPAL EN JUGAR:
 std::string pedirNombre();
 int tirarDado();

 // COMPARACIONES CONDICIONALES:
 bool realizarPrimerOportunidad(int, int);
 bool realizarPrimerOportunidadTresDados(int, int, int);
 bool realizarSegundaComparacion (int, int);
 bool realizarSegundaComparacionTresDados(int, int, int);
 bool realizarTerceraComparacion(int, int);
 bool realizarTerceraComparacionTresDados(int, int, int);
 bool realizarUltimaOportunidad(int, int);
 bool realizarUltimaOportunidadTresDados(int, int, int);
 bool preguntarLanzada();
 bool preguntarLanzadaDos();


 // JUGAR:

 void jugarCerdo(std::string&, int&);
 void iniciarJuego(std::string &, std::string &);
 void contarPuntosVictoria(int[ ],int,int[ ],int, std::string, std::string,int&, int&);
 void mostrarEstadisticas( int estadisticaPuntaje[], int tamU , std::string estadisticaNombre[], int tamDos);



#endif // BIBLIOTECAOINK_H_INCLUDED
