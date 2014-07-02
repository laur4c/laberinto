#include "cabeceras/Laberinto.h"

Laberinto::Laberinto() {
   this->mochila = new Mochila();
   this->info = new InfoRecorrido();
   this->grafo = new Grafo<string>();
}

void Laberinto::mostrarInfo() {
   this->info->mostrar();
}

void Laberinto::mostrarMochila() {
   this->mochila->mostrar();
}

void Laberinto::generarImagen() {
   this->imagenLaberinto = new ImagenLaberinto(this->grafo);
   this->imagenLaberinto->generar();
}

void Laberinto::dibujarCaminoMinimo(string origen, string destino) {
   this->imagenLaberinto->dibujarCaminoMinimo(origen, destino);
}

void Laberinto::generarArista(Color * color, Cola<Comando*> * componentes, char ultimaOrientacion) {
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
         tramos->agregar(new Tramo(
            ultimaOrientacion, longitud, tiroObjeto, new Color(color->rojo, color->verde, color->azul)
         ));
         tiroObjeto = false;
         peso += longitud;

      } else if (nombre == "G") {
         ultimaOrientacion = argumento.c_str()[0];
      }

   }
   arista = "arista-" + entrada + "-" + salida;
   this->grafo->agregarArista(entrada, salida, arista, peso, tramos);
}

void Laberinto::generarDesdeListaDeComandos(Cola<Comando*> * comandos) {
   Comando * comando;
   Comando * cmd;
   string nombre, argumento, orientacionContraria, ultimaOrientacion;
   Color * color;

   Cola<Comando*> * componentesArista = new Cola<Comando*>();
   Cola<Comando*> * comandosABorrar = new Cola<Comando*>();
   Cola<Color*> * colores = new Cola<Color*>();
   bool existeVerticeEntrada = false;

   while (!comandos->estaVacia()) {
      comando = comandos->desacolar();
      comandosABorrar->acolar(comando);
      nombre = comando->obtenerNombre();
      argumento = comando->obtenerArgumento();

      if (nombre == "PP") {
         color = util::string_a_color(argumento.substr(argumento.find(" ", 0) + 1));
         colores->acolar(color);
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
            this->generarArista(color, componentesArista, ultimaOrientacion.c_str()[0]);

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

         cmd = new Comando("G", orientacionContraria);
         comandosABorrar->acolar(cmd);
         componentesArista->acolar(cmd);
         cmd = new Comando("A", argumento);
         comandosABorrar->acolar(cmd);
         componentesArista->acolar(cmd);
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

   while(!comandosABorrar->estaVacia())
      delete comandosABorrar->desacolar();
   delete comandosABorrar;

   while(!colores->estaVacia())
      delete colores->desacolar();
   delete colores;

   while(!componentesArista->estaVacia())
      delete componentesArista->desacolar();
   delete componentesArista;
}

Laberinto::~Laberinto() {
   delete this->mochila;
   delete this->info;
   delete this->imagenLaberinto;
   delete this->grafo;
}










