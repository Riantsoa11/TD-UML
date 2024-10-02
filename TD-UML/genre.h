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

    // M�thode priv�e pour d�terminer le rang d'un livre bas� sur son titre
    int rangLivre(std::string titreLivre);

public:
    // Constructeur de la classe Genre
    Genre(std::string libelleGenre = "", Etagere* uneEtagere = NULL); // Initialise le genre avec un libell� et une �tag�re (par d�faut vide ou NULL)

    // M�thode pour afficher ou retourner la liste des livres
    std::string meslivres();  

    // M�thode pour placer un livre dans le genre
    void placeLivre(Livre unLivre);  // Ajoute un livre � ce genre
};

#endif  
