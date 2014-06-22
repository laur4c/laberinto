/**
   Laberinto - TP 1
   Vertice del grafo

   @author Laura Corvalan
*/

#ifndef _VERTICE_H_
#define _VERTICE_H_

#include "ListaEnlazada.h"
#include "Arista.h"
#include <iostream>

template<class V> class Vertice {
   public:

      /**
       * Constructor
       */
      Vertice(V dato);

      /**
       * Retorna nombre del vertice
       */
      V obtenerDato();

      /**
       * Agrega arista saliente del vertice
       */
      void agregarArista(Arista<V> * arista);

      /**
       * Retorna lista de aristas
       */
      ListaEnlazada< Arista<V>* > * obtenerAristas();

      /**
       * Marca vertice como no visitado (visitado = false)
       */
      void marcarComoNoVisitado();

      /**
       * Marca vertice como visitado (visitado = true)
       */
      void marcarComoVisitado();

      /**
       * Retorna true si el vertice fue visitado
       */
      bool fueVisitado();

      /**
       * Imprime info del vertice en consola
       */
      void mostrar();

      /**
       * Modifica el atributo pesoArista
       */
      void guardarPesoArista(int value);

      /**
       * Retorna el peso de la arista de menor longitud
       */
      int obtenerPesoArista();

      /**
       * Guarda el vertice anterior. Se ultiza para recorrer caminos minimos
       */
      void guardarAnterior(Vertice<V> * anterior);

      /**
       * Retorna true si anterior distinto de NULL
       */
      bool tieneAnterior();

      /**
       * Retorna vertice anterior. Utilizado para recorrer caminos minimos
       */
      Vertice<V> * obtenerAnterior();

      /**
       * Actualiza coordenadas (x, y) del vertice
       */
      void actualizarXY(int x, int y);

      /**
       * Retorna valor coordenada X
       */
      int obtenerX();

      /**
       * Retorna valor coordenada Y
       */
      int obtenerY();

      /**
       * Retorna true si coordenadas igual a (0, 0)
       */
      bool tieneCoordenadas();

   private:

      /**
       * Nombre del vertice
       */
      V dato;

      /**
       * Flag. Indica si el vertice fue visitado o no
       */
      bool visitado;

      /**
       * Peso de la arista, utilizada para la busqueda de caminos minimos.
       * Se almacena el peso de la arista de menor valor
       */
      int pesoArista;

      /**
       * Vertice anterior. Se ultiliza para recorrer caminos minimos
       */
      Vertice<V> * anterior;

      /**
       * Aristas salientes del vertice
       */
      ListaEnlazada< Arista<V>* > * aristas;

      /**
       * Representa coordenada X en la imagen del laberinto
       */
      int x;

      /**
       * Representa coordenada Y en la imagen del laberinto
       */
      int y;

};

template<class V>
Vertice<V>::Vertice(V dato) {
   this->dato = dato;
   this->aristas = new ListaEnlazada< Arista<V>* >();
   this->visitado = false;
   this->anterior = NULL;
   this->x = 0;
   this->y = 0;
}

template<class V>
V Vertice<V>::obtenerDato() {
   return this->dato;
}

template<class V>
void Vertice<V>::agregarArista(Arista<V> * arista) {
   return this->aristas->agregar(arista);
}

template<class V>
ListaEnlazada< Arista<V>* > * Vertice<V>::obtenerAristas() {
   return this->aristas;
}

template<class V>
void Vertice<V>::mostrar() {
   std::cout << "Vertice: " << this->dato << std::endl;

   this->aristas->iniciarCursor();
   while(this->aristas->avanzarCursor()) {
      this->aristas->obtenerCursor()->mostrar();
   }
}

template<class V>
void Vertice<V>::marcarComoVisitado() {
   this->visitado = true;
}

template<class V>
void Vertice<V>::marcarComoNoVisitado() {
   this->visitado = false;
}

template<class V>
bool Vertice<V>::fueVisitado() {
   return this->visitado;
}

template<class V>
void Vertice<V>::guardarPesoArista(int valor) {
   this->pesoArista = valor;
}

template<class V>
int Vertice<V>::obtenerPesoArista() {
   return this->pesoArista;
}

template<class V>
Vertice<V> * Vertice<V>::obtenerAnterior() {
   return this->anterior;
}

template<class V>
void Vertice<V>::guardarAnterior(Vertice<V> * anterior) {
   this->anterior = anterior;
}

template<class V>
bool Vertice<V>::tieneAnterior() {
   return this->anterior != NULL;
}

template<class V>
void Vertice<V>::actualizarXY(int x, int y) {
   this->x = x;
   this->y = y;
}

template<class V>
int Vertice<V>::obtenerX() {
   return this->x;
}

template<class V>
int Vertice<V>::obtenerY() {
   return this->y;
}

template<class V>
bool Vertice<V>::tieneCoordenadas() {
   return (this->x != 0 && this->y != 0);
}


#endif