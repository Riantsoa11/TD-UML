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
}

// M�thode pour ajouter une �tag�re
void Bibliotheque::setEtagere(Etagere& etagere) 
{
    // V�rifie si la capacit� maximale d'�tag�res n'est pas atteinte
    if (nbEtageres < capaciteEtageres) {
        etageres[nbEtageres] = etagere;  // Ajoute l'�tag�re dans le tableau
        nbEtageres++;
    }
    // Affiche un message d'erreur si la capacit� maximale est atteinte
    else {
        std::cout << "Capacit� maximale d'�tag�res atteinte !" << std::endl;
    }
}

#endif
