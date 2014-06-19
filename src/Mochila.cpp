#include "cabeceras/Mochila.h"

Mochila::Mochila() {
	this->items = new ListaEnlazada<ItemMochila*>();
}

void Mochila::agregar(std::string nombre) {
	if (this->existeItem(nombre)) {
		ItemMochila * item = this->obtenerItem(nombre);
		item->total++;

	} else {
		this->items->agregar(new ItemMochila(nombre));
	}
}

void Mochila::quitar(std::string nombre) {
	ItemMochila * aQuitar = this->obtenerItem(nombre);
	if (this->existeItem(nombre) && aQuitar->total > 0) {
		aQuitar->total--;

	} else
		throw "ERR: Se intenta tirar un elemento que no se encuentra en la mochila";
}

bool Mochila::existeItem(std::string nombre) {
	bool encontrado = false;
	this->items->iniciarCursor();
	while(!encontrado && this->items->avanzarCursor()) {
		encontrado = (this->items->obtenerCursor()->nombre == nombre);
	}
	return encontrado;
}

ItemMochila * Mochila::obtenerItem(std::string nombre) {
	ItemMochila * cursor;
	bool encontrado = false;
	this->items->iniciarCursor();
	while(!encontrado && this->items->avanzarCursor()) {
		cursor = this->items->obtenerCursor();
		encontrado = (cursor->nombre == nombre);
	}
	return cursor;
}

void Mochila::mostrar() {
	ItemMochila * cursor;
	this->items->iniciarCursor();
	while(this->items->avanzarCursor()) {
		cursor = this->items->obtenerCursor();
		if (cursor->total > 0) {
			std::cout << cursor->nombre;
			std::cout << ": ";
			std::cout << cursor->total << std::endl;
		}
	}
}
