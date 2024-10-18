#include <stdio.h>
#include <stdlib.h>


void input(int** arr, int N, int M) {
    printf("your array:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}


void print(int** arr, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


void deleteRows(int** arr, int* N, int M, int k1, int k2) {
    if (k1 < 0 || k2 >= *N || k1 > k2) {
        printf("no solution.\n");
        return;
    }

    for (int i = k1; i <= k2; i++) {
        free(arr[i]);
    }

    for (int i = k2 + 1; i < *N; ++i) {
        arr[i - (k2 - k1 + 1)] = arr[i];
    }

    *N -= (k2 - k1 + 1);
}

int main() {
    int N, M;
    printf("N = ");
    scanf("%d", &N);
    printf("M = ");
    scanf("%d", &M);

    int** arr = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(M * sizeof(int));
    }

    input(arr, N, M);

    int k1, k2;
    printf("k1 = ");
    scanf("%d", &k1);
    printf("k2 = ");
    scanf("%d", &k2);


    deleteRows(arr, &N, M, k1, k2);

    printf("\n solution:\n", k1, k2);
    print(arr, N, M);


    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
