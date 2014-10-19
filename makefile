# this makefile is based off of http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ \
more references:																			 \
http://www.gnu.org/software/make/manual/make.html#Simple-Makefile							 \
http://www.cprogramming.com/tutorial/makefiles.html

CC=gcc

SDIR=source
_SRC=maze.c
SRC=$(patsubst %,$(SDIR)/%,$(_SRC))
INCDIR=include

ODIR=source/obj
LDIR=lib

LIBS=-lm

CFLAGS=-I$(INCDIR) -I$(SDIR) -I$(LDIR)

_SOLVER=solver.c
SOLVER=$(patsubst %,$(INCDIR)/%,$(_SOLVER))

# reasons to use object files: http://stackoverflow.com/questions/14636916/why-use-object-files-in-c
# http://stackoverflow.com/questions/1814270/gcc-g-option-to-place-all-object-files-into-separate-directory
_OBJ=maze.o helper_functions.o solver.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(SRC)
	$(CC) -c -o $@ $< $(CFLAGS)
	
build: rename makemaze clean

makemaze: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

rename:
	cp $(INCDIR)/${USERNAME_ID}.solver $(SDIR)/solver.c

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(SDIR)/solver.c *~ core $(INCDIR)/*~