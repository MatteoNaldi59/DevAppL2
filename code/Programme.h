#ifndef Programme
#define Programme

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Structure.h"

void Quitter();
void viderFichier();
void EcraserFichier(Adherent *a);
int recherche(Adherent *a,int n);
Adherent *creerIntiale(Adherent t);
Adherent *insererInitiale(Adherent *a, Adherent t);
Adherent *Initialiser();
Adherent *creerNoeud(int licence);
Adherent *inserer(Adherent *a,int licence);
void rechercheAffiche(Adherent *a,int n);
void afficheCroissant(Adherent *a);
void afficheDecroissant(Adherent *a);
void modifier(Adherent *a, int licence);
int nbFils(Adherent *a,int licence);
Adherent *SupprimerZeroFils(Adherent *a,int licence);
Adherent *Supprimer1Fils(Adherent *a,int licence);
Adherent *Supprimer2Fils(Adherent *a,int licence);
Adherent *liberer (Adherent *a);

#endif 
