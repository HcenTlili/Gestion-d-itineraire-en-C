#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "route.h"
#include "ville.h"
int id_ville(ville *v,int nbrvilles, char *nom_ville)
{int i;
    for(i=0;i<nbrvilles;i++)
       {if(strcmp(nom_ville,v[i].nomville)==0)
            return (v[i].idville);
       }

    return -1;
}


int chercherroute(route *r,int nbrroutes,route rout1)
{int i;
    for (i=0;i<nbrroutes;i++)
    {


          if((r[i].idvillearrivee==rout1.idvillearrivee)&&(r[i].idvilledepart==rout1.idvilledepart))
            return i;
            if((r[i].idvillearrivee==rout1.idvilledepart)&&(r[i].idvilledepart==rout1.idvillearrivee))
            return i;

      }

     return(-1);
}
route saisirroute(ville *tabVilles,int nbrroutes,int nbrvilles)
{   route rout1;
    int id1,id2;
    char ville1[100], ville2[100];
   do{ printf("donner la ville de depart: ");
    scanf("%s",ville1);
    printf("Arrivee: ");
    scanf("%s",ville2);
    printf("distance: ");
    scanf("%d",&(rout1.distance));
    id1=id_ville(tabVilles,nbrvilles,ville1);
    id2=id_ville(tabVilles,nbrvilles,ville2);
    }while((id1<0)||(id2<0));
   rout1.idvilledepart=id1; //printf("test : %d",rout1.idvilledepart);
   rout1.idvillearrivee=id2;
   rout1.id=nbrroutes;
return rout1;
}
void ajouterroute(route* tab_rout,int *nbrroutes,route r)
{
    tab_rout[*nbrroutes].distance=r.distance;
    tab_rout[*nbrroutes].id=*nbrroutes;
    tab_rout[*nbrroutes].idvillearrivee=r.idvillearrivee;

    tab_rout[*nbrroutes].idvilledepart=r.idvilledepart;
    (*nbrroutes)++;

}
void modifierroute(route *tab_route,int *nbrroutes)
{int dist,ident=-1;
do{
printf("donner l id de la route a modifier");
scanf("%d",&ident);
}while((ident<0)||(ident>*nbrroutes));

        do{
    printf("la nouvelle distance ?");
    scanf("%d",&dist);
    tab_route[ident].distance=dist;
}while(dist<=0);


}
 void supprimerroute(route tab_route[10],int *nbrroutes,route r)
 { int ind;
   ind=chercherroute( tab_route,*nbrroutes,r);
       if(ind==-1) printf("cette route n'existe pas");
      else {tab_route[ind]=tab_route[(*nbrroutes)-1];
         (*nbrroutes)--;}
 }



void afficheroutes(int nbrroutes,ville *tab_villes,int nbrvilles,route *tab_route)
    {int i;

    char a[10];
    char b[10];
    printf("les %d routes sont\n",nbrroutes);
        for(i=0;i<nbrroutes;i++)
        {
          strcpy(a,tab_villes[tab_route[i].idvilledepart].nomville);

          strcpy(b,tab_villes[tab_route[i].idvillearrivee].nomville);

            printf(" %s -->%s:distance en KM =%d, id=%d\n",a,b,tab_route[i].distance,tab_route[i].id);
        }}
int minimum(int tab[100], int a)
{int m;
int i ;
int k;

for(i=0;i<a;i++){if((tab[i]!=0)&&(tab[i]!=-1)){m=tab[i];}}
for(k=0;k<a;k++){if((tab[k]!=0)&&(tab[k]!=-1)&&(tab[k]<m)){m=tab[k];}}
return m ;
}
int existance(int a,int tab[100],int b)
{ int k,i;
k=0;
if(b==-1){return 1;}
else {    for(i=0;i<b;i++)
    {
        if(tab[i]==a){k=1;}
    }}
    return k;
}
int supp_elt(int tab[100],int i,int a)
{int j ;
    for(j=i;j<a;j++){tab[j]=tab[j+1];}
}


