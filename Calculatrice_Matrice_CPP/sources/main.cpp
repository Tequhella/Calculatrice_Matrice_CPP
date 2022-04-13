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
    Matrice* matrice = new Matrice("Matrice 1", 4, 4, ALEATOIRE);
    matrice->afficherMatrice(10);

    cout << matrice->calculerDeterminant() << endl;

    delete matrice;

    return 0;
}