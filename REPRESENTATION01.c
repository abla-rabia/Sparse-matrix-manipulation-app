#include "REPRESENTATION01.h"
#include<stdio.h>
#include<stdbool.h>


//================================================================================================================


/**1- La machine abstraite **/
/*Allouer : l'allocation dynamique d'une case memoire de a taille de mmc à l'aide de "malloc" */

void Allouer(ptr_mc *p)
{
    *p=(ptr_mc)malloc(sizeof(mmc));
}

// ====================================================

/*Liberer : procedure qui détruit le maillon pointé par p*/
void Liberer(ptr_mc p)
{
    free(p);
}

// ====================================================

/* Aff_val : affecter la valeur dans le champs de valeur */

void Aff_val(ptr_mc p, int v)
{
    p->val = v;
}

// ====================================================

/* Aff_adr affecter la reference du maillon suivant dans le champs suiv*/

void Aff_adr(ptr_mc p, ptr_mc q)
{
    p->suiv = q;
}

// ====================================================

/* Aff_ligne : affecter le numéro de la ligne dans le champs ligne*/

void Aff_ligne(ptr_mc p, int l)
{
    p->ligne = l;
}
// ====================================================

/* Aff_col : affecter le numéro de la colonne dans le champs col*/

void Aff_col(ptr_mc p, int c)
{
    p->col = c;
}

// ====================================================

/* Valeur :avoir l'accée au champs de la valeur */

int Valeur(ptr_mc p)
{
    return p->val;
}


// ====================================================

/* Ligne  :avoir l'accée au champs de la ligne */

int Ligne(ptr_mc p)
{
    return p->ligne;
}

// ====================================================

/* Colonne :avoir l'accée au champs de la colonne */

int Colonne(ptr_mc p)
{
    return p->col;
}

// ====================================================

/* Suivant :avoir l'accée au champs du maillon suivant */

ptr_mc Suivant(ptr_mc p)
{
return p->suiv;
}

//================================================================================================================

/** 2- Les opérations sur la matrice creuse :
      -------------------------------------**/

/* a) Création et lecture de la matrice  */
/* Méthode : La méthode suivie est presque identique a la maniére de création d'une LLC, on lit d'abord le nombre de
lignes et de colonnes et on créer des maillon MC autant de valeurs non nulles, à chaque fois qu'on rencontre une
valeur nulle on saute sa case (soit la colonne seulement ou la ligne et la colonne en cas ou la valeur se trouve
à la fin de la ligne . */

void Lect_Mc(ptr_mc *tete,int n,int m)
{
    int i,j,v;
    ptr_mc p,pre;
    *tete = NULL;//Initialisation
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            printf("Mc[ %d , %d ] = ",i,j);
            scanf("%d",&v);//l'étape de lecture
            if (v != 0) // si c'est 0 on la saute
            {
                Allouer(&p);//création d'un maillon
                Aff_adr(p,NULL);
                if (*tete==NULL)
                    *tete=p;
                else
                    Aff_adr(pre,p);
                Aff_val (p,v);
                Aff_ligne(p,i);
                Aff_col(p,j);
                pre=p;
            }
        }
    }
}

// ====================================================

/* b) Affichage de la matrice */
/* Méthode : L'affichage se fait ainsi : on fait varier deux variables de tailles (ligne-colonnes ) -boucle imbriquées)
àfin de savoir le bon emplacement d'une case lors de l'affichage et surtout l'emplacement des valeurs nulles (là ou il ya
un probleme dans la ligne ou la colonne correspondante  */

