#ifndef _VERTICE_H_
#define _VERTICE_H_

#include "ListaEnlazada.h"
#include "Arista.h"
#include <iostream>

template<class V> class Vertice {
   public:
      Vertice(V dato);

      V obtenerDato();

      void agregarArista(Arista<V> * arista);

      ListaEnlazada< Arista<V>* > * obtenerAristas();

      void marcarComoNoVisitado();

      void marcarComoVisitado();

      bool fueVisitado();

      void mostrar();

      void guardarPesoArista(int value);

      int obtenerPesoArista();

      void guardarAnterior(Vertice<V> * anterior);

      bool tieneAnterior();

      Vertice<V> * obtenerAnterior();

   private:

      V dato;

      bool visitado;

      int pesoArista;

      Vertice<V> * anterior;

      ListaEnlazada< Arista<V>* > * aristas;

};

template<class V>
Vertice<V>::Vertice(V dato) {
   this->dato = dato;
   this->aristas = new ListaEnlazada< Arista<V>* >();
   this->visitado = false;
   this->anterior = NULL;
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
   std::cout << "Vertice: " << std::endl;
   std::cout << this->dato << std::endl;

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


#endif