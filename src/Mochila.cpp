#include "Mochila.h"

mochila::mochila () {
	this -> ultimonodo = NULL;
	this -> primernodo = NULL;
};

void mochila::agregarobjeto(string nuevo_objeto) {
	nodomochila* nuevo = new nodomochila(nuevo_objeto);
	this -> ultimonodo = nuevo;
};

string mochila::mostrar() {
	return (this -> nuevo_objeto);
}

