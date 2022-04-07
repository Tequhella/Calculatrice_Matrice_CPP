/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : main.cpp                              */
/* Numéro de version : 0.0.4                                 */
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

    if (matrice2.setElement(1, 1, 5))
    {
        cout << "L'élément a bien été modifié." << endl;
        cout << "Element : " << matrice2.getElement(1, 1) << endl;
    }
    else
    {
        cout << "Erreur : l'élément n'a pas pu être modifié" << endl;
    }

    if (matrice3.setNomDeLaMatrice("Matrice 3 modifié"))
    {
        cout << "Le nom a bien été modifié : " << matrice3.getNomDeLaMatrice() << endl;
    }
    else
    {
        cout << "Erreur : le nom n'a pas pu être modifié" << endl;
    }

    if (matrice1.setDimX(5))
    {
        cout << "La dimension X a bien été modifié." << endl;
        matrice1.afficherMatrice(5);
    }
    else
    {
        cout << "Erreur : la dimension X n'a pas pu être modifié" << endl;
    }

    if (matrice1.setDimY(5))
    {
        cout << "La dimension Y a bien été modifié." << endl;
        matrice1.afficherMatrice(5);
    }
    else
    {
        cout << "Erreur : la dimension Y n'a pas pu être modifié" << endl;
    }
    return 0;
}