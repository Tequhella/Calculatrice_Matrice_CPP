/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : matrice.cpp                           */
/* Numéro de version : 0.0.15                                */
/* Date              : 05/04/2024                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/

#include "../headers/matrice.h"
#include "../headers/fractionizer.h"

int Matrice::nbMatriceCrees = 0;
int Matrice::nbMatriceDetruites = 0;

/**
 * @brief Constructeur Matrice, crée une matrice de dimensions aléatoire de 0 à 255, de valeurs aléatoires, et de nom aléatoire.
 */
Matrice::Matrice()
{

    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<uint8_t> distr(1, 20);
    uniform_int_distribution<uint8_t> distr2(1, 100);

    this->dimX = distr(eng);
    this->dimY = distr(eng);

    cout << "DimX = " << (int)dimX << endl;
    cout << "DimY = " << (int)dimY << endl;

    this->nomDeLaMatrice = "Matrice Hasard";
    this->elements = new double[this->dimX * this->dimY];

    if (this->elements)
    {
        for (int i = 0; i < this->dimY; i++)
        {
            for (int j = 0; j < this->dimX; j++)
            {
                this->setElement(j, i, distr2(eng));
            }
        }
        numMatrice = nbMatriceCrees;
        nbMatriceCrees++;
    }
    else
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Constructeur Matrice, crée une matrice avec les dimensions données et la remplit selon le type.
 *
 * @param nomDeLaMatrice le nom de la matrice
 * @param dimX le nombre de lignes dans la matrice
 * @param dimY le nombre de lignes dans la matrice
 * @param type 1 pour la matrice d'identité, 2 pour la matrice aléatoire
 *
 * @return Un pointeur vers une structure Matrice nouvellement allouée.
 */
Matrice::Matrice(const char* nomDeLaMatrice, uint8_t dimX, uint8_t dimY, uint8_t type) : dimX(dimX), dimY(dimY), nomDeLaMatrice(nomDeLaMatrice)
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<uint8_t> distr(1, 100);

    this->elements = new double[this->dimX * this->dimY];
    /* Pour accéder à un élément de la matrice, on utilise la formule suivante :
     * elements[dimX * i + j]
     * où i est la ligne et j la colonne
     */

    if (this->elements)
    {
        switch (type)
        {
        case NULLE:
            for (int i = 0; i < this->dimY; i++)
                for (int j = 0; j < this->dimX; j++)
                    this->setElement(j, i, 0);
            break;
        case IDENTITE:
            for (int i = 0; i < this->dimY; i++)
                for (int j = 0; j < this->dimX; j++)
                {
                    if (i == j) /*--->*/ this->setElement(j, i, 1);
                    else /*---------->*/ this->setElement(j, i, 0);
                }
            break;
        case ALEATOIRE:
            for (int i = 0; i < this->dimY; i++)
                for (int j = 0; j < this->dimX; j++)
                    this->setElement(j, i, distr(eng));
            break;
        }
        numMatrice = nbMatriceCrees;
        nbMatriceCrees++;
    }
    else
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
        exit(EXIT_FAILURE);
    }
}

Matrice::~Matrice()
{
    delete[] this->elements;
    nbMatriceDetruites++;
}

//=======================================================================================//

long gcd(long a, long b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}

/**
 * @brief Méthode afficherMatrice, imprime la matrice.
 *
 * @param format le nombre de caractères à afficher pour chaque élément.
 */
void Matrice::afficherMatrice(uint8_t format)
{
    cout.precision(format);
    cout << endl << this->nomDeLaMatrice << endl;

    for (int i = 0; i < this->dimY; i++)
    {
        for (int j = 0; j < this->dimX; j++)
        {
            double input = this->getElement(j, i);
            double integral = std::floor(input);
            double frac = input - integral;

            if (frac == 0) // Si l'élément est un entier
            {
                cout << integral << " ";
            }
            else // Si l'élément est un nombre décimal
            {
                double num, denom;
                Fractionizer::fractionize(input, num, denom);
                cout << num << "/" << denom << " ";
            }
        }
        cout << endl;
    }
}

