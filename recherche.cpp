/* ---------------------------
Laboratoire : 09
Fichier : recherche.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Le but de ce laboratoire est d'établir les bases d'un correcteur orthographique.
Nous nous intéressons particulièrement à la lecture d'un fichier contenant la liste des mots du dictionnaire,
et à la recherche dans cette liste d'un mot donné ou d'un vector<string> de mots provenant d'un fichier.
Le progrmme affiche alors si le ou les mots ne sont pas présent dans le dictionnaire.

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */

#include "recherche.h"

using namespace std;

/**
 * 
 * @param dictionary
 * @param word
 * @param first
 * @param last
 * @return
 */
bool rechercheDichotomiqueRecursive(const vector<string> &dictionary, const string &word,
                                    size_t first, size_t last);

size_t rechercheLineaire(const vector<string> &dictionary, const string &word) {
    for (size_t i = 0; i < dictionary.size(); ++i) {
        if (dictionary.at(i) == word) {
            return i;
        }
    }
    return size_t(-1);
}

vector<string>::iterator rechercheLineaire(vector<string>::iterator begin,
                                               vector<string>::iterator end, const string &word) {
    for (auto i = begin; i != end; ++i){
        if(*i == word){
            return i;
        }
    }
    return end;

}

size_t rechercheDichotomique(const vector<string> &dictionary, const string &word) {
    size_t start = 0;
    size_t end = dictionary.size() - 1;
    size_t output = size_t(-1);

    while (start <= end) {
        size_t middle = (start + end) / 2;
        string test = dictionary.at(middle);
        if (test == word) {
            output = middle;
            break;
        } else {
            if (word > test) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }
    }
    return output;
}

vector<string>::iterator rechercheDichotomique(vector<string>::iterator begin,
                                               vector<string>::iterator end, const string &word) {

    vector<string>::iterator output = end;

    while (begin <= end) {
        size_t size = end - begin; // size of the list
        size_t decal = size / 2;
        vector<string>::iterator middle = begin + decal;
        string test = *(middle);
        if (test == word) {
            output = middle;
            break;
        } else {
            if (word > test) {
                begin = middle + 1;
            } else {
                end = middle - 1;
            }
        }
    }
    return output;
}

bool rechercheDichotomiqueRecursive(const vector<string> &dictionary, const string &word) {
    return rechercheDichotomiqueRecursive(dictionary, word, 0, dictionary.size());
}

bool rechercheDichotomiqueRecursive(const vector<string> &dictionary, const string &word,
                                    size_t first, size_t last) {
    size_t middle = (last + first) / 2;

    string test = dictionary.at(middle);

    if (test == word) {
        return true;
    } else {
        if (middle == 0 || first == last) {
            return false;
        } else {
            if (word > test) {
                return rechercheDichotomiqueRecursive(dictionary, word, middle + 1, last);
            } else {
                return rechercheDichotomiqueRecursive(dictionary, word, first, middle);
            }
        }
    }
}


bool rechercheDichotomiqueRecursive(vector<string>::iterator begin,
                                    vector<string>::iterator end, const string &word) {
    size_t size = end - begin; // size of the list
    size_t decal = size / 2;
    vector<string>::iterator middle = begin + decal;
    string test = *(middle);
    if (test == word) {
        return true;
    } else {
        if (begin == end) {
            return false;
        } else {
            if (word > test) {
                return rechercheDichotomiqueRecursive(middle + 1, end, word);
            } else {
                return rechercheDichotomiqueRecursive(begin, middle, word);
            }
        }
    }
}
