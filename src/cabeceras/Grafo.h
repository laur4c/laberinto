/**
   Laberinto - TP 1
   Grafo: Implementacion con listas enlazadas
   Grafo dirigido ponderado

   @author Laura Corvalan
*/

#ifndef _GRAFO_H_
#define _GRAFO_H_

#include "ListaEnlazada.h"
#include "Vertice.h"
#include "Arista.h"
#include "Cola.h"
#include "Color.h"

#include <iostream>
#include <queue>
#include <vector>

#define MAX_PESO_ARISTA 100000

template<typename A, typename V> class Grafo {
   public:

      /**
       * Constructor
       */
      Grafo();

      /**
       * Retorna vertice por su nombre
       */
      Vertice<V,A> * obtenerVertice(std::string nombre);

      /**
       * Retorna el primer vertice agregado a la lista
       */
      Vertice<V,A> * obtenerPrimerVertice();

      /**
       * Retorna true si el grafo no contiene vertices
       */
      bool estaVacio();

      /**
       * Agrega vertice con nombre = dato. Si el vertice ya existe, no se hace nada.
       */
      void agregarVertice(std::string nombre, V dato);

      /**
       * Agrega arista al grafo. Si alguno de los vertices (entrada y salida) no existen, se agregan
       */
      void agregarArista(std::string nombre, std::string entrada, std::string salida, A dato, int peso);

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
      Vertice<V,A> * obtenerVerticeRecorridoActual();

      struct comparador {
         bool operator() (pair<std::string, int> a, pair<std::string, int> b) {
            return a.second > b.second;
         }
      };

      /**
       * Agrega a la cola los vertices adyacentes.
       * Metodo invocado para recorrer todos los vertices del grafo
       */
      void procesarVertice(Vertice<V,A> * vertice);

      /**
       * Setea en false el atributo visitado de cada vertice del grafo
       */
      void marcarTodosLosVerticesComoNoVisitados();

      /**
       * Genera caminos minimos utilizando el algoritmo de Dijkstra
       */
      void generarCaminosMinimos(std::string origen);

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
      void imprimirCaminoMinimo(std::string origen, std::string destino);

      ~Grafo();
   private:
      /**
       * Cola de prioridad
       */
      std::priority_queue<pair<std::string, int>, vector< pair<std::string, int> >, comparador> ColaDePrioridad;

      /**
       * Vertice cursor
       */
      Vertice<V,A> * verticeActual;

      /**
       * Cola para recorrido en anchura
       */
      Cola< Vertice<V,A>* > * colaParaRecorrido;

      /**
       * Almacena todos los vertices del grafo
       */
      ListaEnlazada< Vertice<V,A>* > * vertices;

      /**
       * Almacena todas las aristas del grafo
       */
      ListaEnlazada< Arista<A,V>* > * aristas;

      /**
       * Almacena todos los tramos de las aristas del grafo
       */
      ListaEnlazada<A> * datosAristas;

      /**
       * Retorna true si el vertice existe en el grafo
       */
      bool existeVertice(std::string nombre);

      /**
       * Aplica algoritmo de Dijkstra para calculo de caminos minimos
       */
      void dijkstra(Vertice<V,A> * origen);

      /**
       * Se agregan a la cola de prioridad los trayectos mas cortos, para obtener mejoras
       * en cuanto al recorrido del camino
       */
      void optimizarDistancias(Vertice<V,A> * actual, Vertice<V,A> * adyacente, int peso);

      /**
       * Imprime en consola vertices a seguir para recorrer el camino minimo
       */
      void imprimirVerticeCaminoMinimo(std::string nombreVertice);

      /**
       * Medio fulero, pero elimina todos los datos de los nodos de las listas
       * Ver destructor
       */
      void borrarDatosLista(ListaEnlazada< Vertice<V,A>* > * lista);

      void borrarDatosLista(ListaEnlazada<A> * lista);

      void borrarDatosLista(ListaEnlazada< Arista<A,V>* > * lista);
};

template<typename A, typename V>
Grafo<A,V>::Grafo() {
   this->vertices = new ListaEnlazada< Vertice<V,A>* >();
   this->aristas = new ListaEnlazada< Arista<A,V>* >();
   this->datosAristas = new ListaEnlazada<A>();
   this->colaParaRecorrido = new Cola< Vertice<V,A>* >();
   this->verticeActual = NULL;
}

