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
    bubbleSort(test_shuffled);
    string a = "Whiskey";
    cout << rechercheDichotomiqueRecursive(test_shuffled, "alpha");
    return 0;
}
