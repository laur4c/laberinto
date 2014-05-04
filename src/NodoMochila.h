/*
		@author Ezequiel Guitler
		
		Coments: Micro programa (parte de "Mochila"). Definicion de cada Nodo.

*/

#ifndef NODOMOCHILA_H_
#define NODOMOCHILA_H_

#include <iostream>
#include <string>
using namespace std;

class NodoMochila {
	
	private:
		string elemento;
		int cantidad;
		NodoMochila* siguiente;
		
	public:
		
		/*
		*
		*	Post: queda creado el nodo donde se guardara la info del objeto nuevo
		*
		*/
		NodoMochila(string elemento);

	friend class Mochila;		
};

#endif /* NODOMOCHILA_H_ */
