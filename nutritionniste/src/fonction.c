#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fonction.h"

enum
{
	ETEMPS,
	EJOUR,
	EENTREE,
	EPLAT,
	EDESSERT,
	EDECHETS,
	COLUMNS
};

/********************************************************************************/

int verif(menu m,char nom_fichier[])
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
        supprimer_menu("menu.txt",tmp.jour,tmp.temps);
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
	column = gtk_tree_view_column_new_with_attributes("JOUR", renderer, "text",EJOUR, NULL);
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

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

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

/********************************************************************************/

