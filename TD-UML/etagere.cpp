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
    this->livres = new Livre[1000];  
    //Ajouter
    this->nom = nom;
    this->capacite = capacite;
    this->nbGenres = 0;
    this->genres = new Genre[capacite];
}

std::string Etagere::getNom()
{
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
    //
    else {
        std::cout << "Capacité maximale de genres atteinte sur l'étagère !" << std::endl;
    }
}

#endif





