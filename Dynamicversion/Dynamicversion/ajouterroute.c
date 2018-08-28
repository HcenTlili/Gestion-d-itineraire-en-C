#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct route* ajouterroute(struct route* L)
{   struct route* nouveau;
nouveau=(struct route*)malloc(sizeof(struct route));
printf("Taper la ville de depart: "); fflush(stdin); scanf("%s",nouveau->villedepart);
printf("Taper la ville d\'arrivee: "); fflush(stdin); scanf("%s",nouveau->villearrivee);
printf("Taper la distance separant ces 2 villes: "); fflush(stdin); scanf("%d",&nouveau->distance);
printf("Taper l\'identificateur de ce route: "); fflush(stdin); scanf("%d",&nouveau->id);

nouveau->suivant=L;
L=nouveau;
return L;
}
