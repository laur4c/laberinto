#include "cabeceras/NodoMochila.h"
#include "cabeceras/Mochila.h"

Mochila::Mochila () {
	this -> primernodo = NULL;
	this -> ultimonodo = NULL;
	this -> cursor = NULL;
	this->tamanio = 0;
};

bool Mochila::esta_vacia() {
	return (this -> primernodo == NULL);
}

bool Mochila::buscar_elemento (string elem_buscado) {
	this->cursor = this->primernodo;
	int pos = 1;

	while ((pos <= this->tamanio) && (this->cursor->obtenerDato()->obtenerElemento() != elem_buscado)) {
		this->cursor = this->cursor->obtenerSiguiente();
	}

	return (this->cursor->obtenerDato()->obtenerElemento() == elem_buscado);
}


void Mochila::agregar_elemento(string elemento) {
	Nodo<NodoMochila*>* nuevo = new Nodo<NodoMochila*>(new NodoMochila(elemento));

	if (this->esta_vacia() ) {
		this -> primernodo = nuevo;
	}
	else {
		this -> ultimonodo->cambiarSiguiente(nuevo);
	}
	this -> ultimonodo = nuevo;
	this -> tamanio++;
};

void Mochila::sumar_elemento () {
	this -> cursor->obtenerDato()->sumarCantidad();
};

string Mochila::obtenerElemento(){
	return (this->cursor->obtenerDato()->obtenerElemento());
}

void Mochila::tirar_elemento() {

	if (this->cursor->obtenerDato()->obtenerCantidad() > 1) {
		this->cursor->obtenerDato()->restarCantidad();
	}
	else {
		Nodo<NodoMochila*>* auxSig = this->cursor->obtenerSiguiente();
		Nodo<NodoMochila*>* auxAnt = this->cursor->obtenerAnterior();
		if (auxAnt == NULL) { // Eliminando primero
			this->primernodo = this->cursor->obtenerSiguiente();
			auxSig->cambiarAnterior(NULL);
		}
		else {
			auxAnt->cambiarSiguiente(this->cursor->obtenerSiguiente());
			auxSig->cambiarAnterior(this->cursor->obtenerAnterior());
		}

		delete this->cursor;
	}
};

void Mochila::mostrar() {
 	this->cursor = this->primernodo;
 	int pos =1;
 	while (pos <= this->tamanio) {
 		cout << "Objeto: " << this->cursor->obtenerDato()->obtenerElemento() << "  Cantidad: " << this->cursor->obtenerDato()->obtenerCantidad() << endl;
 		this->cursor = this->cursor->obtenerSiguiente();
 	}
};

Mochila::~Mochila () {
	int pos = 1;
	this->cursor = this->primernodo;
 	while (pos <= this->tamanio) {
		delete this->cursor;
		this->cursor = this->cursor->obtenerSiguiente();
	}
};

