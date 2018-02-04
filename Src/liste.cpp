#include "liste.hpp"

#include <iostream>
#include <cassert>

Liste::Liste() {
  adr_prem = nullptr;
  nb_elem = 0;
}

Liste::Liste(const Liste& autre) {
  Cellule* c_tmp = autre.adr_prem;
  while (c_tmp != nullptr) {
    ajouter_en_queue(c_tmp->valeur);
    c_tmp = c_tmp->adr_suiv;
  }
}

Liste& Liste::operator=(const Liste& autre) {
  // Premièrement, on vide la liste.
  while (taille() != 0) {
    supprimer_en_tete();
  }

  Cellule* c_tmp = autre.adr_prem;
  while (c_tmp != nullptr) {
    ajouter_en_queue(c_tmp->valeur);
    c_tmp = c_tmp->adr_suiv;
  }
  return *this ;
}

Liste::~Liste() {
  while (taille() != 0) {
    supprimer_en_tete();
  }

  adr_prem = nullptr;
}

void Liste::ajouter_en_tete(int valeur) {
  Cellule* c = new Cellule(valeur);
  c->adr_suiv = tete();
  adr_prem = c;
  nb_elem++;
}

void Liste::ajouter_en_queue(int valeur) {
  if (taille() == 0) {
    ajouter_en_tete(valeur);
  }
  else {
    Cellule* c = new Cellule(valeur);    
    Cellule* c_tmp = queue();
    c_tmp->adr_suiv = c;
  }
  nb_elem++;
}

void Liste::supprimer_en_tete() {
  Cellule* c_tmp = tete();
  adr_prem = adr_prem->adr_suiv;
  delete c_tmp;
  nb_elem--;
}

Cellule* Liste::tete() {
  return adr_prem;
}

const Cellule* Liste::tete() const {
  return adr_prem;
}

Cellule* Liste::queue() {
  if (taille() == 0) {
    return nullptr;
  }

  else {
    Cellule* c_tmp = adr_prem;
    while (c_tmp->adr_suiv != nullptr) {
      c_tmp = c_tmp->adr_suiv; 
    }
    return c_tmp;
  }
}

const Cellule* Liste::queue() const {
  if (taille() == 0) {
    return nullptr;
  }

  else {
    Cellule* c_tmp = adr_prem;
    while(c_tmp->adr_suiv != nullptr) {
      c_tmp = c_tmp->adr_suiv;
    }
    return c_tmp;
  }
}

int Liste::taille() const {
  return nb_elem;
}

Cellule* Liste::recherche(int valeur) {
  Cellule* c_tmp = adr_prem;
  while (c_tmp != nullptr) {
    if (c_tmp->valeur == valeur) return c_tmp;
    else c_tmp = c_tmp->adr_suiv;
  }
  return nullptr ;
}

const Cellule* Liste::recherche(int valeur) const {
  Cellule* c_tmp = adr_prem;
  while (c_tmp != nullptr) {
    if (c_tmp->valeur == valeur) return c_tmp;
    else c_tmp = c_tmp->adr_suiv;
  }
  return nullptr ;
}

void Liste::afficher() const {
  Cellule* c_tmp = adr_prem;
  std::cout << "[";
  while (c_tmp != nullptr) {
    std::cout << " " << c_tmp->valeur;
    c_tmp = c_tmp->adr_suiv;
  }
  std::cout << " ]" << std::endl;
}
