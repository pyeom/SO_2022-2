#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include <sys/types.h>
#include <sys/wait.h>
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
struct tablero *Jugador[4];
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
//int buscar_chancho(struct tablero *t, int value);
int buscar_mayor_mano(struct tablero *t);
void voltear_ficha(struct ficha *f);
struct ficha *check_values(struct tablero *t);
void print_mesa(struct tablero *t);
void agregar_ficha_extremo(struct tablero *t, struct ficha *f, bool position);
int sumar_mano(struct tablero *t);



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
    Jugador[0] = new_hand();
    Jugador[1] = new_hand();
    Jugador[2]  = new_hand();
    Jugador[3]  = new_hand();               // Crea el jugador     
    

    int indice;
    int buscar;
    i = 0;
    printf("Fichas del Jugador 1:\n");
    while (i < 7) {
        agregar_ficha(Jugador[0], &fichas[orden[i]]);
        print_ficha(&fichas[orden[i]]);
        i++;
    }
    printf("Fichas del Jugador 2:\n");
    while (i < 14) {
        agregar_ficha(Jugador[1], &fichas[orden[i]]);
        print_ficha(&fichas[orden[i]]);
        i++;
    }
    printf("Fichas del Jugador 3:\n");
    while (i < 21) {
        agregar_ficha(Jugador[2], &fichas[orden[i]]);
        print_ficha(&fichas[orden[i]]);
        i++;
    }
    printf("Fichas del Jugador 4:\n");
    while (i < 28) {
        agregar_ficha(Jugador[3], &fichas[orden[i]]);
        print_ficha(&fichas[orden[i]]);
        i++;
    }


    //creando los turnos
    Jugador_actual = new_hand();
    int turno;
    int ronda;
    turno = rand() % 4;
    Jugador_actual = Jugador[turno % 4];
    turno = turno % 4;
    printf("turno de %d \n",turno + 1);
    indice = -1;
    buscar = 6;
    bool notficha = true;
    bool position;
    int ganador = -1; // -1 sino, 0,1,2 o 3 si gana el jugador
    buscar = buscar_mayor_mano(Jugador[turno]);
    printf("el jugador %d tiene la ficha de mayor valor en la posicion %d \n", turno+1 , buscar);
    aux = quitar_ficha(Jugador[turno], buscar);
    printf("el jugador %d ha jugado una ficha \n", turno + 1);
    printf("ha jugado la ");
    print_ficha(aux);
    agregar_ficha(Mesa, aux);
    printf("Mesa: ");
    print_mesa(Mesa);
    printf("\n");


    while (ganador == -1)
    {
        turno++;
        turno = turno % 4;
        
        Jugador_actual = Jugador[turno % 4];
        aux = check_values(Mesa);
        ronda = 0;
        while (notficha && ronda < 4){
            printf("turno del jugador %d \n", turno + 1);
            Jugador_actual = Jugador[turno % 4];

            //Codigo si es turno de jugador 1
            if (turno == 0){
                int input_id;
                int decision;

                printf("Esta es tu mano: \n");
                print_mesa(Jugador_actual);
                printf("Desea pasar? (0) o jugar una ficha? (1): \n");
                scanf("%d", &input_id);
                if (input_id == 0){
                    notficha = true;
                    printf(" jugador %d no tiene ficha para jugar\n", turno + 1);
                    ronda++;
                    turno++;
                    turno = turno % 4;
                }  
                else {
                    printf("Ingrese la posicion de la ficha a jugar (contando desde el 0): \n");
                    scanf("%d", &input_id);
                    aux = quitar_ficha(Jugador_actual, input_id);
                    printf("Desea jugarla a la izquieda (0) o derecha? (1): \n");
                    scanf("%d", &decision);
                    if (decision == 0) {
                        position = true;
                    }
                    else{
                        position = false;
                    }
                    notficha = false;
                    
                }
            }
            else {
                indice = buscar_valor(Jugador_actual, aux->valores[0]);
                if (indice == -1){
                    //no se encuentra la izquierda
                    notficha = true;
                    indice = buscar_valor(Jugador_actual, aux->valores[1]);
                    if (indice == -1){
                        //no se encuentra la derecha
                        notficha = true;
                        printf(" jugador %d no tiene ficha para jugar\n", turno + 1);
                        ronda++;
                        turno++;
                        turno = turno % 4;
                    }
                    else {
                        //encontramos la derecha
                        buscar = aux->valores[1];
                        notficha = false;
                        position = false;
                    }
                }
                else{
                    //encontramos la izquierda
                    buscar = aux->valores[0];
                    notficha = false;
                    position = true;
                }
            }
        }
        if (notficha){
            printf("No se pueden jugar más fichas");
            if (ronda >= 4){
                printf("Ningun jugador pudo colocar más fichas, se suman las manos");
                int suma_mano[4];
                int suma_mayor = -1;
                suma_mano[0] = sumar_mano(Jugador[0]);
                suma_mano[1] = sumar_mano(Jugador[1]);
                suma_mano[2]= sumar_mano(Jugador[2]);
                suma_mano[3] = sumar_mano(Jugador[3]);
                for (i = 0; i < 4; i++){
                    if (suma_mano[i] > suma_mayor){
                        ganador = i;
                    }
                }
            }
        }
        aux = quitar_ficha(Jugador_actual, indice);
        printf("juega ");
        print_ficha(aux);
        if (position){
            printf("a la izquieda \n");
            if (Mesa->first->valores[0] != aux->valores[1]){
                voltear_ficha(aux);
            }
        }
        else{
            printf("a la derecha \n");
            if (Mesa->last->valores[1] != aux->valores[0]){
                voltear_ficha(aux);
            }
        }
        agregar_ficha_extremo(Mesa, aux, position);
        printf("Mesa:  \n");
        print_mesa(Mesa);
        if (Jugador_actual->total == 0){
            ganador = turno;
        }
        notficha = true;
    }
    printf("Ganó el jugador %d \n", ganador);
    free(aux);
    free(Mesa);
    free(Jugador[0]);
    free(Jugador[1]);
    free(Jugador[2]);
    free(Jugador[3]);
    free(Jugador_actual);
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

/*
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
*/

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
    printf("\n");
}

int buscar_mayor_mano(struct tablero *t) {
    int v = -1;
    struct ficha *actual;
    int mayor = 0;
    int i = 0;
    int suma;

    while (i < t -> total){
        actual = t -> fichas[i];
        suma = actual -> valores[0] + actual -> valores[1];
        if (suma > mayor) {
            v = i;
            mayor = suma;
        }
        i++;
        
    }
    return v;
}

void agregar_ficha_extremo(struct tablero *t, struct ficha *f, bool position){
    // if position true , derecha, false derecha
    if (t){
        if (f){
            t->fichas = realloc(t->fichas, sizeof(struct ficha *) * (t->total + 1));
            if (position){
                int i = t->total;
                while (i > 0){
                    t->fichas[i] = t->fichas[i-1];
                    i--;
                }
                t->fichas[0] = f;
            }
            else{
                t->fichas[t->total] = f;
            }
            t->total++;
            t->first = t->fichas[0];
            t->last = t->fichas[t->total-1];
        }
    }

}

int sumar_mano(struct tablero *t){
    struct ficha *actual;
    int i = 0;
    int suma;

    while (i < t -> total){
        actual = t -> fichas[i];
        suma = actual -> valores[0] + actual -> valores[1];
        i++;
        
    }
    return suma;

}