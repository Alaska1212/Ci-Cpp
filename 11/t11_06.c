#include <stdio.h>
#include <stdlib.h>


int prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}


int counter(FILE *file) {
    int count = 0;
    int num;

    while (fscanf(file, "%d", &num) == 1) {
        if (prime(num)) {
            count++;
        }
    }

    return count;
}

int main() {
    const char *filename = "numbers.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    int res = counter(file);
    fclose(file);

    printf("The number of prime numbers in the file: %d\n", res);

    return 0;
}
