#include <stdlib.h>
#include "cabeceras/ImagenLaberinto.h"

ImagenLaberinto::ImagenLaberinto(Grafo<string> * grafo, int unidad) {
   this->grafo = grafo;
   this->unidad = unidad;
   this->colorNegro = new Color(0, 0, 0);
}

void ImagenLaberinto::recorrerTramos(ListaEnlazada<Tramo*> * tramos, bool cambiarSentido, int &x, int &y) {
   Tramo * tramo;
   tramos->iniciarCursor();

   while(tramos->avanzarCursor()) {
      tramo = tramos->obtenerCursor();

      if (!tramo->estaDibujado()) {
         this->dibujar(tramo, x, y, cambiarSentido);
         tramo->marcarComoDibujado();
      }
   }
}

void ImagenLaberinto::recorrerAristas(Vertice<string> * vertice, int &x, int &y) {
   Arista<string> * arista;
   ListaEnlazada< Arista<string>* > * aristas = vertice->obtenerAristas();
   aristas->iniciarCursor();
   while(aristas->avanzarCursor()) {
      arista = aristas->obtenerCursor();

      // seteo x, y con las coordenadas del vertice
      x = vertice->obtenerX();
      y = vertice->obtenerY();
      // Porque al generar el grafo se crean las aristas
      // en el sentido qeu indica el archivo de entrada
      // y en el sentido contrario, para poder llegar a todos los vertices
      this->recorrerTramos(arista->obtenerTramos(), arista->dibujarEnSentidoContrario(), x, y);

      // Las coordenadas finales del tramo son las coordenadas del proximo vertice
      if (!arista->obtenerSalida()->tieneCoordenadas()) {
         arista->obtenerSalida()->actualizarXY(x, y);
      }
   }
}

void ImagenLaberinto::generar() {
   SetEasyBMPwarningsOff();

   int sum = 1000;
   int tam = sum / 2;
   this->imagen.SetSize(sum, sum);
   int x = tam;
   int y = tam;

   this->grafo->iniciarRecorridoEnAnchura();
   Vertice<string> * vertice = this->grafo->obtenerPrimerVertice();
   vertice->actualizarXY(x, y);

   while(this->grafo->avanzarRecorridoEnAnchura()) {
      vertice = this->grafo->obtenerVerticeRecorridoActual();
      this->recorrerAristas(vertice, x, y);
   }

   this->imagen.WriteToFile("laberinto.bmp");
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

void ImagenLaberinto::dibujarCaminoMinimo(string origen, string destino) {
   this->grafo->generarCaminosMinimos(origen);
   this->dibujarCaminoMinimo(destino);
}

void ImagenLaberinto::dibujarCaminoMinimo(string datoVertice) {
   Vertice<string> * vertice = this->grafo->obtenerVertice(datoVertice);
   if(vertice->tieneAnterior()) {
      this->dibujarCaminoMinimo(vertice->obtenerAnterior()->obtenerDato());

      int x, y;
      this->recorrerAristasCaminoMinimo(vertice, x, y);
      this->imagen.WriteToFile("laberinto.bmp");
   }
}

void ImagenLaberinto::recorrerTramosCaminoMinimo(ListaEnlazada<Tramo*> * tramos, bool cambiarSentido, int &x, int &y) {
   Tramo * tramo;
   tramos->iniciarCursor();

   while(tramos->avanzarCursor()) {
      tramo = tramos->obtenerCursor();

      if (!tramo->estaDibujado()) {
         this->dibujar(tramo, x, y, cambiarSentido, true);
         tramo->marcarComoDibujado();
      }
   }
}

void ImagenLaberinto::recorrerAristasCaminoMinimo(Vertice<string> * vertice, int &x, int &y) {
   Arista<string> * arista;
   ListaEnlazada< Arista<string>* > * aristas = vertice->obtenerAnterior()->obtenerAristas();

   aristas->iniciarCursor();
   while(aristas->avanzarCursor()) {
      arista = aristas->obtenerCursor();

      if (arista->obtenerSalida()->obtenerDato() == vertice->obtenerDato()) {
         x = vertice->obtenerAnterior()->obtenerX();
         y = vertice->obtenerAnterior()->obtenerY();

         arista->marcarTramosComoNoDibujados();
         this->recorrerTramosCaminoMinimo(arista->obtenerTramos(), arista->dibujarEnSentidoContrario(), x, y);
      }
   }
}

ImagenLaberinto::~ImagenLaberinto() {
   delete this->colorNegro;
}

