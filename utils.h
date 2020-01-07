/* ---------------------------
Laboratoire : 09
Fichier : utils.h
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Le but de ce laboratoire est d'établir les bases d'un correcteur orthographique.
Nous nous intéressons particulièrement à la lecture d'un fichier contenant la liste des mots du dictionnaire,
et à la recherche dans cette liste d'un mot donné ou d'un vector<string> de mots provenant d'un fichier.
Le progrmme affiche alors si le ou les mots ne sont pas présent dans le dictionnaire.

Remarque(s) : Fichier non demandé dans la consigne

Compilateur : g++ 7.4.0

--------------------------- */

#ifndef LABO_9_UTILS_H
#define LABO_9_UTILS_H

#include <string>

/**
 * Swap two element between themselves
 * @param a the first string to be swapped
 * @param b the second string to be swapped
 */
void swap(std::string &a, std::string &b);


#endif //LABO_9_UTILS_H
