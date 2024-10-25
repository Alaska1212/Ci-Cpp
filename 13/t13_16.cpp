#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void getWordsEndingWithChar(const string& text, char ending_char, string* words, int& count) {
    istringstream iss(text);
    string word;
    count = 0;

    while (iss >> word) {
        // ¬идал€Їмо зайв≥ проб≥ли з початку та к≥нц€ слова
        word.erase(0, word.find_first_not_of(" \t\n\r\f\v"));
        word.erase(word.find_last_not_of(" \t\n\r\f\v") + 1);

        if (!word.empty() && word.back() == ending_char) {
            words[count++] = word;
        }
    }
}

int main() {
    string text;
    char ending_char;

    cout << "¬вед≥ть р€док: ";
    getline(cin, text);

    cout << "¬вед≥ть символ: ";
    cin >> ending_char;

    const int MAX_WORDS = 1000;
    string words[MAX_WORDS];
    int count = 0;

    getWordsEndingWithChar(text, ending_char, words, count);

    cout << "—лова, що зак≥нчуютьс€ на '" << ending_char << "':" << endl;
    for (int i = 0; i < count; ++i) {
        cout << words[i] << endl;
    }

    return 0;
}

