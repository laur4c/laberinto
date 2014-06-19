#include "cabeceras/Laberinto.h"

#include <iostream>

using namespace std;

Laberinto::Laberinto() {
   this->caminos = new ListaEnlazada<Camino*>();
   this->mochila = new Mochila();
   this->bifurcaciones = new ListaEnlazada<Punto*>();
   this->empalmes = new ListaEnlazada<Punto*>();
   this->info = new InfoRecorrido();
}

ListaEnlazada<Camino*> * Laberinto::obtenerCaminos() {
   return this->caminos;
}

void Laberinto::mostrarInfo() {
   this->info->mostrar();
}

Mochila * Laberinto::obtenerMochila() {
   return this->mochila;
}

void Laberinto::crearCaminosDesdeListaDeComandos(Cola<Comando*> * comandos) {
   InfoPunto * infoPunto;
   Comando * comando;
   string nombreComando;
   string argumento;
   string strColor;
   int pos;
   Color * colorActual;
   char ultimaOrientacion = 'X'; // por default
   ListaEnlazada<InfoPunto*> * listaInfo;
   InfoPunto * infoPtoAnterior;

   while (!comandos->estaVacia()) {
      comando = comandos->desacolar();
      nombreComando = comando->obtenerNombre();
      argumento = comando->obtenerArgumento();

      if(nombreComando == "PP") { // Punto de partida
         listaInfo = new ListaEnlazada<InfoPunto*>();
         pos = argumento.find(" ", 0);
         strColor = argumento.substr(pos + 1);
         colorActual = util::string_a_color(strColor);
         infoPtoAnterior = NULL;

      } else if(nombreComando == "PLL") { // Punto de llegada
         if (listaInfo == NULL)
            throw "ERR: Archivo de entrada mal definido.";

         this->agregarCamino(colorActual, listaInfo);
         delete listaInfo;
         listaInfo = NULL;

      } else if (nombreComando == "G") { // Giro
         this->info->agregarGiro();
         ultimaOrientacion = argumento.c_str()[0];

      } else if (nombreComando == "L") { // Levantar objeto
         this->mochila->agregar(argumento);

      } else if (nombreComando == "A" || nombreComando == "R" || nombreComando == "U" || nombreComando == "B") {
         if (nombreComando == "B") {
            // y si el primer comando es una Bifurcacion??
            // se agrega un punto a la lista con pasos = 0 porque ante una bifurcacion no se avanzan pasos
            infoPunto = this->obtenerInfoBifurcacionDeComando(argumento, ultimaOrientacion);
         } else {
            infoPunto = this->obtenerInfoDeComando(nombreComando, argumento, ultimaOrientacion);
            infoPtoAnterior = infoPunto;
         }
         listaInfo->agregar(infoPunto);

      } else if(nombreComando == "T") {
         this->tirarElementoEnPuntoAnterior(infoPtoAnterior, argumento);

      } else
         throw "ERR: Comando Invalido";
   }

   this->unirPuntos();
}

InfoPunto * Laberinto::obtenerInfoDeComando(std::string comando, std::string argumento, char orientacion) {
   string empalme = "";
   int pasos = 0;

   if(comando == "A") {
      pasos = util::string_a_int(argumento);

   } else if(comando == "R") {
      orientacion = util::obtener_orientacion_contraria(orientacion);
      pasos = util::string_a_int(argumento);

   } else if (comando == "U") {
      this->info->agregarUnion();

      empalme = argumento;
   }

   this->info->agregarPasos(abs(pasos));

   InfoPunto * infoPunto = new InfoPunto(orientacion, pasos, false);
   infoPunto->cambiarEmpalme(empalme);

   return infoPunto;
}

InfoPunto * Laberinto::obtenerInfoBifurcacionDeComando(std::string infoBifurcacion, char orientacion) {
   this->info->agregarBifurcacion();

   int pos = infoBifurcacion.find(" ", 0);
   char bifurcacionOrientacion = infoBifurcacion.substr(0, pos).c_str()[0];
   std::string bifurcacionNombre = infoBifurcacion.substr(pos + 1);

   InfoPunto * infoPunto = new InfoPunto(orientacion, 0, false);
   infoPunto->cambiarBifurcacion(bifurcacionNombre, bifurcacionOrientacion);
   return infoPunto;
}

void Laberinto::tirarElementoEnPuntoAnterior(InfoPunto * infoPtoAnterior, std::string objeto) {
   this->mochila->quitar(objeto);
   infoPtoAnterior->marcarConObjeto();
}

