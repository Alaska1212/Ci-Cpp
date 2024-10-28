#include <iostream>
#include <cmath>
using namespace std;

class QuadraticEquation {
private:
    int a, b, c;

public:
    QuadraticEquation(int a, int b, int c) : a(a), b(b), c(c) {} // конструктор

    void roots(double& r1, double& r2, int& res) {
        double d = b * b - 4 * a * c;
        if (d > 0) {
            r1 = (-b + sqrt(d)) / (2 * a);
            r2 = (-b - sqrt(d)) / (2 * a);
            res = 2;
        } else if (d == 0) {
            r1 = r2 = -b / (2 * a);
            res = 1;
        } else {
            res = 0;
        }
    }

    double extremum() {
        return -b / (2.0 * a);
    }

    void intervals() {
        double ext = extremum();
        if (a > 0) {
            cout << "Decay: (-infinity, " << ext << ")\n";
            cout << "Increasing: (" << ext << ", +infinity)\n";
        } else {
            cout << "Decay: (" << ext << ", +infinity)\n";
            cout << "Increasing: (-infinity, " << ext << ")\n";
        }
    }
};

int main() {
    QuadraticEquation eq[] = {
        QuadraticEquation(1, 2, -3),
        QuadraticEquation(2, -4, -6),
        QuadraticEquation(3, 5, -2)
    };

    int num = sizeof(eq) / sizeof(eq[0]);

    double largest = -INFINITY;
    double smallest = INFINITY;

    for (int i = 0; i < num; ++i) {
        cout << "Equation " << i + 1 << ":\n";
        cout << "Vertex: " << eq[i].extremum() << endl;

        double r1, r2;
        int res;
        eq[i].roots(r1, r2, res);

        if (res == 2) {
            cout << "Roots: " << r1 << ", " << r2 << endl;
            if (r1 > largest) largest = r1;
            if (r2 > largest) largest = r2;
            if (r1 < smallest) smallest = r1;
            if (r2 < smallest) smallest = r2;
        } else if (res == 1) {
            cout << "Roots: " << r1 << endl;
            if (r1 > largest) largest = r1;
            if (r1 < smallest) smallest = r1;
        } else {
            cout << "No real roots." << endl;
        }

        eq[i].intervals();
        cout << endl;
    }

    if (largest != -INFINITY && smallest != INFINITY) {
        cout << "Largest root: " << largest << endl;
        cout << "Smallest root: " << smallest << endl;
    } else {
        cout << "No roots found in any equation." << endl;
    }

    return 0;
}
