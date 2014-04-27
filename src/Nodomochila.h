#ifndef NODOMOCHILA_H_
#define NODOMOCHILA_H_
#include <iostream>
#include <string>
using namespace std;

class nodomochila {
	
	private:
		string nuevo_objeto;
		int cantidad;
		nodomochila* siguiente;
		
	public:
		/*
		*	Post: queda creado el nodo donde se guardara la info del objeto nuevo
		*
		*/
		nodomochila(string nuevo_objeto);

	friend class mochila;		
};

#endif /* NODOMOCHILA_H_ */
