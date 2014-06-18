#ifndef _GRAFO_H_
#define _GRAFO_H_

#include "Vertice.h"
#include "Arista.h"
#include "ListaEnlazada.h"
#include "Cola.h"

#include <iostream>

#include <queue>
#include <vector>

#define MAX_PESO_ARISTA 100000

struct comparador {
   bool operator() (int * a, int * b) {
      return a[1] > b[1];
   }
};

template<class V> class Grafo {
   public:
      Grafo();

      bool existeVertice(V dato);

      Vertice<V> * obtenerVertice(V dato);

      bool estaVacio();

      void agregarVertice(V dato);

      void agregarArista(V entrada, V salida, V dato, int peso);

      void mostrar();

      void recorrer(V desdeVertice);

      void imprimirCaminoMinimo(V origen, V destino);

   private:
      std::priority_queue<int*, vector<int*>, comparador> ColaDePrioridad;

      void procesarVertice(Vertice<V> * vertice);

      void marcarTodosLosVerticesComoNoVisitados();

      void dijkstra(Vertice<V> * origen);

      void optimizarDistancias(Vertice<V> * actual, Vertice<V> * adyacente, int peso);

      void imprimirVerticeCaminoMinimo(V datoVertice);

      void generarCaminosMinimos(V origen);

      ListaEnlazada< Vertice<V>* > * vertices;

      Cola< Vertice<V>* > * cola;


};

template<class V>
Grafo<V>::Grafo() {
   this->vertices = new ListaEnlazada< Vertice<V>* >();
   this->cola = new Cola< Vertice<V>* >();
}

template<class V>
bool Grafo<V>::estaVacio() {
   return this->vertices->estaVacia();
}

template<class V>
Vertice<V> * Grafo<V>::obtenerVertice(V dato) {
   this->vertices->iniciarCursor();
   bool encontrado = false;
   Vertice<V> * vertice;

   while(!encontrado && this->vertices->avanzarCursor()) {
      vertice = this->vertices->obtenerCursor();
      encontrado = (vertice->obtenerDato() == dato);
   }

   if (!encontrado)
      throw("ERR: El vertice no existe");

   return vertice;
}

template<class V>
bool Grafo<V>::existeVertice(V dato) {
   bool encontrado = false;

   this->vertices->iniciarCursor();
   while(!encontrado && this->vertices->avanzarCursor()) {
      encontrado = (this->vertices->obtenerCursor()->obtenerDato() == dato);
   }
   return encontrado;
}

template<class V>
void Grafo<V>::agregarVertice(V dato) {
   if (!this->existeVertice(dato)) {
      Vertice<V> * vertice = new Vertice<V>(dato);
      this->vertices->agregar(vertice);
   }
}

template<class V>
void Grafo<V>::agregarArista(V entrada, V salida, V dato, int peso) {
   if (!this->existeVertice(entrada)) {
      this->agregarVertice(entrada);
   }
   Vertice<V> * vEntrada = this->obtenerVertice(entrada);

   if (!this->existeVertice(salida)) {
      this->agregarVertice(salida);
   }
   Vertice<V> * vSalida = this->obtenerVertice(salida);

   Arista<V> * arista = new Arista<V>(dato, vEntrada, vSalida, peso);
   vEntrada->agregarArista(arista);
}

template<class V>
void Grafo<V>::mostrar() {
   this->vertices->iniciarCursor();
   while(this->vertices->avanzarCursor()) {
      this->vertices->obtenerCursor()->mostrar();
   }
}

template<class V>
void Grafo<V>::procesarVertice(Vertice<V> * vertice) {
   ListaEnlazada< Arista<V>* > * aristas = vertice->obtenerAristas();
   aristas->iniciarCursor();
   while(aristas->avanzarCursor()) {
      std::cout << "Acolo Vertice Adyacente: ";
      std::cout << aristas->obtenerCursor()->obtenerSalida()->obtenerDato() << std::endl;

      this->cola->acolar(aristas->obtenerCursor()->obtenerSalida());
   }
}

