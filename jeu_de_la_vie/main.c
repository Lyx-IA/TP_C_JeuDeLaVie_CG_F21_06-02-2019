#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int main( ) {
   int i;
   FILE *pFile;
   int nbr_cycles;
   int matrice[TAILLE_SUR_MATRICE] [TAILLE_SUR_MATRICE ];
   char s[2];
   printf("Nombre de cycles : ");
   scanf("%i",&nbr_cycles);
   init(matrice);
   printf("La population au depart : \n");
   affiche_matrice(matrice, pFile);
   printf("Pressez sur ENTER pour continuer...\n");
   gets(s);
   for(i=0; i<nbr_cycles; i++) {
      mise_a_jour (matrice);
      printf("La population après %d cycles: \n", i+1);
      affiche_matrice (matrice, pFile);
      printf("Pressez sur ENTER pour continuer...\n");
      gets(s);
        if ((pFile=fopen("etat.txt", "a"))==NULL){

        perror("Erreur de creation de fichier\n");

    } else {

    fprintf(pFile,"La population après %d cycles: \n", i+1);
    fclose(pFile);

    }
   }

   return 0;
}
