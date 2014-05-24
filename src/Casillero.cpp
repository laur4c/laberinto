#include "Casillero.h"
#include "util.h"
#include <sstream>
using namespace std;

Casillero::Casillero(char orientacion, int cantidadDePasos, bool objeto) {
   this->orientacion = orientacion;
   this->cantidadDePasos = cantidadDePasos;
   this->bifurcacion = "";
   this->empalme = "";
   this->objeto = objeto;
   this->punto = new Punto(0, 0);
}

void Casillero::cambiarXY(int x, int y) {
this->punto->cambiarXY(x, y);
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

std::string Casillero::aString() {
   string str = "";
   str += "Orientacion: " + util::char_a_string(this->orientacion) + " \n";
   str += "Pasos: " + util::int_a_string(this->cantidadDePasos) + " \n";
   str += "Bifurcacion: " + this->bifurcacion + " \n";
   str += "Empalme: " + this->empalme + " \n";
   str += "Punto: " + this->punto->aString() + " \n";
   str += "Tiene objeto: ";
   if (this->hayObjeto())
      str += "SI \n";
   else
      str += "NO \n";

   return str;
}

