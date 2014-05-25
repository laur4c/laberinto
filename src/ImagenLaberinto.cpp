#include <stdlib.h>
#include "ImagenLaberinto.h"


ImagenLaberinto::ImagenLaberinto(ListaEnlazada<Camino*> * caminos, int unidad = 5) {
   this->caminos = caminos;
   this->unidad = unidad;
}

void ImagenLaberinto::dibujar(Punto * punto, char orientacion, int x, int y, int &maxAncho) {
   InfoPunto * infoPunto = punto->obtenerInformacion();
   int pasos = infoPunto->obtenerCantidadDePasos();

   bool estaAvanzando = pasos > 0; // o retrocede...
   pasos = abs(pasos);
   Color * color = punto->obtenerColor();

   if (pasos > 0) { // NOTE: algunos puntos (como las bifurcaciones por ej.) no avanzan ningun paso
      switch(orientacion) {
         case 'N':
            if (estaAvanzando) {
               this->avanzarNorte(color, x, y, pasos);
            } else {
               this->avanzarSur(color, x, y, pasos);
            }

            break;
         case 'S':
            if (estaAvanzando)
               this->avanzarSur(color, x, y, pasos);
            else
               this->avanzarNorte(color, x, y, pasos);
            break;

         case 'E':
            if (estaAvanzando)
               this->avanzarEste(color, x, y, pasos);
            else
               this->avanzarOeste(color, x, y, pasos);
            break;

         case 'O':
            if (estaAvanzando)
               this->avanzarOeste(color, x, y, pasos);
            else
               this->avanzarEste(color, x, y, pasos);
            break;
      }
   }

   punto->marcarComoDibujado();
   if (maxAncho < x) maxAncho = x; // maximo ancho del camino

   InfoPunto * info;
   char nvaOrientacion;
   char unaOrientacion;

   // dibujo ramas en todas las direcciones
   for (unsigned int i = 0; i < 4; i++) {
      unaOrientacion = orientaciones[i];

      if (punto->tienePuntoEn(unaOrientacion) && !punto->obtenerPunto(unaOrientacion)->estaDibujado()) {
         info = punto->obtenerPunto(unaOrientacion)->obtenerInformacion();
         nvaOrientacion = info->obtenerOrientacion();

         // si dibujo al reves cambio la orientacion del punto
         if (nvaOrientacion != unaOrientacion)
            nvaOrientacion = this->obtenerOrientacionContraria(nvaOrientacion);

         this->dibujar(punto->obtenerPunto(unaOrientacion), nvaOrientacion, x, y, maxAncho);
      }
   }
}

void ImagenLaberinto::generar() {
   Camino * camino;
   Punto * comienzo;
   int sum = 1000;

   int x = sum / 2;
   int y = x;
   int maxAncho = x;

   this->imagen.SetSize(sum, sum);

   // primero dibujo los caminos que tienen uniones
   this->caminos->iniciarCursor();
   while(this->caminos->avanzarCursor()) {
      if (this->caminos->obtenerCursor()->tieneEmpalme()) {
         camino = this->caminos->obtenerCursor();
         comienzo = camino->obtenerComienzo();

         if (!comienzo->estaDibujado()) {
            this->dibujar(comienzo, comienzo->obtenerInformacion()->obtenerOrientacion(), x, y, maxAncho);
            x = maxAncho;
         }
      }
   }

   // dibujo los caminos sin uniones
   x += 20;
   this->caminos->iniciarCursor();
   while(this->caminos->avanzarCursor()) {
      if (!this->caminos->obtenerCursor()->tieneEmpalme()) {
         camino = this->caminos->obtenerCursor();
         comienzo = camino->obtenerComienzo();

         if (!comienzo->estaDibujado()) {
            this->dibujar(comienzo, comienzo->obtenerInformacion()->obtenerOrientacion(), x, y, maxAncho);
            x = maxAncho + 20;
         }

      }
   }
   this->imagen.WriteToFile("laberinto.bmp");
}

void ImagenLaberinto::avanzarNorte(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      this->dibujarUnidad(color, x, y);
      y = y - this->unidad;
   }
}

void ImagenLaberinto::avanzarSur(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      this->dibujarUnidad(color, x, y);
      y = y + this->unidad;
   }
}

void ImagenLaberinto::avanzarOeste(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      this->dibujarUnidad(color, x, y);
      x = x - this->unidad;
   }
}

void ImagenLaberinto::avanzarEste(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      this->dibujarUnidad(color, x, y);
      x = x + this->unidad;
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

char ImagenLaberinto::obtenerOrientacionContraria(char orientacion) {
   char orientacionContraria;
   if (orientacion == 'S')
      orientacionContraria ='N';

   else if (orientacion == 'N')
      orientacionContraria = 'S';

   else if (orientacion == 'E')
      orientacionContraria = 'O';

   else if (orientacion == 'O')
      orientacionContraria = 'E';

   else
      throw "ERR: Orientacion Invalida";

   return orientacionContraria;
}

