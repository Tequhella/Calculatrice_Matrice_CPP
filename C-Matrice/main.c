#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "type.h"
#include "fonction.h"

int main()
{
    srand (time(NULL));

    Matrice matrice = *creerMatrice ("a", 2, 2, HASARD);

    afficherMatrice (&matrice, 3, 0);

    Matrice matriceInversee = *inverserMatrice (&matrice, "Inverse");

    afficherMatrice (&matriceInversee, 3, 3);
    
    return 0;
}

