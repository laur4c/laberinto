/**
   Laberinto - TP 1

   Implementacion de una lista de tipo: Cola

   @author Laura Corvalan
*/

#ifndef _COLA_H_
#define _COLA_H_


#include <iostream>
using namespace std;

#include "Nodo.h"

template<class T> class Cola {
   public:
      /**
       * Constructor.
       */
      Cola();

      /**
       * Retorna true si la lista esta vacia, false en caso contrario
       */
      bool estaVacia();

      /**
       * Agrega un elemento al final de la lista.
       */
      void acolar(T dato);

      /**
       * Remueve un elemento del frente de la lista.
       */
      T desacolar();

      /**
       * toString a cada elemento de la cola
       */
      void mostrar();

      Nodo<T> * obtenerFrente();

      ~Cola();

   private:

      /**
       * Puntero a primer elemento de la lista
       */
      Nodo<T> * frente;

      /**
       * Puntero a ultimo elemento de la lista
       */
      Nodo<T> * fondo;

};


template<class T>
Cola<T>::Cola() {
   this->frente = NULL;
   this->fondo = NULL;
}

template<class T>
bool Cola<T>::estaVacia() {
   return this->frente == NULL;
}

template<class T>
void Cola<T>::acolar(T dato) {
   Nodo<T> * ultimo = new Nodo<T>(dato);

   if (this->estaVacia()) {
      this->frente = ultimo;
   } else {
      this->fondo->cambiarSiguiente(ultimo);
   }
   this->fondo = ultimo;
}

template<class T>
T Cola<T>::desacolar() {
   T elemento;
   if (!this->estaVacia()) {
      elemento = this->frente->obtenerDato();
      Nodo<T> * primero = this->frente;
      this->frente = primero->obtenerSiguiente();
      delete primero;
      if (this->frente == NULL) {
         this->fondo = NULL;
      }
   }
   return elemento;
}

template<class T>
void Cola<T>::mostrar() {
   Nodo<T> * nodo = this->frente;
   while(nodo != NULL) {
      std::cout << nodo->obtenerDato()->aString() << std::endl;
      nodo = nodo->obtenerSiguiente();
   }
}

template<class T>
Nodo<T> * Cola<T>::obtenerFrente() {
  return this->frente;
}

template<class T>
Cola<T>::~Cola() {
   while(!this->estaVacia()) {
      this->desacolar();
   }
}

#endif