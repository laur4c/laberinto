#include "Laberinto.h"

#include <iostream>

using namespace std;

Laberinto::Laberinto() {
   this->recorridos = new ListaRecorridos();
}

ListaRecorridos * Laberinto::obtenerRecorridos() {
   return this->recorridos;
}

void Laberinto::generarRecorridosDesdeListaDeComandos(ListaComandos * comandos) {
   Comando * comando = comandos->obtenerFrente();
   Recorrido * recorrido;
   char ultimaOrientacion;
   char orientacion;

   int pos = 0;
   string argumento;
   string bifurcacion;

   while (comando != NULL) {

      if(comando->obtenerNombre() == "PP") {
         recorrido = new Recorrido(util::string_a_color(comando->obtenerArgumento()));

      } else if(comando->obtenerNombre() == "G") {
         ultimaOrientacion = comando->obtenerArgumento().c_str()[0];
      } else if(comando->obtenerNombre() == "A") {
         recorrido->acolar(ultimaOrientacion, util::string_a_int(comando->obtenerArgumento()));

      } else if(comando->obtenerNombre() == "R") {
         recorrido->acolar(ultimaOrientacion, util::string_a_int(comando->obtenerArgumento()) * -1 );

      } else if(comando->obtenerNombre() == "B") {
         argumento = comando->obtenerArgumento();
         pos = argumento.find(" ", 0);
         orientacion = argumento.substr(0, pos).c_str()[0];
         bifurcacion = argumento.substr(pos + 1);

         recorrido->acolar(orientacion, 0, false, bifurcacion);

      } else if (comando->obtenerNombre() == "U") {
         recorrido->acolar(ultimaOrientacion, 1, false, "", comando->obtenerArgumento());

      } else if (comando->obtenerNombre() == "T") {
         recorrido->acolar(ultimaOrientacion, 0, true);

      } else if (comando->obtenerNombre() == "PLL") {
         this->recorridos->acolar(recorrido);

      } else {
         cout << "ERR: Comando Invalido" << endl;
      }

      comando = comando->obtenerSiguiente();
   }

   NodoRecorrido * nodoRecorrido = this->recorridos->obtenerFrente();
   while(nodoRecorrido != NULL) {
      this->definirCoordenadas(nodoRecorrido->obtenerRecorrido());
      nodoRecorrido = nodoRecorrido->obtenerSiguiente();
   }

}

void Laberinto::definirCoordenadas(Recorrido * recorrido) {
   int x = 0;
   int y = 0;
   Casillero * casillero = recorrido->obtenerFrente();

   while(casillero != NULL) {
      int pasos = casillero->obtenerCantidadDePasos();
      switch(casillero->obtenerOrientacion()) {
         case 'N':
           y = y + pasos;
           break;
         case 'S':
           y = y - pasos;
           break;
         case 'E':
           x = x + pasos;
           break;
         case 'O':
           x = x - pasos;
           break;
         default:
            0;
      }
      casillero->cambiarXY(x, y);
      casillero = casillero->obtenerSiguiente();
   }
}



