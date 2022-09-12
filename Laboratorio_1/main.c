#include "funciones.h"

void menu(){
    int auxiliar = 0;
    int decision = 0;

    while (auxiliar == 0){
        printf("¿Que accion desea realizar?\n");
        printf("1.- Ordenar\n");
        printf("2.- Visualizar\n");
        printf("3.- Salir\n");
        scanf("%d", &decision);

        if(decision == 1){
            mover();
        }
        else if(decision == 2){
            visualizacion();
        }
        else{
            auxiliar = 1;
        }
    }
}

int main(){
    menu();
    return 0;
}
