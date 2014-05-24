#ifndef _NODO_CASILLERO_H_
#define _NODO_CASILLERO_H_
#include "Casillero.h"
#include <iostream>
#include "util.h"
using namespace std;

class NodoCasillero {
   public:
      bool dibujado;

      Color * color;

      NodoCasillero(Casillero * dato) {
         this->dato = dato;
         this->dibujado = false;
         this->norte = NULL;
         this->sur = NULL;
         this->este = NULL;
         this->oeste = NULL;
      }

      std::string aString() {
         string str = "";
         str += "DATO: " + this->dato->aString() + " \n";
         str += "dibujado: ";

         if (this->dibujado)
            str += "SI \n";
         else
            str += "NO \n";

         return str;
      }

      bool esUltimo() {
         return (this->norte == NULL) && (this->sur == NULL) && (this->este == NULL) && (this->oeste == NULL);
      }

      NodoCasillero * obtenerNodo(char orientacion) {
         if (orientacion == 'N')
            return this->norte;
         else if(orientacion == 'S')
            return this->sur;
         else if(orientacion == 'O')
            return this->oeste;
         else if(orientacion == 'E')
            return this->este;
         else
            throw "ERR: Orientacion invalida";
      }

      void cambiarNodo(char orientacion, NodoCasillero * nodo) {
         if (orientacion == 'N')
            return this->cambiarNorte(nodo);
         else if(orientacion == 'S')
            return this->cambiarSur(nodo);
         else if(orientacion == 'O')
            return this->cambiarOeste(nodo);
         else if(orientacion == 'E')
            return this->cambiarEste(nodo);
      }

      NodoCasillero * obtenerNorte() {
         return this->obtenerNodo('N');
      }

      NodoCasillero * obtenerSur() {
         return this->obtenerNodo('S');
      }

      NodoCasillero * obtenerEste() {
         return this->obtenerNodo('E');
      }

      NodoCasillero * obtenerOeste() {
         return this->obtenerNodo('O');
      }

      void cambiarSur(NodoCasillero * nodo) {
         this->sur = nodo;
      }

      void cambiarNorte(NodoCasillero * nodo) {
         this->norte = nodo;
      }

      void cambiarEste(NodoCasillero * nodo) {
         this->este = nodo;
      }

      void cambiarOeste(NodoCasillero * nodo) {
         this->oeste = nodo;
      }

      Casillero * obtenerDato() {
         return this->dato;
      }

   private:
      Casillero * dato;

      NodoCasillero * norte;

      NodoCasillero * sur;

      NodoCasillero * este;

      NodoCasillero * oeste;


};

#endif