#ifndef BIBLIOTHEQUE_H   
#define BIBLIOTHEQUE_H   

#include <string>        
#include "livre.h"       
#include "genre.h"       

class Livre;             
class Etagere;           

// D�claration de la classe Bibliotheque
class Bibliotheque {     
private:
    Livre* livres;        
    std::string name;     
    Etagere* etageres;    
    int nbEtageres;       
    int capaciteEtageres; 

public:
    // Constructeur de la classe Bibliotheque
    Bibliotheque(std::string name = "", int capaciteEtageres = 10); // Initialise la biblioth�que avec un nom et une capacit� d'�tag�res

    // M�thode pour ajouter une �tag�re
    void setEtagere(Etagere& etagere);  // Passe l'�tag�re par r�f�rence pour �viter les copies inutiles
};

#endif
