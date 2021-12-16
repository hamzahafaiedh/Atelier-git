#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "string.h"
#include "fonction.h"



int x,y;
int t[1]={0};
int conf=0;
int *r=&conf;
char idspp[20];

void
on_hh_rechercher_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* hh_window_produits;
hh_window_produits=lookup_widget(button,"hh_window_produits");
gtk_widget_destroy(hh_window_produits);
GtkWidget* hh_window_Rechercher;
hh_window_Rechercher=create_hh_window_Rechercher();
gtk_widget_show(hh_window_Rechercher);
}


void
on_hh_rupture_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_window_rupture;
GtkWidget *hh_window_produits;
GtkWidget *hh_rupture;

hh_window_produits=lookup_widget(button,"hh_window_produits");
gtk_widget_destroy(hh_window_produits);
hh_window_rupture=create_hh_window_rupture();
gtk_widget_show(hh_window_rupture);
hh_rupture=lookup_widget(hh_window_rupture,"hh_rupture");

rupture(hh_rupture);
remove(hh_rupture);
}


void
on_hh_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_window_produits;
GtkWidget *hh_window_modif;
GtkWidget *treeview2;
GtkWidget *type_m;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
gchar* type;
gchar* nom;
gchar* id;
gchar* kg;
gchar* jour_aj;
gchar* mois_aj;
gchar* annee_aj;
gchar* jour_exp;
gchar* mois_exp;
gchar* annee_exp;
nourriture n;
int hh_index=0;

GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*input5;
GtkWidget*input6;
GtkWidget*input7;
GtkWidget*input8;
GtkWidget*input9;
GtkWidget*input10;

hh_window_produits=lookup_widget(button,"hh_window_produits");
treeview2=lookup_widget(hh_window_produits,"treeview2");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview2));
if(gtk_tree_selection_get_selected(selection,&model,&iter)){
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &type,1,&nom,2,&id,3,&kg,4,&jour_aj,5,&mois_aj ,6,&annee_aj ,7,&jour_exp,8,&mois_exp,9,&annee_exp,-1);
	strcpy(n.type,type);
	strcpy(n.nom,nom);
	strcpy(n.id,id);
	strcpy(n.kg,kg);
	n.date_ajout.jour=jour_aj;
	n.date_ajout.mois=mois_aj;
	n.date_ajout.annee=annee_aj;
	n.date_exp.jour=jour_exp;
	n.date_exp.mois=mois_exp;
	n.date_exp.annee=annee_exp;

gtk_widget_hide(hh_window_produits);
hh_window_modif=create_hh_window_modif();
gtk_widget_show(hh_window_modif);
input1=lookup_widget(hh_window_modif,"type_m");
input2=lookup_widget(hh_window_modif,"hh_nom_modifier");
input3=lookup_widget(hh_window_modif,"hh_id_modifier");
input4=lookup_widget(hh_window_modif,"hh_quantite_modifier");
input5=lookup_widget(hh_window_modif,"hh_j_ajouter_mod");
input6=lookup_widget(hh_window_modif,"hh_m_ajouter_mod");
input7=lookup_widget(hh_window_modif,"hh_a_ajouter_mod");
input8=lookup_widget(hh_window_modif,"hh_j_exp_mod");
input9=lookup_widget(hh_window_modif,"hh_m_exp_mod");
input10=lookup_widget(hh_window_modif,"hh_a_exp_mod");


if (strcmp(type,"Fruit")==0){
    hh_index=0;
}
if (strcmp(type,"Legume")==0){
    hh_index=1;
}
if (strcmp(type,"Viande")==0){
    hh_index=2;
}
if (strcmp(type,"Liquides")==0){
    hh_index=3;
}
if (strcmp(type,"Ingedients")==0){
    hh_index=4;
}

gtk_combo_box_set_active(GTK_ENTRY(lookup_widget(hh_window_modif,"type_m")),hh_index);
gtk_entry_set_text (GTK_ENTRY(input2),n.nom);
gtk_entry_set_text (GTK_ENTRY(input3),n.id);
gtk_entry_set_text (GTK_ENTRY(input4),n.kg);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5),n.date_ajout.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6),n.date_ajout.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7),n.date_ajout.annee);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),n.date_exp.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input9),n.date_exp.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input10),n.date_exp.annee);
	
}
}