void leplusprochevoisin(ville tp[100],int nvp,int nbrvilles,ville *tab_ville,int nbrroutes,route *tab_route)
{ int i,j;
int tab[100];
int mat[100][100];
int p;
int u ;
route r;
    do{
    printf("donner le nombre de villes a parcourir \t");
    scanf("%d",&nvp);
    }while(nvp<1);

    for(i=0;i<nvp;i++)
    {
    do{printf("donner l id de la ville %d dans le tableau des villes \n",i);
    scanf("%d",&tp[i].idville);
    }while((tp[i].idville<0)||(tp[i].idville>=nbrvilles));
    }
    for(j=0;j<nvp;j++)
    {
        printf("%s\t\n",tab_ville[tp[j].idville].nomville);
    }
    for(i=0;i<nvp;i++)
    {
        for(j=0;j<nvp;j++)
        { route r;
        r.idvilledepart=tp[i].idville;
        r.idvillearrivee=tp[j].idville;
            if(chercherroute(tab_route,nbrroutes,r)!=-1){mat[i][j]=tab_route[chercherroute(tab_route,nbrroutes,r)].distance;}
            if(chercherroute(tab_route,nbrroutes,r)==-1){mat[i][j]=-1;}
            if(i==j){mat[i][j]=0;}
        }
    }
    for(i=0;i<nvp;i++)
    {
        for(j=0;j<nvp;j++)
            {
             printf("%d\t",mat[i][j]);
             if(j==nvp-1){printf("\n");}
            }
    }

  int k ;
  int h;
  int tab1[100];
   i=0;
   k=1;
   h=0;
   p=0;
   printf("le parcours est : %s\t",tab_ville[tp[0].idville].nomville);
for(j=0;j<nvp;j++){tab[j]=mat[0][j];}
for(j=0;j<nvp;j++){if(tab[j]==minimum(tab,nvp)){i=j;}}
for(u=0;u<nvp;u++){mat[u][0]=0;}
i=0;
p=0;
   while(k<nvp)
   {
   for(j=0;j<nvp;j++)
   { if(j==i){tab[j]=0;}
       tab[j]=mat[i][j];
   }
   tab1[k-1]=minimum(tab,k);
   for(j=0;j<nvp;j++)
   {
       if((tab[j]==minimum(tab,nvp))){r.idvilledepart=tp[i].idville;
       r.idvillearrivee=tp[j].idville;
       p=p+tab_route[chercherroute(tab_route,nbrroutes,r)].distance;
       {for(u=0;u<nvp;u++){mat[u][j]=0;};
       printf("%s\t",tab_ville[tp[j].idville].nomville);
       mat[j][i]=-1;i=j; h++;
       }}
   }
  k++;
   }
   printf("et on reprend le meme chemin en sens inverse pour completer le parcours\n");
   printf("la distance parcourue est : %d\t\n",p);
   for(i=0;i<nvp;i++)
    {
        for(j=0;j<nvp;j++)
            {
             printf("%d\t",mat[i][j]);
             if(j==nvp-1){printf("\n");}
            }
    }
}

