//Projet takuzu,Dany costa ,Ilyas SIDI-YEKHLEF, haider.h: répertoire des fonctions lister(pour les appeller dans le main)

#ifndef TAKUSU_HEADER_H
#define TAKUSU_HEADER_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void espace(void);

int modifier4x4(int Matrice_joueur[4][4],int Matrice_solution[][4]);
void modifier8x8(int test[8][8],int solution[][8]);
void afficher_4x4(int solution[4][4]);
void afficher_8x8(int solution[8][8]);
int validiter_4x4(int test[4][4], int *vie);
int validiter_8x8(int test[8][8],int *vie);
int verif_Ligne_colonne_doublons_4x4(int Matrice_joueur[4][4], int *vie);
int verif_Ligne_colonne_doublons_8x8(int Matrice_joueur[8][8], int *vie);
int Matrice_joueur4x4(int Matrice_solution[][4], int Matrice_masque[][4], int Matrice_joueur[][4]);
int Matrice_joueur8x8(int Matrice_solution[][8], int Matrice_masque[][8], int joueur1[][8]);
void victoire(int solution[4][4],int grille_joueur[4][4]);
int ligne_complet4x4(int joueur[][4],int l,int lig);
int colonne_complet4x4(int joueur[][4],int c,int col);
int colonne_complet8x8(int joueur[][8],int c,int col);
int ligne_complet8x8(int joueur[][8],int c,int col);
int verification_Adjacent4x4(int Matrice_joueur[][4], int *vie);
int verification_Adjacent8x8(int joueur[][8],int *vie);
void masque_manuelle4x4(int masque[4][4]);
void masque_manuelle8x8(int Matrice_Masque[][8]);
void masque_alleatoire8x8(int Matrice_Masque[][8]);
void masque_alleatoire4x4(int Matrice_Masque[][4]);
void coup_correct4x4(int l,int c,int joueur[][4],int solution[][4]);
void coup_correct8x8(int l,int c,int Matrice_joueur[][8],int Matrice_solution[][8]);
void resolution_matrice4x4(int joueur[][4], int solution[][4],int masque[][4]);
void resolution_matrice8x8(int joueur2[][8], int solution2[][8],int masque8x8[][8]);
void free_grille2d(int **grille, int c);
void case_videOUincorrect4x4(int solution1[4][4],int grille_joueur[4][4]);
int victoire_auto(int solution1[4][4],int grille_joueur[4][4]);
int victoire_auto8x8(int solution1[8][8],int grille_joueur[8][8]);


void code_binaireL(int matrice_solution[][4], int l);
void code_binaireC(int solution[][4],int c);
int puissance(int n,int p);
int verif_binaire4x4(int code_binaire[4]);
void generer_matrice4x4(int matrice_solution[][4]);
int Gen_egaliter1et0_4x4(int test[4][4]);
void inverser(int i,int j, int matrice_solution[][4]);
int Gen_verif_adjacent4x4(int matrice_solution[][4]);
int Gen_verif_doublons_4x4(int matrice_solution[4][4]);
int Gen_verif_doublons_8x8(int matrice_solution[][8]);
void inverser8x8(int i,int j, int matrice_solution[][8]);
int Gen_verif_adjacent_8x8(int matrice_solution[][8]);
void code_binaireC8x8(int solution[][8],int c);
int Gen_egaliter1et0_8x8(int matrice_solution[][8]);
void code_binaireL8x8(int matrice_solution[][8], int l);
void generer_matrice8x8(int matrice_solution[][8]);
#endif //TAKUSU_HEADER_H