#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"


int t=1,CA=1,CM=1;
int choix[2]={0,0};
menu tmp;

///////////////////////////////////////////////////////////////////////

void
on_button_connection_fn_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *login;
	GtkWidget *id;
	GtkWidget *Gestionf_fn;
	GtkWidget *authentification_fn;
	GtkWidget *treeview_fn;
	char log[20];
	char ident[20];

	login = lookup_widget (button, "entry_login_fn");
	strcpy(log, gtk_entry_get_text(GTK_ENTRY(login)));

	id = lookup_widget (button, "entry_id_fn");
	strcpy(ident, gtk_entry_get_text(GTK_ENTRY(id)));

	if((strcmp(log,"fatma")==0) && (strcmp(ident,"nouioui")==0))
	{
		Gestionf_fn = lookup_widget(button,"Gestionf_fn");
		authentification_fn = lookup_widget(button,"authentification_fn");
		Gestionf_fn = create_Gestionf_fn();
		gtk_widget_show (Gestionf_fn);
		treeview_fn = lookup_widget(Gestionf_fn,"treeview_fn");
		afficher_menu(treeview_fn,"menu.txt");
		gtk_widget_destroy(authentification_fn);
	}
}

///////////////////////////////////////////////////////////////////////

void
on_button_ajouter_fn_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestionf_fn;
	GtkWidget *Ajout_fn;

	Gestionf_fn = lookup_widget(button,"Gestionf_fn");
	Ajout_fn = create_Ajout_fn ();
	gtk_widget_show (Ajout_fn);
	gtk_widget_destroy(Gestionf_fn);
}

////////////////////////////////////////////////////////////////////////

void
on_button_modifier_fn_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestionf_fn;
	GtkWidget *Rechercher_fn;

	Gestionf_fn = lookup_widget(button,"Gestionf_fn");
	Rechercher_fn = create_Rechercher_fn ();
	gtk_widget_show (Rechercher_fn);
	gtk_widget_destroy(Gestionf_fn); 
}

////////////////////////////////////////////////////////////////////////

void
on_button_supprimer_fn_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestionf_fn;
	GtkWidget *Supprimer_fn;

	Gestionf_fn = lookup_widget(button,"Gestionf_fn");
	Supprimer_fn = create_Supprimer_fn ();
	gtk_widget_show (Supprimer_fn);
	gtk_widget_hide(Gestionf_fn);
}

////////////////////////////////////////////////////////////////////////

void
on_button_rafraichir_fn_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview_fn;
	GtkWidget *Gestionf_fn;

	Gestionf_fn = lookup_widget(button,"Gestionf_fn");
	gtk_widget_destroy(Gestionf_fn);
	Gestionf_fn = lookup_widget(button,"Gestionf_fn");
	Gestionf_fn = create_Gestionf_fn();
	gtk_widget_show(Gestionf_fn);
	treeview_fn = lookup_widget(Gestionf_fn,"treeview_fn");
	afficher_menu(treeview_fn,"menu.txt");
}

////////////////////////////////////////////////////////////////////////

void
on_button_meilleur_fn_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *output;
        char winner[200],che[20],chp[20],chd[20],msg[200];
	menu m;
	int x;

	output = lookup_widget(button,"label_affichage_meilleur_menu"); 
	m=meilleur_menu("menu.txt");
	x=rechercher_menu("menu.txt",m.jour,m.temps);
	if(x==1)
	{
	strcpy(che,m.menu.entree);
	strcpy(chp,m.menu.plat_principale);
	strcpy(chd,m.menu.dessert);

	strcat(che,"/");
	strcpy(winner,che);
	strcat(chp,"/");
	strcat(winner,chp);
	strcat(winner,chd);
	}
	else
	{
	strcpy(winner," ********* ");
	}
	strcpy(msg,"Le meilleur menu est = ");
	strcat(msg,winner);
	gtk_label_set_text(GTK_LABEL(output),msg);

}

////////////////////////////////////////////////////////////////////////

void
on_treeview_fn_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* temps;
	gchar* jour;
	gchar* entree;
	gchar* plat;
	gchar* dessert ;
	gchar* dechets;
	GtkWidget *pInfo;
	menu m;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&temps,1,&jour,2,&entree,3,&plat,4,&dessert,5,&dechets,-1);

	strcpy(m.temps,temps);
	strcpy(m.jour,jour);
	
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cet utilisateur ?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	{gtk_widget_destroy(pInfo);
	supprimer_menu("menu.txt",m.jour,m.temps);
	break;}
	case GTK_RESPONSE_NO:
	{gtk_widget_destroy(pInfo);
	break;}
	}
	}

}

