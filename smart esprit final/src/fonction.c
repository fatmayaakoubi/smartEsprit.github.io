#include "fonction.h"
#include "callbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>


void ajouter_etudiant(Etudiant e)
{
    FILE *fp;
    fp = fopen("utilisateurs.txt", "a+");
    if (fp!=NULL)
    {
        
 fprintf(fp,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,e.id,e.sexe,e.compt.username,e.compt.password,e.date_naissance.jour,e.date_naissance.mois,e.date_naissance.annee,e.chambre,e.categorie);
        
    }
    else
    {
        printf("\nEchec lors de l'ouverture du fichier 'utilisateurs.txt'");
    }
fclose(fp);
}

void afficher_etudiant(GtkWidget *liste)
{
Etudiant e;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store = NULL;

FILE *fp;


store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",0,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",3,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",4,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Classe",renderer,"text",5,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",6,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Chambre",renderer,"text",7,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();

	column = gtk_tree_view_column_new_with_attributes(" Categorie",renderer,"text",8,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



}
	store = gtk_list_store_new(9, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("utilisateurs.txt", "r");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("utilisateurs.txt", "a+");	
		while(fscanf(fp,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,&e.id,e.sexe,e.compt.username,e.compt.password,&e.date_naissance.jour,&e.date_naissance.mois,&e.date_naissance.annee,e.chambre,e.categorie)!=EOF)
		{
		sprintf(DATE, "%d/%d/%d", e.date_naissance.jour,e.date_naissance.mois,e.date_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, 0, e.nom, 1, e.prenom, 2, e.sexe, 3, DATE, 4, e.cin, 5, e.gsm, 6, e.id,7,e.chambre,8,e.categorie,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

void supprimer_etudiant(Etudiant e, char cin[])
{

FILE *fp1, *fp2;
    fp1 = fopen("utilisateurs.txt", "r");
    fp2 = fopen("temp.txt", "a+");
    
    if (fp1==NULL)
    {
        printf("\nEchec lors de l'ouverture du fichier 'utilisateurs.txt'");
    }
    else
    {
        while(fscanf(fp1,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,&e.id,e.sexe,e.compt.username,e.compt.password,&e.date_naissance.jour,&e.date_naissance.mois,&e.date_naissance.annee,e.chambre,e.categorie)!=EOF)
		
        {
            if (strcmp(cin, e.cin)!=0)
               fprintf(fp2,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,e.id,e.sexe,e.compt.username,e.compt.password,e.date_naissance.jour,e.date_naissance.mois,e.date_naissance.annee,e.chambre,e.categorie);

        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("utilisateurs.txt");
    rename("temp.txt", "utilisateurs.txt");
}

int id_supprimer_etudiant(Etudiant e, char cin[])
{
int id;
FILE *fp1;
    fp1 = fopen("utilisateurs.txt", "r");

    
    if (fp1==NULL)
    {
        printf("\nEchec lors de l'ouverture du fichier 'utilisateurs.bin'");
    }
    else
    {
        while(fscanf(fp1,"%s %s %s %s %d %s %s %s  %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,&e.id,e.sexe,e.compt.username,e.compt.password,&e.date_naissance.jour,&e.date_naissance.mois,&e.date_naissance.annee,e.chambre,e.categorie)!=EOF)
		
        {
            if (strcmp(cin, e.cin)==0)
                id=e.id;	
        }
    }
    fclose(fp1);
    return id;
}


void chercher_etudiant(Etudiant e, char cin[20], int *ok)
{
FILE *fp ,*fp1;
fp = fopen("utilisateurs.txt", "r");
fp1 = fopen("temp1.txt", "w");
*ok=0;

if(fp==NULL)
{
return;
}
else
{
while(fscanf(fp,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,&e.id,e.sexe,e.compt.username,e.compt.password,&e.date_naissance.jour,&e.date_naissance.mois,&e.date_naissance.annee,e.chambre,e.categorie)!=EOF)
	
{
	if (strcmp(cin, e.cin)==0)
	{
		fprintf(fp1,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,e.id,e.sexe,e.compt.username,e.compt.password,e.date_naissance.jour,e.date_naissance.mois,e.date_naissance.annee,e.chambre,e.categorie);

		*ok=1; // ok prends la valeur 1 si cin existe *********** sinon ok = 0
	}

}
}
fclose(fp);
fclose(fp1);
}

void afficher_etudiantModif(GtkWidget *liste)
{
Etudiant e;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store = NULL;

FILE *fp;



store = gtk_tree_view_get_model(liste);

if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",0,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",3,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",4,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Classe",renderer,"text",5,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",6,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Chambre",renderer,"text",7,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Categorie",renderer,"text",8,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(8, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("temp1.txt", "r");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("temp1.txt", "a+");	
		while(fscanf(fp,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,&e.id,e.sexe,e.compt.username,e.compt.password,&e.date_naissance.jour,&e.date_naissance.mois,&e.date_naissance.annee,e.chambre,e.categorie)!=EOF)
	{
		sprintf(DATE, "%d/%d/%d", e.date_naissance.jour,e.date_naissance.mois,e.date_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, 0, e.nom, 1, e.prenom, 2, e.sexe, 3, DATE, 4, e.cin, 5, e.gsm, 6, e.id,7,e.chambre,8,e.categorie,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

void modifier_etudiant(Etudiant h, char cin[])
{
FILE *fp1, *fp2;
Etudiant e;
fp1 = fopen("utilisateurs.txt", "r");
fp2 = fopen("tmpp.txt","a+");
if (fp1==NULL)
{
	return ;
}
else
{
	while(fscanf(fp1,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,&e.id,e.sexe,e.compt.username,e.compt.password,&e.date_naissance.jour,&e.date_naissance.mois,&e.date_naissance.annee,e.chambre,e.categorie)!=EOF)
	
	{
		if (strcmp(e.cin,cin)!=0)
			fprintf(fp2,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,e.id,e.sexe,e.compt.username,e.compt.password,e.date_naissance.jour,e.date_naissance.mois,e.date_naissance.annee,e.chambre,e.categorie);

		else
		{
			fprintf(fp2,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",h.prenom,h.nom,h.gsm,h.cin,h.id,h.sexe,h.compt.username,h.compt.password,h.date_naissance.jour,h.date_naissance.mois,h.date_naissance.annee,h.chambre,e.categorie);
						
		}
	}
}
fclose(fp1);
fclose(fp2);
remove("utilisateurs.txt");
rename("tmpp.txt", "utilisateurs.txt");

}

void afficher_etudiantSupp(GtkWidget *liste)
{

Etudiant e;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store = NULL;

FILE *fp;



store = gtk_tree_view_get_model(liste);

if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",0,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Sexe",renderer,"text",2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date de Naissance",renderer,"text",3,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new(); 
	column = gtk_tree_view_column_new_with_attributes(" CIN",renderer,"text",4,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Classe",renderer,"text",5,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Identifiant",renderer,"text",6,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Chambre",renderer,"text",7,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Categorie",renderer,"text",8,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(8, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("temp1.txt", "r");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("temp1.txt", "a+");	
		while(fscanf(fp,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,&e.id,e.sexe,e.compt.username,e.compt.password,&e.date_naissance.jour,&e.date_naissance.mois,&e.date_naissance.annee,e.chambre,e.categorie)!=EOF)
	
		{
		sprintf(DATE, "%d/%d/%d", e.date_naissance.jour,e.date_naissance.mois,e.date_naissance.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, 0, e.nom, 1, e.prenom, 2, e.sexe, 3, DATE, 4, e.cin, 5, e.gsm, 6, e.id,7,e.chambre,8,e.categorie,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}


////////////////////////
int nbre (int calcul[],char txt[])
{
 	FILE *fp=NULL;
	Etudiant e;
    	int s1=0,s2=0,s3=0,s4=0,s5=0,s=0;
    	fp=fopen("utilisateurs.txt","r");
  if(fp!=NULL)
  {
        
          while(fscanf(fp,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,&e.id,e.sexe,e.compt.username,e.compt.password,&e.date_naissance.jour,&e.date_naissance.mois,&e.date_naissance.annee,e.chambre,e.categorie)!=EOF)
        	{ 		if((calcul[0]==1) &&(strcmp(e.gsm,"1")==0))

                                 {
                                  s1++;

                                 }

  				if((calcul[1]==1)&&(strcmp(e.gsm,"2")==0))
                                {
                                 s2++;

                                }

 				if((calcul[2]==1)&&(strcmp(e.gsm,"3")==0))
                                {
              			 s3++;

            			}

 				if((calcul[3]==1)&&(strcmp(e.gsm,"4")==0))
            			{
              			s4++;

            			}

 				if((calcul[4]==1)&&(strcmp(e.gsm,"5")==0))
            			{
              			s5++;

            			}
       
       
    		}
s=s1+s2+s3+s4+s5;
 }
    fclose(fp);
return s;
}




GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;


int i;
enum
{
	ETYPE,
	EID,
	EMARQUE,
	EVALEUR,
	EJOUR,
	EHEURE,
	COLUMNS,
};



////////////////////////////////////////////////////////
void ajouter_capteur(capteur c)
{
FILE *f;
f=fopen("capteur.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s \n" ,c.type,c.id,c.marque,c.valeur,c.jour,c.heure);
fclose(f);
}
}
//////////////////////////////////////
int exist_capteur(char*id){
FILE*f=NULL;
 capteur c;
f=fopen("capteur.txt","r");
while(fscanf(f,"%s %s %s %s %s %s \n",c.type,c.id,c.marque,c.valeur,c.jour,c.heure)!=EOF){
if(strcmp(c.id,id)==0)return 1;
}
fclose(f);
return 0;
}
/////////////////////////////////////////////////////
void afficher_capteur(GtkWidget *liste , char fichier[20])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char type[30];
	char id[30];
	char marque[30];
	char valeur[30];
	char jour[30];
	char heure[30];
	store=NULL;

	FILE *f;
	
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("marque", renderer, "text",EMARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("valeur", renderer, "text",EVALEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("heure", renderer, "text",EHEURE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen(fichier,"r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen(fichier, "a+");
		while(fscanf(f,"%s %s %s %s %s %s \n" ,type,id,marque,valeur,jour,heure)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter, ETYPE, type, EID, id, EMARQUE, marque, EVALEUR, valeur, EJOUR , jour, EHEURE, heure, -1);
		}
		close(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}
////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
void supprimer_capteur(char numero[100]){
FILE*f=NULL;
FILE*f1=NULL;
capteur m ;
f=fopen("capteur.txt","r");

f1=fopen("ancien.txt","w");
while(fscanf(f,"%s %s %s %s %s %s\n",m.type,m.id,m.marque,m.valeur,m.jour,m.heure)!=EOF){
if(strcmp(numero,m.id)!=0)
fprintf(f1,"%s %s %s %s %s %s\n",m.type,m.id,m.marque,m.valeur,m.jour,m.heure);
}
fclose(f);
fclose(f1);
remove("capteur.txt");
rename("ancien.txt","capteur.txt");

}
///////////////////////////////////////////////////////////////////////////////////
int ChercherCapteur(GtkWidget* treeview1,char*l,char*type)
{
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
capteur c;
int nb=0, j;

        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
					G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s \n",c.id,c.type,c.marque,c.valeur,c.jour,c.heure)!=EOF)
        {
	if( strcmp(type,c.type)==0){ nb++;
	GtkTreeIter pIter;
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.id,
                            1,c.type,
                            2,c.marque,
                            3,c.valeur,
                            4,c.jour,
				5,c.heure,
                            -1);}
}
        fclose(f);

	/* Creation de la 1ere colonne */
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("id",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("marque",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeur",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("jour",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("heure",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}
////////////////////////////////////////////////////////////////////////////////
void modifier_capteur(capteur c,char numero [30]){

supprimer_capteur(numero);
ajouter_capteur(c);


}
///////////////////////////////////////////////////////
void fichierRef() {

FILE*f=NULL;
FILE*f1=NULL;
capteur c;
f=fopen("capteur.txt","r");
f1=fopen("reference.txt","w+");
while (fscanf(f,"%s %s %s %s %s %s \n" ,c.type,c.id,c.marque,c.valeur,c.jour,c.heure)!=EOF)
{

fprintf(f1,"%s \n",c.id);

}

fclose(f);
fclose(f1);

}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficherCapteur(GtkWidget* treeview1,char*l){

capteur c;


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s \n" ,c.type,c.id,c.marque,c.valeur,c.jour,c.heure)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.type,
                            1,c.id,
                            2,c.marque,
                            3,c.valeur,
                            4,c.jour,
                            5,c.heure,
                            -1);}
        fclose(f);


if(i==0)
	{



        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MARQUE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("VALEUR",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("HEURE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	i++;
}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );





}

///////////////////////////////////////////////////////////////////////////////
void capteur_def(capteur c)
{
    
    FILE *f=NULL;
    FILE *f1=NULL;
    f=fopen("temperature.txt","r");
    f1=fopen("capteur2.txt","w");
     while(fscanf(f,"%s %s %s %s \n" ,c.jour,c.heure,c.id,c.valeur)!=EOF)
     {
        if (atoi(c.valeur)<10 || atoi(c.valeur)>30)
        fprintf(f1,"%s %s %s %s %s %s \n" ,"temperature",c.id,"--" ,c.valeur,c.jour,c.heure);
     }
     fclose(f);
}

void liste_alarme(capteur c)
{
    FILE *f1=NULL;
    FILE *f=NULL;
    FILE *f2=NULL;
    f=fopen("fumee.txt","r");
    f2=fopen("mouvement.txt","r");
    f1=fopen("capteur1.txt","w");
    while(fscanf(f,"%s %s %s %s \n" ,c.jour,c.heure,c.id,c.valeur)!=EOF)
    {
        if(strcmp(c.valeur,"1")==0)
        fprintf(f1,"%s %s %s %s %s %s \n" ,"fumee",c.id,"--" ,c.valeur,c.jour,c.heure);
    }
    while(fscanf(f2,"%s %s %s %s \n" ,c.jour,c.heure,c.id,c.valeur)!=EOF)
    {
        if(strcmp(c.valeur,"1")==0)
        fprintf(f1,"%s %s %s %s %s %s \n" ,"mouvement",c.id,"--" ,c.valeur,c.jour,c.heure);
    }
    fclose(f);
    fclose(f2);
    fclose(f1);
}
void etage_pannes(capteur c)
{
   FILE *f=NULL;
    FILE *f1=NULL;
    f=fopen("debit.txt","r");
    f1=fopen("capteur3.txt","w");
     while(fscanf(f,"%s %s %s %s \n" ,c.jour,c.heure,c.id,c.valeur)!=EOF)
     {
        if (atoi(c.valeur)>30)
        fprintf(f1,"%s %s %s %s %s %s \n" ,"debit",c.id,"--" ,c.valeur,c.jour,c.heure);
     }
     fclose(f);
}

int verif(char user[], char pw[])
{
int trouve = -1;
char nom[20], prenom[20], username[20], password[20], role[20];

FILE *fp=NULL;

fp = fopen("admin.txt", "r");

if (fp==NULL)
{
printf("Echec lors de l'ouverture du fichier 'admin.txt'");
}
else
{
while(fscanf(fp, "%s %s %s %s %s", nom, prenom, username, password, role)!=EOF)
{
if ((strcmp(user, username)==0) && (strcmp(pw, password)==0))
trouve = 1;
}
fclose(fp);
}

return (trouve);


}


enum
{
	ENOM,
	EPRENOM,
	ECIN,
	EID1,
	EDDN,
	ESEXE,
	EPOSTE,
	COLUMNS1,
};

void ajouter_personne (char utilisateur[],personne p)
{
	FILE *f=NULL;
	f=fopen(utilisateur,"a+");
        fprintf(f,"%s %s %s %s %d %d %d %s %s\n",p.nom,p.prenom,p.numero_de_cin,p.identifiant,p.d.jour,p.d.mois,p.d.annee,p.sexe,p.poste);
        fclose(f);
}
///////////////////////////////


void afficher(GtkWidget *liste,char texte[])
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[30];
char prenom[30];
char numero_cin[30];
char identifiant[30];
char date_naissance[30];
char sexe[30];
char poste[30];
store=NULL;
FILE *f;
date d;personne p;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("numero_cin", renderer, "text",ECIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",EID1, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("date_naissance", renderer, "text",EDDN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("poste", renderer, "text",EPOSTE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}

store=gtk_list_store_new (COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen(texte,"r");

if(f==NULL)
{
return;
}
else
{
f=fopen("users.txt", "r");
while(fscanf(f," %s %s %s %s %d %d %d %s %s",nom,prenom,numero_cin,identifiant,&p.d.jour,&p.d.mois,&p.d.annee,sexe,poste)!=EOF)
{
 sprintf(date_naissance,"%d/%d/%d",p.d.jour,p.d.mois,p.d.annee);

gtk_list_store_append (store, &iter);
gtk_list_store_set (store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,numero_cin,EID,identifiant,EDDN,date_naissance,ESEXE,sexe,EPOSTE,poste,-1);
}

fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
int rechercher_personne(char utilisateur[],char identifiant[])
{
    FILE *f=NULL;
    char ch1[30],ch2[30],ch3[50],ch4[50],s[20],c[20] ;
    int j,m,a,trouve=0,id;
    f=fopen("users.txt","r");
    if(f != NULL)
    {
        while(fscanf(f," %s %s %s %s %d %d %d %s %s ",ch1,ch2,c,ch4,&j,&m,&a,s,ch3)!=EOF)
        if(strcmp(ch4,identifiant)==0)
        {
	   trouve=1;
        }
    }
    fclose(f);
    return trouve;
}
void modifier_personne(personne p1)
{
    FILE *f=NULL;
    FILE *f1=NULL;
    personne p;
  
    
    f=fopen("users.txt","r");
    f1=fopen("temp.txt","w");
   
        while(fscanf(f,"%s %s %s %s %d %d %d %s %s",p.nom,p.prenom,p.numero_de_cin,p.identifiant,&p.d.jour,&p.d.mois,&p.d.annee,p.sexe,p.poste)!=EOF)
        {
            if(strcmp(p1.identifiant,p.identifiant)!=0)
            {
            fprintf(f,"%s %s %s %s %d %d %d %s %s\n",p.nom,p.prenom,p.numero_de_cin,p.identifiant,p.d.jour,p.d.mois,p.d.annee,p.sexe,p.poste);
            }
            else
            {
            
            fprintf(f1,"%s %s %s %s %d %d %d %s %s\n",p1.nom,p1.prenom,p1.numero_de_cin,p1.identifiant,p1.d.jour,p1.d.mois,p1.d.annee,p1.sexe,p1.poste);
            }
        }
    
    fclose(f);
    fclose(f1);
    remove("users.txt");
    rename("temp.txt","users.txt");
}
void supprimer_personne(char identifiant[50])
{
    FILE *f=NULL;
    FILE *fs=NULL;
    personne p;

    f=fopen("users.txt","r");
    fs=fopen("temp.txt","w");
        while(fscanf(f,"%s %s %s %s %d %d %d %s %s",p.nom,p.prenom,p.numero_de_cin,p.identifiant,&p.d.jour,&p.d.mois,&p.d.annee,p.sexe,p.poste)!=EOF)
        {
            if(strcmp(identifiant,p.identifiant)!=0)
            {
            fprintf(fs,"%s %s %s %s %d %d %d %s %s\n",p.nom,p.prenom,p.numero_de_cin,p.identifiant,p.d.jour,p.d.mois,p.d.annee,p.sexe,p.poste);
            }
    }
    fclose(f);
    fclose(fs);
    remove("users.txt");
    rename("temp.txt","users.txt");

}


////////////////////////////////////////////////


enum
{
	ID,
	NOM,
	CLASSE,
	SERVICE,
	DESC,
	COLUMNS88
};

void ajouter(reclam u, char *fname){
GtkWidget *pQuestion, *pInfo;
char str[100];
FILE *f, *file;
int b=0;
gpointer user_data;
reclam p;
f=fopen(fname,"a+");
if(f)
{	while(fscanf(f,"%d %s %s %s %d\n",&(p.id),p.prenom,p.nom,p.classe,&(p.service))!=EOF)
	{	
		if(p.id==u.id)
		b++;
	}
	if(b==0){
	fprintf(f,"%d %s %s %s %d\n",u.id,u.prenom,u.nom,u.classe,u.service);
	sprintf(str,"%d.txt",u.id);
	file=fopen(str,"a+");
	if(file){
	fprintf(file,"%s\n",u.desc);
	fclose(file);
	}
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Réclamation ajoutée avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	}
	if(b!=0){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"ID déja existant !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	fclose(f);
}
}

void modifier(reclam u, char *fname){
reclam p;
int a=0;
char str[100];
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g, *file;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%d %s %s %s %d\n",&(p.id),p.prenom,p.nom,p.classe,&(p.service))!=EOF)
	{
		if(p.id!=u.id)
			fprintf(g,"%d %s %s %s %d\n",p.id,p.prenom,p.nom,p.classe,p.service);
		else{
			fprintf(g,"%d %s %s %s %d\n",p.id,u.prenom,u.nom,u.classe,u.service);
			a=1;
		}
	}
	if(a==1){
	sprintf(str,"%d.txt",u.id);
	remove(str);
	file=fopen(str,"a+");
	if(file){
	fprintf(file,"%s\n",u.desc);
	fclose(file);
	}
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Réclamation modifiée avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

void afficherrec(GtkWidget *liste, char *fname)
{
reclam p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar nom[50], service [50], desc[500], str[100];
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID Réclamation", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Prénom et nom", renderer,"text",NOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Classe", renderer,"text",CLASSE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Service réclamé", renderer,"text",SERVICE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Description", renderer,"text",DESC, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_resizable(column,TRUE);
	gtk_tree_view_column_set_expand(column,TRUE);



store=gtk_list_store_new(COLUMNS88, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen(fname,"r");
if(f!=NULL)

{ f = fopen(fname,"a+");
		while(fscanf(f,"%d %s %s %s %d\n",&(p.id),p.prenom,p.nom,p.classe,&(p.service))!=EOF)
	{
sprintf(nom,"%s %s",p.prenom,p.nom);
sprintf(service,p.service==0?"Menu":p.service==1?"Salle de repas":p.service==2?"Sanitaire":p.service==3?"Electricité":p.service==4?"Connectivité":"Salle TV");
sprintf(str,"%d.txt",p.id);
FILE *file = fopen(str,"r");
if(file){
while(!feof(file))
fgets(desc,500,file);
fclose(file);
}
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,NOM,nom,CLASSE,p.classe,SERVICE,service,DESC,desc,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}

void supprimer(reclam u, char *fname)
{
reclam p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%d %s %s %s %d\n",&(p.id),p.prenom,p.nom,p.classe,&(p.service))!=EOF)
	{
		if(p.id!=u.id)
			fprintf(g,"%d %s %s %s %d\n",p.id,p.prenom,p.nom,p.classe,p.service);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Réclamation supprimée avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

char* plus_reclame(char *fname){
    reclam p;
    int a=0, b=0, c=0, d=0, e=0, f=0;
    char* ch = (char*) malloc(1000);
    char str[50];
    FILE *file = fopen(fname,"r");
    if(file){
        while(fscanf(file,"%d %s %s %s %d\n",&(p.id),p.prenom,p.nom,p.classe,&(p.service))!=EOF){
			switch(p.service){
			case 0:
			a++;
			break;
			case 1:
			b++;
			break;
			case 2:
			c++;
			break;
			case 3:
			d++;
			break;
			case 4:
			e++;
			break;
			case 5:
			f++;
			break;
			}
        }
        fclose(file);
    }
    sprintf(str,a>b&&a>c&&a>d&&a>e&&a>f?"Menu":b>c&&b>d&&b>e&&b>f?"Salle de repas":c>d&&c>e&&c>f?"Sanitaire":d>e&&d>f?"Electricité":e>f?"Connectivité":"Salle TV");
    sprintf(ch,"Le service le plus réclamé est : %s",str);
return ch;
    }

////////////////////////////////////////////////////////////
void ajouterstock (char id[],char type[],int quant)
{
char id1[50];
char type1[50];
int quant1;
int v=0;
char empty[50]="\0" ;
FILE *f;
f=fopen("/home/wassim/Bureau/wassimpr/src/prod.txt","a+");
if(f!=NULL)

{while(fscanf(f,"%s %s %d \n",id1,type1,&quant1)!=EOF)
          {
               if (strcmp(id,id1)==0) 
                   {
                       v=1 ;
                   }  
               if ( (strcmp(id,empty)==0) || (strcmp(type,empty)==0)) 
                   {
                      v=1 ;
                   }
          }
if(v==0)
{fprintf(f,"%s %s %d \n",id,type,quant);
fclose(f);}
}
}


void supprimerstock(char id1[])

{
FILE *f;
FILE *f1;

int r;


char id[50]; 
int quant;
char type[50]; 



f=fopen("prod.txt","r");
f1=fopen("prod1.txt","w");
if (f!=NULL){
    if(f1!=NULL){
while(fscanf(f,"%s %s %d \n",id,type,&quant)!=EOF ) {
    if(strcmp(id1,id)!=0)  
    {
        fprintf(f1,"%s %s %d \n",id,type,quant);
        r=1;
    }
}
    }
    fclose(f1);
}

fclose(f);
if (r){
	remove ("prod.txt");
	rename ("prod1.txt","prod.txt");
	}

}




void modifierstock(char id1[],int quant1)
{
FILE *f;
FILE *f1;
 
int r;
char id[50]; 
int quant;
char type[50]; 


f=fopen("prod.txt","r");
f1=fopen("prod1.txt","w");
if (f!=NULL)
{
    if(f1!=NULL)
     {
while(fscanf(f,"%s %s %d \n",id,type,&quant)!=EOF  ) 
{
    if(strcmp(id1,id)==0)  
            {
        fprintf(f1,"%s %s %d \n",id,type,quant1);
            }
     else 
          {fprintf(f1,"%s %s %d \n",id,type,quant);} 
}
}
}
fclose(f1);
fclose(f);

	remove ("prod.txt");
	rename ("prod1.txt","prod.txt");
	
}

void alerte ()
{char id[50];
char type[50];
int quant;
FILE *f;
FILE *f1;
f=fopen("prod.txt","r");
f1=fopen("alerte.txt","w");
if(f!=NULL)
{if(f1!=NULL)
{while(fscanf(f,"%s %s %d \n",id,type,&quant)!=EOF) 
{
    if(quant==0)
            {
        fprintf(f1,"%s %s %d \n",id,type,quant);
            }

}
fclose(f1);
fclose(f);
}
}
}




enum 
{
ID11 ,
TYPE,
QUANT, 
COLUMNS11
}; 


void afficherstock (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char id[50]; 
int quant;
char type[50]; 
store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("id",render,"text",ID11,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("type",render,"text",TYPE,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("quant",render,"text",QUANT,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNS11,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT) ; 

f=fopen("prod.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("prod.txt","a+") ;
 while(fscanf(f,"%s %s %d \n",id,type,&quant)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,ID,id,TYPE,type,QUANT,quant,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}



enum 
{
ID2 ,
TYPE2,
QUANT2, 
COLUMNS2
}; 


void afficheralerte (GtkTreeView *liste)
{
GtkCellRenderer *render ;
GtkTreeViewColumn *column ; 
GtkTreeIter iter ; 

GtkListStore *store ;

char id[50]; 
int quant;
char type[50]; 
store=NULL ; 
FILE* f ; 

store=gtk_tree_view_get_model(liste) ; 
if (store==NULL) 
{
render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("id",render,"text",ID2,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 


render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("type",render,"text",TYPE2,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 

render=gtk_cell_renderer_text_new () ; 
column =gtk_tree_view_column_new_with_attributes("quant",render,"text",QUANT2,NULL) ; 
gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 



store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT) ; 

f=fopen("alerte.txt","r") ; 
if (f==NULL) 
{
return ; 
}
else 
{
f=fopen("alerte.txt","a+") ;
 while(fscanf(f,"%s %s %d \n",id,type,&quant)!=EOF) 
{
gtk_list_store_append (store,&iter) ; 
gtk_list_store_set (store,&iter,ID2,id,TYPE2,type,QUANT2,quant,-1) ; 
}
fclose(f) ; }
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)); 
g_object_unref (store) ; 

}
}
//////////////////////////////////////
enum
{
	ETEMPS,
	EJOUR11,
	EENTREE,
	EPLAT,
	EDESSERT,
	EDECHETS,
	COLUMNS9
};

int verifier(menu m,char nom_fichier[])
{
	FILE *f=NULL;
        char cht[20],chj[20],che[20],chp[20],chd[20];
        int d,trouve=1;

	f=fopen(nom_fichier,"r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d",cht,chj,che,chp,chd,&d)!=EOF)
		{
			if ((strcmp(m.temps,cht)==0) && (strcmp(m.jour,chj)) && (strcmp(m.menu.entree,che)==0) && (strcmp(m.menu.plat_principale,chp)==0) && (strcmp(m.menu.dessert,chd)==0) && (m.dechets==d))
			{
			trouve=0;
			}
		}
	}
	fclose(f);
	return (trouve);
}

/********************************************************************************/

int rechercher_menu(char nom_fichier[],char jour[],char temps[])
{
	FILE *f=NULL;
        menu m;
        char cht[20],chj[20],che[20],chp[20],chd[20];
        int d,trouve=0;
        
	f=fopen(nom_fichier,"r");
        if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d \n",cht,chj,che,chp,chd,&d)!=EOF)
		{
			if ((strcmp(chj,jour)==0) && (strcmp(cht,temps)==0))
			{
			trouve=1;
			}
		}
	}
	fclose(f);
	return (trouve);       
}

/********************************************************************************/

void ajout_menu(menu m,char nom_fichier[])
{
	FILE *f;
	f=fopen(nom_fichier,"a");
	if(f != NULL)
	{
	fprintf(f,"%s %s %s %s %s %d \n", m.temps, m.jour, m.menu.entree, m.menu.plat_principale, m.menu.dessert, m.dechets);
	fclose(f);
	}
}

/********************************************************************************/

void modifier_menu(char nom_fichier[],menu m)
{

	ajout_menu(m,"menu.txt");
        supprimer_menu("menu.txt",m.jour,m.temps);
}



/********************************************************************************/

void supprimer_menu(char nom_fichier[],char jour[],char temps[])
{
        FILE *f=NULL;
        FILE *s=NULL;
        char cht[20],chj[20],che[20],chp[20],chd[20];
        int d,x;
	menu p;

	f=fopen(nom_fichier,"r");
	s=fopen("sup.txt","a+");
	if(f!=NULL && s!=NULL)
	{
	while(fscanf(f,"%s %s %s %s %s %d \n",p.temps,p.jour,p.menu.entree,p.menu.plat_principale,p.menu.dessert,&p.dechets)!=EOF)
	{
	if ((strcmp(p.temps,temps)!=0) || (strcmp(p.jour,jour)!=0))
	{
	fprintf(s,"%s %s %s %s %s %d \n",p.temps,p.jour,p.menu.entree,p.menu.plat_principale,p.menu.dessert,p.dechets);
	x=1;
	}
	}
	}
	fclose(f);
	fclose(s);
	remove(nom_fichier);
	rename("sup.txt","menu.txt");
	return x;
}

/********************************************************************************/

void afficher_menu(GtkWidget *liste,char texte[])
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char cht[20],chj[20],che[20],chp[20],chd[20],chdes[20];
	int d;
	menu m;

	FILE *f;

	store = gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("TEMPS", renderer, "text",ETEMPS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("JOUR", renderer, "text",EJOUR11, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("ENTREE", renderer, "text",EENTREE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("PLAT", renderer, "text",EPLAT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("DESSERT", renderer, "text",EDESSERT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("DECHETS", renderer, "text",EDECHETS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	store=gtk_list_store_new (COLUMNS9, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen(texte,"r");

	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("menu.txt", "a+");
		while(fscanf(f," %s %s %s %s %s %d ",cht,chj,che,chp,chd,&d)!=EOF)
		{
		sprintf(chdes,"%d",d);
		gtk_list_store_append (store, &iter);
		gtk_list_store_set (store,&iter,ETEMPS,cht,EJOUR,chj,EENTREE,che,EPLAT,chp,EDESSERT,chd,EDECHETS,chdes,-1);
		}
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
	gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}

/********************************************************************************/

menu meilleur_menu(char nom_fichier[])
{
	FILE *f=NULL;
	menu m;
	char cht[20],chj[20],che[20],chp[20],chd[20],jour[20],temps[20];
	int d,cmp=100000;


	f=fopen(nom_fichier,"r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d",cht,chj,che,chp,chd,&d)!=EOF)
		{
			if(cmp>d)
			{
			cmp=d;
			strcpy(temps,cht);
			strcpy(jour,chj);
			}
		}
	}
	fclose(f);
	f=fopen(nom_fichier,"r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d",cht,chj,che,chp,chd,&d)!=EOF)
			{
			if((strcmp(chj,jour)==0) && (strcmp(cht,temps)==0))
				{
				strcpy(m.temps,cht);
				strcpy(m.jour,chj);
				strcpy(m.menu.entree,che);
				strcpy(m.menu.plat_principale,chp);
				strcpy(m.menu.dessert,chd);
				m.dechets=d;
				}

			}
	}
	fclose(f);
	return m;
}









