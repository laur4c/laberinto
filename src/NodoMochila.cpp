# include "cabeceras/NodoMochila.h"

NodoMochila::NodoMochila (string elemento) {
	this -> elemento = elemento;
	this -> cantidad = 1;
	this -> siguiente = NULL;
}
