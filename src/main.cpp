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
   // nombreArchivo = "/home/laurac/src/fiuba/tp1/pepe.txt";
   nombreArchivo = "/tmp/Caminos.txt";
   Parser parser(nombreArchivo);
   parser.iniciar();

   Cola<Comando*> * listaComandos = parser.obtenerLista();
   cout << "Lista de comandos" << endl;
   // listaComandos->mostrar();

   Laberinto laberinto;
   laberinto.crearCaminosDesdeListaDeComandos(listaComandos);
   // Mochila * mochila = laberinto.obtenerMochila();
   // cout << "Mochila: " << endl;
   // mochila->mostrar();

   ListaEnlazada<Camino*> * caminos = laberinto.obtenerCaminos();
   // caminos->mostrar();

   Camino * camino;
   Casillero * casillero;
   NodoCasillero * primero;
   NodoCasillero * siguiente;
   ListaEnlazada<Casillero*> * recorrido;
   Estructura * estructura;

   ListaEnlazada<Estructura*> * estructuras = new ListaEnlazada<Estructura*>();

   ListaEnlazada<NodoCasillero*> * bifurcaciones = new ListaEnlazada<NodoCasillero*>();
   ListaEnlazada<NodoCasillero*> * empalmes = new ListaEnlazada<NodoCasillero*>();
   char orientacionContraria;
   caminos->iniciarCursor();
   while(caminos->avanzarCursor()) {
      camino = caminos->obtenerCursor();
      recorrido = camino->obtenerRecorrido();

      estructura = new Estructura(camino->obtenerColor());

      recorrido->iniciarCursor();
      recorrido->avanzarCursor();

      casillero = recorrido->obtenerCursor();
      primero = new NodoCasillero(casillero);
      primero->color = estructura->color;
      // cout << nodoCasillero << endl;

      if (casillero->obtenerBifurcacion() != "") {
         bifurcaciones->agregar(primero);
         estructura->bifurcaciones->agregar(primero);
      }
      if (casillero->obtenerEmpalme() != "") {
         empalmes->agregar(primero);
         estructura->empalmes->agregar(primero);
      }

      estructura->primero = primero;
      estructura->ultimo = primero;

      while(recorrido->avanzarCursor()) {
         casillero = recorrido->obtenerCursor();
         siguiente = new NodoCasillero(casillero);
         siguiente->color = estructura->color;
         // cout << nodoCasillero << endl;

         estructura->ultimo->cambiarNodo(casillero->obtenerOrientacion(), siguiente);

         if (casillero->obtenerOrientacion() == 'E') {
            orientacionContraria = 'O';
         } else if (casillero->obtenerOrientacion() == 'O') {
            orientacionContraria = 'E';
         } else if (casillero->obtenerOrientacion() == 'S') {
            orientacionContraria = 'N';
         } else if (casillero->obtenerOrientacion() == 'N') {
            orientacionContraria = 'S';
         }
         siguiente->cambiarNodo(orientacionContraria, estructura->ultimo);
         estructura->ultimo = siguiente;

         if (casillero->obtenerBifurcacion() != "") {
            bifurcaciones->agregar(siguiente);
            estructura->bifurcaciones->agregar(siguiente);
         }

         if (casillero->obtenerEmpalme() != "") {
            empalmes->agregar(siguiente);
            estructura->empalmes->agregar(siguiente);
         }
      } // fin bucle

      estructuras->agregar(estructura);
   }

   NodoCasillero * empalme;
   NodoCasillero * bifurcacion;

   string nombreEmpalme;
   bool encontrado;

   // cout << "EMPALMES" << endl;
   // empalmes->mostrar();

   // cout << "BIFURCACIONES" << endl;
   // bifurcaciones->mostrar();
   // cout << "000000000000000000000" << endl;
   empalmes->iniciarCursor();
   while(empalmes->avanzarCursor()) {
      empalme = empalmes->obtenerCursor();
      nombreEmpalme = empalme->obtenerDato()->obtenerEmpalme();

      // busco entre bifurcaciones
      bifurcaciones->iniciarCursor();
      encontrado = false;

      cout << "EMPALME: " << endl;
      cout << "DIR " << empalme << endl;
      cout << empalme->aString() << endl;

      while(!encontrado && bifurcaciones->avanzarCursor()) {
         bifurcacion = bifurcaciones->obtenerCursor();
         casillero = bifurcacion->obtenerDato();

         if (casillero->obtenerBifurcacion() == nombreEmpalme) {
            cout << "BIF: " << bifurcacion->aString() << endl;
            encontrado = true;
            cout << "ORIENTACION ";
            cout << casillero->obtenerOrientacion() << endl;
            bifurcacion->cambiarNodo(casillero->obtenerOrientacion(), empalme);
            empalme->cambiarNodo(empalme->obtenerDato()->obtenerOrientacion(), bifurcacion);

          }
      }

   }

   // cout << "ppppppppppppppppppppppppppppppp" << endl;


   ImagenLaberinto * imagen = new ImagenLaberinto(estructuras, 3);
   imagen->generar();

   return 0;
}
