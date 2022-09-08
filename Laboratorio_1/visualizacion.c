<<<<<<< HEAD:Laboratorio_1/visualizacion.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void visualizacion_anno(int anno){
    int cantidad_total, cant_baja, cant_media, cant_alta, anno_baja, anno_media, anno_alta;

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
    return;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void visualizacion_anno(int anno){
    int cantidad_total, cant_baja, cant_media, cant_alta, anno_baja, anno_media, anno_alta;
    DIR *dp = opendir("/%d", anno);
    struct dirent *de = NULL;

    /* ABRIR EL DIRECTORIO DEL AÑO, RECORRER Y CONTAR CUANTOS ARCHIVOS HAY, SUMAR TANTO A LA VARIABLE CANT_XX
    COMO A ANNO_XX */

    cantidad_total = 0;
    
    system("cd 3000+");
    

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
    return;
}
>>>>>>> main:Laboratorio_1/visualizacion.c
