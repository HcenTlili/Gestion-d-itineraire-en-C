#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct route* gererroutes(struct route* L)
{
    int choix;
    printf("Gestion des routes\n");
    do
    {
        printf("1- Ajouter une route\n2- Modifier une route\n3- Supprimer une route\n4- Afficher les routes\n5- Retour au menu principale\n");
        scanf("%d",&choix);
       switch(choix){
        case 1: system("cls"); L=ajouterroute(L);  system("cls"); break;
        case 2: system("cls"); L=modifierroute(L); system("cls"); break;
        case 3: system("cls"); L=supprimerroute(L); break;
        case 4: system("cls"); afficherroute(L);    break;
        case 5: system("cls"); break;
        default:system("cls"); printf("\n\nErreur dans votre saisie! Essayer de nouveau!\n\n");
        }
    }while(choix!=5);
    return L;
}
