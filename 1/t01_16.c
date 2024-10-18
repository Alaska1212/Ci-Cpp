#include <stdio.h>
#include <math.h>

int main(){
    int x1 = 1, x2 = 2, x3 = 3, x4 = 4 ,x5 = 5;

    printf("a)\n");
    printf("x---|--%i---|--%i---|--%i---|--%i---|--%i---|\n", x1, x2, x3, x4, x5);
    printf("----|------|------|------|------|------|\n");
    float y1 = exp(-x1^2);
    float y2 = exp(-x2^2);
    float y3 = exp(-x3^2);
    float y4 = exp(-x4^2);
    float y5 = exp(-x5^2);
    printf("F(x)|-%0.2f-|-%0.2f-|-%0.2f-|-%0.2f-|-%0.2f-|\n", y1, y2, y3, y4, y5);


    printf("b)\n");
    printf("x---|--%i---|--%i---|--%i---|--%i---|--%i---|\n", x1, x2, x3, x4, x5);
    printf("----|------|------|------|------|------|\n");
    float y6 = sqrt(x1);
    float y7 = sqrt(x2);
    float y8 = sqrt(x3);
    float y9 = sqrt(x4);
    float y10 = sqrt(x5);
    printf("F(x)|-%0.2f-|-%0.2f-|-%0.2f-|-%0.2f-|-%0.2f-|\n", y6, y7, y8, y9, y10);


    return 0;
}
