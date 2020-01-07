/* ---------------------------
Laboratoire : 09
Fichier : lecture.h
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But :

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */

#ifndef LABO_9_LECTURE_H
#define LABO_9_LECTURE_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
 * \brief read file by line
 *
 * This method read a file line by line.
 * Add them to a string vector.
 * Return the string vector.
 *
 * \param name of the file by reference (constant)
 */
vector<string> readFileByLine(const string &filename);

#endif //LABO_9_LECTURE_H
