#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string str = "hello, world";
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return toupper(c);
    });

    cout << "res: " << str << endl;

    return 0;
}
