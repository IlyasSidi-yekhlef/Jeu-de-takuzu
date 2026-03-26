//Projet takuzu,Dany costa ,Ilyas SIDI-YEKHLEF, main: accueil le menu



#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "header.h"
#include "header.c"



int main()
{
    int choix;
    int vie;
    vie = 3;
    printf("Bienvenue, pret a jouer au takusu? \n");
    printf("Saisisez une tache : \n");
    printf("1) résoudre une grille \n 2) laisser l'odinateur résoudre une grille \n 3) Génerer une grille\n");
    scanf("%d", &choix); // on affiche la présentation du menu
    while (choix < 1 || choix > 3)// saisie sécurier pour le premier menu
    {
        printf("Saisisez une tache entre celle ci-dessous : \n");
        printf("1) résoudre une grille \n 2) laisser l'odinateur résoudre une grille \n 3) Génerer une grille\n");
        scanf("%d", &choix);

    }
    switch (choix) {//permet de naviguer dans les choix du menu
        case 1: {// second menu après avoir choisir l'option "résoudre une grille"

            espace();// permet d'ajouter des espace dans la console, revoie des \n
            int choix_grille;
            printf("choisicer la taille de la grille\n");
            printf("4) grille 4x4 \n 5) grille 8x8 \n");
            scanf("%d", &choix_grille);
            while (choix_grille < 4 || choix_grille > 5) {// saisie sécurisé
                printf("choisicer la taille de la grille entre les option si-dessous\n");
                printf("4) grille 4x4 \n 5) grille 8x8 \n");
                scanf("%d", &choix_grille);
            }
            switch (choix_grille) {// permet de naviguer dans le choix des grille
                case 4:
                {// troisième menu après avoie selectionner l'option "4) grille 4x4"
                    // toute les matrice utiliser ici sont de dimention 4x4

                    espace();// permet d'ajouter des espace dans la console, revoie des \n
                    int choix_option;//initialisation de la variable pour choisir une option
                    printf("choisisez une option\n");
                    printf("6) Sasir manuellement un masque`\n 7)Générer automatiquent un masque\n 8)jouer\n");
                    scanf("%d", &choix_option);// affichage du troisième menu
                    while (choix_option < 6 || choix_option > 8) // saisi sécurisé
                    {
                        printf("choisisez une option si dessous\n");
                        printf("6) Sasir manuellement un masque`\n 7)Générer automatiquent un masque\n 8)jouer\n");
                        scanf("%d", &choix_option);

                    }
                    switch (choix_option) {// permet de naviguer entre les option
                        case 6:
                        {// lance une séris de fonction pour pouvoir saisir un masque
                            espace();// permet d'ajouter des espace dans la console, revoie des \n
                            masque_manuelle4x4(masque);//créer manuellement un masque4x4; prend en paramètre un matrice,revoie une matrice avec les modification apliquer
                            afficher_4x4(masque);// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console
                            printf("\n");
                            Matrice_joueur4x4(solution,masque,joueur);// créer la matrice de jeu, prend trois matrice en paramètre,solution sert a etre comparer a la matrice joueur,masque pour masque,joueur:la matrice de jeu
                            //revoie la matrice de jeu créer par le masque
                            afficher_4x4(joueur);// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console

                            break;
                        }
                        case 7:
                        {// lance une séri de fonction pour générer automatiquement un masque
                            espace();// permet d'ajouter des espace dans la console, revoie des \n
                            masque_alleatoire4x4(masque);// créer un masque aléatoire,prend la matrice masque en paramètre,revoie un masque générer aléatoirement
                            afficher_4x4(masque);// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console
                            printf("\n");
                            Matrice_joueur4x4(solution,masque,joueur); // créer la matrice de jeu, prend trois matrice en paramètre,solution comme base de la création,masque pour le masque,joueur:la matrice de jeu
                            //revoie la matrice de jeu créer par le masque
                            afficher_4x4(joueur);// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console

                            break;

                        }


                        case 8:
                        {// lance une séri de fonction pour jouer
                            espace();// permet d'ajouter des espace dans la console, revoie des \n
                            masque_alleatoire4x4(masque);// créer un masque aléatoire,prend la matrice masque en paramètre,revoie un masque générer aléatoirement
                            Matrice_joueur4x4(solution, masque, joueur);// créer la matrice de jeu, prend trois matrice en paramètre,solution pour la solution de la grille,masque pour le masque,joueur:la matrice de jeu
                            //revoie la matrice de jeu créer par le masque
                            do// condition qui permet de jouer temps que le joueur a des vies
                            {
                                afficher_4x4(joueur); // affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console
                                modifier4x4(joueur, solution);//permet d'ajouter une valeur sur la grille de jeu,prend en paramètre joueur: la matrice de jeu:solution pour vérifier la si coup est bon
                                // renvoie la matrice joueur modifier
                                validiter_4x4(joueur, &vie); //permet de savoir si il y a autant de 0 que de 1 sur une ligne ou collone,prend en paramètre,joueur:la matrice de jeu, &vie: pour enlever une vie en cas d'erreur
                                //renvoie vie-1 en cas erreur et explique pourquoi
                                verif_Ligne_colonne_doublons_4x4(joueur, &vie); //permet de savoir si une ligne ou une collone sont pareil,prend en paramètre,:joueur: la matrice de jeu, &vie: pour enlever une vie en cas d'érreur
                                //renvoie vie-1 en cas d'erreur et explique pourquoi
                                verification_Adjacent4x4(joueur, &vie); //permet de savoir si trois 0 ou trois 1 sont placer d'affiler,prend en paramètre,:joueur: la matrice de jeu, &vie: pour enlever une vie en cas d'érreur
                                //renvoie vie-1 en cas d'erreur et explique pourquoi
                                victoire(solution, joueur); //permet de gagner, prend en paramètre solution:pour comparer si les condition de victoire son remplis, joueur: la matrice de jeu
                                //renvoie un message de victoire
                            }while (vie != 0 || victoire_auto(solution,joueur) != 1);// condition qui permet de jouer temps que le joueur a des vies
                            //permet de gagner, prend en paramètre solution:pour comparer si les condition de victoire son remplis, joueur: la matrice de jeu
                            break;
                        }
                    }
                    break;
                }



                case 5:
                { //troisième menu après avoie selectionner l'option "5) grille 8x8"
                    // toute les matrice utiliser ici sont de dimention 8x8


                    espace();// permet d'ajouter des espace dans la console, revoie des \n
                    int choix_option;
                    printf("choisisez une option\n");
                    printf("6) Sasir manuellement un masque`\n 7)Générer automatiquent un masque\n 8)jouer\n");
                    scanf("%d", &choix_option);
                    while (choix_option < 6 || choix_option > 8)  // saisi sécurisé
                    {
                        printf("choisisez une option si dessous\n");
                        printf("6) Sasir manuellement un masque`\n 7)Générer automatiquent un masque\n 8)jouer\n");
                        scanf("%d", &choix_option);

                    }
                    switch (choix_option) { // pertmet de choisir l'un des option
                        case 6:
                        {// lance une séris de fonction pour pouvoir saisir un masque
                            espace();// permet d'ajouter des espace dans la console, revoie des \n
                            masque_manuelle8x8(masque8x8);//créer manuellement un masque8x8; prend en paramètre un matrice,revoie une matrice avec les modification apliquer
                            afficher_8x8(masque8x8);// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console
                            printf("\n");
                            Matrice_joueur8x8(solution2,masque8x8,joueur2);// créer la matrice de jeu, prend trois matrice en paramètre,solution2 pour la solution de la grille,masque8x8 pour le masque,joueur2:la matrice de jeu
                            //revoie la matrice de jeu créer avec le nouveau masque
                            afficher_8x8(joueur2);// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console

                            break;
                        }
                        case 7:{

                            espace();// permet d'ajouter des espace dans la console, revoie des \n
                            masque_alleatoire8x8(masque8x8);// créer un masque aléatoire,prend la matrice masque en paramètre,revoie un masque générer aléatoirement
                            afficher_8x8(masque8x8);// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console
                            printf("\n");
                            Matrice_joueur8x8(solution2, masque8x8, joueur2);// créer la matrice de jeu, prend trois matrice en paramètre,solution2 pour la solution de la grille,masque8x8 pour le masque,joueur2:la matrice de jeu
                            //revoie la matrice de jeu créer avec le nouveau masque
                            afficher_8x8(joueur2);// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console
                            break;
                        }
                        case 8:
                        {
                            espace();// permet d'ajouter des espaces dans la console, revoie des \n
                            masque_alleatoire8x8(masque8x8);// créer un masque aléatoire,prend la matrice masque en paramètre,revoie un masque générer aléatoirement
                            Matrice_joueur8x8(solution2, masque8x8, joueur2);// créer la matrice de jeu, prend trois matrice en paramètre,solution2 pour la solution de la grille,masque8x8 pour le masque,joueur2:la matrice de jeu
                            //revoie la matrice de jeu créer avec le nouveau masque
                            do
                            {
                                afficher_8x8(joueur2);// affiche une matrice,prend une matrice en paramètre, print cette matrice dans la console
                                modifier8x8(joueur2, solution2);//permet d'ajouter une valeur sur la matrice  de jeu,prend en paramètre joueur2: la matrice de jeu,solution2 pour vérifier  si coup est bon
                                // renvoie la matrice joueur modifier
                                validiter_8x8(joueur2, &vie);//permet de savoir s'il y a autant de 0 que de 1 sur une ligne ou collone,prend en paramètre,joueur2:la matrice de jeu, &vie: pour enlever une vie en cas d'erreur
                                //renvoie vie-1 en cas erreur et explique pourquoi
                                verif_Ligne_colonne_doublons_8x8(joueur2, &vie);//permet de savoir si une ligne ou une collone sont pareil,prend en paramètre,:joueur: la matrice de jeu, &vie: pour enlever une vie en cas d'érreur
                                //renvoie vie-1 en cas d'erreur et explique pourquoi
                                verification_Adjacent8x8(joueur2, &vie);//permet de savoir si trois 0 ou trois 1 sont placer d'affiler,prend en paramètre joueur2 : la matrice de jeu, &vie : pour enlever une vie en cas d'érreur
                                //renvoie vie-1 en cas d'erreur et explique pourquoi
                                victoire8x8(solution2, joueur2);//permet de gagner, prend en paramètre solution2 :pour comparer si les conditions de victoire sont remplis, joueur2 : la matrice de jeu
                                //renvoie un message de victoire
                            }while (vie != 0, victoire_auto8x8(solution2,joueur2)!=1);
                            break;
                        }

                    }


                    break;
                }
            }

            break;
        }
        case 2:
        {// second menu après avoir choisir l'option "laisser l'odinateur résoudre une grille"
            espace();// permet d'ajouter des espaces dans la console, revoie des \n
            int choix_grille;
            printf("choisicer la taille de la grille\n");
            printf("4) grille 4x4 \n 5) grille 8x8 \n");
            scanf("%d", &choix_grille);
            while (choix_grille < 4 || choix_grille > 5) // saisi sécuriser
            {
                printf("choisicer la taille de la grille entre les option si-dessous\n");
                printf("4) grille 4x4 \n 5) grille 8x8 \n");
                scanf("%d", &choix_grille);
            }
            switch (choix_grille) // permet de choisir une grille
            {
                case 4:
                {//séri de fonction après avoie selectionner l'option "4) grille 4x4"
                    espace();// permet d'ajouter des espace dans la console, revoie des \n
                    resolution_matrice4x4(joueur,solution,masque);// permet de résoudre automatiquement une grille de takuzu, prend en parramètre, joueur: la grille de jeu,solution sert a etre comparer a la matrice joueur,masque pour le masque
                    //revoie la résolution complète par étabe de la grille de takuzu
                    break;
                }
                case 5:
                {//séri de fonction après avoie selectionner l'option "5) grille 8x8"
                    espace();// permet d'ajouter des espace dans la console, revoie des \n
                    resolution_matrice8x8(joueur2,solution2,masque8x8);// permet de résoudre automatiquement une grille de takuzu, prend en parramètre, joueur: la grille de jeu,solution sert a etre comparer a la matrice joueur,masque pour le masque
                    //revoie la résolution complète par étabe de la grille de takuzu

                    break;
                }
            }
            break;
        }
        case 3:
        {// second menu après avoir choisir l'option "laisser l'odinateur résoudre une grille"
            espace();// permet d'ajouter des espace dans la console, revoie des \n
            int choix_grille;
            printf("choisicer la taille de la grille\n");
            printf("4) grille 4x4 \n 5) grille 8x8 \n");
            scanf("%d", &choix_grille);
            while (choix_grille < 4 || choix_grille > 5)// saisi sécurisé
            {
                printf("choisicer la taille de la grille entre les option si-dessous\n");
                printf("4) grille 4x4 \n 5) grille 8x8 \n");
                scanf("%d", &choix_grille);
            }
            switch (choix_grille)// permet de choisir une grille
            {
                case 4:
                {//séri de fonction après avoie selectionner l'option "4) grille 4x4"
                    // toute les matrice utiliser ici sont de dimention 4x4


                    espace();// permet d'ajouter des espace dans la console, revoie des \n
                    int choix_option2;

                    printf("choisisez une option\n");
                    printf("6) afficher l'ensemble des ligne/collone valide\n 7)générer une grille de takuzu\n");
                    scanf("%d", &choix_option2);
                    while (choix_option2<6 || choix_option2>7)// saisi sécurisé
                    {
                        printf("choisisez une option si dessous\n");
                        printf("6) afficher l'ensemble des ligne/collone valide\n 7)générer une grille de takuzu\n");
                        scanf("%d", &choix_option2);

                    }
                    switch (choix_option2) {     // permet de choisir une option
                        case 6:
                        {//séri de fonction après avoir sélectionner "6) afficher l'ensemble des ligne/collone valide"
                            espace();// permet d'ajouter des espace dans la console, revoie des \n
                            code_binaireL(solution,0);//
                            break;
                        }
                        case 7:
                        {//séri de fonction après avoir sélectionner "7)générer une grille de takuzu"
                            espace();// permet d'ajouter des espace dans la console, revoie des \n
                            generer_matrice4x4(solution);//
                            break;
                        }
                    }

                    break;
                }
                case 5:
                {//séri de fonction après avoie selectionner l'option "4) grille 8x8"
                    // toute les matrice utiliser ici sont de dimention 8x8

                    espace();// permet d'ajouter des espace dans la console, revoie des \n
                    int choix_option;

                    printf("choisisez une option\n");
                    printf("6) afficher l'ensemble des ligne/collone valide\n 7)générer une grille de takuzu\n");
                    scanf("%d", &choix_option);
                    while (choix_option<6 || choix_option>7) // saisi sécurisé
                    {
                        printf("choisisez une option si dessous\n");
                        printf("6) afficher l'ensemble des ligne/collone valide\n 7)générer une grille de takuzu\n");
                        scanf("%d", &choix_option);

                    }
                    switch (choix_option) // permet de choisir une option
                    {
                        case 6:
                        {//séri de fonction après avoir sélectionner "6) afficher l'ensemble des ligne/collone valide"
                            espace();// permet d'ajouter des espace dans la console, revoie des \n
                            code_binaireL8x8(solution2,0);//

                            break;
                        }
                        case 7:
                        {//séri de fonction après avoir sélectionner "7)générer une grille de takuzu"
                            espace();// permet d'ajouter des espace dans la console, revoie des \n
                            generer_matrice8x8(solution2);
                            break;
                        }

                    }
                    break;
                }
            }
            break;
        }

    }
    return 0;
}