////////////////////////////////////////////////////////////////////////

void
on_button_home1_fn_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestionf_fn;
	GtkWidget *Ajout_fn;
	GtkWidget *treeview_fn;

	Ajout_fn = lookup_widget(button,"Ajout_fn");
	Gestionf_fn = lookup_widget(button,"Gestionf_fn");
	Gestionf_fn = create_Gestionf_fn ();
	gtk_widget_show (Gestionf_fn);
	gtk_widget_destroy(Ajout_fn);
	treeview_fn = lookup_widget(Gestionf_fn,"treeview_fn");
	afficher_menu(treeview_fn,"menu.txt");
}

////////////////////////////////////////////////////////////////////////

void
on_checkbutton_dejeuner_ajouter_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	CA = 1;
}

////////////////////////////////////////////////////////////////////////

void
on_checkbutton_diner_ajouter_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	CA = 2;
}

////////////////////////////////////////////////////////////////////////

void
on_button_enregister_fn_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Ajout_fn;
	GtkWidget *Gestionf_fn;
	GtkWidget *temps;
	GtkWidget *jour;
	GtkWidget *entree;
	GtkWidget *plat;
	GtkWidget *dessert;
	GtkWidget *dechets;
	GtkWidget *treeview;
	GtkWidget *combobox_jour_ajouter_fn;
	menu m;
	int x;

	if(CA==1)
	strcpy(m.temps,"dejeuner");
	if(CA==2)
	strcpy(m.temps,"diner");

	jour = lookup_widget(objet,"combobox_jour_ajouter_fn");
	strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));

	entree = lookup_widget (objet, "entry_entree_ajouter_fn");
	strcpy(m.menu.entree, gtk_entry_get_text(GTK_ENTRY(entree)));

	plat = lookup_widget (objet, "entry_plat_principal_ajouter_fn");
	strcpy(m.menu.plat_principale, gtk_entry_get_text(GTK_ENTRY(plat)));

	dessert = lookup_widget (objet, "entry_dessert_ajouter_fn");
	strcpy(m.menu.dessert, gtk_entry_get_text(GTK_ENTRY(dessert)));

	dechets = lookup_widget(objet, "spinbutton_dechets_ajouter_fn");
	m.dechets = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (dechets));

	x=verif(m,"menu.txt");

	if(x==1)
	{
	ajout_menu(m,"menu.txt");
	}
}

////////////////////////////////////////////////////////////////////////

void
on_button_home2_fn_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestionf_fn;
	GtkWidget *Modifier_fn;
	GtkWidget *treeview_fn;

	Modifier_fn = lookup_widget(button,"Modifier_fn");
	Gestionf_fn = lookup_widget(button,"Gestionf_fn");
	Gestionf_fn = create_Gestionf_fn ();
	gtk_widget_show (Gestionf_fn);
	gtk_widget_destroy(Modifier_fn);
	treeview_fn = lookup_widget(Gestionf_fn,"treeview_fn");
	afficher_menu(treeview_fn,"menu.txt");
}

////////////////////////////////////////////////////////////////////////

void
on_checkbutton_dejeuner_modification_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	CM = 1;
}

////////////////////////////////////////////////////////////////////////

void
on_checkbutton_diner_modification_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	CM = 2;
}

////////////////////////////////////////////////////////////////////////

void
on_button_sauvegarder_fn_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *combobox_jour_modification_fn;
	GtkWidget *Gestionf_fn;
	GtkWidget *Modifier_fn;
	GtkWidget *jour;
	GtkWidget *temps;
	GtkWidget *entree;
	GtkWidget *plat;
	GtkWidget *dessert;
	GtkWidget *dechets;
	GtkWidget *treeview;
	menu m;
	int x;


	if(CM==1)
	strcpy(m.temps,"dejeuner");
	if(CM==2)
	strcpy(m.temps,"diner");

	jour = lookup_widget(button,"combobox_jour_modification_fn");
	strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));

	entree = lookup_widget (button, "entry_modification_fn");
	strcpy(m.menu.entree, gtk_entry_get_text(GTK_ENTRY(entree)));

	plat = lookup_widget (button, "entry_plat_modification_fn");
	strcpy(m.menu.plat_principale, gtk_entry_get_text(GTK_ENTRY(plat)));

	dessert = lookup_widget (button, "entry_dessert_modification_fn");
	strcpy(m.menu.dessert, gtk_entry_get_text(GTK_ENTRY(dessert)));

	dechets = lookup_widget(button, "spinbutton_dechets_modification_fn");
	m.dechets = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (dechets));

	x=verif(m,"menu.txt");

	if(x==1)
	{
	//supprimer_menu("menu.txt",tmp.jour,tmp.temps);
	modifier_menu("menu.txt",m);
	}	
}

