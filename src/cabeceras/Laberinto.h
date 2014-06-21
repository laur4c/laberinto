/**
   Laberinto - TP 1

   @author Laura Corvalan
*/

#ifndef _LABERINTO_H_
#define _LABERINTO_H_

#include "util.h"

#include "Mochila.h"
#include "Comando.h"
#include "ListaEnlazada.h"
#include "InfoRecorrido.h"
#include "Cola.h"
#include "Grafo.h"

class Laberinto {
   public:
      /**
       * Constructor.
       */
      Laberinto();

      Grafo<std::string> * crearGrafoDesdeListaDeComandos(Cola<Comando*> * comandos);

      /**
       * Retorna instancia clase Mochila con todos los elementos encontrados en el camino
       */
      Mochila * obtenerMochila();

      /**
       * Imprime info del recorrido
       */
      void mostrarInfo();


      ~Laberinto();


   private:

      /**
       * Lista con elementos levantados en el camino
       */
      Mochila * mochila;

      /**
       * Info del laberinto. Total uniones, bifurcaciones, etc.
       */
      InfoRecorrido * info;

      /**
       * Agrega un elemento a la mochila
       */
      void agregarElementoAMochila(std::string elemento);

      void generarArista(Grafo<std::string> * grafo, Color * color, Cola<Comando*> * componentes, char ultimaOrientacion);
};

#endif
