/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : matrice.h                             */
/* Numéro de version : 0.0.8                                 */
/* Date              : 07/04/2022                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/

#pragma once

#include <iostream>
#include <random>
/* Enumération des différents type de matrice. */
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
		 * Crée une matrice avec les dimensions données et la remplit selon le type.
		 *
		 * @param nomDeLaMatrice le nom de la matrice.
		 * @param dimX le nombre de lignes dans la matrice.
		 * @param dimY le nombre de lignes dans la matrice.
		 * @param type 1 pour la matrice d'identité, 2 pour la matrice aléatoire.
		 *
		 * @return Un pointeur vers une structure Matrice nouvellement allouée.
		 */
		Matrice(char* nomDeLaMatrice, uint8_t dimX, uint8_t dimY, uint8_t type);
		
		~Matrice();

        //=======================================================================================//

		/**
		 * Méthode afficherMatrice, imprime la matrice.
		 *
		 * @param format le nombre de caractères à afficher pour chaque élément.
		 */
		void afficherMatrice(uint8_t format);

		/**
		 * Méthode transposerMatrice, transpose la matrice.
		 * 
		 * @return la matrice transposée.
		 */
		Matrice* transposerMatrice();

		/**
		 * Méthode additionnerMatrice, additionne deux matrice.
		 * 
		 * @param matriceAdditionneur la matrice qui s'ajoutera à la matrice actuelle.
		 * @param nomDeLaMatriceSomme le nom de la matrice issue de l'addition.
		 * 
		 * @return la matrice issue de l'addition.
		 */
		Matrice* additionnerMatrice(Matrice* matriceAdditionneur, char* nomDeLaMatriceSomme);

		/**
		 * Méthode soustraireMatrice, soustrait deux matrice.
		 * 
		 * @param matriceSoustrait la matrice qui sera soustraite à la matrice actuelle.
		 * @param nomDeLaMatriceSoustraite le nom de la matrice issue de la soustraction.
		 * 
		 * @return la matrice issue de la soustraction.
		 */
		Matrice* soustraireMatrice(Matrice* matriceSoustrait, char* nomDeLaMatriceSoustraite);
		
		/**
		 * @brief 
		 * Il multiplie la matrice par un nombre réel.
		 * 
		 * @param nb 
		 * @param nomDeLaMatriceProduitReel 
		 * @return Matrice* 
		 */
		Matrice* multiplierMatriceParUnReel(double nb, char* nomDeLaMatriceProduitReel);
        //=======================================================================================//

        /**
         * Méthode getDimX, retourne la dimension en X de la matrice.
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

		/**
		 * Méthode getElement, retourne l'élément de la matrice à la position donnée.
		 *
		 * @param x la position en X de l'élément à retourner.
		 * @param y la position en Y de l'élément à retourner.
		 *
		 * @return l'élément de la matrice à la position donnée.
		 */
		double getElement(uint8_t x, uint8_t y);

		/**
		 * Méthode setElement, modifie l'élément de la matrice à la position donnée.
		 *
		 * @param x la position en X de l'élément à modifier.
		 * @param y la position en Y de l'élément à modifier.
		 * @param valeur la nouvelle valeur de l'élément à modifier.
		 *
		 * @return 2 si les coordonnées sont invalides, 1 si la modification a pu se faire, 0 sinon.
		 */
		uint8_t setElement(uint8_t x, uint8_t y, double valeur);

		/**
		 * Méthode setNomDeLaMatrice, modifie le nom de la matrice.
		 *
		 * @param nomDeLaMatrice le nouveau nom de la matrice.
		 *
		 * @return 1 si la modification a pu se faire, 0 sinon.
		 */
		uint8_t setNomDeLaMatrice(char* nomDeLaMatrice);

		/**
		 * Méthode setDimX, modifie la dimension en X de la matrice en créant une nouvelle matrice.
		 *
		 * @param dimX la nouvelle dimension en X de la matrice.
		 *
		 * @return 1 si la modification a pu se faire, 0 sinon.
		 */
		uint8_t setDimX(uint8_t dimX);

		/**
		 * Méthode setDimY, modifie la dimension en Y de la matrice en créant une nouvelle matrice.
		 *
		 * @param dimY la nouvelle dimension en Y de la matrice.
		 *
		 * @return 1 si la modification a pu se faire, 0 sinon.
		 */
		uint8_t setDimY(uint8_t dimY);



		
	private:
		
		/* Deux variables de type `uint8_t` (entier 8 bits non signé) et elles sont utilisées pour stocker les
		valeurs des dimension X et Y. */
		uint8_t dimX;
		uint8_t dimY;

		/* Il s'agit du tableau d'élément de la matrice. */
		double* elements;

		/* Un tableau de caractères pour stocker le nom de la matrice. */
		char*	nomDeLaMatrice;
};