template<typename A, typename V>
bool Grafo<A,V>::estaVacio() {
   return this->vertices->estaVacia();
}

template<typename A, typename V>
Vertice<V,A> * Grafo<A,V>::obtenerVertice(std::string nombre) {
   this->vertices->iniciarCursor();
   bool encontrado = false;
   Vertice<V,A> * vertice;

   while(!encontrado && this->vertices->avanzarCursor()) {
      vertice = this->vertices->obtenerCursor();
      encontrado = (vertice->obtenerNombre() == nombre);
   }

   if (!encontrado)
      throw("ERR: El vertice no existe");

   return vertice;
}

template<typename A, typename V>
bool Grafo<A,V>::existeVertice(std::string nombre) {
   bool encontrado = false;

   this->vertices->iniciarCursor();
   while(!encontrado && this->vertices->avanzarCursor()) {
      encontrado = (this->vertices->obtenerCursor()->obtenerNombre() == nombre);
   }
   return encontrado;
}

template<typename A, typename V>
void Grafo<A,V>::agregarVertice(std::string nombre, V dato) {
   if (!this->existeVertice(nombre)) {
      Vertice<V,A> * vertice = new Vertice<V,A>(nombre, NULL);
      this->vertices->agregar(vertice);
   }
}

template<typename A, typename V>
void Grafo<A,V>::agregarArista(std::string nombre, std::string entrada, std::string salida, A dato, int peso) {
   if (!this->existeVertice(entrada)) {
      this->agregarVertice(entrada, NULL);
   }
   Vertice<V,A> * vEntrada = this->obtenerVertice(entrada);

   if (!this->existeVertice(salida)) {
      this->agregarVertice(salida, NULL);
   }
   Vertice<V,A> * vSalida = this->obtenerVertice(salida);

   Arista<A,V> * arista = new Arista<A,V>(nombre, dato, vEntrada, vSalida, peso);
   vEntrada->agregarArista(arista);

   // agrego la inversa para poder recorrer todo el grafo desde un vertice
   Arista<A,V> * aristaInversa = new Arista<A,V>(nombre, dato, vSalida, vEntrada, peso);
   aristaInversa->marcarSentidoContrario();
   vSalida->agregarArista(aristaInversa);

   this->aristas->agregar(arista);
   this->aristas->agregar(aristaInversa);

   // tramos->iniciarCursor();
   // while(tramos->avanzarCursor()) {
   //    this->tramos->agregar(tramos->obtenerCursor());
   // }

}

template<typename A, typename V>
void Grafo<A,V>::mostrar() {
   this->vertices->iniciarCursor();
   while(this->vertices->avanzarCursor()) {
      this->vertices->obtenerCursor()->mostrar();
   }
}

template<typename A, typename V>
Vertice<V,A> * Grafo<A,V>::obtenerPrimerVertice() {
   this->vertices->iniciarCursor();
   this->vertices->avanzarCursor();
   return this->vertices->obtenerCursor();
}

template<typename A, typename V>
void Grafo<A,V>::procesarVertice(Vertice<V,A> * vertice) {
   ListaEnlazada< Arista<A,V>* > * aristas = vertice->obtenerAristas();
   aristas->iniciarCursor();

   while(aristas->avanzarCursor()) {
      this->colaParaRecorrido->acolar(aristas->obtenerCursor()->obtenerSalida());
   }
}

template<typename A, typename V>
void Grafo<A,V>::marcarTodosLosVerticesComoNoVisitados() {
   this->vertices->iniciarCursor();
   while(this->vertices->avanzarCursor()) {
      this->vertices->obtenerCursor()->marcarComoNoVisitado();
   }
}

template<typename A, typename V>
void Grafo<A,V>::iniciarRecorridoEnAnchura() {
   this->iniciarRecorridoEnAnchura(this->obtenerPrimerVertice()->obtenerNombre());
}

template<typename A, typename V>
void Grafo<A,V>::iniciarRecorridoEnAnchura(V desde) {
   this->marcarTodosLosVerticesComoNoVisitados();

   Vertice<V,A> * vertice = this->obtenerVertice(desde);

   this->colaParaRecorrido->acolar(vertice);
}