void Affiche_mc(ptr_mc tete,int n, int m )
{
    int lig,col,i,j,h;
    ptr_mc p;
    p=tete;
    printf(" +");
    for (h=1;h<=m;h++)
        printf("======+");
    printf("\n");
    for (i=1; i<=n; i++)//variation des lignes
    {
        printf(" |");
        j=1;
        while ((j<= m) && (p!=NULL))//variation de colonnes et parcours de la mc pour faire la comparaison des lignes et cols
        {
            lig= Ligne(p);
            col= Colonne(p);
            if ((lig==i)&&(col==j))//la condition d'affichage direct d'un element -c.à.d qu'il existe et c pas nulle
            {
                printf("%5d |", Valeur(p));
                p= Suivant(p);
            }
            else
                printf("%5d |",nul);//traitement du cas nul .
            j++;

        }
        if ((p==NULL)&&(j<=m))//traitement du cas nul a la fin de la liste
        {
            while (j<=m)
            {
                printf("%5d |",nul);
                j++;
            }
        }
        printf("\n");
        printf(" +");
        for (h=1;h<=m;h++)
            printf("------+");
        printf("\n");
    }
}
// ====================================================
/* c) Extraction d'une sous-matrice de la matrice principale */
/* Méethode : l'idée c'est de prendre la premiere et la dernier case choisis, parcourir la liste et prendre
que le élements qui se trouve entre la ligne 1 et ligne 2 au meme temps la colonne 1 et la colonne 2 des cases choisis ,
cela demande des tests sur les lignes et les colonnes , le plus important c'est de chercher le pointeur qui pointe vers la
premiere case choisie et pour cela on a d'abord besoin du module rech_case qui recherche un maillon selon la ligne et la colonne*/

/* c.1) rech_case */
/* ce module est destinée directement au matrices creuses sous forme de liste , *cela signifie qu'il traite le cas ou le
pointeur recherché n'existe meme pas car la valeur =0 ; donc il donne la prochaine valeur directement */
bool rech_case(ptr_mc T, int l, int c,ptr_mc *p)
{
    bool trouve;
    if (T != NULL)
    {
        *p=T;
        trouve=0;
        while ((*p != NULL) && (trouve==0))
        {
            if ((((Ligne(*p)==l) && (Colonne(*p)>=c)) || (Ligne(*p)>l)))
                //on a trouvé le pointeur meme ou bien le pointeur de la case non nulle suivante
                trouve=1;
            else
                *p=Suivant(*p);
        }

    }
    return trouve;//si c faux donc la v=colonne ou la ligne n'existe meme pas
}

/* c.2) Extraction */
ptr_mc Extraction(ptr_mc T,int n , int m, int l1, int c1, int l2, int c2)
{
    ptr_mc Tex,p,q,pre;
    int i,j;
    Tex=NULL;//Initialisation
    if ((l1<=n)&&(c1<=m))//sinon la valeur n'existe mem pas :) !
    {
        if ((rech_case(T,l1,c1,&p))&& ((Ligne(p)<=l2) && (Colonne(p)<=c2)))//les bornes de recherche
        {
            while (p != NULL)
                {
                    i=Ligne(p);
                    j=Colonne(p);
                    if ((i<=l2 && i>=l1)&&(j<=c2 && j>=c1))
                    {
                        Allouer(&q);//création de la sous-matrice extraite
                        Aff_adr(q,NULL);
                        if (Tex==NULL)
                            Tex=q;
                        else
                            Aff_adr(pre,q);
                        Aff_val(q,Valeur(p));
                        Aff_ligne(q,i-l1+1);
        //un sous-matrice est une nouvelle matrice ! donc on doit chainer bien ses élément , pour cela on doit soustraire les case non prise et commencer de 1
                        Aff_col(q,j-c1+1);
                        pre=q;
                    }
                    p=Suivant(p);

                }
        }
    }
    return Tex;
}

// ====================================================
/*d) Division d'une matrice en sous-blocs : */
/* Méthode : La division est un peu differente , on a une matrice et on veut la diviser en un nombre non connue de sous-matrice
donc c'est impossible de déclarer un nombre fixe de tetes; on a opter pour cela d'utiliser un représentation dynamique pour
garder les sous-blocs obtenus , c'est une liste de matrices creuses qui a comme nombre d'elements le nombres des sous-blocs obtenus
d'ou la necessité d'une déclaration et définition d'un nouvel type de maillon ainsi que sa machine abstraite , on suite ,tout sera
facile, on utilise le module d'extraction pour obtenir les sous blocs selon la variation de la 1ere case et la derniere qui est
exactement dépendante du sous-blocs en ligne & en colonne que l'utilisateur va choisir */
//========================================================

/* d.2 Sa machine abstraite :  */
/*Allouer_mmc : l'allocation dynamique d'une zone memoire de taille llc_mc*/

