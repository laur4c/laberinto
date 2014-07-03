#include "cabeceras/VerticeLaberinto.h"
#include <iostream>
VerticeLaberinto::VerticeLaberinto(std::string nombre, std::string dato) : Vertice<std::string,ListaEnlazada< Tramo* >*>(nombre, dato) {
   this->x = 0;
   this->y = 0;
}

void VerticeLaberinto::actualizarXY(int x, int y) {
   this->x = x;
   this->y = y;
}

int VerticeLaberinto::obtenerX() {
   return this->x;
}

int VerticeLaberinto::obtenerY() {
   return this->y;
}

bool VerticeLaberinto::tieneCoordenadas() {
   return (this->x != 0 && this->y != 0);
}

