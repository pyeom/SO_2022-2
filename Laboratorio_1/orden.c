#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <dirent.h>

#include "funciones.h"

/*
Lee el interior del archivo de texto y luego lo mueve a la carpeta correspondiente teniendo en cuenta el contenido
*/
void leer(char *nombre, char *directorio){
    char buffer[50];
    strcpy(buffer, directorio);
    strcat(buffer, "/");
    strcat(buffer, nombre);
    FILE *fp = fopen(buffer, "r");
    //printf ("el nombre es '%s'\n", buffer);
    int prioridad, anno;

    if (fp == NULL)
    {
        printf("Error: could not open file %s \n", buffer);
        return;
    }
    
    fscanf(fp, "%d\n%d", &anno, &prioridad);
    //printf ("el anno es '%d' y su prioridad '%d' \n", anno, prioridad);
    char aux[100];
    if (anno == 2019){
             if (prioridad >= 9000){ //Mueve el file al folder correspondiente
                strcpy(aux, "mv ");
                strcat(aux, buffer);
                strcat(aux, " ./2019/9000+");
                system(aux);
            }

            else if (prioridad >= 6000){
                strcpy(aux, "mv ");
                strcat(aux, buffer);
                strcat(aux, " ./2019/6000+");
                system(aux);
            }

            else{
                strcpy(aux, "mv ");
                strcat(aux, buffer);
                strcat(aux, " ./2019/3000+");
                system(aux);
            }
        }
        else if (anno == 2020){
            if (prioridad >= 9000){ //Mueve el file al folder correspondiente
                strcpy(aux, "mv ");
                strcat(aux, buffer);
                strcat(aux, " ./2020/9000+");
                system(aux);
            }

            else if (prioridad >= 6000){
                strcpy(aux, "mv ");
                strcat(aux, buffer);
                strcat(aux, " ./2020/6000+");
                system(aux);
            }

            else{
                strcpy(aux, "mv ");
                strcat(aux, buffer);
                strcat(aux, " ./2020/3000+");
                system(aux);
            }
        }

        else{
            if (prioridad >= 9000){ //Mueve el file al folder correspondiente
                strcpy(aux, "mv ");
                strcat(aux, buffer);
                strcat(aux, " ./2021/9000+");
                system(aux);
            }

            else if (prioridad >= 6000){
                strcpy(aux, "mv ");
                strcat(aux, buffer);
                strcat(aux, " ./2021/6000+");
                system(aux);
            }

            else{
                strcpy(aux, "mv ");
                strcat(aux, buffer);
                strcat(aux, " ./2021/3000+");
                system(aux);
            }
        }
     // close the file
    fclose(fp);
}



/*
Abre el directorio "test" en busca de los archivos que hay que mover, recorre cada archivo del directorio y
llama a la funcion leer() con cada archivo.
*/
void mover () {
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir ("./test");
    if (pDir == NULL) {
        printf ("Cannot open directory '%s'\n", "test");
    }

    // Procesar cada entrada.

    while ((pDirent = readdir(pDir)) != NULL)  {
        if((strcmp(pDirent->d_name,".")==0 || strcmp(pDirent->d_name,"..")==0 || (*pDirent->d_name) == '.' )){}
        else {
        leer(pDirent->d_name, "./test");
        }
    }

    // Close directory and exit.

    closedir (pDir);
}