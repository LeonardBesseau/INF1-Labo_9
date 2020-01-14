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
 * Merge two vector into one with the elements in order
 * @param v1 the first vector of string to merge
 * @param v2 the second vector of string to merge
 * @return a vector of string containing all the elements of the two in croissant order
 */
std::vector<std::string> mergeVectors(const std::vector<std::string> &v1, const std::vector<std::string> &v2);

/**
 * Verify in which order a list is sorted
 * @param list a vector of string containing a list of word
 * @return 0 if the list is sorted alphabetically, 1 if the list is inverted, 2 if the list is shuffled
 */
int checkIfSorted(const std::vector<std::string> &list);

/**
 * transform a string into a lowercase string with only alphabetical, ' and space remaining
 * @param s a string to normalize
 * @return the normalized string
 */
std::string normaliseString(std::string &s);

/**
 * transform a vector of string into a lowercase string with only alphabetical, '
 * and space remaining
 * @param s a vector of string to normalize
 * @return the normalize
 */
std::vector<std::string> &normaliseVector(std::vector<std::string> &s);


#endif //LABO_9_UTILS_H
