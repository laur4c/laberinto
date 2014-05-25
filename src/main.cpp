#include <iostream>

#include "cabeceras/ImagenLaberinto.h"
#include "cabeceras/Parser.h"
#include "cabeceras/Laberinto.h"

using namespace std;


int main(int argc, char *argv[]) {
   string nombreArchivo;
   cout << "Ingrese el path del archivo: ";

   try {
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

      delete laberinto;
   } catch (const char* msg) {
      cout << msg << endl;
   }

   return 0;
}
