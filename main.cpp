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
 * Get a list all word not present in dictionary
 * @param pathDictionary a string containing the path to the file
 * @param pathBook a string containing the path to the file
 */
void findMissingWord(const string &pathDictionary, const string &pathBook) {
    const size_t MAX = size_t(-1);

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
    vector<string> tttt;


    for (std::size_t i = 0; i < wordsNormalized.size(); ++i) {
        for (size_t j = 0; j < wordsNormalized.at(i).size(); ++j) {
            size_t position = rechercheDichotomique(dictionary, wordsNormalized.at(i).at(j));
            if (MAX == position) {
                string missing = to_string(i);
                missing += " : " + words.at(i).at(j) + " p " + to_string(position);
                cout << missing << endl;
                tttt.push_back(missing);
            }
        }
    }
    cout << "dictionnary size " << dictionary.size() << endl;
    cout << "missing size " << tttt.size() << endl;

}

int main() {
    const string PATH = PWD + "dictionary.txt";
    const string WORD = "knapsacked";


    string test = "test test1 test2";
    string test1 = "test3 test4 test5";
    vector<string> a;
    a.push_back(test);
    a.push_back(test1);
    vector<vector<string>> c = readWordByLine(a);
    string b;


    string dict = PWD + "dictionary.txt";
    string input = PWD + "input_sh.txt";
    findMissingWord(dict, input);
/*

    cout << "word " << (findWord(PATH, WORD) ? "found" : "not found") << endl;
    */
    return 0;
}
