//Projet takuzu,Dany costa ,Ilyas SIDI-YEKHLEF, haider.c: répertoire des fonction

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>
#include <time.h>
int solution2[8][8]={1,0,1,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,1,0,1,0,1,1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,1,0,1,1,0,0,1,0,0,1};
int solution[4][4] = {0,1,1,0,0,1,0,1,1,0,1,0,1,0,0,1};
int masque[4][4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int joueur[4][4] = {0,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,1};
int joueur2 [8][8]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int masque8x8[8][8]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

// permet d'ajouter des espace dans la console, revoie des \n
void espace(void)
{
    int i;
    for (i=0;i<10;i++)// permet de faire plusieur espace
    {
        printf(" \n");
    }
}

// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console
void afficher_4x4(int Matrice[4][4]) {
    printf("        A       B       C       D\n");

    int i, j, lig = 4, col = 4;
    for (i = 0; i < lig; i++) {
        printf("%d \t", i+1);
        for (j = 0; j < col; j++) { // parcour de la Matrice en paramètre

            if (Matrice[i][j] != -1) //permet d'afficher un X(pour représenter un abasence de numéro) quand la matrice a une valeur -1
                printf("%d \t", Matrice[i][j]);
            else
                printf("x\t");
        }
        printf("\n");
    }

}

// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console
void afficher_8x8(int Matrice[8][8]) {
    printf("        A       B       C       D       E       F       G       H  \n");

    int i, j, lig = 8, col = 8;
    for (i = 0; i < lig; i++) {
        printf("%d \t", i+1);
        for (j = 0; j < col; j++) {// parcour de la Matrice en paramètre
            if (Matrice[i][j]!= -1)//permet d'afficher un X(pour représenter un abasence de numéro) quand la matrice a une valeur -1
                printf("%d \t", Matrice[i][j]);
            else
                printf("x\t");
        }
        printf("\n");

    }

}

//permet d'ajouter une valeur sur la grille de jeu,prend en paramètre Matrice_joueur: la matrice de jeu,Matrice_solution pour vérifier la si coup est bon
// renvoie la matrice joueur modifier
int  modifier4x4(int Matrice_joueur[4][4],int Matrice_solution[][4]){

    int ligne, choix,position;
    char colonne[1] = "A";
    printf("choisicer le numéro ligne\n");
    scanf("%d", &ligne);// demande du numéro de ligne
    while(ligne<1 || ligne>4)// saisi sécurisé
    {
        printf("choisisez le numéro ligne\n");
        scanf("%d", &ligne);
    }
    printf("choisiser la lettre de la colonne\n");
    scanf(" %c", colonne);// demande de la lettre de la colonne
    while ( *colonne < 'A' || *colonne >'D')// saisi sécurisé
    {
        printf("choisiser la lettre de la colonne\n");
        scanf(" %c", colonne);
    }
    printf("quelle valeur voulez vous mettre entre 0 et 1?\n");
    scanf("%d", &choix);// demande de la valeur a entré
    while(choix<0 || choix>1)// saisi sécurisé
    {
        printf("quelle valeur voulez vous mettre entre 0 et 1?\n");
        scanf("%d", &choix);
    }
    Matrice_joueur[ligne - 1][*colonne - 65] = choix;// place la valeur selon les paramètres choisis
    // utiliser pour savoir si le coup est valide mais pas correct
    position = ligne - 1 ;
    position = position*4 + *colonne - 65;
    return position;


}

//permet de savoir les coup valide mais incorecte en matrice 4x4,prend en paramètre deux entier, Matrice_joueur:la matrice de jeux,Matrice_solution: élément de comparaisont
//renvoie un affichage
void coup_correct4x4(int l,int c,int Matrice_joueur[][4],int Matrice_solution[][4]){
    if(Matrice_joueur[l][c]!=Matrice_solution[l][c])
        printf("Coup valide mais incorrect !\n");


}

//permet de savoir les coup valide mais incorecte en matrice 8x8,prend en paramètre deux entier, Matrice_joueur:la matrice de jeux,Matrice_solution: élément de comparaisont
//renvoie un affichage
void coup_correct8x8(int l,int c,int Matrice_joueur[][8],int Matrice_solution[][8]){
    if(Matrice_joueur[l][c]!=Matrice_solution[l][c])
        printf("Coup valide mais incorrect !\n");


}

//permet d'ajouter une valeur sur la grille de jeu,prend en paramètre matrice_joueur: la matrice de jeu,Matrice_solution pour vérifier la si coup est bon
// renvoie la matrice joueur modifier
void  modifier8x8(int Matrice_joueur[8][8],int Matrice_solution[][8]){

    int ligne, choix;
    char colonne[1] = "A";
    printf("choisicer le numéro ligne\n");
    scanf("%d", &ligne);// demande du numéro de ligne
    while(ligne<1 || ligne>8)// saisi sécurisé
    {
        printf("choisisez le numéro ligne\n");
        scanf("%d", &ligne);
    }
    printf("choisiser la lettre de la colonne\n");
    scanf(" %c", colonne);// demande de la lettre de la colonne
    while ( *colonne < 'A' || *colonne >'H')// saisi sécurisé
    {
        printf("choisiser la lettre de la colonne\n");
        scanf(" %c", colonne);
    }
    printf("quelle valeur voulez vous mettre entre 0 et 1?\n");
    scanf("%d", &choix);// demande de la valeur a entré
    while(choix<0 || choix>1)// saisi sécurisé
    {
        printf("quelle valeur voulez vous mettre entre 0 et 1?\n");
        scanf("%d", &choix);
    }
    Matrice_joueur[ligne - 1][*colonne - 65] = choix;// place la valeur selon les paramètres choisis
    coup_correct8x8(ligne-1,*colonne,Matrice_joueur,Matrice_solution);// utiliser pour savoir si le coup est valide mais pas correct


}

//permet de savoir si une ligne de la grille de jeu est complétement remplie,prend en parramètre Matrice_joueur,et deux entier,renvoie une variable pour savoir si la ligne est complète ou non
int ligne_complet4x4(int Matrice_joueur[][4],int l,int lig){
    int complet = 1, i;// on définit une variable de référence
    for (i = 0; i < lig; i++){
        if (Matrice_joueur[l][i] == -1)// si la matrice n'est pas complete, "complet" passe a 0
            complet = 0;
    }
    return complet;
}

//permet de savoir si une colonne de la grille de jeu est complétement remplie,prend en parramètre Matrice_joueur,et deux entier,renvoie une variable pour savoir si la colonne est complète ou non
int colonne_complet4x4(int Matrice_joueur[][4],int c,int col){
    int complet = 1, i;// on définit une variable de référence
    for (i = 0; i < col; i++){
        if (Matrice_joueur[i][c] == -1)// si la matrice n'est pas complete, "complet" passe a 0
            complet = 0;
    }
    return complet;
}

//permet de savoir si il y a autant de 0 que de 1 sur une ligne ou collone,prend en paramètre,joueur:la matrice de jeu, &vie: pour enlever une vie en cas d'erreur
//renvoie vie-1 en cas erreur et explique pourquoi
int validiter_4x4(int Matrice_joueur[4][4],int *vie) {
    int somme,somme2,n=0;
    char colonne[10]={"ABCD"};
    somme=0;
    somme2=0;
    int i, j, lig = 4, col = 4, k;
    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            somme+=Matrice_joueur[i][j];// on utilise des somme pour savoir si il y a trop de un ou 0. si somme=2, c'est que la ligne/colonne est valide
            somme2+=Matrice_joueur[j][i];
        }
        if (ligne_complet4x4(Matrice_joueur,i,4) == 1) {  // on regarde si la ligne est remplie
            if (somme < 2){
                printf("la ligne %d n'est pas valide,il y a trop de 0, il doit avoir autant de 0 que de 1\n", i + 1);
                *vie-=1;
                n=1;
            }
            else if (somme > 2) {
                printf("la ligne %d n'est pas valide,il y a trop de 1, il doit avoir autant de 0 que de 1\n", i + 1);
                *vie-=1;
                n=1;
            }
        }
        if (colonne_complet4x4(Matrice_joueur, i, 4) == 1){// on regarde si la ligne est remplie
            if (somme2<2){

                printf("la colonne %c n'est pas valide,il y a trop de 0, il doit avoir autant de 0 que de 1\n", colonne[i]);
                *vie-=1;
                n=1;
                }
            else if (somme2>2){
                printf("la colonne %c n'est pas valide,il y a trop de 1, il doit avoir autant de 0 que de 1\n", colonne[i]);
                *vie-=1;
                n=1;
                }
        }
        somme=0;// sert a réinitialiser la somme pour chaque ligne
        somme2=0;// sert a réinitialiser la somme pour chaque colonne
    }
    return n;

}

