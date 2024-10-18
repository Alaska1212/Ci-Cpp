#include <stdio.h>

int main(){
    double t = 365 + 1.0 / (4 + 1.0 / (7 + 1.0 / (1 + 1.0 / 3)));
    printf("%f", t);
    return 0;
}
