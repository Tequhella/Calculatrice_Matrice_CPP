#ifndef _FONCTION_H_INCLUDED_
#define _FONCTION_H_INCLUDED_

#include "type.h"
#include <stdio.h>
#include <stdlib.h>

//-----------------------Gestion Matrice---------------------//

Matrice* creerMatrice (char* _nomDeLaMatrice, unsigned int _dimX, unsigned int _dimY, unsigned int type);

void detruireMatrice (Matrice* m);

void afficherMatrice (Matrice* m, unsigned int format1, unsigned int format2);

Matrice* transposerMatrice (Matrice* m, char* nomMatriceTrp);

Matrice* additionnerMatrice (Matrice* mA, Matrice* mB, char* nomMatriceSomme);

Matrice* soustraireMatrice (Matrice* mA, Matrice* mB, char* nomMatriceDifference);

Matrice* multiplierMatriceParUnReel (Matrice* m, double reel, char* nomMatriceProduit);

Matrice* multiplierMatrice (Matrice* mA, Matrice* mB, char* nomMatriceProduit);

Matrice* creerSousMatrice (Matrice* m, unsigned int l, unsigned int c);

double calculerDeterminantMatrice (Matrice* m);

Matrice* inverserMatrice (Matrice* m, char* nomDeLaMatriceInversee);

//-----------------------Nom de la Matrice-----------------------//

char* getNom (Matrice* m);

void setNom (Matrice* m, char* nom);

//-----------------------Dimension Matrice-----------------------//

unsigned int getDimX (Matrice* m);

unsigned int getDimY (Matrice* m);

void setDimX (Matrice* m, unsigned int newDimX);

void setDimY (Matrice* m, unsigned int newDimY);

//-----------------------Elements Matrice------------------------//

unsigned int getElement (Matrice* m, unsigned int x, unsigned int y, double* search);

unsigned int setElement (Matrice* m, unsigned int x, unsigned y, double ajout);

#endif