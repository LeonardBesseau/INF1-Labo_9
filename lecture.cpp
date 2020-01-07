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

void bubbleSort(std::vector<std::string> &dictionary){
    size_t lastElement = dictionary.size(); // end of the unsorted part of the list
    do{
        size_t newLastElement = 0; //index of the future end of the unsorted part of the list
        for (size_t i = 1; i < lastElement; ++i) {
            if(dictionary.at(i-1) > dictionary.at(i)){
                // swap element
                string temp = dictionary.at(i-1);
                dictionary.at(i-1) = dictionary.at(i);
                dictionary.at(i) = temp;
                // if future element are already ordered, next loop will ignore them
                newLastElement=i;
            }
        }
        lastElement= newLastElement;
    }while(lastElement > 0);
}