#include <stdio.h>

#include "color.h"

int main(void) {
  // The last color characters (\e[m or COLOR_NORMAL) is used to reset the colors at the end of the printf.
  // If you don't reset the colors, the colors will be apply to the following printf ("normal text" printf in this example).
  printf("\e[31m\e[47m\e[1mThis is bold red text on white -- no libcolor\e[m\n");
  printf("normal text\n");
  printf(COLOR_RED COLOR_BG_WHITE COLOR_BOLD "This is bold red text on white -- using libcolor values\n" COLOR_NORMAL);
  printf("normal text\n");
  cprintf(RED, WHITE, BOLD, "This is bold red text on white -- using libcolor cprintf()\n");
  printf("normal text\n");
  return 0;
}
