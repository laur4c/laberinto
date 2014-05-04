#include <iostream>

#include "ListaComandos.h"
#include "Parser.h"
#include "Laberinto.h"

using namespace std;

int main(int argc, char *argv[]) {
   string nombreArchivo;

   cout << "Ingrese el path del archivo: ";
   cin >> nombreArchivo;
   Parser parser(nombreArchivo);
   parser.iniciar();

   ListaComandos * listaComandos = parser.obtenerLista();
   cout << "Lista de comandos" << endl;
   listaComandos->mostrar();

   Laberinto laberinto;
   laberinto.generarRecorridosDesdeListaDeComandos(listaComandos);

   delete listaComandos;

   ListaRecorridos * recorridos = laberinto.obtenerRecorridos();
   NodoRecorrido * nodoRecorrido = recorridos->obtenerFrente();

   while(nodoRecorrido != NULL) {
      Recorrido * recorrido = nodoRecorrido->obtenerRecorrido();
      Casillero * casillero = recorrido->obtenerFrente();
      cout << "Nuevo Recorrido!" << endl;

      while(casillero != NULL) {
         cout << "orientacion: " << casillero->obtenerOrientacion() << endl;
         cout << "pasos: " << casillero->obtenerCantidadDePasos() << endl;
         cout << "Bifurcacion: " << casillero->obtenerBifurcacion() << endl;
         cout << "Empalme: " << casillero->obtenerEmpalme() << endl;
         cout << "x, y: " << casillero->obtenerPunto()->obtenerX();
         cout << ", " << casillero->obtenerPunto()->obtenerY() << endl;
         cout << "-------------------------------------------" << endl;

         casillero = casillero->obtenerSiguiente();
      }
      nodoRecorrido = nodoRecorrido->obtenerSiguiente();
   }
   return 0;
}