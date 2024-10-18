#include <iostream>
#include <bitset>
using namespace std;

int r(int num, int pos) {

    int right = num & ((1 << pos) - 1);
    int left = (num >> (pos + 1)) << pos;
    return left | right;
}

int main() {
    int num, pos;

    cout << "number =  ";
    cin >> num;
    cout << "position = ";
    cin >> pos;

    int result = r(num, pos);
    cout << "Remove " << pos << "-bit: " << result << endl;

    return 0;
}
