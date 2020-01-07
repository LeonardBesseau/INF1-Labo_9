/* ---------------------------
Laboratoire : 09
Fichier : recherche.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But :

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */

#include "recherche.h"

size_t rechercheLineaire(const std::vector<std::string> &dictionary, const std::string &word){
    for (size_t i = 0; i < dictionary.size(); ++i) {
        if(dictionary.at(i) == word){
            return i;
        }
    }
    return size_t(-1);
}