/**
 * @brief afficherTailleMatriceOctet, affiche la taille de la matrice en octet.
 */
void Matrice::afficherTailleMatriceOctet()
{
    cout << "La taille de la matrice en octet est de " << sizeof(this) << " octets." << endl;
    cout << "La taille du tableau d'éléments de la matrice est de " << sizeof(this->elements) * this->dimX * this->dimY << " octets." << endl;
}

/**
 * @brief Méthode transposerMatrice, transpose la matrice.
 * 
 * @param nomDeLaMatriceTransposee le nom de la matrice transposée
 *
 * @return la matrice transposée.
 */
Matrice* Matrice::transposerMatrice(const char* nomDeLaMatriceTransposee)
{
    Matrice *matriceTransposee = new Matrice(nomDeLaMatriceTransposee, this->dimX, this->dimY, NULLE);

    if (matriceTransposee)
    {
        for (int i = 0; i < this->dimY; i++)
        {
            for (int j = 0; j < this->dimX; j++)
            {
                matriceTransposee->setElement(j, i, this->getElement(i, j));
            }
        }

        return matriceTransposee;
    }
    else
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
        return nullptr;
    }
}

/**
 * @brief Méthode additionnerMatrice, additionne deux matrice.
 *
 * @param matriceAdditionneur la matrice qui s'ajoutera à la matrice actuelle.
 * @param nomDeLaMatriceSomme le nom de la matrice issue de l'addition.
 *
 * @return la matrice issue de l'addition.
 */
Matrice* Matrice::additionnerMatrice(Matrice* matriceAdditionneur, const char* nomDeLaMatriceSomme)
{
    if (this->dimX == matriceAdditionneur->getDimX() && this->dimY == matriceAdditionneur->getDimY())
    {
        Matrice *matriceSomme = new Matrice(nomDeLaMatriceSomme, this->dimX, this->dimY, NULLE);

        if (matriceSomme)
        {
            for (int i = 0; i < this->dimY; i++)
            {
                for (int j = 0; j < this->dimX; j++)
                {
                    matriceSomme->setElement(j, i, this->getElement(j, i) + matriceAdditionneur->getElement(j, i));
                }
            }

            return matriceSomme;
        }
        else
        {
            cerr << "Erreur d'allocation de la matrice" << endl;
            return nullptr;
        }
    }
    else
    {
        cerr << "Les matrices ne sont pas de même dimensions" << endl;
        return nullptr;
    }
}

/**
 * @brief Méthode soustraireMatrice, soustrait deux matrice.
 *
 * @param matriceSoustrait la matrice qui sera soustraite à la matrice actuelle.
 * @param nomDeLaMatriceSoustraite le nom de la matrice issue de la soustraction.
 *
 * @return la matrice issue de la soustraction.
 */
Matrice *Matrice::soustraireMatrice(Matrice* matriceSoustrait, const char* nomDeLaMatriceSoustraite)
{
    if (this->dimX == matriceSoustrait->getDimX() && this->dimY == matriceSoustrait->getDimY())
    {
        Matrice *matriceSoustraite = new Matrice(nomDeLaMatriceSoustraite, this->dimX, this->dimY, NULLE);

        if (matriceSoustraite)
        {
            for (int i = 0; i < this->dimY; i++)
            {
                for (int j = 0; j < this->dimX; j++)
                {
                    matriceSoustraite->setElement(j, i, this->getElement(j, i) - matriceSoustrait->getElement(j, i));
                }
            }

            return matriceSoustraite;
        }
        else
        {
            cerr << "Erreur d'allocation de la matrice" << endl;
            return nullptr;
        }
    }
    else
    {
        cerr << "Les matrices ne sont pas de même dimensions" << endl;
        return nullptr;
    }
}

/**
 * @brief Méthode multiplierMatriceParUnReel, multiplie la matrice par un nombre réel.
 * 
 * @param nb 
 * @param nomDeLaMatriceProduitReel 
 * @return la matrice issue de la multiplication.
 */
