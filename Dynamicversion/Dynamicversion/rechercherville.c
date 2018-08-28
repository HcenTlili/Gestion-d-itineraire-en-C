#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
void rechercherville(struct ville* L)
{    int i=0;
     char inter[50];
     struct ville* parcour=L;

printf("Taper le nom de la ville a rechercher: ");
fflush(stdin);
scanf("%s",inter);

while((strcmp(inter,parcour->nomville)!=0) && (parcour->suivant!=NULL))
{
parcour=parcour->suivant;
i++;
}
if (strcmp(parcour->nomville,inter)==0)
printf("Ville trouvee a la position %d\n",i);
else printf("Ville introuvable!\n");
}
