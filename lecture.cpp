/* ---------------------------
Laboratoire : 09
Fichier : lecture.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Le but de ce laboratoire est d'établir les bases d'un correcteur orthographique.
Nous nous intéressons particulièrement à la lecture d'un fichier contenant la liste des mots du dictionnaire,
et à la recherche dans cette liste d'un mot donné ou d'un vector<string> de mots provenant d'un fichier.
Le progrmme affiche alors si le ou les mots ne sont pas présent dans le dictionnaire.

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */
#include "lecture.h"
#include "utils.h"

using namespace std;

vector<string> mergeVectors(const vector<string> &v1, const vector<string> &v2);

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
    return file;
}

void inverseList(vector<string> &dictionary) {
    for (size_t start = 0, end = dictionary.size() - 1; start < end; ++start, --end) {
        swap(dictionary.at(start), dictionary.at(end));
    }
}

void bubbleSort(vector<string> &dictionary) {
    size_t lastElement = dictionary.size(); // end of the unsorted part of the list
    do {
        size_t newLastElement = 0; //index of the future end of the unsorted part of the list
        for (size_t i = 1; i < lastElement; ++i) {
            if (dictionary.at(i - 1) > dictionary.at(i)) {
                swap(dictionary.at(i - 1), dictionary.at(i));
                // if future element are already ordered, next loop will ignore them
                newLastElement = i;
            }
        }
        lastElement = newLastElement;
    } while (lastElement > 0);
}

void mergeSort(vector<string> &dictionary) {
    size_t size = dictionary.size();
    if (size < 2) {
        return;
    }
    size_t middle = (size + 1) / 2; //rounding up
    vector<string> low(dictionary.begin(), dictionary.begin() + middle);
    vector<string> high(dictionary.begin() + middle, dictionary.end());
    if (middle > 1) { // first half part
        mergeSort(low);
    }
    if (size - middle > 1) { // second half part
        mergeSort(high);
    } else {
        high.at(0) =dictionary.at(middle);
    }
    dictionary=mergeVectors(low,high);

}

vector<string> mergeVectors(const vector<string> &v1, const vector<string> &v2) {
    vector<string> output;
    output.reserve(v1.size()+v2.size()); // reserve enough space
    size_t indexV1 = 0;
    size_t indexV2 = 0;
    for (;;) {
        if (v1.at(indexV1) < v2.at(indexV2)){
            output.push_back(v1.at(indexV1));
            ++indexV1;
            if(indexV1 >= v1.size()){
                output.insert(output.end(), v2.begin()+indexV2, v2.end());
                return output;
            }
        }else{

            output.push_back(v2.at(indexV2));
            ++indexV2;
            if(indexV2 >= v2.size()){
                output.insert(output.end(), v1.begin()+indexV1, v1.end());
                return output;
            }
        }
    }
}