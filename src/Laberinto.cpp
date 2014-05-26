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

void Laberinto::agregarElementoAMochila(std::string elemento) {
   if (this->mochila->existe_elemento(elemento)) {
      this->mochila->sumar_elemento(elemento);
   } else {
      this->mochila->agregar_elemento(elemento);
   }
}

void Laberinto::crearCaminosDesdeListaDeComandos(Cola<Comando*> * comandos) {
   InfoPunto * infoPunto;
   Comando * comando;
   string nombreComando;
   string argumento;
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
         colorActual = util::string_a_color(argumento);
         infoPtoAnterior = NULL;

      } else if(nombreComando == "PLL") { // Punto de llegada
         if (listaInfo == NULL)
            throw "ERR: Archivo de entrada mal definido.";

         this->agregarCamino(colorActual, listaInfo);
         delete listaInfo;
         listaInfo = NULL;

      } else if (nombreComando == "G") { // Giro
         this->info->sumar_giro();
         ultimaOrientacion = argumento.c_str()[0];

      } else if (nombreComando == "L") { // Levantar objeto
         this->agregarElementoAMochila(argumento);

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
      this->info->sumar_union();

      empalme = argumento;
      pasos = 1;
   }

   this->info->sumar_pasos(abs(pasos));

   InfoPunto * infoPunto = new InfoPunto(orientacion, pasos, false);
   infoPunto->cambiarEmpalme(empalme);

   return infoPunto;
}

InfoPunto * Laberinto::obtenerInfoBifurcacionDeComando(std::string infoBifurcacion, char orientacion) {
   this->info->sumar_bifurcacion();

   int pos = infoBifurcacion.find(" ", 0);
   char bifurcacionOrientacion = infoBifurcacion.substr(0, pos).c_str()[0];
   std::string bifurcacionNombre = infoBifurcacion.substr(pos + 1);

   InfoPunto * infoPunto = new InfoPunto(orientacion, 0, false);
   infoPunto->cambiarBifurcacion(bifurcacionNombre, bifurcacionOrientacion);
   return infoPunto;
}

void Laberinto::tirarElementoEnPuntoAnterior(InfoPunto * infoPtoAnterior, std::string objeto) {
   if (this->mochila->existe_elemento(objeto)) {
      this->mochila->tirar_elemento(objeto);
      infoPtoAnterior->marcarConObjeto();

   } else
      throw "ERR: Se intenta tirar un elemento que no se encuentra en la Mochila";
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

Laberinto::~Laberinto() {
   this->caminos->iniciarCursor();
   while(this->caminos->avanzarCursor()) {
      delete this->caminos->obtenerCursor();
   }
}

