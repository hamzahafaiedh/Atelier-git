#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <curl/curl.h>

#define from "gestionstockhamza2022@gmail.com"
#define pw "gestion@123"


static const char *payload_text[] = {

  "To: " "administration" "\r\n",
  "From: " "agent du stock" "\r\n",
  "Cc: " "rupture stock" "\r\n",
  "Subject: il y a une rupture dans le stock\r\n",
  "\r\n",
};

char idemail[2][10] = {""};
int j=0;
/*
struct upload_status {
  int lines_read;
};*/

  char flag[100];
static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
  struct upload_status *upload_ctx = (struct upload_status *)userp;
  const char *data;

  if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
    return 0;
  }
if (j == 5){
  
    strcpy(flag,"merci de visiter le ");
    strcat(flag,idemail[0]);
    strcat(flag, " pour analyser les produits en rupture.\r\n");
  payload_text[5] = flag;
  }
if (j == 6){
  payload_text[6] = NULL;}
  data = payload_text[j];
  if(data) {
    size_t len = strlen(data);
    memcpy(ptr, data, len);
    upload_ctx->lines_read++;
    j++;

    return len;
  }

  return 0;
}

void send_email(char to[],char idem[] )
{
strcpy(idemail[0],idem);
j=0;
  CURL *curl;
  CURLcode res = CURLE_OK;
  struct curl_slist *recipients = NULL;
  struct upload_status upload_ctx;
  upload_ctx.lines_read = 0;

  curl = curl_easy_init();
  if(curl) {

    curl_easy_setopt(curl, CURLOPT_USERNAME, from);
    curl_easy_setopt(curl, CURLOPT_PASSWORD, pw);

    curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");

    curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);

    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);

    recipients = curl_slist_append(recipients, to);

    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

    curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
    curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
    else


    curl_slist_free_all(recipients);

    curl_easy_cleanup(curl);
  }
}


//////////////////////////////////////////////////////////////////////////////////////////
enum
{
	ETYPE,
	ENOM,
	EID,
	EKG,
	EJOUR_AJ,
	EMOIS_AJ,
	EJANNEE_AJ,
	EJOUR_EXP,
	EMOIS_EXP,
	EANNEE_EXP,
        COLUMNS,
};


///////////////////////////////////////////////////////////////////////////////////////////

void ajouter(nourriture n)
{
  //  char id[50];
   // char type[50];
   // char nom[50];
   // date date_exp,date_ajout;
    //char kg[10];
FILE *f;
f=fopen("utilisateur.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %d %d %d %d %d %d \n",n.type,n.nom,n.id,n.kg,n.date_ajout.jour,n.date_ajout.mois,n.date_ajout.annee,n.date_exp.jour,n.date_exp.mois,n.date_exp.annee);
fclose(f);
}

}



/////////////////////////////////////////////////////////////////////////////////////////


int modifier(nourriture n)
{
FILE*f;
FILE*f1;
char id1[20];
  char type[30];
  char nom[30];
  int jour_aj;
  int mois_aj;
  int annee_aj;
  int jour_exp;
  int mois_exp;
  int annee_exp;
  char kg[10];

f=fopen("utilisateur.txt","r");
f1=fopen("nouveau.txt","w+");

while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d\n",type,nom,id1,kg,&jour_aj,&mois_aj,&annee_aj,&jour_exp,&mois_exp,&annee_exp)!=EOF)
{
if(strcmp(n.id,id1)==0)
{
fprintf(f1,"%s %s %s %s %d %d %d %d %d %d\n",n.type,n.nom,n.id,n.kg,n.date_ajout.jour,n.date_ajout.mois,n.date_ajout.annee,n.date_exp.jour,n.date_exp.mois,n.date_exp.annee);
}
else 
{
fprintf(f1,"%s %s %s %s %d %d %d %d %d %d\n",type,nom,id1,kg,jour_aj,mois_aj,annee_aj,jour_exp,mois_exp,annee_exp);
}
}

fclose(f);
fclose(f1);

remove("utilisateur.txt");
rename("nouveau.txt","utilisateur.txt");
return 1;
}



/////////////////////////////////////////////////////////////////////////////////////////////////