template<class V>
void Grafo<V>::marcarTodosLosVerticesComoNoVisitados() {
   this->vertices->iniciarCursor();
   while(this->vertices->avanzarCursor()) {
      this->vertices->obtenerCursor()->marcarComoNoVisitado();
   }
}

template<class V>
void Grafo<V>::recorrer(V desde) {
   std::cout << "Recorrido Grafo en anchura" << std::endl;

   this->marcarTodosLosVerticesComoNoVisitados();

   Vertice<V> * vertice = this->obtenerVertice(desde);
   this->cola->acolar(vertice);

   while(!this->cola->estaVacia()) {
      vertice = this->cola->desacolar();

      if (!vertice->fueVisitado()) {
         std::cout << "Proceso Vertice: ";

         this->procesarVertice(vertice);
         vertice->marcarComoVisitado();
      }
   }
}

template<class V>
void Grafo<V>::imprimirVerticeCaminoMinimo(V datoVertice) {
   Vertice<V> * vertice = this->obtenerVertice(datoVertice);
   if(vertice->tieneAnterior()) {
      this->imprimirVerticeCaminoMinimo(vertice->obtenerAnterior()->obtenerDato());
      std::cout << vertice->obtenerDato() << std::endl;
   }
}

template<class V>
void Grafo<V>::imprimirCaminoMinimo(V origen, V destino) {
   this->generarCaminosMinimos(origen);
   this->imprimirVerticeCaminoMinimo(destino);
}

template<class V>
void Grafo<V>::optimizarDistancias(Vertice<V> * actual, Vertice<V> * adyacente, int peso) {
   if ((actual->obtenerPesoArista() + peso) < adyacente->obtenerPesoArista()) {
      adyacente->guardarPesoArista(actual->obtenerPesoArista() + peso);
      adyacente->guardarAnterior(actual);

      int * nuevo = new int[2];
      nuevo[0] = adyacente->obtenerDato();
      nuevo[1] = adyacente->obtenerPesoArista();
      ColaDePrioridad.push(nuevo);
   }
}

template<class V>
void Grafo<V>::dijkstra(Vertice<V> * origen) {
   int * elemento = new int[2];
   elemento[0] = origen->obtenerDato();
   elemento[1] = 0;

   ColaDePrioridad.push(elemento);
   origen->guardarPesoArista(0);

   Vertice<V> * verticeActual;
   Vertice<V> * verticeAdyacente;
   V datoVertice;
   ListaEnlazada< Arista<V>* > * aristas;
   Arista<V> * arista;

   while(!ColaDePrioridad.empty()) {
      datoVertice = ColaDePrioridad.top()[0];
      ColaDePrioridad.pop();

      verticeActual = this->obtenerVertice(datoVertice);
      if(!verticeActual->fueVisitado()) {
         verticeActual->marcarComoVisitado();

         // Recorro vertices adyacentes
         aristas = verticeActual->obtenerAristas();
         aristas->iniciarCursor();
         while(aristas->avanzarCursor()) {
            arista = aristas->obtenerCursor();
            verticeAdyacente = arista->obtenerSalida();

            if (!verticeAdyacente->fueVisitado()) {
               this->optimizarDistancias(verticeActual, verticeAdyacente, arista->obtenerPeso());
            }
         }
      }
   }
}

template<class V>
void Grafo<V>::generarCaminosMinimos(V origen) {
   // Primero inicializo todos los vertices con pesoArista = MAX_PESO_ARISTA
   this->vertices->iniciarCursor();
   while(this->vertices->avanzarCursor()) {
      this->vertices->obtenerCursor()->guardarPesoArista(MAX_PESO_ARISTA); // distancia
   }
   this->marcarTodosLosVerticesComoNoVisitados();

   this->dijkstra(this->obtenerVertice(origen));
}

#endif