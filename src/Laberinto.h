/**
   Laberinto - TP 1

   @author Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _LABERINTO_H_
#define _LABERINTO_H_

#include "util.h"

#include "Mochila.h"
#include "Comando.h"
#include "Camino.h"

#include "ListaEnlazada.h"
#include "Cola.h"

class Laberinto {
   public:
      /**
       * Constructor.
       */
      Laberinto();

      /**
       * A partir de una lista de comandos, popula la lista de caminos
       */
      void crearCaminosDesdeListaDeComandos(Cola<Comando*> * comandos);

      /**
       * Retorna lista de caminos
       */
      ListaEnlazada<Camino*> * obtenerCaminos();

      /**
       * Retorna instancia clase Mochila con todos los elementos encontrados en el camino
       */
      Mochila * obtenerMochila();

   private:

      /**
       * Lista con elementos levantados en el camino
       */
      Mochila * mochila;

      /**
       * Lista de caminos
       */
      ListaEnlazada<Camino*> * caminos;

      ListaEnlazada<Punto*> * empalmes;

      ListaEnlazada<Punto*> * bifurcaciones;

      /**
       * Agrega un elemento a la mochila
       */
      void agregarElementoAMochila(std::string elemento);


      void unirPuntos();

      void agregarCamino(Color * color, ListaEnlazada<InfoPunto*> * listaInfo);

      InfoPunto * obtenerInfoDeComando(std::string comando, std::string argumento, char orientacion);

      char obtenerOrientacionContraria(char orientacion);
};

#endif
