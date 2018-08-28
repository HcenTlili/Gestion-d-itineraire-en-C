#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct route* supprimerroute(struct route* L)
{ struct route* succ,* prec;
  int i;
if(L!=NULL)
{
printf("Taper l\'identificateur du route a supprimer: ");
scanf("%d",&i);
prec=L;
succ=L;
while(succ->id!=i && succ->suivant!=NULL){
                                            prec=succ;
                                            succ=succ->suivant;
                                        }
    if(succ->id==i)
                {
                    if(succ==L) L=succ->suivant;
                    else{
                            if(succ->suivant==NULL) prec->suivant=NULL;
                            else prec->suivant=succ->suivant;
                        }
                    free(succ);
                    printf("\nRoute d\'identificateur %d a ete supprimee\n",i);
                }
    else printf("\nRoute introuvable!\n");
}
else printf("\nPas des routes a supprimer!\n");
 return L;
}
