#ifndef GENRE_CPP          
#define GENRE_CPP          

#include "genre.h"         
#include "livre.h"         
#include <iostream>        

// Constructeur de la classe Genre
Genre::Genre(std::string libelleGenre, Etagere* uneEtagere) {
    this->libelle = libelleGenre;        // Initialise le libell� du genre avec le param�tre 'libelleGenre'
    this->uneEtagere = uneEtagere;        // Initialise le pointeur vers l'�tag�re associ�e au genre
    this->capaciteMax = 1000;
    this->nbLivres = 0;
    this->Leslivres = new Livre[capaciteMax];  // Alloue un tableau dynamique pour les livres
}

// M�thode pour d�terminer le rang d'un livre et faire le tri
int Genre::rangLivre(std::string titreLivre)
{
    int i = 0;

    // Parcourt la liste des livres pour trouver la position correcte d'insertion
    while (i < nbLivres && Leslivres[i].getTitre() < titreLivre) {
        i++;
    }

    return i; // Retourne la position � laquelle le livre devrait �tre ins�r�
}

// M�thode pour placer un livre dans le genre
void Genre::placeLivre(Livre unLivre)
{
    if (nbLivres < capaciteMax) {
        // Trouver la position correcte pour ins�rer le livre (rang)
        int rang = rangLivre(unLivre.getTitre());

        // D�caler les livres pour faire de la place au nouvel �l�ment
        for (int i = nbLivres; i > rang; i--) {
            Leslivres[i] = Leslivres[i - 1];
        }

        // Ins�rer le nouveau livre dans le tableau tri�
        Leslivres[rang] = unLivre;
        nbLivres++; // Incr�mente le nombre de livres
    }
    else {
        std::cout << "Capacit� maximale de livres atteinte dans le genre !" << std::endl;
    }
}

// M�thode pour afficher ou retourner la liste des livres
std::string Genre::meslivres()
{
    std::string listeLivres;
    for (int i = 0; i < nbLivres; ++i) {
        listeLivres += Leslivres[i].getTitre() + "\n"; // Ajoute chaque titre de livre � la cha�ne de caract�res
    }
    return listeLivres; // Retourne la cha�ne de caract�res contenant les titres des livres
}

#endif
