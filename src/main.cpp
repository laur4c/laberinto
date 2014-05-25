#include <iostream>

#include "cabeceras/ImagenLaberinto.h"
#include "cabeceras/Parser.h"
#include "cabeceras/Laberinto.h"

using namespace std;


int main(int argc, char *argv[]) {
   string nombreArchivo;
   cout << "Ingrese el path del archivo: ";

   cin >> nombreArchivo;
   Parser parser(nombreArchivo);
   parser.iniciar();

   Cola<Comando*> * listaComandos = parser.obtenerLista();
   // cout << "Lista de comandos" << endl;
   // listaComandos->mostrar();

   Laberinto * laberinto = new Laberinto();
   laberinto->crearCaminosDesdeListaDeComandos(listaComandos);

   Mochila * mochila = laberinto->obtenerMochila();
   cout << "Estado de la mochila del caminante: " << endl;
   mochila->mostrar();

   cout << "Description cuantitativa del recorrido realizado por el caminante: " << endl;
   laberinto->mostrarInfo();

   ImagenLaberinto * imagen = new ImagenLaberinto(laberinto->obtenerCaminos());
   imagen->generar();

   return 0;
}
