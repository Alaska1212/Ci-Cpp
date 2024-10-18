#include <stdio.h>
#include <math.h>


void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void input(int arr[], int* n) {
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 0) {
            *n = i;
            break;
        }
    }
}


int parny(int arr[], int n){
    int k = pow(n, 0.5);
    int a = 0;  // лічильник
    for(int i = 0; i <= k; i++){
        if (arr[i*i] % 2 == 0)
            a += 1;
        else
            a += 0;
    }
    return a;

}



int main() {
    int n;
    printf("The number of array elements : ");
    scanf("%i", &n);
    int arr[n];

    //int k = pow(n, 0.5);

    printf("Array: ");
    input(arr, &n);
    print(arr, n);

    printf("Answer: %i", parny(arr, n));

    return 0;
}