Matrice* Matrice::multiplierMatriceParUnReel(double nb, const char* nomDeLaMatriceProduitReel)
{
    Matrice* matriceProduitReel = new Matrice(nomDeLaMatriceProduitReel, this->dimX, this->dimY, NULLE);
    if (matriceProduitReel)
    {
        for (int i = 0; i < this->getDimY(); i++)
        {
            for (int j = 0; j < this->getDimX(); j++)
            {
                matriceProduitReel->elements[dimX * i + j] = this->getElement(j, i) * nb;
            }
        }
        return matriceProduitReel;
    }
    else
    {
        return nullptr;
    }
}

/**
 * @brief Méthode multiplierMatriceParUneMatrice, multiplie la matrice par une autre matrice.
 * 
 * @param matriceMultiplieur la matrice qui sera multipliée à la matrice actuelle.
 * @param nomDeLaMatriceProduit la matrice issue de la multiplication.
 * 
 * @return la matrice issue de la multiplication.
 */
Matrice* Matrice::multiplierMatriceParUneMatrice(Matrice* matriceMultiplieur, const char* nomDeLaMatriceProduit)
{
    if (this->dimY != matriceMultiplieur->dimY)
    {
        cerr << "Les matrices ne sont pas compatibles pour la multiplication" << endl;
        return nullptr;
    }

    Matrice* matriceProduit = new Matrice(nomDeLaMatriceProduit, matriceMultiplieur->dimX, matriceMultiplieur->dimY, NULLE);
    if (!matriceProduit)
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
        return nullptr;
        
    }

    for (int i = 0; i < this->dimY; i++)
    {
        for (int j = 0; j < matriceMultiplieur->dimX; j++)
        {
            double somme = 0;
            for (int k = 0; k < this->dimX; k++)
            {
                somme += this->getElement(k, i) * matriceMultiplieur->getElement(j, k);
            }
            matriceProduit->setElement(j, i, somme);
        }
    }
    return matriceProduit;
}

/**
 * @brief sousMatrice, retourne une sous-matrice de la matrice.
 * 
 * @param ligneDebut la ligne de début de la sous-matrice.
 * @param colonneDebut la colonne de début de la sous-matrice.
 * @param nomDeLaMatriceSousMatrice le nom de la sous-matrice.
 * 
 * @return la sous-matrice.
 */
Matrice* Matrice::sousMatrice(uint8_t colonneDebut, uint8_t ligneDebut, const char* nomDeLaMatriceSousMatrice)
{
    Matrice* matriceSousMatrice = new Matrice(nomDeLaMatriceSousMatrice, this->dimX - 1, this->dimY - 1, NULLE);
    if (matriceSousMatrice)
    {
        uint8_t kx = 0, ky = 0;
        for (int i = 0; i < this->dimY; i++)
        {
            if (i != ligneDebut)
            {
                for (int j = 0; j < this->dimX; j++)
                {
                    if (j != colonneDebut)
                    {
                        matriceSousMatrice->setElement(kx, ky, this->getElement(j, i));
                        kx++;
                        if (kx >= matriceSousMatrice->dimX)
                        {
                            kx = 0;
                            ky++;
                        }
                    }
                }
            }
        }
        return matriceSousMatrice;
    }
    else
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
        return nullptr;
    }
}

/**
 * @brief calculerDeterminant, calcule le déterminant de la matrice.
 * 
 * @return le déterminant de la matrice.
 */
double Matrice::calculerDeterminant()
{
    if (this->dimX == this->dimY)
    {
        double determinant = 0;
        if (this->dimX == 1)
        {
            return this->getElement(0, 0);
        }
        else if (this->dimX == 2)
        {
            return this->getElement(0, 0) * this->getElement(1, 1) - this->getElement(0, 1) * this->getElement(1, 0);
        }
        else
        {
            for (int i = 0; i < this->dimX; i++)
            {
                Matrice* matriceSousMatrice = this->sousMatrice(i, 0, "sousMatrice");
                if (matriceSousMatrice)
                {
                    if (i % 2 == 0) /*--->*/ determinant = determinant + this->getElement(i, 0) * matriceSousMatrice->calculerDeterminant();
                    else /*-------------->*/ determinant = determinant - this->getElement(i, 0) * matriceSousMatrice->calculerDeterminant();
                    
                    delete matriceSousMatrice;
                }
                else
                {
                    cerr << "Erreur d'allocation de la matrice" << endl;
                    return 0;
                }
            }
            return determinant;
            
        }
    }
    else
    {
        cerr << "La matrice n'est pas carrée" << endl;
        return 0;
    }
}

