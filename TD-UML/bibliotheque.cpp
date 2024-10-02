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
}

// Méthode pour ajouter une étagère
void Bibliotheque::setEtagere(Etagere& etagere) 
{
    // Vérifie si la capacité maximale d'étagères n'est pas atteinte
    if (nbEtageres < capaciteEtageres) {
        etageres[nbEtageres] = etagere;  // Ajoute l'étagère dans le tableau
        nbEtageres++;
    }
    // Affiche un message d'erreur si la capacité maximale est atteinte
    else {
        std::cout << "Capacité maximale d'étagères atteinte !" << std::endl;
    }
}

#endif
