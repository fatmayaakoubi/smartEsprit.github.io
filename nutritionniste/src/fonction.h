#include <gtk/gtk.h>


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

/********************************************************************************/

int verif(menu m,char nom_fichier[]);

int rechercher_menu(char nom_fichier[],char jour[],char temps[]);

void ajout_menu(menu m,char nom_fichier[]);

void modifier_menu(char nom_fichier[],menu m);

void supprimer_menu(char nom_fichier[],char jour[],char temps[]);

menu meilleur_menu(char nom_fichier[]);

void afficher_menu(GtkWidget *liste,char texte[]);

/********************************************************************************/

