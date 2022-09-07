#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <dirent.h>


void mover(){
    DIR *dp = opendir("/test");
    FILE *fp;
    int prioridad, anno, subfolder;
    struct dirent *de = NULL;

    while ((de = readdir(dp))){ //Itera sobre cada File del directorio
        de -> d_name;

        if((fp = fopen(d_name, "r")) != NULL){  //Abre el File y guarda los datos que contiene en anno y prioridad
            fscanf(fp, "%d\n%d", &anno, &prioridad);
        }

        fclose(fp);
        
        if (prioridad >= 9000){ //Mueve el file al folder correspondiente
            subfolder = 3;
            system("mv %s ~/%i/9000+", d_name, anno);
        }

        else if (prioridad >= 6000){
            subfolder = 2;
            system("mv %s ~/%i/6000+", d_name, anno);
        }

        else{
            subfolder = 1;
            system("mv %s ~/%i/3000+", d_name, anno);
        }
        

    }
    closedir(dp);

}