#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Structure.h"
#include "Programme.h"

int main(){
	int num,num1,croissant,nb;
	char choix='a';
	Adherent *a=NULL;
	a=Initialiser(a);
	while(choix != '0'){
		system("cls");
		printf("1 - Ajouter\n");
		printf("2 - Afficher\n");
		printf("3 - Modifier\n");
		printf("4 - Supprimer\n");
		printf("5 - Recherche\n");
		printf("0 - Quitter\n");
		scanf("%c", &choix);
		switch(choix){
			case '1':
				system("cls");
				num=0;
				while(num==0){
					printf("Numero de la licence : (La licence ne peut pas etre 0) :");
					scanf("%d",&num);
					system("cls");
				}
				a=inserer(a,num);
				break;
			case '2':
				system("cls");
				printf("1 - Croissant\n");
				printf("2 - Decroissant\n");
				scanf("%d",&croissant);
				if(croissant==1){
					afficheCroissant(a);
					Quitter();
				}
				else{
					afficheDecroissant(a);
					Quitter();
				}
				break;
			case '3':
				system("cls");
				printf("Numero de la licence de l'adherent a modifier : ");
				scanf("%d",&num1);
				if(recherche(a,num1)==0){
					printf("Cet adherent n'existe pas\n");
				}
				else{
					modifier(a,num1);
					printf("L'adherent a bien ete modifier !\n");
					viderFichier();
					EcraserFichier(a);
				}
				Quitter();
				break;
			case '4':
				system("cls");
				printf("Numero de la licence de l'adherent a supprimer: ");
				scanf("%d",&num1);
				if(recherche(a,num1)==0){
					printf("Cet adherent n'existe pas\n");
				}
				else{
					nb=nbFils(a,num1);
					if(nb==0){
						a=SupprimerZeroFils(a,num1);
					}
					if(nb==1){
						a=Supprimer1Fils(a,num1);
					}
					if(nb==2){
						a=Supprimer2Fils(a,num1);
					}
					printf("L'adherent a bien ete supprimer !\n");
					viderFichier();
					EcraserFichier(a);
				}
				Quitter();
				break;
			case '5':
				system("cls");
				printf("Numero de la licence a rechercher: ");
				scanf("%d",&num1);
				rechercheAffiche(a,num1);
				break;
			case '0':
				system("cls");
				a=liberer(a);
				printf("Au Revoir");
				break;
			default:
				break;
		}
	}
	return EXIT_SUCCESS;
}
