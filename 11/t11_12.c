#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[100];
    float price;
    int age_from;
    int age_to;
} Toy;


void find_most_expensive_toy(Toy toys[], int count) {
    float max_price = toys[0].price;
    int max_index = 0;


    for (int i = 1; i < count; i++) {
        if (toys[i].price > max_price) {
            max_price = toys[i].price;
            max_index = i;
        }
    }


    printf("The most expensive toy: %s, Price: %.2f UAH\n", toys[max_index].name, toys[max_index].price);


    FILE *file = fopen("most_expensive_toy.bin", "wb");
    if (file != NULL) {
        fwrite(&toys[max_index], sizeof(Toy), 1, file);
        fclose(file);
        printf("The results are written to a binary file'most_expensive_toy.bin'.\n");
    } else {
        printf("Could not open file for writing.\n");
    }
}

int main() {
    FILE *file = fopen("toys.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    Toy toys[100];
    int count = 0;


    while (fscanf(file, "%s %f %d %d", toys[count].name, &toys[count].price, &toys[count].age_from, &toys[count].age_to) == 4) {
        count++;
    }

    fclose(file);


    find_most_expensive_toy(toys, count);

    return 0;
}
