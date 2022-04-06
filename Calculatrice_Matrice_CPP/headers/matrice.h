/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : matrice.h                             */
/* Numéro de version : 0.0.1                                 */
/* Date              : 06/04/2022                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/

#pragma once

#include <iostream>

enum
{
    NULLE,
    IDENTITE,
    ALEATOIRE
};

using namespace std;

class Matrice
{
	public:
		
		/*
		* Crée une matrice de dimensions aléatoire de 0 à 255, de valeurs aléatoires, et de nom aléatoire.
		*/
		Matrice();

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
		Matrice(char* nomDeLaMatrice, uint8_t dimX, uint8_t dimY, uint8_t type);
		
		~Matrice();

        //=======================================================================================//

		/**
		 * Méthode afficherMatrice, imprime la matrice
		 *
		 * @param format le nombre de caractères à afficher pour chaque élément.
		 */
		void afficherMatrice(uint8_t format);

        //=======================================================================================//

        /**
         * Méthode getDimX, retourne la dimension en X de la matrice
         * 
         */
        uint8_t getDimX();

        /**
         * Méthode getDimY, retourne la dimension en Y de la matrice
         * 
         */
        uint8_t getDimY();

        /**
         * Méthode getNomDeLaMatrice, retourne le nom de la matrice
         * 
         */
        char* getNomDeLaMatrice();

		
	private:
		
		uint8_t dimX;
		uint8_t dimY;
		double* elements;
		char*	nomDeLaMatrice;
};