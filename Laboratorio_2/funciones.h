#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>

#include "structures.h"

struct ficha *crear_ficha (int a, int b);
void revolver();
struct tablero *new_hand();
void agregar_ficha(struct tablero *t, struct ficha *f);
struct ficha *quitar_ficha(struct tablero *t, int ficha_quitar);
void print_ficha(struct ficha *f);
int buscar_valor(struct tablero *t, int value);
void voltear_ficha(struct ficha *f);