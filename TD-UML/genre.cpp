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
    this->Leslivres = new Livre[capaciteMax];    

}

// Méthode pour déterminer le rang d'un livre basé sur son titre
int Genre::rangLivre(std::string titreLivre) 
{
    int i = 0;          // Initialisation de l'index pour parcourir le tableau
    int rang = 0;      // Initialisation de la variable pour stocker le rang du livre

    // Boucle pour parcourir le tableau des livres
    while (i < sizeof(Leslivres)) {
        if (Leslivres[i].getTitre() < titreLivre) { // Compare le titre du livre courant avec 'titreLivre'
            rang = i;  // Met à jour le rang si le titre courant est inférieur
        }
        if (Leslivres[i].getTitre() == titreLivre) { // Si le titre courant correspond à 'titreLivre'
            rang = i;  // Met à jour le rang au même index
        }
        i++;  
    }
    return rang; // Retourne le rang déterminé
}

// Méthode pour placer un livre dans le genre
void Genre::placeLivre(Livre unLivre) 
{
    if (nbLivres < capaciteMax) {
        // Trouver la position correcte pour l'insertion
        int i = nbLivres - 1;
        while (i >= 0 && Leslivres[i].getTitre() > unLivre.getTitre()) {
            // Décalage des livres vers la droite pour faire de la place
            Leslivres[i + 1] = Leslivres[i];
            i--;
        }
        // Insérer le nouveau livre à la position correcte
        Leslivres[i + 1] = unLivre;
        nbLivres++; // Incrémenter le nombre de livres
    }
    // Affiche un message d'erreur si la capacité maximale est atteinte
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
