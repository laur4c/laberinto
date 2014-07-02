/**
   Laberinto - TP 1
   Grafo: Implementacion con listas enlazadas
   Grafo dirigido ponderado

   @author Laura Corvalan
*/

#ifndef _GRAFO_H_
#define _GRAFO_H_

#include "Vertice.h"
#include "Arista.h"
#include "ListaEnlazada.h"
#include "Cola.h"
#include "Color.h"
#include "Tramo.h"

#include <iostream>
#include <queue>
#include <vector>

#define MAX_PESO_ARISTA 100000

template<class V> class Grafo {
   public:

      /**
       * Constructor
       */
      Grafo();

      /**
       * Retorna vertice por su nombre
       */
      Vertice<V> * obtenerVertice(V dato);

      /**
       * Retorna el primer vertice agregado a la lista
       */
      Vertice<V> * obtenerPrimerVertice();

      /**
       * Retorna true si el grafo no contiene vertices
       */
      bool estaVacio();

      /**
       * Agrega vertice con nombre = dato. Si el vertice ya existe, no se hace nada.
       */
      void agregarVertice(V dato);

      /**
       * Agrega arista al grafo. Si alguno de los vertices (entrada y salida) no existen, se agregan
       */
      void agregarArista(V entrada, V salida, V dato, int peso, ListaEnlazada<Tramo*> * tramos);

      /**
       * Imprime info de vertices y aristas en consola
       */
      void mostrar();

      /**
       * Funciona como los cursores en la lista enlazada, se recorre grafo en anchura.
       * No recibe argumentos y toma como vertice origen el primero insertado en el grafo
       */
      void iniciarRecorridoEnAnchura();

      /**
       * Funciona como los cursores en la lista enlazada, se recorre grafo en anchura
       */
      void iniciarRecorridoEnAnchura(V desde);

      /**
       * Procesa y apunta cursor a vertice siguiente. Se usa una cola para hacer el recorrido
       */
      bool avanzarRecorridoEnAnchura();

      /**
       * Retorna vertice actual (cursor)
       */
      Vertice<V> * obtenerVerticeRecorridoActual();

      struct comparador {
         bool operator() (pair<V, int> a, pair<V, int> b) {
            return a.second > b.second;
         }
      };

      /**
       * Agrega a la cola los vertices adyacentes.
       * Metodo invocado para recorrer todos los vertices del grafo
       */
      void procesarVertice(Vertice<V> * vertice);

      /**
       * Setea en false el atributo visitado de cada vertice del grafo
       */
      void marcarTodosLosVerticesComoNoVisitados();

      /**
       * Genera caminos minimos utilizando el algoritmo de Dijkstra
       */
      void generarCaminosMinimos(V origen);

      /**
       * Ejemplo de Uso. Ver grafo en resources/grafo.png
       * Grafo<int> * grafo = new Grafo<int>();
       * grafo->agregarArista("1", "2", "a", 5);
       * grafo->agregarArista("1", "4", "f", 32);
       * grafo->agregarArista("1", "5", "g", 80);
       * grafo->agregarArista("2", "3", "b", 60);
       * grafo->agregarArista("3", "5", "h", 5);
       * grafo->agregarArista("5", "4", "e", 10);
       * grafo->agregarArista("4", "5", "d", 75);
       * grafo->agregarArista("4", "3", "c", 25);
       * grafo->imprimirCaminoMinimo("1", "3");
       */
      void imprimirCaminoMinimo(V origen, V destino);

      ~Grafo();
   private:
      /**
       * Cola de prioridad
       */
      std::priority_queue<pair<V, int>, vector< pair<V, int> >, comparador> ColaDePrioridad;

      /**
       * Vertice cursor
       */
      Vertice<V> * verticeActual;

      /**
       * Cola para recorrido en anchura
       */
      Cola< Vertice<V>* > * colaParaRecorrido;

      /**
       * Almacena todos los vertices del grafo
       */
      ListaEnlazada< Vertice<V>* > * vertices;

      /**
       * Almacena todas las aristas del grafo
       */
      ListaEnlazada< Arista<V>* > * aristas;

      /**
       * Almacena todos los tramos de las aristas del grafo
       */
      ListaEnlazada< Tramo* > * tramos;

      /**
       * Retorna true si el vertice existe en el grafo
       */
      bool existeVertice(V dato);

      /**
       * Aplica algoritmo de Dijkstra para calculo de caminos minimos
       */
      void dijkstra(Vertice<V> * origen);

      /**
       * Se agregan a la cola de prioridad los trayectos mas cortos, para obtener mejoras
       * en cuanto al recorrido del camino
       */
      void optimizarDistancias(Vertice<V> * actual, Vertice<V> * adyacente, int peso);

      /**
       * Imprime en consola vertices a seguir para recorrer el camino minimo
       */
      void imprimirVerticeCaminoMinimo(V datoVertice);

      /**
       * Medio fulero, pero elimina todos los datos de los nodos de las listas
       * Ver destructor
       */
      void borrarDatosLista(ListaEnlazada< Vertice<V>* > * lista);

      void borrarDatosLista(ListaEnlazada< Tramo* > * lista);

      void borrarDatosLista(ListaEnlazada< Arista<V>* > * lista);
};

