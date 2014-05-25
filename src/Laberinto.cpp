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
   if (this->mochila->buscar_elemento(elemento)) {
      this->mochila->sumar_elemento();
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

   while (!comandos->estaVacia()) {
      comando = comandos->desacolar();
      nombreComando = comando->obtenerNombre();
      argumento = comando->obtenerArgumento();

      if(nombreComando == "PP") { // Punto de partida
         listaInfo = new ListaEnlazada<InfoPunto*>();
         colorActual = util::string_a_color(argumento);

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

      } else {
         infoPunto = this->obtenerInfoDeComando(nombreComando, argumento, ultimaOrientacion);
         listaInfo->agregar(infoPunto);
      }
   }

   this->unirPuntos();
}

InfoPunto * Laberinto::obtenerInfoDeComando(std::string comando, std::string argumento, char orientacion) {
   string bifurcacion = "";
   string empalme = "";
   int pasos = 0;
   bool tieneObjeto = false;

   if(comando == "A") {
      pasos = util::string_a_int(argumento);

   } else if(comando == "R") {
      pasos = util::string_a_int(argumento) * -1;

   } else if(comando == "B") {
      this->info->sumar_bifurcacion();

      int pos = argumento.find(" ", 0);
      orientacion = argumento.substr(0, pos).c_str()[0];
      bifurcacion = argumento.substr(pos + 1);

   } else if (comando == "U") {
      this->info->sumar_union();

      empalme = argumento;
      pasos = 1;

   } else if (comando == "T") {
      if (this->mochila->buscar_elemento(argumento)) {
         tieneObjeto = true;
         this->mochila->tirar_elemento();
      } else
         throw "ERR: Se intenta tirar un elemento que no se encuentra en la Mochila";

   } else
      throw "ERR: Comando Invalido";

   this->info->sumar_pasos(abs(pasos));

   InfoPunto * infoPunto = new InfoPunto(orientacion, pasos, tieneObjeto);
   infoPunto->cambiarBifurcacion(bifurcacion);
   infoPunto->cambiarEmpalme(empalme);

   return infoPunto;
}

void Laberinto::unirPuntos() {
   Punto * ptoEmpalme;
   Punto * ptoBifurcacion;
   InfoPunto * infoPunto;

   string nombreEmpalme;
   bool encontrado;

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
            ptoBifurcacion->cambiarPunto(infoPunto->obtenerOrientacion(), ptoEmpalme);
            ptoEmpalme->cambiarPunto(ptoEmpalme->obtenerInformacion()->obtenerOrientacion(), ptoBifurcacion);
         }
      }
   }
}

void Laberinto::agregarCamino(Color * color, ListaEnlazada<InfoPunto*> * listaInfo) {
   InfoPunto * infoPunto;
   char orientacion;
   Camino * camino = new Camino();

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

   while(listaInfo->avanzarCursor()) {
      infoPunto = listaInfo->obtenerCursor();
      siguiente = new Punto(infoPunto, color);

      orientacion = infoPunto->obtenerOrientacion();
      camino->obtenerFin()->cambiarPunto(orientacion, siguiente);
      siguiente->cambiarPunto(this->obtenerOrientacionContraria(orientacion), camino->obtenerFin());
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

char Laberinto::obtenerOrientacionContraria(char orientacion) {
   char orientacionContraria;

   if (orientacion == 'E') {
      orientacionContraria = 'O';

   } else if (orientacion == 'O') {
      orientacionContraria = 'E';

   } else if (orientacion == 'S') {
      orientacionContraria = 'N';

   } else if (orientacion == 'N') {
      orientacionContraria = 'S';

   } else
      throw "ERR: Orientacion Invalida";

   return orientacionContraria;
}

Laberinto::~Laberinto() {
   this->caminos->iniciarCursor();
   while(this->caminos->avanzarCursor()) {
      delete this->caminos->obtenerCursor();
   }
}

