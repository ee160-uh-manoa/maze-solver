# this makefile is based off of http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/	\
the basic structure of a makefile statement is:													\
target: [dependencies]																			\
	commands																					\
note:																							\
tabs are important for the second line (aka the command); 4 spaces won't work					\
dependencies are optional and can be other targets												\
more references:																				\
http://www.gnu.org/software/make/manual/make.html#Simple-Makefile								\
http://www.cprogramming.com/tutorial/makefiles.html

# macros:													\
http://www.tutorialspoint.com/makefile/makefile_macros.htm	\
to use macro later: $(EXECUTABLE)
EXECUTABLE = maze_solver # set compiler output
CC         = gcc # set compiler

# set directory structure
SOURCE_DIRECTORY = source
OBJECT_DIRECTORY = source/objects
SOLVER_DIRECTORY = solvers

# set source files
_SOURCE = maze.c functions.c solver.c
SOURCE  = $(patsubst %,$(SOURCE_DIRECTORY)/%,$(_SOURCE)) # substitue string to get relative path e.g. "source/maze.c"

# set object files
# reasons to use object files: http://stackoverflow.com/questions/14636916/why-use-object-files-in-c
# http://stackoverflow.com/questions/1814270/gcc-g-option-to-place-all-object-files-into-separate-directory
_OBJECTS = maze.o functions.o solver.o
OBJECTS  = $(patsubst %,$(OBJECT_DIRECTORY)/%,$(_OBJECTS)) # substitue string to get relative path e.g. "source/maze.o"

# set compiling options
LIBRARIES = -lm
CFLAGS    = -I$(SOURCE_DIRECTORY)

# the following is essentiall doing:												\
source/objects/maze.o: source/maze.c												\
	gcc -c -o source/objects/maze.o source/maze.c -Isource							\
for each dependant object e.g. maze.o helper_functions.o							\
http://stackoverflow.com/questions/1633527/wildcard-targets-in-a-makefile			\
http://www.gnu.org/software/make/manual/make.html#Pattern-Rules
$(OBJECT_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)
	
build: copy_over_custom_solver build_maze_solver clean

build_maze_solver: $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $^ $(CFLAGS) $(LIBS)

copy_over_custom_solver:
	cp $(SOLVER_DIRECTORY)/${SOLVER}.solver $(SOURCE_DIRECTORY)/solver.c

.PHONY: clean # http://www.gnu.org/software/make/manual/make.html#Cleanup

clean: remove_custom_solver
	rm -f $(OBJECT_DIRECTORY)/*.o
	
remove_custom_solver:
	rm -f $(SOURCE_DIRECTORY)/solver.c