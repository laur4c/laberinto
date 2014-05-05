#include "Laberinto.h"

#include <iostream>

using namespace std;

Laberinto::Laberinto() {
   this->recorridos = new ListaRecorridos();
   this->mochila = new Mochila();
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
   string nombreComando;
   string argumento;
   string bifurcacion;

   while (comando != NULL) {
      nombreComando = comando->obtenerNombre();
      argumento = comando->obtenerArgumento();

      if(nombreComando == "PP") {
         recorrido = new Recorrido(util::string_a_color(argumento));

      } else if(nombreComando == "G") {
         ultimaOrientacion = argumento.c_str()[0];

      } else if(nombreComando == "A") {
         recorrido->acolar(ultimaOrientacion, util::string_a_int(argumento));

      } else if(nombreComando == "R") {
         recorrido->acolar(ultimaOrientacion, util::string_a_int(argumento) * -1 );

      } else if(nombreComando == "B") {
         pos = argumento.find(" ", 0);
         orientacion = argumento.substr(0, pos).c_str()[0];
         bifurcacion = argumento.substr(pos + 1);

         recorrido->acolar(orientacion, 0, false, bifurcacion);

      } else if (nombreComando == "U") {
         recorrido->acolar(ultimaOrientacion, 1, false, "", argumento);

      } else if (nombreComando == "L") {
         this->agregarElementoAMochila(argumento);

      } else if (nombreComando == "T") {
         recorrido->acolar(ultimaOrientacion, 0, true);
         this->mochila->tirar_elemento(argumento);

      } else if (nombreComando == "PLL") {
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

      if (casillero->obtenerBifurcacion() != "") {
         recorrido->obtenerBifurcaciones()->acolar(casillero->obtenerBifurcacion(), x, y);
      }

      casillero->cambiarXY(x, y);
      casillero = casillero->obtenerSiguiente();
   }
}

Mochila * Laberinto::obtenerMochila() {
   return this->mochila;
}

void Laberinto::agregarElementoAMochila(std::string elemento) {
   if (this->mochila->existe_elemento(elemento)) {
      this->mochila->sumar_elemento(elemento);
   } else {
      this->mochila->agregar_elemento(elemento);
   }
}
