#include <stdio.h>

float f(float x, int k) {
    float n = 1;
    float x0 = 1;
    for (int i = 1; i <= k; i++) {
        n *= i;
        x0 *= x;
    }
    float res = x0 / n;

    if (k % 2 == 0) {
        return res;
    } else {
        return -res;
    }
}

int main() {
    float x;
    int k;
    printf("x = ");
    scanf("%f", &x);
    printf("k = ");
    scanf("%d", &k);

    printf("Xk = %.2f\n", f(x, k));
    return 0;
}
