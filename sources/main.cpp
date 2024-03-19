/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : main.cpp                              */
/* Numéro de version : 0.0.13                                */
/* Date              : 19/04/2022                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/


#include "../headers/matrice.h"

int main()
{
    Matrice* matrice1 = new Matrice("Matrice 1", 5, 5, ALEATOIRE);
    //Matrice* matrice2 = new Matrice("Matrice 2", 5, 5, ALEATOIRE);
    matrice1->afficherMatrice(10);
    //matrice2->afficherMatrice(10);

    Matrice* matriceInversee = matrice1->inverserMatrice("Matrice 1 inversée");
    matriceInversee->afficherMatrice(10); 

    cout << "Nombre de matrice créées : " << Matrice::nbMatriceCrees << endl;

    delete matrice1;
    //delete matrice2;
    delete matriceInversee;

    cout << "Nombre de matrice détruites : " << Matrice::nbMatriceDetruites << endl;

    return 0;
}

