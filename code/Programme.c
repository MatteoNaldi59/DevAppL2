#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Structure.h"

void Quitter(){
	char quitte[100];
	printf("Pour revenir au menu principal entrer une valeur !");
	scanf("%s",&quitte);
	system("cls");
}

void viderFichier(){
	FILE *f=fopen("data/Adherent.txt", "w");
	fclose(f);
}

void EcraserFichier(Adherent *a){
	if(a){
		FILE *f=fopen("data/Adherent.txt", "a");
		fprintf(f,"%d %s %s %s %s\n",a->num_lic,a->nom,a->prenom,a->datedenaissance,a->Fonction);
		if(a->adroite){
			EcraserFichier(a->adroite);
		}
		if(a->agauche){
			EcraserFichier(a->agauche);
		}
		fclose(f);
	}
}

int recherche(Adherent *a,int n){
	if(!a){
		return 0;
	}
	else if((a->num_lic)==n){
		return 1;
	}
	else if((a->num_lic)>n){
			recherche(a->agauche,n);
		}
		else{
			recherche(a->adroite,n);
		}
}

Adherent *creerIntiale(Adherent t){
	Adherent *a;
	a=(Adherent *)malloc(sizeof(Adherent));
	a->num_lic=t.num_lic;
	strcpy(a->nom,t.nom);
	strcpy(a->prenom,t.prenom);
	strcpy(a->datedenaissance,t.datedenaissance);
	strcpy(a->Fonction,t.Fonction);
	a->adroite=NULL;
	a->agauche=NULL;
	return a;
}

Adherent *insererInitiale(Adherent *a, Adherent t){
	if(!a){
		return creerIntiale(t);
	}
	else{
		if(t.num_lic<a->num_lic){
			a->agauche=insererInitiale(a->agauche,t);
		}
		else{
			a->adroite=insererInitiale(a->adroite,t);
		}
	}
	return a;
}

Adherent *Initialiser(Adherent *a){
	Adherent *courant;
	Adherent tab[1500];
	int adherent=0,i,inserer;
	FILE *f = fopen("data/Adherent.txt", "r");
	if(!f){
	}
	else{
		while(!feof(f)){
			fscanf(f,"%d %s %s %s %s",&tab[adherent].num_lic,&tab[adherent].nom,&tab[adherent].prenom,&tab[adherent].datedenaissance,&tab[adherent].Fonction);
			adherent++;
		}
	}
	
	for(i=0;i<adherent;i++){
		if(tab[i].num_lic!=0){
			a=insererInitiale(a,tab[i]);	
		}
	}
	return a;
}

Adherent *creerNoeud(int licence){
	Adherent *a;
	FILE *f;
	a=(Adherent *)malloc(sizeof(Adherent));
	a->num_lic=licence;
	printf("Nom de l'adherant numero %d :\n",a->num_lic);
	scanf("%s",&a->nom);
	printf("Prenom de l'adherant numero %d :\n",a->num_lic);
	scanf("%s",&a->prenom);
	printf("Date de Naissance (JJ-MM-AAAA) de l'adherant numero %d :\n",a->num_lic);
	scanf("%s",&a->datedenaissance);
	printf("Fonction (Dirigeant ou Joueur ou Dirgeant/Joueur) de l'adherant numero %d :\n",a->num_lic);
	scanf("%s",&a->Fonction);
	printf("L'adherent a bien ete ajoute !\n");
	Quitter();
	f = fopen("data/Adherent.txt", "a");
	if(!f){
		printf("ERREUR\n");
	}
	fprintf(f,"%d %s %s %s %s\n",a->num_lic,a->nom,a->prenom,a->datedenaissance,a->Fonction);
	fclose(f);
	a->adroite=NULL;
	a->agauche=NULL;
	return a;
}

Adherent *inserer(Adherent *a,int licence){
	if(!a){
		return creerNoeud(licence);
	}
	else{
		if(recherche(a,licence)==1){
			system("cls");
			printf("L'adherent numero %d existe deja !\n",licence);
			Quitter();
		}
		else{
			if(licence<a->num_lic){
				a->agauche=inserer(a->agauche,licence);
			}
			else{
				a->adroite=inserer(a->adroite,licence);
			}
		}
		return a;
	}
}

void rechercheAffiche(Adherent *a,int n){
	if(!a){
		printf("Cet adherent n'existe pas\n");
		Quitter();
	}
	else if((a->num_lic)==n){
		printf("Numero de licence : %d\n",a->num_lic);
		printf("Nom :%s\n",a->nom);
		printf("Prenom :%s\n",a->prenom);
		printf("Date de naissance :%s\n",a->datedenaissance);
		printf("Fonction : %s\n",a->Fonction);
		Quitter();
	}
	else if((a->num_lic)>n){
			rechercheAffiche(a->agauche,n);
		}
		else{
			rechercheAffiche(a->adroite,n);
		}
}

void afficheCroissant(Adherent *a){
	if(a){
		if(a->agauche){
			afficheCroissant(a->agauche);
		}
		printf("Numero de licence : %d\n",a->num_lic);
		printf("Nom :%s\n",a->nom);
		printf("Prenom :%s\n",a->prenom);
		printf("Date de naissance :%s\n",a->datedenaissance);
		printf("Fonction : %s\n",a->Fonction);
		printf("----------------------\n");
		if(a->adroite){
			afficheCroissant(a->adroite);
		}
	}
}

