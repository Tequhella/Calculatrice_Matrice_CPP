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
    Matrice* matrice1 = new Matrice("Matrice 1", 5, 5, ALEATOIRE);
    Matrice* matrice2 = new Matrice("Matrice 2", 5, 5, ALEATOIRE);

    Matrice* matriceSomme = matrice1->additionnerMatrice(matrice2, "Matrice Somme");

    matrice1->afficherMatrice(3);
    matrice2->afficherMatrice(3);
    matriceSomme->afficherMatrice(3);

    delete matrice1;
    delete matrice2;
    delete matriceSomme;

    return 0;
}