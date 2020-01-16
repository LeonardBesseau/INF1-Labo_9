/* ---------------------------
Laboratoire : 09
Fichier : utils.h
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Fichier non demandé dans la consigne

Remarque(s) : Fichier non demandé dans la consigne

Compilateur : g++ 7.4.0

--------------------------- */

#ifndef LABO_9_UTILS_H
#define LABO_9_UTILS_H

#include <vector>
#include <string>
#include <algorithm>

/**
 * Swap two element between themselves
 * @param a the first string to be swapped
 * @param b the second string to be swapped
 */
void swap(std::string &a, std::string &b);

/**
 * Verify in which order a list is sorted
 * @param list a vector of string containing a list of word
 * @return 0 if the list is sorted alphabetically, 1 if the list is inverted, 2 if the list is shuffled
 */
int checkIfSorted(const std::vector<std::string> &list);

/**
 * transform a string into a lowercase string with only alphabetical and '
 * @param s a string to normalize
 * @return the normalized string
 */
std::string &normaliseString(std::string &s);

/**
 * Split a line into words. Words are strings composed of [a-zA-Z] characters and '
 * @param line a string containing words and symbols
 * @return a vector of vector string containg the word of each line
 */
std::vector<std::string> split(const std::string &line);
#endif //LABO_9_UTILS_H
