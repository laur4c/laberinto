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
   ImagenLaberinto * imagen;
   Grafo<string> * grafo;
   Laberinto * laberinto;
   Parser * parser;

   try {
      string nombreArchivo;
      cout << "Ingrese el path del archivo: ";
      // cin >> nombreArchivo;
      nombreArchivo = "/home/laurac/src/fiuba/laberinto/test/Caminos.txt";

      parser = new Parser(nombreArchivo);
      parser->iniciar();
      Cola<Comando*> * listaComandos = parser->obtenerLista();
      // listaComandos->mostrar();

      laberinto = new Laberinto();
      grafo = laberinto->crearGrafoDesdeListaDeComandos(listaComandos);

      cout << "Estado de la mochila del caminante: " << endl;
      laberinto->mostrarMochila();

      cout << "Description cuantitativa del recorrido realizado por el caminante: " << endl;
      laberinto->mostrarInfo();

      imagen = new ImagenLaberinto(grafo);
      imagen->generar();

      bool continuar = true;
      string origen, destino, respuesta;

      // grafo->mostrar();

      while(continuar) {
         cout << "Ingrese origen y destino para conocer el minimo camino a recorrer: " << endl;

         cout << "Origen: ";
         // cin >> origen;
         origen = "ROJO-NARANJA-2";

         cout << "Destino: ";
         // cin >> destino;
         destino = "ROJO-ROSA-2";

         imagen->dibujarCaminoMinimo(origen, destino);

         cout << "Desea continuar? S/n ";
         // cin >> respuesta;
         respuesta = "n";
         continuar = (respuesta != "n");
      }

   } catch (const char* msg) {
      cout << msg << endl;
   }

   delete imagen;
   delete grafo;
   delete laberinto;
   delete parser;

   return 0;
}


