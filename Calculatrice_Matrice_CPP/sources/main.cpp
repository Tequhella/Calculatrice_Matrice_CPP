/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : main.cpp                              */
/* Numéro de version : 0.0.5                                 */
/* Date              : 07/04/2022                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/


#include "../headers/matrice.h"

int main()
{
    Matrice* matrice = new Matrice("Matrice 1", 5, 5, ALEATOIRE);
    
    Matrice* matrice2 = matrice->transposerMatrice();

    matrice->afficherMatrice(3);
    matrice2->afficherMatrice(3);

    delete matrice;
    delete matrice2;

    return 0;
}