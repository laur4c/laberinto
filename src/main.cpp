#include <iostream>

#include "NodoCasillero.cpp"
#include "Estructura.cpp"

#include "ImagenLaberinto.cpp"

#include "Parser.h"
#include "Laberinto.h"

using namespace std;


int main(int argc, char *argv[]) {
   string nombreArchivo;
   cout << "Ingrese el path del archivo: ";
   // cin >> nombreArchivo;
   nombreArchivo = "/home/laurac/src/fiuba/tp1/pepe.txt";
   Parser parser(nombreArchivo);
   parser.iniciar();

   Cola<Comando*> * listaComandos = parser.obtenerLista();
   cout << "Lista de comandos" << endl;
   listaComandos->mostrar();

   Laberinto laberinto;
   laberinto.crearCaminosDesdeListaDeComandos(listaComandos);

   Mochila * mochila = laberinto.obtenerMochila();
   cout << "Mochila: " << endl;
   mochila->mostrar();

   ListaEnlazada<Camino*> * caminos = laberinto.obtenerCaminos();
   caminos->mostrar();

   Camino * camino;
   Casillero * casillero;
   NodoCasillero * nodoCasillero;
   ListaEnlazada<Casillero*> * recorrido;
   Estructura * estructura;

   ListaEnlazada<Estructura*> * estructuras = new ListaEnlazada<Estructura*>();

   ListaEnlazada<NodoCasillero*> * bifurcaciones = new ListaEnlazada<NodoCasillero*>();
   ListaEnlazada<NodoCasillero*> * empalmes = new ListaEnlazada<NodoCasillero*>();

   caminos->iniciarCursor();
   while(caminos->avanzarCursor()) {
      camino = caminos->obtenerCursor();
      recorrido = camino->obtenerRecorrido();

      estructura = new Estructura();

      recorrido->iniciarCursor();
      recorrido->avanzarCursor();

      casillero = recorrido->obtenerCursor();
      nodoCasillero = new NodoCasillero(casillero);
      // nodoCasillero->cambiarNodo(casillero->obtenerOrientacion(), nodoCasillero);
      if (casillero->obtenerBifurcacion() != "") {
         bifurcaciones->agregar(nodoCasillero);
         estructura->bifurcaciones->agregar(nodoCasillero);
      }
      if (casillero->obtenerEmpalme() != "") {
         empalmes->agregar(nodoCasillero);
         estructura->empalmes->agregar(nodoCasillero);
      }

      estructura->primero = nodoCasillero;
      estructura->ultimo = nodoCasillero;

      while(recorrido->avanzarCursor()) {
         casillero = recorrido->obtenerCursor();
         nodoCasillero = new NodoCasillero(casillero);
         estructura->ultimo->cambiarNodo(casillero->obtenerOrientacion(), nodoCasillero);
         estructura->ultimo = nodoCasillero;

         if (casillero->obtenerBifurcacion() != "") {
            bifurcaciones->agregar(nodoCasillero);
            estructura->bifurcaciones->agregar(nodoCasillero);
         }

         if (casillero->obtenerEmpalme() != "") {
            empalmes->agregar(nodoCasillero);
            estructura->empalmes->agregar(nodoCasillero);
         }
      }
      estructuras->agregar(estructura);
   }

   NodoCasillero * empalme;
   NodoCasillero * bifurcacion;

   string nombreEmpalme;
   bool encontrado;

   empalmes->iniciarCursor();
   while(empalmes->avanzarCursor()) {
      empalme = empalmes->obtenerCursor();
      nombreEmpalme = nodoCasillero->obtenerDato()->obtenerEmpalme();

      // busco entre bifurcaciones
      bifurcaciones->iniciarCursor();
      encontrado = false;
      while(!encontrado && bifurcaciones->avanzarCursor()) {
         bifurcacion = bifurcaciones->obtenerCursor();
         casillero = bifurcacion->obtenerDato();

         if (casillero->obtenerBifurcacion() == nombreEmpalme) {
            encontrado = true;
            bifurcacion->cambiarNodo(casillero->obtenerOrientacion(), empalme);
         }
      }

   }

   ImagenLaberinto * imagen = new ImagenLaberinto(estructuras, 10);
   imagen->generar();

   return 0;
}
