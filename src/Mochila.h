#ifndef MOCHILA_H_
#define MOCHILA_H_

#include "Nodomochila.h"

class mochila {
	
	private:
		nodomochila* ultimonodo;
		nodomochila* primernodo;
		string nuevo_objeto;
		
	public:
		
		/*
		*	Post: Queda inicializada la mochila sin nodos todavia.
		*			por lo que los punteros ultimonodo y primernodo apuntan a NULL
		*/
		mochila ();
		
		/*
		*	 Pre: recibe el nombre del nuevo objeto a guardar en la lista
		*	 Post: Queda creado un nodo de 3 celdas (nombre, cantidad, proximo nodo)
		*			del nuevo objeto, guardado en el ultimo lugar de la lista.	      
		*/
		void agregarobjeto(string nuevo_objeto);
		
		/*
		*	Pre: recibe un objeto
		*	Post: devuelve el objeto
		*/
		string mostrar();
};

#endif /* MOCHILA_H_ */
