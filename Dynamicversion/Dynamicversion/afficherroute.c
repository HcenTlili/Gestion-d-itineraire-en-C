#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
void afficherroute(struct route* L)
{
    struct route* parcours;
if(L!=NULL){
            parcours=L;
            while(parcours!=NULL)
            {
                printf("Route_id %d: Relie %s et %s d\'une distance egale %d Km\n\n",parcours->id,parcours->villedepart,parcours->villearrivee,parcours->distance);
                parcours=parcours->suivant;
            }
}
else printf("Pas des villes a afficher!\n");
}
