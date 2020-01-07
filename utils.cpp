/* ---------------------------
Laboratoire : 09
Fichier : utils.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But :

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */

#include "utils.h"
#include <string>

using namespace std;

void swap(string &a, string &b){
    string temp = a;
    a = b;
    b= temp;
}
