#ifndef Livre_H           
#define Livre_H           

// Inclusion des bibliothèques nécessaires
#include <string>         
#include "genre.h"       

// Déclaration anticipée des classes Genre et Livre
class Genre;     

class Livre             
{
private:
    std::string titre;   
    Genre* leGenre;     

public:
    // Constructeur de la classe Livre
    Livre(std::string titreLivre = "", Genre* unGenre = NULL); // Initialise le livre avec un titre et un genre (par défaut vide ou NULL)

    // Méthode pour obtenir le titre du livre
    std::string getTitre(); // Retourne le titre du livre
};

#endif  
