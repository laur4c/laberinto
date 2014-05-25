/**
   Laberinto - TP 1


   @author Mariano Cinalli
   @author Ezequiel Guitler
   @author Santiago Montiel
   @author Lucas Dreko
   @author Laura Corvalan
*/

#ifndef _LABERINTO_H_
#define _LABERINTO_H_

#include "util.h"

#include "Mochila.h"
#include "Comando.h"
#include "Camino.h"

#include "ListaEnlazada.h"
#include "InfoRecorrido.h"
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

      /**
       * Imprime info del recorrido
       */
      void mostrarInfo();

   private:

      /**
       * Lista con elementos levantados en el camino
       */
      Mochila * mochila;

      /**
       * Lista de caminos
       */
      ListaEnlazada<Camino*> * caminos;

      /**
       * Lista con todas las uniones del laberinto
       */
      ListaEnlazada<Punto*> * empalmes;

      /**
       * Lista con todas las bifurcaciones del laberinto
       */
      ListaEnlazada<Punto*> * bifurcaciones;

      /**
       * Info del laberinto. Total uniones, bifurcaciones, etc.
       */
      InfoRecorrido * info;

      /**
       * Agrega un elemento a la mochila
       */
      void agregarElementoAMochila(std::string elemento);

      /**
       * Recorre todos los puntos donde hay uniones (this->empalmes)
       * y los une a las correspondientes bifurcaciones (this->bifurcaciones)
       */
      void unirPuntos();

      /**
       * Agrega un camino a la lista de caminos en base a toda la info obtenida de
       * procesar toda la lista de comandos
       */
      void agregarCamino(Color * color, ListaEnlazada<InfoPunto*> * listaInfo);

      /**
       * Retorna una instancia de InfoPunto en base al comando procesado y su argumento
       */
      InfoPunto * obtenerInfoDeComando(std::string comando, std::string argumento, char orientacion);

      /**
       * Retorna orientacion contraria. Por ej. si orientacion = 'N', entonces el valor retornado es: 'S'
       */
      char obtenerOrientacionContraria(char orientacion);
};

#endif
