#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "color.h"

static char* getcolor(color_t c, int bgcolor) {
  int size = 6 * sizeof(char);
  char* str = malloc(size);
  memset(str, 0, size);
  if (c != NORMAL)
    snprintf(str, size, (bgcolor ? "\e[4%dm" : "\e[3%dm"), (int)c);
  return str;
}

static int cprintstream(color_t fontcolor, color_t bgcolor, int bold, FILE* stream, const char* format, va_list ap) {
  char *strcolor, *strbgcolor;
  int nbcharprinted;
  // Set (= print) colors. If the color is NORMAL, an empty string is printed.
  strcolor = getcolor(fontcolor, 0); // Get font color
  strbgcolor = getcolor(bgcolor, 1); // Get background color
  fprintf(stream, "%s%s", strcolor, strbgcolor);
  free(strcolor);
  free(strbgcolor);
  if (bold)
    printf(COLOR_BOLD);
  // Print string
  nbcharprinted = vfprintf(stream, format, ap);
  // Reset colors
  printf(COLOR_NORMAL);
  return nbcharprinted;
}

/*
 * cprintf does not call cfprintf because you cannot pass a variable number of argument.
 * So it invokes cprintstream which has a va_list argument.
 */
int cprintf(color_t fontcolor, color_t bgcolor, int bold, const char* format, ...) {
  va_list arglist;
  int nbcharprinted;
  va_start(arglist, format);
  nbcharprinted = cprintstream(fontcolor, bgcolor, bold, stdout, format, arglist);
  va_end(arglist);
  return nbcharprinted;
}

int cfprintf(FILE* stream, color_t fontcolor, color_t bgcolor, int bold, const char* format, ...) {
  va_list arglist;
  int nbcharprinted;
  va_start(arglist, format);
  nbcharprinted = cprintstream(fontcolor, bgcolor, bold, stream, format, arglist);
  va_end(arglist);
  return nbcharprinted;
}
