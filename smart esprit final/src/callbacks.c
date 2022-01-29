#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

void
on_buttonFoyer_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowGestionEtu;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowAdmin");
gtk_widget_destroy(windowMenu);

windowGestionEtu = lookup_widget(button,"windowGestionEtudiant");
windowGestionEtu = create_windowGestionEtudiant();
gtk_widget_show(windowGestionEtu);
}


void
on_buttonCapteur_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowgestion1;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowAdmin");
gtk_widget_destroy(windowMenu);

windowgestion1 = lookup_widget(button,"gestion1");
windowgestion1 = create_gestion1();
gtk_widget_show(windowgestion1);
}

void
on_buttonListeEtudiants_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview;
GtkWidget *listeemp;
GtkWidget *window;
listeemp = create_windowListeEtudiants();
gtk_widget_show(listeemp);
treeview = lookup_widget(listeemp, "treeview");
afficher_etudiant(treeview);
window = lookup_widget(button,"windowGestionEtudiant");
gtk_widget_destroy(window);




}


void
on_buttonSupprimeEtudiant_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *liste;
windowMenu = lookup_widget(button, "windowGestionEtudiant");
gtk_widget_destroy(windowMenu);
windowSupprimer = create_windowSupprimerEtudiant();
gtk_widget_show(windowSupprimer);

liste = lookup_widget (windowSupprimer, "treeview5");
afficher_etudiant(liste);

}


void
on_buttonAcceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprimer;
GtkWidget *windowMenu;
GtkWidget *windowAjoutEtudiant;
GtkWidget *windowModifier;
GtkWidget *windowListeEtudiants;
GtkWidget *windowCalcul;
windowSupprimer = lookup_widget(button, "windowSupprimerEtudiant");
gtk_widget_destroy(windowSupprimer);

windowModifier = lookup_widget(button, "windowModifierEtudiant");
gtk_widget_destroy(windowModifier);

windowAjoutEtudiant = lookup_widget(button, "windowAjoutEtudiant");
gtk_widget_destroy(windowAjoutEtudiant);


windowListeEtudiants = lookup_widget(button, "windowListeEtudiants");
gtk_widget_destroy(windowListeEtudiants);

windowCalcul = lookup_widget(button, "windowcalcul");
gtk_widget_destroy(windowCalcul);

windowMenu = create_windowGestionEtudiant();
gtk_widget_show(windowMenu);





}


void
on_buttonDeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonAjoutEtudiant_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionEtudiant");
gtk_widget_destroy(windowMenu);

windowAjout = lookup_widget(button,"windowAjoutEtudiant");
windowAjout = create_windowAjoutEtudiant();
gtk_widget_show(windowAjout);






}


void
on_buttonModifEtudiant_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowModifier;
GtkWidget *windowMenu;
GtkWidget *liste;

windowMenu = lookup_widget(button, "windowGestionEtudiant");
gtk_widget_destroy(windowMenu);
windowModifier = create_windowModifierEtudiant();
gtk_widget_show(windowModifier);

liste = lookup_widget (windowModifier, "treeview4");
afficher_etudiant(liste);


}


int i; //variable pour savoir le numero d'identifiant 



void
on_buttonRechercher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview1;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok; //variable de la fonction chercher_employe (1 si existe 0 si existe pas)
Etudiant e;
char cin[30];
input = lookup_widget(button, "entryUsername");
buttonEnable = lookup_widget(button, "buttonModif"); //Pointeur sur bouton Modifier
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

window = lookup_widget(button, "windowModifierEtudiant");
treeview1 = lookup_widget(window, "treeview1");
chercher_etudiant(e, cin, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE


afficher_etudiantModif(treeview1);

}


void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char cin[30];
int id;
GtkWidget *windowSuccees;
Etudiant p;
GtkWidget *input;
input = lookup_widget(button, "entryUsername");
strcpy(cin, gtk_entry_get_text(GTK_ENTRY(input)));
id = id_supprimer_etudiant(p, cin);
supprimer_etudiant(p,cin);
windowSuccees = create_dialog3();
gtk_widget_show(windowSuccees);
}


/*void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{



}
*/






gboolean
on_treeview_start_interactive_search   (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_buttonRefresh_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget *listeemp;
listeemp = create_windowListeEtudiants();
treeview = lookup_widget(listeemp, "treeview");
afficher_etudiant(treeview);


}

char tmps[30];// stocker dans la variable tmps le cin de l'utilisateur a modifier pour l'utiliser dans l'affichage
void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

