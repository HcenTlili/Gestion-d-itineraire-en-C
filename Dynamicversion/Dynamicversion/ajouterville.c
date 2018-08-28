#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct ville* ajouterville(struct ville*L)
{
   struct ville* nouveau;
nouveau=(struct ville*)malloc(sizeof(struct ville));
printf("Taper le nom de ville a ajouter/parcourir:");
fflush(stdin);
scanf("%s",nouveau->nomville);
nouveau->suivant=L;
L=nouveau;
return L;
}