//permet de savoir si une ligne de la grille de jeu est complétement remplie,prend en parramètre Matrice_joueur,et deux entier,renvoie une variable pour savoir si la ligne est complète ou non
int ligne_complet8x8(int Matrice_joueur[][8],int l,int lig){
    int complet = 1, i;// on définit une variable de référence
    for (i = 0; i < lig; i++){
        if (Matrice_joueur[l][i] == -1)// si la matrice n'est pas complete, "complet" passe a 0
            complet = 0;
    }
    return complet;
}

//permet de savoir si une colonne de la grille de jeu est complétement remplie,prend en parramètre Matrice_joueur,et deux entier,renvoie une variable pour savoir si la colonne est complète ou non
int colonne_complet8x8(int joueur[][8],int c,int col){
    int complet = 1, i;// on définit une variable de référence
    for (i = 0; i < col; i++){
        if (joueur[i][c] == -1)// si la matrice n'est pas complete, "complet" passe a 0
            complet = 0;
    }
    return complet;
}

//permet de savoir si il y a autant de 0 que de 1 sur une ligne ou collone,prend en paramètre,joueur:la matrice de jeu, &vie: pour enlever une vie en cas d'erreur
//renvoie vie-1 en cas erreur et explique pourquoi
int validiter_8x8(int Matrice_joueur[8][8],int *vie) {
    int somme,somme2,n=0;
    char colonne[10]={"ABCDEFGH"};
    somme=0;
    somme2=0;
    int i, j, lig = 8, col = 8, k;
    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            somme += Matrice_joueur[i][j];// on utilise des somme pour savoir si il y a trop de un ou 0. si somme=4, c'est que la ligne/colonne est valide
            somme2 += Matrice_joueur[j][i];
        }
        if (ligne_complet8x8(Matrice_joueur, i, 8) == 1) {// on regarde si la ligne est remplie

            if (somme < 4) {
                printf("la ligne %d n'est pas valide,il y a trop de 0, il doit avoir autant de 0 que de 1\n",
                       i + 1);
                *vie -= 1;
                n=1;
            } else if (somme > 4) {
                printf("la ligne %d n'est pas valide,il y a trop de 1, il doit avoir autant de 0 que de 1\n",
                       i + 1);
                *vie -= 1;
                n=1;
            }
        }

        if (colonne_complet8x8(Matrice_joueur, i, 8) == 1) {// on regarde si la colonne est remplie
            if (somme2 < 4) {
                printf("la colonne %c n'est pas valide,il y a trop de 0, il doit avoir autant de 0 que de 1\n",
                       colonne[i]);
                *vie -= 1;
                n=1;
            } else if (somme2 > 4) {
                printf("la colonne %c n'est pas valide,il y a trop de 1, il doit avoir autant de 0 que de 1\n",
                       colonne[i]);
                *vie -= 1;
                n=1;
            }
        }
        somme = 0;// sert a réinitialiser la somme pour chaque ligne
        somme2 = 0;// sert a réinitialiser la somme pour chaque colonne
    }
    return n;
}

