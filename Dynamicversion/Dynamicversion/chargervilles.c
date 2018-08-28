#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct ville* chargervilles(struct ville*L)
{   char inter[50];
    struct ville* nouveau;
    FILE* fp;

fp=fopen("villes.txt","r");
if(fp==NULL){ printf("Impossible d\'ouvrir le fichier"); exit(-1); }
while(fscanf(fp,"%s",inter)!=EOF)
{   nouveau=(struct ville*)malloc(sizeof(struct ville));
    strcpy(nouveau->nomville,inter);
    nouveau->suivant=L;
    L=nouveau;
}
printf("Villes charges avec succee.\n");
fclose(fp);

    return L;
}
