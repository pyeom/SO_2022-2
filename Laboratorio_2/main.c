#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

/***    ALREADY DONE
 * El código por ahora crea cada ficha de domino en un tablero, y crea un jugador.
 * Añade correctamente fichas de domino a la mano del jugador.
 * Puede eliminar o agregar fichas de la mano, lo que permite pasar fichas de la mano al tablero.
 * Puede ver si un jugador posee una ficha con un número específico para poder jugar o pasar.
 * Puede voltear una ficha para que el jugador la juegue en la izquierda o la derecha.
 * ***/

/***    WHATS LEFT?
 * Crear los demás jugadores con el fork().
 * Inicializar cada jugador con su mano.
 * Crear un menú de juego para el jugador.
 * Hacer que los demás jugadores jueguen en automático.
 * ***/



// Definiciones de estructuras

struct ficha {          // Estructura de una ficha [ a | b ]
    int valores[2];
};

struct tablero {
    struct ficha **fichas;
    struct ficha *first, *last;
    int total;
};

struct ficha *fichas = NULL;    // Arreglo punteros a todas las fichas del juego
struct tablero *Mesa = NULL;
struct tablero *Jugador1 = NULL;


// Definiciones de funciones

struct ficha *crear_ficha (int a, int b);
void revolver();
struct tablero *new_hand();
void agregar_ficha(struct tablero *t, struct ficha *f);
struct ficha *quitar_ficha(struct tablero *t, int ficha_quitar);
void print_ficha(struct ficha *f);
int buscar_valor(struct tablero *t, int value);
void voltear_ficha(struct ficha *f);


int orden[28];      // Array de int con para desordenar las piezas


int main() {
    struct ficha *temp;
    int contador = 0;
    int i = 0, j = 0;

    while (i <= 6) {
        j = 0;
        while (j <= i) {
            fichas = realloc(fichas, (contador + 1) * sizeof(struct ficha));    // Crea un arreglo de fichas que se va actualizando a medida que se añade una ficha
            temp = crear_ficha(i, j);                                   // Crea la ficha (i, j)
            memcpy(&fichas[contador], temp, sizeof(struct ficha));      // Fichas apunta a la ficha
            free(temp);                                                 // Libera la memoria que se utiliza al crear una ficha
            contador++;
            j++;
        }
        i++;
    }

    // printf("Fichas creadas: %i\n", contador);

    
    for ( i = 0; i < contador; i++) {           // Forma de recorrer el arreglo de fichas
        struct ficha temp2 = fichas[i];
        //printf("Ficha [ %i | %i ] creada\n", temp2.valores[0], temp2.valores[1]);
    }

    i = 0;
    revolver();             // Revuelve las fichas
    printf("Fichas revueltas.\n");

    /*
    while (i < contador) {
        printf("Ficha: [ %i | %i ]\n", fichas[orden[i]].valores[0], fichas[orden[i]].valores[1]);   // Muesra las fichas revueltas
        i++;
    }
    */

    Mesa = new_hand();       // Crea el tablero
    Jugador1 = new_hand();      // Crea el jugador         

    i = 0;
    printf("Fichas del Jugador 1:\n");
    while (i < 7) {
        agregar_ficha(Jugador1, &fichas[orden[i]]);
        print_ficha(&fichas[orden[i]]);
        i++;
    }
    

    return 0;
}


