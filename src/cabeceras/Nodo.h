/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _NODO_H_
#define _NODO_H_

#include <cstdlib>
using namespace std;


template <class T>
class Nodo {
   public:
      /**
       * Constructor
       */
      Nodo(T dato);

      /**
       * Retorna puntero al nodo siguiente
       */
      Nodo<T> * obtenerSiguiente();

      /**
       * Cambia el puntero al nodo siguiente
       */
      void cambiarSiguiente(Nodo<T> * nodo);

      /**
       * Retorna puntero al nodo anterior
       */
      Nodo<T> * obtenerAnterior();

      /**
       * Cambia el puntero al nodo anterior
       */
      void cambiarAnterior(Nodo<T> * nodo);

      /**
       * Retorna el dato del nodo
       */
      T obtenerDato();

   private:
      /**
       * Dato contenido en el nodo
       */
      T dato;

      /**
       * Puntero al nodo siguiente
       */
      Nodo<T> * siguiente;

      /**
       * Puntero al nodo anterior
       */
      Nodo<T> * anterior;
};

template<class T>
Nodo<T>::Nodo(T dato) {
   this->dato = dato;
   this->siguiente = NULL;
   this->anterior = NULL;
}

template<class T>
T Nodo<T>::obtenerDato() {
   return this->dato;
}

template<class T>
Nodo<T> * Nodo<T>::obtenerSiguiente() {
   return this->siguiente;
}

template<class T>
void Nodo<T>::cambiarSiguiente(Nodo<T> * nodo) {
   this->siguiente = nodo;
}

template<class T>
Nodo<T> * Nodo<T>::obtenerAnterior() {
   return this->anterior;
}

template<class T>
void Nodo<T>::cambiarAnterior(Nodo<T> * nodo) {
   this->anterior = nodo;
}
#endif