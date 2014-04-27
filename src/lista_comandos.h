/**
   Laberinto - TP 1

   @author Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _LISTA_COMANDOS_H_
#define _LISTA_COMANDOS_H_
#include <string>
#include "comando.h"

class ListaComandos {
   public:
      ListaComandos();

      void insertar(std::string nombreComando, std::string argumento);

      void eliminar();

      bool estaVacia();

      int obtenerTamanio();

      void mostrar();

      ~ListaComandos();

   private:

      Comando * primero;

      Comando * ultimo;

      int tamanio;

};

#endif