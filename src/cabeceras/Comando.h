/**
   Laberinto - TP 1
   Representa un comando, el cual se compone de un nombre y un argumento

   @author Mariano Cinalli
   @author Ezequiel Guitler
   @author Santiago Montiel
   @author Lucas Bonastre
   @author Laura Corvalan
*/

#ifndef _COMANDO_H_
#define _COMANDO_H_

#include <string>

class Comando {
   public:
      /**
       * Constructor.
       */
      Comando(std::string nombre, std::string argumento);

      /**
       * Retorna nombre del comando
       */
      std::string obtenerNombre();

      /**
       * Retorna argumento del comando
       */
      std::string obtenerArgumento();

      std::string aString();

   private:

      /**
       * Nombre del comando
       */
      std::string nombre;

      /**
       * Argumento del comando
       */
      std::string argumento;
};

#endif