all: output

output: main.o orden.o visualizacion.o
	gcc -o output main.o orden.o visualizacion.o

main.o: main.c funciones.h
	gcc -c main.c

orden.o: orden.c funciones.h
	gcc -c orden.c

visualizacion.o: visualizacion.c funciones.h
	gcc -c visualizacion.c

clean:
	rm -f output *.o