//permet de savoir si une ligne ou une collone sont pareil,prend en paramètre,:joueur: la matrice de jeu, &vie: pour enlever une vie en cas d'érreur
//renvoie vie-1 en cas d'erreur et explique pourquoi
int verif_Ligne_colonne_doublons_4x4(int Matrice_joueur[4][4], int *vie) {
    int somme,somme2,n=0;
    somme=0;
    somme2=0;
    char colonne[10]={"ABCD"};
    int i, j, lig = 4, col = 4,k,b;
    b=1;// est égale a la condition de départ de la deuxième boucle for
    for (i = 0; i < lig; i++) {
        for (k=b;k<lig;k++) {  // permet de  parcourir les indice d'une deuxième ligne pour pouvoir les comparer ensuite
            // permet aussi de d'optimiser la comparaison en ne vérifiant pas les ligne déja triater example ( on peut comparer la ligne 1et 4 mais il n'y aura pas de comparaison 4et1)
            for (j = 0; j < col; j++) {
                if (Matrice_joueur[i][j] == Matrice_joueur[k][j])// on regarde ici si les ligne sont pareil,somme représente le nombre délément en commun
                    somme += 1;
                if(Matrice_joueur[j][i] == Matrice_joueur[j][k])// on regarde ici si les colonnes sont pareil,somme2 représente le nombre délément en commun
                    somme2 += 1;


            }

            if(ligne_complet4x4(Matrice_joueur, i, 4) + ligne_complet4x4(Matrice_joueur, i, 4) == 2)// regarde si les deux ligne sont complète ou non
                if (somme == 4){// somme=4 veux dire que chauqe élément des deux ligne sont égaux
                    printf("les deux ligne  %d et %d sont égale\n",i+1, k+1);
                    vie-=1;
                    n=1;
                }

            if(colonne_complet4x4(Matrice_joueur, i, 4) + ligne_complet4x4(Matrice_joueur, i, 4) == 2)// regarde si les deux colonnes sont complète ou non
                if (somme2 == 4) {// somme=4 veux dire que chauqe élément des deux colonne sont égaux
                    printf("les deux colonne %c et %c sont égale\n", colonne[i], colonne[k]);
                    *vie-=1;
                    n=1;
                }


            somme = 0;// réinitialise pour pouvoir recommencer
            somme2 = 0;
        }
        b+=1;// augmente la condition de la deuxième boucle for après une itération de i
        }
    return n;

    }

//permet de savoir si une ligne ou une collone sont pareil,prend en paramètre,:joueur: la matrice de jeu, &vie: pour enlever une vie en cas d'érreur
//renvoie vie-1 en cas d'erreur et explique pourquoi
int verif_Ligne_colonne_doublons_8x8(int Matrice_joueur[8][8], int *vie) {
    int somme,somme2, n = 0;
    somme=0;
    somme2=0;
    char colonne[10]={"ABCDEFGH"};
    int i, j, lig = 8, col = 8,k,b;
    b=1;// est égale a la condition de départ de la deuxième boucle for
    for (i = 0; i < lig; i++) {
        for (k=b;k<lig;k++) {// permet de  parcourir les indice d'une deuxième ligne pour pouvoir les comparer ensuite
            // permet aussi de d'optimiser la comparaison en ne vérifiant pas les ligne déja triater example ( on peut comparer la ligne 1et 4 mais il n'y aura pas de comparaison 4et1)// permet de  parcourir les indice d'une deuxième pour pouvoir les comparer ensuite
            for (j = 0; j < col; j++) {
                if (Matrice_joueur[i][j] == Matrice_joueur[k][j])// on regarde ici si les ligne sont pareil,somme représente le nombre délément en commun
                    somme += 1;
                if(Matrice_joueur[j][i] == Matrice_joueur[j][k])// on regarde ici si les colonnes sont pareil,somme2 représente le nombre délément en commun
                    somme2 += 1;


            }

            if(ligne_complet8x8(Matrice_joueur, i, 8) + ligne_complet8x8(Matrice_joueur, i, 8) == 2)
                if (somme == 8) {// somme=8 veux dire que chauqe élément des deux ligne sont égaux
                    printf("les deux ligne  %d et %d sont égale\n", i + 1, k + 1);
                    *vie-=1;
                    n=1;
                }

            if(colonne_complet8x8(Matrice_joueur, i, 8) + ligne_complet8x8(Matrice_joueur, i, 8) == 2)
                if (somme2 == 8) {// somme=8 veux dire que chauqe élément des deux ligne sont égaux
                    printf("les deux colonne %c et %c sont égale\n", colonne[i], colonne[k]);
                    *vie-=1;
                    n=1;
                }


            somme = 0;// réinitialise pour pouvoir recommencer
            somme2 = 0;
        }
        b+=1;// augmente la condition de la deuxième boucle for après une itération de i
    }
    return n;


}

// créer la matrice de jeu, prend trois matrice en paramètre,solution pour la solution de la grille,masque pour le masque,joueur:la matrice de jeu
//revoie la matrice de jeu créer par le masque
int Matrice_joueur4x4(int Matrice_solution[][4], int Matrice_masque[][4], int Matrice_joueur[][4]) {
    int i, j, lig = 4, col = 4;
    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            if (Matrice_masque[i][j] == 1) { // si masque a une valeur 1, la matrice joueur va afficher la valeur de la solution au meme coordonné
                Matrice_joueur[i][j] = Matrice_solution[i][j];
            } else {// sinon matrice joueur prend -1
                Matrice_joueur[i][j] = -1;
            }
        }
    }
}

// créer la matrice de jeu, prend trois matrice en paramètre,solution pour la solution de la grille,masque pour le masque,joueur:la matrice de jeu
//revoie la matrice de jeu créer par le masque
int Matrice_joueur8x8(int Matrice_solution[][8], int Matrice_masque[][8], int joueur1[][8]) {
    int i, j, lig = 8, col = 8;
    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            if (Matrice_masque[i][j] == 1) { // si masque a une valeur 1, la matrice joueur va afficher la valeur de la solution au meme coordonné
                joueur1[i][j] = Matrice_solution[i][j];
            } else {  // sinon matrice joueur prend -1
                joueur1[i][j] = -1;
            }
        }
    }
}

