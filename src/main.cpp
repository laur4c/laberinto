#include <iostream>

#include "Parser.h"
#include "Laberinto.h"

using namespace std;

int main(int argc, char *argv[]) {
   string nombreArchivo;
   cout << "Ingrese el path del archivo: ";
   cin >> nombreArchivo;

   Parser parser(nombreArchivo);
   parser.iniciar();

   Cola<Comando> * listaComandos = parser.obtenerLista();
   cout << "Lista de comandos" << endl;
   listaComandos->mostrar();

   Laberinto laberinto;
   laberinto.crearCaminosDesdeListaDeComandos(listaComandos);

   Mochila * mochila = laberinto.obtenerMochila();
   cout << "Mochila: " << endl;
   mochila->mostrar();

   ListaEnlazada<Camino> * caminos = laberinto.obtenerCaminos();
   caminos->mostrar();

   return 0;
}
