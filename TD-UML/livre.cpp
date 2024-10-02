#ifndef Livre_CPP          
#define Livre_CPP          

#include "livre.h"         
#include "genre.h"         
#include <string>         

// Constructeur de la classe Livre
Livre::Livre(std::string titre, Genre* unGenre) {
    this->titre = titre;          // Initialise le titre du livre avec le paramètre 'titre' passé au constructeur
    this->leGenre = unGenre;      // Initialise le genre du livre avec le pointeur 'unGenre' passé au constructeur
}

// Méthode pour obtenir le titre du livre
std::string Livre::getTitre() {
    return this->titre; // Retourne le titre du livre
}

#endif  
