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
   // cout << "Lista de comandos" << endl;
   // listaComandos->mostrar();

   Laberinto laberinto;
   laberinto.generarRecorridosDesdeListaDeComandos(listaComandos);

   delete listaComandos;

   // Se iteran los recorridos del laberinto y se imprime en pantalla
   // la info de cada casillero
   Mochila * mochila = laberinto.obtenerMochila();
   cout << "Mochila: " << endl;
   mochila->mostrar();

   ListaRecorridos * recorridos = laberinto.obtenerRecorridos();
   NodoRecorrido * nodoRecorrido = recorridos->obtenerFrente();

   while(nodoRecorrido != NULL) {
      Recorrido * recorrido = nodoRecorrido->obtenerRecorrido();
      Casillero * casillero = recorrido->obtenerFrente();
      Bifurcacion * bifurcacion = recorrido->obtenerBifurcaciones()->obtenerFrente();

      cout << endl << "***** Nuevo Recorrido! ******" << endl;

      cout << endl << "Bifurcaciones: " << endl << endl;
      while(bifurcacion != NULL) {
         cout << "Nombre: " << bifurcacion->obtenerNombre() << endl;
         bifurcacion = bifurcacion->obtenerSiguiente();
      }
      cout << "-------------------------------------------" << endl;
      cout << "Casilleros: " << endl;

      while(casillero != NULL) {
         cout << "Orientacion: " << casillero->obtenerOrientacion() << endl;
         cout << "Pasos: " << casillero->obtenerCantidadDePasos() << endl;
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