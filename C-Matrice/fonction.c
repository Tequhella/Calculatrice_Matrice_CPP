#include "fonction.h"

//-----------------------Gestion Matrice---------------------//

Matrice* creerMatrice (char* _nomDeLaMatrice, unsigned int _dimX, unsigned int _dimY, unsigned int type)
{
    Matrice* m = (Matrice*) calloc (1, sizeof(Matrice));

    if (m)
    {
        if (_dimX == 0 || _dimY == 0)
        {
            m->elements = NULL;
            m->dimX     = 0;
            m->dimY     = 0;
        }
        else
        {
            m->elements = (double*) calloc (_dimX*_dimY, sizeof(double));

            if (m->elements)
            {
                m->dimX = _dimX;
                m->dimY = _dimY;
            }
            else
            {
                free (m);
                m = NULL;
            }
            
        }

        switch (type)
        {
        case 1:
            for (unsigned int i = 0; i < _dimY; i++)
                for (unsigned int j = 0; j < _dimX; j++)
                    if (i == j) /*--->*/ m->elements[_dimX*i+j] = 1;

            break;

        case 2:
            for (unsigned int i = 0; i < _dimY*_dimX; i++)
                m->elements[i] = rand()%100+1;
        }

        m->nomDeLaMatrice = _nomDeLaMatrice;
        
    }

    return m;
}

void detruireMatrice (Matrice* m)
{
    if (m)
    {
        if (m->elements) /*--->*/ free (m);
        
        free (m);
    }
    
}

void afficherMatrice (Matrice* m, unsigned int format1, unsigned int format2)
{
    if (m)
    {
        if (m->elements)
        {
            printf ("Matrice %s : \n", m->nomDeLaMatrice);
            for (unsigned int i = 0; i < m->dimY; i++)
            {
                for (unsigned int j = 0; j < m->dimX; j++)
                    printf ("%*.*lf ", format1, format2, m->elements[m->dimX*i+j]);
                printf ("\n");
                
            }

        }
        
    }
    
}

Matrice* transposerMatrice (Matrice* m, char* nomMatriceTrp)
{
    Matrice* trp = creerMatrice (nomMatriceTrp, m->dimY, m->dimX, NULLE);

    if (m && trp)
        if (m->elements && trp->elements)
            for (unsigned int i = 0; i < trp->dimY; i++)
                for (unsigned int j = 0; j < trp->dimX; j++)
                    trp->elements[trp->dimX*j+i] = m->elements[m->dimX*i+j];
                    

    return trp;
}

Matrice* additionnerMatrice (Matrice* mA, Matrice* mB, char* nomMatriceSomme)
{
    Matrice* mSomme = creerMatrice(nomMatriceSomme, mA->dimX, mA->dimY, NULLE);

    if (mA && mB)
    {
        if (mA->dimX == mB->dimX && mA->dimY == mB->dimY)
            for (unsigned int i = 0; i < mA->dimX*mA->dimY; i++)
                mSomme->elements[i] = mA->elements[i] + mB->elements[i];
        else
            printf ("Impossible d'additionner : les 2 matrices n'ont pas les mêmes dimensions.\n");
    }

    return mSomme;
    
}

Matrice* soustraireMatrice (Matrice* mA, Matrice* mB, char* nomMatriceDifference)
{
    Matrice* mDifference = creerMatrice (nomMatriceDifference, mA->dimX, mA->dimY, NULLE);

    if (mA && mB)
    {
        if (mA->dimX == mB->dimX && mA->dimY == mB->dimY)
            for (unsigned int i = 0; i < mA->dimX*mA->dimY; i++)
                mDifference->elements[i] = mA->elements[i] - mB->elements[i];
        else
            printf ("Impossible de soustraire : les 2 matrices n'ont pas les mêmes dimensions.\n");
    }

    return mDifference;
    
}

Matrice* multiplierMatriceParUnReel (Matrice* m, double reel, char* nomMatriceProduit)
{
    Matrice* mProduit = creerMatrice (nomMatriceProduit, m->dimX, m->dimY, NULLE);

    if (m)
        for (unsigned int i = 0; i < m->dimX*m->dimY; i++)
            mProduit->elements[i] = m->elements[i] * reel;
            
    return mProduit;
}

Matrice* multiplierMatrice (Matrice* mA, Matrice* mB, char* nomMatriceProduit)
{
    Matrice* mProduit = creerMatrice (nomMatriceProduit, mB->dimX, mB->dimY, NULLE);

    if (mA && mB)
    {
        for (unsigned int i = 0; i < mA->dimY; i++)
            for (unsigned int j = 0; j < mB->dimX; j++)
            {
                double somme = 0;
                for (unsigned int k = 0; k < mB->dimY; k++)
                {
                    somme = somme + mA->elements[mA->dimX * i + k] * mB->elements[mB->dimX * k + j];
                }
                mProduit->elements[mProduit->dimX * i + j] = somme;
            }
            
    }

    return mProduit;
    
}