void Allouer_mc(ptr_mmc *p)
{
    *p=(ptr_mmc)malloc(sizeof(llc_mc));
}

// ====================================================
/* Aff_mc : affecter le pointeur de la tete de la  matrice creuse dans le champs de valeur */

void Aff_mc(ptr_mmc p, ptr_mc v)
{
    p->matrix = v;
}

// ====================================================

/* Aff_adr_mc : affecter le pointeur du prochain maillon mmc */

void Aff_adr_mc(ptr_mmc p, ptr_mmc q)
{
    p->suiv = q;
}

// ====================================================
/* Matrice : accés au pointeur de la tete de la matrice creuse*/

ptr_mc Matrice(ptr_mmc p)
{
    return p->matrix;

}
// ====================================================

/* Suivant_mc :accés au prochain maillon mmc*/

ptr_mmc Suivant_mc(ptr_mmc p)
{
return p->suiv;
}
// ====================================================
/* d.3 Division de la matrice creuse   */
ptr_mmc Division_mc(ptr_mc T,int l ,int c , int n , int m)
{
    ptr_mc p;
    ptr_mmc T2,Mc,pr;
    int a,b,i,nb,a2,b2,ls,cs;
    nb=(n)*(m);
    ls=l/n;//nombre de lignes des sous matrices
    cs=c/m;//nombre de colonnes des sous matrices
    a=1;//initialisation des cases
    b=1;
    T2=NULL;
    for (i=1;i<=nb;i++)
    {
        Allouer_mc(&Mc);
        a2=a+ls-1;//les bornes de lignes et colonnes selon le nombre de lignes et colonnes de la sous-matrice
        b2=b+cs-1;
        p=Extraction(T,l,c,a,b,a2,b2);
        Aff_mc(Mc,p);
        if (T2==NULL)
            T2=Mc;
        else
            Aff_adr_mc(pr,Mc);
        Aff_adr_mc(Mc,NULL);
        pr=Mc;
        if (b2<c)//le changement de la premiere case et la derniere est trés important , au debut on change la colonne seulement ensuite lorsque la ligne se termine on change la ligne et on ré-initiaslise la colonne
            b=b+cs;
        else
        {
            a=a+ls;
            b=1;
        }


    }
    return T2;

}
// ====================================================
/*e) Addition de deux ou plusieurs matrice : */

