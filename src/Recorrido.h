/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _RECORRIDO_H_
#define _RECORRIDO_H_

#include "Color.h"
#include "Casillero.h"
#include "ListaBifurcaciones.h"

#include <string>

class Recorrido {
   public:
      /**
       * Constructor
       */
      Recorrido(Color * color);

      /**
       * Retorna true si la lista esta vacia, false en caso contrario
       */
      bool estaVacia();

      /**
       * Agrega un elemento al final de la lista
       */
      void acolar(char orientacion, int pasos, bool objeto = false, std::string bifurcacion = "", std::string empalme = "");

      /**
       * Remueve un elemento del principio de la lista
       * @TODO
       * Falta implementar.
       * Que se retorna cuando el nodo no tiene solo un dato, sino varios?
       */
      void desacolar();

      /**
       * Retorna puntero a primer elemento de la lista
       */
      Casillero * obtenerFrente();

      /**
       * Retorna lista de bifurcaciones
       */
      ListaBifurcaciones * obtenerBifurcaciones();

      ~Recorrido();

   private:

      /**
       * Color del recorrido. La clase Color tiene solo tres atributos:
       * rojo, verde y azul
       */
      Color * color;

      /**
       * Puntero al primer elemento de la lista
       */
      Casillero * frente;

      /**
       * Puntero al ultimo elemento de la lista
       */
      Casillero * fondo;

      /**
       * Lista de bifurcaciones encontradas en el recorrido
       */
      ListaBifurcaciones * bifurcaciones;

      int ancho;

      int alto;
};

#endif