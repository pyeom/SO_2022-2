#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void visualizacion(){
    int anno;
    int cantidad_total = cant_baja = cant_media = cant_alta = anno_baja = anno_media = anno_alta = 0;

    struct dirent *pDirent;
    DIR *pDir, *aux;

    scanf("Año que desea revisar: ", anno);

    if (anno == 2019){
        pDir = opendir("/2019");
        if (pDir == NULL) {
        printf ("Cannot open directory '%s'\n", "2019");
        }

        // Process each entry.

        while ((pDirent = readdir(pDir)) != NULL)  {
            if((strcmp(pDirent->d_name,".")==0 || strcmp(pDirent->d_name,"..")==0 || (*pDirent->d_name) == '.' )){}
            else {
                printf ("[%s]\n", pDirent->d_name);

                aux = opendir(pDirent->d_name);
                while ((pDirent = readdir(aux);) != NULL) {

                    if((strcmp(pDirent->d_name,".")==0 || strcmp(pDirent->d_name,"..")==0 || (*pDirent->d_name) == '.' )){}
                    else {
                        printf("[%s]\n", pDirent->d_name);
                        cantidad_total++;
                        cant_baja++;
                        anno_baja++;
                    }
                }
            
            }
        }
    }

    else if(anno == 2020){
        pDir = opendir("/2020");
        if (pDir == NULL) {
        printf ("Cannot open directory '%s'\n", "2020");
        }

        // Process each entry.

        while ((pDirent = readdir(pDir)) != NULL)  {
            if((strcmp(pDirent->d_name,".")==0 || strcmp(pDirent->d_name,"..")==0 || (*pDirent->d_name) == '.' )){}
            else {
            printf ("[%s]\n", pDirent->d_name);

            }
        }
    }

    else{
        pDir = opendir("/2021");
        if (pDir == NULL) {
        printf ("Cannot open directory '%s'\n", "2021");
        }

        // Process each entry.

        while ((pDirent = readdir(pDir)) != NULL)  {
            if((strcmp(pDirent->d_name,".")==0 || strcmp(pDirent->d_name,"..")==0 || (*pDirent->d_name) == '.' )){}
            else {
            printf ("[%s]\n", pDirent->d_name);

            }
        }
    }
    /* ABRIR EL DIRECTORIO DEL AÑO, RECORRER Y CONTAR CUANTOS ARCHIVOS HAY, SUMAR TANTO A LA VARIABLE CANT_XX
    COMO A ANNO_XX */

    printf("La cantidad de estudiantes de %d son: ", anno);
    printf("%d", cantidad_total);
    printf("\n");
    printf("    ");
    printf("La cantidad de estudiantes de %d con prioridad 3000-5999 son: ", anno);
    printf("%d", anno_baja);
    printf("\n");
    printf("    ");
    printf("La cantidad de estudiantes de %d con prioridad 6000-8999 son: ", anno);
    printf("%d", anno_media);
    printf("\n");
    printf("    ");
    printf("La cantidad de estudiantes de %d con prioridad 9000+ son: ", anno);
    printf("%d", anno_alta);

    /* ABRIR LOS DIRECTORIOS DE LOS OTROS AÑOS Y SUMAR SEGUN CORRESPONDA
    EN LA VARIABLE CANT_XX*/
    printf("\nDel total de estudiantes:");
    printf("\n");
    printf("    ");
    printf("Existen %d con prioridad 3000-5999.", cant_baja);
    printf("\n");
    printf("    ");
    printf("Existen %d con prioridad 6000-8999.", cant_media);
    printf("\n");
    printf("    ");
    printf("Existen %d con prioridad 9000+.", cant_alta);
}