void
on_hh_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_window_produits;
GtkWidget *hh_window_supp;
GtkWidget *treeview2;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
gchar* type;
gchar* nom;
gchar* id;
gchar* kg;
gchar* jour_aj;
gchar* mois_aj;
gchar* annee_aj;
gchar* jour_exp;
gchar* mois_exp;
gchar* annee_exp;
nourriture n;

GtkWidget*input0;

hh_window_produits=lookup_widget(button,"hh_window_produits");
treeview2=lookup_widget(hh_window_produits,"treeview2");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview2));
if(gtk_tree_selection_get_selected(selection,&model,&iter))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &type,1,&nom,2,&id,3,&kg,4,&jour_aj,5,&mois_aj ,6,&annee_aj ,7,&jour_exp,8,&mois_exp,9,&annee_exp,-1);
	strcpy(n.type,type);
	strcpy(n.nom,nom);
	strcpy(n.id,id);
	strcpy(n.kg,kg);
	n.date_ajout.jour=jour_aj;
	n.date_ajout.mois=mois_aj;
	n.date_ajout.annee=annee_aj;
	n.date_exp.jour=jour_exp;
	n.date_exp.mois=mois_exp;
	n.date_exp.annee=annee_exp;
gtk_widget_hide(hh_window_produits);
hh_window_supp=create_hh_window_supp();
gtk_widget_show(hh_window_supp);
input0=lookup_widget(hh_window_supp,"id_conf_supp");
gtk_entry_set_text (GTK_ENTRY(input0),n.id);
	
}


*r=0;

}


////////////////////////////////////


void
on_hh_supp_valider_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
nourriture n;
GtkWidget *hh_window_supp;
GtkWidget *hh_window_produits;
GtkWidget *treeview2;
GtkWidget *outputMsg;
GtkWidget *input1;
     int supp,verif;
     char text[200];
     char id1[20];

hh_window_supp=lookup_widget(button,"hh_window_supp");
input1=lookup_widget(button,"id_conf_supp");   
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(input1)));
if (*r==1)
{
verif=test_produit(id1);
switch(verif)
{
	case 1:
		{
		supp=supprimer(id1);
		strcpy (text,"élément supprimé avec succès");
		outputMsg=lookup_widget(button,("errror"));
     		GdkColor color;
     		gdk_color_parse("green",&color);
     		gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(outputMsg),text);
		}
	break;
	case 0:
     		{
		strcpy (text,"Identifiant à supprimer n'est pas correcte");
		outputMsg=lookup_widget(button,("errror"));
                GdkColor color;
     		gdk_color_parse("red",&color);
     		gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(outputMsg),text);
     		}
	break;
	break;
}
}
else
{
strcpy (text,"La confirmation est obligatoire!");
outputMsg=lookup_widget(button,("errror"));
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
}



void
on_annuler_modif_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_window_modif;
GtkWidget *hh_window_produits;
GtkWidget *treeview2;

hh_window_modif=lookup_widget(button,"hh_window_modif");
gtk_widget_destroy(hh_window_modif);
hh_window_produits=create_hh_window_produits();
gtk_widget_show(hh_window_produits);
treeview2=lookup_widget(hh_window_produits,"treeview2");
afficher(treeview2);
}


void
on_modif_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
nourriture n;
GtkWidget *hh_window_modif;


GtkWidget *type_m;
GtkWidget *hh_nom_modifier;
GtkWidget *hh_id_modifier;
GtkWidget *hh_quantite_modifier;
GtkWidget *hh_j_ajouter_mod;
GtkWidget *hh_m_ajouter_mod;
GtkWidget *hh_a_ajouter_mod;
GtkWidget *hh_j_exp_mod;
GtkWidget *hh_m_exp_mod;
GtkWidget *hh_a_exp_mod;


GtkWidget*sortie2;
int mod,verif;
char text[200];

hh_window_modif=lookup_widget(button,"hh_window_modif");

type_m=lookup_widget(button,"type_m");
hh_nom_modifier=lookup_widget(button,"hh_nom_modifier");
hh_id_modifier=lookup_widget(button,"hh_id_modifier");
hh_quantite_modifier=lookup_widget(button,"hh_quantite_modifier");

