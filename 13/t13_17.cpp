#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void trans(string sentence) {
    string word;
    string prev_word = "";
    istringstream stream(sentence);

    while (stream >> word) {
        if (prev_word == "a" || prev_word == "an" || prev_word == "the") {
            if (!word.empty() && word[0] >= 'A' && word[0] <= 'Z') {
                word[0] = word[0] + 32;
            }
        }
        cout << word << " ";
        prev_word = word;
    }

    cout << endl;
}

int main() {
    string sentence = "The Apple is a Great Fruit and the Dog is an Animal";
    trans(sentence);
    return 0;
}
