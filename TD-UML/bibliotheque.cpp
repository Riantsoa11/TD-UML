#ifndef BIBLIOTHEQUE_CPP
#define BIBLIOTHEQUE_CPP

#include "bibliotheque.h"
#include <iostream>

// Constructeur de la classe Bibliotheque
Bibliotheque::Bibliotheque(std::string name, int capaciteEtageres) {
    this->name = name;
    this->capaciteEtageres = capaciteEtageres;
    this->nbEtageres = 0;
    this->etageres = new Etagere[capaciteEtageres];  // Allocation dynamique d'un tableau d'étagères
    this->livres = new Livre[1000];
}

// Méthode pour ajouter une étagère
void Bibliotheque::setEtagere(Etagere& etagere)
{
    if (nbEtageres < capaciteEtageres) {
        etageres[nbEtageres] = etagere;  // Ajoute l'étagère dans le tableau
        nbEtageres++;
    }
    else {
        std::cout << "Capacité maximale d'étagères atteinte !" << std::endl;
    }
}

// Méthode pour créer un nouveau livre et le lier à un genre
Livre* Bibliotheque::nouveauLivre(std::string titre, std::string genre) {
    // Parcours des étagères pour trouver le genre
    for (int i = 0; i < nbEtageres; i++) {
        Genre* genreAssocie = etageres[i].getGenre();  // Suppose que getGenre() existe dans Etagere
        // Vérifie si le genre associé à l'étagère correspond au genre recherche
        if (genreAssocie != nullptr && genreAssocie->getLibelle() == genre) {
			Livre* livre = new Livre(titre, genreAssocie);  // Crée un nouveau livre avec le genre associé
			return livre;  // Retourne le livre créé
		}
    }
    // Si le genre n'est pas trouvé, afficher un message d'erreur
    std::cout << "Genre non trouvé pour le livre : " << titre << std::endl;
    return nullptr;
}

#endif
