#include "liste.hpp"

#include <iostream>
#include <cassert>

Liste::Liste() {
  adr_prem = nullptr;
  nb_elem = 0;
}

Liste::Liste(const Liste& autre) {
  nb_elem = 0;

  if (autre.taille() != 0) {
    adr_prem = new Cellule(autre.tete()->valeur);
    nb_elem++;

    Cellule* c_tmp = autre.tete()->adr_suiv;
    Cellule* adr_der = adr_prem;

    while (c_tmp != nullptr) {
      adr_der->adr_suiv = new Cellule(c_tmp->valeur);
      c_tmp = c_tmp->adr_suiv;
      adr_der = adr_der->adr_suiv;
      nb_elem++;
    }
  }
  else adr_prem = nullptr;
}

Liste& Liste::operator=(const Liste& autre) {
  // Premièrement, on vide la liste.
  while (taille() != 0) {
    supprimer_en_tete();
  }
  nb_elem = 0;

  if (autre.taille() != 0) {
    adr_prem = new Cellule(autre.tete()->valeur);
    nb_elem++;

    Cellule* c_tmp = autre.tete()->adr_suiv;
    Cellule* adr_der = adr_prem;

    while (c_tmp != nullptr) {
      adr_der->adr_suiv = new Cellule(c_tmp->valeur);
      c_tmp = c_tmp->adr_suiv;
      adr_der = adr_der->adr_suiv;
      nb_elem++;
    }
  }
  else adr_prem = nullptr;
  return *this ;
}

Liste::~Liste() {
  while (taille() != 0) {
    supprimer_en_tete();
  }
}

void Liste::ajouter_en_tete(int valeur) {
  Cellule* c = new Cellule(valeur, tete());
  adr_prem = c;
  nb_elem++;
}

void Liste::ajouter_en_queue(int valeur) {
  Cellule* c = new Cellule(valeur);
  if (taille() == 0) {
    adr_prem = c;
  }
  else { 
    Cellule* adr_der = queue();
    adr_der->adr_suiv = c;
  }
  nb_elem++;
}

void Liste::supprimer_en_tete() {
  if (taille() != 0) {
    Cellule* c_tmp = tete();
    adr_prem = adr_prem->adr_suiv;
    delete c_tmp;
    nb_elem--;
  }
}

Cellule* Liste::tete() {
  return adr_prem;
}

const Cellule* Liste::tete() const {
  return (const Cellule*) adr_prem;
}

Cellule* Liste::queue() {
  if (taille() == 0) return nullptr;
  else {
    Cellule* c_tmp = adr_prem;
    while (c_tmp->adr_suiv != nullptr) {
      c_tmp = c_tmp->adr_suiv; 
    }
    return c_tmp;
  }
}

const Cellule* Liste::queue() const {
  if (taille() == 0) return nullptr;
  else {
    Cellule* c_tmp = adr_prem;
    while (c_tmp->adr_suiv != nullptr) {
      c_tmp = c_tmp->adr_suiv; 
    }
    return (const Cellule*) c_tmp;
  }
}

int Liste::taille() const {
  return nb_elem;
}

Cellule* Liste::recherche(int valeur) {
  if (taille() == 0) return nullptr;
  else {
    Cellule* c_tmp = tete();
    while (c_tmp != nullptr) {
      if (c_tmp->valeur == valeur) break;
      c_tmp = c_tmp->adr_suiv;
    }
    return c_tmp;
  }
}

const Cellule* Liste::recherche(int valeur) const {
  if (taille() == 0) return nullptr;
  else {
    Cellule* c_tmp = adr_prem;
    while (c_tmp != nullptr) {
      if (c_tmp->valeur == valeur) break;
      c_tmp = c_tmp->adr_suiv;
    }
    return (const Cellule*) c_tmp;
  }
}

void Liste::afficher() const {
  std::cout << "[";

  if (taille() != 0) {
    Cellule* c_tmp = adr_prem;
    while (c_tmp != nullptr) {
      std::cout << " " << c_tmp->valeur;
      c_tmp = c_tmp->adr_suiv;
    }
  }
  std::cout << " ]" << std::endl;
}
