#include "comando.h"

using namespace std;

Comando::Comando(string nombre, string argumento) {
   this->nombre = nombre;
   this->argumento = argumento;
   this->siguiente = NULL;
}

string Comando::obtenerNombre() {
   return this->nombre;
}

std::string Comando::obtenerArgumento() {
   return this->argumento;
}

Comando * Comando::obtenerSiguiente() {
   return this->siguiente;
}

void Comando::cambiarSiguiente(Comando * comando) {
   this->siguiente = comando;
}