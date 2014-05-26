#include <stdlib.h>
#include "cabeceras/ImagenLaberinto.h"


ImagenLaberinto::ImagenLaberinto(ListaEnlazada<Camino*> * caminos, int unidad) {
   this->caminos = caminos;
   this->unidad = unidad;
   this->colorObjeto = new Color(0, 0, 0);
   this->cargarOrientaciones();
}

void ImagenLaberinto::generar() {
   Camino * camino;
   Punto * comienzo;
   // Tomamos un valor arbitrario
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
            // Para separar un recorrido de otro, sumo un total arbitrario al ancho maximo alcanzado
            // despues de dibujar los recorridos con uniones entre si
            x = maxAncho + 20;
         }

      }
   }
   this->imagen.WriteToFile("laberinto.bmp");
}

void ImagenLaberinto::dibujar(Punto * punto, char orientacion, int x, int y, int &maxAncho) {
   InfoPunto * infoPunto = punto->obtenerInformacion();
   int pasos = infoPunto->obtenerCantidadDePasos();
   Color * color = punto->obtenerColor();

   if (pasos > 0) {
      switch(orientacion) {
         case 'N':
            if (infoPunto->hayObjeto()) {
               if (pasos > 1)
                  this->avanzarNorte(color, x, y, pasos - 1);

               this->avanzarNorte(this->colorObjeto, x, y, 1);

            } else
               this->avanzarNorte(color, x, y, pasos);

            break;
         case 'S':
            if (infoPunto->hayObjeto()) {
               if (pasos > 1)
                  this->avanzarSur(color, x, y, pasos - 1);

               this->avanzarSur(this->colorObjeto, x, y, 1);

            } else
               this->avanzarSur(color, x, y, pasos);

            break;
         case 'E':
            if (infoPunto->hayObjeto()) {
               if (pasos > 1)
                  this->avanzarEste(color, x, y, pasos - 1);

               this->avanzarEste(this->colorObjeto, x, y, 1);
            } else
               this->avanzarEste(color, x, y, pasos);

            break;
         case 'O':
            if (infoPunto->hayObjeto()) {
               if (pasos > 1)
                  this->avanzarOeste(color, x, y, pasos - 1);

               this->avanzarOeste(this->colorObjeto, x, y, 1);

            } else
               this->avanzarOeste(color, x, y, pasos);
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
      unaOrientacion = this->orientaciones[i];

      if (punto->tienePuntoEn(unaOrientacion) && !punto->obtenerPunto(unaOrientacion)->estaDibujado()) {
         info = punto->obtenerPunto(unaOrientacion)->obtenerInformacion();
         nvaOrientacion = info->obtenerOrientacion();

         // si dibujo al reves cambio la orientacion del punto, porque los caminos pueden ser recorridos desde
         // el comienzo o desde cualquiera de sus puntos
         if (nvaOrientacion != unaOrientacion)
            nvaOrientacion = util::obtener_orientacion_contraria(nvaOrientacion);

         if (pasos > 0)
            this->cambiarCoordenadasPorOrientacion(nvaOrientacion, x, y);

         this->dibujar(punto->obtenerPunto(unaOrientacion), nvaOrientacion, x, y, maxAncho);
      }
   }
}

void ImagenLaberinto::cambiarCoordenadasPorOrientacion(char orientacion, int &x, int &y) {
   switch (orientacion) {
      case 'N':
         y = y - this->unidad;
         break;

      case 'S':
         y = y + this->unidad;
         break;

      case 'E':
         x = x + this->unidad;
         break;

      case 'O':
         x = x - this->unidad;
         break;

      default:
         throw "ERR: Orientacion Invalida";
   }
}

void ImagenLaberinto::avanzarNorte(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      if (i != 1) y = y - this->unidad;

      this->dibujarUnidad(color, x, y);
   }
}

void ImagenLaberinto::avanzarSur(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      if (i != 1) y = y + this->unidad;

      this->dibujarUnidad(color, x, y);
   }
}

void ImagenLaberinto::avanzarOeste(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      if (i != 1) x = x - this->unidad;

      this->dibujarUnidad(color, x, y);
   }
}

void ImagenLaberinto::avanzarEste(Color * color, int &x, int &y, int total) {
   for (int i = 1; i <= total; i++) {
      if (i != 1) x = x + this->unidad;

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

void ImagenLaberinto::cargarOrientaciones() {
   this->orientaciones = new char[3];
   this->orientaciones[0] = 'N';
   this->orientaciones[1] = 'S';
   this->orientaciones[2] = 'E';
   this->orientaciones[3] = 'O';
}

