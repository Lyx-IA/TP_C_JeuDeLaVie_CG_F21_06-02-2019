#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

#define TAILLE_SOUS_MATRICE 7
#define TAILLE_SUR_MATRICE  9

#pragma once

extern void init(int matrice [][TAILLE_SUR_MATRICE ]);
extern int nombre_voisins (int matrice [][TAILLE_SUR_MATRICE ],
                    int ligne, int colonne);
extern void mise_a_jour(int matrice[][TAILLE_SUR_MATRICE ]);
extern void affiche_matrice(int matrice [][TAILLE_SUR_MATRICE ], FILE *pFile);
extern void ligne(int largeur);


#endif // PROTOTYPES_H_INCLUDED

