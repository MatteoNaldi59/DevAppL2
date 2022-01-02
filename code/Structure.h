#ifndef Structure
#define Structure

typedef struct Adherent{
	int num_lic;
	char nom[100];
	char prenom[100];
	char datedenaissance[100];
	char Fonction[100];
	struct Adherent *agauche;
	struct Adherent *adroite;
}Adherent;

#endif
