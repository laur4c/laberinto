#include "Recorrido.h"
#include <iostream>

using namespace std;

Recorrido::Recorrido(Color * color) {
   this->color = color;
   this->camino = new ListaEnlazada<Casillero>();
   this->bifurcaciones = new ListaEnlazada<Bifurcacion>();
}

ListaEnlazada<Bifurcacion> * Recorrido::obtenerBifurcaciones() {
   return this->bifurcaciones;
}

ListaEnlazada<Casillero> * Recorrido::obtenerCamino() {
   return this->camino;
}

void Recorrido::agregarCasillero(char orientacion, int pasos, bool tieneObjeto, string bifurcacion, string empalme) {
   Casillero * casillero = new Casillero(orientacion, pasos, tieneObjeto);
   casillero->cambiarBifurcacion(bifurcacion);
   casillero->cambiarEmpalme(empalme);
   this->camino->agregar(casillero, this->camino->obtenerTamanio() + 1);
}

void Recorrido::agregarBifurcacion(string nombre, int x, int y) {
   Bifurcacion * bifurcacion = new Bifurcacion(nombre, x, y);
   this->bifurcaciones->agregar(bifurcacion, this->bifurcaciones->obtenerTamanio() + 1);
}

Recorrido::~Recorrido() {
   delete this->bifurcaciones;
   delete this->camino;
}

void Recorrido::mostrar() {
   cout << "Camino: " << endl;
   this->camino->mostrar();

   cout << "Bifurcaciones: " << endl;
   this->bifurcaciones->mostrar();
}

std::string Recorrido::aString() {
   string str = "\nRecorrido: ";
   str += "-------------------------------\n\n";

   Casillero * casillero;
   str += "Casilleros: \n\n";
   int tamanio = this->camino->obtenerTamanio();
   for (unsigned int i = 1; i <= tamanio; i++) {
      casillero = this->camino->obtenerElemento(i);
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