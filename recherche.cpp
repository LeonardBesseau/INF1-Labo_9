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
    size_t start = 0;
    size_t end= dictionary.size()-1;
    size_t output = size_t(-1);

    while(start <= end){
        size_t middle = (start+end)/2;
        string test = dictionary.at(middle);
        if(test == word){
            output = middle;
            break;
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

vector<string>::iterator rechercheDichotomique(vector<string>::iterator begin,
        vector<string>::iterator end , const string &word){

    vector<string>::iterator output = end;


    while(begin <= end){
        size_t size = end-begin;
        size_t decal = size/2;
        vector<string>::iterator middle = begin+decal;
        string test = *(middle);
        if(test == word){
            output = middle;
            break;
        }else{

            if(word > test){
                begin = middle+1;
            }else{
                end = middle-1;
            }

        }
    }
    return output;


}
