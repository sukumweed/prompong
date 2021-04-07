#include <stdio.h>

struct item {
    long long barcode;
    char name[100];
    float price;
    int amount;
};

int main() {
    int num = 0, k, i;
    struct item A[100];
    char space[500];
    float total = 0;
    long long input;
    FILE *f;
    f = fopen("inventory.txt", "r");
    while (fscanf(f, " %lld", &A[num].barcode) != EOF) {
        fgets(space, 500, f);
        fgets(A[num].name, 500, f);
        fscanf(f, " %f", &A[num].price);
        fscanf(f, " %d", &A[num].amount);
        num++;
    }
    fclose(f);
    scanf(" %lld", &input);
    do {
        k = 0;
        while (A[k].barcode != input && k < num) {
            k++;
        }
        if (k < num) {
            A[k].amount--;
            printf("%s = %.2f THB\n", A[k].name, A[k].price);
            total += A[k].price;
            scanf(" %lld", &input);
        }
    } while (input != 0000000000000);
    printf("Total = %.2f THB", total);
    FILE *UP;
    UP = fopen("inventory.txt", "w");
    for (i = 0; i < num; i++) {
        fprintf(UP, "%lld\n", A[i].barcode);
        fprintf(UP, "%s%.2f\n", A[i].name, A[i].price);
        fprintf(UP, "%d\n\n", A[i].amount);
    }
    fclose(UP);
}

/*
8851932295796
8850329183616
8851932295789
8851932406574
8851932295789
8851932115919
0000000000000
*/