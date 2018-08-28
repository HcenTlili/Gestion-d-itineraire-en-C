#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int calculerdistance(struct route* L,char a[],char b[])
{   int s,q;
struct route* parcours;

    parcours=L;
    q=parcours->distance;
while(parcours!=NULL){
    if((!strcmp(parcours->villedepart,a) && !strcmp(parcours->villearrivee,b)) || (!strcmp(parcours->villedepart,b) && !strcmp(parcours->villearrivee,a))){
        q=parcours->distance;
        parcours=parcours->suivant;
    }
    else parcours=parcours->suivant;
}
s=q;


    return s;
}
