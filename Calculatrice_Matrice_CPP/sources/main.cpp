/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : main.cpp                              */
/* Numéro de version : 0.0.8                                 */
/* Date              : 07/04/2022                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/


#include "../headers/matrice.h"

int main()
{
    Matrice* matrice1 = new Matrice();
    Matrice* matriceProduit = matrice1->multiplierMatriceParUnReel(10, "Matrice Produit");

    matrice1->afficherMatrice(4);
    matriceProduit->afficherMatrice(4);

    delete matrice1;
    delete matriceProduit;

    return 0;
}