Etudiant e;
GtkWidget *input1;
GtkWidget *windowModification;
//char cin[30];
FILE *fp;
fp = fopen("temp1.txt", "r");
input1 = lookup_widget(button, "entryUsername");
strcpy(tmps,gtk_entry_get_text(GTK_ENTRY(input1)));
windowModification = create_ModifierEtudiant();
gtk_widget_show(windowModification);
// *********************************	SET TEXT TO ENTRIES	***************************
GtkWidget *output1, *output2, *output3, *output4, *output5, *output6, *output7 ,*output8;
if(fp!=NULL)
{
while(fscanf(fp,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,&e.id,e.sexe,e.compt.username,e.compt.password,&e.date_naissance.jour,&e.date_naissance.mois,&e.date_naissance.annee,e.chambre,e.categorie)!=EOF)
	
{
	output1 = lookup_widget(windowModification, "entryModifierNom");
	gtk_entry_set_text(GTK_ENTRY(output1), e.nom);

	output2 = lookup_widget(windowModification, "entryModifierPrenom");
	gtk_entry_set_text(GTK_ENTRY(output2), e.prenom);

	output3 = lookup_widget(windowModification, "entryModifierCin");
	gtk_entry_set_text(GTK_ENTRY(output3), e.cin);

	output4 = lookup_widget(windowModification, "entryModifierGsm");
	gtk_entry_set_text(GTK_ENTRY(output4), e.gsm);


	output5 = lookup_widget(windowModification, "spinbuttonModifierJour");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), e.date_naissance.jour);


	output6 = lookup_widget(windowModification, "spinbuttonModifierMois");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6), e.date_naissance.mois);


	output7 = lookup_widget(windowModification, "spinbuttonModifierAnnee");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7), e.date_naissance.annee);

	output8 = lookup_widget(windowModification, "entryModifierChambre");
	gtk_entry_set_text(GTK_ENTRY(output8), e.chambre);

}
}
////////////////////////////////////////////////////////
fclose(fp);
}







void
on_RechercherSupp_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview2;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok; //variable de la fonction chercher_employe (1 si existe 0 si existe pas)
Etudiant e;
char cin[30];
input = lookup_widget(button, "entryUsername");
buttonEnable = lookup_widget(button, "buttonSupprimer"); //Pointeur sur bouton Modifier
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));

window = lookup_widget(button, "windowSupprimerEtudiant");
treeview2 = lookup_widget(window, "treeview2");
chercher_etudiant(e, cin, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); //Set Sensitivity to TRUE
else
gtk_widget_set_sensitive(buttonEnable, FALSE); //Set Sensitivity to FALSE


afficher_etudiantModif(treeview2);

}






void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog1");
gtk_widget_destroy(window);


}


void
on_okbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog2");
gtk_widget_destroy(window);

}


void
on_okbutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog3");
gtk_widget_destroy(window);

}


void
on_okbutton4_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowChamps");
gtk_widget_destroy(window);

}


void
on_okbutton5_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog5");
gtk_widget_destroy(window);

}


void
on_okbutton6_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "dialog6");
gtk_widget_destroy(window);

}





void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowAjout;
Etudiant p;
Etudiant e;
int fail=0;
FILE *fp1;
fp1 = fopen("utilisateurs.txt", "r");
if (fp1==NULL)
    {
	i = 0; //Id = 0 si le fichier n'existe pas (pas d'employe ajouté)
    }
    
 
    else
    {
	while(fscanf(fp1,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",p.prenom,p.nom,p.gsm,p.cin,&p.id,p.sexe,p.compt.username,p.compt.password,&p.date_naissance.jour,&p.date_naissance.mois,&p.date_naissance.annee,e.chambre,e.categorie)!=EOF)
	
	{
		i = p.id; // i prends la valeur du dernier employe ajouté
	}
    }
fclose(fp1);
i++; // si le dernier employe ajouté à un id=5 donc i=6 ou si il nya pas d'employe, i commence de 1

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *dialog;


windowAjout = lookup_widget(button,"windowAjoutEtudiant");
input1 = lookup_widget(button, "entryNom");
input2 = lookup_widget(button, "entryPrenom");
input3 = lookup_widget(button, "entryCin");
input4 = lookup_widget(button, "entryGsm");
input6 = lookup_widget(button, "combobox1");
Jour = lookup_widget(button, "spinbuttonJours");
Mois = lookup_widget(button, "spinbuttonMois");
Annee = lookup_widget(button, "spinbuttonAnnees");
input5 = lookup_widget(button, "entryChambre");


strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.chambre,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.categorie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(lookup_widget(windowAjout,"radiobutton1")) )){
strcpy(p.sexe,"homme");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(lookup_widget(windowAjout,"radiobutton2")) )){
strcpy(p.sexe,"femme");
}



