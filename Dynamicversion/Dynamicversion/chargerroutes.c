#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct route* chargerroutes(struct route*L)
{   char villedep[50],villearr[50];
    int i,j;
    struct route* nouveau;
    FILE* fp;

fp=fopen("routes.txt","r");
if(fp==NULL){ printf("Impossible d\'ouvrir le fichier"); exit(-1); }
while(fscanf(fp,"%d %s %s %d",&i,villedep,villearr,&j)!=EOF)
{
    nouveau=(struct route*)malloc(sizeof(struct route));
    nouveau->id=i;
    strcpy(nouveau->villedepart,villedep);
    strcpy(nouveau->villearrivee,villearr);
    nouveau->distance=j;
    nouveau->suivant=L;
    L=nouveau;
}
printf("Routes charges avec succee.\n");
fclose(fp);

    return L;
}
