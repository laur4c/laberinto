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
      /**
       * Constructor.
       */
      ListaComandos();

      /**
       * Agrega un elemento al final de la lista.
       */
      void acolar(std::string nombreComando, std::string argumento);

      /**
       * Remueve un elemento del frente de la lista.
       */
      void desacolar();

      /**
       * Retorna true si la lista esta vacia, false en caso contrario
       */
      bool estaVacia();

      /**
       * Retorna cantidad de elementos dentro de la lista
       */
      int obtenerTamanio();

      /**
       * Imprime cada elemento de la lista. Invoca el metodo aString
       * de cada elemento de la lista
       */
      void mostrar();

      /**
       * Retorna primer elemento de la lista
       */
      Comando * obtenerFrente();

      ~ListaComandos();

   private:

      /**
       * Puntero a primer elemento de la lista
       */
      Comando * frente;

      /**
       * Puntero al ultimo elemento de la lista
       */
      Comando * fondo;

      /**
       * Tamanio de la lista
       */
      int tamanio;

};

#endif