p.date_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p.date_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p.date_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
p.id = i;
if((strcmp(p.nom,"")==0) || (strcmp(p.prenom,"")==0) || (strcmp(p.cin,"")==0) || (strcmp(p.gsm,"")==0) || (strcmp(p.chambre,"")==0))
{
windowErreur = create_windowChamps();
gtk_widget_show(windowErreur);
fail=1;
}
fp1 = fopen("utilisateurs.txt", "r");
if(fp1==NULL)
{
	return;
}
else
{
while(fscanf(fp1,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",e.prenom,e.nom,e.gsm,e.cin,&e.id,e.sexe,e.compt.username,e.compt.password,&e.date_naissance.jour,&e.date_naissance.mois,&e.date_naissance.annee,e.chambre,e.categorie)!=EOF)
	
{
	if(strcmp(e.cin, p.cin)==0)
	{
		dialog = create_dialog6();
		gtk_widget_show(dialog);
		fail = 1;
		break;
	}
}
fclose(fp1);
}

if (fail==0)
{
ajouter_etudiant(p);
windowSuccees = create_dialog1();
gtk_widget_show(windowSuccees);
}
}



void
on_buttonConfirmerModif_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
Etudiant p;
FILE *fp1;
fp1 = fopen("utilisateurs.txt", "r");
if (fp1==NULL)
    {
	i = 0;
    }
    
 
    else
    {
	while(fscanf(fp1,"%s %s %s %s %d %s %s %s %d %d %d %s %s\n",p.prenom,p.nom,p.gsm,p.cin,&p.id,p.sexe,p.compt.username,p.compt.password,&p.date_naissance.jour,&p.date_naissance.mois,&p.date_naissance.annee,p.chambre,p.categorie)!=EOF)
	
	{
		if (strcmp(p.cin,tmps)==0){
		i = p.id; // i prends la valeur de l'employe qui a la cin à rechercher
		break;}
	}
    }

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *windowM;
GtkWidget *window;
window = lookup_widget(button,"ModifierEtudiant");
input1 = lookup_widget(button, "entryModifierNom");
input2 = lookup_widget(button, "entryModifierPrenom");
input3 = lookup_widget(button, "entryModifierCin");
input4 = lookup_widget(button, "entryModifierGsm");
Jour = lookup_widget(button, "spinbuttonModifierJour");
Mois = lookup_widget(button, "spinbuttonModifierMois");
Annee = lookup_widget(button, "spinbuttonModifierAnnee");
input5 = lookup_widget(button, "entryModifierChambre");
input6 = lookup_widget(button, "combobox2");

strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.chambre,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.categorie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(lookup_widget(window,"radiobutton1")) )){
strcpy(p.sexe,"homme");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(lookup_widget(window,"radiobutton2")) )){
strcpy(p.sexe,"femme");
}


p.date_naissance.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
p.date_naissance.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
p.date_naissance.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
p.id = i;

if( (strcmp(p.nom,"")==0) || (strcmp(p.prenom,"")==0) || (strcmp(p.cin,"")==0) || (strcmp(p.gsm,"")==0) || (strcmp(p.chambre,"")==0))
{
windowErreur = create_windowChamps();
gtk_widget_show(windowErreur);
}
else
{
modifier_etudiant(p, tmps);  
windowSuccees = create_dialog2();
gtk_widget_show(windowSuccees);
windowM = lookup_widget(button, "ModifierEtudiant");
gtk_widget_destroy(windowM);
}
}

calcul[5]={0,0,0,0,0};char so[50];
Etudiant e;


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[1]=1;
}
else
{calcul[1]=0;}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[2]=1;
}
else
{calcul[2]=0;}
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[3]=1;
}
else
{calcul[3]=0;}
}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[0]=1;
}
else
{calcul[0]=0;}
}


void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[5]=1;
}
else
{calcul[5]=0;}
}


void
on_buttoncalculer_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *somme;
int sum;
somme = lookup_widget(button, "label") ;
sum=nbre (calcul,"utilisateurs.txt");
sprintf(so,"%d",sum);
gtk_label_set_text(GTK_LABEL(somme),so);
}





void
on_buttoncalcul_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowMenu;
windowAjout = lookup_widget(button,"windowGestionEtudiant");
gtk_widget_destroy(windowAjout);

windowMenu = lookup_widget(button,"windowcalcul");
windowMenu = create_windowcalcul();
gtk_widget_show(windowMenu);

}




void
on_button2_clicked                     (GtkButton       *gestion,
                                        gpointer         user_data)
{
capteur c;
GtkWidget *entryType;
GtkWidget *entryId;
GtkWidget *entryMarque;
GtkWidget *entryValeur;
GtkWidget *entryJour;
GtkWidget *entryHeure;
GtkWidget *labelType;
GtkWidget *labelId;
GtkWidget *labelMarque;
GtkWidget *labelValeur;
GtkWidget *labelJour;
GtkWidget *labelHeure;
GtkWidget *existe;
GtkWidget *success;
int b=1;



entryType=lookup_widget(gestion,"comboboxentry1");
entryId=lookup_widget(gestion,"id");
entryMarque=lookup_widget(gestion,"marque");
entryValeur=lookup_widget(gestion,"valeur");
entryJour=lookup_widget(gestion,"jour");
entryHeure=lookup_widget(gestion,"heure");

labelType=lookup_widget(gestion,"label95");
labelId=lookup_widget(gestion,"label96");
labelMarque=lookup_widget(gestion,"label100");
labelValeur=lookup_widget(gestion,"label97");
labelJour=lookup_widget(gestion,"label102");
labelHeure=lookup_widget(gestion,"label110");
existe=lookup_widget(gestion,"label98");
success=lookup_widget(gestion,"label99");
        strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryType)));
        strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(entryId)));
	strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(entryMarque)));
	strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(entryValeur)));
	strcpy(c.jour,gtk_entry_get_text(GTK_ENTRY(entryJour)));
	strcpy(c.heure,gtk_entry_get_text(GTK_ENTRY(entryHeure)));

 gtk_widget_hide (success);
