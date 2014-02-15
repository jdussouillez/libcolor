#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "color.h"

static char* getstrcolor(color_t c) {
  int size = 6 * sizeof(char);
  char* str = malloc(size);
  memset(str, 0, size);
  if (c != NORMAL)
    snprintf(str, size, "\e[3%dm]", (int)c);
  return str;
}

static char* getstrbgcolor(color_t bgc) {
  int size = 6 * sizeof(char);
  char* str = malloc(size);
  memset(str, 0, size);
  if (bgc != NORMAL)
    snprintf(str, size, "\e[4%dm]", (int)bgc);
  return str;
}

void cprintf(color_t fontcolor, color_t bgcolor, int bold, const char* format, ...) {
  va_list arglist;
  char *strcolor, *strbgcolor;
  strcolor = getstrcolor(fontcolor);
  strbgcolor = getstrbgcolor(bgcolor);
  printf("%s%s", strcolor, strbgcolor);
  free(strcolor);
  free(strbgcolor);
  if (bold)
    printf(COLOR_BOLD);
  va_start(arglist, format);
  vprintf(format, arglist);
  va_end(arglist);
  printf(COLOR_NORMAL); // Reset colors
}
