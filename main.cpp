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
#include "lecture.h"
#include "utils.h"


using namespace std;

/**
 * Order a list alphabetically (by inverting or ordering it if needed)
 * @param list a vector of string containing a list of word
 */
void formatListAlphabetically(vector<string> &list);

/**
 * Get a list all word not present in dictionary
 * @param pathDictionary a string containing the path to the file
 * @param pathBook a string containing the path to the file
 * @return
 */
vector<string> findMissingWord(const string &pathDictionary, const string &pathBook);

// Current directory
const string PWD = "/home/leonard/CLionProjects/Labo_9/";


void formatListAlphabetically(std::vector<std::string> &list) {
    switch (checkIfSorted(list)) {
        case 1:
            inverseList(list);
            break;
        case 2:
            sort(list.begin(), list.end());
            break;
        default:
            break;
    }
}

vector<string> findMissingWord(const string &pathDictionary, const string &pathBook) {
    const size_t MAX = size_t(-1);

    // Prepare dictionary
    vector<string> dictionary = readFileByLine(pathDictionary);

    //normalize before sorting otherwise won't work
    for (string &s : dictionary) {
        normaliseString(s);
    }

    formatListAlphabetically(dictionary);

    vector<string> book = readFileByLine(pathBook);
    const vector<vector<string>> words = readWordByLine(book);
    vector<vector<string>> wordsNormalized = words;

    for (vector<string> &v : wordsNormalized) {
        for (string &s : v) {
            normaliseString(s);
        }
    }
    vector<string> missingList;


    for (std::size_t i = 0; i < wordsNormalized.size(); ++i) {
        for (size_t j = 0; j < wordsNormalized.at(i).size(); ++j) {
            bool found = binary_search(dictionary.begin(), dictionary.end(), wordsNormalized.at(i).at(j));
            if (!found) {
                string missing = to_string(i + 1);
                missing += ": " + words.at(i).at(j);
                missingList.push_back(missing);
            }
        }
    }
    return missingList;
}

int main() {
    string dict = PWD + "dictionary.txt";
    string input = PWD + "input_sh.txt";
    vector<string> list = findMissingWord(dict, input);
    for (string &s : list) {
        cout << s << endl;
    }
    return 0;
}