strcpy(n.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_m)));
strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(hh_nom_modifier)));
strcpy(n.id,gtk_entry_get_text(GTK_ENTRY(hh_id_modifier)));
strcpy(n.kg,gtk_entry_get_text(GTK_ENTRY(hh_quantite_modifier)));

///////////////////////////////////////////////////

hh_j_ajouter_mod=lookup_widget(button,"hh_j_ajouter_mod");
hh_m_ajouter_mod=lookup_widget(button,"hh_m_ajouter_mod");
hh_a_ajouter_mod=lookup_widget(button,"hh_a_ajouter_mod");

n.date_ajout.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_j_ajouter_mod));
n.date_ajout.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_m_ajouter_mod));
n.date_ajout.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_a_ajouter_mod));

//////////////////////////////////////////////////

hh_j_exp_mod=lookup_widget(button,"hh_j_exp_mod");
hh_m_exp_mod=lookup_widget(button,"hh_m_exp_mod");
hh_a_exp_mod=lookup_widget(button,"hh_a_exp_mod");

n.date_exp.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_j_exp_mod));
n.date_exp.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_m_exp_mod));
n.date_exp.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_a_exp_mod));



verif=test_produit(n.id);
switch(verif)
    
{
    case 0:  
    { strcpy (text,"Identifiant n'existe pas");
    sortie2=lookup_widget(button,("label34"));
    GdkColor color;
    gdk_color_parse("red",&color);
    gtk_widget_modify_fg(sortie2,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(sortie2),text);
    }
    break;
    case 1:
   
    {if ((strcmp(n.nom,"")==0)||(strcmp(n.id,"")==0)||(strcmp(n.kg,"")==0))
{
 strcpy (text,"Merci de remplir toutes les cases");
    sortie2=lookup_widget(button,("label34"));
    GdkColor color;
    gdk_color_parse("red",&color);
    gtk_widget_modify_fg(sortie2,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(sortie2),text);
}
else
{
if ((saisie_nom(n.nom)==0)||(saisie_kg(n.kg)==0)||(strcmp(n.kg,"0")==0))
{
 strcpy (text,"Merci de verifier les informations");
    sortie2=lookup_widget(button,("label34"));
    GdkColor color;
    gdk_color_parse("red",&color);
    gtk_widget_modify_fg(sortie2,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(sortie2),text);
}
else
{
mod=modifier(n);
 strcpy (text,"Element modifié");
    sortie2=lookup_widget(button,("label34"));
    GdkColor color;
    gdk_color_parse("green",&color);
    gtk_widget_modify_fg(sortie2,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(sortie2),text);
}
}
}
    break; 
    break;
} 
}




void
on_hh_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* hh_window_produits;
hh_window_produits=lookup_widget(button,"hh_window_produits");
gtk_widget_destroy(hh_window_produits);
GtkWidget* hh_window_ajout;
hh_window_ajout=create_hh_window_ajout();
gtk_widget_show(hh_window_ajout);

}


void
on_hh_annuler_ajout_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_window_ajout;
GtkWidget *hh_window_produits;
GtkWidget *treeview2;

hh_window_ajout=lookup_widget(button,"hh_window_ajout");
gtk_widget_destroy(hh_window_ajout);
hh_window_produits=create_hh_window_produits();
gtk_widget_show(hh_window_produits);
treeview2=lookup_widget(hh_window_produits,"treeview2");
afficher(treeview2);
}




void
on_hh_supp_oui_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
*r=1;
else
*r=0;
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* type1;
gchar* nom;
gchar* id;
gchar* kg;
gchar* jour_aj;
gchar* mois_aj;
gchar* annee_aj;
gchar* jour_exp;
gchar* mois_exp;
gchar* annee_exp;
nourriture n;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter (model, &iter, path))
{
//obtention des valeurs de la ligne selectionnée
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &type1, 1, &nom, 2,&id, 3,&jour_aj, 4,&mois_aj, 5,&annee_aj, 6,&jour_aj, 7,&mois_exp, 8,&annee_exp, -1); 
// copie des valeurs dans la variable n de type nourriture pour le passer à la fonction de suppression
strcpy(n.type,type1);
strcpy(n.nom,nom);
strcpy(n.id,id);
strcpy(n.kg,kg);


