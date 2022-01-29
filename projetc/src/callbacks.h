#include <gtk/gtk.h>


void
on_retour_clicked                      (GtkButton       *objet,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkWidget       *gestion,
                                        gpointer         user_data);

void
on_modifiercap_clicked                 (GtkButton        *objet_graphique,
                                        gpointer         user_data);

void
on_remplir_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Modifier_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercher_clicked                    (GtkButton       *gestion,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkWidget       *gestion,
                                        gpointer         user_data);

void
on_consulter_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonstat_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonactu_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_gestion2_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_Quitter_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);

void
on_buttonCap_Def_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonGes_alarm_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonE_pannes_clicked              (GtkButton       *button,
                                        gpointer         user_data);
