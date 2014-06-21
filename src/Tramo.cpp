#include "cabeceras/Tramo.h"

Tramo::Tramo(char orientacion, int longitud, bool hayObjeto, Color * color) {
   this->orientacion = orientacion;
   this->longitud = longitud;
   this->hayObjeto = hayObjeto;
   this->color = color;
   this->dibujado = false;
}

void Tramo::marcarComoDibujado() {
   this->dibujado = true;
}

void Tramo::marcarComoNoDibujado() {
   this->dibujado = false;
}

bool Tramo::estaDibujado() {
   return this->dibujado;
}

char Tramo::obtenerOrientacion() {
   return this->orientacion;
}

int Tramo::obtenerLongitud() {
   return this->longitud;
}

bool Tramo::tieneObjeto() {
   return this->hayObjeto;
}
