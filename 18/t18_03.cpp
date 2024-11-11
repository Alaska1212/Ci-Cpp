#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class BlackBox {
private:
    T* array;
    int size;
    static const int MAX_SIZE = 100;

public:

    BlackBox() : size(0) {
        array = new T[MAX_SIZE];
        srand(time(0));
    }

    ~BlackBox() {
        delete[] array;
    }

    void push(T element) {
        if (size >= MAX_SIZE) {
            throw overflow_error("BlackBox is full");
        }
        array[size++] = element;
    }

    T pop() {
        if (size == 0) {
            throw underflow_error("BlackBox is empty");
        }
        int index = rand() % size;
        T element = array[index];
        array[index] = array[--size];
        return element;
    }

    T xpop() const {
        if (size == 0) {
            throw underflow_error("BlackBox is empty");
        }
        int index = rand() % size;
        return array[index];
    }
};

int main() {
    try {
        BlackBox<int> box;
        box.push(10);
        box.push(20);
        box.push(30);

        cout << "Random element (xpop): " << box.xpop() << endl;
        cout << "Random element removed (pop): " << box.pop() << endl;
        cout << "Random element removed (pop): " << box.pop() << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
