#ifndef LIFAP6_LISTE_CELLULE_HPP
#define LIFAP6_LISTE_CELLULE_HPP

class Cellule {

  public:
    int valeur;
    Cellule* adr_suiv;

    Cellule(int v = 0, Cellule* adr = nullptr);
} ;

#endif
