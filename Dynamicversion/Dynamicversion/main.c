#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int main()
{
    struct ville* liste1=NULL;
    struct route* liste2=NULL;
   int choix;


do{
    printf("\t\t\t\t******Gestion d itiniraires******\n\n\n\t\t\t\t\t****Saisir votre choix:****\n\t\t\t\t\t0- Charger les donnees\n\t\t\t\t\t1- Gerer les villes\n\t\t\t\t\t2- Gerer les routes\n\t\t\t\t\t3- Calculer itineraire\n\t\t\t\t\t4- Enregistrer et quitter\n");
    scanf("%d",&choix);
switch(choix)
{
case 0: system("cls");
        liste1=chargervilles(liste1);
        liste2=chargerroutes(liste2);                                   break;
case 1: system("cls"); liste1=gerervilles(liste1);    system("cls");    break;
case 2: system("cls"); liste2=gererroutes(liste2);    system("cls");    break;
case 3: system("cls"); calculeritineraire(liste2);    system("cls");    break;
case 4: system("cls"); enregistrer(liste1,liste2);                      break;
default: system("cls"); printf("\n\nErreur dans votre saisie! Essayer de nouveau!\n\n\n");
}

}while(choix!=4);
    return 0;
}
