#include <stdio.h>

#include "color.h"

int main(void) {
  /*
   * Print colors on stderr
   */
  const char* text = "A random text";
  fprintf(stderr, "\e[35m%s\e[m\n", text);
  cfprintf(stderr, MAGENTA, NORMAL, NOBOLD, "%s\n", text);
  return 0;
}
