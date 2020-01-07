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

using namespace std;

void testReadingFile() {
    const vector<string> NATO{"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India",
                              "Juliet",
                              "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango",
                              "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};
    vector<string> test = readFileByLine("/home/leonard/Downloads/nato.txt");
    bool error = false;
    for (int i = 0; i < NATO.size(); ++i) {
        if (test.at(i) != NATO.at(i)) {
            cout << "Error Inversion Test at index " << i << " element " << test.at(i) << " != " << NATO.at(i) << endl;
            error = true;
        }
    }
    cout << (!error ? "Reading from file OK " : "Error") << endl;
}

void testInversion() {
    const vector<string> NATO{"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India",
                              "Juliet",
                              "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango",
                              "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};
    const vector<string> OTAN{"Zulu", "Yankee", "Xray", "Whiskey", "Victor", "Uniform", "Tango", "Sierra", "Romeo",
                              "Quebec",
                              "Papa", "Oscar", "November", "Mike", "Lima", "Kilo", "Juliet", "India", "Hotel", "Golf",
                              "Foxtrot", "Echo", "Delta", "Charlie", "Bravo", "Alpha"};

    vector<string> v1 = NATO;
    vector<string> v2 = OTAN;

    inverseList(v1);
    inverseList(v2);

    bool error = false;

    for (int i = 0; i < NATO.size(); ++i) {
        if (v1.at(i) != OTAN.at(i)) {
            cout << "Error Inversion Test at index " << i << " element " << v1.at(i) << " != " << OTAN.at(i) << endl;
            error = true;
        }
        if (v2.at(i) != NATO.at(i)) {
            cout << "Error Inversion Test at index " << i << " element " << v2.at(i) << " != " << NATO.at(i) << endl;
            error = true;
        }
    }
    cout << (!error ? "Inversion OK " : "Error") << endl;
}

void testSort() {
    const vector<string> NATO_SHUFFLED{"kilo", "golf", "november", "charlie", "alpha", "sierra", "delta", "uniform",
                                       "yankee", "tango", "echo", "lima", "xray", "victor", "bravo", "romeo", "zulu",
                                       "hotel", "mike", "juliet", "quebec", "foxtrot", "india", "oscar", "papa",
                                       "whiskey"};
    const vector<string> NATO{"alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india",
                              "juliet", "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo",
                              "sierra", "tango", "uniform", "victor", "whiskey", "xray", "yankee", "zulu"};

    vector<string> test = NATO_SHUFFLED;

    bubbleSort(test);

    bool error = false;
    for (int i = 0; i < NATO.size(); ++i) {
        if (test.at(i) != NATO.at(i)) {
            cout << "Error Inversion Test at index " << i << " element " << test.at(i) << " != " << NATO.at(i) << endl;
            error = true;
        }
    }
    cout << (!error ? "BubbleSort OK " : "Error") << endl;

    test = NATO_SHUFFLED;
    mergeSort(test);

    error = false;
    for (int i = 0; i < NATO.size(); ++i) {
        if (test.at(i) != NATO.at(i)) {
            cout << "Error Inversion Test at index " << i << " element " << test.at(i) << " != " << NATO.at(i) << endl;
            error = true;
        }
    }
    cout << (!error ? "MergeSort OK " : "Error") << endl;

}

int main() {
    testReadingFile();
    testInversion();
    testSort();
    //   vector<string> test = readFileByLine("/home/leonard/Downloads/dictionary.txt");
    //  mergeSort(test);
    /*
    std::cout << "Hello, World!" << std::endl;
    vector<string> test{"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliet",
                        "Kilo", "Lima", "Mike", "Novembe", "Osca", "Papa", "Quebec", "Romeo", "Sierra", "Tango",
                        "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};
    vector<string> test_shuffled{"kilo", "golf", "novembe", "charlie", "alpha", "sierra", "delta", "uniform", "yankee",
                                 "tango", "echo", "lima", "xray", "victo", "bravo", "romeo", "zulu", "hotel", "mike",
                                 "juliet", "quebec", "foxtrot", "india", "osca", "papa", "whiskey"};
    vector<string> b = readFileByLine("/home/leonard/Downloads/nato.txt");
    bubbleSort(test_shuffled);
    inverseList(test);
    string a = "Whiskey";
    for (int i = 0; i < test.size(); ++i) {
        cout << test_shuffled.at(i) << " " << rechercheLineaire(test_shuffled, test_shuffled.at(i)) << endl;
    }
    cout << endl;
    for (int i = 0; i < test.size(); ++i) {
        cout << test_shuffled.at(i) << " " << 26 - (test_shuffled.end() -
                                                    rechercheLineaire(test_shuffled.begin(), test_shuffled.end(),
                                                                      test_shuffled.at(i))) << endl;
    }
*/
    return 0;
}
