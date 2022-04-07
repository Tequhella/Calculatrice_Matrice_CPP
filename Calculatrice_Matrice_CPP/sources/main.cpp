/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : main.cpp                              */
/* Numéro de version : 0.0.3                                 */
/* Date              : 07/04/2022                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/


#include "../headers/matrice.h"

int main()
{
    Matrice matrice;
    Matrice matrice1("Matrice 1", 3, 3, NULLE);
    Matrice matrice2("Matrice 2", 3, 3, IDENTITE);
    Matrice matrice3("Matrice 3", 3, 3, ALEATOIRE);

    matrice.afficherMatrice(5);
    matrice1.afficherMatrice(5);
    matrice2.afficherMatrice(5);
    matrice3.afficherMatrice(5);

    cout << matrice2.getNomDeLaMatrice() << endl;
    cout << "Dimesenion : {" << (int)matrice2.getDimX() << ", " << (int)matrice2.getDimY() << "}" << endl;
    cout << "Element : " << matrice2.getElement(1, 1) << endl;
    return 0;
}