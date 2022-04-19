/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : main.cpp                              */
/* Numéro de version : 0.0.12                                */
/* Date              : 19/04/2022                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/


#include "../headers/matrice.h"

int main()
{
    Matrice* matrice = new Matrice("Matrice 1", 5, 5, ALEATOIRE);
    Matrice* matrice2 = matrice->diviserMatriceParUnReel(2, "Matrice Divisée");
    matrice->afficherMatrice(10);
    matrice2->afficherMatrice(10);

    matrice->afficherTailleMatriceOctet();

    delete matrice;
    delete matrice2;

    return 0;
}

