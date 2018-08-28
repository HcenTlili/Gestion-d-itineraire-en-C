#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "header.h"
#define MAXNODES 50
#define MAX1 150
char* aliasfinder(int i,struct ville* K)
{
    struct ville* parcours=K;

while(parcours!=NULL)
    {
        if(parcours->alias==i)
            {
                return parcours->nomville;
                break;
            }
        parcours=parcours->suivant;
    }
}

void Display_Result(int s,int d,int final,int precede[],int distance[],int weight[][MAXNODES],struct ville* K)
{
int path[MAX1];
int i,j;
i=d;
path[final]=d;
final++;
while(precede[i]!=s)
{
  j=precede[i];
  i=j;
  path[final]=i;
  final++;
}
path[final]=s;
printf("\nla plus courte trajectoire est:\n\n");
for(i=final;i>0;i--)
 printf("\t\t(%s -> %s) avec une distance = %d\n",aliasfinder(path[i],K),aliasfinder(path[i-1],K),weight[path[i]][path[i-1]]);
printf("\nDistance total = %d\n\n",distance[d]);
}




void chercherpcourtchemin(struct route* L)
{
    struct ville* K=NULL,*parcours1,*parcours2,*inter;
    int nbr_villes;
    int weight[MAXNODES][MAXNODES],i,j,distance[MAXNODES],visit[MAXNODES];
    int precede[MAXNODES],final=0;

    int smalldist,newdist,k,s,d,current,distcurr;

do{
    printf("Taper le nombre des villes a parcourir: ");
    scanf("%d",&nbr_villes);
  }while(nbr_villes<2 && nbr_villes>N);

for(i=0;i<nbr_villes;i++) K=ajouterville(K);

for(i=0;i<nbr_villes;i++) weight[i][i]=0;
parcours1=K;

for(i=0;i<nbr_villes;i++){
	parcours2=parcours1;
	for(j=i+1;j<nbr_villes;j++){
	parcours2=parcours2->suivant;
	weight[i][j]=weight[j][i]=fctdistance(L,parcours1->nomville,parcours2->nomville);

	}

	parcours1=parcours1->suivant;
}
inter=K;
for(i=0;i<nbr_villes;i++){
printf("la ville %s a comme alias %d\n",inter->nomville,i);
inter->alias=i;
inter=inter->suivant;
}
printf("Taper l\'alias de la ville de depart(entre 0 et %d): ",nbr_villes-1);  scanf("%d",&s);
printf("Taper l\'alias dela ville de destination(entre 0 et %d): ",nbr_villes-1);  scanf("%d",&d);
for(i=0;i<nbr_villes;i++)
{
  distance[i]=INFINITY;
  precede[i]=INFINITY;
}
distance[s]=0;
current=s;
visit[current]=1;



while(current!=d)
{
  distcurr=distance[current];
  smalldist=INFINITY;
  for(i=0;i<nbr_villes;i++)

    if(visit[i]==0)
    {
        newdist=distcurr+weight[current][i];
        if(newdist<distance[i])
        {
        distance[i]=newdist;
        precede[i]=current;
        }
        if(distance[i]<smalldist)
        {
        smalldist=distance[i];
        k=i;
        }
    }

  current=k;
  visit[current]=1;
}






Display_Result(s,d,final,precede,distance,weight,K);

}
