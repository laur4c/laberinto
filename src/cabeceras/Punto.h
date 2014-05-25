/**
   Laberinto - TP 1
   Representa un punto del laberinto.
   Tiene punteros a las cuatro direcciones posibles, para poder representar
   toda la estructura de los caminos.

   Cuando se generan los caminos en la clase Laberinto, los puntos se unen
   de acuerdo a las uniones y bifurcaciones que se indiquen desde el archivo de texto

   @author Mariano Cinalli
   @author Ezequiel Guitler
   @author Santiago Montiel
   @author Lucas Dreko
   @author Laura Corvalan
*/

#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <iostream>
#include "InfoPunto.h"
#include "Color.h"

class Punto {
   public:

      /**
       * Constructor
       * Se inicializan todos los punteros en NULL
       */
      Punto(InfoPunto * info, Color * color);

      /**
       * Retorna punto en la orientacion indicada
       */
      Punto * obtenerPunto(char orientacion);

      /**
       * Cambia punto en la orientacion indicada
       */
      void cambiarPunto(char orientacion, Punto * punto);

      /**
       * Retorna punto en la direccion norte
       */
      Punto * obtenerNorte();

      /**
       * Retorna punto en la direccion sur
       */
      Punto * obtenerSur();

      /**
       * Retorna punto en la direccion este
       */
      Punto * obtenerEste();

      /**
       * Retorna punto en la direccion oeste
       */
      Punto * obtenerOeste();

      /**
       * Retorna true si el punto en la orientacion indicada es distinto de NULL
       */
      bool tienePuntoEn(char orientacion);

      /**
       * Retorna true si el punto en la direccion norte es distinto de NULL
       */
      bool tieneNorte();

      /**
       * Retorna true si el punto en la direccion sur es distinto de NULL
       */
      bool tieneSur();

      /**
       * Retorna true si el punto en la direccion este es distinto de NULL
       */
      bool tieneEste();

      /**
       * Retorna true si el punto en la direccion oeste es distinto de NULL
       */
      bool tieneOeste();

      /**
       * Cambia punto en la direccion sur
       */
      void cambiarSur(Punto * punto);

      /**
       * Cambia punto en la direccion norte
       */
      void cambiarNorte(Punto * punto);

      /**
       * Cambia punto en la direccion este
       */
      void cambiarEste(Punto * punto);

      /**
       * Cambia punto en la direccion oeste
       */
      void cambiarOeste(Punto * punto);

      /**
       * Retorna info del punto. Una instancia de InfoPunto.
       */
      InfoPunto * obtenerInformacion();

      /**
       * Retorna color del punto
       */
      Color * obtenerColor();

      /**
       * Marcar punto como dibujado en la imagen (dibujado igual true).
       * Sirve para no dibujar dos veces el mismo punto.
       * ya que puedo recorrer los caminos unidos en todas las direcciones
       */
      void marcarComoDibujado();

      /**
       * Retorna true si esta el punto dibujado en la imagen
       */
      bool estaDibujado();

      /**
       * Retorna representacion en string del objeto
       */
      std::string aString();

   private:
         /**
          * Color del punto
          */
         Color * color;

         /**
          * Informacion del punto
          */
         InfoPunto * informacion;

         /**
          * Indica si el punto fue dibujado en la imagen o no
          */
         bool dibujado;

         /**
          * Punto en direccion norte
          */
         Punto * norte;

         /**
          * Punto en direccion sur
          */
         Punto * sur;

         /**
          * Punto en direccion este
          */
         Punto * este;

         /**
          * Punto en direccion oeste
          */
         Punto * oeste;
};

#endif