/*
		@author Ezequiel Guitler

		Coments: Mochila del caminante. Lista enlazada de objetos que levanta.

*/

#ifndef MOCHILA_H_
#define MOCHILA_H_

#include "Nodo.h"
#include "NodoMochila.h"

class Mochila {

	private:
		Nodo<NodoMochila*>* ultimonodo;
		Nodo<NodoMochila*>* primernodo;
		Nodo<NodoMochila*>* cursor;
		int tamanio;

	public:

		/*
		*
		*	Post: Queda creada la mochila sin elementos.
		*
		*/
		Mochila ();

		/*
		*
		*	Post: Devuelve "True" si no hay elementos en la mochila, y "False" si hay al menos uno.
		*
		*/
		bool esta_vacia();

		/*
		*
		*	Post: Devuelve "True" si el elemento está al menos una vez en la mochila, y "False" si no se encuentra.
		*			Luego de encontrarlo, se puede manipular ese elemento (agregar, sumar cantidad, tirar)
		*/
		bool buscar_elemento(string elem_buscado);

		/*
		*
		*	Pre: Primero utilizar "buscar_elemento". Solo utilizar si el metodo anterior devuelve FALSE.
		*	Post: Queda guardado el elemento dentro de la mochila
		*
		*/
		void agregar_elemento(string elemento);

		/*
		*
		*	Pre: Primero utilizar "buscar_elemento". Solo sumar en caso que el metodo anterior devuelva TRUE.
		*	Post: Se suma una unidad a la cantidad del elemento.
		*
		*/
		void sumar_elemento();

		string obtenerElemento();
		/*
		*
		*	Pre: Primero utilizar "buscar_elemento". El valor del metodo anterior, no influye.
		*	Post: Se elimina una unidad del elemento tirado. En caso que
		*		la unidad sea 1, el elemento es removido de la mochila.
		*
		*/
		void tirar_elemento();

		/*
		*
		*	Post: Imprime todos los elementos que contiene la mochila hasta el momento
		*
		*/
		void mostrar();


		/*
		*
		*	Post: Todos los elementos de la mochila quedan eliminados.
		*
		*/
		~Mochila ();

};

#endif /* MOCHILA_H_ */
