#include<gtk/gtk.h>

typedef struct
{
int jour;
int mois ;
int annee;
}date;


typedef struct
{
char id[50];
char type[50];
char nom[50];
date date_exp;
date date_ajout;
char kg[10];
}nourriture;

void ajouter(nourriture n);
int modifier(nourriture n);
int supprimer(char id[]);
int test_produit(char *id1[]);
int test_nom(char *nom1[]);
void rechercher(GtkWidget *liste,char id[]);
void afficher(GtkWidget *liste);
void rupture(GtkWidget *liste);
int saisie_nom(char m[]);
int saisie_kg(char k[]);

void hh_send_email(char to[],char idem[] );
static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp);
struct upload_status{
int lines_read;};

