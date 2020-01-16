/* ---------------------------
Laboratoire : 09
Fichier : lecture.h
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Lecture d'un dictionnaire depuis un fichier et tri du fichier

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
 *
 * \param name of the file by reference (constant)
 * \attention if an error occurred with the file, returns an empty vector
 * \return a vector of string
 */
std::vector<std::string> readFileByLine(const std::string &filename);

/**
 * \brief read words of line
 *
 * This method read line and separate the words
 * Add words to a vector of string.
 *
 * \param line to separate
 * \return a vector of vector of string
 */
std::vector<std::vector<std::string>> readWordByLine(std::vector<std::string> &lines);

/**
 * Inverse the dictionary
 * @param dictionary a vector of string containing the entries of the dictionary
 */
void inverseList(std::vector<std::string> &dictionary);

#endif //LABO_9_LECTURE_H
