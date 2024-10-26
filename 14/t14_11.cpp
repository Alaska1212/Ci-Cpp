#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_WIDTH = 50;


void center(const string& filename) {
    ifstream inputf(filename);
    ofstream outputf("output.txt");
    string line;

    if (!inputf.is_open() || !outputf.is_open()) {
        cerr << "Error opening the file." << endl;
        return;
    }

    while (getline(inputf, line)) {
        int len = line.length();

        if (len > 0 && len <= MAX_WIDTH) {
            int max = (MAX_WIDTH - len) / 2;
            outputf << string(max, ' ') << line << endl;
        } else {
            outputf << line << endl;
        }
    }

    inputf.close();
    outputf.close();
}

int main() {
    string file = "input.txt";
    center(file);
    cout << "The answer is saved in the file'output.txt'." << endl;
    return 0;
}
