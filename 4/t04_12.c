#include <stdio.h>

int f(int x, int n) {
    int y;
    for(int i = 1; i <= n; i ++){
        x = x*x;
        y += x;
    }
    return y + 1;
}

int main(){
    int x,n;
    printf("x = ");
    scanf("%i", &x);
    printf("n = ");
    scanf("%i", &n);

    printf("y = %i", f(x,n));
    return 0;
}
