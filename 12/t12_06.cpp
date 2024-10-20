#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    string input;
    cout << "Enter real numbers separated by commas (less than 1000): ";
    getline(cin, input);

    stringstream ss(input);
    string number;
    double numbers[1000];
    int count = 0;

    while (getline(ss, number, ',')) {
        try {
            numbers[count] = stod(number);
            count++;
        } catch (const invalid_argument&) {
            cerr << "none " << number << endl;
            return 1;
        }
    }

    for (int i = 0; i < count; i++) {
        if (numbers[i] <= 0) {
            cout << "None" << endl;
        } else {
            double log_value = log(numbers[i]);
            cout << "Scientific format: " << log_value << "e, Decimal format: " << log_value << endl;
        }
    }

    return 0;
}
