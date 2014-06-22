/**
 * Integrantes:
 *
 * Corvalan, Laura Estefania 93082
 */

#include <iostream>

#include "cabeceras/ImagenLaberinto.h"
#include "cabeceras/Parser.h"
#include "cabeceras/Laberinto.h"
#include "cabeceras/Grafo.h"

using namespace std;

int main(int argc, char *argv[]) {
   try {
      string nombreArchivo;
      cout << "Ingrese el path del archivo: ";
      cin >> nombreArchivo;

      Parser parser(nombreArchivo);
      parser.iniciar();
      Cola<Comando*> * listaComandos = parser.obtenerLista();
      // listaComandos->mostrar();

      Laberinto * laberinto = new Laberinto();
      Grafo<string> * grafo = laberinto->crearGrafoDesdeListaDeComandos(listaComandos);

      cout << "Estado de la mochila del caminante: " << endl;
      laberinto->mostrarMochila();

      cout << "Description cuantitativa del recorrido realizado por el caminante: " << endl;
      laberinto->mostrarInfo();

      ImagenLaberinto * imagen = new ImagenLaberinto(grafo);
      imagen->generar();

      bool continuar = true;
      string origen, destino, respuesta;

      // grafo->mostrar();

      while(continuar) {
         cout << "Ingrese origen y destino para conocer el minimo camino a recorrer: " << endl;

         cout << "Origen: ";
         cin >> origen;

         cout << "Destino: ";
         cin >> destino;

         imagen->dibujarCaminoMinimo(origen, destino);

         cout << "Desea continuar? S/n ";
         cin >> respuesta;

         continuar = (respuesta != "n");
      }

   } catch (const char* msg) {
      cout << msg << endl;
   }

   return 0;
}


