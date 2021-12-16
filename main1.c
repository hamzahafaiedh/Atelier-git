#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int main()
{
    nourriture n;
    char fich[30]="utilisateur.txt";
    char id[20];
    char a='9';
    while(a!='0'){
         do{
            printf("\n\n1.ajouter un produit\n");
            printf("2.modifier un produit\n");
            printf("3.supprimer un produit\n");
            printf("4.rechercher produits \n");
            printf("5.afficher tous les produits \n");
            printf("6.afficher les produits en rupture (retoune seulement les produits dont la quantite < 2kg)\n");
            printf("0.quittez\n");
            scanf(" %c",&a);
            printf("____________________________________________\n\n");
         }while(a!='1' && a!='2' && a!='3' && a!='4' && a!='5' && a!='6' && a!='0');

         switch (a){
            case '1':
                ajouter(fich,n);
                break;
            case '2':
                printf("donner ID:\n");
                scanf("%s",id);
                modifier(fich,id);
                break;
            case '3':
                printf("donner ID:\n");
                scanf("%s",id);
                supprimer(fich,id);
                break;
            case '4':
                printf("donner ID:\n");
                scanf("%s",id);
                rechercher(fich,id);
                break;
            case '5':
                afficher(fich);
                break;
            case '6':
                rupture(fich);
                break;
            case '0':
                printf("merci :) \n");
            }
    }
}

