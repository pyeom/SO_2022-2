#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>

#include "funciones.h"
#include "structures.h"

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

struct ficha *fichas = NULL;    // Arreglo punteros a todas las fichas del juego
struct tablero *Mesa = NULL;
struct tablero *Jugador1 = NULL;
struct tablero *Jugador2 = NULL;
struct tablero *Jugador3 = NULL;
struct tablero *Jugador4 = NULL;


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
    Jugador2 = new_hand(); 
    Jugador3 = new_hand(); 
    Jugador4 = new_hand();     

    int pid = fork();

    if (pid == 0){
        i = 0;
        printf("Fichas del Jugador 1:\n");
        printf("This is the child process. My pid is %d and my parent's id is %d.\n", getpid(), getppid());
        while (i < 7) {
            agregar_ficha(Jugador1, &fichas[orden[i]]);
            print_ficha(&fichas[orden[i]]);
            i++;
        }
    }
    else {
        int pid2 = fork();
        if (pid2 == 0){
            i = 7;
            printf("This is the child process. My pid is %d and my parent's id is %d.\n", getpid(), getppid());
            printf("Fichas del Jugador 2:\n");
            while (i < 14) {
                agregar_ficha(Jugador2, &fichas[orden[i]]);
                print_ficha(&fichas[orden[i]]);
                i++;
            }
        }
        else {
            int pid3 = fork();
            if (pid3 == 0){
                i = 14;
                printf("This is the child process. My pid is %d and my parent's id is %d.\n", getpid(), getppid());
                printf("Fichas del Jugador 3:\n");
                while (i < 21) {
                    agregar_ficha(Jugador3, &fichas[orden[i]]);
                    print_ficha(&fichas[orden[i]]);
                    i++;
                }
            }
            else {
                int pid4 = fork();
                if (pid4 == 0){
                    i = 21;
                    printf("This is the child process. My pid is %d and my parent's id is %d.\n", getpid(), getppid());
                    printf("Fichas del Jugador 4:\n");
                    while (i < 28) {
                        agregar_ficha(Jugador4, &fichas[orden[i]]);
                        print_ficha(&fichas[orden[i]]);
                        i++;
                    }
                }
                else{
                    //PROCESO PADRE
                    printf("This is the parent process. My pid is %d and my parent's id is %d.\n", getpid(), pid);
                    agregar_ficha(Mesa, &fichas[orden[0]]);
                    agregar_ficha(Mesa, &fichas[orden[3]]);
                    printf("mesa: \n");
                    print_ficha(Mesa->first);
                    print_ficha(Mesa->last);

                }
            }
        }
    }
    
  

    return 0;
}
