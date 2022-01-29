#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "reclam.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	ID,
	NOM,
	CLASSE,
	SERVICE,
	DESC,
	COLUMNS
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

void afficher(GtkWidget *liste, char *fname)
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



store=gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
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

