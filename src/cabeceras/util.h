#ifndef _UTIL_H_
#define _UTIL_H_

#include "Color.h"

namespace util {

   /**
    * Convierte un string a entero
    */
   int string_a_int(std::string str);

   /**
    * Retorna una instancia de la clase Color
    * @param color Ejemplo: "255 0 0"
    */
   Color * string_a_color(std::string color);

   /**
    * Convierte un entero a string
    */
   std::string int_a_string(int i);

    /**
    * Convierte un char a string
    */
   std::string char_a_string(char i);

   /**
    * Retorna la orientacion contraria. Por ej. si orientacion = 'N' retorna 'S'
    */
   char obtener_orientacion_contraria(char orientacion);

}

#endif


