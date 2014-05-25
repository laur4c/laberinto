# Laberinto

### TP I - Algoritmos y Programación II
### Cátedra Calvo FIUBA

#### Grupo 8
#### Integrantes:

* Mariano Cinalli
* Lucas Dreko
* Santiago Montiel
* Ezequiel Guitler
* Laura Corvalán

#### + src/cabeceras/
   Headers (*.h)

#### + test/
   Contiene un ejemplo que subieron al campus y otros archivos de prueba
   que utilizamos para probar el programa

#### + src/
   Archivos fuente

   * Camino.cpp:
      Representa un recorrido en el laberinto. Está compuesto por puntos.
      Cada punto tiene referencias a sus cuatro direcciones: Norte, Sur, Oeste, Este

      Al tener los puntos referencias a todas las direcciones, se puede levantar
      en memoria toda la estructura del laberinto. Ya que las uniones
      a las bifurcaciones se representan uniendo los puntos de diferentes caminos
      de acuerdo a la orientacion de cada uno de ellos.

      Cada camino tiene referencia al comienzo y al final del recorrido.

   * Punto.cpp:
      Representa un "punto" en un recorrido del laberinto.
      El punto tiene un atributo: "informacion" que es una instancia de InfoPunto.
      InfoPunto contiene informacion acerca de la orientacion del punto, cuantos pasos se van a avanzar
      en esa direccion, si existe un objeto, si hay una bifurcacion o una union.

   * ImagenLaberinto.cpp:
      Recibe la lista de caminos y se encarga de dibujar todos los recorridos del laberinto a
      una imagen. Se ultiliza la libreria EasyBMP: http://easybmp.sourceforge.net/

   * Comando.cpp:
      Cuando se ejecuta el programa, el sistema pide al usuario que indique el nombre y la ruta
      del archivo de texto (.txt), con los recorridos.
      Lo primero que hace el programa es procesar el archivo y transformar cada directiva
      a una lista de Comandos. Cada comando tiene un nombre y un argumento.
      Por ej. Si la entrada del archivo de texto es:

      PP 255 0 0
      L moneda
      ...

      El nombre del comando es L (levantar) y su argumento es: "moneda".

   * Parser.cpp:
      Se encarga de procesar el archivo de texto y generar la lista de Comandos (ver arriba).
      La lista es de tipo cola.

   * util.cpp:
      Tiene funciones que se utilizan en todo el sistema, como por ej. util::string_a_int()
      que transforma un string a entero.




