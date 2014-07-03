/**
   Laberinto - TP 1
   Arista: Relacion entre dos vertices del grafo

   @author Laura Corvalan
*/

#ifndef _ARISTA_H_
#define _ARISTA_H_

#include <iostream>
#include "ListaEnlazada.h"

template<typename V, typename A> class Vertice;
template<typename A, typename V> class Arista {
   public:

      /**
       * Constructor
       */
      Arista(std::string nombre, A dato, Vertice<V,A> * entrada, Vertice<V,A> * salida, int peso);

      /**
       * Retorna entrada de la arista
       */
      Vertice<V,A> * obtenerEntrada();

      /**
       * Retorna salida de la arista
       */
      Vertice<V,A> * obtenerSalida();

      /**
       * Retorna dato
       */
      A obtenerDato();

      /**
       * Setea el atributo enSentidoContrario igual a true
       */
      void marcarSentidoContrario();

      /**
       * Retorna el peso de la arista
       */
      int obtenerPeso();

      /**
       * Imprime en consola los datos de la arista
       */
      void mostrar();

      ~Arista();

   protected:

      /**
       * Dato
       */
      A dato;

      bool enSentidoContrario;

      /**
       * Vertice de entrada
       */
      Vertice<V,A> * entrada;

      /**
       * Vertice de salida
       */
      Vertice<V,A> * salida;

   private:

      /**
       * Nombre de la arista
       */
      std::string nombre;


      /**
       * Peso de la arista
       */
      int peso;
};

template<typename A, typename V>
Arista<A,V>::Arista(std::string nombre, A dato, Vertice<V,A> * entrada, Vertice<V,A> * salida, int peso) {
   this->entrada = entrada;
   this->salida = salida;
   this->nombre = nombre;
   this->dato = dato;
   this->peso = peso;
   this->enSentidoContrario = false;
}

template<typename A, typename V>
Vertice<V,A> * Arista<A,V>::obtenerEntrada() {
   return this->entrada;
}

template<typename A, typename V>
Vertice<V,A> * Arista<A,V>::obtenerSalida() {
   return this->salida;
}

template<typename A, typename V>
A Arista<A,V>::obtenerDato() {
   return this->dato;
}

template<typename A, typename V>
void Arista<A,V>::marcarSentidoContrario() {
  this->enSentidoContrario = true;
}

template<typename A, typename V>
int Arista<A,V>::obtenerPeso() {
   return this->peso;
}

template<typename A, typename V>
void Arista<A,V>::mostrar() {
   std::cout << "Arista: ";
   std::cout << this->dato << "(" << this->peso << ") -";

   std::cout << "Vertices: ";
   std::cout << "( " << this->entrada->obtenerDato() << " - ";
   std::cout << this->salida->obtenerDato() << ")" << std::endl;
}

template<typename A, typename V>
Arista<A,V>::~Arista() {
}
#endif