// controle saisie
if(strcmp(c.type,"")==0){
		  gtk_widget_show (labelType);
b=0;
}
else {
		  gtk_widget_hide(labelType);
}

if(strcmp(c.id,"")==0){
		  gtk_widget_show (labelId);
b=0;
}
else {
		  gtk_widget_hide(labelId);
}
if(strcmp(c.marque,"")==0){
		  gtk_widget_show (labelMarque);
b=0;
}
else {
		  gtk_widget_hide(labelMarque);
}
if(strcmp(c.valeur,"")==0){
		  gtk_widget_show (labelValeur);
b=0;
}
else {
		  gtk_widget_hide(labelValeur);
}
if(strcmp(c.jour,"")==0){
		  gtk_widget_show (labelJour);
b=0;
}
else {
		  gtk_widget_hide(labelJour);
}
if(strcmp(c.heure,"")==0){
		  gtk_widget_show (labelHeure);
b=0;
}
else {
		  gtk_widget_hide(labelHeure);
}


if(b==1){

       if(exist_capteur(c.id)==1)
        {

				  gtk_widget_show (existe);
        }
        else {
						  gtk_widget_hide (existe);
                ajouter_capteur(c);

						  gtk_widget_show (success);
        }
//mise a jour du treeView
        GtkWidget*p=lookup_widget(gestion,"treeview6");

        //AfficherCapteur(p,"capteur.txt");

}
}


void
on_retour_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *retour,*ges;
retour=lookup_widget(objet,"Aceuill");
gtk_widget_destroy(retour);
ges=create_gestion1();
gtk_widget_show(ges);
}




void
on_remplir_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ref,*nom,*prenom,*tel,*fonction,*jour,*mois,*annee,*jour1,*mois1,*annee1,*identifiant;

identifiant=lookup_widget(button,"combobox3");
nom=lookup_widget(button,"type1");
prenom=lookup_widget(button,"marque1");
tel=lookup_widget(button,"valeur1");
fonction=lookup_widget(button,"jour1");

jour=lookup_widget(button,"heure1");

char var[10];
strcpy(var,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
capteur c;
FILE *f=NULL;
f = fopen("capteur.txt","r");
if(f!=NULL)
{
 while (fscanf(f,"%s %s %s %s %s %s \n" ,c.type,c.id,c.marque,c.valeur,c.jour,c.heure)!=EOF)

{
if(strcmp(var,c.id)==0)
{
//gtk_entry_set_text (ref,t.ref);
gtk_entry_set_text (nom,c.type);
gtk_entry_set_text (prenom,c.marque);
gtk_entry_set_text (tel,c.valeur);
gtk_entry_set_text (fonction,c.jour);
gtk_entry_set_text (jour,c.heure);





}


}
}
fclose(f);
}

void
on_modifiercap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
capteur p;
	GtkWidget *identifiant,*nom,*prenom,*tel,*jour, *mois, *annee, *fonction,*jour1, *mois1, *annee1 ;
	char ver[30];

	
	identifiant=lookup_widget(button,"combobox3");
	nom=lookup_widget(button,"type1");
	prenom=lookup_widget(button,"marque1");
	tel=lookup_widget(button, "valeur1");
	fonction=lookup_widget(button, "jour1");

	jour=lookup_widget(button, "heure1");
	
	strcpy(ver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	

	
	strcpy(p.type,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(p.marque,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(p.valeur,gtk_entry_get_text(GTK_ENTRY(tel)));
	strcpy(p.jour,gtk_entry_get_text(GTK_ENTRY(fonction)));
	strcpy(p.heure,gtk_entry_get_text(GTK_ENTRY(jour)));

	strcpy(p.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(identifiant)));
	modifier_capteur(p,ver);

}




void
on_chercher_clicked                    (GtkButton       *gestion,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelid;
GtkWidget *nbResultat;
GtkWidget *message;
char id[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion,"entry11");
labelid=lookup_widget(gestion,"label125");
p1=lookup_widget(gestion,"treeview6");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(id,"")==0){
  gtk_widget_show (labelid);b=0;
}else{
b=1;
gtk_widget_hide (labelid);}

if(b==0){return;}else{

nb=ChercherCapteur(p1,"capteur.txt",id);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);//conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultat=lookup_widget(gestion,"label131");
message=lookup_widget(gestion,"label127");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);



}
}

