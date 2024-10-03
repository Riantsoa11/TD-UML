#ifndef Etagere_CPP // Vérifie si ETAGERE_CPP n'est pas déjà défini
#define Etagere_CPP // Définit ETAGERE_CPP pour éviter les inclusions multiples

// Inclusion des fichiers d'entête
#include "etagere.h"  
#include <iostream>   
#include "livre.h"    
#include "genre.h"    

// Constructeur
Etagere::Etagere(std::string nom, int capacite)
{
    this->nom = nom;
    this->capacite = capacite;
    this->nbGenres = 0;
    this->nbLivres = 0;
    this->genres = new Genre[capacite];
    this->livres = new Livre[1000];
}

std::string Etagere::getNom()
{
    // Retourne le nom de l'étagère
	return nom;
}

//methode pour ajouter un  genre à l'etagere
void Etagere::setGenre(Genre genre)
{
    // Vérifie si la capacité maximale de genres n'est pas atteinte
    if (nbGenres < capacite) {
        genres[nbGenres] = genre;  // Ajoute le genre à l'étagère
        nbGenres++;
    }
    // Sinon, affiche un message d'erreur
    else {
        std::cout << "Capacité maximale de genres atteinte sur l'étagère !" << std::endl;
    }
}

// Méthode pour obtenir le genre associé à l'étagère
Genre* Etagere::getGenre() {
    if (nbGenres > 0) {
        return &genres[0];  // Retourne le premier genre si plusieurs genres sont possibles
    }
    return nullptr;  // Retourne nullptr si aucun genre n'est présent
}

// Méthode pour retourner les genres de l'étagère
std::string Etagere::mesGenres() {
    std::string resultat = "Genres sur l'étagère " + nom + " : \n";

    // Vérifie si aucun genre n'est disponible
    if (nbGenres == 0) {
        resultat += "Aucun genre disponible\n";
    }
    // Sinon, affiche les genres disponibles
    else {
        // Parcourt la liste des genres
        for (int i = 0; i < nbGenres; ++i) {
            resultat += genres[i].getLibelle() + "\n";  // Ajoute le libellé de chaque genre
        }
    }
    // Retourne la liste des genres
    return resultat;
}



#endif





