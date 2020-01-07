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

int main() {
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
        cout <<test_shuffled.at(i)<<" "<< rechercheLineaire(test_shuffled, test_shuffled.at(i))<<endl;
    }
    cout << endl;
    for (int i = 0; i < test.size(); ++i) {
        cout <<test_shuffled.at(i)<<" "<< 26-(test_shuffled.end()-rechercheLineaire(test_shuffled.begin(), test_shuffled.end(), test_shuffled.at(i)))<<endl;
    }

    return 0;
}
