#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

/****************************************/
/* Initialisation de la matrice */
void init(int matrice [][TAILLE_SUR_MATRICE ]) {
/****************************************/
   int i,j;
   for(i=0; i<TAILLE_SUR_MATRICE; i++) {
      for(j=0; j<TAILLE_SUR_MATRICE; j++) {
         if (i<=j && i>0 && j<=7)
            matrice[i][j]=1;
         else
            matrice[i][j]=0;
      }
   }
}
/****************************************/
/* Calcul du nombre de voisins vivants */
int nombre_voisins (int matrice[][TAILLE_SUR_MATRICE ],
                    int ligne, int colonne) {
/****************************************/
   int compte=0; /* compteur de cellules */
   int i,j;
/* On additionne les 9 cellules centrées en ligne,colonne */
   for (i=ligne-1;i<=ligne+1;i++)
      for(j=colonne-1;j<=colonne+1;j++)
         compte=compte+matrice[i][j];

         compte -= matrice[ligne][colonne];
         return compte;
}
/****************************************/
/* Correspond à l'étape n+1 */
void mise_a_jour(int matrice[ ][TAILLE_SUR_MATRICE ]) {
/****************************************/
   int i,j;
   int nbr_voisins;
   int matrice_densite[TAILLE_SOUS_MATRICE][TAILLE_SOUS_MATRICE];
   for(i=0; i< TAILLE_SOUS_MATRICE; i++)
         for(j=0; j< TAILLE_SOUS_MATRICE; j++)
            matrice_densite[i][j]=nombre_voisins(matrice,i+1,j+1);

   for(i=0; i< TAILLE_SOUS_MATRICE; i++)
      for(j=0; j< TAILLE_SOUS_MATRICE; j++) {
            nbr_voisins=matrice_densite[i][j];
            if(nbr_voisins==2)
                  matrice[i+1][j+1]=1;
            else if (nbr_voisins==0 || nbr_voisins==4)
                  matrice[i+1][j+1]=0;
   }
}

/****************************************/
/* Affichage à l'écran des cellules vivantes */
void affiche_matrice(int matrice[ ][TAILLE_SUR_MATRICE ], FILE *pFile) {
/****************************************/

   int i,j;

     if ((pFile=fopen("etat.txt", "a"))==NULL){

        perror("Erreur de creation de fichier\n");

    } else {

    for(i=1; i<=TAILLE_SOUS_MATRICE; i++) {
      ligne(7);
      for(j=1; j<= TAILLE_SOUS_MATRICE; j++)
         if (matrice[i][j]==1)
            {
            printf("|%c",'*');
            fputc ( '*', pFile );
            }
         else{
            printf("|%c",'|');
            fputc ( '|', pFile );
            }
      printf("|\n");
      fputs("|\n",pFile);

   }
   ligne(TAILLE_SOUS_MATRICE);
   fclose (pFile);
    }

}
/****************************************/
/* Tracé d'une ligne */
void ligne(int largeur) {
/****************************************/
   int i;
   for(i=0; i<largeur; i++)
      printf("+-");
   printf("+\n");
}
