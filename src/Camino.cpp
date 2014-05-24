#include "Camino.h"
#include <iostream>

using namespace std;

Camino::Camino(Color * color) {
   this->color = color;
   this->recorrido = new ListaEnlazada<Casillero*>();
   this->bifurcaciones = new ListaEnlazada<Bifurcacion*>();
   this->empalmes = new ListaEnlazada<Bifurcacion*>();
}

Color * Camino::obtenerColor() {
   return this->color;
}

ListaEnlazada<Bifurcacion*> * Camino::obtenerBifurcaciones() {
   return this->bifurcaciones;
}

ListaEnlazada<Casillero*> * Camino::obtenerRecorrido() {
   return this->recorrido;
}

void Camino::agregarCasillero(char orientacion, int pasos, bool tieneObjeto, string bifurcacion, string empalme) {
   Casillero * casillero = new Casillero(orientacion, pasos, tieneObjeto);
   casillero->cambiarBifurcacion(bifurcacion);
   casillero->cambiarEmpalme(empalme);
   this->recorrido->agregar(casillero);
}

void Camino::agregarBifurcacion(string nombre, int x, int y) {
   Bifurcacion * bifurcacion = new Bifurcacion(nombre, x, y);
   this->bifurcaciones->agregar(bifurcacion);
}

void Camino::agregarEmpalme(string nombre, int x, int y) {
   Bifurcacion * empalme = new Bifurcacion(nombre, x, y);
   this->empalmes->agregar(empalme);
}

bool Camino::tieneEmpalmes() {
   return !this->empalmes->estaVacia();
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
   for (int i = 1; i <= tamanio; i++) {
      casillero = this->recorrido->obtenerElemento(i);
      str += casillero->aString() + "\n";
   }

   Bifurcacion * bifurcacion;
   str += "Bifurcaciones: \n\n";
   tamanio = this->bifurcaciones->obtenerTamanio();
   for (int j = 1; j <= tamanio; j++) {
      bifurcacion = this->bifurcaciones->obtenerElemento(j);
      str += bifurcacion->aString() + "\n";
   }

   return str;
}