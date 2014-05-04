#include "casillero.h"

#include <sstream>
using namespace std;

Casillero::Casillero(char orientacion, int cantidadDePasos, bool objeto) {
   this->orientacion = orientacion;
   this->cantidadDePasos = cantidadDePasos;
   this->bifurcacion = "";
   this->empalme = "";
   this->objeto = objeto;

   this->siguiente = NULL;
   this->punto = new Punto(0, 0);
}

 void Casillero::cambiarXY(int x, int y) {
   this->punto->cambiarXY(x, y);
 }

Casillero * Casillero::obtenerSiguiente() {
   return this->siguiente;
}

void Casillero::cambiarSiguiente(Casillero * casillero) {
   this->siguiente = casillero;
}

std::string Casillero::obtenerBifurcacion() {
   return this->bifurcacion;
}

void Casillero::cambiarBifurcacion(std::string nombre)    {
   this->bifurcacion = nombre;
}

std::string Casillero::obtenerEmpalme() {
   return this->empalme;
}

void Casillero::cambiarEmpalme(std::string nombre) {
   this->empalme = nombre;
}

bool Casillero::hayObjeto() {
   return this->objeto == true;
}

std::string Casillero::aString() {
   stringstream str;

   stringstream x;
   x << this->punto->obtenerX();
   stringstream y;
   y << this->punto->obtenerY();

   str << "orientacion: " + this->orientacion;
   str << " (x, y): " + x.str() + ", " + y.str();
   if (this->bifurcacion != "")
     str << " bifurcacion: " + this->bifurcacion;

   if (this->empalme != "")
     str << " empalme: " + this->empalme;

   return str.str();
}