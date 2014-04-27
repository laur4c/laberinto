#include "lista_comandos.h"
#include <iostream>

using namespace std;

ListaComandos::ListaComandos() {
   this->primero = NULL;
   this->ultimo = NULL;
   this->tamanio = 0;
}

void ListaComandos::insertar(std::string nombreComando, std::string argumento) {
   Comando * comando = new Comando(nombreComando, argumento);
   if(this->primero == NULL) {
      this->primero = comando;
   } else {
      this->ultimo->cambiarSiguiente(comando);
   }
   this->tamanio++;
   this->ultimo = comando;
}

void ListaComandos::eliminar() {
   // falta implementar
}

bool ListaComandos::estaVacia() {
   return this->tamanio == 0;
}

int ListaComandos::obtenerTamanio() {
   return this->tamanio;
}

void ListaComandos::mostrar() {
   Comando * ultimoComando = this->primero;
   for (unsigned int i = 0; i < this->tamanio; i++) {
      cout << "nombre comando: " << ultimoComando->obtenerNombre();
      cout << ", argumento: " << ultimoComando->obtenerArgumento() << endl;

      ultimoComando = ultimoComando->obtenerSiguiente();
   }
}

ListaComandos::~ListaComandos() {
   while(this->tamanio < 0) {
      this->eliminar();
   }
}
