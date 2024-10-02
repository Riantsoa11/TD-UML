#ifndef Livre_H           
#define Livre_H           

// Inclusion des biblioth�ques n�cessaires
#include <string>         
#include "genre.h"       

// D�claration anticip�e des classes Genre et Livre
class Genre;     

class Livre             
{
private:
    std::string titre;   
    Genre* leGenre;     

public:
    // Constructeur de la classe Livre
    Livre(std::string titreLivre = "", Genre* unGenre = NULL); // Initialise le livre avec un titre et un genre (par d�faut vide ou NULL)

    // M�thode pour obtenir le titre du livre
    std::string getTitre(); // Retourne le titre du livre
};

#endif  
