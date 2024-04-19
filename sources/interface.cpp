/*************************************************************/
/* Calculatrice_Matrice_CPP						             */
/*-----------------------------------------------------------*/
/* Module            : interface.cpp                         */
/* Numéro de version : 0.0.15                                */
/* Date              : 05/04/2024                            */
/* Auteurs           : Lilian CHARDON, Andréas CASTELLO      */
/*************************************************************/

#include "../headers/interface.h"

Interface::Interface()
{
    app = new Application("org.gtkmm.example");
    fenetre = new Window();
    boiteMatrices = new Box(ORIENTATION_VERTICAL);
    boutonCreerMatrice = new Button("Créer une matrice");
    boutonSupprimerMatrice = new Button("Supprimer une matrice");
    boutonAjouterColonne = new Button("Ajouter une colonne");
    boutonAjouterLigne = new Button("Ajouter une ligne");
    boutonSupprimerColonne = new Button("Supprimer une colonne");
    boutonSupprimerLigne = new Button("Supprimer une ligne");
    boutonModifierValeur = new Button("Modifier une valeur");
    boutonCalculer = new Button("Calculer");
    boutonAdditionner = new Button("Additionner");
    boutonSoustraire = new Button("Soustraire");
    boutonMultiplier = new Button("Multiplier");
    boutonDiviser = new Button("Diviser");
    boutonTransposer = new Button("Transposer");
    boutonInverser = new Button("Inverser");
    boutonDeterminer = new Button("Déterminer");

    fenetre->add(*boiteMatrices);
    boiteMatrices->pack_start(*boutonCreerMatrice);
    boiteMatrices->pack_start(*boutonSupprimerMatrice);
    boiteMatrices->pack_start(*boutonAjouterColonne);
    boiteMatrices->pack_start(*boutonAjouterLigne);
    boiteMatrices->pack_start(*boutonSupprimerColonne);
    boiteMatrices->pack_start(*boutonSupprimerLigne);
    boiteMatrices->pack_start(*boutonModifierValeur);
    boiteMatrices->pack_start(*boutonCalculer);
    boiteMatrices->pack_start(*boutonAdditionner);
    boiteMatrices->pack_start(*boutonSoustraire);
    boiteMatrices->pack_start(*boutonMultiplier);
    boiteMatrices->pack_start(*boutonDiviser);
    boiteMatrices->pack_start(*boutonTransposer);
    boiteMatrices->pack_start(*boutonInverser);
    boiteMatrices->pack_start(*boutonDeterminer);

    app->run(*fenetre);
}

Interface::~Interface()
{
    delete app;
    delete fenetre;
    delete boiteMatrices;
    delete boutonCreerMatrice;
    delete boutonSupprimerMatrice;
    delete boutonAjouterColonne;
    delete boutonAjouterLigne;
    delete boutonSupprimerColonne;
    delete boutonSupprimerLigne;
    delete boutonModifierValeur;
    delete boutonCalculer;
    delete boutonAdditionner;
    delete boutonSoustraire;
    delete boutonMultiplier;
    delete boutonDiviser;
    delete boutonTransposer;
    delete boutonInverser;
    delete boutonDeterminer;
}

void
Interface::afficherMenu()
{
    
}

void
Interface::afficherMatrices()
{
    
}