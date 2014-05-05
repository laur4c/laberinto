/**
   Laberinto - TP 1
   Representa un comando, el cual se compone de un nombre y un argumento

   @author Santiago Montiel, Lucas Dreko, Laura Corvalan
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

      /**
       * Retorna puntero al siguiente comando
       */
      Comando * obtenerSiguiente();

      /**
       * Modifica el puntero al siguiente comando
       */
      void cambiarSiguiente(Comando * comando);

   private:

      /**
       * Nombre del comando
       */
      std::string nombre;

      /**
       * Argumento del comando
       */
      std::string argumento;

      /**
       * Puntero al siguiente comando
       */
      Comando * siguiente;
};

#endif