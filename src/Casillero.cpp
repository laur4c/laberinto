#include "Casillero.h"

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

char Casillero::obtenerOrientacion() {
   return this->orientacion;
}

Punto * Casillero::obtenerPunto() {
   return this->punto;
}

int Casillero::obtenerCantidadDePasos() {
   return this->cantidadDePasos;
}

bool Casillero::hayObjeto() {
   return this->objeto == true;
}
