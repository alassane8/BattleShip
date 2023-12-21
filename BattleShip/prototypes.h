#ifndef PROTOTYPES_H
#define PROTOTYPES_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void gotoligcol(int lig, int col);

void menu(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);

void rules(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);

void initialisation_matrice(unsigned char** mat, unsigned char** mat_ia1);

void decors();
void decors1();
void display_boat_decoration();
void boat_decoration_main();
void boat_decoration_rules();
void boat_decoration_load();
void boat_decoration_menu();
void boats_decoration_exit();
void boats_decoration_winner();
void boats_decoration_save1();
void boats_decoration_save2();

void placement_bateaux(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void placement_bateaux_aleatoire(unsigned char ** mat);
void placement_bateaux_aleatoire1(unsigned char ** mat_ia1);

void jouer(unsigned char ** mat, unsigned char ** mat_ia1, int *a, char *pseudo, int w, int choix,unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);

void tirer(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void tirer_aleatoirement_matelot(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void tirer_aleatoirement_caporal_chef(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void tirer_aleatoirement_amiral(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
void tir_aerien(unsigned char ** mat_ia1);

void fumigene(unsigned char ** mat_ia1);

void mode_visible(unsigned char ** mat_ia1);
void mode_visible_desactive(unsigned char ** mat_ia1);

void choix_chargement_partie(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo,int w, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
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

int game_over(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);
int game_over_ia(unsigned char ** mat, unsigned char ** mat_ia1, int *a , char *pseudo, int choix, unsigned char ** mat_bis, unsigned char ** mat_ia1_bis);

int aircraft_carrier(char aircraftcarrier);
int cruisers1(char cruisers1);
int cruisers2(char cruisers2);
int destroyers1(char destroyers1);
int destroyers2(char destroyers2);
int destroyers3(char destroyers3);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif