#include "cabeceras/Parser.h"

#include <iostream>
#include <fstream>

using namespace std;

Parser::Parser(string nombreArchivo) {
   this->nombreArchivo = nombreArchivo;
   this->listaComandos = new Cola<Comando*>();
}

void Parser::iniciar() {
   ifstream fs (this->nombreArchivo.c_str());
   Comando * cmd;

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
         cmd = new Comando(nombreComando, argumento);
         this->listaComandos->acolar(cmd);
      }
      fs.close();
   } else {
      cout << "Error en la lectura del archivo." << endl;
   }
}

Cola<Comando*> * Parser::obtenerLista() {
   return this->listaComandos;
}
