#include <stdio.h>
#include <float.h>


double onestep(double x){
    if(x >= 0){
        return 1;
    }
    else{
        return 0;
    }
}

double identity_onestep(double x){
    if(x == 0){
        return DBL_MAX;
    }
    else{
        return 0;
    }
}

int main(){
    double x;
    printf("x = ");
    scanf("%lf", &x );

    printf("onestep(x) = %ld\n", onestep(x));
    printf("identity_onestep(x) = %e", identity_onestep(x));


    return 0;

}
