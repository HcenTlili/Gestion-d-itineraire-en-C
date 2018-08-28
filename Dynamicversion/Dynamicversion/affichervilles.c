#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
void affichervilles(struct ville* L)
{   int i=1;
    struct ville* parcours;
if(L!=NULL){
    parcours=L;
while(parcours!=NULL)
{
printf("Ville %d: %s\n",i++,parcours->nomville);
parcours=parcours->suivant;
}
}
else printf("Pas des villes a afficher!\n");
}
