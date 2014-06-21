/**
   Laberinto - TP 1
   Se utiliza la libreria EasyBMP para pasar los caminos del laberinto
   a una imagen de formato BMP.
   La imagen se guarda en el directorio desde donde se ejecuta el programa
   El nombre de la imagen es: laberinto.bmp

   @author Laura Corvalan
*/

#ifndef _IMAGEN_LABERINTO_H_
#define _IMAGEN_LABERINTO_H_

#include "../EasyBMP/EasyBMP.h"
#include "util.h"

#include "Camino.h"
#include "Color.h"
#include "Tramo.h"
#include "ListaEnlazada.h"
#include <string>

#include "Grafo.h"

class ImagenLaberinto {
   public:
      /**
       * Constructor
       * @param caminos Lista de caminos. Representacion de todo el laberinto
       * @param unidad Tamanio de la unidad, por default: 3x3
       */
      // ImagenLaberinto(ListaEnlazada<Camino*> * caminos, int unidad = 3);
      ImagenLaberinto(Grafo<string> * grafo, int unidad = 3);

      /**
       * Generar imagen de caminos del laberinto
       * La imagen se guarda en el directorio actual con el nombre: laberinto.bmp
       */
      void generar(ListaEnlazada<string> * puntosDePartida);


      void imprimirVerticeCaminoMinimo(string datoVertice);

      void dibujarCaminoMinimo(string origen, string destino);

   private:
      /**
       * Lista de caminos que representan todo el laberinto
       */
      // ListaEnlazada<Camino*> * caminos;
      Grafo<string> * grafo;

      /**
       * Tamanio de unidad de mapa.
       * Valor por default: 3x3
       */
      int unidad;

      /**
       * Mapa del laberinto
       */
      BMP imagen;

      /**
       * Color que se va a usar para pintar los objetos
       */
      Color * colorObjeto;

      /**
       * Array con orientaciones posibles: 'N', 'O', 'S', 'E'
       */
      char * orientaciones;

      /**
       * Dibuja en mapa total de unidades hacia el norte
       *
       * @param color Color de la unidad
       * @param x
       * @param y
       * @param total Total de unidades a avanzar
       */
      void avanzarNorte(Color * color, int &x, int &y, int total);

      /**
       * Dibuja en mapa total de unidades hacia el sur
       *
       * @param color Color de la unidad
       * @param x
       * @param y
       * @param total Total de unidades a avanzar
       */
      void avanzarSur(Color * color, int &x, int &y, int total);

      /**
       * Dibuja en mapa total de unidades hacia el oeste
       *
       * @param color Color de la unidad
       * @param x
       * @param y
       * @param total Total de unidades a avanzar
       */
      void avanzarOeste(Color * color, int &x, int &y, int total);

      /**
       * Dibuja en mapa total de unidades hacia el este
       *
       * @param color Color de la unidad
       * @param x
       * @param y
       * @param total Total de unidades a avanzar
       */
      void avanzarEste(Color * color, int &x, int &y, int total);

      /**
       * Modifica las coordenadas segun a que orientacion me vaya a mover
       */
      void cambiarCoordenadasPorOrientacion(char orientacion, int &x, int &y);

      /**
       * Este metodo se encarga de dibujar el punto y las ramas del mismo
       * en todas las direcciones recursivamente
       *
       * @param punto Punto a dibujar
       * @param x
       * @param y
       * @param maxAncho Sirve para calcular cual es el ancho maximo del camino que
       * se esta dibujando, para luego poder calcular donde dibujar los proximos caminos,
       * si los hubiere
       *
       */
      // void dibujar(Punto * punto, char orientacion, int x, int y, int &maxAncho);
      void dibujar(Tramo * tramo, int &x, int &y, bool cambiarSentido, bool esCaminoMinimo);

      /**
       * Dibuja una unica unidad en la imagen
       */
      void dibujarUnidad(Color * color, int x, int y);

      /**
       * Carga el array de orientaciones. Este atributo se ultiza en el metodo dibujar()
       * Para dibujar las uniones de los puntos en todas las direcciones
       */
      void cargarOrientaciones();
};
#endif