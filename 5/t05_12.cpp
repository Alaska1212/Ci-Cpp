#include <iostream>
using namespace std;

double S(int k) {

    double a0 = 1, a1 = 2;
    double b0 = 5, b1 = 5;
    double a2, b2;
    double pow = 1;
    double sum = 0.0;

    for (int i = 2; i <= k; i++) {
        a2 = b0 + (b0 * b0 - a1) / 2.0;
        b2 = b0 * b0 - a1;
        pow *= (a2 / b2);
        sum += pow;

        b0 = b1;
        b1 = b2;
        a1 = a2;
    }

    return sum;
}

int main() {
    cout << "k = ";
    int k;
    cin >> k;

    cout << "S(k) = " << S(k) << endl;

    return 0;
}