//strcpy(n.date_ajout,date_ajout); 
n.date_ajout.jour=jour_aj;
n.date_ajout.mois=mois_aj;
n.date_ajout.annee=annee_aj;
n.date_exp.jour=jour_exp;
n.date_exp.mois=mois_exp;
n.date_exp.annee=annee_exp;
//strcpy(n.date_exp,date_exp);


//appel de la fonction de suppression

// mise à jour de l'affichage de la treeview
afficher(treeview);
}
}


void
on_hh_rupture_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* type1;
gchar* nom;
gchar* id;
gchar* kg;
gchar* jour_aj;
gchar* mois_aj;
gchar* annee_aj;
gchar* jour_exp;
gchar* mois_exp;
gchar* annee_exp;
nourriture n;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter (model, &iter, path))
{
//obtention des valeurs de la ligne selectionnée
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &type1, 1, &nom, 2,&id, 3,&jour_aj, 4,&mois_aj, 5,&annee_aj, 6,&jour_aj, 7,&mois_exp, 8,&annee_exp, -1); 
// copie des valeurs dans la variable n de type nourriture pour le passer à la fonction de suppression
strcpy(n.type,type1);
strcpy(n.nom,nom);
strcpy(n.id,id);
strcpy(n.kg,kg);


//strcpy(n.date_ajout,date_ajout); 
n.date_ajout.jour=jour_aj;
n.date_ajout.mois=mois_aj;
n.date_ajout.annee=annee_aj;
n.date_exp.jour=jour_exp;
n.date_exp.mois=mois_exp;
n.date_exp.annee=annee_exp;
//strcpy(n.date_exp,date_exp);


//appel de la fonction de suppression

// mise à jour de l'affichage de la treeview
afficher(treeview);
}
}


void
on_hh_ajout_prod_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{

nourriture n;
GtkWidget *hh_window_ajout;
GtkWidget *hh_nom_ajout; 
GtkWidget *hh_id_ajout ;
GtkWidget *hh_quantite_ajout ; 
GtkWidget *hh_j_ajouter ;
GtkWidget *hh_a_ajouter; 
GtkWidget *hh_m_ajouter; 
GtkWidget *spinbutton7;
GtkWidget *hh_m_exp; 
GtkWidget *hh_a_exp;
GtkWidget *sortieaj;
char text[200];


hh_window_ajout=lookup_widget(button,"hh_window_ajout");

strcpy(n.type,"fruit");


if (x==1)
	strcpy(n.type,"fruit");

if (x==2)
	strcpy(n.type,"legume");

if (x==3)
	strcpy(n.type,"viande");

if (x==4)
	strcpy(n.type,"liquides");

if (x==5)
	strcpy(n.type,"ingredients");

hh_nom_ajout= lookup_widget(GTK_WIDGET(button),"hh_nom_ajout");
strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(hh_nom_ajout)));

hh_id_ajout= lookup_widget(GTK_WIDGET(button),"hh_id_ajout");
strcpy(n.id,gtk_entry_get_text(GTK_ENTRY(hh_id_ajout)));

hh_quantite_ajout= lookup_widget(GTK_WIDGET(button),"hh_quantite_ajout");
strcpy(n.kg,gtk_entry_get_text(GTK_ENTRY(hh_quantite_ajout)));

/////////////////////////

hh_j_ajouter = lookup_widget(GTK_WIDGET(button), "hh_j_ajouter");
n.date_ajout.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_j_ajouter));

hh_m_ajouter = lookup_widget(GTK_WIDGET(button), "hh_m_ajouter");
n.date_ajout.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_m_ajouter));


hh_a_ajouter = lookup_widget(GTK_WIDGET(button), "hh_a_ajouter");
n.date_ajout.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_a_ajouter));


spinbutton7 = lookup_widget(GTK_WIDGET(button), "spinbutton7");
n.date_exp.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton7));


hh_m_exp = lookup_widget(GTK_WIDGET(button), "hh_m_exp");
n.date_exp.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_m_exp));


hh_a_exp = lookup_widget(GTK_WIDGET(button), "hh_a_exp");
n.date_exp.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hh_a_exp));

/////////////////////////
//n.kg=gtk_entry_get_text(GTK_ENTRY(hh_quantite_ajout));


