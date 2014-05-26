#include "cabeceras/InfoPunto.h"
#include "cabeceras/util.h"

#include <sstream>
using namespace std;

InfoPunto::InfoPunto(char orientacion, int cantidadDePasos, bool objeto) {
   this->orientacion = orientacion;
   this->cantidadDePasos = cantidadDePasos;
   this->bifurcacion = "";
   this->bifurcacionOrientacion = ' '; // invalida
   this->empalme = "";
   this->objeto = objeto;
}

std::string InfoPunto::obtenerBifurcacion() {
   return this->bifurcacion;
}

char InfoPunto::obtenerOrientacionDeBifurcacion() {
   return this->bifurcacionOrientacion;
}

bool InfoPunto::tieneBifurcacion() {
   return this->bifurcacion != "";
}

void InfoPunto::cambiarBifurcacion(std::string nombre, char orientacion)    {
   this->bifurcacion = nombre;
   this->bifurcacionOrientacion = orientacion;
}

std::string InfoPunto::obtenerEmpalme() {
   return this->empalme;
}

bool InfoPunto::tieneEmpalme() {
   return this->empalme != "";
}

void InfoPunto::cambiarEmpalme(std::string nombre) {
   this->empalme = nombre;
}

char InfoPunto::obtenerOrientacion() {
   return this->orientacion;
}

int InfoPunto::obtenerCantidadDePasos() {
   return this->cantidadDePasos;
}

void InfoPunto::marcarConObjeto() {
   this->objeto = true;
}

bool InfoPunto::hayObjeto() {
   return this->objeto == true;
}

std::string InfoPunto::aString() {
   string str = "";
   str += "Orientacion: " + util::char_a_string(this->orientacion) + " \n";
   str += "Pasos: " + util::int_a_string(this->cantidadDePasos) + " \n";
   str += "Bifurcacion: " + this->bifurcacion + " " + util::char_a_string(this->bifurcacionOrientacion) + " \n" ;
   str += "Empalme: " + this->empalme + " \n";
   str += "Tiene objeto: ";
   if (this->hayObjeto())
      str += "SI \n";
   else
      str += "NO \n";

   return str;
}

