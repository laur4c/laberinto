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

      bool estaVacia();

      /**
       * Agrega un elemento al final de la lista.
       */
      void agregar(T dato, int posicion);


      /*
      * Agrega el elemento al final de la Lista
      */
      void agregar(T dato);

      /**
       * Remueve un elementode la lista.
       */
      T eliminar(int posicion);

      T obtenerElemento(int posicion);

      int obtenerTamanio();

      void mostrar();

      /*
       * Deja el cursor de la Lista preparado para hacer un nuevo
       * recorrido sobre sus elementos.
       */
      void iniciarCursor();

      /*
       * Mueve el cursor y lo posiciona en el siguiente elemento
       */
      bool avanzarCursor();

      /**
       * El cursor está posicionado sobre un elemento de la Lista,
       * Devuelve el elemento en la posición del cursor.
       */
      T obtenerCursor();

      ~ListaEnlazada();
   private:

      /**
       * Puntero a primer elemento de la lista
       */
      Nodo<T> * frente;

      int tamanio;

      Nodo<T> * cursor;

      Nodo<T> * obtenerNodo(int posicion);
};


template<class T>
ListaEnlazada<T>::ListaEnlazada() {
   this->frente = NULL;
   this->tamanio = 0;
   this->cursor = NULL;
}

template<class T>
bool ListaEnlazada<T>::estaVacia() {
   return this->tamanio == 0;
}

template<class T>
void ListaEnlazada<T>::agregar(T dato, int posicion) {
   if ((posicion > 0) && (posicion <= this->tamanio + 1)) {
      Nodo<T> * nodo = new Nodo<T>(dato);
      if (posicion == 1) {
         nodo->cambiarSiguiente(this->frente);
         this->frente = nodo;
      } else {
         Nodo<T> * anterior = this->obtenerNodo(posicion - 1);
         nodo->cambiarSiguiente(anterior->obtenerSiguiente());
         anterior->cambiarSiguiente(nodo);
      }
      this->tamanio++;
      this->iniciarCursor();
   }
}

template<class T>
void ListaEnlazada<T>::agregar(T dato) {
   this->agregar(dato, this->tamanio + 1);
}

template<class T>
T ListaEnlazada<T>::obtenerElemento(int posicion) {
   T elemento;
   if ((posicion > 0) && (posicion <= this->tamanio)) {
      elemento = this->obtenerNodo(posicion)->obtenerDato();
   }
   return elemento;
}

template<class T>
T ListaEnlazada<T>::eliminar(int posicion) {
   if ((posicion > 0) && (posicion <= this->tamanio)) {
      Nodo<T>* removido;

      if (posicion == 1) {
         removido = this->frente;
         this->frente = removido->obtenerSiguiente();
      } else {
         Nodo<T> * anterior = this->obtenerNodo(posicion - 1);
         removido = anterior->obtenerSiguiente();
         anterior->cambiarSiguiente(removido->obtenerSiguiente());
      }

      delete removido;
      this->tamanio--;

      this->iniciarCursor();
   }
}

template<class T>
int ListaEnlazada<T>::obtenerTamanio() {
   return this->tamanio;
}

template<class T>
void ListaEnlazada<T>::iniciarCursor() {
   this->cursor = NULL;
}

template<class T>
bool ListaEnlazada<T>::avanzarCursor() {
   if (this->cursor == NULL) {
      this->cursor = this->frente;
   } else {
      this->cursor = this->cursor->obtenerSiguiente();
   }
   return this->cursor != NULL;
}

template<class T>
T ListaEnlazada<T>::obtenerCursor() {
   T elemento;
   if (this->cursor != NULL) {
      elemento = this->cursor->obtenerDato();
   }
   return elemento;
}

template<class T>
Nodo<T> * ListaEnlazada<T>::obtenerNodo(int posicion) {
   Nodo<T> * actual = this->frente;
   for (int i = 1; i < posicion; i++) {
      actual = actual->obtenerSiguiente();
   }
   return actual;
}

template<class T>
void ListaEnlazada<T>::mostrar() {
   T elemento;
   for (int i = 1; i <= this->tamanio; i++) {
      elemento = this->obtenerElemento(i);
      std::cout << elemento->aString() << std::endl;
   }
}

template<class T>
ListaEnlazada<T>::~ListaEnlazada() {
   while (this->frente != NULL) {
      Nodo<T> * aBorrar = this->frente;
      this->frente = this->frente->obtenerSiguiente();

      delete aBorrar;
   }
}

#endif