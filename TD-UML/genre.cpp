#ifndef GENRE_CPP          
#define GENRE_CPP          

#include "genre.h"         
#include "livre.h"         
#include <iostream>        

// Constructeur de la classe Genre
Genre::Genre(std::string libelleGenre, Etagere* uneEtagere) {
    this->libelle = libelleGenre;        // Initialise le libell� du genre avec le param�tre 'libelleGenre'
    this->uneEtagere = uneEtagere;        // Initialise le pointeur vers l'�tag�re associ�e au genre
    
    this->capaciteMax = 1000;
    this->nbLivres = 0;
    this->Leslivres = new Livre[capaciteMax];    

}

// M�thode pour d�terminer le rang d'un livre bas� sur son titre
int Genre::rangLivre(std::string titreLivre) 
{
    int i = 0;          // Initialisation de l'index pour parcourir le tableau
    int rang = 0;      // Initialisation de la variable pour stocker le rang du livre

    // Boucle pour parcourir le tableau des livres
    while (i < sizeof(Leslivres)) {
        if (Leslivres[i].getTitre() < titreLivre) { // Compare le titre du livre courant avec 'titreLivre'
            rang = i;  // Met � jour le rang si le titre courant est inf�rieur
        }
        if (Leslivres[i].getTitre() == titreLivre) { // Si le titre courant correspond � 'titreLivre'
            rang = i;  // Met � jour le rang au m�me index
        }
        i++;  
    }
    return rang; // Retourne le rang d�termin�
}

// M�thode pour placer un livre dans le genre
void Genre::placeLivre(Livre unLivre) 
{
    if (nbLivres < capaciteMax) {
        // Trouver la position correcte pour l'insertion
        int i = nbLivres - 1;
        while (i >= 0 && Leslivres[i].getTitre() > unLivre.getTitre()) {
            // D�calage des livres vers la droite pour faire de la place
            Leslivres[i + 1] = Leslivres[i];
            i--;
        }
        // Ins�rer le nouveau livre � la position correcte
        Leslivres[i + 1] = unLivre;
        nbLivres++; // Incr�menter le nombre de livres
    }
    // Affiche un message d'erreur si la capacit� maximale est atteinte
    else {
        std::cout << "Capacit� maximale de livres atteinte dans le genre !" << std::endl;
    }
}

// M�thode pour afficher ou retourner la liste des livres
std::string Genre::meslivres()
{
    std::string listeLivres;
    for (int i = 0; i < nbLivres; ++i) {
        listeLivres += Leslivres[i].getTitre() + "\n"; // Ajoute chaque titre de livre � la cha�ne de caract�res
    }
    return listeLivres; // Retourne la cha�ne de caract�res contenant les titres des livres
}

#endif 
