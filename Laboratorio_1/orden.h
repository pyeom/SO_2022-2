#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <dirent.h>

#define SOURCE_FOLDER "/test"



// Lee un archivo y retorna los parámetros que se encuentran en su interior
int leerArch(char *nombreArch){
    FILE *arch;
    int prioridad, anno;
    if  ((arch = fopen(nombreArch, "r")) != NULL){
        fscanf(arch, "%d\n%d", anno, prioridad);
    }
    fclose(arch);
    return anno, prioridad;
}

// Recibe el nombre del archivo a mover y los datos dentro de el para poder moverlo a la
// carpeta correcta
void mover(char* nombreArch, int anno, int prioridad){
    DIR *dir;
    struct dirent *ent;
    if (anno == 2019){
        if(prioridad >= 9000){
            //dir = opendir("C:\USM\2022-2\SO\Laboratorio_1\2019\9000+");
            rename(SOURCE_FOLDER, "/test/")    
        }
        else if(prioridad >= 6000){
            //dir = opendir("C:\USM\2022-2\SO\Laboratorio_1\2019\6000+");
        }
        else if(prioridad >= 3000){
            //dir = opendir("C:\USM\2022-2\SO\Laboratorio_1\2019\3000+");
        }
    }
    else if (anno == 2020){

    }
    else{

    }
    return;
}