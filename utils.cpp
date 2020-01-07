/* ---------------------------
Laboratoire : 09
Fichier : utils.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Le but de ce laboratoire est d'établir les bases d'un correcteur orthographique.
Nous nous intéressons particulièrement à la lecture d'un fichier contenant la liste des mots du dictionnaire,
et à la recherche dans cette liste d'un mot donné ou d'un vector<string> de mots provenant d'un fichier.
Le progrmme affiche alors si le ou les mots ne sont pas présent dans le dictionnaire.

Remarque(s) : Fichier non demandé dans la consigne

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
