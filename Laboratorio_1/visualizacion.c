#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include "funciones.h"


void listFiles(const char* dirname, int anno, int number, int *cantidad_total, int *cant_prio, int *cant_annoprio) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        return;
    }

    printf("Leyendo archivos en: %s\n", dirname);

    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        if (strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
            *cant_prio += 1;
            //number sera 1 si estamos en el año que nos piden, 0 si no es el caso
            if (number == 1){
                *cantidad_total += 1;
                *cant_annoprio += 1;
            }
        }
        entity = readdir(dir);
        
    }

    closedir(dir);
}

int visualizacion() {
    int cantidad_total = 0, cant_baja = 0, cant_media = 0, cant_alta = 0, anno_baja = 0, anno_media = 0, anno_alta = 0;
    int intanno;
    printf("Ingrese el ano de ingreso: ");
    scanf("%d", &intanno);  

    if (intanno == 2019){
        //2019
        listFiles("./2019/3000+", intanno, 1, &cantidad_total, &cant_baja, &anno_baja);
        listFiles("./2019/6000+", intanno, 1, &cantidad_total, &cant_media, &anno_media);
        listFiles("./2019/9000+", intanno, 1, &cantidad_total, &cant_alta, &anno_alta);
        //2020
        listFiles("./2020/3000+", intanno, 0, &cantidad_total, &cant_baja, &anno_baja);
        listFiles("./2020/6000+", intanno, 0, &cantidad_total, &cant_media, &anno_media);
        listFiles("./2020/9000+", intanno, 0, &cantidad_total, &cant_alta, &anno_alta);
        //2021
        listFiles("./2021/3000+", intanno, 0, &cantidad_total, &cant_baja, &anno_baja);
        listFiles("./2021/6000+", intanno, 0, &cantidad_total, &cant_media, &anno_media);
        listFiles("./2021/9000+", intanno, 0, &cantidad_total, &cant_alta, &anno_alta);
    }
    if (intanno == 2020){
        //2019
        listFiles("./2019/3000+", intanno, 0, &cantidad_total, &cant_baja, &anno_baja);
        listFiles("./2019/6000+", intanno, 0, &cantidad_total, &cant_media, &anno_media);
        listFiles("./2019/9000+", intanno, 0, &cantidad_total, &cant_alta, &anno_alta);
        //2020
        listFiles("./2020/3000+", intanno, 1, &cantidad_total, &cant_baja, &anno_baja);
        listFiles("./2020/6000+", intanno, 1, &cantidad_total, &cant_media, &anno_media);
        listFiles("./2020/9000+", intanno, 1, &cantidad_total, &cant_alta, &anno_alta);
        //2021
        listFiles("./2021/3000+", intanno, 0, &cantidad_total, &cant_baja, &anno_baja);
        listFiles("./2021/6000+", intanno, 0, &cantidad_total, &cant_media, &anno_media);
        listFiles("./2021/9000+", intanno, 0, &cantidad_total, &cant_alta, &anno_alta);
    }
    if (intanno == 2021){
        //2019
        listFiles("./2019/3000+", intanno, 0, &cantidad_total, &cant_baja, &anno_baja);
        listFiles("./2019/6000+", intanno, 0, &cantidad_total, &cant_media, &anno_media);
        listFiles("./2019/9000+", intanno, 0, &cantidad_total, &cant_alta, &anno_alta);
        //2020
        listFiles("./2020/3000+", intanno, 0, &cantidad_total, &cant_baja, &anno_baja);
        listFiles("./2020/6000+", intanno, 0, &cantidad_total, &cant_media, &anno_media);
        listFiles("./2020/9000+", intanno, 0, &cantidad_total, &cant_alta, &anno_alta);
        //2021
        listFiles("./2021/3000+", intanno, 1, &cantidad_total, &cant_baja, &anno_baja);
        listFiles("./2021/6000+", intanno, 1, &cantidad_total, &cant_media, &anno_media);
        listFiles("./2021/9000+", intanno, 1, &cantidad_total, &cant_alta, &anno_alta);
    }

    printf("La cantidad de estudiantes de %d son: ", intanno);

    printf("%d", cantidad_total);
    printf("\n");
    printf("    ");
    printf("La cantidad de estudiantes de %d con prioridad 3000-5999 son: ", intanno);
    printf("%d", anno_baja);
    printf("\n");
    printf("    ");
    printf("La cantidad de estudiantes de %d con prioridad 6000-8999 son: ", intanno);
    printf("%d", anno_media);
    printf("\n");
    printf("    ");
    printf("La cantidad de estudiantes de %d con prioridad 9000+ son: ", intanno);
    printf("%d", anno_alta);


    printf("\nDel total de estudiantes:");
    printf("\n");
    printf("    ");
    printf("Existen %d con prioridad 3000-5999.", cant_baja);
    printf("\n");
    printf("    ");
    printf("Existen %d con prioridad 6000-8999.", cant_media);
    printf("\n");
    printf("    ");
    printf("Existen %d con prioridad 9000+. \n", cant_alta);
    return 0;

}
