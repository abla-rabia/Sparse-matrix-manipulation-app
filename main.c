#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Affichage_et_Menu.h"
#include <time.h>
#include <windows.h>
#include "REPRESENTATION01.h"


int main(int argc, char* argv[])
{
    ptr_mc T=NULL;
    ptr_mc T1,T2,T3,Tex,p,trsp,M1,M2,M3,V1,V2,V3,Nlg;
    ptr_mmc Mt;
    int l1,c1,l2,c2,choix1,choix2,l3,c3,nb,n1,m1,n2,m2,lx1,lx2,cx1,cx2,sbl,sbc,i,N,a1,a2,b1,b2,choice,ele1,ele2;
    bool arret=0;
    bool retour=0;
    srand(time(NULL));
    Welcome();
    do
    {
        system("cls||clear");
        Menu_principal();
        scanf("%d",&choix1);
        switch (choix1)
        {
            case 1 :
                {
                    do {
                        system("cls||clear");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                        printf("\n");
                        printf("         Vous avez choisis d'utiliser la 1 ere representation ! Super! \n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                        printf("         ---> Voici un petit guide qui peux vous aider  :\n ");
                        printf("\n");
                        Menu_rep1();
                        scanf("%d",&choix2);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                        switch (choix2)
                        {
                            case 1 :
                            {
                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   1. Cr%cation d'une Matrice creuse \n", 130);
                                printf("    -----------------------------\n");
                                printf(" --> Introduire la taille de la matrice : \n ");
                                printf("    Nombre de lignes : ");
                                scanf("%d",&l1);
                                printf("    Nombre de colonnes : ");
                                scanf("%d",&c1);
                                if (l1>0 && c1>0)
                                    Lect_Mc(&T,l1,c1);
                                else
                                    printf("La taille doit %ctre > 0",136);
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                                break;
                            }
                            case 2 :
                            {

                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   2. Affichage d'une Matrice creuse \n");
                                printf("    ------------------------------\n");
                                if (T==NULL)
                                    printf(" --> ERREUR ! Veuillez cr%cer d'abord la matrice !\n",130);
                                else
                                {
                                    printf(" --> Voici votre Matrice : \n");
                                    Affiche_mc(T,l1,c1);
                                }
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                                break;
                            }
                            case 3 :
                            {
                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   3. Extraction d'une sous-matrice \n");
                                printf("    ------------------------------\n");
                                if (T==NULL)
                                    printf(" --> ERREUR ! Veuillez cr%cer d'abord la matrice !\n",130);
                                else
                                {
                                    printf(" --> Veuillez introduire les bornes de l'extraction : \n");
                                    printf("        Ligne de la 1ere case : ");
                                    scanf("%d",&lx1);
                                    printf("        Colonne de la 1ere case : ");
                                    scanf("%d",&cx1);
                                    printf("        Ligne de la 2eme case : ");
                                    scanf("%d",&lx2);
                                    printf("        Colonne de la 2eme case : ");
                                    scanf("%d",&cx2);
                                    if ((lx1>l1 || cx1>c1)||((lx2>l1 || cx2>c1)))
                                    printf(" --> ERREUR ! Veuiller re-introduire une autre taille !\n",130);
                                    else
                                    {
                                        Tex=Extraction(T,l1,c1,lx1,cx1,lx2,cx2);
                                        printf(" --> Voici votre Matrice Extraite : \n");
                                        Affiche_mc(Tex,lx2-lx1+1,cx2-cx1+1);
                                    }
                                }
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                                break;
                            }
                            case 4 :
                            {

                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   4. Division d'une Matrice creuse en sous-blocs \n");
                                printf("    -------------------------------------------\n");
                                if (T==NULL)
                                    printf(" --> ERREUR ! Veuillez cr%cer d'abord la matrice !\n",130);
                                else
                                {
                                    printf(" --> Veuillez introduire le nombre de sous-blocs en lignes : ");
                                    scanf("%d",&sbl);
                                    printf(" --> Veuillez introduire le nombre de sous-blocs en colonnes : ");
                                    scanf("%d",&sbc);
                                    if (l1%sbl!=0 || c1%sbc!=0)
                                        printf(" --> ERREUR ! Le nombre de lignes / colonnes n'est pas divisible par le nombre de sous-blocs saisie !\n",130);
                                    else
                                    {
                                        Mt=Division_mc(T,l1,c1,sbl,sbc);
                                        p=Mt;
                                        for (i=1;i<=sbl*sbc;i++)
                                        {
                                            printf("---> Le sous-bloc N=%d\n",i);
                                            Affiche_mc(Matrice(p),l1/sbl,c1/sbc);
                                            printf("\n");
                                            p=Suivant_mc(p);
                                        }
                                    }

                                }
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                                break;
                            }
                            case 5 :
                            {
                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   5. La transposée d'une Matrice creuse \n");
                                printf("    ----------------------------------\n");
                                if (T==NULL)
                                    printf(" --> ERREUR ! Veuillez cr%cer d'abord la matrice !\n",130);
                                else
                                {
                                    trsp=transp_mc(T,l1,c1);
                                    printf(" --> Voici votre Matrice Transposee: \n");
                                    Affiche_mc(trsp,c1,l1);
                                    printf("\n");
                                }
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                                break;
                            }
                            case 6 :
                            {
                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   6. Addition de deux ou plusieurs Matrices creuses \n");
                                printf("    ----------------------------------------------\n");
                                printf(" ---> Veuiller introduire le nombre de matrice que vous voullez les sommer: ");
                                scanf("%d",&N);
                                printf ("\n---> Veuillez saisir le nombre des lignes de la premiere matrice: ");
                                scanf("%d",&n1);
                                printf (" \n---> Veuillez saisir le nombre de colonnes de la premiere matrice:");
                                scanf("%d",&m1);
                                Lect_Mc(&T1,n1,m1);
                                printf("\n");
                                Affiche_mc(T1,n1,m1);
                                for (i=2; i<=N; i++)
                                {
                                    printf("---> La matrice N=%d <--- \n",i);
                                    printf ("\n Veuillez entrer le nombre de ligne : ");
                                    scanf("%d",&n2);
                                    printf (" \n Veuillez entrer le nombre de colonne :");
                                    scanf("%d",&m2);
                                    if (n2!=n1 || m2!=m1)
                                        {
                                            printf("    ERREUR ! Vous devez entrer la meme taille que premiere matrice ! ");
                                            break;
                                        }
                                        Lect_Mc(&T2,n2,m2);
                                        Affiche_mc(T2,n2,m2);
                                        printf("\n");
                                        printf("\n");
                                        T3=Addition_mc(T1,T2,n1,m1,n2,m2);
                                        T1=T3;
                                }
                                Affiche_mc(T3,n2,m2);
                                printf("\n");
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                            }
                            case 7 :
                            {
                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   7. Multiplication par vecteur / de deux matrices creuse \n");
                                printf("    ----------------------------------------------------\n");
                                printf("\n ---> Que voulez vous faire ? \n");
                                printf("\n      1 : Multiplication de vecteurs .");
                                printf("\n      2 : Multiplication de deux matrices .");
                                printf("\n          Taper votre choix : ");
                                scanf("%d",&choice);
                                if (choice==1)
                                {
                                    printf("\n");
                                    printf("\n");
                                    printf(" ---> Veuillez introduire le nombre d element du premier vecteur : ");
                                    scanf("%d",&ele1);
                                    printf(" ---> Veuillez introduire le nombre d element du deuxieme vecteur : ");
                                    scanf("%d",&ele2);
                                    printf("\n");
                                    printf(" ---> Veuillez introduire le premier vecteur : \n");
                                    Lect_Mc(&V1,ele1,1);
                                    printf("\n");
                                    Affiche_mc(V1,ele1,1);
                                    printf("\n");
                                    printf("\n");
                                    printf(" ---> Veuillez introduire le deuxieme vecteur : \n");
                                    Lect_Mc(&V2,1,ele2);
                                    printf("\n");
                                    Affiche_mc(V2,1,ele2);
                                    printf("\n");
                                    V3=mux_vect(V1,V2);
                                    printf("\n");
                                    printf(" ---> Voici votre Vecteur resultat : \n");
                                    Affiche_mc(V3,ele1,ele2);
                                    printf("\n");
                                }
                                else
                                {
                                    printf ("\n---> Veuillez saisir le nombre des lignes de la premiere matrice: ");
                                    scanf("%d",&a1);
                                    printf (" \n---> Veuillez saisir le nombre de colonnes de la premiere matrice:");
                                    scanf("%d",&b1);
                                    printf ("\n---> Veuillez saisir le nombre des lignes de la deuxieme matrice: ");
                                    scanf("%d",&a2);
                                    printf (" \n---> Veuillez saisir le nombre de colonnes de la deuxieme matrice:");
                                    scanf("%d",&b2);
                                    if (b1 != a2 )
                                        printf("    ERREUR ! YA PAS DE COMPATIBILITE DE TAILLE !");
                                    else
                                    {
                                        printf("\n");
                                        printf("\n");
                                        printf(" ---> Veuillez introduire la premiere matrice : \n");
                                        Lect_Mc(&M1,a1,b1);
                                        printf("\n");
                                        Affiche_mc(M1,a1,b1);
                                        printf("\n");
                                        printf(" ---> Veuillez introduire la deuxieme matrice : \n");
                                        Lect_Mc(&M2,a2,b2);
                                        printf("\n");
                                        Affiche_mc(M2,a1,b1);
                                        printf("\n");
                                        M3=Mux_matrix(M1,M2,a1,b1,a2,b2);
                                        printf("\n");
                                        printf(" ---> Voici votre matrice resultante : \n");
                                        printf("\n");
                                        Affiche_mc(M3,a1,b2);
                                    }
                                }
                                printf("\n");
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                            }
                            case 8 :
                            {
                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   8. NON logique \n");
                                printf("    ----------------------------------\n");
                                if (T==NULL)
                                    printf(" --> ERREUR ! Veuillez cr%cer d'abord la matrice !\n",130);
                                else
                                {
                                    Nlg=NON_mc(l1,c1,T);
                                    printf(" --> Voici le non logique de votre matrice: \n");
                                    Affiche_mc(Nlg,c1,l1);
                                    printf("\n");
                                }
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                                break;
                            }
                            case 9 :
                            {
                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   8. OU logique  \n");
                                printf("    ----------------------------------\n");
                                printf ("\n---> Veuillez saisir le nombre des lignes de la premiere matrice: ");
                                scanf("%d",&a1);
                                printf (" \n---> Veuillez saisir le nombre de colonnes de la premiere matrice:");
                                scanf("%d",&b1);
                                printf ("\n---> Veuillez saisir le nombre des lignes de la deuxieme matrice: ");
                                scanf("%d",&a2);
                                printf (" \n---> Veuillez saisir le nombre de colonnes de la deuxieme matrice:");
                                scanf("%d",&b2);
                                printf("\n");
                                if (a1!=a2 ||b1!=b2)
                                    printf("ERREUR ! Les deux matrices doivent avoir la meme taille ! \n");
                                else
                                {
                                    printf("\n");
                                    printf(" ---> Veuillez introduire la premiere matrice : \n");
                                    Lect_Mc(&M1,a1,b1);
                                    printf("\n");
                                    Affiche_mc(M1,a1,b1);
                                    printf("\n");
                                    printf(" ---> Veuillez introduire la deuxieme matrice : \n");
                                    Lect_Mc(&M2,a2,b2);
                                    printf("\n");
                                    Affiche_mc(M2,a1,b1);
                                    M3=OU_mc(a1,b1,a2,b2,M1,M2);
                                    printf("\n");
                                    printf("\n");
                                    printf(" ---> Voici votre matrice resultante : \n");
                                    printf("\n");
                                    Affiche_mc(M3,a1,b1);
                                    printf("\n");
                                }
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                                break;
                            }
                            case 10 :
                            {
                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   10. ET logique  \n");
                                printf("    ----------------------------------\n");
                                printf ("\n---> Veuillez saisir le nombre des lignes de la premiere matrice: ");
                                scanf("%d",&a1);
                                printf (" \n---> Veuillez saisir le nombre de colonnes de la premiere matrice:");
                                scanf("%d",&b1);
                                printf ("\n---> Veuillez saisir le nombre des lignes de la deuxieme matrice: ");
                                scanf("%d",&a2);
                                printf (" \n---> Veuillez saisir le nombre de colonnes de la deuxieme matrice:");
                                scanf("%d",&b2);
                                printf("\n");
                                if (a1!=a2 ||b1!=b2)
                                    printf("ERREUR ! Les deux matrices doivent avoir la meme taille ! \n");
                                else
                                {
                                    printf("\n");
                                    printf(" ---> Veuillez introduire la premiere matrice : \n");
                                    Lect_Mc(&M1,a1,b1);
                                    printf("\n");
                                    Affiche_mc(M1,a1,b1);
                                    printf("\n");
                                    printf(" ---> Veuillez introduire la deuxieme matrice : \n");
                                    Lect_Mc(&M2,a2,b2);
                                    printf("\n");
                                    Affiche_mc(M2,a1,b1);
                                    M3=ET_mc(a1,b1,a2,b2,M1,M2);
                                    printf("\n");
                                    printf("\n");
                                    printf(" ---> Voici votre matrice resultante : \n");
                                    printf("\n");
                                    Affiche_mc(M3,a1,b1);
                                    printf("\n");
                                }
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                                break;
                            }
                            case 11 :
                            {
                                system("cls||clear");
                                printf("\n\n\n\n");
                                printf ("   11. OU exclusif  \n");
                                printf("    ----------------------------------\n");
                                printf ("\n---> Veuillez saisir le nombre des lignes de la premiere matrice: ");
                                scanf("%d",&a1);
                                printf (" \n---> Veuillez saisir le nombre de colonnes de la premiere matrice:");
                                scanf("%d",&b1);
                                printf ("\n---> Veuillez saisir le nombre des lignes de la deuxieme matrice: ");
                                scanf("%d",&a2);
                                printf (" \n---> Veuillez saisir le nombre de colonnes de la deuxieme matrice:");
                                scanf("%d",&b2);
                                printf("\n");
                                if (a1!=a2 ||b1!=b2)
                                    printf("ERREUR ! Les deux matrices doivent avoir la meme taille ! \n");
                                else
                                {
                                    printf("\n");
                                    printf(" ---> Veuillez introduire la premiere matrice : \n");
                                    Lect_Mc(&M1,a1,b1);
                                    printf("\n");
                                    Affiche_mc(M1,a1,b1);
                                    printf("\n");
                                    printf(" ---> Veuillez introduire la deuxieme matrice : \n");
                                    Lect_Mc(&M2,a2,b2);
                                    printf("\n");
                                    Affiche_mc(M2,a1,b1);
                                    M3=XOR_mc(a1,b1,a2,b2,M1,M2);
                                    printf("\n");
                                    printf("\n");
                                    printf(" ---> Voici votre matrice resultante : \n");
                                    printf("\n");
                                    Affiche_mc(M3,a1,b1);
                                    printf("\n");
                                }
                                printf("    Appuyez sur la touche ENTRER pour continuer .");
                                fflush(stdin);
                                getchar();
                                break;
                            }
                            case 12 :
                                retour=1;
                        }

                    }while ( !  retour);
                    break;
                }
            case 2 :
                {
                    system("cls||clear");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                    printf("\n");
                    printf("         Vous avez choisis d'utiliser la 2 eme representation ! Formidable ! \n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    printf("         ---> Voici un petit guide qui peux vous aider  :\n ");
                    printf("\n");
                    Menu_rep2();
                    scanf("%d",&choix2);
                    break;
                }
            case 3 :
                arret=1;

        }
    }while (!arret);


    return 0;
}