void
on_supprimer_clicked                   (GtkButton       *gestion,
                                        gpointer         user_data)
{
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar *numero;
	gchar*type;
gchar*valeur;
gchar*marque ;
gchar*jour;
gchar*heure;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        label=lookup_widget(gestion,"label124");
        p=lookup_widget(gestion,"treeview6");




        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&type,1,&numero,2,&marque,3,&valeur,4,&jour,5,&heure,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_capteur(numero);// supprimer la ligne du fichier

           gtk_widget_hide (label);}
else{
                gtk_widget_show (label);
        }
}



void
on_consulter_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *Affich;
GtkWidget *treevie;

Affich=lookup_widget(objet,"label131");

treevie=lookup_widget(objet,"treeview6");


afficher_capteur(treevie,"capteur.txt");
}



void
on_buttonactu_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ACT;
ACT=lookup_widget(button,"Aceuill");
/*refresh Treeview*/
GtkWidget *p;
p=lookup_widget(ACT,"stattreeview");
afficherCapteur(p,"capteur.txt");
}



void
on_Modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *combo,*btn;
combo=lookup_widget(button,"combobox3");
btn=lookup_widget(button,"modifier");
gtk_widget_set_sensitive ( btn, FALSE);//disable button
fichierRef();

char id[30];

FILE *f=NULL;
f = fopen("reference.txt","r");
if(f!=NULL)
{
 while (fscanf(f,"%s \n " ,id)!=EOF)
gtk_combo_box_append_text (GTK_COMBO_BOX(combo),(id));
}
fclose(f);
remove("reference.txt");

}


void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *type;
        gchar *id;
        gchar *marque;
        gchar *valeur;
	gchar *jour;
	gchar *heure;
	capteur k;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &type, 1, &id, 2, &marque, 3, &valeur, 4, &jour, 5, &heure, -1);
		strcpy(k.type,type);
		strcpy(k.id,id);
		strcpy(k.marque,marque);
		strcpy(k.valeur,valeur);
		strcpy(k.jour,jour);
		strcpy(k.heure,heure);
		
		///////appele fonction suprrimer 
		///supprimer_capteur(c);
		
		afficher_capteur(treeview,"capteur.txt");
		
        

}
}



void
on_buttonCap_Def_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	capteur c;	
	GtkWidget * Cap_def;
	GtkWidget * treeview8;
	Cap_def=lookup_widget(button,"Cap_def");
	Cap_def=create_Cap_def();
	gtk_widget_show(Cap_def);
	capteur_def(c);
	treeview8=lookup_widget(Cap_def,"treeview8");
	afficher_capteur(treeview8,"capteur2.txt");
}


void
on_gestion2_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion;
GtkWidget *Aceuill;

Gestion=lookup_widget(button,"gestion1");
gtk_widget_destroy(Gestion);
Aceuill = create_Aceuill();

/*Preparation Treeview*/
GtkWidget *p;
p=lookup_widget(Aceuill,"stattreeview");
i=0;
afficherCapteur(p,"capteur.txt");

gtk_widget_show(Aceuill);
}


void
on_buttonGes_alarm_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{	
	capteur c;
	GtkWidget * Ges_alrm;
	GtkWidget * treeview5;
	Ges_alrm=lookup_widget(button,"Ges_alrm");
	Ges_alrm=create_Ges_alrm();
	gtk_widget_show(Ges_alrm);
	liste_alarme(c);
	treeview5=lookup_widget(Ges_alrm,"treeview9");
	afficher_capteur(treeview5,"capteur1.txt");
}


void
on_buttonE_pannes_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
capteur c;
GtkWidget * etage_panne;
GtkWidget * treeview6;
etage_panne=lookup_widget(button,"etage_panne");
etage_panne=create_etage_panne();
gtk_widget_show(etage_panne);
etage_pannes(c);
treeview6=lookup_widget(etage_panne,"treeview10");
afficher_capteur(treeview6,"capteur3.txt");
}



void
on_Quitter_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *quitter;
quitter=lookup_widget(objet,"gestion1");
gtk_widget_destroy(quitter);
}


void
on_modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *combo,*btn;
combo=lookup_widget(button,"combobox3");
btn=lookup_widget(button,"modifier");
gtk_widget_set_sensitive ( btn, FALSE);//disable button
fichierRef();

char id[30];

FILE *f=NULL;
f = fopen("reference.txt","r");
if(f!=NULL)
{
 while (fscanf(f,"%s \n " ,id)!=EOF)
gtk_combo_box_append_text (GTK_COMBO_BOX(combo),(id));
}
fclose(f);
remove("reference.txt");
}


void
on_buttonLogin_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *fp;
fp = fopen("utilisateurs.txt", "a+");
int test;

