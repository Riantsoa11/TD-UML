#ifndef ETAGERE_H
#define ETAGERE_H

#include <string>
#include "livre.h"
#include "genre.h"

class Livre;// D�claration anticip�e de la classe Livre
class Genre;

class Etagere {

private:
    std::string nom;
    int nbLivres; 
    Livre* livres; 
    // ajouter
    Genre* genres;
    int nbGenres;
    int capacite;

public:
    // Constructeur pour initialiser l'�tag�re avec un nom et une capacit�
    Etagere(std::string nom = "", int capacite = 10);
    std::string getNom();
    std::string mesGenres();
    //methode pour ajouter un  genre � l'etagere
    void setGenre(Genre genre);

    //Methode pour obtenir le genre associ� � l'etagere
    Genre* getGenre();
};

#endif
#pragma once
