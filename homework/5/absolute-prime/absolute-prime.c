//
// Created by 35861 on 24-11-1.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isprime(int n) {
    int i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}
int reverse(int n) {
    char reverse[5];
    char num[5];
    sprintf(num, "%d", n);
    for (int i = 0; i < strlen(num); i++) {
        reverse[i] = num[strlen(num) - i - 1];
    }
    reverse[strlen(reverse)] = '\0';
    return atoi(reverse);
}
int main() {
    int n;
    scanf("%d", &n);
    int sum=0;
    for (int i=2; i<=n; i++) {
        if (isprime(i)&&isprime(reverse(i))) {
            sum++;
        }
    }
    printf("%d\n", sum);
    return 0;
}