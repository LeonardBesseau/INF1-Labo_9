/* ---------------------------
Laboratoire : 09
Fichier : lecture.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But :

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */
#include "lecture.h"

using namespace std;

vector<string> readFileByLine(const string &filename) {
    vector<string> file;
    ifstream inputFile;
    inputFile.open(filename);
    while (!inputFile.eof()) {
        string line;
        getline(inputFile, line);
        file.push_back(line);
    }
    inputFile.close();
}
