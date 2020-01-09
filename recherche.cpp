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
 * Search recursively using binary search if a word is contained inside a dictionary in an interval [a,b)
 * @param dictionary a vector of string containing the entries of the dictionary
 * @param word a string containing the word to find
 * @param first the beginning of the interval in which to look for (included)
 * @param last the end of the interval in which to look for (non-included)
 * @details average performance = O(log n)
 * @return true if the word is in the array, false otherwise
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

vector<string>::const_iterator rechercheLineaire(vector<string>::const_iterator begin,
                                                 vector<string>::const_iterator end, const string &word) {
    for (auto i = begin; i != end; ++i) {
        if (*i == word) {
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
                if (!middle) {
                    break;
                }
                end = middle - 1;

            }
        }
    }
    return output;
}

vector<string>::const_iterator rechercheDichotomique(vector<string>::const_iterator begin,
                                                     vector<string>::const_iterator end, const string &word) {

    vector<string>::const_iterator output = end;

    while (begin <= end) {
        size_t size = distance(begin, end); // size of the list
        size_t decal = size / 2;
        vector<string>::const_iterator middle = begin + decal;
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

    if (first == last) {
        return false;
    }
    string test = dictionary.at(middle);


    if (test == word) {
        return true;
    } else {
        if (middle == 0) {
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


bool rechercheDichotomiqueRecursive(vector<string>::const_iterator begin,
                                    vector<string>::const_iterator end, const string &word) {
    size_t size = end - begin; // size of the list
    size_t decal = size / 2;
    vector<string>::const_iterator middle = begin + decal;
    if (begin == end) {
        return false;
    }
    string test = *(middle);
    if (test == word) {
        return true;
    } else {
        if (word > test) {
            return rechercheDichotomiqueRecursive(middle + 1, end, word);
        } else {
            return rechercheDichotomiqueRecursive(begin, middle, word);
        }

    }
}
