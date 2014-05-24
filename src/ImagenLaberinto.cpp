#include "EasyBMP/EasyBMP.h"
#include "Estructura.cpp"
#include "ListaEnlazada.h"

class ImagenLaberinto {
   public:
      ImagenLaberinto(ListaEnlazada<Estructura*> * estructuras, int unidad = 5) {
         this->estructuras = estructuras;
         this->unidad = unidad;
      }

      void avanzarNorte(Color * color, int &x, int &y, int total) {
         for (int i = 1; i <= total; i++) {
            this->dibujarUnidad(color, x, y);
            y = y - this->unidad;
         }
      }

      void avanzarSur(Color * color, int &x, int &y, int total) {
         for (int i = 1; i <= total; i++) {
            this->dibujarUnidad(color, x, y);
            y = y + this->unidad;
         }
      }

      void avanzarOeste(Color * color, int &x, int &y, int total) {
         for (int i = 1; i <= total; i++) {
            this->dibujarUnidad(color, x, y);
            x = x - this->unidad;
         }
      }

      void avanzarEste(Color * color, int &x, int &y, int total) {
         for (int i = 1; i <= total; i++) {
            this->dibujarUnidad(color, x, y);
            x = x + this->unidad;
         }
      }

      char obtenerContrario(char orientacion) {
         if (orientacion == 'S')
            return 'N';
         if (orientacion == 'N')
            return 'S';
         if (orientacion == 'E')
            return 'O';
         if (orientacion == 'O')
            return 'E';
         else
            return 'D';
      }

      void dibujar(NodoCasillero * nodo, char direccion, int x, int y, int &maxAncho) {
         Casillero * casillero = nodo->obtenerDato();
         int pasos = casillero->obtenerCantidadDePasos();
         bool estaAvanzando = pasos > 0;
         if (pasos < 0)
            pasos = pasos * -1;

         // cout << "PASOS " << pasos << endl;
         cout << nodo->dibujado << endl;
         cout << casillero->aString() << endl;
         if (pasos > 0) {
            switch(direccion) {
               case 'N':
                  if (estaAvanzando) {
                     this->avanzarNorte(nodo->color, x, y, pasos);
                  } else {
                     this->avanzarSur(nodo->color, x, y, pasos);
                  }

                  break;
               case 'S':
                  if (estaAvanzando)
                     this->avanzarSur(nodo->color, x, y, pasos);
                  else
                     this->avanzarNorte(nodo->color, x, y, pasos);
                  break;
               case 'E':
                  if (estaAvanzando)
                     this->avanzarEste(nodo->color, x, y, pasos);
                  else
                     this->avanzarOeste(nodo->color, x, y, pasos);
                  break;
               case 'O':
                  if (estaAvanzando)
                     this->avanzarOeste(nodo->color, x, y, pasos);
                  else
                     this->avanzarEste(nodo->color, x, y, pasos);
                  break;
            }
         }

         if (maxAncho < x) {
            maxAncho = x;
         }
         nodo->dibujado = true;
         // if (!nodo->esUltimo()) {
            if (nodo->obtenerNorte() != NULL && !nodo->obtenerNorte()->dibujado) {
cout << "RAMA AL NORTE" << endl;
// nodo->obtenerNorte()->obtenerDato()->orientacion = 'N';
               // si dibujo al reves cambio la orientacion del casillero !!!!
               if (nodo->obtenerNorte()->obtenerDato()->orientacion != 'N') {
                  direccion = this->obtenerContrario(nodo->obtenerNorte()->obtenerDato()->orientacion);
               } else {
                  direccion = nodo->obtenerNorte()->obtenerDato()->orientacion;
               }
cout << direccion << endl;
               this->dibujar(nodo->obtenerNorte(), direccion, x, y, maxAncho);

            }

            if (nodo->obtenerSur() != NULL && !nodo->obtenerSur()->dibujado) {
cout << "RAMA AL SUR" << endl;
// nodo->obtenerSur()->obtenerDato()->orientacion = 'S';
               if (nodo->obtenerSur()->obtenerDato()->orientacion != 'S') {
                  direccion = this->obtenerContrario(nodo->obtenerSur()->obtenerDato()->orientacion);
               } else {
                  direccion = nodo->obtenerSur()->obtenerDato()->orientacion;
               }
               cout << direccion << endl;
               this->dibujar(nodo->obtenerSur(), direccion, x, y, maxAncho);
            }

            if (nodo->obtenerOeste() != NULL && !nodo->obtenerOeste()->dibujado) {
cout << "RAMA AL OESTE" << endl;
cout << nodo->obtenerOeste()->obtenerDato()->orientacion << endl;
// nodo->obtenerOeste()->obtenerDato()->orientacion = 'O';
               if (nodo->obtenerOeste()->obtenerDato()->orientacion != 'O') {
                  direccion = this->obtenerContrario(nodo->obtenerOeste()->obtenerDato()->orientacion);
               } else {
                  direccion = nodo->obtenerOeste()->obtenerDato()->orientacion;
               }
cout << direccion << endl;
               this->dibujar(nodo->obtenerOeste(), direccion, x, y, maxAncho);
            }

            if (nodo->obtenerEste() != NULL && !nodo->obtenerEste()->dibujado) {

cout << "RAMA AL ESTE" << endl;

// nodo->obtenerEste()->obtenerDato()->orientacion = 'E';
               if (nodo->obtenerEste()->obtenerDato()->orientacion != 'E') {
                  direccion = this->obtenerContrario(nodo->obtenerEste()->obtenerDato()->orientacion);
               } else {
                  direccion = nodo->obtenerEste()->obtenerDato()->orientacion;
               }
cout << direccion << endl;
               this->dibujar(nodo->obtenerEste(), direccion, x, y, maxAncho);
            }
         // }
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
               // cout << "recorrido con union" << endl;
               estructura = this->estructuras->obtenerCursor();

               if (!estructura->primero->dibujado) {
                  this->dibujar(estructura->primero, estructura->primero->obtenerDato()->orientacion, x, y, maxAncho);
                  x = maxAncho;
               }

            }
         }

         x += 20;
         this->estructuras->iniciarCursor();
         while(this->estructuras->avanzarCursor()) {
            if (!this->estructuras->obtenerCursor()->tieneEmpalme()) {
               estructura = this->estructuras->obtenerCursor();

               if (!estructura->primero->dibujado) {
                  cout << "recorrido sin union" << endl;
                  this->dibujar(estructura->primero, estructura->primero->obtenerDato()->orientacion, x, y, maxAncho);
                  x = maxAncho + 20;
               }

            }
         }

         this->imagen.WriteToFile("imagen.bmp");
      }

      void dibujarUnidad(Color * color, int x, int y) {
         for (int i = 0; i < this->unidad; i++) {
            for (int j = 0; j < this->unidad; j++) {
               this->imagen(i + x, j + y)->Red = color->rojo;
               this->imagen(i + x, j + y)->Green = color->verde;
               this->imagen(i + x, j + y)->Blue = color->azul;
            }
         }
      }

      ListaEnlazada<Estructura*> * estructuras;
      int unidad;
      BMP imagen;
};