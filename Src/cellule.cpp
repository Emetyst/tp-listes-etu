#include "cellule.hpp"
#include <iostream>

Cellule::Cellule(int v, Cellule* adr) {
    valeur = v;
    adr_suiv = adr;
    std::cout << "Création de cellule" << std::endl ;
}
