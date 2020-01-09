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

/**
 * Search linearly if a word is contained inside a dictionary
 * @param dictionary a vector of string containing the entries of the dictionary
 * @param word a string containing the word to find
 * @return an unsigned integer representing the index of the word in the dictionary or size_t(-1) otherwise
 */
size_t rechercheLineaire(const std::vector<std::string> &dictionary, const std::string &word);


/**
 * Search linearly if a word is contained inside a dictionary
 * @param begin a const_iterator pointing to the beginning of the vector
 * @param end a const_iterator pointing to the end of the vector
 * @param word a string containing the word to find
 * @return a const_iterator at the index of the word in the dictionary or end otherwise
 */
std::vector<std::string>::const_iterator rechercheLineaire(std::vector<std::string>::const_iterator begin,
        std::vector<std::string>::const_iterator end , const std::string &word);

/**
 * Search using binary search if a word is contained inside a dictionary
 * @param dictionary a vector of string containing the entries of the dictionary
 * @param word a string containing the word to find
 * @details based on https://fr.wikipedia.org/wiki/Recherche_dichotomique#%C3%89criture_it%C3%A9rative
 * @return an unsigned integer representing the index of the word in the dictionary or size_t(-1) otherwise
 */
size_t rechercheDichotomique(const std::vector<std::string> &dictionary, const std::string &word);

/**
 * Search using binary search if a word is contained inside a dictionary
 * @param begin a const_iterator pointing to the beginning of the vector
 * @param end a const_iterator pointing to the end of the vector
 * @param word a string containing the word to find
 * @return a const_iterator at the index of the word in the dictionary or end otherwise
 */
std::vector<std::string>::const_iterator rechercheDichotomique(std::vector<std::string>::const_iterator begin,
        std::vector<std::string>::const_iterator end , const std::string &word);


/**
 * Search recursively using binary search if a word is contained inside a dictionary in an interval [a,b)
 * @param dictionary a vector of string containing the entries of the dictionary
 * @param word a string containing the word to find
 * @return true if the word is in the array, false otherwise
 */
bool rechercheDichotomiqueRecursive(const std::vector<std::string> &dictionary, const std::string &word);


/**
 * Search recursively using binary search if a word is contained inside a dictionary in an interval [a,b)
 * @param begin a const_iterator pointing to the beginning of the interval
 * @param end a const_iterator pointing to the end of the interval
 * @param word a string containing the word to find
 * @return true if the word is in the array, false otherwise
 */
bool rechercheDichotomiqueRecursive(std::vector<std::string>::const_iterator begin,
        std::vector<std::string>::const_iterator end , const std::string &word);

#endif //LABO_9_RECHERCHE_H