void inversion(ville *tab_villes,int nbr_villes,route *tab_route,int nbrroutes)
{ int a;
int b;
int i;
int j;
route r;
    int tabid[100];
    for(i=0;i<nbr_villes;i++){tabid[i]=tab_villes[i].idville;}
    printf("donner l id de la ville de depart");
    scanf("%d",&a);
    printf("donner l id de la ville d arrivee");
    scanf("%d",&b);
    i=a;
    printf("%s\t",tab_villes[a].nomville);
    j=a+1;
    do{
        r.idvilledepart=i;
        r.idvillearrivee=j;
        if(chercherroute(tab_route,nbrroutes,r)!=-1){printf("%s\t",tab_villes[j].nomville);i=j;j++;}
        else{j++;}
    }while(j<=b);
}
int egalitevect(int a[100],int b[100],int c)
{
    int i ;
    int k=1;
    for(i=0;i<=c;i++)
    {
        if(a[i]!=b[i]){ k=-1 ;}
    }
    return k;
}
int fact(int a)
{
    int k=1 ;
    int i ;
    if(a==0){return 1 ;}
    else{for(i=1;i<=a;i++)
    {
        k=k*i;
    }
    return k ;}
}
void saisir_tab_parcours(ville *tab_ville,int nbrvilles)
{int j,i;
int tab_parcours[100];
char nom[15];
int g,y,h,e;
   int nvp=0;
   int mat[100][100];
   int tab[100];
   int tab1[100];
   int tab2[100];
   int m=-1;
   do{
    printf("donner le nombre de villes du parcours");
    scanf("%d",&nvp);
   }while(nvp<2);
    for(i=0;i<nvp;i++)
    {
    do{
    printf("donner la ville num %d :",i);
    scanf("%s",nom);
        j=id_ville(tab_ville,nbrvilles,nom);

    tab_parcours[i]=j;
       }while(id_ville(tab_ville,nbrvilles,nom)==-1);
    }
    for(i=0;i<nvp;i++)
    {
        mat[i][0]=tab_parcours[i];
    }
    for(i=1;i<nvp;i++)
    {
        do
            {for(g=0;g<nvp;g++)
            { do
            {

    srand(time(NULL));
    int random = rand() % nvp;
    mat[g][i]=tab_parcours[random];
    for(h=0;h<g;h++){tab[h]=mat[h][i];}
}while(existance(mat[g][i],tab,g)==1);
            }
            for(y=0;y<nvp;y++){tab1[y]=mat[i][y];}
           for(y=0;y<i;y++){for(e=0;e<nvp;e++){tab2[e]=mat[e][y];} if(egalitevect(tab1,tab2,nvp)==1){m=1;}}
    }while(m=-1);

        }

        for(i=0;i<nvp;i++)
        {
            for(j=0;j<nvp;j++)
            {
                printf("%d",mat[i][j]);
            }
        }
}
void permutations(ville *tab_ville,int nbrvilles,route *tab_route,int nbrroutes)
{int i , j , k , h,z ;
int tab_parcours[100];
int tab1[100];
int mat[100][100];
int r;
int nvp;
int p ;
char nom[100];
    do{
    printf("donner le nombre de villes du parcours");
    scanf("%d",&nvp);
   }while(nvp<2);
    for(i=0;i<nvp;i++)
    {
    do{
    printf("donner la ville num %d :",i);
    scanf("%s",nom);
        j=id_ville(tab_ville,nbrvilles,nom);

    tab_parcours[i]=j;
       }while(id_ville(tab_ville,nbrvilles,nom)==-1);
    }

    for(j=0;j<4;j++)
    {
    for(i=0;i<nvp;i++)
    {
     tab1[i]=tab_parcours[i];
    }
    k=nvp;
    do
    {
    srand(time(NULL));
    r = rand() % k-1;
    mat[nvp-k][j]=tab1[r];
    for(z=r;z<=k-1;z++)
    {
        tab1[z]=tab1[z+1];
    }
    k=k-1;
    }while(k!=0);
    }
    for(i=0;i<nvp;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d\t",mat[i][j]);
            if(j==3){printf("\n");}
        }
    }
    printf("%d",mat[0][0]);
}
void permutaionspossibles(route tab_route[100],ville *tab_ville,int *nbrroutes,int nbrvilles)
{int i;
int j ;
int k ;
int nvp;
int p;
int tabdist[100];
int tab_parcours[100];
char nom[100];
int mat[100][100];
route r;
int aux;
  do{
    printf("donner le nombre de villes du parcours");
    scanf("%d",&nvp);
   }while(nvp<2);
    for(i=0;i<nvp;i++)
    {
    do{
    printf("donner la ville num %d :",i);
    scanf("%s",nom);
        j=id_ville(tab_ville,nbrvilles,nom);

    tab_parcours[i]=j;
       }while(id_ville(tab_ville,nbrvilles,nom)==-1);
    }
    for(i=0;i<nvp;i++)
    {
        mat[i][0]=tab_parcours[i];
    }
    for(i=1;i<nvp-1;i++)
    {
        aux=tab_parcours[i-1];
        tab_parcours[i-1]=tab_parcours[i];
        tab_parcours[i]=aux;
        for(j=0;j<nvp;j++)
        {
            mat[j][i]=tab_parcours[j];
        }
    }


    for(i=0;i<nvp-1;i++)
    {
        j=1;
        r.idvilledepart=mat[0][i];
        r.idvillearrivee=mat[1][i];
        do{
                j++;
        r.idvilledepart=mat[j-1][i];
        r.idvillearrivee=mat[j][i];

        }while((chercherroute(tab_route,nbrroutes,r)<nbrroutes)&&(chercherroute(tab_route,nbrroutes,r)>0));
        if(j>=nvp){tabdist[i]=1;}
        else{tabdist[i]=0;}
    }

    printf("le tableau des id apres les permutations\t");for(i=0;i<nvp;i++){printf("%d\t",tab_parcours[i]);}printf("\n");
    printf("le tableau de verification de l existance d'une route complete dans chaque ordre( 1:oui  0:non)\n");for(i=0;i<nvp-1;i++){printf("%d\t",tabdist[i]);}
    for(i=0;i<nvp-1;i++)
    {
        if(tabdist[i]==1)
        { p=0;
            for(j=1;j<nvp;j++){
                r.idvilledepart=mat[j-1][i];
                r.idvillearrivee=mat[j][i];
                p=p+tab_route[chercherroute(tab_route,nbrroutes,r)].distance;
            }
            tabdist[i]=p;
        }
    }
   printf("\nle parcours est\t");
    for(i=0;i<nvp-1;i++){
        if(tabdist[i]==minimum(tabdist,nvp-1)){for(j=0;j<nvp;j++){printf("%s\t",tab_ville[mat[j][i]].nomville);}printf("\n la distance parcourue est \t %d\n",tabdist[i]);}
    }

}
void gestion_des_routes(int *nbrroutes,route *tab_route, ville* tab_villes,int nbrvilles){

int c ;
route r ;
printf("\t\t\t\t*****GESTION DES ROUTES*****\n");
printf("\t\t\t\t1:ajouter une route\n");
printf("\t\t\t\t2:supprimer une route\n");
printf("\t\t\t\t3:afficher les routes\n");
printf("\t\t\t\t4:modifier une route\n");
printf("\t\t\t\t5:menu principal\n");
scanf("%d",&c);
switch(c)
{
  case 1:system("cls");
       r=saisirroute(tab_villes,*nbrroutes,nbrvilles);
    ajouterroute(tab_route,nbrroutes,r);
break;
    case 2:system("cls");printf("donner l id de la ville de depart");
 scanf("%d",&r.idvilledepart);printf("donner l id de la ville de arrivee");scanf("%d",&r.idvillearrivee); supprimerroute(tab_route,nbrroutes,r);break;
    case 3:system("cls");printf("%d",*nbrroutes);afficheroutes(*nbrroutes,tab_villes,nbrvilles,tab_route);break;
    case 4:system("cls");modifierroute(tab_route,nbrroutes);break;
    case 5:system("cls");


    default:system("cls");printf("choix inexistant");

}
}

/*** gestion ***/

void calculs_itineraires (ville *tab_villes,int nbrvilles,route tab_route[100],int nbrroutes)
{int q;
ville tp[100];
int nvp;
    printf("\t\t\t\t1:chercher la pct en utilisant la methode du plus proche voisin\n");
    printf("\t\t\t\t2:chercher la pct en utilisant la methode des permutations aleatoires \n");
    printf("\t\t\t\t3:utiliser la gestion aleatoire de tout les chemins et le choix du meilleur \n");
    printf("\t\t\t\t4:retourner au menu principal\n");
    scanf("%d",&q);
    switch(q)
    {
        case 1:system("cls");afficher_villes(tab_villes,nbrvilles);
        leplusprochevoisin(tp,nvp,nbrvilles,tab_villes,nbrroutes,tab_route);break;
        case 2:system("cls");permutaionspossibles(tab_route,tab_villes,nbrroutes,nbrvilles);break;
        case 3:system("cls");saisir_tab_parcours(tab_villes,nbrvilles);break;
        case 4:system("cls");
        default:system("cls");printf("choix inexistant");void calculs (ville *tab_ville,int nbrvilles,route *tab_route,int nbrroutes);
    }
}

