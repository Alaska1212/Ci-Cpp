#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct{
    int uah;
    int kop;

} Product;

void input(Product* p,int n){
    printf("Enter price of product(grn kop): ");
    for(int i = 0; i< n; i++){
        scanf("%d %d", &p[i].uah, &p[i].kop);
    }
}

int expens(Product* p, int n){
    int max = 0;
    for(int i = 1; i < n; i++) {
        if (p[i].uah > p[max].uah || (p[i].uah == p[max].uah && p[i].kop > p[max].kop)) {
            max = i;
        }
    }
    return max;
}

int cheap(Product* p, int n){
    int min = 0;
    for(int i = 1; i < n; i++) {
        if (p[i].uah < p[min].uah || (p[i].uah == p[min].uah && p[i].kop < p[min].kop)) {
            min = i;
        }
    }
    return min;
}

int differ(Product* p, int n) {
    int sum_uah = 0;
    int sum_kop = 0;
    for(int i = 0; i < n; i++) {
        sum_uah += p[i].uah;
        sum_kop += p[i].kop;
    }
    double middle = (sum_uah + sum_kop / 100.0) / n;
    for(int i = 0; i < n; i++) {
        double price = p[i].uah + p[i].kop / 100.0;
        if(fabs(price - middle) <= 10)
            return i;
    }
    return -1; // якщо немає таких товарів
}



int main(){
    int n;
    printf("Number of product: ");
    scanf("%d", &n);

    Product* p = (Product*)malloc(n * sizeof(Product));

    input(p, n);

    int max = expens(p, n);
    printf("The most expensive product cost: %d.%d uah\n", p[max].uah, p[max].kop);

    int min = cheap(p, n);
    printf("The cheapest product cost: %d.%d uah\n", p[min].uah, p[min].kop);

    int a = differ(p, n);
    if (a == -1)
        printf("No solution");
    else
        printf("Product close to average price costs: %d.%d uah\n", p[a].uah, p[a].kop);

    free(p);

    return 0;
}
