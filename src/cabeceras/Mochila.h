/**
   Laberinto - TP 1

   @author Laura Corvalan
*/

#ifndef _MOCHILA_H_
#define _MOCHILA_H_

#include "ListaEnlazada.h"
#include "ItemMochila.h"

class Mochila {

	public:

      /**
       * Constructor
       */
		Mochila();

      /**
       * Agrega item en mochila. Si ya existe, modifica total de items con ese mismo nombre en la mochila.
       */
		void agregar(std::string nombre);

      /**
       * Quita item de mochila. Si el item no existe, se lanza una excepcion
       */
		void quitar(std::string nombre);

      /**
       * Imprime en consola items en la mochila
       */
		void mostrar();

	private:

      /**
       * Items dentro de la mochila
       */
		ListaEnlazada<ItemMochila*> * items;

      /**
       * Retorna true si el item esta presente en la mochila
       */
    	bool existeItem(std::string nombre);

       /**
       * Retorna item por nombre
       */
		ItemMochila * obtenerItem(std::string nombre);
};

#endif
