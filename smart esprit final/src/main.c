/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{ 
  GtkWidget *inscription;
  GtkWidget *windowAuthentification;
  GtkWidget *windowAdmin;
  GtkWidget *ajouter;
  GtkWidget *admin;
  GtkWidget *modif;
  GtkWidget *alerte;
  GtkWidget *Aceuill;
  GtkWidget *gestion1;
  GtkWidget *windowGestionEtudiant;
  GtkWidget *windowAjoutEtudiant;
  GtkWidget *windowModifierEtudiant;
  GtkWidget *windowSupprimerEtudiant;
  GtkWidget *windowListeEtudiants;
  GtkWidget *windowModification;
  GtkWidget *authentification;
  GtkWidget *Ajout;
  GtkWidget *Modification_;
  GtkWidget *Suppression_;
  GtkWidget *liste_des_utilisateurs;
  GtkWidget *dashboard;
  GtkWidget *mod;
  GtkWidget *af;
  GtkWidget *aj;
  GtkWidget *Gestionf_fn;
  GtkWidget *Rechercher_fn;
  GtkWidget *Ajout_fn;
  GtkWidget *Supprimer_fn;
  GtkWidget *Modifier_fn;


#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory("../pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  /*windowGestionEtudiant = create_windowGestionEtudiant ();
  gtk_widget_show (windowGestionEtudiant);*/
  /*windowAjoutEtudiant = create_windowAjoutEtudiant ();
  gtk_widget_show (windowAjoutEtudiant);
  windowModifierEtudiant = create_windowModifierEtudiant ();
  gtk_widget_show (windowModifierEtudiant);
  windowSupprimerEtudiant = create_windowSupprimerEtudiant ();
  gtk_widget_show (windowSupprimerEtudiant);
  windowListeEtudiants = create_ModifierEtudiant ();
  gtk_widget_show (windowListeEtudiants);
  windowModification = create_ModifierEtudiant();
  gtk_widget_show(windowModification);*/
  inscription = create_inscription ();
  gtk_widget_show (inscription);
  windowAuthentification = create_windowAuthentification ();
  //gtk_widget_show (windowAuthentification);
 // windowAdmin = create_windowAdmin ();
  //gtk_widget_show (windowAdmin);
 /* authentification = create_authentification ();
  gtk_widget_show (authentification);
  Ajout = create_Ajout ();
  gtk_widget_show (Ajout);
  Modification_ = create_Modification_ ();
  gtk_widget_show (Modification_);
  Suppression_ = create_Suppression_ ();
  gtk_widget_show (Suppression_);
  liste_des_utilisateurs = create_liste_des_utilisateurs ();
  gtk_widget_show (liste_des_utilisateurs);
  dashboard = create_dashboard ();
  gtk_widget_show (dashboard);*/
/*
  mod = create_mod ();
  gtk_widget_show (mod);
  af = create_af ();
  gtk_widget_show (af);
  aj = create_aj ();
  gtk_widget_show (aj);
*/
  /*ajouter = create_ajouter ();
  gtk_widget_show (ajouter);
  admin = create_admin ();
  gtk_widget_show (admin);
  modif = create_modif ();
  gtk_widget_show (modif);
  alerte = create_alerte ();
  gtk_widget_show (alerte);*/

  gtk_main ();
  return 0;
}