////////////////////////////////////////////////////////////////////////

void
on_button_home3_fn_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestionf_fn;
	GtkWidget *Supprimer_fn;
	GtkWidget *treeview_fn;

	Supprimer_fn = lookup_widget(button,"Supprimer_fn");
	Gestionf_fn = lookup_widget(button,"Gestionf_fn");
	Gestionf_fn = create_Gestionf_fn ();
	gtk_widget_show (Gestionf_fn);
	gtk_widget_destroy(Supprimer_fn);
	treeview_fn = lookup_widget(Gestionf_fn,"treeview_fn");
	afficher_menu(treeview_fn,"menu.txt");
}

////////////////////////////////////////////////////////////////////////

void
on_radiobutton_dejeuner3_fn_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	t=1;
}

////////////////////////////////////////////////////////////////////////

void
on_radiobutton_diner3_fn_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	t=2;
}

////////////////////////////////////////////////////////////////////////

void
on_button_suppression_fn_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *combobox_suppression_fn;
	GtkWidget *Gestionf_fn;
	GtkWidget *Supprimer_fn;
	GtkWidget *jour;
	GtkWidget *temps;
	GtkWidget *entree;
	GtkWidget *plat;
	GtkWidget *desert;
	GtkWidget *dechets;
	GtkWidget *treeview;
	menu m;
	int x;

	if(t==1)
	strcpy(m.temps,"dejeuner");
	if(t==2)
	strcpy(m.temps,"diner");

	jour = lookup_widget(button,"combobox_suppression_fn");
	strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));

	x=rechercher_menu("menu.txt",m.jour,m.temps);

	if(x==1)
	{
	supprimer_menu("menu.txt",m.jour,m.temps);
	}
}

////////////////////////////////////////////////////////////////////////

void
on_button_home5_fn_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Gestionf_fn;
	GtkWidget *Rechercher_fn;
	GtkWidget *treeview_fn;

	Rechercher_fn = lookup_widget(button,"Rechercher_fn");
	Gestionf_fn = lookup_widget(button,"Gestionf_fn");
	Gestionf_fn = create_Gestionf_fn ();
	gtk_widget_show (Gestionf_fn);
	gtk_widget_destroy(Rechercher_fn);
	treeview_fn = lookup_widget(Gestionf_fn,"treeview_fn");
	afficher_menu(treeview_fn,"menu.txt");
}

////////////////////////////////////////////////////////////////////////

void
on_checkbutton_dejeuner_rechercher_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	choix[0]=1;
}

////////////////////////////////////////////////////////////////////////

void
on_checkbutton_diner_rechercher_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	choix[1]=1;
}

////////////////////////////////////////////////////////////////////////

void
on_button_chercher_fn_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Modifier_fn;
	GtkWidget *Rechercher_fn;
	GtkWidget *combobox_jour_rechercher_fn;
	GtkWidget *jour;
	GtkWidget *temps;
	GtkWidget *entree;
	GtkWidget *plat;
	GtkWidget *desert;
	GtkWidget *dechets;
	GtkWidget *treeview;
	int x;
	menu m;

	if(choix[0]==1 && choix[1]==0)
	strcpy(m.temps,"dejeuner");

	if(choix[0]==0 && choix[1]==1)
	strcpy(m.temps,"diner");

	jour = lookup_widget(button,"combobox_jour_rechercher_fn");
	strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));

	x=rechercher_menu("menu.txt",m.jour,m.temps);

	if(x==1)
	{
	tmp=m;
	Rechercher_fn = lookup_widget(button,"Rechercher_fn");
	Modifier_fn = lookup_widget(button,"Modifier_fn");
	Modifier_fn = create_Modifier_fn ();
	gtk_widget_show (Modifier_fn);
	gtk_widget_destroy(Rechercher_fn);
	}

}