ptr_mc Addition_mc( ptr_mc L1, ptr_mc L2,int n1, int m1, int n2, int m2)
{
    int i,j,v,lig1,col1,lig2,col2;
    ptr_mc tete,p3,p1,p2,pre;

    if ((n1==n2)&&(m1==m2))
    {
        tete=NULL;
        p1=L1;
        p2=L2;
        for (i=1; i<=n1; i++)
        {
            j=1;
            while ((j<= m1 ) && ((p1!=NULL) && (p2!=NULL)))
            {
                lig1=Ligne(p1);
                col1=Colonne(p1);
                lig2=Ligne(p2);
                col2=Colonne(p2);
                if (((lig1==i)&&(col1==j))||((lig2==i)&&( col2==j)))
                {
                    if (((lig1==i)&&(col1==j))&&((lig2==i)&&( col2==j)))
                    {
                        v=Valeur(p1)+Valeur(p2);
                        if (v!=0)
                        {
                            Allouer(&p3);
                            Aff_adr(p3,NULL);
                            if (tete==NULL)
                                tete=p3;
                            else
                                Aff_adr(pre,p3);
                            Aff_ligne(p3,i);
                            Aff_col(p3,j);
                            pre=p3;
                            Aff_val (p3,v);
                            p1=Suivant(p1);
                            p2=Suivant(p2);
                        }
                        else
                        {
                            p1=Suivant(p1);
                            p2=Suivant(p2);
                        }
                    }
                    else
                    {
                        if ((lig1==i)&&(col1==j))
                        {
                            Allouer(&p3);
                            Aff_adr(p3,NULL);
                            if (tete==NULL)
                            tete=p3;
                            else
                                Aff_adr(pre,p3);
                            Aff_ligne(p3,i);
                            Aff_col(p3,j);
                            pre=p3;
                            Aff_val (p3,Valeur(p1));
                            p1=Suivant(p1);
                        }
                        else
                        {
                            Allouer(&p3);
                            Aff_adr(p3,NULL);
                            if (tete==NULL)
                                tete=p3;
                            else
                                Aff_adr(pre,p3);
                            Aff_ligne(p3,i);
                            Aff_col(p3,j);
                            pre=p3;
                            Aff_val (p3,Valeur(p2));
                            p2=Suivant(p2);
                        }
                    }
                }
            j++;
            }
            if (((p1!=NULL)||(p2!=NULL)) &&(j<=m1))
            {
                while ((p1!=NULL) &&(j<=m1))
                {
                    lig1=Ligne(p1);
                    col1=Colonne(p1);
                    if ((lig1==i)&&(col1==j))
                    {
                        Allouer(&p3);
                        Aff_adr(p3,NULL);
                        if (tete==NULL)
                            tete=p3;
                        else
                            Aff_adr(pre,p3);
                        Aff_ligne(p3,i);
                        Aff_col(p3,j);
                        pre=p3;
                        Aff_val (p3,Valeur(p1));
                        p1=Suivant(p1);
                    }
                j++;
                }
                while ((p2!=NULL) &&(j<=m1))
                {
                    lig2=Ligne(p2);
                    col2=Colonne(p2);
                    if ((lig2==i)&&(col2==j))
                    {
                        Allouer(&p3);
                        Aff_adr(p3,NULL);
                        if (tete==NULL)
                            tete=p3;
                        else
                            Aff_adr(pre,p3);
                        Aff_ligne(p3,i);
                        Aff_col(p3,j);
                        pre=p3;
                        Aff_val (p3,Valeur(p2));
                        p2=Suivant(p2);
                    }
                    j++;
                }
            }
        }
     }
   return tete;
}
// ====================================================
/*f) Multiplication de deux matrices /matrice par vecteur  : */
/* La multiplication comme définition est un peu compliqué car à chaque fois on a besoin de tester les lignes et les colonnes et
faire un parcours horizontal de la 1ere matrice et un autre vertical de la 2eme ; mais on a opter pour une simple solution comme
c'est cité dans l'énnoncé, c'est d'utiliser la multiplication vecteur*vecteur ; o
- soient m1 et m2 nos 2 matrices creuse ( bien sûr elles doivent avoir la taille : (x,y)*(y,z):) )ensuite on les divise à l'aide du module
de division en y sous-matrices que se présentent sous forme de vecteurs , m1 en vecteur horizontaux et m2 verticaux ;
on effectue la multiplication par vecteur à l'aide de module mux_vect 2 par deux et on sauvegarde le resultat dans la liste des matrices
creuse -déja introduite- et enfin à l'aide du module addition_mc on vas seulement faire la somme des matrices resultantes de la
multiplication des vecteurs , ces matrices ont la taille (x,y) */
//======================================================

