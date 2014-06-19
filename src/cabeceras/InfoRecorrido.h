#ifndef _INFO_RECORRIDO_H_
#define _INFO_RECORRIDO_H_

#include <iostream>
using namespace std;

class InfoRecorrido {

	private:
		int totalBifurcaciones;
		int totalUniones;
		int totalPasos;
		int totalGiros;

	public:

		InfoRecorrido();

		void agregarBifurcacion();

		void agregarUnion();

		void agregarPaso();

		void agregarPasos(int pasos);

		void agregarGiro();

		void mostrar();
};

#endif
