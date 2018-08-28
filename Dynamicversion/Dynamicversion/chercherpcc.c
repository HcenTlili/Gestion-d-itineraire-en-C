#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
void chercherpcc(struct route* L)
{
char ville1[50],ville2[50];
struct route* parcours;
int i,s=0;
if(L==NULL) printf("Pas des routes enregistres dans le systeme!\n");
else{
    printf("Taper La ville 1: "); fflush(stdin); scanf("%s",ville1);
    printf("Taper La ville 2: "); fflush(stdin); scanf("%s",ville2);

    parcours=L;
    s=parcours->distance;
    i=parcours->id;

while(parcours!=NULL){
    if((!strcmp(parcours->villedepart,ville1) && !strcmp(parcours->villearrivee,ville2)) || (!strcmp(parcours->villedepart,ville2) && !strcmp(parcours->villearrivee,ville1)))
    {
        if(s>(parcours->distance))
            {
            s=parcours->distance;

            i=parcours->id;
            }
        parcours=parcours->suivant;
    }
    else parcours=parcours->suivant;
}
}
if(s) printf("Le plus court chemin entre %s et %s est en prenant la route d\'identificateur %d et qui parcourt une distance egale a %d Km\n",ville1,ville2,i,s);
else printf("L\'une de deux ville n\'est pas trouvee dans le systeme!\n");
}
