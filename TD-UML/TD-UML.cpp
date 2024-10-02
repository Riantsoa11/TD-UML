#include <iostream>
#include "livre.h"
#include "genre.h"
#include "etagere.h"
#include "bibliotheque.h"

// Fonction pour trier les livres par ordre alphabétique en utilisant un tri par insertion
void trierLivres(Livre* livres[], int nbLivres) {
    // Tri par insertion
    for (int i = 1; i < nbLivres; ++i) {
        // Livre actuel
        Livre* livreActuel = livres[i];
        // Comparaison des titres des livres
        int j = i - 1;
        // Utilisation de strcmp pour comparer les titres
        while (j >= 0 && livres[j]->getTitre() > livreActuel->getTitre()) 
        {
            // Déplace les livres vers la droite
            livres[j + 1] = livres[j];
            j--;
        }
        // Insère le livre actuel à la bonne position
        livres[j + 1] = livreActuel;
    }
}

int main() {
    // Nom de la bibliothèque
    std::string name = "CDI";
    std::cout << "Ma Bibliotheque : " << name << std::endl;

    // Création de la bibliothèque
    Bibliotheque maBibliotheque(name);

    // Création des étagères
    Etagere* etagere1 = new Etagere("Etagere 1", 10); // Première étagère
    Etagere* etagere2 = new Etagere("Etagere 2", 10); // Deuxième étagère

    // Ajout des étagères à la bibliothèque
    maBibliotheque.setEtagere(*etagere1);
    maBibliotheque.setEtagere(*etagere2);

    // Création de genres
    Genre* genreRoman = new Genre("Roman", etagere1); // Genre Roman associé à l'étagère 1
    Genre* genreFiction = new Genre("Fiction", etagere2); // Genre Fiction associé à l'étagère 2

    // Ajout des genres aux étagères
    etagere1->setGenre(*genreRoman);
    etagere2->setGenre(*genreFiction);

    // Création de livres
    Livre* livre1 = new Livre("Les Miserables - Victor Hugo", genreRoman);
    Livre* livre2 = new Livre("Les Fleurs du mal - Baudelaire", genreRoman);
    Livre* livre3 = new Livre("2001 L'Odyssey - Kubrick", genreFiction);
    Livre* livre4 = new Livre("1984 Orwell", genreFiction);

    // Placement des livres dans les genres
    genreRoman->placeLivre(*livre1); // Place le livre dans le genre Roman
    genreRoman->placeLivre(*livre2); // Place le livre dans le genre Roman
    genreFiction->placeLivre(*livre3); // Place un autre livre dans le genre Fiction
    genreFiction->placeLivre(*livre4); // Place un autre livre dans le genre Fiction

    // Création de tableaux de pointeurs pour trier les livres
    Livre* livresRoman[] = { livre1, livre2 };
    Livre* livresFiction[] = { livre3, livre4 };

    // Tri des livres par ordre alphabétique
    trierLivres(livresRoman, 2);
    trierLivres(livresFiction, 2);

    // Affichage des livres triés pour le genre Roman
    std::cout << "Livres disponibles dans le genre Roman sur l'etagere " << etagere1->getNom() << " :\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << livresRoman[i]->getTitre() << std::endl;
    }

    // Affichage des livres triés pour le genre Fiction
    std::cout << "Livres disponibles dans le genre Fiction sur l'etagere " << etagere2->getNom() << " :\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << livresFiction[i]->getTitre() << std::endl;
    }

    return 0; // Indique que le programme s'est exécuté avec succès
}