//permet de savoir si trois 0 ou trois 1 sont placer d'affiler,prend en paramètre,:Matrice_joueur: la matrice de jeu, &vie: pour enlever une vie en cas d'érreur
//renvoie vie-1 en cas d'erreur et explique pourquoi
int verification_Adjacent4x4(int Matrice_joueur[][4], int *vie){
    int i,j,n=0;
    char colonne[10]={"ABCD"};
    for (i = 0; i < 4; i++)
    {
        printf("\n");
        for (j = 0; j < 4; j++){
            if(Matrice_joueur[i][j] != -1){
                if ((i == 0) && (j == 0) || (i == 3) && (j==3) ||(i == j+3) || (j == i+3))
                    printf("");
                else {
                    if ((i == 0) || (i == 3))
                        if (Matrice_joueur[i][j] == Matrice_joueur[i][j + 1] && Matrice_joueur[i][j] == Matrice_joueur[i][j - 1]) {
                            printf("Il y a trois chiffres identique en %d-%c", i, colonne[j]);
                            *vie-=1;
                            n = 1;
                        }
                        else{
                            if ((j == 0) || (j == 3)) {
                                if (Matrice_joueur[i][j] == Matrice_joueur[i + 1][j] && Matrice_joueur[i][j] == Matrice_joueur[i - 1][j]) {
                                    printf("Il y a trois chiffres identique en %d-%c", i, colonne[j]);
                                    *vie-=1;
                                    n = 1;
                                }
                            }
                            else {
                                if (Matrice_joueur[i][j] == Matrice_joueur[i][j + 1] && Matrice_joueur[i][j] == Matrice_joueur[i][j - 1]) {
                                    printf("Il y a trois chiffres identique en %d-%c", i, colonne[j]);
                                    *vie-=1;
                                    n = 1;
                                }
                                if (Matrice_joueur[i][j] == Matrice_joueur[i + 1][j] && Matrice_joueur[i][j] == Matrice_joueur[i - 1][j]) {
                                    printf("Il y a trois chiffres identique en %d-%c", i, colonne[j]);
                                    *vie-=1;
                                    n = 1;
                                }
                            }
                        }
                }
            }
        }
    }
    return n;
}

//permet de savoir si trois 0 ou trois 1 sont placer d'affiler,prend en paramètre,:Matrice_joueur: la matrice de jeu, &vie: pour enlever une vie en cas d'érreur
//renvoie vie-1 en cas d'erreur et explique pourquoi
int verification_Adjacent8x8(int joueur[][8],int *vie) {
    int i, j, n = 0;
    char colonne[10] = {"ABCD"};
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (joueur[i][j] != -1) {
                if ((i == 0) && (j == 0) || (i == 7) && (j == 7) || (i == j + 7) || (j == i + 7))
                    printf("");
                else {
                    printf("\n");
                    if ((i == 0) || (i == 7))
                        if (joueur[i][j] == joueur[i][j + 1] && joueur[i][j] == joueur[i][j - 1]) {
                            printf("Il y a trois chiffres identique en %d-%c", i, colonne[j]);
                            *vie -= 1;
                            n=1;
                        }
                        else {
                            if ((j == 0) || (j == 7)) {
                                if (joueur[i][j] == joueur[i + 1][j] && joueur[i][j] == joueur[i - 1][j]) {
                                    printf("Il y a trois chiffres identique en %d-%c", i, colonne[j]);
                                    *vie-=1;
                                    n=1;
                                }
                            } else {
                                if (joueur[i][j] == joueur[i][j + 1] && joueur[i][j] == joueur[i][j - 1]) {
                                    printf("Il y a trois chiffres identique en %d-%c", i, colonne[j]);
                                    *vie -= 1;
                                    n=1;
                                }
                                if (joueur[i][j] == joueur[i + 1][j] && joueur[i][j] == joueur[i - 1][j]) {
                                    printf("Il y a trois chiffres identique en %d-%c", i, colonne[j]);
                                    *vie -= 1;
                                    n=1;
                                }
                            }
                        }
                }
            }
        }
    }
    return n;
}

//créer manuellement un masque4x4; prend en paramètre un matrice,revoie une matrice avec les modification apliquer
void masque_manuelle4x4(int Matrice_Masque[][4])
    {
    int lig=4, col=4,i,j;
    for (i=0;i<lig;i++){
        for(j=0;j<col;j++){ // on insert les donner dans la matrice
            printf("Sasir les valeur du masque entre 0 et 1: ");
            scanf("%d", &Matrice_Masque[i][j]);
        }
    }

    }

//créer manuellement un masque8x8; prend en paramètre un matrice,revoie une matrice avec les modification apliquer
void masque_manuelle8x8(int Matrice_Masque[][8])
{
    int lig=8, col=8,i,j;
    for (i=0;i<lig;i++){
        for(j=0;j<col;j++){// on insert les donner dans la matrice
            printf("Sasir les valeur du masque entre 0 et 1: ");
            scanf("%d", &Matrice_Masque[i][j]);
        }
    }

}

// créer un masque aléatoire,prend la matrice masque en paramètre,revoie un masque générer aléatoirement
void masque_alleatoire4x4(int Matrice_Masque[][4]){
    int lig=4, col=4,i,j,k,valeur_aleatoire_1,valeur_aleatoire_2;
    valeur_aleatoire_1=0;
    valeur_aleatoire_2=0;
    k=0;
    srand(time(0));// permet d'avoir différent tirage aléatoire
    while (k<5){
        valeur_aleatoire_2= rand() % 4;// on optien une valeur entre 0 et 3
        valeur_aleatoire_1= rand() % 4;
        if (Matrice_Masque[valeur_aleatoire_1][valeur_aleatoire_2] != 1){// si les cordonné tirré ont deja été tirer, cela refait un tirage
            Matrice_Masque[valeur_aleatoire_1][valeur_aleatoire_2]=1;
            k++;
        }

    }
}

