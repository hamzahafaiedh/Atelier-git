#include <gtk/gtk.h>




void
on_deconnecter_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_rechercher_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_rupture_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_supp_valider_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_modif_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_modif_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_hh_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_annuler_ajout_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_5kg_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_10kg_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_20kg_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hh_supp_oui_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_hh_rupture_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_hh_ajout_prod_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_affich_supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_affich_ajout_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_affich_modif_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_recherche_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_rupture_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_fruit_a_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_legume_a_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_viande_a_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_liquides_a_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ingredients_a_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fruit_m_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_legume_m_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_viande_m_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ingredients_m_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_liquides_m_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rech_par_nom_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rech_par_id_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rech_valider_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualiser_prod_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_mail_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_annuler_mail_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_valider_mail_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_mail_clicked                 (GtkButton       *button,
                                        gpointer         user_data);
