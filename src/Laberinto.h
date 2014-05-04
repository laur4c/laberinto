/**
   Laberinto - TP 1

   @author Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _LABERINTO_H_
#define _LABERINTO_H_

#include "util.h"
#include "ListaRecorridos.h"
#include "ListaComandos.h"

class Laberinto {
   public:
      Laberinto();

      void generarRecorridosDesdeListaDeComandos(ListaComandos * comandos);

      ListaRecorridos * obtenerRecorridos();

   private:

      ListaRecorridos * recorridos;

      void definirCoordenadas(Recorrido * recorrido);
};

#endif