GtkWidget *windowAdmin, *username, *password;
char username1[20],password1[20];


username = lookup_widget(button, "entryAdresse");
password = lookup_widget(button, "entryMdp");


strcpy(username1, gtk_entry_get_text(GTK_ENTRY(username))); 
strcpy(password1, gtk_entry_get_text(GTK_ENTRY(password))); 


test = verif(username1, password1);

if (test ==1 )
{
windowAdmin = create_windowAdmin();
gtk_widget_show(windowAdmin) ;
}
fclose(fp);


}
int b1 ,b2;

void
on_buttonAjouterInsc_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *fp;
fp = fopen("admin.txt", "a+");

GtkWidget *windowAuth, *windowMenu, *username, *password, *nom, *prenom, *role;
char username1[20],password1[20], nom1[20], prenom1[20], role1[20];

nom = lookup_widget(button, "entryName");
prenom = lookup_widget(button, "entryPrename");
username = lookup_widget(button, "entryuser");
password = lookup_widget(button, "entryPassword");
role = lookup_widget(button, "entryRole");

strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom))); 
strcpy(prenom1, gtk_entry_get_text(GTK_ENTRY(prenom))); 
strcpy(username1, gtk_entry_get_text(GTK_ENTRY(username))); 
strcpy(password1, gtk_entry_get_text(GTK_ENTRY(password))); 
strcpy(role1, gtk_entry_get_text(GTK_ENTRY(role)));

if (fp!=NULL)
{
fprintf(fp, "%s %s %s %s %s\n", nom1, prenom1, username1, password1, role1);
fclose(fp);
}
else
{
printf("Echec de l'ouverture du fichier 'admin.txt'");
}
windowMenu = lookup_widget(button,"inscription");
gtk_widget_destroy(windowMenu);
windowAuth = create_windowAuthentification();
gtk_widget_show(windowAuth);

}





void
on_homme1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
personne p;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(p.sexe,"Homme");
}


void
on_femme1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

personne p;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(p.sexe,"Femme");
}


void
on_Sauvegarder_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
personne p;
char comp[20];
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *identifiant;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *cin;
GtkWidget *poste;
GtkWidget *authentification;
GtkWidget *input1;
GtkWidget *input2;
nom = lookup_widget(button, "nomajouteraa");
prenom = lookup_widget(button, "prenomajouteraa");
identifiant = lookup_widget(button, "identifiantajouteraa");
cin = lookup_widget(button, "cinajouteraa");
jour = lookup_widget(button, "jourajouteraa");
mois = lookup_widget(button, "moisajouteraa");
annee = lookup_widget(button, "anneajouteraa");
input1= lookup_widget(button, "homme1");
input2=lookup_widget(button, "femme1");
poste= lookup_widget(button, "combobox_poste2");
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(p.identifiant, gtk_entry_get_text(GTK_ENTRY(identifiant)));
strcpy(p.numero_de_cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(p.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(poste)));
p.d.jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
p.d.mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
p.d.annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input1)))
strcpy(p.sexe,"Homme");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input2)))
strcpy(p.sexe,"Femme");


ajouter_personne ( "users.txt", p);
authentification =create_liste_des_utilisateurs();
gtk_widget_show (authentification);
}


void
on_Retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_femme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

personne p1;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(p1.sexe,"Femme");
}


void
on_homme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

personne p1;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(p1.sexe,"Homme");
}


void
on_oui_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
personne p1;
char comp[20];
GtkWidget *authentification;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *identifiant;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *cin;
GtkWidget *combobox;
GtkWidget *input1,*input2;

nom = lookup_widget(button, "nommodificationaa");
prenom = lookup_widget(button, "prenommodificationaa");
identifiant = lookup_widget(button, "identifiantmodificationaa");
cin = lookup_widget(button, "cinmodificationaa");
jour = lookup_widget(button, "jourmodificationaa");
mois = lookup_widget(button, "moismodificationaa");
annee = lookup_widget(button, "anneemodificationaa");
combobox=lookup_widget(button, "combobox_modification");
input1= lookup_widget(button, "homme2");
input2=lookup_widget(button, "femme2");
p1.d.jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
p1.d.mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
p1.d.annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(p1.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p1.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(p1.identifiant, gtk_entry_get_text(GTK_ENTRY(identifiant)));
strcpy(p1.numero_de_cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(p1.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input1)))
strcpy(p1.sexe,"Homme");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input2)))
strcpy(p1.sexe,"Femme");



modifier_personne(p1);

authentification=create_liste_des_utilisateurs();
gtk_widget_show (authentification);
}


void
on_non_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *retour;

retour=create_liste_des_utilisateurs();
gtk_widget_show (retour);
}


void
on_treeview11_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* cin;
gchar* identifiant;
gchar* date ;
gchar* sexe;
gchar* poste;
personne p;



GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path))
{

gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&identifiant,4,&date,5,&sexe,6,&poste,-1);
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
strcpy(p.numero_de_cin,cin);
strcpy(p.identifiant,identifiant);
strcpy(p.d.jour,date);
strcpy(p.d.mois,date);
strcpy(p.d.annee,date);
strcpy(p.sexe,sexe);
strcpy(p.poste,poste);

afficher(treeview,"users.txt");
}

}


void
on_AjouterPersonne_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *ajout;
ajout=create_AjoutPersonne();
gtk_widget_show (ajout);
}


void
on_modifierper_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modification;

modification=create_Modificationpersonne();
gtk_widget_show (modification);
}


void
on_supprimerper_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *suppression;

suppression=create_Suppressionper();
gtk_widget_show (suppression);
}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *treeview1;
	GtkWidget *liste_des_utilisateurs_;

	liste_des_utilisateurs_=lookup_widget(button,"liste_des_utilisateurs_");
	treeview1=lookup_widget(button,"treeview11");
	liste_des_utilisateurs_ = create_liste_des_utilisateurs();
	gtk_widget_show (liste_des_utilisateurs_);
	gtk_widget_hide(liste_des_utilisateurs_);
	afficher(treeview1,"users.txt");
}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonconfirmer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char identifiant[50];
GtkWidget *entrysupp;
entrysupp=lookup_widget(button,"entrysupp");
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(entrysupp)));
supprimer_personne(identifiant);
}


gboolean
on_image104_button_press_event         (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{

GtkWidget *windowMeriam;
GtkWidget *window;
windowMeriam = create_liste_des_utilisateurs();
gtk_widget_show(windowMeriam);
window = lookup_widget(widget, "windowAdmin");
gtk_widget_destroy(window);

  return FALSE;
}



void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowMeriam;
GtkWidget *window;
windowMeriam = create_liste_des_utilisateurs();
gtk_widget_show(windowMeriam);
window = lookup_widget(button, "windowAdmin");
gtk_widget_destroy(window);
}


gboolean
on_eventbox1_button_press_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data)
{
GtkWidget *windowMeriam;
GtkWidget *window;
windowMeriam = create_liste_des_utilisateurs();
gtk_widget_show(windowMeriam);
window = lookup_widget(widget, "windowAdmin");
gtk_widget_destroy(window);
  return FALSE;
}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aj, *dashboard;
dashboard=lookup_widget(button,"dashboard");
aj=lookup_widget(button,"aj");
aj=create_aj();
gtk_widget_show(aj);
}





void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(button,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview12");
afficher(treeview,"reclamations.txt");
}


void
on_button4_clicked                     (GtkButton       *button,
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
on_button_mod_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4, *mod5, *r1, *r2, *r3, *r4, *r5, *r6;
reclam u;
mod1=lookup_widget(button,"mod1");
mod2=lookup_widget(button,"mod2");
mod3=lookup_widget(button,"mod3");
mod4=lookup_widget(button,"mod4");
mod5=lookup_widget(button,"mod5");
r1=lookup_widget(button,"r1");
r2=lookup_widget(button,"r2");
r3=lookup_widget(button,"r3");
r4=lookup_widget(button,"r4");
r5=lookup_widget(button,"r5");
r6=lookup_widget(button,"r6");
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
on_check_id_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4, *mod5, *r1, *r2, *r3, *r4, *r5, *r6;
reclam p;
char str[100];
char* desc = (char*) malloc(500);
strcpy(desc,"");
int a=0, id;
FILE *f, *file;
mod1=lookup_widget(button,"mod1");
mod2=lookup_widget(button,"mod2");
mod3=lookup_widget(button,"mod3");
mod4=lookup_widget(button,"mod4");
mod5=lookup_widget(button,"mod5");
r1=lookup_widget(button,"r1");
r2=lookup_widget(button,"r2");
r3=lookup_widget(button,"r3");
r4=lookup_widget(button,"r4");
r5=lookup_widget(button,"r5");
r6=lookup_widget(button,"r6");
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
on_treeview12_row_activated            (GtkTreeView     *treeview,
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




void
on_button22_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *mod, *dashboard;
dashboard=lookup_widget(button,"dashboard");
mod=lookup_widget(button,"mod");
mod=create_mod();
gtk_widget_show(mod);
}


void
on_button_af_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(button,"af");
gtk_widget_destroy(af);
af=lookup_widget(button,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview12");
afficher(treeview,"reclamations.txt");
}


void
on_button_aj_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6;
reclam u;
aj1=lookup_widget(button,"aj1");
aj2=lookup_widget(button,"aj2");
aj3=lookup_widget(button,"aj3");
aj4=lookup_widget(button,"aj4");
aj5=lookup_widget(button,"aj5");
aj6=lookup_widget(button,"aj6");
u.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aj1));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(aj2)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(aj3)));
strcpy(u.classe,gtk_entry_get_text(GTK_ENTRY(aj4)));
u.service=gtk_combo_box_get_active(GTK_COMBO_BOX(aj5));
strcpy(u.desc,gtk_entry_get_text(GTK_ENTRY(aj6)));
ajouter(u,"reclamations.txt");
}


