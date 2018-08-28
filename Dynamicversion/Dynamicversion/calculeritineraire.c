#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
void calculeritineraire(struct route* L)
{   int choix;

do{
printf("1- Chercher le plus court chemin avec le theoreme de Dijkstra\n2- Retour au menu principale\n");
fflush(stdin);
scanf("%d",&choix);
switch(choix){

case 1: system("cls"); chercherpcourtchemin(L); break;
case 2: break;
default: system("cls"); printf("Erreur dans votre saisie! Essayer de nouveau!\n");

}
}while(choix!=2);
}
