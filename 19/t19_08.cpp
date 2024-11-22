#include <iostream>
#include <list>
#include <cmath>
using namespace std;

class NumberStorage {
private:
    list<int> numbers;
public:
    void addNumber(int num) {
        numbers.push_back(num);
    }

    void removeNumber(int num) {
        numbers.remove(num);
    }

    int findClosestNumber(int target) {
        if (numbers.empty()) {
            throw runtime_error("List is empty");
        }

        int closest = *numbers.begin();
        int min_diff = abs(target - closest);

        for (int num : numbers) {
            int diff = abs(target - num);
            if (diff < min_diff) {
                closest = num;
                min_diff = diff;
            }
        }

        return closest;
    }

    void printNumbers() {
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    NumberStorage storage;
    storage.addNumber(10);
    storage.addNumber(20);
    storage.addNumber(30);

    cout << "List of numbers: ";
    storage.printNumbers();

    cout << "Closest to 25: " << storage.findClosestNumber(25) << endl;

    storage.removeNumber(20);
    cout << "Remove 20: ";
    storage.printNumbers();

    return 0;
}
