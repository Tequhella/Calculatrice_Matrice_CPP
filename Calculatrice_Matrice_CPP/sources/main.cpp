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
    Matrice* matrice1 = new Matrice("Matrice 1", 3, 3, ALEATOIRE);
    Matrice* matrice2 = new Matrice("Matrice 2", 2, 3, ALEATOIRE);
    Matrice* matriceProduit = matrice1->multiplierMatriceParUneMatrice(matrice2, "Matrice Produit");

    matrice1->afficherMatrice(4);
    matrice2->afficherMatrice(4);
    matriceProduit->afficherMatrice(6);

    delete matrice1;
    delete matrice2;
    delete matriceProduit;

    return 0;
}