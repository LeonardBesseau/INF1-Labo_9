/* ---------------------------
Laboratoire : 09
Fichier : utils.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Le but de ce laboratoire est d'établir les bases d'un correcteur orthographique.
Nous nous intéressons particulièrement à la lecture d'un fichier contenant la liste des mots du dictionnaire,
et à la recherche dans cette liste d'un mot donné ou d'un vector<string> de mots provenant d'un fichier.
Le progrmme affiche alors si le ou les mots ne sont pas présent dans le dictionnaire.

Remarque(s) : Fichier non demandé dans la consigne

Compilateur : g++ 7.4.0

--------------------------- */

#include "utils.h"
#include <string>


using namespace std;

/**
 * Verify in which order a list is sorted
 * @param list a vector of string containing a list of word
 * @return 0 if the list is sorted alphabetically, 1 if the list is inverted, 2 if the list is shuffled
 */
int checkIfSorted(const vector<string> &list);

void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

vector<string> mergeVectors(const vector<string> &v1, const vector<string> &v2) {
    vector<string> output;
    output.reserve(v1.size() + v2.size()); // reserve enough space
    size_t indexV1 = 0;
    size_t indexV2 = 0;
    for (;;) {
        if (v1.at(indexV1) < v2.at(indexV2)) {
            output.push_back(v1.at(indexV1));
            ++indexV1;
            if (indexV1 >= v1.size()) {
                output.insert(output.end(), v2.begin() + indexV2, v2.end());
                return output;
            }
        } else {

            output.push_back(v2.at(indexV2));
            ++indexV2;
            if (indexV2 >= v2.size()) {
                output.insert(output.end(), v1.begin() + indexV1, v1.end());
                return output;
            }
        }
    }
}

int checkIfSorted(const vector<string> &list) {
    int listState = 0; // 0 for in order, 1 for backwards, 2 for shuffled
    for (size_t i = 1; i < list.size(); ++i) {
        string a = list.at(i - 1);
        string b = list.at(i);
        if (!list.at(i).empty()) {
            if (list.at(i - 1) > list.at(i)) {
                listState = 1;
            } else {
                if (listState == 1) {
                    listState = 2;
                    break;
                }
            }
        }
    }
    return listState;
}

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
