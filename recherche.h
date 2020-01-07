/* ---------------------------
Laboratoire : 09
Fichier : recherche.h
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But :

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */

#ifndef LABO_9_RECHERCHE_H
#define LABO_9_RECHERCHE_H

#include <vector>
#include <string>

size_t rechercheLineaire(const std::vector<std::string> &dictionary, const std::string &word);

std::vector<std::string>::iterator rechercheLineaire(std::vector<std::string>::iterator begin,
        std::vector<std::string>::iterator end , const std::string &word);



#endif //LABO_9_RECHERCHE_H
