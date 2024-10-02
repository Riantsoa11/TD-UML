#ifndef BIBLIOTHEQUE_H   
#define BIBLIOTHEQUE_H   

#include <string>        
#include "livre.h"       
#include "genre.h"       

class Livre;             
class Etagere;           

// Déclaration de la classe Bibliotheque
class Bibliotheque {     
private:
    Livre* livres;        
    std::string name;     
    Etagere* etageres;    
    int nbEtageres;       
    int capaciteEtageres; 

public:
    // Constructeur de la classe Bibliotheque
    Bibliotheque(std::string name = "", int capaciteEtageres = 10); // Initialise la bibliothèque avec un nom et une capacité d'étagères

    // Méthode pour ajouter une étagère
    void setEtagere(Etagere& etagere);  // Passe l'étagère par référence pour éviter les copies inutiles
};

#endif
