/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : interface.h                           */
/* Numéro de version : 0.0.15                                */
/* Date              : 05/04/2024                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/

#pragma once

#include "matrice.h"
#include <gtkmm.h>
#include <gtkmm/application.h>

using namespace std;
using namespace Gtk;

class Interface
{
    public:
        /**
         * @brief Constructeur Interface, crée une interface pour manipuler des matrices.
         */
        Interface();

        /**
         * @brief Destructeur Interface, détruit l'interface.
         */
        ~Interface();

        //=======================================================================================//

        /**
         * @brief Méthode afficherMenu, affiche le menu de l'interface.
         */
        void afficherMenu();

        /**
         * @brief Méthode afficherMatrices, affiche toutes les matrices.
         */
        void afficherMatrices();

    private:

        vector<Matrice*> matrices;

        Glib::RefPtr<Gtk::Application> app;
        Window* fenetre;
        Box* boiteMatrices;
        Button* boutonCreerMatrice;
        Button* boutonSupprimerMatrice;
        Button* boutonAjouterColonne;
        Button* boutonAjouterLigne;
        Button* boutonSupprimerColonne;
        Button* boutonSupprimerLigne;
        Button* boutonModifierValeur;
        Button* boutonCalculer;
        Button* boutonAdditionner;  
        Button* boutonSoustraire;
        Button* boutonMultiplier;
        Button* boutonDiviser;
        Button* boutonTransposer;
        Button* boutonInverser; 
        Button* boutonDeterminer;
};