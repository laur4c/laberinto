#ifndef _MOCHILA_H_
#define _MOCHILA_H_

#include "ListaEnlazada.h"
#include "ItemMochila.h"

class Mochila {

	public:

		Mochila();

		void agregar(std::string nombre);

		void quitar(std::string nombre);

		void mostrar();

	private:

		ListaEnlazada<ItemMochila*> * items;

    	bool existeItem(std::string nombre);

		ItemMochila * obtenerItem(std::string nombre);
};

#endif