void
on_reclamat_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowMeriam;
GtkWidget *window;
windowMeriam = create_dashboard();
gtk_widget_show(windowMeriam);
window = lookup_widget(button, "windowAdmin");
gtk_widget_destroy(window);

}

char idg[50];
void
on_nutritionniste_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowMeriam;
GtkWidget *window;
windowMeriam = create_admin();
gtk_widget_show(windowMeriam);
window = lookup_widget(button, "windowAdmin");
gtk_widget_destroy(window);
}


void
on_buttonajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *quantt ,*typpe ,*idd,*interf,*Home,*treeview ;

char id[50]; 
char type[50]; 
int quant;


idd=lookup_widget(button,"entry3");
typpe=lookup_widget(button,"comboboxentrytype");
quantt=lookup_widget(button,"spinbuttonct");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));
strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(typpe)));
quant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantt));

ajouterstock(id,type,quant);

Home=lookup_widget(button,"ajouter");
interf=create_admin();
gtk_widget_show(interf);
gtk_widget_hide(Home);
treeview=lookup_widget(interf,"treeview1");
afficherstock(treeview) ;
}


void
on_buttonretourajout_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next ,*treeview ;
Home=lookup_widget(button,"ajouter");
Next=create_admin(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview1");
afficherstock(treeview) ;
}


void
on_buttonlogout_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next ,*treeview ;
Home=lookup_widget(button,"admin");
Next=create_windowAuthentification(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
}


void
on_buttontoajou_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next ,*treeview ;
Home=lookup_widget(button,"admin");
Next=create_ajouter(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview1");
afficherstock(treeview) ;
}


void
on_buttonmodif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next ,*treeview,*idd ;
idd=lookup_widget(button,"entry4");
strcpy(idg,gtk_entry_get_text(GTK_ENTRY(idd)));
Home=lookup_widget(button,"admin");
Next=create_modif(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
}


void
on_buttonSupp_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f ; 
GtkWidget *Home ,*idd ,*Next ,*treeview ;

char id[50] ; 

idd=lookup_widget(button,"entry4");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));

supprimerstock(id);

Home=lookup_widget(button,"admin");
Next=create_admin(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview1");
afficherstock(treeview) ;
}


void
on_buttonalerte_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next  ,*treeview ;
Home=lookup_widget(button,"admin");
Next=create_alerte(); 
alerte();
gtk_widget_show(Next);
gtk_widget_hide(Home);

treeview=lookup_widget(Next,"treeview2");
afficheralerte(treeview) ;
}


void
on_buttonannulmodif_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next  ,*treeview ;
Home=lookup_widget(button,"modif");
Next=create_admin(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview1");
afficherstock(treeview) ;
}


void
on_buttonmod_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f ; 
GtkWidget *Home ,*Next ,*qu ,*treeview ;
int quant;

qu=lookup_widget(button,"spinbutton3");
quant=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(qu));

modifierstock(idg,quant);

Home=lookup_widget(button,"modif");
Next=create_admin(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview1");
afficherstock(treeview) ;
}


void
on_buttonretalerte_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Home ,*Next  ,*treeview ;
Home=lookup_widget(button,"alerte");
Next=create_admin(); 
gtk_widget_show(Next);
gtk_widget_hide(Home);
treeview=lookup_widget(Next,"treeview1");
afficherstock(treeview) ;
}


void
on_nutri_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowMeriam;
GtkWidget *window;
windowMeriam = create_Gestionf_fn();
gtk_widget_show(windowMeriam);
window = lookup_widget(button, "windowAdmin");
gtk_widget_destroy(window);
}


int t=1,CA=1,CM=1;
int choix[2]={0,0};
menu tmp;

///////////////////////////////////////////////////////////////////////


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
on_button_enregister_fn_clicked        (GtkButton       *button,
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

	jour = lookup_widget(button,"combobox_jour_ajouter_fn");
	strcpy(m.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));

	entree = lookup_widget (button, "entry_entree_ajouter_fn");
	strcpy(m.menu.entree, gtk_entry_get_text(GTK_ENTRY(entree)));

	plat = lookup_widget (button, "entry_plat_principal_ajouter_fn");
	strcpy(m.menu.plat_principale, gtk_entry_get_text(GTK_ENTRY(plat)));

	dessert = lookup_widget (button, "entry_dessert_ajouter_fn");
	strcpy(m.menu.dessert, gtk_entry_get_text(GTK_ENTRY(dessert)));

	dechets = lookup_widget(button, "spinbutton_dechets_ajouter_fn");
	m.dechets = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (dechets));

	x=verifier(m,"menu.txt");

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

	x=verifier(m,"menu.txt");

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



