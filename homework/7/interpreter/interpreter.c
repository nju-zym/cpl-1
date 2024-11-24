//
// Created by 35861 on 24-11-22.
//
#include <stdio.h>
int main() {
    unsigned int number;
    scanf("%x", &number);
    printf("%d\n", (int)number);
    printf("%u\n", number);
    printf("%.6f\n", *(float*)&number);
    printf("%.3e\n", *(float*)&number);
    return 0;
}