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
        file.push_back(line);
    }
    inputFile.close();
    return file;
}

vector<vector<string>> readWordByLine(vector<string> &lines) {
    vector<vector<string>> separatedLines;
    separatedLines.reserve(lines.size());
    for (const string &line : lines) {
        separatedLines.push_back(split(line));
    }
    return separatedLines;
}


void inverseList(vector<string> &dictionary) {
    for (size_t start = 0, end = dictionary.size() - 1; start < end; ++start, --end) {
        swap(dictionary.at(start), dictionary.at(end));
    }
}

