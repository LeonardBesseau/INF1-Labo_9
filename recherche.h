/* ---------------------------
Laboratoire : 09
Fichier : recherche.h
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Le but de ce laboratoire est d'établir les bases d'un correcteur orthographique.
Nous nous intéressons particulièrement à la lecture d'un fichier contenant la liste des mots du dictionnaire,
et à la recherche dans cette liste d'un mot donné ou d'un vector<string> de mots provenant d'un fichier.
Le progrmme affiche alors si le ou les mots ne sont pas présent dans le dictionnaire.

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

/**
 *
 * @param dictionary
 * @param word
 * @details based on https://fr.wikipedia.org/wiki/Recherche_dichotomique#%C3%89criture_it%C3%A9rative
 * @return
 */
size_t rechercheDichotomique(const std::vector<std::string> &dictionary, const std::string &word);

std::vector<std::string>::iterator rechercheDichotomique(std::vector<std::string>::iterator begin,
        std::vector<std::string>::iterator end , const std::string &word);

bool rechercheDichotomiqueRecursive(const std::vector<std::string> &dictionary, const std::string &word);

bool rechercheDichotomiqueRecursive(std::vector<std::string>::iterator begin,
        std::vector<std::string>::iterator end , const std::string &word);

#endif //LABO_9_RECHERCHE_H
