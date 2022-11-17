#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>

// Definiciones de estructuras

struct ficha {          // Estructura de una ficha [ a | b ]
    int valores[2];
};

struct tablero {
    struct ficha **fichas;
    struct ficha *first, *last;
    int total;
};