#include <iostream>
#include "lista_comandos.h"
#include "parser.h"

using namespace std;

int main(int argc, char *argv[]) {
   string nombreArchivo;

   cout << "Ingrese el path del archivo: ";
   cin >> nombreArchivo;

   Parser parser(nombreArchivo);
   parser.iniciar();
   ListaComandos * listaComandos = parser.obtenerLista();

   listaComandos->mostrar();


   return 0;
}