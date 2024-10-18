#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    double* val;

}Vector;


void input(Vector v){
    printf("Enter values of vector: ");
    for(int i = 0; i< v.size; i++){
        scanf("%lf ", &v.val[i]);
    }
}

void print(Vector v){
    printf("Size of vector: %d ", v.size );
    printf("Values of vector: ");
    for(int i=0 ; i < v.size; i++){
        printf("%.3lf ", v.val[i]);
    }
}

int main(){
    int size;
    printf("Size of vector: ");
    scanf("%d", &size);

    Vector v;
    v.size = size;
    v.val = (double*)malloc(size * sizeof(double));

    input(v);
    print(v);

    free(v.val);


    return 0;
}
