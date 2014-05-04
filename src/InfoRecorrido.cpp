#include "InfoRecorrido.h"

InfoRecorrido::InfoRecorrido() {
	this -> cant_bifurcaciones = 0;
	this -> cant_uniones = 0;
	this -> cant_pasos = 0;
	this -> cant_giros = 0;
}

void InfoRecorrido::sumar_bifurcacion() {
	this->cant_bifurcaciones++;
}

void InfoRecorrido::sumar_union() {
	this->cant_uniones++;
}

void InfoRecorrido::sumar_paso() {
	this->cant_pasos++;
}

void InfoRecorrido::sumar_giro() {
	this->cant_giros++;
}

void InfoRecorrido::mostrar() {
	cout << "Cantidad de pasos:         " << this -> cant_pasos;
	cout << "Cantidad de giros:         " << this -> cant_giros;
	cout << "Cantidad de bifurcaciones: " << this -> cant_bifurcaciones;
	cout << "Cantidad de uniones:       " << this -> cant_uniones;
}
