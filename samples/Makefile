CC = gcc
CFLAGS = -g -Wall -O3
LIB = -I../include -L../bin -lcolor
SRC = $(wildcard *.c)
EXEC = $(SRC:.c=) # Remove the extension ".c"
TARGETS = build

all: $(TARGETS)

build:
	@if [ ! -e ../bin/libcolor.a ]; then \
		echo "libcolor.a not detected. Compiling libcolor.a"; \
		make -C ../; \
	fi;
	@$(foreach f, $(EXEC), \
		echo "Compiling $f.c"; \
		$(CC) $(CFLAGS) $(f).c -o $(f) $(LIB); \
	)

clean: clean_tmp
	@$(foreach f, $(EXEC), \
		rm -vf $f; \
	)

clean_tmp:
	@rm -vf *~

distclean mrproper veryclean: clean
