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

      // Se genera una lista con comandos. Cada comando representa una directiva
      // del archivo de texto
      parser.iniciar();
      Cola<Comando*> * listaComandos = parser.obtenerLista();
      // cout << "Lista de comandos" << endl;
      // listaComandos->mostrar();

      // A partir de la lista de comandos, se crea una lista de caminos
      // El camino es una estructura de puntos entrelazados (cada punto tiene
      // cuatro punteros, que representan las uniones del punto
      // con otros puntos en todas las direcciones: norte, sur, este, oeste)
      // Estos puntos pretenden representar todos los recorridos del laberinto
      Laberinto * laberinto = new Laberinto();
      laberinto->crearCaminosDesdeListaDeComandos(listaComandos);

      Mochila * mochila = laberinto->obtenerMochila();
      cout << "Estado de la mochila del caminante: " << endl;
      mochila->mostrar();

      cout << "Description cuantitativa del recorrido realizado por el caminante: " << endl;
      laberinto->mostrarInfo();

      ImagenLaberinto * imagen = new ImagenLaberinto(laberinto->obtenerCaminos());
      imagen->generar();

      // TP2
      // Sin terminar

      // Llegue a implementar el Grafo y el algoritmo de Dijkstra para el calculo de caminos
      // minimos, pero no llegue a integrarlo con lo que tenia hecho anteriormente en el TP1.
      // Comportamiento actual: Se imprimen los vertices del recorrido minimo en consola,
      // pero no se dibujan en la imagen generada.
      //
      // Qué falta: Representar de manera correcta los caminos del laberinto en un grafo :/
      // y dibujar el recorrido en la imagen laberinto.bmp

      parser.iniciar();
      listaComandos = parser.obtenerLista();
      Grafo<string> * grafo = laberinto->crearGrafoDesdeListaDeComandos(listaComandos);

      bool continuar = true;
      string origen, destino, respuesta;

      while(continuar) {
         cout << "Ingrese origen y destino para conocer el minimo camino a recorrer: " << endl;

         cout << "Origen: ";
         cin >> origen;

         cout << "Destino: ";
         cin >> destino;

         grafo->imprimirCaminoMinimo(origen, destino);

         cout << "Desea continuar? S/n ";
         cin >> respuesta;

         continuar = (respuesta == "n");
      }

      delete laberinto;
   } catch (const char* msg) {
      cout << msg << endl;
   }

   return 0;
}


