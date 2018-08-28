#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
void enregistrer(struct ville* L,struct route* K)
{   struct ville* parcours1;
    struct route* parcours2;
    FILE *fp1,*fp2;


if(L!=NULL){
  parcours1=L;

fp1=fopen("villes.txt","w+");
        while(parcours1!=NULL)
            {
                fprintf(fp1,"%s\n",parcours1->nomville);
                parcours1=parcours1->suivant;
            }
            printf("Villes enregistrees avec succes.\n");
fclose(fp1);
}
else{ printf("\n\nPas des villes a enregistrer!\n\n"); }


if(K!=NULL){
    parcours2=K;

fp2=fopen("routes.txt","w+");
        while(parcours2!=NULL)
                {
                fprintf(fp2,"%d %s %s %d\n",parcours2->id,parcours2->villedepart,parcours2->villearrivee,parcours2->distance);
                parcours2=parcours2->suivant;
            }
            printf("Routes enregistrees avec succes.\n");
fclose(fp2);
}
else{ printf("\n\nPas des routes a enregistrer!\n\n"); }
}
