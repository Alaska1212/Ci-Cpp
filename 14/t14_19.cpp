#include <iostream>
#include <fstream>
#include <string>
using namespace std;



bool starts(char target, const string& word) {
    if (word.empty()) return false;
    return (word[0] == target || word[0] == target + ('a' - 'A'));
}

void filter(char letter, const string& inputf, const string& outputf) {
    ifstream input(inputf);
    ofstream output(outputf);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Ошибка при открытии файлов." << endl;
        return;
    }

    string word;
    bool foundWord = false;

    while (input >> word) {
        size_t start = 0, end = word.size() - 1;
        while (start < word.size() && !(word[start] >= 'A' && word[start] <= 'Z') && !(word[start] >= 'a' && word[start] <= 'z')) ++start;
        while (end > start && !(word[end] >= 'A' && word[end] <= 'Z') && !(word[end] >= 'a' && word[end] <= 'z')) --end;

        word = word.substr(start, end - start + 1);

        if (starts(letter, word)) {
            output << word << endl;
            foundWord = true;
        }
    }

    input.close();
    output.close();
}

int main() {
    char letter;
    string inputf;
    string outputf = "words.txt";

    cout << "Enter a letter: ";
    cin >> letter;
    cout << "The name of the input file: ";
    cin >> inputf;

    filter(letter, inputf, outputf);
    cout << "The answer is in the file 'words.txt'." << endl;

    return 0;
}
