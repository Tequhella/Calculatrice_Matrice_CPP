#ifndef _TYPE_H_INCLUDED_
#define _TYPE_H_INCLUDED_

typedef struct Matrice
{
    unsigned int dimX;
    unsigned int dimY;

    double* elements;

    char* nomDeLaMatrice;
}
Matrice;

#define NULLE    0
#define IDENTITE 1
#define HASARD   2

#endif