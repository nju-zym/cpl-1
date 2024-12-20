//
// Created by 35861 on 24-12-20.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    int *arr;
}stack;

stack stacks[1000002];

void initStacks(int n);
void clearStack(int i);
void pourStacks(int x, int y);
void displayStacks(int i);
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    initStacks(n);
    while(m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        pourStacks(x, y);
    }
    for(int i = 1; i <= n; i++) {
        displayStacks(i);
    }
    return 0;
}
void initStacks(int n) {
    for(int i = 1; i <= n; i++) {
        stacks[i].top = 0;
        stacks[i].arr = (int *)malloc(sizeof(int));
        stacks[i].arr[0] = i;
    }
}
void clearStack(int i) {
    free(stacks[i].arr);
    stacks[i].top = -1;
    stacks[i].arr = NULL;
}
void pourStacks(int x, int y) {
    int size = stacks[x].top + stacks[y].top + 2;
    stacks[y].arr = realloc(stacks[y].arr, size * sizeof(int));
    for (int i = stacks[x].top; i >= 0; i--) {
        stacks[y].top++;
        stacks[y].arr[stacks[y].top] = stacks[x].arr[i];
    }
    clearStack(x);
}
void displayStacks(int i) {
    if (stacks[i].top >= 0) {
        for (int j = 0; j <= stacks[i].top; j++) {
            printf("%d ", stacks[i].arr[j]);
        }
    }
    else printf("0");
    printf("\n");
}