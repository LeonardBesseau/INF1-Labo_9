/* ---------------------------
Laboratoire : 09
Fichier : lecture.h
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Le but de ce laboratoire est d'établir les bases d'un correcteur orthographique.
Nous nous intéressons particulièrement à la lecture d'un fichier contenant la liste des mots du dictionnaire,
et à la recherche dans cette liste d'un mot donné ou d'un vector<string> de mots provenant d'un fichier.
Le progrmme affiche alors si le ou les mots ne sont pas présent dans le dictionnaire.

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */

#ifndef LABO_9_LECTURE_H
#define LABO_9_LECTURE_H

#include <iostream>
#include <fstream>
#include <vector>


/**
 * \brief read file by line
 *
 * This method read a file line by line.
 * Add them to a string vector.
 * Return the string vector.
 *
 * \param name of the file by reference (constant)
 */
std::vector<std::string> readFileByLine(const std::string &filename);


void inverseList(std::vector<std::string> &dictionary);

/**
 * Sort the dictionary using bubbleSort
 * @param dictionary a vector of string containing the entry of the dictionary
 * @details based on https://en.wikipedia.org/wiki/Bubble_sort#Optimizing_bubble_sort
 */
void bubbleSort(std::vector<std::string> &dictionary);

#endif //LABO_9_LECTURE_H
