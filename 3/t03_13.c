#include <stdio.h>

int main(){
    float a, b, c;
    printf("a = ");
    scanf("%f", &a );
    printf("b = ");
    scanf("%f", &b );
    printf("c = ");
    scanf("%f", &c );

    if(a == b){
        printf("NO SOLUTIONS");}
    else {
        float x1 = (b - 2*a +c)/(b-a);
        float x2 = (c-b)/(b-a);
        float y = (a-c)/(b-a);
        printf("2 SOLUTIONS: (%f, %f), (%f, %f)", x1, y, x2, y);}


    return 0;

}
