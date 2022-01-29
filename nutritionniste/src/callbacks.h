#include <gtk/gtk.h>


void
on_treeview_fn_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_meilleur_fn_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rafraichir_fn_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_fn_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_fn_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_fn_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_dejeuner_rechercher_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_diner_rechercher_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_chercher_fn_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_home5_fn_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_enregister_fn_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkbutton_diner_ajouter_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_dejeuner_ajouter_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_home1_fn_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_diner3_fn_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_dejeuner3_fn_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_home3_fn_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_suppression_fn_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_connection_fn_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_sauvegarder_fn_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_diner_modification_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_dejeuner_modification_fn_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_home2_fn_clicked             (GtkButton       *button,
                                        gpointer         user_data);