void Laberinto::unirPuntos() {
   Punto * ptoEmpalme;
   Punto * ptoBifurcacion;
   InfoPunto * infoPunto;

   string nombreEmpalme;
   bool encontrado;

   Punto * ptoSiguiente;
   char orientacionEmpalme;
   char orientacionBifurcacion;

   // recorremos todas las uniones y las unimos con las correspondientes bifurcaciones
   this->empalmes->iniciarCursor();
   while(this->empalmes->avanzarCursor()) {
      ptoEmpalme = this->empalmes->obtenerCursor();
      nombreEmpalme = ptoEmpalme->obtenerInformacion()->obtenerEmpalme();

      // buscamos la bifurcacion
      this->bifurcaciones->iniciarCursor();
      encontrado = false;

      while(!encontrado && this->bifurcaciones->avanzarCursor()) {
         ptoBifurcacion = this->bifurcaciones->obtenerCursor();
         infoPunto = ptoBifurcacion->obtenerInformacion();

         if (infoPunto->obtenerBifurcacion() == nombreEmpalme) {
            encontrado = true;

            orientacionBifurcacion = infoPunto->obtenerOrientacionDeBifurcacion();
            orientacionEmpalme = util::obtener_orientacion_contraria(orientacionBifurcacion);

            ptoBifurcacion->cambiarPunto(orientacionBifurcacion, ptoEmpalme);

            if (!ptoEmpalme->tienePuntoEn(orientacionEmpalme)) {
               ptoEmpalme->cambiarPunto(orientacionEmpalme, ptoBifurcacion);
            } else {
               ptoSiguiente = ptoEmpalme->obtenerPunto(orientacionEmpalme);
               ptoEmpalme->cambiarPunto(orientacionEmpalme, ptoBifurcacion);
               ptoBifurcacion->cambiarPunto(orientacionEmpalme, ptoSiguiente);
            }
         }
      }
   }
}

void Laberinto::agregarCamino(Color * color, ListaEnlazada<InfoPunto*> * listaInfo) {
   InfoPunto * infoPunto;
   char orientacion;
   Camino * camino = new Camino();

   // Agrego el primer punto del camino
   listaInfo->iniciarCursor();
   listaInfo->avanzarCursor();

   infoPunto = listaInfo->obtenerCursor();
   camino->cambiarComienzo(new Punto(infoPunto, color));
   camino->cambiarFin(camino->obtenerComienzo());

   if (infoPunto->tieneBifurcacion()) {
      this->bifurcaciones->agregar(camino->obtenerComienzo());
   }

   if (infoPunto->tieneEmpalme()) {
      this->empalmes->agregar(camino->obtenerComienzo());
      camino->marcarEmpalme();
   }

   Punto * siguiente;
   // Agrego los siguientes puntos del camino
   while(listaInfo->avanzarCursor()) {
      infoPunto = listaInfo->obtenerCursor();
      siguiente = new Punto(infoPunto, color);

      orientacion = infoPunto->obtenerOrientacion();
      camino->obtenerFin()->cambiarPunto(orientacion, siguiente);
      siguiente->cambiarPunto(util::obtener_orientacion_contraria(orientacion), camino->obtenerFin());

      camino->cambiarFin(siguiente);

      if (infoPunto->tieneBifurcacion()) {
         this->bifurcaciones->agregar(siguiente);
      }

      if (infoPunto->tieneEmpalme()) {
         this->empalmes->agregar(siguiente);
         camino->marcarEmpalme();
      }
   }
   this->caminos->agregar(camino);
}

void Laberinto::generarArista(Grafo<std::string> * grafo, Cola<Comando*> * componentes) {
   Comando * comando;
   string nombreVertice;
   string nombre;
   string argumento;
   int pos;

   int peso = 0;
   string nombreArista = "NombreArista-AUTO";
   string entrada = "";
   string salida = "";

   while (!componentes->estaVacia()) {
      comando = componentes->desacolar();
      nombre = comando->obtenerNombre();
      argumento = comando->obtenerArgumento();

      if (nombre == "PP") {
         pos = argumento.find(" ", 0);
         entrada = argumento.substr(0, pos);

      } else if (nombre == "PLL" || nombre == "U") {
         salida = argumento;

      } else if (nombre == "A") {
         peso += util::string_a_int(argumento);

      } else if (nombre == "B") {
         pos = argumento.find(" ", 0);
         nombreVertice = argumento.substr(pos + 1);
         if (entrada == "") {
            entrada = nombreVertice;
         } else {
            salida = nombreVertice;
         }

      } else if (nombre == "G") {
         nombreArista = "Arista" + argumento;
         if (entrada == "") {
            entrada = argumento;
         } else if(componentes->estaVacia()) {
            salida = argumento;
         }
      }
   }
   grafo->agregarArista(entrada, salida, nombreArista, peso);
}

Grafo<std::string> * Laberinto::crearGrafoDesdeListaDeComandos(Cola<Comando*> * comandos) {
   Comando * comando;
   string nombre;
   string argumento;
   string ultimaOrientacion = "";
   string orientacionActual;

   Grafo<string> * grafo = new Grafo<string>();
   Cola<Comando*> * componentesArista = new Cola<Comando*>();

   while (!comandos->estaVacia()) {
      comando = comandos->desacolar();
      nombre = comando->obtenerNombre();
      argumento = comando->obtenerArgumento();

      if (nombre == "PP" || nombre == "A") {
         componentesArista->acolar(comando);

      } else if (nombre == "U" || nombre == "B" || nombre == "PLL" || nombre == "G") {
         componentesArista->acolar(comando);

         if (nombre == "G") {
            orientacionActual = argumento;
            if (ultimaOrientacion != "" && orientacionActual != ultimaOrientacion) {
               this->generarArista(grafo, componentesArista);
               componentesArista->acolar(comando);
            }
         } else {
            this->generarArista(grafo, componentesArista);
            if (nombre != "PLL")
               componentesArista->acolar(comando);
         }


      }

   }

   return grafo;
}

Laberinto::~Laberinto() {
   this->caminos->iniciarCursor();
   while(this->caminos->avanzarCursor()) {
      delete this->caminos->obtenerCursor();
   }
}

