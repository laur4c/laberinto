/**
   Laberinto - TP 1
   Parsea un archivo con las instrucciones (Comandos) para armar 1
   ó más recorridos del laberinto. Las intrucciones estan separadas
   por saltos de linea

   @author Santiago Montiel, Lucas Dreko, Laura Corvalan
*/


#ifndef _PARSER_H_
#define _PARSER_H_

#include "lista_comandos.h"
#include <string>

class Parser {
   public:
      Parser(std::string nombreArchivo);

      void iniciar();

      ListaComandos * obtenerLista();
   private:

      std::string nombreArchivo;

      ListaComandos * listaComandos;
};

#endif