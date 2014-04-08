CC = gcc
CFLAGS = -g -fPIC -Wall -Wextra -O3
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
EXDIR = samples
INCLUDES = -I$(INCDIR)
LIBFLAGS = -cruvs
SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGETS = lib buildsamples

all: $(TARGETS)

lib: $(BINDIR)/libcolor.a

$(BINDIR)/libcolor.a: $(OBJ)
	@[ -d $(BINDIR) ] || mkdir $(BINDIR)
	@echo "Creating $@"
	@ar $(LIBFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@[ -d $(OBJDIR) ] || mkdir $(OBJDIR)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

buildsamples:
	@echo "Building samples"
	@make -C $(EXDIR)

clean: clean_tmp
	@rm -vrf $(OBJDIR)
	@make clean -C $(EXDIR)

clean_tmp:
	@rm -vf *~ $(SRCDIR)/*~ $(INCDIR)/*~
	@make clean_tmp -C $(EXDIR)

distclean mrproper veryclean: clean
	@rm -vrf $(BINDIR)
	@make distclean -C $(EXDIR)
