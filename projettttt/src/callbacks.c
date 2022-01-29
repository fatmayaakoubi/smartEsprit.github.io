#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclam.h"


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *aj, *dashboard;
dashboard=lookup_widget(objet,"dashboard");
aj=lookup_widget(objet,"aj");
aj=create_aj();
gtk_widget_show(aj);


}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod, *dashboard;
dashboard=lookup_widget(objet,"dashboard");
mod=lookup_widget(objet,"mod");
mod=create_mod();
gtk_widget_show(mod);
}


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
afficher(treeview,"reclamations.txt");
}


void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *pInfo;
char str[1000], ch[1000]="";
strcpy(ch,plus_reclame("reclamations.txt"));
sprintf(str,"%s",ch);
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,str);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4, *mod5, *r1, *r2, *r3, *r4, *r5, *r6;
reclam u;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
r1=lookup_widget(objet,"r1");
r2=lookup_widget(objet,"r2");
r3=lookup_widget(objet,"r3");
r4=lookup_widget(objet,"r4");
r5=lookup_widget(objet,"r5");
r6=lookup_widget(objet,"r6");
u.id=atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(mod2)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(mod3)));
strcpy(u.classe,gtk_entry_get_text(GTK_ENTRY(mod4)));
u.service=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r1))?0:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r2))?1:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r3))?2:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r4))?3:gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(r5))?4:5;
strcpy(u.desc,gtk_entry_get_text(GTK_ENTRY(mod5)));
modifier(u,"reclamations.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Réclamation modifiée avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}

}


void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4, *mod5, *r1, *r2, *r3, *r4, *r5, *r6;
reclam p;
char str[100];
char* desc = (char*) malloc(500);
strcpy(desc,"");
int a=0, id;
FILE *f, *file;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
mod5=lookup_widget(objet,"mod5");
r1=lookup_widget(objet,"r1");
r2=lookup_widget(objet,"r2");
r3=lookup_widget(objet,"r3");
r4=lookup_widget(objet,"r4");
r5=lookup_widget(objet,"r5");
r6=lookup_widget(objet,"r6");
id = atoi(gtk_entry_get_text(GTK_ENTRY(mod1)));
f = fopen("reclamations.txt","r");
if(f!=NULL){
while(fscanf(f,"%d %s %s %s %d\n",&(p.id),p.prenom,p.nom,p.classe,&(p.service))!=EOF)
	{
		if(p.id==id){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_entry_set_text(GTK_ENTRY(mod2),p.prenom);
gtk_entry_set_text(GTK_ENTRY(mod3),p.nom);
gtk_entry_set_text(GTK_ENTRY(mod4),p.classe);
p.service==0?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r1),TRUE):p.service==1?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r2),TRUE):p.service==2?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r3),TRUE):p.service==3?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r4),TRUE):p.service==4?gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r5),TRUE):gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(r6),TRUE);
sprintf(str,"%d.txt",id);
file = fopen(str,"a+");
if(file){
while(!feof(file))
fgets(desc,500,file);
fclose(file);
}
memmove(&desc[strlen(desc)-1],&desc[strlen(desc)],strlen(desc) - (strlen(desc)-1));
gtk_entry_set_text(GTK_ENTRY(mod5),desc);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Réclamation introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet,"af");
gtk_widget_destroy(af);
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
afficher(treeview,"reclamations.txt");
}


void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6;
reclam u;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
aj4=lookup_widget(objet,"aj4");
aj5=lookup_widget(objet,"aj5");
aj6=lookup_widget(objet,"aj6");
u.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aj1));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(aj2)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(aj3)));
strcpy(u.classe,gtk_entry_get_text(GTK_ENTRY(aj4)));
u.service=gtk_combo_box_get_active(GTK_COMBO_BOX(aj5));
strcpy(u.desc,gtk_entry_get_text(GTK_ENTRY(aj6)));
ajouter(u,"reclamations.txt");
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint id;
	reclam u;
	char str[100];
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	u.id=id;
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cette réclamation?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer(u,"reclamations.txt");
	sprintf(str,"%d.txt",u.id);
	remove(str);
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
}

