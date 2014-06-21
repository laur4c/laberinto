#include <stdlib.h>
#include "cabeceras/ImagenLaberinto.h"

ImagenLaberinto::ImagenLaberinto(Grafo<string> * grafo, int unidad) {
   this->grafo = grafo;
   this->unidad = unidad;
   this->colorNegro = new Color(0, 0, 0);
}

void ImagenLaberinto::imprimirVerticeCaminoMinimo(string datoVertice) {
   Vertice<string> * vertice = this->grafo->obtenerVertice(datoVertice);
   ListaEnlazada< Arista<string>* > * aristas;
   Tramo * tramo;
   Arista<string> * arista;
   ListaEnlazada<Tramo*> * tramos;
   bool cambiarSentido;

   if(vertice->tieneAnterior()) {
      this->imprimirVerticeCaminoMinimo(vertice->obtenerAnterior()->obtenerDato());

      int x, y;
      aristas = vertice->obtenerAnterior()->obtenerAristas();

      aristas->iniciarCursor();
      while(aristas->avanzarCursor()) {
         arista = aristas->obtenerCursor();

         if (arista->obtenerSalida()->obtenerDato() == vertice->obtenerDato()) {
            x = vertice->obtenerAnterior()->x;
            y = vertice->obtenerAnterior()->y;

            arista->marcarTramosComoNoDibujados();
            tramos = arista->obtenerTramos();
            tramos->iniciarCursor();

            while(tramos->avanzarCursor()) {
               tramo = tramos->obtenerCursor();

               if (!tramo->estaDibujado()) {
                  cambiarSentido = arista->enSentidoContrario;

                  this->dibujar(tramo, x, y, cambiarSentido, true);
                  tramo->marcarComoDibujado();
               }
            }
         }
      }

      this->imagen.WriteToFile("laberinto.bmp");
   }

}

void ImagenLaberinto::dibujarCaminoMinimo(string origen, string destino) {
   this->grafo->generarCaminosMinimos(origen);
   this->imprimirVerticeCaminoMinimo(destino);
}

void ImagenLaberinto::dibujar(Tramo * tramo, int &x, int &y, bool cambiarSentido, bool esCaminoMinimo) {
   int pasos = tramo->obtenerLongitud();
   Color * color = tramo->color;

   if (esCaminoMinimo) {
      color = this->colorNegro;
   }

   char orientacion = tramo->obtenerOrientacion();

   if (cambiarSentido) {
      orientacion = util::obtener_orientacion_contraria(orientacion);
   }

   switch(orientacion) {
      case 'N':
         if (tramo->tieneObjeto()) {
            this->avanzarNorte(this->colorNegro, x, y, 1);
            this->avanzarNorte(color, x, y, pasos - 1);

         } else
            this->avanzarNorte(color, x, y, pasos);

         break;
      case 'S':
         if (tramo->tieneObjeto()) {
            this->avanzarSur(this->colorNegro, x, y, 1);
            this->avanzarSur(color, x, y, pasos - 1);

         } else
            this->avanzarSur(color, x, y, pasos);

         break;
      case 'E':
         if (tramo->tieneObjeto()) {
            this->avanzarEste(this->colorNegro, x, y, 1);
            this->avanzarEste(color, x, y, pasos - 1);

         } else
            this->avanzarEste(color, x, y, pasos);

         break;
      case 'O':
         if (tramo->tieneObjeto()) {
            this->avanzarOeste(this->colorNegro, x, y, 1);
            this->avanzarOeste(color, x, y, pasos - 1);

         } else
            this->avanzarOeste(color, x, y, pasos);
         break;
   }
}

void ImagenLaberinto::generar() {
   SetEasyBMPwarningsOff();

   int sum = 1000;
   int tam = sum / 2;
   this->imagen.SetSize(sum, sum);
   int x = tam;
   int y = tam;

   this->grafo->marcarTodosLosVerticesComoNoVisitados();
   ListaEnlazada< Arista<string>* > * aristas;

   ListaEnlazada<Tramo*> * tramos;

   Vertice<string> * vertice = this->grafo->obtenerPrimerVertice();
   vertice->x = x;
   vertice->y = y;

   this->grafo->cola->acolar(vertice);

   Tramo * tramo;
   Arista<string> * arista;
   bool cambiarSentido;

   while(!this->grafo->cola->estaVacia()) {
      vertice = this->grafo->cola->desacolar();

      if (!vertice->fueVisitado()) {

         this->grafo->procesarVertice(vertice);
         vertice->marcarComoVisitado();

         aristas = vertice->obtenerAristas();
         aristas->iniciarCursor();
         while(aristas->avanzarCursor()) {
            arista = aristas->obtenerCursor();

            x = vertice->x;
            y = vertice->y;

            tramos = arista->obtenerTramos();
            tramos->iniciarCursor();
            while(tramos->avanzarCursor()) {
               tramo = tramos->obtenerCursor();

               if (!tramo->estaDibujado()) {
                  cambiarSentido = aristas->obtenerCursor()->enSentidoContrario;

                  this->dibujar(tramo, x, y, cambiarSentido, false);
                  tramo->marcarComoDibujado();
               }
            }

            if (arista->obtenerSalida()->x == 0 && arista->obtenerSalida()->y == 0) {
               arista->obtenerSalida()->y = y;
               arista->obtenerSalida()->x = x;
            }

         }
      }
   }

   this->imagen.WriteToFile("laberinto.bmp");
}

void ImagenLaberinto::avanzarNorte(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      y = y - this->unidad;
      this->dibujarUnidad(color, x, y);
   }
}

void ImagenLaberinto::avanzarSur(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      y = y + this->unidad;
      this->dibujarUnidad(color, x, y);
   }
}

void ImagenLaberinto::avanzarOeste(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      x = x - this->unidad;
      this->dibujarUnidad(color, x, y);
   }
}

void ImagenLaberinto::avanzarEste(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      x = x + this->unidad;
      this->dibujarUnidad(color, x, y);
   }
}

void ImagenLaberinto::dibujarUnidad(Color * color, int x, int y) {
   for (int i = 0; i < this->unidad; i++) {
      for (int j = 0; j < this->unidad; j++) {
         this->imagen(i + x, j + y)->Red = color->rojo;
         this->imagen(i + x, j + y)->Green = color->verde;
         this->imagen(i + x, j + y)->Blue = color->azul;
      }
   }
}


