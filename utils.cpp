/* ---------------------------
Laboratoire : 09
Fichier : utils.cpp
Auteur(s) : Besseau Zwick Austburger
Date :  07.01.2020

But : Methodes supplémentaires. Liste:
 - Swap string
 - Merge vectors in place
 - check how a vector is sorted

Remarque(s) : Fichier non demandé dans la consigne

Compilateur : g++ 7.4.0

--------------------------- */


#include <string>
#include "utils.h"


using namespace std;

/**
 * Verify if a char is an invalid character for a word or a phrase (' and space are authorized)
 * @param c a char to validate
 * @return false if a valid character, true otherwise
 */
bool isInvalidChar(char c);

/**
 * Verify is a character is a punctuation sign
 * @param c a char to verify
 * @return true if a valid character, false otherwise
 */
bool isPunctuation(char c);

void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

vector<string> mergeVectors(const vector<string> &v1, const vector<string> &v2) {
    vector<string> output;
    output.reserve(v1.size() + v2.size()); // reserve enough space
    size_t indexV1 = 0;
    size_t indexV2 = 0;
    for (;;) {
        if (v1.at(indexV1) < v2.at(indexV2)) {
            output.push_back(v1.at(indexV1));
            ++indexV1;
            if (indexV1 >= v1.size()) {
                output.insert(output.end(), v2.begin() + indexV2, v2.end());
                return output;
            }
        } else {

            output.push_back(v2.at(indexV2));
            ++indexV2;
            if (indexV2 >= v2.size()) {
                output.insert(output.end(), v1.begin() + indexV1, v1.end());
                return output;
            }
        }
    }
}

int checkIfSorted(const vector<string> &list) {
    int listState = 0; // 0 for in order, 1 for backwards, 2 for shuffled
    for (size_t i = 1; i < list.size(); ++i) {
        if (!list.at(i).empty()) {
            if (list.at(i - 1) > list.at(i)) {
                listState = 1;
            } else {
                if (listState == 1) {
                    listState = 2;
                    break;
                }
            }
        }
    }
    return listState;
}

bool isInvalidChar(char c) {
    return !isalpha(c) && c != '\'';
}

string &normaliseString(string &s) {
    s.erase(remove_if(s.begin(), s.end(), isInvalidChar), s.end());
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (all_of(s.begin(), s.end(), [](char c) { return c == '\''; })) {
        s.erase();
    }
    if (!s.empty() && s.front() == '\'') {
        s.erase(0, 1);
    }
    if (!s.empty() && s.back() == '\'') {
        s.pop_back();
    }
    return s;
}

// TODO do we need to split for - too
vector<string> split(const string &line) {
    // remove dash
    string noPunctuation = line;
    replace_if(noPunctuation.begin(), noPunctuation.end(), isPunctuation, ' ');
    vector<string> output;


    string::iterator i = noPunctuation.begin();

    // +1 because we take the element after the iterator
    while (i != noPunctuation.end() + 1) {
        string::iterator b = find(i, noPunctuation.end(), ' ');
        if (distance(i, b)) {
            output.emplace_back(i, b);
        }
        i = b + 1;
    }

    return output;
}

bool isPunctuation(char c) {
    switch (c) {
        case '-':
        case '.':
        case ',':
        case '/':
        case '\"':
        case '@':
        case ':':
            return true;
        default:
            return false;
    }
}