if ((strcmp(n.nom,"")==0)||(strcmp(n.id,"")==0)||(strcmp(n.kg,"")==0))
{
 strcpy (text,"Merci de remplir toutes les cases");
    sortieaj=lookup_widget(button,("ajout_err"));
    GdkColor color;
    gdk_color_parse("red",&color);
    gtk_widget_modify_fg(sortieaj,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(sortieaj),text);
}
else
{
	if ((saisie_nom(n.nom)==0)||(saisie_kg(n.kg)==0)||(strcmp(n.kg,"0")==0))
	{
		strcpy (text,"Merci de verifier les informations");
		sortieaj=lookup_widget(button,("ajout_err"));
		GdkColor color;
		gdk_color_parse("red",&color);
		gtk_widget_modify_fg(sortieaj,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(sortieaj),text);
	}
	else
	{
		if ((test_nom(n.nom)==1)||(test_produit(n.id)==1))
		{
			strcpy (text,"Ce produit existe déja");
			sortieaj=lookup_widget(button,("ajout_err"));
			GdkColor color;
			gdk_color_parse("red",&color);
			gtk_widget_modify_fg(sortieaj,GTK_STATE_NORMAL,&color);
			gtk_label_set_text(GTK_LABEL(sortieaj),text);
		}
		else
		{
			ajouter(n);
			strcpy (text,"Element ajouté");
			sortieaj=lookup_widget(button,("ajout_err"));
			GdkColor color;
			gdk_color_parse("green",&color);
			gtk_widget_modify_fg(sortieaj,GTK_STATE_NORMAL,&color);
			gtk_label_set_text(GTK_LABEL(sortieaj),text);
		}
	}
}
x=1;
}


void
on_affich_supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_window_supp;

GtkWidget *treeview2;

hh_window_supp=lookup_widget(button,"hh_window_supp");
gtk_widget_destroy(hh_window_supp);
GtkWidget* hh_window_produits;
hh_window_produits=create_hh_window_produits();
gtk_widget_show(hh_window_produits);
treeview2=lookup_widget(hh_window_produits,"treeview2");
afficher(treeview2);
}


void
on_affich_ajout_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_window_ajout;
GtkWidget *hh_window_produits;
GtkWidget *treeview2;

hh_window_ajout=lookup_widget(button,"hh_window_ajout");
gtk_widget_destroy(hh_window_ajout);
hh_window_produits=lookup_widget(button,"hh_window_produits");
hh_window_produits=create_hh_window_produits();
gtk_widget_show(hh_window_produits);
treeview2=lookup_widget(hh_window_produits,"treeview2");
afficher(treeview2);

}


void
on_affich_modif_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_window_modif;
GtkWidget *hh_window_produits;
GtkWidget *treeview2;

hh_window_modif=lookup_widget(button,"hh_window_modif");
gtk_widget_destroy(hh_window_modif);
hh_window_produits=create_hh_window_produits();
gtk_widget_show(hh_window_produits);
treeview2=lookup_widget(hh_window_produits,"treeview2");
afficher(treeview2);
}


void
on_retour_recherche_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_window_Rechercher;
GtkWidget *hh_window_produits;
GtkWidget *treeview2;

hh_window_Rechercher=lookup_widget(button,"hh_window_Rechercher");
gtk_widget_destroy(hh_window_Rechercher);
hh_window_produits=create_hh_window_produits();
gtk_widget_show(hh_window_produits);
treeview2=lookup_widget(hh_window_produits,"treeview2");
afficher(treeview2);
}


void
on_retour_rupture_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_window_rupture;
GtkWidget *hh_window_produits;
GtkWidget *treeview2;

hh_window_rupture=lookup_widget(button,"hh_window_rupture");
gtk_widget_destroy(hh_window_rupture);
hh_window_produits=create_hh_window_produits();
gtk_widget_show(hh_window_produits);
treeview2=lookup_widget(hh_window_produits,"treeview2");
afficher(treeview2);
}


void
on_fruit_a_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_legume_a_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_viande_a_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=3;}
}


void
on_liquides_a_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=4;}
}


void
on_ingredients_a_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=5;}
}



void
on_rech_valider_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *hh_window_Rechercher;
   GtkWidget *entry2;
   GtkWidget *treeview3;
   GtkWidget *hh_rechercher_error;
   int verif;
   char text[200];
   char id[20];
   
