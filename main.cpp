/* ---------------------------
Laboratoire : 09
Fichier : main.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But :

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */
#include <iostream>
#include "recherche.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<string> test{"Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliet",
                        "Kilo", "Lima", "Mike", "Novembe", "Osca", "Papa", "Quebec", "Romeo", "Sierra", "Tango",
                        "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"};
    string a = "Whiskey";
    cout << (test.end()-rechercheDichotomique(test.begin(), test.end(), "Bravo"));
    return 0;
}
