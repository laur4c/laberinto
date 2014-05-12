#include "Laberinto.h"
#include "Camino.h"

#include <iostream>

using namespace std;

Laberinto::Laberinto() {
   this->caminos = new ListaEnlazada<Camino>();
   this->mochila = new Mochila();
}

ListaEnlazada<Camino> * Laberinto::obtenerCaminos() {
   return this->caminos;
}

void Laberinto::crearCaminosDesdeListaDeComandos(Cola<Comando> * comandos) {
   int pos = 0;
   int ubicacion = 1;
   char ultimaOrientacion = 'X'; // por default

   Camino * camino;
   Comando * comando;

   char orientacion;
   string bifurcacion;
   string empalme;
   int pasos;
   bool tieneObjeto;

   string nombreComando;
   string argumento;

   while (!comandos->estaVacia()) {
      comando = comandos->desacolar();

      nombreComando = comando->obtenerNombre();
      argumento = comando->obtenerArgumento();

      orientacion = ultimaOrientacion;
      bifurcacion = "";
      empalme = "";
      pasos = 0;
      tieneObjeto = false;

      if(nombreComando == "PP") {
         camino = new Camino(util::string_a_color(argumento));

      } else if(nombreComando == "PLL") {
         this->caminos->agregar(camino, ubicacion);
         ++ubicacion;

      } else if (nombreComando == "G") {
         ultimaOrientacion = argumento.c_str()[0];

      } else {

         if(nombreComando == "A") {
            orientacion = ultimaOrientacion;
            pasos = util::string_a_int(argumento);

         } else if(nombreComando == "R") {
            orientacion = ultimaOrientacion;
            pasos = util::string_a_int(argumento) * -1;

         } else if(nombreComando == "B") {
            pos = argumento.find(" ", 0);
            orientacion = argumento.substr(0, pos).c_str()[0];
            bifurcacion = argumento.substr(pos + 1);

         } else if (nombreComando == "U") {
            orientacion = ultimaOrientacion;
            empalme = argumento;
            pasos = 1;

         } else if (nombreComando == "L") {
            this->agregarElementoAMochila(argumento);

         } else if (nombreComando == "T") {
            orientacion = ultimaOrientacion;
            tieneObjeto = true;
            this->mochila->tirar_elemento(argumento);

         } else {
            // @TODO: usar una exception!
            cout << "ERR: Comando Invalido" << endl;
            return;
         }

         camino->agregarCasillero(orientacion, pasos, tieneObjeto, bifurcacion, empalme);
      }
   }

   Camino * item;
   int tamanio = this->caminos->obtenerTamanio();
   for (int i = 1; i <= tamanio; i++) {
      item = this->caminos->obtenerElemento(i);
      this->definirCoordenadas(item);
   }
}

void Laberinto::definirCoordenadas(Camino * camino) {
   int x = 0;
   int y = 0;
   int pasos;
   Casillero * casillero;

   int tamanio = camino->obtenerRecorrido()->obtenerTamanio();
   for (int i = 1; i <= tamanio; i++) {
      casillero = camino->obtenerRecorrido()->obtenerElemento(i);
      pasos = casillero->obtenerCantidadDePasos();

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
      }

      if (casillero->obtenerBifurcacion() != "") {
         camino->agregarBifurcacion(casillero->obtenerBifurcacion(), x, y);
      }

      casillero->cambiarXY(x, y);
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
