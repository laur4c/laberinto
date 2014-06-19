#include "cabeceras/InfoRecorrido.h"

InfoRecorrido::InfoRecorrido() {
	this->totalBifurcaciones = 0;
	this->totalUniones = 0;
	this->totalPasos = 0;
	this->totalGiros = 0;
}

void InfoRecorrido::agregarBifurcacion() {
	this->totalBifurcaciones++;
}

void InfoRecorrido::agregarUnion() {
	this->totalUniones++;
}

void InfoRecorrido::agregarPaso() {
	this->totalPasos++;
}

void InfoRecorrido::agregarPasos(int pasos) {
	this->totalPasos = this->totalPasos + pasos;
}

void InfoRecorrido::agregarGiro() {
	this->totalGiros++;
}

void InfoRecorrido::mostrar() {
	cout << "Total Pasos:         " << this->totalPasos << endl;
	cout << "Total Giros:         " << this->totalGiros << endl;
	cout << "Total Bifurcaciones: " << this->totalBifurcaciones << endl;
	cout << "Total Uniones:       " << this->totalUniones << endl;
}