template<typename A, typename V>
bool Grafo<A,V>::avanzarRecorridoEnAnchura() {
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

template<typename A, typename V>
Vertice<V,A> * Grafo<A,V>::obtenerVerticeRecorridoActual() {
   Vertice<V,A> * vertice;
   if (this->verticeActual != NULL) {
      vertice = this->verticeActual;
   }
   return vertice;
}

template<typename A, typename V>
void Grafo<A,V>::imprimirVerticeCaminoMinimo(std::string nombreVertice) {
   Vertice<V,A> * vertice = this->obtenerVertice(nombreVertice);
   if(vertice->tieneAnterior()) {
      this->imprimirVerticeCaminoMinimo(vertice->obtenerAnterior()->obtenerNombre());
   }
}

template<typename A, typename V>
void Grafo<A,V>::imprimirCaminoMinimo(std::string origen, std::string destino) {
   this->generarCaminosMinimos(origen);
   this->imprimirVerticeCaminoMinimo(destino);
}

template<typename A, typename V>
void Grafo<A,V>::optimizarDistancias(Vertice<V,A> * actual, Vertice<V,A> * adyacente, int peso) {
   if (adyacente->obtenerPesoArista() > (actual->obtenerPesoArista() + peso)) {
      adyacente->guardarPesoArista(actual->obtenerPesoArista() + peso);
      adyacente->guardarAnterior(actual);

      pair<std::string, int> nuevo;
      nuevo.first = adyacente->obtenerNombre();
      nuevo.second = adyacente->obtenerPesoArista();
      ColaDePrioridad.push(nuevo);
   }
}

template<typename A, typename V>
void Grafo<A,V>::dijkstra(Vertice<V,A> * origen) {
   pair<V, int> elemento;
   elemento.first = origen->obtenerDato();
   elemento.second = 0;

   ColaDePrioridad.push(elemento);
   origen->guardarPesoArista(0);

   Vertice<V,A> * verticeActual;
   Vertice<V,A> * verticeAdyacente;
   std::string nombreVertice;
   ListaEnlazada< Arista<A,V>* > * aristas;
   Arista<A,V> * arista;

   while(!ColaDePrioridad.empty()) {
      nombreVertice = ColaDePrioridad.top().first;
      ColaDePrioridad.pop();

      verticeActual = this->obtenerVertice(nombreVertice);
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

template<typename A, typename V>
void Grafo<A,V>::generarCaminosMinimos(std::string origen) {
   // Primero inicializo todos los vertices con pesoArista = MAX_PESO_ARISTA
   this->vertices->iniciarCursor();
   while(this->vertices->avanzarCursor()) {
      this->vertices->obtenerCursor()->guardarPesoArista(MAX_PESO_ARISTA); // distancia
   }
   this->marcarTodosLosVerticesComoNoVisitados();

   this->dijkstra(this->obtenerVertice(origen));
}

template<typename A, typename V>
void Grafo<A,V>::borrarDatosLista(ListaEnlazada< Vertice<V,A>* > * lista) {
   lista->iniciarCursor();
   Vertice<V,A> * aBorrar;

   lista->avanzarCursor();
   Vertice<V,A> * siguiente = lista->obtenerCursor();

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

template<typename A, typename V>
void Grafo<A,V>::borrarDatosLista(ListaEnlazada< Arista<A,V>* > * lista) {
   lista->iniciarCursor();
   Arista<A,V> * aBorrar;

   lista->avanzarCursor();
   Arista<A,V> * siguiente = lista->obtenerCursor();

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

template<typename A, typename V>
void Grafo<A,V>::borrarDatosLista(ListaEnlazada<A> * lista) {
   lista->iniciarCursor();
   A aBorrar;

   lista->avanzarCursor();
   A siguiente = lista->obtenerCursor();

   while(siguiente != NULL) {
      aBorrar = siguiente;
      if (lista->avanzarCursor()) {
         siguiente = lista->obtenerCursor();

      } else
         siguiente = NULL;

      delete aBorrar;
   }
   delete this->datosAristas;
}

template<typename A, typename V>
Grafo<A,V>::~Grafo() {

   this->borrarDatosLista(this->vertices);
   this->borrarDatosLista(this->aristas);
   this->borrarDatosLista(this->datosAristas);

   delete this->colaParaRecorrido;
}

#endif