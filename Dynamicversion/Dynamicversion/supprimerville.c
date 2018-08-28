#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct ville* supprimerville(struct ville* L)
{
        struct ville* succ,* prec;
        char choix[50];
if(L!=NULL)
{
printf("Taper la ville a supprimer: ");
scanf("%s",choix);
prec=L;
succ=L;
while(strcmp(succ->nomville,choix) && succ->suivant!=NULL){
                                            prec=succ;
                                            succ=succ->suivant;
                                        }
    if(!strcmp(succ->nomville,choix))
                {
                    if(succ==L) L=succ->suivant;
                    else{
                            if(succ->suivant==NULL) prec->suivant=NULL;
                            else prec->suivant=succ->suivant;
                        }
                    free(succ);
                    printf("\n%s a ete supprimee\n\n",choix);
                }
    else printf("\nVille introuvable!\n\n");
}
else printf("\nPas des villes a supprimer!\n\n");

    return L;
}
