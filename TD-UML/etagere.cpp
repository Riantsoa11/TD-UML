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
//methode pour ajouter un  genre � l'etagere
void Etagere::setGenre(Genre genre)
{
    // V�rifie si la capacit� maximale de genres n'est pas atteinte
    if (nbGenres < capacite) {
        genres[nbGenres] = genre;  // Ajoute le genre � l'�tag�re
        nbGenres++;
    }
    //
    else {
        std::cout << "Capacit� maximale de genres atteinte sur l'�tag�re !" << std::endl;
    }
}

#endif





