#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct ville* modifierville(struct ville*L)
{
     char inter[50];
     struct ville* parcour=L;

printf("Taper le nom de la ville a modifier: ");
fflush(stdin);
scanf("%s",inter);

while((strcmp(inter,parcour->nomville)!=0) && (parcour->suivant!=NULL)) parcour=parcour->suivant;
if (strcmp(parcour->nomville,inter)==0){
printf("Taper le nouveau nom de cette ville: ");
scanf("%s",parcour->nomville);

}
else printf("Ville introuvable!\n");
return L;
}