/* f.1 ) Multiplication par Vecteur :*/
/*C'est simple de multiplier deux vecteurs , on va parcourir les deux matrices (boucles imbriquées) pour effectuer la multiplication normale entre les
valeurs et on crée la nouvel matrice on doit seulement faire attention à ne pas créer des maillon qui on la valeur 0 aprés la multiplication*/
ptr_mc mux_vect(ptr_mc t1, ptr_mc t2 )
{
    ptr_mc p,q,pre,r,vect;
    int value;
    vect=NULL;
    p=t1;
    while(p != NULL)
    {
        q=t2;
        while (q != NULL )
        {
            value=0;
            value=Valeur(p)*Valeur(q);
            if (value != 0)//verification afin de ne pas créer des maillons de valeur nulle
            {
                Allouer(&r);//création
                if (vect==NULL)
                    vect=r;
                else
                    Aff_adr(pre,r);
                Aff_adr(r,NULL);
                Aff_ligne(r,Ligne(p));//toujours dans la multiplication , le champs obtenu a la ligne de la 1er matrice et la colonne de la seconde
                Aff_col(r,Colonne(q));
                Aff_val(r,value);
                pre=r;
                q=Suivant(q);
            }
        }
        p=Suivant(p);
    }
    return vect;
}
// ====================================================
/* f.2 ) Multiplication de deux matrices :*/
ptr_mc Mux_matrix(ptr_mc t1,ptr_mc t2,int l1 ,int c1 ,int l2 ,int c2 )
{
    ptr_mmc L1,L2,L3,r,pre,p,q;
    ptr_mc f,s;
    L1=Division_mc(t1,l1,c1,1,c1);//utilisation de la division
    L2=Division_mc(t2,l2,c2,l2,1);
    p=L1;
    q=L2;
    L3=NULL;//initialisation de la liste des mcs
    while (p != NULL )//même chose pour q
    {
        Allouer_mc(&r);
        if (L3==NULL)
            L3=r;
        else
            Aff_adr_mc(pre,r);
        Aff_adr_mc(r,NULL);
        s=mux_vect(Matrice(p),Matrice(q));//nouvelle matrice résultante de la multiplication des vecteurs
        Aff_mc(r,s);//on affecte la matrice à la liste L3
        p=Suivant_mc(p);
        q=Suivant_mc(q);
        pre=r;
    }
    r=L3;
    f=Matrice(L3);
    while (Suivant_mc(r) != NULL)//ici on effectue l'addition
    {
        r=Suivant_mc(r);
        f=Addition_mc(f,Matrice(r),l1,c2,l1,c2);
    }
    return f;
}

// ====================================================
/*g) Transposée d'une matrice   : */
/*Méthode : L'idée est simple , on varie le nombre de colonne (pusique ils seront des lignes ) et on parcours
la matrice creuse , lorsque on trouve que la colonnes de la case pointée = colonne variée , on crée un maillon
qui représente maintenant la tete de la ligne indicée par c, on affecte les valeurs et on inverse entrer le numéro de la
ligne et de la colonne */

ptr_mc transp_mc(ptr_mc L,int n, int m)
{
    int c;
    ptr_mc p,q,pre,nv;
    nv=NULL;//initialisation
    for (c=1;c<=m;c++)//parcours de colonnes
    {
        p=L;//initialisation
        while(p != NULL)//parcours de la matrice creuse
        {
            if (Colonne(p)==c)
            {
                Allouer(&q);//création du nouveau maillon
                if (nv==NULL)
                    nv=q;
                else
                    Aff_adr(pre,q);
                Aff_adr(q,NULL);
                Aff_val(q,Valeur(p));
                Aff_col(q,Ligne(p));//inverser les lignes et les colonnes
                Aff_ligne(q,c);
                pre=q;
            }
            p=Suivant(p);
        }
    }
    return nv;
}

// ====================================================
/****** les opérations logiques:*******/
//  dans les opérations logiques on cosidère les valeurs positifs comme des '1' et les valeurs négatifs et nuls comme des '0'
//la taille des deux matrice doit etre la meme
/*** ET logique***/
// le resultat est egal à 1 ssi les deux valeurs sont des 1
ptr_mc ET_mc(int n1, int m1, int n2, int m2, ptr_mc L1, ptr_mc L2) //(n1,m1):la taille du 1ère matrice
                                                                  //(n2,m2):la taille du 2ème matrice
{
    int i,j,v,v1,v2,lig1,col1,lig2,col2;
    ptr_mc tete,p3,p1,p2,pre;// tete: un pointeur vers la liste du resultat

    if ((n1==n2)&&(m1==m2))// les deux matrice doivent avoir la mème taille
    {
        tete=NULL;
        p1=L1;
        p2=L2;

         for (i=1; i<=n1; i++)//la boucle des lignes
    {
        j=1;
        while ((j<= m1 ) && ((p1!=NULL) && (p2!=NULL)))// la boucle du colonnes
        {
            lig1=Ligne(p1);
            col1=Colonne(p1);
            lig2=Ligne(p2);
            col2=Colonne(p2);

                if (((lig1==i)&&(col1==j))&&((lig2==i)&&( col2==j)))//vérification d'existance de la case (i,j) dans les deux listes
                {
                 if (Valeur(p1)>0)
                    v1=1;
                 else
                    v1=0;

                 if (Valeur(p2)>0)
                    v2=1;
                 else
                    v2=0;
                 v=v1*v2;
                if (v>0) // on vérifie esq le resultat est nul ou pas avant de créer la nouvelle maillon
                {
                Allouer(&p3);
                Aff_adr(p3,NULL);
                if (tete==NULL)
                    tete=p3;
                else
                    Aff_adr(pre,p3);
                Aff_ligne(p3,i);
                Aff_col(p3,j);
                pre=p3;
                Aff_val (p3,v);
                p1=Suivant(p1);
                p2=Suivant(p2);
                }
                else{
                p1=Suivant(p1);
                p2=Suivant(p2);

                }
                }
                else {
            if ((lig1==i)&&(col1==j))// si l'un des cases n'existe pas => leur valeur est nul => le résultat est nul
                p1=Suivant(p1);
            else
                p2=Suivant(p2);
                }

       j++;
       }
        }
    }
    return tete;
    }

