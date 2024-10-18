#include <stdio.h>
#include <math.h>

float f(int x){
    return x * pow((1+exp(-x)),-1);
}

char* g(){
    return "(e^x *(e^x+1+x)/(e^x +1)^2)";
}

int main() {
    int x;
    printf("x = ");
    scanf("%i", &x);

    printf("f(x) = %f\n", f(x));
    printf("g(x) = %s", g());


    return 0;
}
