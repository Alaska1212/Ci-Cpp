#include <stdio.h>

void input(int matrix[][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}


void print(int matrix[][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}



void transpose(int matrix[][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}


void reverse(int matrix[][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }
}

void rotate(int matrix[][20], int n) {
    transpose(matrix, n);
    reverse(matrix, n);
}


int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    int matrix[20][20];
    input(matrix, n*2);

    rotate(matrix, n*2);
    printf("Solution: \n");
    print(matrix, n*2);

    return 0;
}