/***************************************/
/**2* OU logique***/
// le resultat est egal à 1 ssi l'un des deux valeurs est egal à 1
ptr_mc OU_mc(int n1, int m1, int n2, int m2, ptr_mc L1, ptr_mc L2)//(n1,m1):la taille du 1ère matrice
                                                                 //(n2,m2):la taille du 2ème matrice
{
    int i,j,v,v1,v2,lig1,col1,lig2,col2;
    ptr_mc tete,p3,p1,p2,pre; // tete: un pointeur vers la liste du resultat

    if ((n1==n2)&&(m1==m2))// les deux matrice doivent avoir la mème taille
    {
        tete=NULL;
        p1=L1;
        p2=L2;

         for (i=1; i<=n1; i++)//la boucles des lignes
    {
        j=1;
        while ((j<= m1 ) && ((p1!=NULL) && (p2!=NULL)))// la boucles des colonnes
        {   lig1=Ligne(p1);
            col1=Colonne(p1);
            lig2=Ligne(p2);
            col2=Colonne(p2);
            if (((lig1==i)&&(col1==j))||((lig2==i)&&( col2==j)))//vérification d'existance des cases
                {
                if (((lig1==i)&&(col1==j))&&((lig2==i)&&( col2==j)))// si les deux cases existent
                {
                if (Valeur(p1)>0)
                    v1=1;
                 else
                    v1=0;

                 if (Valeur(p2)>0)
                    v2=1;
                 else
                    v2=0;
                v=v1+v2;
                if (v>0)//càd il suffit que l'un des valeurs etre 1
                {
                Allouer(&p3);
                Aff_adr(p3,NULL);
                if (tete==NULL)
                    tete=p3;
                else
                    Aff_adr(pre,p3);
                Aff_ligne(p3,i);
                Aff_col(p3,j);
                pre=p3;
                Aff_val (p3,1);
                p1=Suivant(p1);
                p2=Suivant(p2);
                }
                else{
                p1=Suivant(p1);
                p2=Suivant(p2);

                }
                }
            else {
            if ((lig1==i)&&(col1==j))//=> la case de p1 existe , de p2 n'existe pas=> il suffit que la valeur de p1 etre positif
            {  if (Valeur(p1)>0)
                { Allouer(&p3);
                Aff_adr(p3,NULL);
                if (tete==NULL)
                    tete=p3;
                else
                    Aff_adr(pre,p3);
                Aff_ligne(p3,i);
                Aff_col(p3,j);
                pre=p3;
              Aff_val (p3,1);
              }
              p1=Suivant(p1);
            }
            else //=>  la case existe  dans p2 ,de p1 n'existe pas=> il suffit que la valeur de p2 etre positif
                {
            if (Valeur(p2)>0)
            {Allouer(&p3);
                Aff_adr(p3,NULL);
                if (tete==NULL)
                    tete=p3;
                else
                    Aff_adr(pre,p3);
                Aff_ligne(p3,i);
                Aff_col(p3,j);
                pre=p3;
                Aff_val (p3,1);
                }
                p2=Suivant(p2);
             }
            }
           }
       }

       if (((p1!=NULL)||(p2!=NULL)) &&(j<=m1)) // le cas ou l'un des listes est terminée avant l'autre
       {
           while ((p1!=NULL) &&(j<=m1))// le reste de la 2ème matrice est nul => on compléte le resultat selon la 1ère matrice
           {    lig1=Ligne(p1);        // pour créer une nouvelle maillon on doit assure que la case existe + leur valeur est positif
                col1=Colonne(p1);
                 if ((lig1==i)&&(col1==j))
                 {
                     if (Valeur(p1)>0)
                     {
                Allouer(&p3);
                Aff_adr(p3,NULL);
                if (tete==NULL)
                    tete=p3;
                else
                    Aff_adr(pre,p3);

                Aff_ligne(p3,i);
                Aff_col(p3,j);
                pre=p3;
                Aff_val (p3,1);
                }
                p1=Suivant(p1);
                }
                j++;
           }
            while ((p2!=NULL) &&(j<=m1)) // le reste de la 2ème matrice est nul => on compléte le resultat selon la 1ère matrice
           {    lig2=Ligne(p2);
                col2=Colonne(p2);
                 if ((lig2==i)&&(col2==j))
                 {
                     if (Valeur(p2)>0)
                     {
                        Allouer(&p3);
                        Aff_adr(p3,NULL);
                        if (tete==NULL)
                           tete=p3;
                        else
                           Aff_adr(pre,p3);

                        Aff_ligne(p3,i);
                        Aff_col(p3,j);
                        pre=p3;
                        Aff_val (p3,1);
                      }
                p2=Suivant(p2);
                }
                j++;
           }
                }
                }
     }

   return tete;
}


