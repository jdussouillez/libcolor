#include <stdio.h>

#include "color.h"

int main(void) {
  /*
   * Example #1
   */
  printf("\e[31m\e[47m\e[1mThis is bold red text on white -- no libcolor\e[m\n");
  cprintf(RED, WHITE, 1, "This is bold red text on white -- using libcolor\n");

  /*
   * Example #2
   */
  // Using color characters
  printf("\e[30m\e[47mBlack on white\e[m | \e[37m\e[40mWhite on black\e[m -- no libcolor\n");

  // Using the cprintf function from libsort (need several instructions here because there are different colors on the same line)
  cprintf(BLACK, WHITE, 0, "Black on white");
  printf(" | ");
  cprintf(WHITE, BLACK, 0, "White on black");
  printf(" -- using libcolor (1)\n");

  // Or using the libsort defined color's value
  printf(COLOR_BLACK COLOR_BG_WHITE "Black on white" COLOR_NORMAL " | " COLOR_WHITE COLOR_BG_BLACK "White on black" COLOR_NORMAL " -- using libcolor (2)\n");
  return 0;
}
