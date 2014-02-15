libcolor
========

A static C library to output colored text to the console.

Why ?
-----

Output colored text to the console is quite easy. Before the text, you have to print "special characters" to set the colors and style (font color, background color, bold text).

However, the color characters are not easy to handle, and makes your printf look horrible.
libcolor supplies all color characters and a printf-like function to output colored text without going crazy.
// Example

How to build
------------

Use the makefile to build the lib (bin/libcolor.a):
``` bash
make # Build the lib and the samples
make clean # Clean the temporary and objects file.
```

If you want to remove the lib and all the temporary files:
``` bash
make distclean
```

Tools
-----

- Written with Emacs 24
- Built with gcc 4.8
- Tested on GNU/Linux (Linux Mint 16)
