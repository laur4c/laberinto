/**
   Laberinto - TP 1

   @author Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _LISTA_COMANDOS_H_
#define _LISTA_COMANDOS_H_
#include <string>
#include "Comando.h"

class ListaComandos {
   public:
      ListaComandos();

      void acolar(std::string nombreComando, std::string argumento);

      void desacolar();

      bool estaVacia();

      int obtenerTamanio();

      void mostrar();

      Comando * obtenerFrente();

      ~ListaComandos();

   private:

      Comando * frente;

      Comando * fondo;

      int tamanio;

};

#endif