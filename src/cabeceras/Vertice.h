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

template<typename V, typename A> class Vertice {

   public:

      /**
       * Constructor
       */
      Vertice(std::string nombre, V dato);

      /**
       * Retorna nombre del vertice
       */
      std::string obtenerNombre();

      /**
       * Retorna dato del vertice
       */
      V obtenerDato();

      /**
       * Agrega arista saliente del vertice
       */
      void agregarArista(Arista<A,V> * arista);

      /**
       * Retorna lista de aristas
       */
      ListaEnlazada< Arista<A,V>* > * obtenerAristas();

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
      void guardarAnterior(Vertice<V,A> * anterior);

      /**
       * Retorna true si anterior distinto de NULL
       */
      bool tieneAnterior();

      /**
       * Retorna vertice anterior. Utilizado para recorrer caminos minimos
       */
      Vertice<V,A> * obtenerAnterior();


      ~Vertice();
   private:

      /**
       * Nombre del vertice
       */
      std::string nombre;

      /**
       * Dato
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
      Vertice<V,A> * anterior;

      /**
       * Aristas salientes del vertice
       */
      ListaEnlazada< Arista<A,V>* > * aristas;


};

template<typename V, typename A>
Vertice<V, A>::Vertice(std::string nombre, V dato) {
   this->nombre = nombre;
   this->dato = dato;
   this->aristas = new ListaEnlazada< Arista<A,V>* >();
   this->visitado = false;
   this->anterior = NULL;
}

template<typename V, typename A>
std::string Vertice<V,A>::obtenerNombre() {
   return this->nombre;
}

template<typename V, typename A>
V Vertice<V,A>::obtenerDato() {
   return this->dato;
}

template<typename V, typename A>
void Vertice<V,A>::agregarArista(Arista<A,V> * arista) {
   return this->aristas->agregar(arista);
}

template<typename V, typename A>
ListaEnlazada< Arista<A,V>* > * Vertice<V,A>::obtenerAristas() {
   return this->aristas;
}

template<typename V, typename A>
void Vertice<V,A>::mostrar() {
   std::cout << "Vertice: " << this->dato << std::endl;

   this->aristas->iniciarCursor();
   while(this->aristas->avanzarCursor()) {
      this->aristas->obtenerCursor()->mostrar();
   }
}

template<typename V, typename A>
void Vertice<V,A>::marcarComoVisitado() {
   this->visitado = true;
}

template<typename V, typename A>
void Vertice<V,A>::marcarComoNoVisitado() {
   this->visitado = false;
}

template<typename V, typename A>
bool Vertice<V,A>::fueVisitado() {
   return this->visitado;
}

template<typename V, typename A>
void Vertice<V,A>::guardarPesoArista(int valor) {
   this->pesoArista = valor;
}

template<typename V, typename A>
int Vertice<V,A>::obtenerPesoArista() {
   return this->pesoArista;
}

template<typename V, typename A>
Vertice<V,A> * Vertice<V,A>::obtenerAnterior() {
   return this->anterior;
}

template<typename V, typename A>
void Vertice<V,A>::guardarAnterior(Vertice<V,A> * anterior) {
   this->anterior = anterior;
}

template<typename V, typename A>
bool Vertice<V,A>::tieneAnterior() {
   return this->anterior != NULL;
}

template<typename V, typename A>
Vertice<V,A>::~Vertice() {
    delete this->aristas;
}
#endif