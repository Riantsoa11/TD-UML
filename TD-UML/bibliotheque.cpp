#ifndef BIBLIOTHEQUE_CPP
#define BIBLIOTHEQUE_CPP

#include "bibliotheque.h"
#include <iostream>

// Constructeur de la classe Bibliotheque
Bibliotheque::Bibliotheque(std::string name, int capaciteEtageres) {
    this->name = name;
    this->capaciteEtageres = capaciteEtageres;
    this->nbEtageres = 0;
    this->etageres = new Etagere[capaciteEtageres];  // Allocation dynamique d'un tableau d'�tag�res
    this->livres = new Livre[1000];
}

// M�thode pour ajouter une �tag�re
void Bibliotheque::setEtagere(Etagere& etagere)
{
    if (nbEtageres < capaciteEtageres) {
        etageres[nbEtageres] = etagere;  // Ajoute l'�tag�re dans le tableau
        nbEtageres++;
    }
    else {
        std::cout << "Capacit� maximale d'�tag�res atteinte !" << std::endl;
    }
}

// M�thode pour cr�er un nouveau livre et le lier � un genre
Livre* Bibliotheque::nouveauLivre(std::string titre, std::string genre) {
    // Parcours des �tag�res pour trouver le genre
    for (int i = 0; i < nbEtageres; i++) {
        Genre* genreAssocie = etageres[i].getGenre();  // Suppose que getGenre() existe dans Etagere
        // V�rifie si le genre associ� � l'�tag�re correspond au genre recherche
        if (genreAssocie != nullptr && genreAssocie->getLibelle() == genre) {
			Livre* livre = new Livre(titre, genreAssocie);  // Cr�e un nouveau livre avec le genre associ�
			return livre;  // Retourne le livre cr��
		}
    }
    // Si le genre n'est pas trouv�, afficher un message d'erreur
    std::cout << "Genre non trouv� pour le livre : " << titre << std::endl;
    return nullptr;
}

#endif
