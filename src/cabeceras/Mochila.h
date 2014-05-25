/*
		@author Ezequiel Guitler

		Coments: Mochila del caminante. Lista enlazada de objetos que levanta.

*/

#ifndef MOCHILA_H_
#define MOCHILA_H_

#include "NodoMochila.h"

class Mochila {

	private:
		NodoMochila* ultimonodo;
		NodoMochila* primernodo;
		NodoMochila* encontrado; // Cuando se busca un elemento en la mochila se guarda aca su dir
		string elemento;
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
		*	Post: Devuelve "True" si no hay elementos, y "False" si hay al menos un elemento en la mochila
		*
		*/
		bool esta_vacia();

		/*
		*
		*	Post: Devuelve "True" si el elemento está al menos una vez en la mochila, y "False" si no se encuentra.
		*
		*/
		bool existe_elemento(string elem_buscado);

		/*
		*
		*	Pre: El elemento no debe existir dentro de la mochila. ( Comprobar con "Existe_elemento()" )
		*	Post: Queda guardado el elemento dentro de la mochila
		*
		*/
		void agregar_elemento(string elemento);

		/*
		*
		*	Pre: El elemento ya debe existir dentro de la mochila al levantarlo ( Comprobar con "Existe_elemento()" )
		*	Post: Se suma una unidad a la cantidad del elemento.
		*
		*/
		void sumar_elemento(string elemento);

		/*
		*
		*	Pre: Tiene que haber en la mochila almenos 1 unidad del elemento que se desea tirar
		*	Post: Se elimina una unidad del elemento tirado. En caso que
		*		la unidad sea 1, el elemento es removido de la mochila.
		*
		*/
		void tirar_elemento(string elem_buscado);

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
