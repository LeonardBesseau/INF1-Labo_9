/* ---------------------------
Laboratoire : 09
Fichier : recherche.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But :

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */

#include "recherche.h"
using namespace std;

size_t rechercheLineaire(const vector<string> &dictionary, const string &word){
    for (size_t i = 0; i < dictionary.size(); ++i) {
        if(dictionary.at(i) == word){
            return i;
        }
    }
    return size_t(-1);
}

size_t rechercheDichotomique(const vector<string> &dictionary, const string &word){
    bool found = false;
    size_t start = 0;
    size_t end= dictionary.size()-1;
    size_t output = size_t(-1);
    while( !found && start <= end){
        size_t middle = (start+end)/2;
        string test = dictionary.at(middle);
        if(test == word){
            found = true;
            output = middle;
        }else{
            if(word > test){
                start = middle+1;
            }else{
                end= middle-1;
            }
        }
    }
    return output;
}
