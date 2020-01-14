/* ---------------------------
Laboratoire : 09
Fichier : main.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Le but de ce laboratoire est d'établir les bases d'un correcteur orthographique.
Nous nous intéressons particulièrement à la lecture d'un fichier contenant la liste des mots du dictionnaire,
et à la recherche dans cette liste d'un mot donné ou d'un vector<string> de mots provenant d'un fichier.
Le progrmme affiche alors si le ou les mots ne sont pas présent dans le dictionnaire.

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */
#include <iostream>
#include "recherche.h"
#include "lecture.h"
#include "utils.h"

using namespace std;

/**
 * Order a list alphabetically (by inverting or ordering it if needed)
 * @param list a vector of string containing a list of word
 */
void formatListAlphabetically(vector<string> &list);

// Current directory
const string PWD = "/home/leonard/CLionProjects/Labo_9/";


void formatListAlphabetically(std::vector<std::string> &list) {
    switch (checkIfSorted(list)) {
        case 1:
            inverseList(list);
            break;
        case 2:
            mergeSort(list);
            break;
        default:
            break;
    }
}

/**
 * Find if a word is present in a file
 * @param pathDictionary a string containing the path to the file
 * @param word a string containing the word to find
 * @return true if the word is present, false otherwise
 */
bool findMissingWord(const string &pathDictionary, const string &word) {
    vector<string> dictionary = readFileByLine(pathDictionary);
    formatListAlphabetically(dictionary);
    normaliseVector(dictionary);
    cout << "dictionnary size " << dictionary.size() << endl;
    return rechercheDichotomique(dictionary, word) != size_t(-1);
}

int main() {
    string test = "aas-ss    r-akdh, 36378eu6s78duh2ns7e278oditgfikmcvhz nd78aopxl,jcsazdcujmewugdbc jgsdhzdjxjwhdkdi9u";
    cout << normaliseString(test);
    string a;
/*
    const string PATH = PWD + "dictionary.txt";
    const string WORD = "knapsacked";
    cout << "word " << (findWord(PATH, WORD) ? "found" : "not found") << endl;
    */
    return 0;
}
