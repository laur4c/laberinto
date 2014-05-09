/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _LISTA_ENLAZADA_H_
#define _LISTA_ENLAZADA_H_


#include <iostream>
using namespace std;

#include "Nodo.h"

template<class T> class ListaEnlazada {
   public:
      /**
       * Constructor.
       */
      ListaEnlazada();

      /**
       * Agrega un elemento al final de la lista.
       */
      void agregar(T * dato, int posicion);

      /**
       * Remueve un elementode la lista.
       */
      T * eliminar(int posicion);

      T * obtenerElemento(int posicion);

      int obtenerTamanio();

      void mostrar();

      // ~ListaEnlazada();
   private:

      /**
       * Puntero a primer elemento de la lista
       */
      Nodo<T> * frente;

      int tamanio;
};


template<class T>
ListaEnlazada<T>::ListaEnlazada() {
   this->frente = NULL;
   this->tamanio = 0;
}

template<class T>
void ListaEnlazada<T>::agregar(T * dato, int posicion) {
   Nodo<T> * nodo = new Nodo<T>(dato);
   if (posicion == 1) {
      nodo->cambiarSiguiente(nodo);
      this->frente = nodo;
   } else {
      Nodo<T> * unNodo = this->frente;
      for (unsigned int i= 1; i < (posicion - 1) && unNodo && unNodo != NULL; i++) {
         unNodo = unNodo->obtenerSiguiente();
      }
      nodo->cambiarSiguiente(unNodo->obtenerSiguiente());
      unNodo->cambiarSiguiente(nodo);
   }
   this->tamanio++;
}

template<class T>
T * ListaEnlazada<T>::obtenerElemento(int posicion) {
   // @TODO mejorar con cursor
   T * elemento;
   if (posicion > 0 && posicion <= this->tamanio) {
      Nodo<T> * actual = this->frente;
      for (int i = 1; i < posicion; i++) {
         actual = actual->obtenerSiguiente();
      }
      elemento = actual->obtenerDato();
   }
   return elemento;
}

template<class T>
T * ListaEnlazada<T>::eliminar(int posicion) {
   // @TODO: falta implementar
   return this->obtenerElemento(posicion);
}

template<class T>
int ListaEnlazada<T>::obtenerTamanio() {
   return this->tamanio;
}

template<class T>
void ListaEnlazada<T>::mostrar() {
   T * elemento;
   for (unsigned int i = 1; i <= this->tamanio; i++) {
      elemento = this->obtenerElemento(i);
      std::cout << elemento->aString() << std::endl;
   }
}

// template<class T>
// ListaEnlazada::~ListaEnlazada() {
//    while(this->tamanio > 0) {
//       this->eliminar(1);
//    }
//    delete this->frente;
// }

#endif