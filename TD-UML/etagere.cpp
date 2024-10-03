#ifndef Etagere_CPP // V�rifie si ETAGERE_CPP n'est pas d�j� d�fini
#define Etagere_CPP // D�finit ETAGERE_CPP pour �viter les inclusions multiples

// Inclusion des fichiers d'ent�te
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
    // Retourne le nom de l'�tag�re
	return nom;
}

//methode pour ajouter un  genre � l'etagere
void Etagere::setGenre(Genre genre)
{
    // V�rifie si la capacit� maximale de genres n'est pas atteinte
    if (nbGenres < capacite) {
        genres[nbGenres] = genre;  // Ajoute le genre � l'�tag�re
        nbGenres++;
    }
    // Sinon, affiche un message d'erreur
    else {
        std::cout << "Capacit� maximale de genres atteinte sur l'�tag�re !" << std::endl;
    }
}

// M�thode pour obtenir le genre associ� � l'�tag�re
Genre* Etagere::getGenre() {
    if (nbGenres > 0) {
        return &genres[0];  // Retourne le premier genre si plusieurs genres sont possibles
    }
    return nullptr;  // Retourne nullptr si aucun genre n'est pr�sent
}

// M�thode pour retourner les genres de l'�tag�re
std::string Etagere::mesGenres() {
    std::string resultat = "Genres sur l'�tag�re " + nom + " : \n";

    // V�rifie si aucun genre n'est disponible
    if (nbGenres == 0) {
        resultat += "Aucun genre disponible\n";
    }
    // Sinon, affiche les genres disponibles
    else {
        // Parcourt la liste des genres
        for (int i = 0; i < nbGenres; ++i) {
            resultat += genres[i].getLibelle() + "\n";  // Ajoute le libell� de chaque genre
        }
    }
    // Retourne la liste des genres
    return resultat;
}



#endif





