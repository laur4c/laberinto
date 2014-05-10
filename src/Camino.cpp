#include "Camino.h"
#include <iostream>

using namespace std;

Camino::Camino(Color * color) {
   this->color = color;
   this->recorrido = new ListaEnlazada<Casillero>();
   this->bifurcaciones = new ListaEnlazada<Bifurcacion>();
}

ListaEnlazada<Bifurcacion> * Camino::obtenerBifurcaciones() {
   return this->bifurcaciones;
}

ListaEnlazada<Casillero> * Camino::obtenerRecorrido() {
   return this->recorrido;
}

void Camino::agregarCasillero(char orientacion, int pasos, bool tieneObjeto, string bifurcacion, string empalme) {
   Casillero * casillero = new Casillero(orientacion, pasos, tieneObjeto);
   casillero->cambiarBifurcacion(bifurcacion);
   casillero->cambiarEmpalme(empalme);
   this->recorrido->agregar(casillero, this->recorrido->obtenerTamanio() + 1);
}

void Camino::agregarBifurcacion(string nombre, int x, int y) {
   Bifurcacion * bifurcacion = new Bifurcacion(nombre, x, y);
   this->bifurcaciones->agregar(bifurcacion, this->bifurcaciones->obtenerTamanio() + 1);
}

Camino::~Camino() {
   delete this->bifurcaciones;
   delete this->recorrido;
}

void Camino::mostrar() {
   cout << "Camino: " << endl;
   this->recorrido->mostrar();

   cout << "Bifurcaciones: " << endl;
   this->bifurcaciones->mostrar();
}

std::string Camino::aString() {
   string str = "\nCamino: ";
   str += "-------------------------------\n\n";

   Casillero * casillero;
   str += "Casilleros: \n\n";
   int tamanio = this->recorrido->obtenerTamanio();
   for (unsigned int i = 1; i <= tamanio; i++) {
      casillero = this->recorrido->obtenerElemento(i);
      str += casillero->aString() + "\n";
   }

   Bifurcacion * bifurcacion;
   str += "Bifurcaciones: \n\n";
   tamanio = this->bifurcaciones->obtenerTamanio();
   for (unsigned int j = 1; j <= tamanio; j++) {
      bifurcacion = this->bifurcaciones->obtenerElemento(j);
      str += bifurcacion->aString() + "\n";
   }

   return str;
}