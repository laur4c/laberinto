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
#include "ImagenLaberinto.h"

#include <iostream>
using namespace std;

class Laberinto {
   public:
      /**
       * Constructor.
       */
      Laberinto();

      /**
       * Crea grafo de acuerdo a las entradas del archivo de texto, que terminan siendo "comandos"
       * Los vertices pueden ser: el punto de llegada, punto de partida y bifurcaciones
       * Con el resto de los comandos se generan los tramos de cada arista, ya que la arista
       * no es una linea recta.
       */
      void generarDesdeListaDeComandos(Cola<Comando*> * comandos);

      /**
       * Imprime items en la mochila, en consola
       */
      void mostrarMochila();

      /**
       * Imprime info del recorrido
       */
      void mostrarInfo();

      void generarImagen();

      void dibujarCaminoMinimo(string origen, string destino);

      ~Laberinto();


   private:
      ImagenLaberinto * imagenLaberinto;

      /**
       * Lista con elementos levantados en el camino
       */
      Mochila * mochila;

      /**
       * Info del laberinto. Total uniones, bifurcaciones, etc.
       */
      InfoRecorrido * info;

      Grafo<ListaEnlazada <Tramo*>*, std::string> * grafo;

      void generarArista(Color * color, Cola<Comando*> * componentes, char ultimaOrientacion);
};

#endif