hh_window_Rechercher=lookup_widget(button,"hh_window_Rechercher");
entry2=lookup_widget(button,"entry2");
treeview3=lookup_widget(button,"treeview3");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry2)));
verif=test_produit(id);

switch(verif)
   
{
    case 0:  
    { strcpy (text,"Identifiant n'existe pas");
    hh_rechercher_error=lookup_widget(button,("hh_rechercher_error"));
    GdkColor color;
    gdk_color_parse("red",&color);
    gtk_widget_modify_fg(hh_rechercher_error,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(hh_rechercher_error),text);
    }
    break;
    case 1:
   
    {  rechercher(treeview3, id);
       remove(treeview3);
       strcpy (text,"Identifiant existe");
       hh_rechercher_error=lookup_widget(button,("hh_rechercher_error"));
       GdkColor color;
       gdk_color_parse("green",&color);
       gtk_widget_modify_fg(hh_rechercher_error,GTK_STATE_NORMAL,&color);
       gtk_label_set_text(GTK_LABEL(hh_rechercher_error),text);
      }
    break;
    break;
}
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* type1;
gchar* nom;
gchar* id;
gchar* kg;
gchar* jour_aj;
gchar* mois_aj;
gchar* annee_aj;
gchar* jour_exp;
gchar* mois_exp;
gchar* annee_exp;
nourriture n;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter (model, &iter, path))
{
//obtention des valeurs de la ligne selectionnée
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &type1, 1, &nom, 2,&id, 3,&jour_aj, 4,&mois_aj, 5,&annee_aj, 6,&jour_aj, 7,&mois_exp, 8,&annee_exp, -1); 
// copie des valeurs dans la variable n de type nourriture pour le passer à la fonction de suppression
strcpy(n.type,type1);
strcpy(n.nom,nom);
strcpy(n.id,id);
strcpy(n.kg,kg);


//strcpy(n.date_ajout,date_ajout); 
n.date_ajout.jour=jour_aj;
n.date_ajout.mois=mois_aj;
n.date_ajout.annee=annee_aj;
n.date_exp.jour=jour_exp;
n.date_exp.mois=mois_exp;
n.date_exp.annee=annee_exp;
//strcpy(n.date_exp,date_exp);


//appel de la fonction de suppression

// mise à jour de l'affichage de la treeview
afficher(treeview);
}
}


void
on_actualiser_prod_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview2;
treeview2=lookup_widget(button,"treeview2");
afficher(treeview2);
}


void
on_hh_mail_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* hh_window_produits;
hh_window_produits=lookup_widget(button,"hh_window_produits");
gtk_widget_destroy(hh_window_produits);
GtkWidget* hh_mail;
hh_mail=create_hh_mail();
gtk_widget_show(hh_mail);

}


void
on_hh_annuler_mail_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *hh_mail;
GtkWidget *hh_window_produits;
GtkWidget *treeview2;

hh_mail=lookup_widget(button,"hh_mail");
gtk_widget_destroy(hh_mail);
hh_window_produits=create_hh_window_produits();
gtk_widget_show(hh_window_produits);
treeview2=lookup_widget(hh_window_produits,"treeview2");
afficher(treeview2);
}
//////////////////////////////////////////////////






////////////////////////////////////////////////////
void
on_hh_valider_mail_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char text[200];
char hh_mailto[50];
GtkWidget *hh_email_cmpt;
GtkWidget *text_email;

hh_email_cmpt = lookup_widget (button,"hh_email_cmpt");
strcpy(hh_mailto,gtk_entry_get_text(GTK_ENTRY(hh_email_cmpt)));
 send_email(hh_mailto,"stock");

GtkWidget *hh_mail;
hh_mail=lookup_widget(button,"hh_mail");


strcpy (text,"votre email a été envoyé");
text_email=lookup_widget(button,("text_email"));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(text_email,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(text_email),text);
}


void
on_retour_mail_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hh_mail;
GtkWidget *hh_window_produits;
GtkWidget *treeview2;

hh_mail=lookup_widget(button,"hh_mail");
gtk_widget_destroy(hh_mail);
hh_window_produits=create_hh_window_produits();
gtk_widget_show(hh_window_produits);
treeview2=lookup_widget(hh_window_produits,"treeview2");
afficher(treeview2);
}

