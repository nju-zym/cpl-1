#include <stdio.h>
long int p1_nums[100002];
long int p2_nums[100002];

int main() {
    int p1_order, p2_order;
    scanf("%d %d", &p1_order, &p2_order);
    char var[12];
    scanf("%s", var);
    for (int i = p1_order; i >= 0; i--) {
        scanf("%ld", &p1_nums[i]);
    }
    for (int i = p2_order; i >= 0; i--) {
        scanf("%ld", &p2_nums[i]);
    }
    printf("%d %d\n", p1_order, p2_order);
    printf("%s\n", var);
    for (int i = p1_order; i >= 0; i--) {
        printf("%ld ", p1_nums[i]);
    }
    printf("\n");
    for (int i = p2_order; i >= 0; i--) {
        printf("%ld ", p2_nums[i]);
    }
}