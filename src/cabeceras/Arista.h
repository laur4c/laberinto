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

      /**
       * Constructor
       */
      Arista(V dato, Vertice<V> * entrada, Vertice<V> * salida, int peso, ListaEnlazada<Tramo*> * tramos);

      /**
       * Retorna entrada de la arista
       */
      Vertice<V> * obtenerEntrada();

      /**
       * Retorna salida de la arista
       */
      Vertice<V> * obtenerSalida();

      /**
       * Retorna lista de tramos
       *
       * Cada tramo tiene una sentido y una longitud.
       * Ver Tramo.h
       */
      ListaEnlazada<Tramo*> * obtenerTramos();

      /**
       * Marca todos los tramos de la arista como no dibujados
       */
      void marcarTramosComoNoDibujados();

      /**
       * Retorna true si sus tramos deben dibujarse en el sentido contrario
       */
      bool dibujarEnSentidoContrario();

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

    private:

      /**
       * Nombre de la arista
       */
      V dato;

      /**
       * Peso de la arista
       */
      int peso;

      /**
       * Indica si debe dibujarse en sentido contrario.
       * Cuando se agrega una arista al laberinto, se agrega la arista con el sentido
       * que indica el archivo de texto y otra con el sentido contrario.
       * Esto se hace para poder, desde un vertice
       * recorrer todo el laberinto
       */
      bool enSentidoContrario;

      /**
       * Lista de tramos
       * Porque las aristas entre vertice y vertice no son lineas rectas
       */
      ListaEnlazada<Tramo*> * tramos;

      /**
       * Vertice de entrada
       */
      Vertice<V> * entrada;

      /**
       * Vertice de salida
       */
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
Vertice<V> * Arista<V>::obtenerEntrada() {
   return this->entrada;
}

template<class V>
Vertice<V> * Arista<V>::obtenerSalida() {
   return this->salida;
}

template<class V>
ListaEnlazada<Tramo*> * Arista<V>::obtenerTramos() {
  return this->tramos;
}

template<class V>
void Arista<V>::marcarTramosComoNoDibujados() {
  this->tramos->iniciarCursor();
  while(this->tramos->avanzarCursor()) {
    this->tramos->obtenerCursor()->marcarComoNoDibujado();
  }
}

template<class V>
void Arista<V>::marcarSentidoContrario() {
  this->enSentidoContrario = true;
}

template<class V>
bool Arista<V>::dibujarEnSentidoContrario() {
   return this->enSentidoContrario;
}

template<class V>
int Arista<V>::obtenerPeso() {
   return this->peso;
}

template<class V>
void Arista<V>::mostrar() {
   std::cout << "Arista: ";
   std::cout << this->dato << "(" << this->peso << ") -";

   std::cout << "Vertices: ";
   std::cout << "( " << this->entrada->obtenerDato() << " - ";
   std::cout << this->salida->obtenerDato() << ")" << std::endl;
}

template<class V>
Arista<V>::~Arista() {
  if (!this->enSentidoContrario)
    delete this->tramos;

}
#endif