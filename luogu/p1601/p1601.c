//
// Created by 35861 on 24-10-28.
//
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[10005], b[10005], op;
int c[10005], d[10005], e[10005], alen, blen, clen, i, j;

void Plus() {
    clen = (alen > blen ? alen : blen) + 1;
    for (i = 0; i < clen - 1; i++) {
        c[i] += d[i] + e[i];
        if (c[i] >= 10) {
            c[i + 1] += 1;
            c[i] -= 10;
        }
    }
}

void Minus() {
    clen = alen;
    for (i = 0; i < clen; i++) {
        c[i] += d[i] - e[i];
        if (c[i] < 0) {
            c[i + 1] -= 1;
            c[i] += 10;
        }
    }
}

void Multiply() {
    clen = alen + blen;
    for (i = 0; i < clen; i++) {
        for (j = 0; j <= i; j++)
            c[i] += d[j] * e[i - j];
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

bool Equal(int d[], int e[], int i) {
    if (d[i + blen] != 0)
        return true;
    for (j = blen - 1; j >= 0; j--) {
        if (d[i + j] > e[j])
            return true;
        if (d[i + j] < e[j])
            return false;
    }
    return true;
}

void Divide() {
    clen = alen - blen + 1;
    for (i = clen - 1; i >= 0; i--)
        while (Equal(d, e, i)) {
            for (j = 0; j < blen; j++) {
                d[i + j] -= e[j];
                if (d[i + j] < 0) {
                    d[i + j] += 10;
                    d[i + j + 1]--;
                }
            }
            c[i]++;
        }
}

int main() {
    int n;
    scanf("%d\n", &n);
    for (int m = 0; m < n; m++) {
        scanf("%s %c %s", a, &op, b);
        alen = strlen(a);
        blen = strlen(b);
        for (i = 0; i < alen; i++)
            d[alen - i - 1] = a[i] - '0';
        for (i = 0; i < blen; i++)
            e[blen - i - 1] = b[i] - '0';
        switch (op) {
            case '+': Plus(); break;
            case '-': Minus(); break;
            case '*': Multiply(); break;
            case '/': Divide(); break;
            default: assert(0);
        }
        for (i = clen; i > 0; i--)
            if (c[i] != 0)
                break;
        for (; i >= 0; i--)
            printf("%d", c[i]);
        printf("\n");
        memset(c, 0, sizeof c);
        memset(d, 0, sizeof d);
        memset(e, 0, sizeof e);
    }
    return 0;
}