// créer un masque aléatoire,prend la matrice masque en paramètre,revoie un masque générer aléatoirement
void masque_alleatoire8x8(int Matrice_Masque[][8]){
    int lig=8, col=8,i,j,k,test1,test2;
    test1=0;
    test2=0;
    k=0;
    srand(time(0));// permet d'avoir différent tirage aléatoire
    while (k<20){
        test2=rand()%8;// on optien une valeur entre 0 et 7
        test1=rand()%8;
        if (Matrice_Masque[test1][test2]!=1){   // si les cordonnés tiré ont deja été tiré, cela refait un tirage
            Matrice_Masque[test1][test2]=1;
            k++;
        }

    }
}
void victoire(int solution1[4][4],int grille_joueur[4][4]) {
    int i, j, lig = 4, col = 4,incorect=0;

    for (i = 0; i < lig; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (solution1[i][j]!=grille_joueur[i][j])
                incorect+=1;
        }

    }
    if (incorect ==0)
        printf("gagner");


}
void victoire8x8(int Matrice_solution1[8][8],int grille_joueur[8][8]) {
    int i, j, lig = 8, col = 8,incorect=0;

    for (i = 0; i < lig; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (Matrice_solution1[i][j]!=grille_joueur[i][j])
                incorect+=1;
        }

    }
    if (incorect ==0)
        printf("gagner");


}

void resolution_matrice4x4(int joueur[][4], int solution[][4],int masque[][4]){
    int i, j, l, c, k = 0, lig = 4, col = 4;
    char r;
    srand(time(0));
    int** clone_masque = (int**) malloc(4 * sizeof(int));
    for (int i = 0; i < 4; i++)
        clone_masque[i] = malloc(4 * 4);
    for (i = 0; i < lig; i++)
    {
        for (j = 0; j < col; j++)
            clone_masque[i][j] = masque[i][j];
    }
    while (victoire_auto(solution, joueur) == 0) {
        l = rand() % 4;
        c = rand() % 4;
        if (clone_masque[l][c] == 0) {
            joueur[l][c] = rand() % 2;
            if (joueur[l][c] == solution[l][c]){
                clone_masque[l][c] = 1;
                printf("Entrer une lettre quelconque pour continuer\n");
                scanf("%c",&r);
                afficher_4x4(joueur);
                case_videOUincorrect4x4(solution,joueur);
            }
        }

    }
    free_grille2d(clone_masque,4);

}
void free_grille2d(int **grille, int c)
{
    int i;
    for (i = 0; i < c; i++) {
        free(grille[i]);
    }

    free(grille);
}

void case_videOUincorrect4x4(int solution1[4][4],int grille_joueur[4][4]) {
    int i, j, incorect = 0, lig = 4, col = 4;

    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            if (solution1[i][j] != grille_joueur[i][j])
                incorect += 1;
        }

    }
    if(incorect!=0)
        printf("Cases vides ou incorrects : %d\n",incorect);
}
void case_videOUincorrect8x8(int solution1[8][8],int grille_joueur[8][8]) {
    int i, j, incorect = 0, lig = 8, col = 8;

    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            if (solution1[i][j] != grille_joueur[i][j])
                incorect += 1;
        }

    }
    if(incorect!=0)
        printf("Cases vides ou incorrects : %d\n",incorect);
}
void resolution_matrice8x8(int joueur[][8], int solution[][8],int masque8x8[][8]){
    int i, j, l, c, r = 0, k = 0, lig = 8, col = 8;
    srand(time(0));
    int** clone_masque = (int**) malloc(lig * sizeof(int));
    for (int i = 0; i < lig; i++)
        clone_masque[i] = malloc(col * 4);
    for (i = 0; i < lig; i++)
    {
        for (j = 0; j < col; j++)
            clone_masque[i][j] = masque[i][j];
    }
    while (victoire_auto8x8(solution, joueur) == 0) {
        l = rand() % 8;
        c = rand() % 8;
        if (clone_masque[l][c] == 0) {
            joueur[l][c] = rand() % 2;
            if (joueur[l][c] == solution[l][c]){
                clone_masque[l][c] = 1;
                printf("Entrer une lettre quelconque pour continuer\n");
                scanf("%d",&r);
                afficher_8x8(joueur);
                case_videOUincorrect8x8(solution,joueur);
            }
        }

    }
    free_grille2d(clone_masque,8);

}
int victoire_auto(int solution1[4][4],int grille_joueur[4][4]) {
    int i, j, lig = 4, col = 4,incorect=0;

    for (i = 0; i < lig; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (solution1[i][j]!=grille_joueur[i][j])
                incorect+=1;
        }

    }
    if (incorect ==0){
        printf("Gagner !\n");
        return 1;
    }
    else
        return 0;
}
int victoire_auto8x8(int solution1[8][8],int grille_joueur[8][8]) {
    int i, j, lig = 8, col = 8,incorect=0;

    for (i = 0; i < lig; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (solution1[i][j]!=grille_joueur[i][j])
                incorect+=1;
        }

    }
    if (incorect ==0){
        printf("Gagner !\n");
        return 1;
    }
    else
        return 0;
}

//permet davoir un int puissance un autre int,prend en parramètre le nombre qu'on veur mettre a une puissance, et ça puissance associer. retourne le résultat
int puissance(int n,int p){
    int n_i = n;
    if(p == 0)
        n = 1;
    else{
        for(int i = p;i >= 2;i--){ // boucle qui permet d'avoir une puissace
            n = n_i*n;
        }
    }
    return n;
}

