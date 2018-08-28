#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int fctdistance(struct route* L,char a[],char b[])
{   struct route* parcours;
    int j=INFINITY,i=1;

    parcours=L;

while(parcours!=NULL && i!=0){
    if((!strcmp(parcours->villedepart,a) && !strcmp(parcours->villearrivee,b)) || (!strcmp(parcours->villedepart,b) && !strcmp(parcours->villearrivee,a))){
        	j=parcours->distance;
        	i=0;
    }
    else parcours=parcours->suivant;
}
return j;
}

