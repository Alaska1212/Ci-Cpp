#include <iostream>
#include <vector>
#include <map>
#include <string>

char getKey(const std::string& word) {
    return (word.length() > 1) ? word[1] : word[0];
}

int main() {
    std::vector<std::string> V;
    int n;
    std::cout << "Enter the number of words: ";
    std::cin >> n;
    std::cout << "Enter the words (one at a time):\n";
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;
        V.push_back(word);
    }

    std::multimap<char, std::string> M;
    for (const auto& word : V) {
        char key = getKey(word);
        M.insert({key, word});
    }

    std::cout << "\nGrouping result:\n";
    for (const auto& [key, value] : M) {
        std::cout << "Key: " << key << " -> Word: " << value << '\n';
    }

    return 0;
}
