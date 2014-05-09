#include "Comando.h"

using namespace std;

Comando::Comando(string nombre, string argumento) {
   this->nombre = nombre;
   this->argumento = argumento;
}

string Comando::obtenerNombre() {
   return this->nombre;
}

std::string Comando::obtenerArgumento() {
   return this->argumento;
}

std::string Comando::aString() {
   return "Nombre: " + this->nombre + " Argumento: " + this->argumento;
}