/***XOR logique****/
// pour le 'ou exclisif' le resultat est égal à 1 ssi les deux valeurs sont differentes càd l'un est 1 l'autre est 0

ptr_mc XOR_mc(int n1, int m1, int n2, int m2, ptr_mc L1, ptr_mc L2)//(n1,m1):la taille du 1ère matrice
                                                                   //(n2,m2):la taille du 2ème matrice
{
    int i,j,v,v1,v2,lig1,col1,lig2,col2;
    ptr_mc tete,p3,p1,p2,pre; // tete: un pointeur vers la liste du resultat

    if ((n1==n2)&&(m1==m2))// les deux matrice doivent avoir la mème taille
    {
        tete=NULL;
        p1=L1;
        p2=L2;

         for (i=1; i<=n1; i++) // la boucles des lignes
    {
        j=1;
        while ((j<= m1 ) && ((p1!=NULL) && (p2!=NULL))) // la boucle du colonnes
        {   lig1=Ligne(p1);
            col1=Colonne(p1);
            lig2=Ligne(p2);
            col2=Colonne(p2);

            if (((lig1==i)&&(col1==j))||((lig2==i)&&( col2==j))) //vérification d'existance de la case (i,j) dans les deux matrice
                {
                if (((lig1==i)&&(col1==j))&&((lig2==i)&&( col2==j))) // si les deux cases existent
                {
                if (Valeur(p1)>0)
                    v1=1;
                 else
                    v1=0;

                 if (Valeur(p2)>0)
                    v2=1;
                 else
                    v2=0;
                v=v1+v2;
                if (v==1)// on verifie esq les valeurs sont differents ou pas si oui on créer la nouvelle maillon
                {
                Allouer(&p3);
                Aff_adr(p3,NULL);
                if (tete==NULL)
                    tete=p3;
                else
                    Aff_adr(pre,p3);
                Aff_ligne(p3,i);
                Aff_col(p3,j);
                pre=p3;
                Aff_val (p3,1);
                p1=Suivant(p1);
                p2=Suivant(p2);
                }
                else{
                p1=Suivant(p1);
                p2=Suivant(p2);

                }
                }
            else {
            if ((lig1==i)&&(col1==j)) // si l'un des cases n'existe pas => leur valeur egal à 0 => la valeur de l'autre case doit etre positif
            {  if (Valeur(p1)>0)
                { Allouer(&p3);
                Aff_adr(p3,NULL);
                if (tete==NULL)
                    tete=p3;
                else
                    Aff_adr(pre,p3);
                Aff_ligne(p3,i);
                Aff_col(p3,j);
                pre=p3;
              Aff_val (p3,1);
              }
              p1=Suivant(p1);
            }
            else{ // lig2==i && col1==j
            if (Valeur(p2)>0)
            {Allouer(&p3);
                Aff_adr(p3,NULL);
                if (tete==NULL)
                    tete=p3;
                else
                    Aff_adr(pre,p3);
                Aff_ligne(p3,i);
                Aff_col(p3,j);
                pre=p3;
                Aff_val (p3,1);
                }
                p2=Suivant(p2);
             }
            }
           }
       j++;
       }

       if (((p1!=NULL)||(p2!=NULL)) &&(j<=m1)) // le cas ou l'un des liste est terminée avant l'autre
       {
           while ((p1!=NULL) &&(j<=m1)) // le reste de la 2ème matrice est nul => on compléte le resultat selon la 1ère matrice
           {    lig1=Ligne(p1);         // pour créer une nouvelle maillon on doit assure que la case existe + leur valeur est positif
                col1=Colonne(p1);
                 if ((lig1==i)&&(col1==j))
                 {
                     if (Valeur(p1)>0)
                     {
                Allouer(&p3);
                Aff_adr(p3,NULL);
                if (tete==NULL)
                    tete=p3;
                else
                    Aff_adr(pre,p3);

                Aff_ligne(p3,i);
                Aff_col(p3,j);
                pre=p3;
                Aff_val (p3,1);
                }
                p1=Suivant(p1);
                }
                j++;
           }
            while ((p2!=NULL) &&(j<=m1)) // le reste de la 1ère matrice est nul => on compléte le resultat selon la 2ème matrice
           {    lig2=Ligne(p2);
                col2=Colonne(p2);
                 if ((lig2==i)&&(col2==j))
                 {
                     if (Valeur(p2)>0)
                     {
                        Allouer(&p3);
                        Aff_adr(p3,NULL);
                        if (tete==NULL)
                          tete=p3;
                        else
                          Aff_adr(pre,p3);

                     Aff_ligne(p3,i);
                     Aff_col(p3,j);
                     pre=p3;
                     Aff_val (p3,1);
                     }
                     p2=Suivant(p2);
                     }
                j++;
                 }
            }
         }

     }

   return tete;
}


