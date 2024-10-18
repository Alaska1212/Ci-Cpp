#include <stdio.h>
#include <math.h>

int main() {
    float r, R;
    printf("r = ");
    scanf("%f", &r);
    printf("R = ");
    scanf("%f", &R);

    float V = 2 * pow(3.141592, 2) * R * pow(r, 2);
    printf("V = %f\n", V);

    return 0;
}
