#ifndef REPRESENTATION01_H_INCLUDED
#define REPRESENTATION01_H_INCLUDED
#include <stdbool.h>
#define nul 0
/**1- Déclaration et définition : **/
/***********************************/
// Déclaration de la structure du maillon
typedef struct mmc mmc;
typedef struct mmc {
        int val;
        int ligne;
        int col;
        mmc *suiv;
} ;
// Définition du nouveau type ptr_mc
typedef mmc *ptr_mc;

/**1-     Machine abstraite     : **/
/***********************************/
void Allouer(ptr_mc *p);
void Liberer(ptr_mc p);
void Aff_val(ptr_mc p, int v);
void Aff_adr(ptr_mc p, ptr_mc q);
void Aff_ligne(ptr_mc p, int l);
void Aff_col(ptr_mc p, int c);
int Valeur(ptr_mc p);
int Ligne(ptr_mc p);
int Colonne(ptr_mc p);
ptr_mc Suivant(ptr_mc p);


void Lect_Mc(ptr_mc *T ,int n,int m);
void Affiche_mc(ptr_mc tete,int n, int m );
bool rech_case(ptr_mc T, int l, int c,ptr_mc *p);
ptr_mc Extraction(ptr_mc T,int n , int m, int l1, int c1, int l2, int c2);


ptr_mc Addition_mc( ptr_mc L1, ptr_mc L2,int n1, int m1, int n2, int m2);
ptr_mc mux_vect(ptr_mc t1, ptr_mc t2 );
ptr_mc Mux_matrix(ptr_mc t1,ptr_mc t2,int l1 ,int c1 ,int l2 ,int c2 );
ptr_mc transp_mc(ptr_mc L,int n, int m);



/************1-Division**************/
/***********************************/
/* d.1 déclarations de la liste qui contient la matrice */
typedef struct llc_mc llc_mc;
typedef struct llc_mc {
        ptr_mc matrix;
        llc_mc *suiv;
} ;
typedef llc_mc *ptr_mmc;//c'est un pointeur vers ptr_mc
void Allouer_mc(ptr_mmc *p);
void Aff_mc(ptr_mmc p, ptr_mc v);
void Aff_adr_mc(ptr_mmc p, ptr_mmc q);
ptr_mc Matrice(ptr_mmc p);
ptr_mmc Suivant_mc(ptr_mmc p);
ptr_mmc Division_mc(ptr_mc T,int l ,int c , int n , int m);

ptr_mc ET_mc(int n1, int m1, int n2, int m2, ptr_mc L1, ptr_mc L2);
ptr_mc OU_mc(int n1, int m1, int n2, int m2, ptr_mc L1, ptr_mc L2);
ptr_mc XOR_mc(int n1, int m1, int n2, int m2, ptr_mc L1, ptr_mc L2);
ptr_mc NON_mc(int n, int m, ptr_mc L);
#endif // REPRESENTATION01_H_INCLUDED