/**
 * @brief inverserMatrice, inverse la matrice.
 * 
 * @param nomDeLaMatriceInverse la matrice issue de l'inversion.
 * 
 * @return la matrice issue de l'inversion.
 */
Matrice* Matrice::inverserMatrice(const char* nomDeLaMatriceInverse)
{
    Matrice* matriceInverse = new Matrice(nomDeLaMatriceInverse, this->dimX, this->dimY, NULLE);
    if (matriceInverse)
    {
        double determinant = this->calculerDeterminant();
        if (determinant != 0)
        {
            for (int i = 0; i < this->dimY; i++)
            {
                for (int j = 0; j < this->dimX; j++)
                {
                    Matrice* matriceSousMatrice = this->sousMatrice(i, j, "sousMatrice");
                    if (matriceSousMatrice)
                    {
                        double coeff = pow(-1, i + j) * matriceSousMatrice->calculerDeterminant();
                        matriceInverse->setElement(j, i, coeff / determinant);
                        delete matriceSousMatrice;
                    }
                    else
                    {
                        cerr << "Erreur d'allocation de la matrice" << endl;
                        return nullptr;
                    }
                }
            }
            return matriceInverse;
        }
        else
        {
            cerr << "La matrice n'est pas inversible" << endl;
            return nullptr;
        }
    }
    else
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
        return nullptr;
    }
}

/**
 * @brief diviserMatriceParUnReel, divise la matrice par un nombre réel.
 * 
 * @param nb le nombre qui sera divisé par la matrice.
 * @param nomDeLaMatriceDivisee le nom de la matrice issue de la division.
 * 
 * @return la matrice issue de la division.
 */
Matrice* Matrice::diviserMatriceParUnReel(double nb, const char* nomDeLaMatriceDivisee)
{
    Matrice* matriceDivisee = new Matrice(nomDeLaMatriceDivisee, this->dimX, this->dimY, NULLE);
    if (matriceDivisee)
    {
        for (int i = 0; i < this->dimY; i++)
        {
            for (int j = 0; j < this->dimX; j++)
            {
                matriceDivisee->setElement(j, i, this->getElement(j, i) / nb);
            }
        }
        return matriceDivisee;
    }
    else
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
        return nullptr;
    }
}

/**
 * @brief diviserMatriceParUneMatrice, divise la matrice par une autre matrice.
 * 
 * @param matriceDiviseur la matrice qui divise la matrice actuelle.
 * @param nomDeLaMatriceDivisee le nom de la matrice issue de la division.
 * @return Matrice* la matrice issue de la division.
 */
Matrice* Matrice::diviserMatriceParUneMatrice(Matrice* matriceDiviseur, const char* nomDeLaMatriceDivisee)
{
    Matrice* matriceInverse = matriceDiviseur->inverserMatrice("matriceInverse");
    if (matriceInverse)
    {
        Matrice* matriceDivisee = this->multiplierMatriceParUneMatrice(matriceInverse, nomDeLaMatriceDivisee);
        delete matriceInverse;
        return matriceDivisee;
    }
    else
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
        return nullptr;
    }
}

//=======================================================================================//

/**
 * @brief Méthode getDimX, retourne la dimension en X de la matrice.
 *
 */
uint8_t Matrice::getDimX()
{
    return this->dimX;
}

/**
 * @brief Méthode getDimY, retourne la dimension en Y de la matrice.
 *
 */
uint8_t Matrice::getDimY()
{
    return this->dimY;
}

/**
 * @brief Méthode getNomDeLaMatrice, retourne le nom de la matrice.
 *
 */
const char *Matrice::getNomDeLaMatrice()
{
    return this->nomDeLaMatrice;
}

