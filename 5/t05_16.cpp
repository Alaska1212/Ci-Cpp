#include <iostream>
using namespace std;

double y(double x, double eps) {
    double s = 0;
    double d1 = x;
    int n = 1;
    double num = x;
    double dem = 1;
    while (d1 > eps || d1 < -eps) {
        s += d1;
        n++;
        num *=-x ;
        dem *= n;
        d1 *= num / dem;
    }

    return s;
}

int main() {
    cout << "x = ";
    double x;
    double eps = 0.000001;
    cin >> x;

    cout << "y(x) = " << y(x, eps) << endl;

    return 0;
}