Matrice* creerSousMatrice (Matrice* m, unsigned int l, unsigned int c)
{
    Matrice* sous_Matrice = creerMatrice (m->nomDeLaMatrice, m->dimX-1, m->dimY-1, NULLE);

    unsigned int k = 0;

    if (sous_Matrice)
    {
        for (unsigned int i = 0; i < m->dimY; i++)
        {
            for (unsigned int j = 0; j < m->dimX; j++)
            {
                if (i == l || j == c);
                else
                {
                    sous_Matrice->elements[k] = m->elements[m->dimX*i + j];
                    k++;
                } 
            }
        }
    }
    
    return sous_Matrice;
}

double calculerDeterminantMatrice (Matrice* m)
{
    double determinant = 0;

    if (m)
    {
        if (m->dimX == m->dimY)
        {
            if (m->dimX == 2) /*--->*/ determinant = m->elements[0] * m->elements[3] - m->elements[1] * m->elements[2];
            
            else
            {
                for (unsigned int j = 0; j < m->dimX; j++)
                {
                    Matrice* sousMat = creerSousMatrice (m, 0, j);
                    if (sousMat->dimX > 2)
                    {
                        if (j%2 == 0) /*--->*/ determinant = determinant + m->elements[j] * calculerDeterminantMatrice(sousMat);
                        else /*------------>*/ determinant = determinant - m->elements[j] * calculerDeterminantMatrice(sousMat);
                    }
                    else
                    {
                        if (j%2 == 0) /*--->*/ determinant = determinant + m->elements[j] * (sousMat->elements[0]*sousMat->elements[3] - sousMat->elements[1]*sousMat->elements[2]);
                        else /*------------>*/ determinant = determinant - m->elements[j] * (sousMat->elements[0]*sousMat->elements[3] - sousMat->elements[1]*sousMat->elements[2]);
                    }
                    
                    free (sousMat);
                }    

            }

        }
        else /*--->*/ printf ("Erreur : les dimensions de la matrices sont différentes, impossible de calculer le déterminant.\n");
    }
    
    
    return (-1) * determinant;
}

Matrice* inverserMatrice (Matrice* m, char* nomDeLaMatriceInversee)
{
    Matrice* matInv = creerMatrice (nomDeLaMatriceInversee, m->dimX, m->dimY, NULLE);
    double determinant = calculerDeterminantMatrice (m);

    if (determinant != 0)
    {
        if (m->dimX == 2)
        {
            matInv->elements[0] = (1/determinant)*m->elements[3];
            matInv->elements[1] = (1/determinant)*m->elements[1]*(-1);
            matInv->elements[2] = (1/determinant)*m->elements[2]*(-1);
            matInv->elements[3] = (1/determinant)*m->elements[0];
        }
        
    }
    
    return matInv;

    /*Suite à des problèmes que j'ai rencontré, je me suis retrouvé sans pouvoir travailler sur aucun de mes ordinateurs.
    J'ai pu tout refaire fonctionner comme il se doit, mais par manque de temps, je n'ai pu aller seulement jusqu'au jalon 16.
    Je vous rend donc ce j'ai pu faire, et je continuerai malgré tout à faire le TP, ça reste très intéressant à travailler !*/
}

//-----------------------Nom de la Matrice-----------------------//

char* getNom (Matrice* m)
{
    if (m) /*--->*/ return m->nomDeLaMatrice;
}

void setNom (Matrice* m, char* nom)
{
    if (m) /*--->*/ m->nomDeLaMatrice = nom;
}

//-----------------------Dimension Matrice-----------------------//

unsigned int getDimX (Matrice* m)
{
    if (m) /*--->*/ return m->dimX;
}

unsigned int getDimY (Matrice* m)
{
    if (m) /*--->*/ return m->dimY;
}

void setDimX (Matrice* m, unsigned int newDimX)
{
    if (m)
    {
        if (newDimX != m->dimX)
        {
            Matrice* mat = creerMatrice(m->nomDeLaMatrice, newDimX, m->dimY, NULLE);

            if (mat) /*--->*/ *m = *mat;

            free (mat);
        }
        
    }
    
}

void setDimY (Matrice* m, unsigned int newDimY)
{
    if (m)
    {
        if (newDimY != m->dimY)
        {
            Matrice* mat = creerMatrice(m->nomDeLaMatrice, m->dimX, newDimY, NULLE);

            if (mat) /*--->*/ *m = *mat;

            free (mat);
        }
        
    }
}

//-----------------------Elements Matrice------------------------//

unsigned int getElement (Matrice* m, unsigned int x, unsigned int y, double* search)
{
    if (m)
    {
        if (x > m->dimX || y > m->dimY)
            return 0;
        if (m->elements)
        {
            if (m->elements[m->dimX*y+x ] == *search)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            
        }
        
    }
    
}

unsigned int setElement (Matrice* m, unsigned int x, unsigned int y, double ajout)
{
    if (m)
    {
        if (x > m->dimX || y > m->dimY)
            return 0;
        else
            if (m->elements)
            {
                m->elements[m->dimX*y+x] = ajout;
                return 1;
            }
    }

    return 0;
}
