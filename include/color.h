#ifndef COLOR_H
#define COLOR_H

// Reset all colors (foreground, background and bold)
#define COLOR_NORMAL "\e[m"

#define COLOR_BOLD "\e[1m"

// Font colors
#define COLOR_BLACK "\e[30m"
#define COLOR_RED "\e[31m"
#define COLOR_GREEN "\e[32m"
#define COLOR_YELLOW "\e[33m"
#define COLOR_BLUE "\e[34m"
#define COLOR_MAGENTA "\e[35m"
#define COLOR_CYAN "\e[36m"
#define COLOR_WHITE "\e[37m"

// Background colors
#define COLOR_BG_BLACK "\e[40m"
#define COLOR_BG_RED "\e[41m"
#define COLOR_BG_GREEN "\e[42m"
#define COLOR_BG_YELLOW "\e[43m"
#define COLOR_BG_BLUE "\e[44m"
#define COLOR_BG_MAGENTA "\e[45m"
#define COLOR_BG_CYAN "\e[46m"
#define COLOR_BG_WHITE "\e[47m"

/*
 * Available colors.
 * http://en.wikipedia.org/wiki/ANSI_escape_code#Colors
 */
typedef enum {
  NORMAL = -1,
  BLACK,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE,
} color_t;

/*
 * Write a colord text to stdout.
 * @param fontcolor The font color. Use NORMAL to use default color.
 * @param bgcolor The background color. Use NORMAL to use default background color.
 * @param bold An non-zero value to change the text to bold, 0 otherwise.
 * @param format Output format
 * @return The number of characters printed (including the colors caracters and excluding the null byte used to end output to strings.
 * See the printf(3) manpage for more information.
 */
int cprintf(color_t fontcolor, color_t bgcolor, int bold, const char* format, ...);

#endif // COLOR_H
