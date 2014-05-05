#include "util.h"
#include <stdlib.h>

using namespace std;

namespace util {

   int string_a_int(std::string str) {
      return atoi(str.c_str());
   }

   Color * string_a_color(std::string color) {
      int rojo, verde, azul;

      int pos1 = color.find(" ", 0);
      int pos2 = color.find(" ", pos1);

      rojo = string_a_int(color.substr(0, pos1));
      verde = string_a_int(color.substr(pos1 + 1, pos2));
      azul = string_a_int(color.substr(pos2 + 1));

      return new Color(rojo, verde, azul);
   }

}