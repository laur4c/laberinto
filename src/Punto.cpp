#include "Punto.h"
#include "util.h"

#include <iostream>

Punto::Punto(InfoPunto * info, Color * color) {
   this->color = color;
   this->informacion = info;
   this->dibujado = false;
   this->norte = NULL;
   this->sur = NULL;
   this->este = NULL;
   this->oeste = NULL;
}

bool Punto::tienePuntoEn(char orientacion) {
   bool resultado;
   switch(orientacion) {
      case 'N':
         resultado = this->tieneNorte();
         break;

      case 'S':
         resultado = this->tieneSur();
         break;

      case 'O':
         resultado = this->tieneOeste();
         break;

      case 'E':
         resultado = this->tieneEste();
         break;

      default:
         throw "ERR: Orientacion invalida";
   }
   return resultado;
}

bool Punto::tieneNorte() {
   return this->norte != NULL;
}

bool Punto::tieneSur() {
   return this->sur != NULL;
}

bool Punto::tieneOeste() {
   return this->oeste != NULL;
}

bool Punto::tieneEste() {
   return this->este != NULL;
}

Punto * Punto::obtenerPunto(char orientacion) {
   Punto * punto;
   switch(orientacion) {
      case 'N':
         punto = this->norte;
         break;

      case 'S':
         punto = this->sur;
         break;

      case 'O':
         punto = this->oeste;
         break;

      case 'E':
         punto = this->este;
         break;

      default:
         throw "ERR: Orientacion invalida";
   }
   return punto;
}

void Punto::cambiarPunto(char orientacion, Punto * punto) {
   if (orientacion == 'N')
      this->cambiarNorte(punto);
   else if(orientacion == 'S')
      this->cambiarSur(punto);
   else if(orientacion == 'O')
      this->cambiarOeste(punto);
   else if(orientacion == 'E')
      this->cambiarEste(punto);
}

Punto * Punto::obtenerNorte() {
   return this->obtenerPunto('N');
}

Punto * Punto::obtenerSur() {
   return this->obtenerPunto('S');
}

Punto * Punto::obtenerEste() {
   return this->obtenerPunto('E');
}

Punto * Punto::obtenerOeste() {
   return this->obtenerPunto('O');
}

void Punto::cambiarSur(Punto * punto) {
   this->sur = punto;
}

void Punto::cambiarNorte(Punto * punto) {
   this->norte = punto;
}

void Punto::cambiarEste(Punto * punto) {
   this->este = punto;
}

void Punto::cambiarOeste(Punto * punto) {
   this->oeste = punto;
}

InfoPunto * Punto::obtenerInformacion() {
   return this->informacion;
}

Color * Punto::obtenerColor() {
   return this->color;
}

void Punto::marcarComoDibujado() {
   this->dibujado = true;
}

bool Punto::estaDibujado() {
   return this->dibujado;
}

std::string Punto::aString() {
   std::string str = "";
   str += "Info: " + this->informacion->aString() + " \n";
   str += "dibujado: ";

   if (this->dibujado)
      str += "SI \n";
   else
      str += "NO \n";

   return str;
}
