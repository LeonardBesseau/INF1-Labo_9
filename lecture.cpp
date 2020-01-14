/* ---------------------------
Laboratoire : 09
Fichier : lecture.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Lecture d'un dictionnaire depuis un fichier et tri du fichier

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */
#include "lecture.h"
#include "utils.h"

using namespace std;


vector<string> readFileByLine(const string &filename) {
    vector<string> file;
    ifstream inputFile;
    inputFile.open(filename);

    // Check if file is valid and present
    if (!inputFile.good()) {
        return file;
    }

    while (!inputFile.eof()) {
        string line;
        getline(inputFile, line);
        size_t lineSize = line.size();
        // if file encoded as windows and on linux
        if (lineSize && line.at(lineSize - 1) == '\r') {
            line.resize(line.size() - 1);
        }
        if (!line.empty()) {
            file.push_back(line);
        }
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
        high.at(0) = dictionary.at(middle);
    }
    dictionary = mergeVectors(low, high);
}