/**
 * @brief Méthode getElement, retourne l'élément de la matrice à la position donnée.
 *
 * @param x la position en X de l'élément à retourner.
 * @param y la position en Y de l'élément à retourner.
 *
 * @return l'élément de la matrice à la position donnée.
 */
double Matrice::getElement(uint8_t x, uint8_t y)
{
    if (x < this->dimX && y < this->dimY) /*--->*/ return this->elements[this->dimX * y + x];
    else
    {
        cerr << "Erreur : la position du getter est invalide" << endl;
        return 0;
    }
}

/**
 * @brief Méthode getNumMatrice, retourne le numéro de la matrice.
 * 
 */
uint8_t Matrice::getNumMatrice()
{
    return this->numMatrice;
}

/**
 * @brief Méthode setElement, modifie l'élément de la matrice à la position donnée.
 *
 * @param x la position en X de l'élément à modifier.
 * @param y la position en Y de l'élément à modifier.
 * @param valeur la nouvelle valeur de l'élément à modifier.
 *
 * @return 2 si les coordonnées sont invalides, 1 si la modification a pu se faire, 0 sinon.
 */
uint8_t Matrice::setElement(uint8_t x, uint8_t y, double valeur)
{
    if (x < this->dimX && y < this->dimY)
    {
        this->elements[this->dimX * y + x] = valeur;

        if (this->elements[this->dimX * y + x] == valeur) /*--->*/ return 1;
        else
        {
            cerr << "Erreur : le changement de valeur ne s'est pas produit" << endl;
            return 0;
        }
    }
    else 
    {
        cerr << "Erreur : la position du setter est invalide" << endl;
        return 2;
    }
}

/**
 * @brief Méthode setNomDeLaMatrice, modifie le nom de la matrice.
 *
 * @param nomDeLaMatrice le nouveau nom de la matrice.
 *
 * @return 1 si la modification a pu se faire, 0 sinon.
 */
uint8_t Matrice::setNomDeLaMatrice(const char* nomDeLaMatrice)
{
    this->nomDeLaMatrice = nomDeLaMatrice;

    if (this->nomDeLaMatrice == nomDeLaMatrice) /*--->*/ return 1;
    else /*--->*/ return 0;
}

/**
 * @brief Méthode setDimX, modifie la dimension en X de la matrice en créant une nouvelle matrice.
 *
 * @param dimX la nouvelle dimension en X de la matrice.
 *
 * @return 1 si la modification a pu se faire, 0 sinon.
 */
uint8_t Matrice::setDimX(uint8_t dimX)
{
    double *elements = new double[dimX * this->dimY];

    if (elements)
    {
        for (int i = 0; i < this->dimY; i++)
        {
            for (int j = 0; j < dimX; j++)
            {
                if (j < this->dimX)
                {
                    elements[dimX * i + j] = this->getElement(j, i);
                }
                else
                {
                    elements[dimX * i + j] = 0;
                }
            }
        }

        delete[] this->elements;
        this->elements = elements;
        this->dimX = dimX;

        if (this->dimX == dimX) /*--->*/ return 1;
        else /*--->*/ return 0;
    }
    else
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
        return 0;
    }
}


/**
 * @brief Méthode setDimY, modifie la dimension en Y de la matrice en créant une nouvelle matrice
 *
 * @param dimY la nouvelle dimension en Y de la matrice
 *
 * @return 1 si la modification a pu se faire, 0 sinon
 */
uint8_t Matrice::setDimY(uint8_t dimY)
{
    double *elements = new double[this->dimX * dimY];

    if (elements)
    {
        for (int i = 0; i < dimY; i++)
        {
            for (int j = 0; j < this->dimX; j++)
            {
                if (i < this->dimY)
                {
                    elements[this->dimX * i + j] = this->getElement(j, i);
                }
                else
                {
                    elements[this->dimX * i + j] = 0;
                }
            }
        }

        delete[] this->elements;
        this->elements = elements;
        this->dimY = dimY;

        if (this->dimY == dimY) /*--->*/ return 1;
        else /*--->*/ return 0;
    }
    else
    {
        cerr << "Erreur d'allocation de la matrice" << endl;
        return 0;
    }
}
