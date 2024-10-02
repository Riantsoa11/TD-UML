#ifndef Genre_H            
#define Genre_H            

#include <string>          
#include "livre.h"        
#include "etagere.h"      

class Etagere;            
class Livre;              

class Genre {             
private:
    std::string libelle;   
    Livre* Leslivres;      
    int capaciteMax;       
    int nbLivres;          
    Etagere* uneEtagere;  

    // Méthode privée pour déterminer le rang d'un livre basé sur son titre
    int rangLivre(std::string titreLivre);

public:
    // Constructeur de la classe Genre
    Genre(std::string libelleGenre = "", Etagere* uneEtagere = NULL); // Initialise le genre avec un libellé et une étagère (par défaut vide ou NULL)

    // Méthode pour afficher ou retourner la liste des livres
    std::string meslivres();  

    // Méthode pour placer un livre dans le genre
    void placeLivre(Livre unLivre);  // Ajoute un livre à ce genre
};

#endif  
