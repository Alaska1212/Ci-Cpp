#include <iostream>
#include <sstream>
#include <string>
using namespace std;


void del(const string& text, char ending_char, string* words, int& count) {
    istringstream iss(text);
    string word;
    count = 0;

    while (iss >> word) {
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

    cout << "Enter the line: ";
    getline(cin, text);

    cout << "Enter a char: ";
    cin >> ending_char;

    const int MAX_WORDS = 1000;
    string words[MAX_WORDS];
    int count = 0;

    del(text, ending_char, words, count);

    cout << "Words ending in '" << ending_char << "':" << endl;
    for (int i = 0; i < count; ++i) {
        cout << words[i] << endl;
    }

    return 0;
}

