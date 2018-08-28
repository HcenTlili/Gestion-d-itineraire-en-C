#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct route* modifierroute(struct route* L)
{
 int idd;
 struct route* parcour;

 if(L!=NULL)
 {
    parcour=L;
    printf("Taper l\'identificateur de route reliant ces 2 villes: "); fflush(stdin); scanf("%d",&idd);
    while( (parcour->suivant!=NULL)&&(parcour->id!=idd) ) parcour=parcour->suivant;
    if(parcour->id==idd){
     printf("Taper la nouvelle distance entre %s et %s: ",parcour->villedepart,parcour->villearrivee); fflush(stdin); scanf("%d",&parcour->distance);
     }
    else printf("Route introuvable!\n");

 }
 else printf("Pas des routes enregistres!\n");
return L;
}
