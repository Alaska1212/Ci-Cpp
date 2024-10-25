#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void transformSentence(string sentence) {
    string word;
    string prev_word = "";  // To track the previous word
    istringstream stream(sentence);

    while (stream >> word) {
        // Check if the previous word was an article
        if (prev_word == "a" || prev_word == "an" || prev_word == "the") {
            if (!word.empty() && word[0] >= 'A' && word[0] <= 'Z') {
                word[0] = word[0] + 32;  // Convert uppercase to lowercase by adding 32 (ASCII)
            }
        }
        cout << word << " ";
        prev_word = word;  // Update previous word
    }

    cout << endl;
}

int main() {
    string sentence = "The Apple is a Great Fruit and the Dog is an Animal";
    transformSentence(sentence);
    return 0;
}
