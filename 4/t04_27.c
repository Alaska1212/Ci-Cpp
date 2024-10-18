#include <stdio.h>

double pi(double eps) {
    double s = 0.0;
    double a = 1.0;
    int k = 0;
    double x = 1.0;  // (-1)^k
    double y = 1.0;  // 4^k

    while (a > eps || a < -eps) {
        a = x / y * (2.0 / (4 * k + 1) + 2.0 / (4 * k + 2) + 1.0 / (4 * k + 3));
        s += a;
        x = -x;
        y *= 4.0;
        k++;
    }

    return s;
}

int main() {
    double eps = 0.000001;

    printf("pi = %.15f\n", pi(eps));

    return 0;
}
