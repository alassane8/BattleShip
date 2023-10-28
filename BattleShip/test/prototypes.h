#ifndef PROTOTYPES_H
#define PROTOTYPES_H


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void gotoligcol(int lig, int col);

void menu(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);

void initialisation_matrice(unsigned char** mat, unsigned char** mat_ia1);

void decors();
void decors1();

void placement_bateaux(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo);
void placement_bateaux_aleatoire(unsigned char ** mat);
void placement_bateaux_aleatoire1(unsigned char ** mat_ia1);

void jouer(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo, int w, int choix,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);

void tirer(unsigned char ** mat_ia1, char *pseudo);
void tirer_aleatoirement_matelot(unsigned char **  mat ,int compteur_tour);
void tirer_aleatoirement_caporal_chef(unsigned char **  mat ,int compteur_tour);
void tirer_aleatoirement_amiral(unsigned char **  mat ,int compteur_tour);

void fumigene(unsigned char ** mat_ia1, int compteur_tour);

void tir_aerien(unsigned char ** mat_ia1);

void mode_visible(unsigned char ** mat_ia1);
void mode_visible_desactive(unsigned char ** mat_ia1);

void choix_chargement_partie(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);

void affichage_matrices_fichiers(unsigned char ** mat, unsigned char ** mat_ia1);

void sauvegarde_matrices(unsigned char ** mat, unsigned char ** mat_ia1,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void sauvegarde(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo, int w,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void sauvegarder_partie(unsigned char ** mat, int choix);
void sauvegarder_partie1(unsigned char ** mat_ia1, int choix);

void chargement_matrices (unsigned char ** mat, unsigned char ** mat_ia1,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void charger_partie(unsigned char ** mat);
void charger_partie1(unsigned char ** mat_ia1);
void charger_partie1_0(unsigned char ** mat);
void charger_partie2(unsigned char ** mat_ia1);
void charger_partie2_0(unsigned char ** mat);
void charger_partie3(unsigned char ** mat_ia1);

int vainqueur_joueur(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
int vainqueur_ia(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif