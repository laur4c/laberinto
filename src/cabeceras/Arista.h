/**
   Laberinto - TP 1
   Arista: Relacion entre dos vertices del grafo

   @author Laura Corvalan
*/

#ifndef _ARISTA_H_
#define _ARISTA_H_

#include <iostream>
#include "Tramo.h"
#include "ListaEnlazada.h"

template<class V> class Vertice;
template<class V> class Arista {
   public:
      bool enSentidoContrario;


      void marcarTramosComoNoDibujados();

      Arista(V dato, Vertice<V> * entrada, Vertice<V> * salida, int peso, ListaEnlazada<Tramo*> * tramos);

      /**
       * Retorna entrada de la arista
       */
      Vertice<V> * obtenerEntrada();

      /**
       * Retorna salida de la arista
       */
      Vertice<V> * obtenerSalida();


      ListaEnlazada<Tramo*> * obtenerTramos();

      /**
       * Retorna el peso de la arista
       */
      int obtenerPeso();

      void mostrar();

      V dato;
   private:

      int peso;



      ListaEnlazada<Tramo*> * tramos;

      Vertice<V> * entrada;

      Vertice<V> * salida;

};

template<class V>
Arista<V>::Arista(V dato, Vertice<V> * entrada, Vertice<V> * salida, int peso, ListaEnlazada<Tramo*> * tramos) {
   this->entrada = entrada;
   this->salida = salida;
   this->dato = dato;
   this->peso = peso;
   this->tramos = tramos;
   this->enSentidoContrario = false;
}


template<class V>
void Arista<V>::marcarTramosComoNoDibujados() {
  this->tramos->iniciarCursor();
  while(this->tramos->avanzarCursor()) {
    this->tramos->obtenerCursor()->marcarComoNoDibujado();
  }
}


template<class V>
Vertice<V> * Arista<V>::obtenerEntrada() {
   return this->entrada;
}

template<class V>
Vertice<V> * Arista<V>::obtenerSalida() {
   return this->salida;
}

template<class V>
int Arista<V>::obtenerPeso() {
   return this->peso;
}

template<class V>
ListaEnlazada<Tramo*> * Arista<V>::obtenerTramos() {
  return this->tramos;
}

template<class V>
void Arista<V>::mostrar() {
   std::cout << "Arista: " << std::endl;
   std::cout << this->dato << std::endl;
   std::cout << "Con peso: " << std::endl;
   std::cout << this->peso << std::endl;

   std::cout << "Vertices: " << std::endl;
   std::cout << this->entrada->obtenerDato() << std::endl;
   std::cout << this->salida->obtenerDato() << std::endl;
}
#endif