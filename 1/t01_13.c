#include <stdio.h>

int main(){
    float a;
    scanf("%f", &a);
    double n = log10(a);
    printf("%.3f", n);

    return 0;
}
