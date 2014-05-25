# include "cabeceras/NodoMochila.h"

NodoMochila::NodoMochila (string elemento) {
	this -> elemento = elemento;
	this -> cantidad = 1;
}

void NodoMochila::mod_elemento (string elemento) {
	this->elemento = elemento;
}

string NodoMochila::obtenerElemento() {
	return (this->elemento);
}

int NodoMochila::obtenerCantidad() {
	return (this->cantidad);
}

void NodoMochila::sumarCantidad() {
	this->cantidad++;
}

void NodoMochila::restarCantidad() {
	this->cantidad--;
}