/**3 NON logique****/
// le résultat est égal à 1 ssi la valeur est nul ou négatif

ptr_mc NON_mc(int n, int m, ptr_mc L) // (n,m) la  taille de la matrice
{
    int i,j,lig,col;
    ptr_mc tete,p1,p2,pre;

        tete=NULL;// un pointeur vers la liste du resultat
        p1=L;// pour parcourir la liste


         for (i=1; i<=n; i++) //la boucle des lignes
    {
        j=1;
        while ((j<= m ) && (p1!=NULL)) //la boucle des colonnes
        {   lig=Ligne(p1);
            col=Colonne(p1);
            if ((lig==i)&&(col==j)) // on vérifie esq la case(i,j) existe ou pas,
            {   if (Valeur(p1)<=0)// si elle existe on doit assure que la valeur est negative avant de créer la nouvelle maillon
               {
                Allouer(&p2);
                Aff_adr(p2,NULL);
                if (tete==NULL)
                    tete=p2;
                else
                    Aff_adr(pre,p2);

                Aff_ligne(p2,i);
                Aff_col(p2,j);
                pre=p2;
                Aff_val (p2,1);
                }
                p1=Suivant(p1);
                }
                else // si la case n'existe pas => leur valeur est nul => le resultat est 1
                {
                    Allouer(&p2);
                Aff_adr(p2,NULL);
                if (tete==NULL)
                    tete=p2;
                else
                    Aff_adr(pre,p2);//on fait le chainnage

                Aff_ligne(p2,i);
                Aff_col(p2,j);
                pre=p2;
                Aff_val (p2,1);
                }
                j++;
                }
                 while (j<=m) // le cas ou le reste de la matrice est nul, on complete le reste avec des 1
                {
                   Allouer(&p2);
                Aff_adr(p2,NULL);
                if (tete==NULL)
                    tete=p2;
                else
                    Aff_adr(pre,p2);//on fait le chainnage

                Aff_ligne(p2,i);
                Aff_col(p2,j);
                pre=p2;
                Aff_val (p2,1);
                j++;

                }
            }
            return tete;
}

