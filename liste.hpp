#ifndef LISTE_HPP
#define LISTE_HPP

#include <iostream>
#include <vector>

typedef int TELEM;

// liste d'éléments de type TELEM
class liste {
public:
  // constructeur d'une liste vide
  liste();

  // destructeur
  ~liste();

  // teste si une liste est vide
  bool est_vide() const;

  // retourne le nombre d'éléments d'une liste
  int taille() const;

  // accès au i-ème élément
  // PRECOND : taille() > 0 et 0 <= i <= taille()-1
  const TELEM& operator[](int i) const;

  // insertion d'un élément e à la position i
  // PRECOND : 0 <= i <= taille()
  void inserer(const TELEM& e, int i);

  // suppression de l'élément à la position i
  // PRECOND : taille() > 0 et 0 <= i <= taille()-1
  void supprimer(int i);

private:

  std::vector<int> v;

};

// opérateur d'écriture sur un flot de sortie
std::ostream& operator<<(std::ostream& os, const liste& l);

#endif
