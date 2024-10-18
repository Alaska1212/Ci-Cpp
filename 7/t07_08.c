#include <stdio.h>


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
int power(int x){
    while (x % 2 == 0){
        x /= 2;
    }
    return x == 1;
}




int main() {
    int N;
    printf("The number of array elements : ");
    scanf("%i", &N);
    int n = N;
    int arr[N];

    printf("Array: ");
    input(arr, &n);
    print(arr, n);

    int a = 0;
    for (int i = 0; i < n; i++){
        if (power(arr[i]))
            a += 1;
        else
            a += 0;
    }


    printf("Answer: %i", a);


    return 0;
}
