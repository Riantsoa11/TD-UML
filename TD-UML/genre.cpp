#ifndef GENRE_CPP          
#define GENRE_CPP          

#include "genre.h"         
#include "livre.h"         
#include <iostream>        

// Constructeur de la classe Genre
Genre::Genre(std::string libelleGenre, Etagere* uneEtagere) {
    this->libelle = libelleGenre;        // Initialise le libellé du genre avec le paramètre 'libelleGenre'
    this->uneEtagere = uneEtagere;        // Initialise le pointeur vers l'étagère associée au genre
    this->capaciteMax = 1000;
    this->nbLivres = 0;
    this->Leslivres = new Livre[capaciteMax];  // Alloue un tableau dynamique pour les livres
}

// Méthode pour déterminer le rang d'un livre et faire le tri
int Genre::rangLivre(std::string titreLivre)
{
    int i = 0;

    // Parcourt la liste des livres pour trouver la position correcte d'insertion
    while (i < nbLivres && Leslivres[i].getTitre() < titreLivre) {
        i++;
    }

    return i; // Retourne la position à laquelle le livre devrait être inséré
}

// Méthode pour placer un livre dans le genre
void Genre::placeLivre(Livre unLivre)
{
    if (nbLivres < capaciteMax) {
        // Trouver la position correcte pour insérer le livre (rang)
        int rang = rangLivre(unLivre.getTitre());

        // Décaler les livres pour faire de la place au nouvel élément
        for (int i = nbLivres; i > rang; i--) {
            Leslivres[i] = Leslivres[i - 1];
        }

        // Insérer le nouveau livre dans le tableau trié
        Leslivres[rang] = unLivre;
        nbLivres++; // Incrémente le nombre de livres
    }
    else {
        std::cout << "Capacité maximale de livres atteinte dans le genre !" << std::endl;
    }
}

// Méthode pour afficher ou retourner la liste des livres
std::string Genre::meslivres()
{
    std::string listeLivres;
    for (int i = 0; i < nbLivres; ++i) {
        listeLivres += Leslivres[i].getTitre() + "\n"; // Ajoute chaque titre de livre à la chaîne de caractères
    }
    return listeLivres; // Retourne la chaîne de caractères contenant les titres des livres
}

#endif
