/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : matrice.cpp                           */
/* Numéro de version : 0.0.3                                 */
/* Date              : 07/04/2022                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/

#include "../headers/matrice.h"

/*
* Crée une matrice de dimensions aléatoire de 0 à 255, de valeurs aléatoires, et de nom aléatoire.
*/
Matrice::Matrice()
{
    srand(time(NULL));
	this->dimX = rand() % 50;
	this->dimY = rand() % 50;
	this->nomDeLaMatrice = "Matrice Hasard";
	this->elements = new double[this->dimX * this->dimY];

    if (this->elements)
    {
        for (int i = 0; i < this->dimY; i++)
        {
            for (int j = 0; j < this->dimX; j++)
            {
                this->elements[this->dimX * i + j] = rand() % 500;
            }
        }
    }
    else
    {
        cout << "Erreur d'allocation de la matrice" << endl;
    }
}

/**
 * Crée une matrice avec les dimensions données et la remplit selon le type
 *
 * @param nomDeLaMatrice le nom de la matrice
 * @param dimX le nombre de lignes dans la matrice
 * @param dimY le nombre de lignes dans la matrice
 * @param type 1 pour la matrice d'identité, 2 pour la matrice aléatoire
 *
 * @return Un pointeur vers une structure Matrice nouvellement allouée.
 */
Matrice::Matrice(char* nomDeLaMatrice, uint8_t dimX, uint8_t dimY, uint8_t type) : dimX(dimX), dimY(dimY), nomDeLaMatrice(nomDeLaMatrice)
{
    this->elements = new double[this->dimX * this->dimY];

    if (this->elements)
    {
        switch (type)
        {
            case NULLE:
                for (int i = 0; i < this->dimY; i++)
                {
                    for (int j = 0; j < this->dimX; j++)
                    {
                        this->elements[this->dimX * i + j] = 0;
                    }
                }
                break;
            case IDENTITE:
                for (int i = 0; i < this->dimY; i++)
                {
                    for (int j = 0; j < this->dimX; j++)
                    {
                        if (i == j)
                        {
                            this->elements[this->dimX * i + j] = 1;
                        }
                        else
                        {
                            this->elements[this->dimX * i + j] = 0;
                        }
                    }
                }
                break;
            case ALEATOIRE:
                for (int i = 0; i < this->dimY; i++)
                {
                    for (int j = 0; j < this->dimX; j++)
                    {
                        this->elements[this->dimX * i + j] = rand() % 500;
                    }
                }
                break;
        }
    }
    else
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
    }
}

Matrice::~Matrice()
{
    delete[] this->elements;
}

//=======================================================================================//

/**
* Méthode afficherMatrice, imprime la matrice
*
* @param format le nombre de caractères à afficher pour chaque élément.
*/
void Matrice::afficherMatrice(uint8_t format)
{
    cout.precision(format);
	cout << this->nomDeLaMatrice << endl;

	for (int i = 0; i < this->dimY; i++)
	{
		for (int j = 0; j < this->dimX; j++)
		{
			cout << this->elements[this->dimX * i + j] << " ";
		}
		cout << endl;
	}
}

//=======================================================================================//

/**
 * Méthode getDimX, retourne la dimension en X de la matrice
 * 
 */
uint8_t Matrice::getDimX()
{
    return this->dimX;
}

/**
 * Méthode getDimY, retourne la dimension en Y de la matrice
 * 
 */
uint8_t Matrice::getDimY()
{
    return this->dimY;
}

/**
 * Méthode getNomDeLaMatrice, retourne le nom de la matrice
 * 
 */
char* Matrice::getNomDeLaMatrice()
{
    return this->nomDeLaMatrice;
}

/**
 * Méthode getElement, retourne l'élément de la matrice à la position donnée
 *
 * @param x la position en X de l'élément à retourner
 * @param y la position en Y de l'élément à retourner
 *
 * @return l'élément de la matrice à la position donnée
 */
double Matrice::getElement(uint8_t x, uint8_t y)
{
    if (x < this->dimX && y < this->dimY) /*--->*/ return this->elements[this->dimX * y + x];
    else
    {
        cout << "Erreur : la position de l'élément est invalide" << endl;
        return 0;
    }
}