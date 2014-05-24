#include "EasyBMP/EasyBMP.h"
#include "Estructura.cpp"
#include "ListaEnlazada.h"

class ImagenLaberinto {
   public:
      ImagenLaberinto(ListaEnlazada<Estructura*> * estructuras, int unidad = 5) {
         this->estructuras = estructuras;
         this->unidad = unidad;
      }

      void avanzarNorte(int &x, int &y, int total) {
         for (int i = 1; i <= total; i++) {
            this->dibujarUnidad(x, y);
            y = y - this->unidad;
         }
      }

      void avanzarSur(int &x, int &y, int total) {
         for (int i = 1; i <= total; i++) {
            this->dibujarUnidad(x, y);
            y = y + this->unidad;
         }
      }

      void avanzarOeste(int &x, int &y, int total) {
         for (int i = 1; i <= total; i++) {
            this->dibujarUnidad(x, y);
            x = x - this->unidad;
         }
      }

      void avanzarEste(int &x, int &y, int total) {
         for (int i = 1; i <= total; i++) {
            this->dibujarUnidad(x, y);
            x = x + this->unidad;
         }
      }

      void dibujar(NodoCasillero * nodo, int x, int y, int &maxAncho) {
         Casillero * casillero = nodo->obtenerDato();
         int pasos = casillero->obtenerCantidadDePasos();
         bool estaAvanzando = pasos > 0;
         if (pasos < 0)
            pasos = pasos * -1;

         // cout << "PASOS " << pasos << endl;
         cout << casillero->aString() << endl;

         if (pasos > 0) {
            switch(casillero->obtenerOrientacion()) {
               case 'N':
                  if (estaAvanzando)
                     this->avanzarNorte(x, y, pasos);
                  else
                     this->avanzarSur(x, y, pasos);
                  break;
               case 'S':
                  if (estaAvanzando)
                     this->avanzarSur(x, y, pasos);
                  else
                     this->avanzarNorte(x, y, pasos);
                  break;
               case 'E':
                  if (estaAvanzando)
                     this->avanzarEste(x, y, pasos);
                  else
                     this->avanzarOeste(x, y, pasos);
                  break;
               case 'O':
                  if (estaAvanzando)
                     this->avanzarOeste(x, y, pasos);
                  else
                     this->avanzarEste(x, y, pasos);
                  break;
            }
         }

         if (maxAncho < x) {
            maxAncho = x;
         }
         nodo->dibujado = true;
         if (!nodo->esUltimo()) {
            if (nodo->obtenerNorte() != NULL && !nodo->obtenerNorte()->dibujado) {
               this->dibujar(nodo->obtenerNorte(), x, y, maxAncho);
            }

            if (nodo->obtenerSur() != NULL && !nodo->obtenerSur()->dibujado) {
               this->dibujar(nodo->obtenerSur(), x, y, maxAncho);
            }

            if (nodo->obtenerOeste() != NULL && !nodo->obtenerOeste()->dibujado) {
               this->dibujar(nodo->obtenerOeste(), x, y, maxAncho);
            }

            if (nodo->obtenerEste() != NULL && !nodo->obtenerEste()->dibujado) {
               this->dibujar(nodo->obtenerEste(), x, y, maxAncho);
            }
         }
      }

      void generar() {
         // primero pinto uniones
         Estructura * estructura;
         int sum = 1000;

         int x = sum / 2;
         int y = x;
         int maxAncho = x;

         this->imagen.SetSize(sum, sum);

         this->estructuras->iniciarCursor();
         while(this->estructuras->avanzarCursor()) {
            if (this->estructuras->obtenerCursor()->tieneEmpalme()) {
               cout << "recorrido con union" << endl;
               estructura = this->estructuras->obtenerCursor();

               if (!estructura->primero->dibujado) {
                  this->dibujar(estructura->primero, x, y, maxAncho);
                  x = maxAncho;
               }

            }
         }

         x += 20;
         this->estructuras->iniciarCursor();
         while(this->estructuras->avanzarCursor()) {
            if (!this->estructuras->obtenerCursor()->tieneEmpalme()) {
               cout << "recorrido sin union" << endl;
               estructura = this->estructuras->obtenerCursor();

               if (!estructura->primero->dibujado) {
                  this->dibujar(estructura->primero, x, y, maxAncho);
                  x = maxAncho + 20;
               }

            }
         }

         this->imagen.WriteToFile("imagen.bmp");
      }

      void dibujarUnidad(int x, int y) {
         for (int i = 0; i < this->unidad; i++) {
            for (int j = 0; j < this->unidad; j++) {
               this->imagen(i + x, j + y)->Red = 255;
               this->imagen(i + x, j + y)->Green = 0;
               this->imagen(i + x, j + y)->Blue = 0;
            }
         }
      }

      ListaEnlazada<Estructura*> * estructuras;
      int unidad;
      BMP imagen;
};