template<class V>
Grafo<V>::Grafo() {
   this->vertices = new ListaEnlazada< Vertice<V>* >();
   this->aristas = new ListaEnlazada< Arista<V>* >();
   this->tramos = new ListaEnlazada< Tramo* >();
   this->colaParaRecorrido = new Cola< Vertice<V>* >();
   this->verticeActual = NULL;
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
void Grafo<V>::agregarArista(V entrada, V salida, V dato, int peso, ListaEnlazada<Tramo*> * tramos) {
   if (!this->existeVertice(entrada)) {
      this->agregarVertice(entrada);
   }
   Vertice<V> * vEntrada = this->obtenerVertice(entrada);

   if (!this->existeVertice(salida)) {
      this->agregarVertice(salida);
   }
   Vertice<V> * vSalida = this->obtenerVertice(salida);

   Arista<V> * arista = new Arista<V>(dato, vEntrada, vSalida, peso, tramos);
   vEntrada->agregarArista(arista);

   // agrego la inversa para poder recorrer todo el grafo desde un vertice
   Arista<V> * aristaInversa = new Arista<V>(dato, vSalida, vEntrada, peso, tramos);
   aristaInversa->marcarSentidoContrario();
   vSalida->agregarArista(aristaInversa);

   this->aristas->agregar(arista);
   this->aristas->agregar(aristaInversa);

   tramos->iniciarCursor();
   while(tramos->avanzarCursor()) {
      this->tramos->agregar(tramos->obtenerCursor());
   }

}

template<class V>
void Grafo<V>::mostrar() {
   this->vertices->iniciarCursor();
   while(this->vertices->avanzarCursor()) {
      this->vertices->obtenerCursor()->mostrar();
   }
}

template<class V>
Vertice<V> * Grafo<V>::obtenerPrimerVertice() {
   this->vertices->iniciarCursor();
   this->vertices->avanzarCursor();
   return this->vertices->obtenerCursor();
}

template<class V>
void Grafo<V>::procesarVertice(Vertice<V> * vertice) {
   ListaEnlazada< Arista<V>* > * aristas = vertice->obtenerAristas();
   aristas->iniciarCursor();

   while(aristas->avanzarCursor()) {
      this->colaParaRecorrido->acolar(aristas->obtenerCursor()->obtenerSalida());
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
void Grafo<V>::iniciarRecorridoEnAnchura() {
   this->iniciarRecorridoEnAnchura(this->obtenerPrimerVertice()->obtenerDato());
}

template<class V>
void Grafo<V>::iniciarRecorridoEnAnchura(V desde) {
   this->marcarTodosLosVerticesComoNoVisitados();

   Vertice<V> * vertice = this->obtenerVertice(desde);

   this->colaParaRecorrido->acolar(vertice);
}

template<class V>
bool Grafo<V>::avanzarRecorridoEnAnchura() {
   if (!this->colaParaRecorrido->estaVacia()) {
      this->verticeActual = this->colaParaRecorrido->desacolar();

      if (!this->verticeActual->fueVisitado()) {
         this->procesarVertice(this->verticeActual);
         this->verticeActual->marcarComoVisitado();
      }

   } else {
      this->verticeActual = NULL;
   }
   return this->verticeActual != NULL;
}

template<class V>
Vertice<V> * Grafo<V>::obtenerVerticeRecorridoActual() {
   Vertice<V> * vertice;
   if (this->verticeActual != NULL) {
      vertice = this->verticeActual;
   }
   return vertice;
}

template<class V>
void Grafo<V>::imprimirVerticeCaminoMinimo(V datoVertice) {
   Vertice<V> * vertice = this->obtenerVertice(datoVertice);
   if(vertice->tieneAnterior()) {
      this->imprimirVerticeCaminoMinimo(vertice->obtenerAnterior()->obtenerDato());
   }
}

template<class V>
void Grafo<V>::imprimirCaminoMinimo(V origen, V destino) {
   this->generarCaminosMinimos(origen);
   this->imprimirVerticeCaminoMinimo(destino);
}

template<class V>
void Grafo<V>::optimizarDistancias(Vertice<V> * actual, Vertice<V> * adyacente, int peso) {
   if (adyacente->obtenerPesoArista() > (actual->obtenerPesoArista() + peso)) {
      adyacente->guardarPesoArista(actual->obtenerPesoArista() + peso);
      adyacente->guardarAnterior(actual);

      pair<V, int> nuevo;
      nuevo.first = adyacente->obtenerDato();
      nuevo.second = adyacente->obtenerPesoArista();
      ColaDePrioridad.push(nuevo);
   }
}

template<class V>
void Grafo<V>::dijkstra(Vertice<V> * origen) {
   pair<V, int> elemento;
   elemento.first = origen->obtenerDato();
   elemento.second = 0;

   ColaDePrioridad.push(elemento);
   origen->guardarPesoArista(0);

   Vertice<V> * verticeActual;
   Vertice<V> * verticeAdyacente;
   V datoVertice;
   ListaEnlazada< Arista<V>* > * aristas;
   Arista<V> * arista;

   while(!ColaDePrioridad.empty()) {
      datoVertice = ColaDePrioridad.top().first;
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

template<class V>
void Grafo<V>::borrarDatosLista(ListaEnlazada< Vertice<V>* > * lista) {
   lista->iniciarCursor();
   Vertice<V> * aBorrar;

   lista->avanzarCursor();
   Vertice<V> * siguiente = lista->obtenerCursor();

   while(siguiente != NULL) {
      aBorrar = siguiente;
      if (lista->avanzarCursor()) {
         siguiente = lista->obtenerCursor();

      } else
         siguiente = NULL;

      delete aBorrar;
   }
   delete this->vertices;
}

template<class V>
void Grafo<V>::borrarDatosLista(ListaEnlazada< Arista<V>* > * lista) {
   lista->iniciarCursor();
   Arista<V> * aBorrar;

   lista->avanzarCursor();
   Arista<V> * siguiente = lista->obtenerCursor();

   while(siguiente != NULL) {
      aBorrar = siguiente;
      if (lista->avanzarCursor()) {
         siguiente = lista->obtenerCursor();

      } else
         siguiente = NULL;

      delete aBorrar;
   }
   delete this->aristas;
}

template<class V>
void Grafo<V>::borrarDatosLista(ListaEnlazada< Tramo* > * lista) {
   lista->iniciarCursor();
   Tramo * aBorrar;

   lista->avanzarCursor();
   Tramo * siguiente = lista->obtenerCursor();

   while(siguiente != NULL) {
      aBorrar = siguiente;
      if (lista->avanzarCursor()) {
         siguiente = lista->obtenerCursor();

      } else
         siguiente = NULL;

      delete aBorrar;
   }

   delete this->tramos;
}

template<class V>
Grafo<V>::~Grafo() {

   this->borrarDatosLista(this->vertices);
   this->borrarDatosLista(this->aristas);
   this->borrarDatosLista(this->tramos);

   delete this->colaParaRecorrido;
}

#endif