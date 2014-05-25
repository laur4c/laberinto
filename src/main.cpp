#include <iostream>

#include "ImagenLaberinto.h"
#include "Parser.h"
#include "Laberinto.h"

using namespace std;


int main(int argc, char *argv[]) {
   string nombreArchivo;
   cout << "Ingrese el path del archivo: ";

   // cin >> nombreArchivo;
   nombreArchivo = "/home/laurac/src/fiuba/laberinto/test/Caminos.txt";
   Parser parser(nombreArchivo);
   parser.iniciar();

   Cola<Comando*> * listaComandos = parser.obtenerLista();
   // cout << "Lista de comandos" << endl;
   // listaComandos->mostrar();

   Laberinto * laberinto = new Laberinto();
   laberinto->crearCaminosDesdeListaDeComandos(listaComandos);

   Mochila * mochila = laberinto->obtenerMochila();
   cout << "Mochila: " << endl;
   mochila->mostrar();

   ImagenLaberinto * imagen = new ImagenLaberinto(laberinto->obtenerCaminos(), 3);
   imagen->generar();

   return 0;
}
