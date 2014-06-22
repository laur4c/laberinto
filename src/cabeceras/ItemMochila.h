/**
   Laberinto - TP 1

   @author Laura Corvalan
*/

#ifndef _ITEM_MOCHILA_H_
#define _ITEM_MOCHILA_H_

#include <iostream>

class ItemMochila {

   public:

      /**
       * Constructor
       */
      ItemMochila(std::string nombre);

      /**
       * Total
       */
      int total;

      /**
       * Nombre del item
       */
      std::string nombre;

};

#endif
