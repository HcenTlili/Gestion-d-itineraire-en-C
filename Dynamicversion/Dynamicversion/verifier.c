#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int verifier(int i,struct route* L)
{
    struct route* inter;
    int j=1;
if (L!=NULL){
inter=L;
while((inter!=NULL) && (inter->id!=i)) inter=inter->suivant;
if(inter->id==i) j=0;
}

return j;
}