int supprimer(char id[])
{
  nourriture n;
FILE *f;
FILE *g;
f=fopen("utilisateur.txt","r");
g=fopen("temp.txt","a+");

if (f==NULL || g==NULL )
	return;
else
{
while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d\n",n.nom,n.type,n.id,&n.kg,&n.date_ajout.jour,&n.date_ajout.mois,&n.date_ajout.annee,&n.date_exp.jour,&n.date_exp.mois,&n.date_exp.annee)!=EOF)
{
if( strcmp(n.id,id)!=0)
{
fprintf(g,"%s %s %s %s %d %d %d %d %d %d\n",n.nom,n.type,n.id,n.kg,n.date_ajout.jour,n.date_ajout.mois,n.date_ajout.annee,n.date_exp.jour,n.date_exp.mois,n.date_exp.annee);
}
}
}
fclose(f);
fclose(g);
remove("utilisateur.txt");
rename("temp.txt","utilisateur.txt");
return 1;
}



////////////////////////////////////////////////////////////////////////////////////////////


void rechercher(GtkWidget *liste,char id1[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id[20];
  char type[30];
  char nom[30];
  int jour_aj;
  int mois_aj;
  int annee_aj;
  int jour_exp;
  int mois_exp;
  int annee_exp;
  char kg[10];
store=NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" kg",renderer,"text",EKG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

//////////////
renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" jour_aj",renderer,"text",EJOUR_AJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" mois_aj",renderer,"text",EMOIS_AJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" annee_aj",renderer,"text",EJANNEE_AJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" jour_exp",renderer,"text",EJOUR_EXP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" mois_exp",renderer,"text",EMOIS_EXP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" annee_exp",renderer,"text",EANNEE_EXP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
/////////////////////////////

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f=fopen("utilisateur.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("utilisateur.txt","a+");
   while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d\n",type,nom,id,kg,&jour_aj,&mois_aj,&annee_aj,&jour_exp,&mois_exp,&annee_exp)!= EOF)
{
 if(strcmp(id,id1)==0)                  
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,ETYPE,type,ENOM,nom,EID,id,EKG,kg,EJOUR_AJ,jour_aj,EMOIS_AJ,mois_aj,EJANNEE_AJ,annee_aj,EJOUR_EXP,jour_exp,EMOIS_EXP,mois_exp,EANNEE_EXP,annee_exp,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

}



///////////////////////////////////////////////////////////////////////////////////////////

void  afficher(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id[20];
  char type[30];
  char nom[30];
  int jour_aj;
  int mois_aj;
  int annee_aj;
  int jour_exp;
  int mois_exp;
  int annee_exp;
  char kg[10];
  store=NULL ;

FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" kg",renderer,"text",EKG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

//////////////
renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" jour_aj",renderer,"text",EJOUR_AJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" mois_aj",renderer,"text",EMOIS_AJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" annee_aj",renderer,"text",EJANNEE_AJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" jour_exp",renderer,"text",EJOUR_EXP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" mois_exp",renderer,"text",EMOIS_EXP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" annee_exp",renderer,"text",EANNEE_EXP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
/////////////////////////////

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f=fopen("utilisateur.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("utilisateur.txt","a+");
   while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d\n",type,nom,id,kg,&jour_aj,&mois_aj,&annee_aj,&jour_exp,&mois_exp,&annee_exp)!= EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ETYPE,type,ENOM,nom,EID,id,EKG,kg,EJOUR_AJ,jour_aj,EMOIS_AJ,mois_aj,EJANNEE_AJ,annee_aj,EJOUR_EXP,jour_exp,EMOIS_EXP,mois_exp,EANNEE_EXP,annee_exp,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

}



////////////////////////////////////////////////////////////////////////////////////////


void rupture(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
  char id[20];
  char type[30];
  char nom[30];
  int jour_aj;
  int mois_aj;
  int annee_aj;
  int jour_exp;
  int mois_exp;
  int annee_exp;
  char kg[10];
  float kgf;
store=NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" kg",renderer,"text",EKG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

//////////////
renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" jour_aj",renderer,"text",EJOUR_AJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" mois_aj",renderer,"text",EMOIS_AJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" annee_aj",renderer,"text",EJANNEE_AJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" jour_exp",renderer,"text",EJOUR_EXP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" mois_exp",renderer,"text",EMOIS_EXP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer =gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" annee_exp",renderer,"text",EANNEE_EXP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
/////////////////////////////

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f=fopen("utilisateur.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("utilisateur.txt","a+");
   while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d\n",type,nom,id,kg,&jour_aj,&mois_aj,&annee_aj,&jour_exp,&mois_exp,&annee_exp)!= EOF)
{
 kgf=atof(kg);
 if(kgf<5)                  
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,ETYPE,type,ENOM,nom,EID,id,EKG,kg,EJOUR_AJ,jour_aj,EMOIS_AJ,mois_aj,EJANNEE_AJ,annee_aj,EJOUR_EXP,jour_exp,EMOIS_EXP,mois_exp,EANNEE_EXP,annee_exp,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

/////////////////////////////////////////////////////////////////////////////////////////

int test_produit(char *id1[])
{
FILE *f=NULL;
    nourriture n;

    f = fopen("utilisateur.txt","r");
    while (fscanf(f,"%s %s %s %s %d %d %d %d %d %d\n",n.nom,n.type,n.id,&n.kg,&n.date_ajout.jour,&n.date_ajout.mois,&n.date_ajout.annee,&n.date_exp.jour,&n.date_exp.mois,&n.date_exp.annee)!=EOF)
	{
            if (strcmp(n.id,id1)==0)
		return 1;   //id existe deja 
	}	
fclose(f);
return 0;
}



//////////////////////////////////////////////////////////////////////////////////////////

int saisie_nom(char n[50])
{ int i;int a = 0;
for(i=0;i<strlen(n);i++)
{if ((n[i]!='a')&&(n[i]!='b')&&(n[i]!='c')&&(n[i]!='d')&&(n[i]!='e')&&(n[i]!='f')&&(n[i]!='g')&&(n[i]!='h')&&(n[i]!='i')&&(n[i]!='j')&&(n[i]!='k')&&(n[i]!='l')&&(n[i]!='m')&&(n[i]!='n')&&(n[i]!='o')&&(n[i]!='p')&&(n[i]!='q')&&(n[i]!='r')&&(n[i]!='s')&&(n[i]!='t')&&(n[i]!='u')&&(n[i]!='v')&&(n[i]!='w')&&(n[i]!='x')&&(n[i]!='y')&&(n[i]!='z')&&(n[i]!='A')&&(n[i]!='B')&&(n[i]!='C')&&(n[i]!='D')&&(n[i]!='E')&&(n[i]!='F')&&(n[i]!='G')&&(n[i]!='H')&&(n[i]!='I')&&(n[i]!='J')&&(n[i]!='K')&&(n[i]!='L')&&(n[i]!='M')&&(n[i]!='N')&&(n[i]!='O')&&(n[i]!='P')&&(n[i]!='Q')&&(n[i]!='R')&&(n[i]!='S')&&(n[i]!='T')&&(n[i]!='U')&&(n[i]!='V')&&(n[i]!='W')&&(n[i]!='X')&&(n[i]!='Y')&&(n[i]!='Z'))
{a=1;
}
}
   if ( a == 0 ) return 1;
    else return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

int saisie_kg(char k[50])
{ int i;int a=0;
for(i=0;i<strlen(k);i++)

{if ((k[i]!='0')&&(k[i]!='1')&&(k[i]!='2')&&(k[i]!='3')&&(k[i]!='4')&&(k[i]!='5')&&(k[i]!='6')&&(k[i]!='7')&&(k[i]!='8')&&(k[i]!='9'))
a=1;
}

   if ( a == 0 ) return 1;
    else return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

int test_nom(char *nom1[])
{
FILE *f=NULL;
    nourriture n;

    f = fopen("utilisateur.txt","r");
    while (fscanf(f,"%s %s %s %s %d %d %d %d %d %d\n",n.nom,n.type,n.id,&n.kg,&n.date_ajout.jour,&n.date_ajout.mois,&n.date_ajout.annee,&n.date_exp.jour,&n.date_exp.mois,&n.date_exp.annee)!=EOF)
	{
            if (strcmp(n.nom,nom1)==0)
		return 1;   //id existe deja 
	}	
fclose(f);
return 0;
}

