# TP 1 - Laberinto

### Directorios
----

**+ src/cabeceras/**
   Headers (*.h)

**+ test/**
   Contiene un ejemplo que subieron al campus y otros archivos de prueba
   que utilizamos para probar el programa

**+ src/**
   Archivos fuente

   * **ImagenLaberinto.cpp**:
      Recibe grafo y se encarga de dibujar todos los recorridos del laberinto a
      una imagen. Se ultiliza la libreria EasyBMP: http://easybmp.sourceforge.net/

   * **Comando.cpp**:
      Cuando se ejecuta el programa, el sistema pide al usuario que indique el nombre y la ruta
      del archivo de texto (.txt), con los recorridos.
      Lo primero que hace el programa es procesar el archivo y transformar cada directiva
      a una lista de Comandos. Cada comando tiene un nombre y un argumento.
      Por ej. Si la entrada del archivo de texto es:

      PP 255 0 0
      L moneda
      ...

      El nombre del comando es L (levantar) y su argumento es: "moneda".

   * **Parser.cpp**:
      Se encarga de procesar el archivo de texto y generar la lista de Comandos (ver arriba).
      La lista es de tipo cola.

   * **util.cpp**:
      Tiene funciones que se utilizan en todo el sistema, como por ej. util::string_a_int()
      que transforma un string a entero.




