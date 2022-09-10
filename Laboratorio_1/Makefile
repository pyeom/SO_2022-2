.SUFFIXES: .o .c
.c.o:
		$(CC) -c $(CFLAGS) $<


CC=gcc
CFLAGS= -g -Wall
SOURCE = orden.c visualizacion.c 
OBJ = $(SOURCE: .c=.o)
EXE = orden visualizacion

all: $(SOURCE) $(EXE)

$(EXE): $(OBJ)
		$(CC) $(OBJ) -o $@

%.o: %.c 
		$(CC) $(CFLAGS) $< -0 $@

clean:
		rm -rf $(OBJ) $(EXE)

