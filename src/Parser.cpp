#include "Parser.h"

#include <iostream>
#include <fstream>

using namespace std;

Parser::Parser(string nombreArchivo) {
   this->nombreArchivo = nombreArchivo;
   this->listaComandos = new ListaComandos();
}

void Parser::iniciar() {
   ifstream fs (this->nombreArchivo.c_str());
   if (fs.is_open()) {
      int pos;
      string nombreComando;
      string argumento;
      string linea;
      while(getline(fs, linea)) {
         argumento = "";
         nombreComando = linea;
         if (nombreComando.at(0) == 'G') {
            nombreComando = "G";
            argumento = linea.at(1);

         } else if(nombreComando.at(0) == 'B') {
            nombreComando = "B";
            argumento += linea.at(1);
            argumento += " " + linea.substr(linea.find(" ", 0) + 1);

         } else if((pos = linea.find(" ", 0)) != string::npos) {
            nombreComando = linea.substr(0, pos);
            argumento = linea.substr(pos + 1);
         }
         this->listaComandos->acolar(nombreComando, argumento);
      }
      fs.close();
   } else {
      cout << "Error en la lectura del archivo." << endl;
   }
}

ListaComandos * Parser::obtenerLista() {
   return this->listaComandos;
}
