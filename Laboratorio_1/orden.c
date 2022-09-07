#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <dirent.h>


void mover(){
    DIR *dp = opendir("/test");
    FILE *fp;
    char *comando;
    int prioridad, anno;
    struct dirent *de = NULL;

    while ((de = readdir(dp))){ //Itera sobre cada File del directorio
        de -> d_name;

        if((fp = fopen(d_name, "r")) != NULL){  //Abre el File y guarda los datos que contiene en anno y prioridad
            fscanf(fp, "%d\n%d", &anno, &prioridad);
        }

        fclose(fp);
        
        if ((*int)anno == 2019){

             if (prioridad >= 9000){ //Mueve el file al folder correspondiente
            system("mv %s ~/2019/9000+", d_name);
            }

            else if (prioridad >= 6000){
                system("mv %s ~/2019/6000+", d_name);
            }

            else{
                system("mv %s ~/2019/3000+", d_name);
            }
        }

        else if ((*int)anno == 2020){
            if (prioridad >= 9000){ //Mueve el file al folder correspondiente
                system("mv %s ~/2020/9000+", d_name);
            }

            else if (prioridad >= 6000){
                system("mv %s ~/2020/6000+", d_name);
            }

            else{
                system("mv %s ~/2020/3000+", d_name);
            }
        }

        else{
            if (prioridad >= 9000){ //Mueve el file al folder correspondiente
                system("mv %s ~/2021/9000+", d_name);
            }

            else if (prioridad >= 6000){
                system("mv %s ~/2021/6000+", d_name);
            }

            else{
                system("mv %s ~/2021/3000+", d_name);
            }
        }
        

    }
    closedir(dp);

}