#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>

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
struct tablero *Jugador2 = NULL;
struct tablero *Jugador3 = NULL;
struct tablero *Jugador4 = NULL;
struct ficha *aux = NULL;
struct tablero *Jugador_actual = NULL;


// Definiciones de funciones

struct ficha *crear_ficha (int a, int b);
void revolver();
struct tablero *new_hand();
void agregar_ficha(struct tablero *t, struct ficha *f);
struct ficha *quitar_ficha(struct tablero *t, int ficha_quitar);
void print_ficha(struct ficha *f);
int buscar_valor(struct tablero *t, int value);
int buscar_chancho(struct tablero *t, int value);
void voltear_ficha(struct ficha *f);
struct ficha *check_values(struct tablero *t);
void print_mesa(struct tablero *t);



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

    int busqueda;
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
        busqueda = buscar_chancho(Jugador1, 6);
        if (busqueda != -1)
        printf("el jugador 1 si tiene el chancho 6 en la posicion %d \n", busqueda);
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
            busqueda = buscar_chancho(Jugador2, 6);
            if (busqueda != -1)
            printf("el jugador 2 si tiene el chancho 6 en la posicion %d \n", busqueda);
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
                busqueda = buscar_chancho(Jugador3, 6);
                if (busqueda != -1)
                printf("el jugador 3 si tiene el chancho 6 en la posicion %d \n", busqueda);
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
                    busqueda = buscar_chancho(Jugador4, 6);
                    if (busqueda != -1)
                    printf("el jugador 4 si tiene el chancho 6 en la posicion %d \n", busqueda);
                }
                else{
                    //PROCESO PADRE
                    printf("This is the parent process. My pid is %d and my parent's id is %d.\n", getpid(), pid);
                    wait(NULL);
                    busqueda = buscar_valor(Jugador1, 1);
                    if (busqueda != -1)
                    printf("el jugador 1 si tiene el valor 1 en la posicion %d \n", busqueda);
                    agregar_ficha(Mesa, &fichas[orden[0]]);
                    //gregar_ficha(Mesa, &fichas[orden[3]]);
                    print_mesa(Mesa);
                    printf("\n");
                }
            }
        }
    }
    
  

    return 0;
}

/***
 * Crea la ficha (i, j) y la agrega a las fichas
 * 
 * ***/
struct ficha *crear_ficha (int a, int b) {
    struct ficha *new = calloc(sizeof(struct ficha), 1);                // Pide memoria para la ficha
    new -> valores[0] = a;                                              // Asigna los valores internos de la ficha
    new -> valores[1] = b;
    //printf("Creando ficha nueva [%i | %i]\n", new -> valores[0], new -> valores[1]);
    return new;
}

/***
 * Revuelve las fichas, en realidad solo crea un arreglo de 28 numeros con numeros del 0 al 28 en un orden random
 * de modo que cuando se busque a las fichas estas aparezcan desordenadas
 * ***/
void revolver() {
    int i = 0, random;
    int aux[28];
    memset(&aux, 0, sizeof(int) * 28);
    srand(time(NULL));

    while (i < 28) {
        random = rand() % 28;

        if (aux[random] == 0) {
            orden[i] = random;
            i++;
            aux[random] = 1;
        }
        
    }
    
}

/***
 * Crea un nuevo tablero/mano
 * 
 * ***/

struct tablero *new_hand() {
    struct tablero *temp = NULL;
    temp = calloc(1, sizeof(struct tablero));      // Crea mesa inicializada en 0
    return temp;
}

/***
 * Agrega la ficha f al tablero o mano
 * 
 * ***/

void agregar_ficha(struct tablero *t, struct ficha *f){
    if (t) {
        if (f) {
            t -> fichas = realloc(t -> fichas, sizeof(struct ficha *) * t -> total+1);
            t -> fichas[t -> total] = f;
            t -> total++;
            t -> first = t -> fichas[0];
            t -> last = t -> fichas[t -> total - 1];
        }
         
        else {
            printf("Ficha invalida");
        }
    }

    else {
        printf("Tablero invalido");
    }
}

/***
 * Busca la ficha en el tablero o mano y la quita
 * Retorna la ficha que se quita de modo que esta se pueda poner en el tablero o en la mano de un jugador
 * ***/

struct ficha *quitar_ficha(struct tablero *t, int ficha_quitar) {
    int i = ficha_quitar;
    struct ficha *temp = NULL;

    temp = t -> fichas[ficha_quitar];

    while (i < t -> total - 1) {
        t-> fichas[i] = t -> fichas[i + 1];
        i++;
    }

    t -> fichas[i] = NULL;
    t -> fichas = realloc(t -> fichas, sizeof(struct ficha*) * (t -> total - 1));
    t -> total --;

    if (t -> total > 0) {
        t -> first = t -> fichas[0];
        t -> last = t -> fichas[t -> total - 1];
    }
    

    return temp;
}

/***
 * Simplemente printea los valores de la ficha f
 * 
 * ***/
void print_ficha(struct ficha *f) {
    printf("Ficha: [ %i | %i ]\n", f -> valores[0], f -> valores[1]);
}

/***
 * Busca el indice v de la ficha que tiene el valor value, retorna el la posicion de la ficha si es que tiene el valor
 * Retorna -1 si no encuentra la ficha
 * ***/
int buscar_valor(struct tablero *t, int value) {
    int v = -1;
    struct ficha *actual;
    bool found = false;
    int i = 0;

    while (!found && i < t -> total){
        actual = t -> fichas[i];

        if (actual -> valores[0] == value || actual -> valores[1] == value) {
            v = i;
            found = true;
        }

        i++;
        
    }

    return v;
}

/***
 * Voltea los valores de la ficha f para poder jugarla a un lado o al otro
 * 
 * ***/
void voltear_ficha(struct ficha *f) {
    int aux;
    aux = f -> valores[0];
    f -> valores[0] = f -> valores[1];
    f ->valores[1] = aux;
}

int buscar_chancho(struct tablero *m, int value){
    int v = -1;
    struct ficha *actual;
    bool found = false;
    int i = 0;

    while (!found && i < m -> total){
        actual = m -> fichas[i];
        if (actual -> valores[0] == value && actual -> valores[1] == value) {
            v = i;
            found = true;
        }
        i++;
    }
    return v;
}

struct ficha *check_values(struct tablero *t){
    struct ficha *f = malloc(sizeof(struct ficha));
    f->valores[0] = t->first->valores[0];
    f->valores[1] = t->last->valores[1];
    return f;
}

void print_mesa(struct tablero *t){
    int i = 0;
    while (i < t->total){
        printf("[ %i | %i ]", t->fichas[i]->valores[0], t->fichas[i]->valores[1]);
        i++;
    }
}