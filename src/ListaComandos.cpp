#include "ListaComandos.h"
#include <iostream>

using namespace std;

ListaComandos::ListaComandos() {
   this->frente = NULL;
   this->fondo = NULL;
   this->tamanio = 0;
}

void ListaComandos::acolar(std::string nombreComando, std::string argumento) {
   Comando * comando = new Comando(nombreComando, argumento);
   if(this->frente == NULL) {
      this->frente = comando;
   } else {
      this->fondo->cambiarSiguiente(comando);
   }
   this->tamanio++;
   this->fondo = comando;
}

void ListaComandos::desacolar() {
   // falta implementar
}

bool ListaComandos::estaVacia() {
   return this->tamanio == 0;
}

int ListaComandos::obtenerTamanio() {
   return this->tamanio;
}

Comando * ListaComandos::obtenerFrente() {
   return this->frente;
}

void ListaComandos::mostrar() {
   Comando * ultimoComando = this->frente;
   for (unsigned int i = 0; i < this->tamanio; i++) {
      cout << "nombre comando: " << ultimoComando->obtenerNombre();
      cout << ", argumento: " << ultimoComando->obtenerArgumento() << endl;

      ultimoComando = ultimoComando->obtenerSiguiente();
   }
}

ListaComandos::~ListaComandos() {
   while(this->tamanio < 0) {
      this->desacolar();
   }
}
