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

const vector<string> NATO_WITH_MAJ{"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India",
                                   "Juliet", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
                                   "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};
const vector<string> NATO_WITHOUT_MAJ{"alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india",
                                      "juliet", "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo",
                                      "sierra", "tango", "uniform", "victor", "whiskey", "xray", "yankee", "zulu"};

const vector<string> OTAN{"Zulu", "Yankee", "Xray", "Whiskey", "Victor", "Uniform", "Tango", "Sierra", "Romeo",
                          "Quebec", "Papa", "Oscar", "November", "Mike", "Lima", "Kilo", "Juliet", "India", "Hotel",
                          "Golf", "Foxtrot", "Echo", "Delta", "Charlie", "Bravo", "Alpha"};
const vector<string> OTAN_WITHOUT_MAJ{"zulu", "yankee", "xray", "whiskey", "victor", "uniform", "tango", "sierra",
                                      "romeo",
                                      "quebec", "papa", "oscar", "november", "mike", "lima", "kilo", "juliet", "india",
                                      "hotel",
                                      "golf", "foxtrot", "echo", "delta", "charlie", "bravo", "alpha"};

const vector<string> NATO_SHUFFLED{"kilo", "golf", "november", "charlie", "alpha", "sierra", "delta", "uniform",
                                   "yankee", "tango", "echo", "lima", "xray", "victor", "bravo", "romeo", "zulu",
                                   "hotel", "mike", "juliet", "quebec", "foxtrot", "india", "oscar", "papa",
                                   "whiskey"};

void testReadingFile() {
    vector<string> test = readFileByLine("/home/leonard/Downloads/nato.txt");
    bool error = false;
    for (int i = 0; i < NATO_WITH_MAJ.size(); ++i) {
        if (test.at(i) != NATO_WITH_MAJ.at(i)) {
            cout << "Error readingFile Test at index " << i << " element " << test.at(i) << " != "
                 << NATO_WITH_MAJ.at(i)
                 << endl;
            error = true;
        }
    }
    cout << (!error ? "Reading from file OK " : "Error") << endl;
}

void testInversion() {
    vector<string> v1 = NATO_WITH_MAJ;
    vector<string> v2 = OTAN;

    inverseList(v1);
    inverseList(v2);

    bool error = false;

    for (int i = 0; i < NATO_WITH_MAJ.size(); ++i) {
        if (v1.at(i) != OTAN.at(i)) {
            cout << "Error Inversion Test at index " << i << " element " << v1.at(i) << " != " << OTAN.at(i) << endl;
            error = true;
        }
        if (v2.at(i) != NATO_WITH_MAJ.at(i)) {
            cout << "Error Inversion Test at index " << i << " element " << v2.at(i) << " != " << NATO_WITH_MAJ.at(i)
                 << endl;
            error = true;
        }
    }
    cout << (!error ? "Inversion OK " : "Error") << endl;
}

void testSort() {
    vector<string> test = NATO_SHUFFLED;

    bubbleSort(test);

    bool error = false;
    for (int i = 0; i < NATO_WITHOUT_MAJ.size(); ++i) {
        if (test.at(i) != NATO_WITHOUT_MAJ.at(i)) {
            cout << "Error BubbleSort Test at index " << i << " element " << test.at(i) << " != " << NATO_WITH_MAJ.at(i)
                 << endl;
            error = true;
        }
    }
    cout << (!error ? "BubbleSort OK " : "Error") << endl;

    test = NATO_SHUFFLED;
    mergeSort(test);

    error = false;
    for (int i = 0; i < NATO_WITHOUT_MAJ.size(); ++i) {
        if (test.at(i) != NATO_WITHOUT_MAJ.at(i)) {
            cout << "Error MergeSort Test at index " << i << " element " << test.at(i) << " != " << NATO_WITH_MAJ.at(i)
                 << endl;
            error = true;
        }
    }
    cout << (!error ? "MergeSort OK " : "Error") << endl;
}

void testLinear() {
    const vector<string> wordTest{"alpha", "al", "a", "alpa", "kilo", "rover", "zuluR"};
    const size_t NOT_FOUND = size_t(-1);
    const vector<size_t> WORD_TEST_INDEX_ORDERED{0, NOT_FOUND, NOT_FOUND, NOT_FOUND, 10, NOT_FOUND, NOT_FOUND};
    const vector<size_t> WORD_TEST_INDEX_UNORDERED{4, NOT_FOUND, NOT_FOUND, NOT_FOUND, 0, NOT_FOUND, NOT_FOUND};

    bool error = false;

    for (size_t i = 0; i < wordTest.size(); ++i) {
        if (rechercheLineaire(NATO_SHUFFLED, wordTest.at(i)) != WORD_TEST_INDEX_UNORDERED.at(i)) {
            cout << "Error linear unordered Test at index " << i << endl;
            error = true;
        }
        if (rechercheLineaire(NATO_WITHOUT_MAJ, wordTest.at(i)) != WORD_TEST_INDEX_ORDERED.at(i)) {
            cout << "Error linear ordered Test at index " << i << endl;
            error = true;
        }
    }
    bool test = NATO_SHUFFLED.begin() + 4 == rechercheLineaire(NATO_SHUFFLED.cbegin(), NATO_SHUFFLED.cend(), "alpha");
    bool test1 = NATO_SHUFFLED.end() == rechercheLineaire(NATO_SHUFFLED.begin(), NATO_SHUFFLED.end(), "al");
    if (!test || !test1) {
        cout << "Error linear unordered Test" << endl;
    }

    cout << (!error ? "LinearSort OK " : "Error") << endl;
}

void testDichotomique() {
    const vector<string> wordTest{"alpha", "al", "a", "alpa", "kilo", "rover", "zuluR"};
    const size_t NOT_FOUND = size_t(-1);
    const vector<size_t> WORD_TEST_INDEX_ORDERED{0, NOT_FOUND, NOT_FOUND, NOT_FOUND, 10, NOT_FOUND, NOT_FOUND};
    const vector<bool> WORD_TEST_RECURSIVE{true, false, false, false, true, false, false};


    bool error = false;

    for (size_t i = 0; i < wordTest.size(); ++i) {

        if (rechercheDichotomique(NATO_WITHOUT_MAJ, wordTest.at(i)) != WORD_TEST_INDEX_ORDERED.at(i)) {
            cout << "Error dichotomique Test at index " << i << endl;
            error = true;
        }
        if (rechercheDichotomiqueRecursive(NATO_WITHOUT_MAJ, wordTest.at(i)) != WORD_TEST_RECURSIVE.at(i)) {
            cout << "Error dichotomique recursive Test at index " << i << endl;
            error = true;
        }
    }
    bool validIteratorSearch = NATO_WITHOUT_MAJ.begin() ==
                               rechercheDichotomique(NATO_WITHOUT_MAJ.cbegin(), NATO_WITHOUT_MAJ.cend(), "alpha");
    bool validIteratorSearchB = NATO_WITHOUT_MAJ.begin()+4 ==
                               rechercheDichotomique(NATO_WITHOUT_MAJ.cbegin(), NATO_WITHOUT_MAJ.cend(), "echo");
    bool invalidIteratorSearchLower = NATO_WITHOUT_MAJ.end() ==
                                      rechercheDichotomique(NATO_WITHOUT_MAJ.begin(), NATO_WITHOUT_MAJ.end(), "al");
    bool invalidIteratorSearchUpper = NATO_WITHOUT_MAJ.end() ==
                                      rechercheDichotomique(NATO_WITHOUT_MAJ.begin(), NATO_WITHOUT_MAJ.end(), "zulur");
    bool test2 = rechercheDichotomiqueRecursive(NATO_WITHOUT_MAJ.cbegin(), NATO_WITHOUT_MAJ.cend(), "alpha");
    bool test3 = !rechercheDichotomiqueRecursive(NATO_WITHOUT_MAJ.begin(), NATO_WITHOUT_MAJ.end(), "al");
    bool test4 = !rechercheDichotomiqueRecursive(NATO_WITHOUT_MAJ.begin(), NATO_WITHOUT_MAJ.end(), "zuluR");
    bool test5 = !rechercheDichotomiqueRecursive(NATO_WITHOUT_MAJ.begin(), NATO_WITHOUT_MAJ.end(), "zula");
    bool test6 = !rechercheDichotomiqueRecursive(NATO_WITHOUT_MAJ.begin(), NATO_WITHOUT_MAJ.end(), "");
    if (!validIteratorSearch || !invalidIteratorSearchLower || !invalidIteratorSearchUpper) {
        cout << "Error dichotomique Test" << endl;
    }
    if (!test2 || !test3 || !test4|| !test5 || !test6) {
        cout << "Error dichotomique recursive Test" << endl;
    }

    cout << (!error ? "dichotomique OK " : "Error") << endl;
}


size_t findWord(const string &path, const string &word) {
    vector<string> dictionary = readFileByLine(path);
    formatListAlphabetically(dictionary);
    cout << "dictionnary size "<<dictionary.size()<<endl;
    return rechercheDichotomique(dictionary, word);
}

int main() {
    testReadingFile();
    testInversion();
    testSort();
    testLinear();
    testDichotomique();

    const string PATH = "/home/leonard/Downloads/dictionary.txt";
    const string WORD = "";
    cout << findWord(PATH, "zip")<<endl;
    return 0;
}
