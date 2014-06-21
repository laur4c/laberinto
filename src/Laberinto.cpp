#include "cabeceras/Laberinto.h"

#include <iostream>

using namespace std;

Laberinto::Laberinto() {
   this->mochila = new Mochila();
   this->info = new InfoRecorrido();
}

void Laberinto::mostrarInfo() {
   this->info->mostrar();
}

Mochila * Laberinto::obtenerMochila() {
   return this->mochila;
}

void Laberinto::generarArista(Grafo<std::string> * grafo, Color * color, Cola<Comando*> * componentes, char ultimaOrientacion) {
   Comando * comando;
   string vertice, nombre, argumento, arista;
   ListaEnlazada<Tramo*> * tramos = new ListaEnlazada<Tramo*>();

   int pos, longitud;
   int peso = 0;
   bool tiroObjeto = false;

   string entrada = "";
   string salida = "";

   while (!componentes->estaVacia()) {
      comando = componentes->desacolar();
      nombre = comando->obtenerNombre();
      argumento = comando->obtenerArgumento();

      if (nombre == "PP") {
         pos = argumento.find(" ", 0);
         entrada = argumento.substr(0, pos);

      } else if (nombre == "PLL") {
         salida = argumento;

      } else if (nombre == "U") {
         if (entrada == "") {
            entrada = argumento;
         } else {
            salida = argumento;
         }

      } else if (nombre == "B") {
         pos = argumento.find(" ", 0);
         vertice = argumento.substr(pos + 1);
         if (entrada == "") {
            entrada = vertice;
         } else {
            salida = vertice;
         }
      } else if (nombre == "T") {
         tiroObjeto = true;

      } else if (nombre == "A") {
         longitud = util::string_a_int(argumento);
         tramos->agregar(new Tramo(ultimaOrientacion, longitud, tiroObjeto, color));
         tiroObjeto = false;
         peso += longitud;

      } else if (nombre == "G") {
         ultimaOrientacion = argumento.c_str()[0];
      }
   }
   arista = "arista-" + entrada + "-" + salida;
   grafo->agregarArista(entrada, salida, arista, peso, tramos);
}

Grafo<std::string> * Laberinto::crearGrafoDesdeListaDeComandos(Cola<Comando*> * comandos) {
   Comando * comando;
   string nombre, argumento, orientacionContraria, ultimaOrientacion;
   Color * color;

   Grafo<string> * grafo = new Grafo<string>();
   Cola<Comando*> * componentesArista = new Cola<Comando*>();
   bool existeVerticeEntrada = false;

   while (!comandos->estaVacia()) {
      comando = comandos->desacolar();
      nombre = comando->obtenerNombre();
      argumento = comando->obtenerArgumento();

      if (nombre == "PP") {
         color = util::string_a_color(argumento.substr(argumento.find(" ", 0) + 1));
      }
      if (nombre != "R") {
         componentesArista->acolar(comando);
      }

      // Si el comando genera un vertice...
      if (nombre == "PP" || nombre == "B" || nombre == "U" || nombre == "PLL") {
         if (nombre == "U") {
            this->info->agregarUnion();
         } else if (nombre == "B") {
            this->info->agregarBifurcacion();
         }


         if (existeVerticeEntrada) {
            this->generarArista(grafo, color, componentesArista, ultimaOrientacion.c_str()[0]);

            if (nombre != "PLL") {
               // acolo de nuevo el comando ya que va a ser la entrada de la
               // arista siguiente, salvo el punto de llegada (PLL)
               componentesArista->acolar(comando);
               existeVerticeEntrada = true;
            } else {
               existeVerticeEntrada = false;
            }

         } else {
            existeVerticeEntrada = true;
         }
      } else if (nombre == "G") {
         this->info->agregarGiro();
         ultimaOrientacion = argumento;

      } else if (nombre == "R") { // retroceder es igual a girar hacia el sentido contrario y avanzar
         orientacionContraria = util::char_a_string(util::obtener_orientacion_contraria(ultimaOrientacion.c_str()[0]));

         componentesArista->acolar(new Comando("G", orientacionContraria));
         componentesArista->acolar(new Comando("A", argumento));
         this->info->agregarPasos(util::string_a_int(argumento));

      }

      if (nombre == "A") {
         this->info->agregarPasos(util::string_a_int(argumento));
      } else if(nombre == "L") {
         this->mochila->agregar(argumento);
      } else if(nombre == "T") {
         this->mochila->quitar(argumento);
      }
   }
   return grafo;
}

Laberinto::~Laberinto() {
}










