#include "Mochila.h"

Mochila::Mochila () {
	this -> primernodo = NULL;
	this -> ultimonodo = NULL;
};

bool Mochila::esta_vacia() {
	return (this -> primernodo == NULL);
}

bool Mochila::existe_elemento (string elem_buscado) {
	NodoMochila* seeker = this -> primernodo;
	while ((seeker->siguiente != NULL) && (seeker->elemento != elem_buscado)) {
		seeker = seeker->siguiente;
	};
	this -> encontrado = seeker;
	
	return (seeker -> elemento == elem_buscado);
}

void Mochila::agregar_elemento(string elemento) {
	NodoMochila* nuevo = new NodoMochila(elemento);
	if (this->esta_vacia() ) {
		this -> primernodo = nuevo;
	}
	else {
		this -> ultimonodo -> siguiente = nuevo;		
	}
	this -> ultimonodo = nuevo;
	this -> tamanio++;
};

void Mochila::sumar_elemento (string elemento) {
	this -> encontrado -> cantidad ++;
};

void Mochila::tirar_elemento(string elem_buscado) {
	NodoMochila* anterior = NULL;
	NodoMochila* seeker = this -> primernodo;
	while (seeker->elemento != elem_buscado) {
		anterior = seeker;
		seeker = seeker->siguiente;
	};
	/* No valido el supuesto caso que el elemento no se encuentre ya que suponemos que se 
	usará correctamente en situaciones validas, es decir cuando haya al menos 1 elemento */
	if (seeker->cantidad == 1) {
		if (anterior != NULL) {
			anterior->siguiente = seeker->siguiente;
		}
		else {
			this -> primernodo = seeker -> siguiente;
		}
		delete seeker;
		this->tamanio--;
	}
	else {
		seeker->cantidad--;
	};
};

void Mochila::mostrar() {
 	NodoMochila* tmp = this->primernodo;
 	for (int count=1; count <= this->tamanio; count++) {
 		cout << "Objeto: " << tmp->elemento << "  Cantidad: " << tmp->cantidad << endl;
 		tmp = tmp->siguiente;
 	}
};

Mochila::~Mochila () {
	NodoMochila* seeker = this->primernodo;
	for ( int cont = 1; cont <= this->tamanio; cont++) {
		delete seeker;
		seeker = seeker->siguiente;
	}
};

