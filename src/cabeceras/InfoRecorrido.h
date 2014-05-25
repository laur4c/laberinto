/*
		@author Ezequiel Guitler

		Coments: Micro programa independiente. No necesita descripcion.

*/

#ifndef INFORECORRIDO_H_
#define INFORECORRIDO_H_

#include <iostream>
using namespace std;

class InfoRecorrido {

	private:
		int cant_bifurcaciones;
		int cant_uniones;
		int cant_pasos;
		int cant_giros;

	public:

		/*
		*
		*	Post: Quedan inicializados los atributos en 0
		*
		*/
		InfoRecorrido();

		/*
		*
		*	Post: Suma 1 unidad a la cantidad de bifurcaciones
		*
		*/
		void sumar_bifurcacion();

		/*
		*
		*	Post: Suma 1 unidad a la cantidad de uniones
		*
		*/
		void sumar_union();

		/*
		*
		*	Post: Suma 1 unidad a la cantidad de pasos
		*
		*/
		void sumar_paso();

		/*
		*
		*	Post: Suma al total la cantidad de pasos indicada
		*
		*/
		void sumar_pasos(int pasos);

		/*
		*
		*	Post: Suma 1 unidad a la cantidad de giros
		*
		*/
		void sumar_giro();

		/*
		*
		*	Post: Imprime cada atributo con su cantidad hasta el momento
		*
		*/
		void mostrar();
};

#endif /* INFORECORRIDO_H_ */
