/**
   Laberinto - TP 1
   Arista: Relacion entre dos vertices del grafo

   @author Laura Corvalan
*/

#ifndef _ARISTA_H_
#define _ARISTA_H_

#include <iostream>

template<class V> class Vertice;
template<class V> class Arista {
   public:
      Arista(V dato, Vertice<V> * entrada, Vertice<V> * salida, int peso);

      /**
       * Retorna entrada de la arista
       */
      Vertice<V> * obtenerEntrada();

      /**
       * Retorna salida de la arista
       */
      Vertice<V> * obtenerSalida();

      /**
       * Retorna el peso de la arista
       */
      int obtenerPeso();

      void mostrar();

   private:

      V dato;

      int peso;

      Vertice<V> * entrada;

      Vertice<V> * salida;

};

template<class V>
Arista<V>::Arista(V dato, Vertice<V> * entrada, Vertice<V> * salida, int peso) {
   this->entrada = entrada;
   this->salida = salida;
   this->dato = dato;
   this->peso = peso;
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