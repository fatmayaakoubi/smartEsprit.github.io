#include <gtk/gtk.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
}Naissance;
typedef struct
{
    char username[20];
    char password[20];
}compt;

typedef struct
{
    char nom[20];
    char prenom[20];
    char sexe[20];
    Naissance date_naissance;
    char cin[20];
    char gsm[20];
    int id;
   char chambre[20];
    compt compt;
  char categorie[20];
}Etudiant;

typedef struct
{
char id[30];
char type[30];

char marque[30];
char valeur[30];
char jour[30];
char heure[30];
} capteur;


struct date_de_naissance {
int jour;
int mois;
int annee;
};
typedef struct date_de_naissance date ;

struct per  {
char nom[30];
char prenom[30];
char identifiant[30];
date d;
char numero_de_cin[30] ; 
char sexe[30]; 
char poste[50];
};typedef struct per personne;

typedef struct reclam
{
    int id;
    char prenom[20];
    char nom[20];
    char classe[10];
    int service;
    char desc[500];
}reclam;

typedef struct
{
	char entree[50];
	char plat_principale[50];
	char dessert[50];
}plat;

typedef struct
{
	char temps[20];
	char jour[20];
	plat menu;
	int dechets;
}menu;

void  ajouter_etudiant(Etudiant e);
void afficher_etudiant(GtkWidget *liste);
void supprimer_etudiant(Etudiant e, char cin[]);
void modifier_etudiant(Etudiant h, char cin[]);
void chercher_etudiant(Etudiant e, char cin[20], int *ok);//pointeur ok pour verifier eistance du utilisateur recherché
void afficher_etudiantModif(GtkWidget *liste);
void afficher_etudiantSupp(GtkWidget *liste);
int nbre (int calcul[],char txt[]);
int id_supprimer_etudiant(Etudiant e, char cin[]); //Return la valeur de l'id qui va être supprimer

void ajouter_capteur(capteur c);
void afficher_capteur(GtkWidget *liste, char fichier[20]);
int exist_capteur(char*id);
void supprimer_capteur(char numero[100]);
int ChercherCapteur(GtkWidget* treeview1,char*l,char*type);
void modifier_capteur(capteur c,char numero [30]);
void afficherCapteur(GtkWidget* treeview1,char*l);
void etage_pannes(capteur c);
////////////////////////////////////////////////////////////////
void capteur_def(capteur c);
void liste_alarme(capteur c);
int verif(char user[], char pw[]);
void ajouter_personne(char utilisateur[],personne p);
void afficher(GtkWidget *liste,char texte[]);
void modifier_personne(personne p1);
void supprimer_personne(char identifiant[50]);
int rechercher_personne(char utilisateur[],char identifiant[]);
////////////////////
void ajouter(reclam u, char *fname);
void supprimer(reclam u, char *fname);
void modifier(reclam u, char *fname);
void afficherrec(GtkWidget *liste, char *fname);
char* plus_reclame(char *fname);
///////////////////////////////////////
void ajouterstock (char id[],char type[],int quant);
void supprimerstock(char id1[]);
void modifierstock(char id1[],int quant1);
void afficherstock (GtkTreeView *liste);
void alerte ();
void afficheralerte (GtkTreeView *liste);
///////////////////////////////
int rechercher_menu(char nom_fichier[],char jour[],char temps[]);

void ajout_menu(menu m,char nom_fichier[]);

void modifier_menu(char nom_fichier[],menu m);

void supprimer_menu(char nom_fichier[],char jour[],char temps[]);

menu meilleur_menu(char nom_fichier[]);

void afficher_menu(GtkWidget *liste,char texte[]);
int verifier(menu m,char nom_fichier[]);