void code_binaireL(int matrice_solution[][4], int l){   //Rempli validement une ligne donné de la grille matrice_solution a partir de nombres binaire, prend matrice_solution pour modifier la ligne donné par l aussi en parametre, ne retourne donc rien //
    int code_binaire[4];
    int random;
    do{
        random = rand() % 16;  //Génere un nombre aléatoire entre 0 et 15//
        for (int i = 3; i >= 0; i--){
            if( random - puissance(2,i) >= 0){ //Si le nombre peut etre soustrait par 2 puissance (la valeur la plus haute qui est 3 dans ce cas) on met 1 dans la liste code_binaire et effectue le calcule//
                code_binaire[i] = 1;
                random -= puissance(2,i);
            }
            else
                code_binaire[i] = 0;
            matrice_solution[l][i] = code_binaire[i];
        }
    }while(verif_binaire4x4(code_binaire) == 1); //Tant que la ligne n'est pas valide on recommence//
}
int verif_binaire4x4(int code_binaire[4]){ //Vérifie si la liste binaire est valide, elle prend donc code_binaire pour le faire et retourne 1 si elle n'est pas valide,0 pour l'inverse//
    int i;
    int n = 0, somme = 0;
    for (i = 0; i < 4; i++)
    {
        somme+=code_binaire[i];        //On vérifie juste le nombre de 0 et 1 pas besoin de vérifier si il y a 3 chiffre identique car dans tout les cas il faut seulement deux 1 et 0//
    }
    if (somme < 2 || somme > 2)
        n=1;
    return n;
}
int verif_binaire8x8(int code_binaire[8]){ //Vérifie si la liste binaire est valide, elle prend donc code_binaire pour le faire et retourne 1 si elle n'est pas valide,0 pour l'inverse//
    int i;
    int n = 0, somme = 0;
    for (i = 0; i < 8; i++)
    {
        somme+=code_binaire[i];
        if ((i == 0) ||  (i == 7))                        //On vérifie si il y a autant de 0 que de 1 et si il n'y a pas 3 chiffres identique cote à cote//
            printf("");
        else {
            if (code_binaire[i] == code_binaire[i+1] && code_binaire[i] == code_binaire[i-1])
                n = 1;
        }
    }
    if (somme < 4 || somme > 4)
        n=1;
    return n;
}
void generer_matrice4x4(int matrice_solution[][4]){ //Permet de génerer un matrice ,elle prend donc en parametre matrice_solution pour generer la matrice_solution dedans, elle retourne rien car elle modifie matrice_solution a partir de son pointeur//
    srand(time(0));
    int n,r;
    for(int i = 0; i < 4; i++){
        code_binaireL(matrice_solution, i); //On genere 4 lignes valide
    }
    do{
        printf("Entrer une chiffre quelconque pour continuer :\n");
        scanf("%d",&r);
        printf(" \tA\tB\tC\tD\n");
        for(int i = 0; i < 4; i++){                         //On affiche la matrice matrice_solution a chaque fois pour montrer les modification et laisse un temp a l'utilisateur pour comprendre et observer celle-ci//
            printf("%d\t",i+1);
            for(int j = 0; j < 4; j++){
                printf("%d\t", matrice_solution[i][j]);
            }
            printf("\n");
        }
        n = 0;
        n += Gen_egaliter1et0_4x4(matrice_solution);
        n += Gen_verif_adjacent4x4(matrice_solution);    // Cela peut paraitre inutile de verifier si il y a 3 chiffres identiques en trop mais etant donné que on genere aléatoirement une nouvelle ligne ou colonne dans Gen_egaliter1et0_4x4 cela peut parfois corriger les erreurs génerer//
        n += Gen_verif_doublons_4x4(matrice_solution);
    }while(n != 0);           //Tant qu'une seule des conditions n'est pas valide on répete les modifications
    printf("Grille matrice_solution terminé !");
}
int Gen_egaliter1et0_4x4(int matrice_solution[4][4]) { // Modifie les lignes et colonnes si un la condition d'egalité des 0 et des 1 n'est pas réspecter, elle prend soltion en parametre pour modifier en cas de regle ligne ou colonne non valide//
    int sommeL=0,sommeC=0,n = 0;                // Elle retourne 1 si la condition n'est pas valide, 0 a l'inverse//
    char colonne[10] = "ABCD";
    int i, j, lig = 4, col = 4, k;
    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            sommeL+=matrice_solution[i][j];                 // Fait la somme des lignes et des colonnes puis vérifie si c'est bien égal a 2//
            sommeC+=matrice_solution[j][i];
        }
        if (sommeL < 2 || sommeL > 2){
            code_binaireL(matrice_solution,i);
            n = 1;
            printf("la ligne %d n'est pas valide, il doit avoir autant de 0 que de 1\n", i+1);
        }
        if (sommeC<2 || sommeC>2){
            code_binaireC(matrice_solution,i);                                                            //On genere une nouvelle colonne ou ligne si elle n'est pas valide//
            n = 1;
            printf("la colonne %c n'est pas valide, il doit avoir autant de 0 que de 1\n", colonne[i]);
        }
        sommeL=0;
        sommeC=0;
    }
    return n;

}
void code_binaireC(int solution[][4],int c){ //Rempli validement une colonne donné de la grille solution a partir de nombres binaire, prend solution pour modifier la ligne donné par c aussi en parametre, ne retourne donc rien //
    int code_binaire[4];
    int random;
    do{
        random = rand() % 16;                 //On genere un chiffre entre 0 et 15//
        for (int i = 3; i >= 0; i--){
            if( random - puissance(2,i) >= 0){
                code_binaire[i] = 1;
                random -= puissance(2,i);                 //Si le nombre peut etre soustrait par 2 puissance (la valeur la plus haute qui est 3 dans ce cas) on met 1 dans la liste code_binaire et effectue le calcule//
            }
            else
                code_binaire[i] = 0;
            solution[i][c] = code_binaire[i];
        }
    }while(verif_binaire4x4(code_binaire) == 1);
}
int Gen_verif_adjacent4x4(int matrice_solution[][4]){      //Vérifie pour chaque case si elle est entouré de deux chiffres identiques, si oui on inverse le chiffre.Prend matrice_solution en parametre pour se faire et retourne 1 si la conditon n'est pas validé//
    int i,j,n=0;
    char colonne[10] = "ABCD";
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++){
            if ((i == 0) && (j == 0) || (i == 3) && (j==3) || (i == j+3) || (j == i+3))            //On ne prend pas en compte les coins car il ne peut y avoir 3 chiffres identiques
                printf("");
            else {
                if ((i == 0) || (i == 3))   //Si on est tout en haut ou en bas de la matrice on vérifie qu'à gauche et à droite//
                    if (matrice_solution[i][j] == matrice_solution[i][j + 1] && matrice_solution[i][j] == matrice_solution[i][j - 1]) {
                        inverser(i, j, matrice_solution);
                        n = 1;
                        printf("Il y a trois chiffres identique en %d-%c\n", i, colonne[j]);
                    }
                    else{
                        if ((j == 0) || (j == 3)) {    //Si on est tout à gauche ou à droite de la matrice on vérifie qu'en haut et en bas//
                            if (matrice_solution[i][j] == matrice_solution[i + 1][j] && matrice_solution[i][j] == matrice_solution[i - 1][j]){
                                inverser(i, j, matrice_solution);
                                n = 1;
                                printf("Il y a trois chiffres identique en %d-%c\n", i, colonne[j]);
                            }
                        }
                        else {  //Sinon on vérifie de tout les cotés//
                            if (matrice_solution[i][j] == matrice_solution[i][j + 1] && matrice_solution[i][j] == matrice_solution[i][j - 1]){
                                inverser(i, j, matrice_solution);
                                n = 1;
                                printf("Il y a trois chiffres identique en %d-%c\n", i, colonne[j]);
                            }
                            if (matrice_solution[i][j] == matrice_solution[i + 1][j] && matrice_solution[i][j] == matrice_solution[i - 1][j]){
                                inverser(i, j, matrice_solution);
                                n = 1;
                                printf("Il y a trois chiffres identique en %d-%c\n", i, colonne[j]);
                            }
                        }
                    }
            }
        }
    }
    return n;
}
void inverser(int i,int j, int matrice_solution[][4]){ //Inverse les 0 en 1 et les 1 en 0 dans la matrice_solution et la prend donc en parametre,elle retourne donc rien//
    if (matrice_solution[i][j] == 0)
        matrice_solution[i][j] = 1;
    else
        matrice_solution[i][j] = 0;
}
int Gen_verif_doublons_4x4(int matrice_solution[4][4]) {   //Verifie les lignes et les colonnes identiques, si une d'entre elle est identique elle est modifier.Prend matrice_solution en parametre pour se faire et retourne 1 si la conditon n'est pas validé//
    int sommeL=0,sommeC=0,n=0;
    int i, j, lig = 4, col = 4,k,b=1;
    char colonne[10] = "ABCD";
    for (i = 0; i < lig; i++) {
        for (k=b;k<lig;k++) {
            for (j = 0; j < col; j++) {
                if (matrice_solution[i][j] == matrice_solution[k][j])          //On compare une ligne ou colonne a toute les autres, si on passe a la ligne suivante on ne la compare pas avec la ligne précedente ,on reduit donc le nombre d'itération de la boucle k avec b//
                    sommeL += 1;
                if(matrice_solution[j][i] == matrice_solution[j][k])
                    sommeC += 1;


            }

            if (sommeL == 4){
                code_binaireL(matrice_solution, k);
                n = 1;
                printf("les deux ligne  %d et %d sont égale\n",i+1, k+1);
            }
            if (sommeC == 4){
                code_binaireL(matrice_solution, k);                          //On genere une nouvelle colonne ou ligne si elle n'est pas valide//
                n = 1;
                printf("les deux colonne %c et %c sont égale\n",colonne[i],colonne[k]);
            }


            sommeL = 0;
            sommeC = 0;
        }
        b+=1;
    }
    return n;
}
void code_binaireL8x8(int matrice_solution[][8], int l){   //Rempli validement une ligne donné de la grille matrice_solution a partir de nombres binaire, prend matrice_solution pour modifier la ligne donné par l aussi en parametre, ne retourne donc rien //
    int code_binaire[8];
    int random;
    do{
        random = rand() % 257;  //Génere un nombre aléatoire entre 0 et 256//
        for (int i = 7; i >= 0; i--){
            if( random - puissance(2,i) >= 0){ //Si le nombre peut etre soustrait par 2 puissance (la valeur la plus haute qui est 7 dans ce cas) on met 1 dans la liste code_binaire et effectue le calcule//
                code_binaire[i] = 1;
                random -= puissance(2,i);
            }
            else
                code_binaire[i] = 0;
            matrice_solution[l][i] = code_binaire[i];
        }
    }while(verif_binaire8x8(code_binaire) == 1); //Tant que la ligne n'est pas valide on recommence//
}
void generer_matrice8x8(int matrice_solution[][8]){ //Permet de génerer un matrice ,elle prend donc en parametre matrice_solution pour generer la matrice_solution dedans, elle retourne rien car elle modifie matrice_solution a partir de son pointeur//
    srand(time(0));
    int n,r;
    for(int i = 0; i < 8; i++){
        code_binaireL8x8(matrice_solution, i); //On genere 8 lignes valide
    }
    do{
        printf("Entrer une chiffre quelconque pour continuer :\n");
        scanf("%d",&r);
        printf(" \tA\tB\tC\tD\tE\tF\tG\tH\n");
        for(int i = 0; i < 8; i++){                         //On affiche la matrice matrice_solution a chaque fois pour montrer les modification et laisse un temp a l'utilisateur pour comprendre et observer celle-ci//
            printf("%d\t",i+1);
            for(int j = 0; j < 8; j++){
                printf("%d\t", matrice_solution[i][j]);
            }
            printf("\n");
        }
        n = 0;
        n += Gen_egaliter1et0_8x8(matrice_solution);
        n += Gen_verif_adjacent_8x8(matrice_solution);
        n += Gen_verif_doublons_8x8(matrice_solution);
    }while(n != 0);           //Tant qu'une seule des conditions n'est pas valide on répete les modifications
    printf("Grille matrice_solution terminé !");
}
int Gen_egaliter1et0_8x8(int matrice_solution[][8]) { // Modifie les lignes et colonnes si un la condition d'egalité des 0 et des 1 n'est pas réspecter, elle prend soltion en parametre pour modifier en cas de regle ligne ou colonne non valide//
    int sommeL=0,sommeC=0,n = 0;                // Elle retourne 1 si la condition n'est pas valide, 0 a l'inverse//
    char colonne[10] = "ABCDEFGH";
    int i, j, lig = 8, col = 8, k;
    for (i = 0; i < lig; i++) {
        for (j = 0; j < col; j++) {
            sommeL+=matrice_solution[i][j];                 // Fait la somme des lignes et des colonnes puis vérifie si c'est bien égal a 2//
            sommeC+=matrice_solution[j][i];
        }
        if (sommeL < 8 || sommeL > 8){
            code_binaireL8x8(matrice_solution,i);
            n = 1;
            printf("la ligne %d n'est pas valide, il doit avoir autant de 0 que de 1\n", i+1);
        }
        if (sommeC<8 || sommeC>8){
            code_binaireC8x8(matrice_solution,i);                                                            //On genere une nouvelle colonne ou ligne si elle n'est pas valide//
            n = 1;
            printf("la colonne %c n'est pas valide, il doit avoir autant de 0 que de 1\n", colonne[i]);
        }
        sommeL=0;
        sommeC=0;
    }
    return n;

}
void code_binaireC8x8(int solution[][8],int c){ //Rempli validement une colonne donné de la grille solution a partir de nombres binaire, prend solution pour modifier la ligne donné par c aussi en parametre, ne retourne donc rien //
    int code_binaire[8];
    int random;
    do{
        random = rand() % 257;                 //On genere un chiffre entre 0 et 256//
        for (int i = 7; i >= 0; i--){
            if( random - puissance(2,i) >= 0){
                code_binaire[i] = 1;
                random -= puissance(2,i);                 //Si le nombre peut etre soustrait par 2 puissance (la valeur la plus haute qui est 7 dans ce cas) on met 1 dans la liste code_binaire et effectue le calcule//
            }
            else
                code_binaire[i] = 0;
            solution[i][c] = code_binaire[i];
        }
    }while(verif_binaire8x8(code_binaire) == 1);
}
int Gen_verif_adjacent_8x8(int matrice_solution[][8]){      //Vérifie pour chaque case si elle est entouré de deux chiffres identiques, si oui on inverse le chiffre.Prend matrice_solution en parametre pour se faire et retourne 1 si la conditon n'est pas validé//
    int i,j,n=0;
    char colonne[10] = "ABCDEFGH";
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++){
            if ((i == 0) && (j == 0) || (i == 7) && (j==7) || (i == j+7) || (j == i+7))            //On ne prend pas en compte les coins car il ne peut y avoir 3 chiffres identiques
                printf("");
            else {
                if ((i == 0) || (i == 7))   //Si on est tout en haut ou en bas de la matrice on vérifie qu'à gauche et à droite//
                    if (matrice_solution[i][j] == matrice_solution[i][j + 1] && matrice_solution[i][j] == matrice_solution[i][j - 1]) {
                        inverser8x8(i, j, matrice_solution);
                        n = 1;
                        printf("Il y a trois chiffres identique en %d-%c\n", i, colonne[j]);
                    }
                    else{
                        if ((j == 0) || (j == 7)) {    //Si on est tout à gauche ou à droite de la matrice on vérifie qu'en haut et en bas//
                            if (matrice_solution[i][j] == matrice_solution[i + 1][j] && matrice_solution[i][j] == matrice_solution[i - 1][j]){
                                inverser8x8(i, j, matrice_solution);
                                n = 1;
                                printf("Il y a trois chiffres identique en %d-%c\n", i, colonne[j]);
                            }
                        }
                        else {  //Sinon on vérifie de tout les cotés//
                            if (matrice_solution[i][j] == matrice_solution[i][j + 1] && matrice_solution[i][j] == matrice_solution[i][j - 1]){
                                inverser8x8(i, j, matrice_solution);
                                n = 1;
                                printf("Il y a trois chiffres identique en %d-%c\n", i, colonne[j]);
                            }
                            if (matrice_solution[i][j] == matrice_solution[i + 1][j] && matrice_solution[i][j] == matrice_solution[i - 1][j]){
                                inverser8x8(i, j, matrice_solution);
                                n = 1;
                                printf("Il y a trois chiffres identique en %d-%c\n", i, colonne[j]);
                            }
                        }
                    }
            }
        }
    }
    return n;
}
void inverser8x8(int i,int j, int matrice_solution[][8]){ //Inverse les 0 en 1 et les 1 en 0 dans la matrice_solution et la prend donc en parametre,elle retourne donc rien//
    if (matrice_solution[i][j] == 0)
        matrice_solution[i][j] = 1;
    else
        matrice_solution[i][j] = 0;
}
int Gen_verif_doublons_8x8(int matrice_solution[][8]) {   //Verifie les lignes et les colonnes identiques, si une d'entre elle est identique elle est modifier.Prend matrice_solution en parametre pour se faire et retourne 1 si la conditon n'est pas validé//
    int sommeL=0,sommeC=0,n=0;
    int i, j, lig = 8, col = 8,k,b=1;
    char colonne[10] = "ABCDEFGH";
    for (i = 0; i < lig; i++) {
        for (k=b;k<lig;k++) {
            for (j = 0; j < col; j++) {
                if (matrice_solution[i][j] == matrice_solution[k][j])          //On compare une ligne ou colonne a toute les autres, si on passe a la ligne suivante on ne la compare pas avec la ligne précedente ,on reduit donc le nombre d'itération de la boucle k avec b//
                    sommeL += 1;
                if(matrice_solution[j][i] == matrice_solution[j][k])
                    sommeC += 1;


            }

            if (sommeL == 8){
                code_binaireL(matrice_solution, k);
                n = 1;
                printf("les deux ligne  %d et %d sont égale\n",i+1, k+1);
            }
            if (sommeC == 8){
                code_binaireL(matrice_solution, k);                          //On genere une nouvelle colonne ou ligne si elle n'est pas valide//
                n = 1;
                printf("les deux colonne %c et %c sont égale\n",colonne[i],colonne[k]);
            }


            sommeL = 0;
            sommeC = 0;
        }
        b+=1;
    }
    return n;
}