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
      Comando(std::string nombre, std::string argumento);

      std::string obtenerNombre();

      std::string obtenerArgumento();

      Comando * obtenerSiguiente();

      void cambiarSiguiente(Comando * comando);

   private:
      std::string nombre;

      std::string argumento;

      Comando * siguiente;
};

#endif