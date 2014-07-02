/**
   Laberinto - TP 1
   Parsea un archivo con las instrucciones (Comandos) para armar 1
   ó más recorridos del laberinto. Las intrucciones estan separadas
   por saltos de linea

   @author Laura Corvalan
*/


#ifndef _PARSER_H_
#define _PARSER_H_

#include "Comando.h"
#include "Cola.h"

#include <string>

class Parser {
   public:
      /**
       * Constructor
       * @param nombreArchivo Archivo de texto (.txt) con los recorridos
       */
      Parser(std::string nombreArchivo);

      /**
       * Parsea el archivo y genera una lista de comandos.
       * La funcion es separar lo que nosotros llamamos el comando
       * de sus argumentos.
       */
      void iniciar();

      /**
       * Retorna lista de comandos
       */
      Cola<Comando*> * obtenerLista();

      ~Parser();
   private:

      /**
       * Archivo de texto (.txt) con los recorridos
       */
      std::string nombreArchivo;

      /**
       * Lista de comandos
       */
      Cola<Comando*> * listaComandos;
};

#endif