#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct ville* gerervilles(struct ville* L)
{   int choix;
    printf("Gestion des villes\n");

    do
    {
        printf("1- Ajouter une ville\n2- Modifier une ville\n3- Supprimer une ville\n4- Rechercher une ville\n5- Afficher les villes\n6- Retour au menu principale\n");
        scanf("%d",&choix);
        switch(choix){
        case 1: system("cls"); L=ajouterville(L);  system("cls"); break;
        case 2: system("cls"); L=modifierville(L); system("cls"); break;
        case 3: system("cls"); L=supprimerville(L); break;
        case 4: system("cls"); rechercherville(L);  break;
        case 5: system("cls"); affichervilles(L);   break;
        case 6: break;
        default:system("cls"); printf("\n\nErreur dans votre saisie! Essayer de nouveau!\n\n    ");
        }
    }while(choix!=6);
    return L;
}