void afficheDecroissant(Adherent *a){
	if(a){
		if(a->adroite){
			afficheDecroissant(a->adroite);
		}
		printf("Numero de licence : %d\n",a->num_lic);
		printf("Nom :%s\n",a->nom);
		printf("Prenom :%s\n",a->prenom);
		printf("Date de naissance :%s\n",a->datedenaissance);
		printf("Fonction : %s\n",a->Fonction);
		printf("----------------------\n");
		if(a->agauche){
			afficheDecroissant(a->agauche);
		}
	}
}

void modifier(Adherent *a, int licence){
	if(a->num_lic==licence){
		printf("Nom de l'adherant numero %d :\n",a->num_lic);
		scanf("%s",&a->nom);
		printf("Prenom de l'adherant numero %d :\n",a->num_lic);
		scanf("%s",&a->prenom);
		printf("Date de Naissance (JJ-MM-AAAA) de l'adherant numero %d :\n",a->num_lic);
		scanf("%s",&a->datedenaissance);
		printf("Fonction (Dirigeant ou Joueur ou Dirgeant/Joueur) de l'adherant numero %d :\n",a->num_lic);
		scanf("%s",&a->Fonction);
	}
	else{
		if(licence<a->num_lic){
			modifier(a->agauche,licence);
		}
		else{
			modifier(a->adroite,licence);
		}
	}
}

int nbFils(Adherent *a,int licence){
	int nb=0;
	if(a->num_lic==licence){
		if(a->adroite){
			nb++;
		}
		if(a->agauche){
			nb++;
		}
		return nb;
	}
	else{
		if(licence<a->num_lic){
			return nb+nbFils(a->agauche,licence);
		}
		else{
			return nb+nbFils(a->adroite,licence);
		}
	}
}

Adherent *liberer(Adherent *a) {
	if(a){
		if(a->agauche){
			a->agauche=liberer(a->agauche);	
		}
		if(a->adroite){
			a->adroite=liberer(a->adroite);
		}
		free(a);
	}
	return NULL;
}

Adherent *SupprimerZeroFils(Adherent *a,int licence){
	Adherent *courant;
	if(licence<a->num_lic){
		courant=a->agauche;
	}
	else{
		if(licence>a->num_lic){
			courant=a->adroite;
		}
		else{
			courant=a;
		}
	}
	if(courant->num_lic==licence){
		if(courant==a){
			a=NULL;
			courant=NULL;
		}
		else{
			if(a->adroite==courant){
				a->adroite=NULL;
			}
			else{
				a->agauche=NULL;
			}
		}
	}
	else{
		if(licence<a->num_lic){
			SupprimerZeroFils(a->agauche,licence);
		}
		else{
			SupprimerZeroFils(a->adroite,licence);
		}
	}
	return a;
}

Adherent *Supprimer1Fils(Adherent *a,int licence){
	Adherent *courant;
	if(licence<a->num_lic){
		courant=a->agauche;
	}
	else{
		if(licence>a->num_lic){
			courant=a->adroite;
		}
		else{
			courant=a;
		}
	}
	
	
	
	if(courant->num_lic==licence){
		
		if(courant==a->agauche){
			if(courant->adroite){
				a->agauche=courant->adroite;
			}
			else{
				a->agauche=courant->agauche;
			}
		}
		
		if(courant==a->adroite){
			if(courant->adroite){
				a->adroite=courant->adroite;
			}
			else{
				a->adroite=courant->agauche;
			}
		}
		
		if(courant==a){
			if(courant->adroite){
				a=courant->adroite;
			}
			else{
				a=courant->agauche;
			}
		}
	}
	else{
		if(licence<a->num_lic){
			Supprimer1Fils(a->agauche,licence);
		}
		else{
			Supprimer1Fils(a->adroite,licence);
		}
	}
	return a;
}

Adherent *Supprimer2Fils(Adherent *a,int licence){
	Adherent *courant=NULL;
	Adherent *courant1=NULL;	
	Adherent *courant2=NULL;
	if(licence<a->num_lic){
		courant=a->agauche;
	}
	else{
		if(licence>a->num_lic){
			courant=a->adroite;
		}
		else{
			courant=a;
		}
	}
	if(courant->num_lic==licence){
		courant1=courant->agauche;
		courant2=courant->agauche;
		while(courant2->adroite){
			courant2=courant1->adroite;
			if(courant2->adroite){
				courant1=courant2;
			}
		}
		if(courant1!=courant2){
			courant1->adroite=NULL;
			courant2->agauche=courant->agauche;
			courant2->adroite=courant->adroite;
			if(courant==a){
				a=courant2;
			}
			else{
				if(courant2->num_lic>a->num_lic){
					a->adroite=courant2;
				}
				else{
					a->agauche=courant2;
				}
			}
		}
		
		else{
			courant1->adroite=courant->adroite;
			a=courant1;
		}
	}
	else{
		if(licence<a->num_lic){
			Supprimer2Fils(a->agauche,licence);
		}
		else{
			Supprimer2Fils(a->adroite,licence);
		}
	}
	return a;
}

