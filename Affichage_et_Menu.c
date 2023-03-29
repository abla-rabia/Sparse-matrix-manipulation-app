#include "Affichage_et_Menu.h"
#include <windows.h>

/************************************************Welcome***********************************************************/
void Welcome()
{
    system("cls");
    printf("\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("     %c .88d88b.  .d88888b    dP   %c     RABIA   ABLA       %c\n",186,186,186);
    printf("     %c 88.  `88  88.    \"'        %c     KOUADRI NADA       %c\n",186,186,186);
    printf("     %c 888d888;  ~Y88888b.   88   %c     GROUPE  : 07       %c\n",186,186,186);
    printf("     %c 88.             `8b   88   %c     TP N:1             %c\n",186,186,186);
    printf("     %c  Y88888    Y88888P    dP   %c     Matrices Creuses   %c\n",186,186,186);
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("     %c   ECOLE   NATIONALE   SUPERIEURE   D'INFORMATIQUE   %c\n",186,186);
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    printf("          Merci d'avoir choisir notre application ! ");
    printf(" \n\n        Appuyer sur la touche ENTRER  pour continuer ! ");
    getchar();
}

/************************************************MENU PRINCIPAL****************************************************/

void Menu_principal()
{
    system("cls||clear");
    printf("\n\n\n");
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("     %c     Notre programme vous donne la possibilite de    %c\n",186,186);
    printf("     %c     representer des matrices creuses et faire vos   %c\n",186,186);
    printf("     %c     calcules a l aide de deux representations !     %c\n",186,186);
    printf("     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    printf("\n\n\n");
    printf("         Que voulez vous faire ?\n ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    printf("           -----------> 1: Utiliser la representation 1  \n");
    printf("            -----------> 2: Utiliser la representation 2  \n");
    printf("            -----------> 3: Quitter le programme :')  \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    printf("         Alors, qu'\ avez vous choisis ? Tapez votre choix ! ");
}

/*********************************************Menu representation 1************************************************/
void Menu_rep1()
{
    printf("       ________________________________________________________________________________________\n");
    printf("      |    _______________________                                                             |\n");
    printf("      |   |                       |                                                            |\n");
    printf("      |   |   REPRESENTATION 01   |                                                            |\n");
    printf("      |   |_______________________|                                                            |\n");
    printf("      |   __________________________________________________________________________________   |\n");
    printf("      |  |   Une liste comprenant les elements vus comme vecteur ou la structure definit    |  |\n");
    printf("      |  |   la ligne et la colonne de la valeur non nulle enregistree.                     |  |\n");
    printf("      |  |__________________________________________________________________________________|  |\n");
    printf("      |________________________________________________________________________________________|\n");
    printf("      |                                        MENU:                                           |\n");
    printf("      |            Operations de base                Arithmetiques          Logiques           |\n");
    printf("      |  _________________    _________________    _________________    _________________      |\n");
    printf("      | | 1: Creer & Lire |  | 3: Extraction.  |  | 6: Addition de 2|  | 8: Non logique. |     |\n");
    printf("      | |    Une Matrice. |  | 4: Division de  |  |   ou +2 matrices|  | 9: OU logique.  |     |\n");
    printf("      | | 2: Afficher Une |  |    la matrice.  |  | 7: Multiplica-  |  | 10: ET logique. |     |\n");
    printf("      | |    Matrice.     |  | 5: Transposee.  |  |    -tion.       |  | 11: OU exclusif.|     |\n");
    printf("      | |_________________|  |_________________|  |_________________|  |_________________|     |\n");
    printf("      |                                                                                        |\n");
    printf("      |                           12: RETOUR AU MENU PRINCIPAL                                 |\n");
    printf("      |________________________________________________________________________________________|\n");
    printf("      |                                SHEMA ILLUSTRATIF:                                      |\n");
    printf("      |                                                                                        |\n");
    printf("      |         _______________         _______________         _______________                |\n");
    printf("      |        |   |   |   |   |       |   |   |   |   |       |   |   |   |   |               |\n");
    printf("      |   T--->|Val|Lig|Col|Sui|------>|   |   |   |   |------>|   |   |   |   |------[        |\n");
    printf("      |        |___|___|___|___|       |___|___|___|___|       |___|___|___|___|               |\n");
    printf("      |                                                                                        |\n");
    printf("      |________________________________________________________________________________________|\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    printf("                                        Votre choix :");

}


/*********************************************Menu representation 2************************************************/
void Menu_rep2()
{
     printf("       ________________________________________________________________________________________\n");
    printf("      |    _______________________                                                             |\n");
    printf("      |   |                       |                                                            |\n");
    printf("      |   |   REPRESENTATION 02   |                                                            |\n");
    printf("      |   |_______________________|                                                            |\n");
    printf("      |   __________________________________________________________________________________   |\n");
    printf("      |  |   Une liste de listes ou chaque liste represente une ligne de la matrice         |  |\n");
    printf("      |  |   comprenant les elements non nulles. Une ligne entierement nulle est representee|  |\n");
    printf("      |  |   par un pointeur NIL.L enregistrement contient seulement le numéro de la colonne|  |\n");
    printf("      |  |__________________________________________________________________________________|  |\n");
    printf("      |________________________________________________________________________________________|\n");
    printf("      |                                        MENU:                                           |\n");
    printf("      |            Operations de base                Arithmetiques          Logiques           |\n");
    printf("      |  _________________    _________________    _________________    _________________      |\n");
    printf("      | | 1: Creer & Lire |  | 3: Extraction.  |  | 6: Addition de 2|  | 8: Non logique. |     |\n");
    printf("      | |    Une Matrice. |  | 4: Division de  |  |   ou +2 matrices|  | 9: OU logique.  |     |\n");
    printf("      | | 2: Afficher Une |  |    la matrice.  |  | 7: Multiplica-  |  | 10: ET logique. |     |\n");
    printf("      | |    Matrice.     |  | 5: Transposee.  |  |    -tion.       |  | 11: OU exclusif.|     |\n");
    printf("      | |_________________|  |_________________|  |_________________|  |_________________|     |\n");
    printf("      |                                                                                        |\n");
    printf("      |                           12: RETOUR AU MENU PRINCIPAL                                 |\n");
    printf("      |________________________________________________________________________________________|\n");
    printf("      |                                SHEMA ILLUSTRATIF:                                      |\n");
    printf("      |                                                                                        |\n");
    printf("      |         _______________         ______________         ______________                  |\n");
    printf("      |        |       |       |       |    |    |    |       |    |    |    |                 |\n");
    printf("      |    .---|       |       |------>|    |    |    |------>|    |    |    |------[          |\n");
    printf("      |    |   |_______|_______|       |____|____|____|       |____|____|____|                 |\n");
    printf("      |    |                                                                                   |\n");
    printf("      |    |    _______________         ______________                                         |\n");
    printf("      |    `-->|       |       |       |    |    |    |                                        |\n");
    printf("      |    .---|       |       |------>|    |    |    |------[                                 |\n");
    printf("      |    |   |_______|_______|       |____|____|____|                                        |\n");
    printf("      |    |                                                                                   |\n");
    printf("      |    `--[                                                                                |\n");
    printf("      |________________________________________________________________________________________|\n");
    printf("                                        Votre choix : ");

}


