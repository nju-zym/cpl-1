//
// Created by 35861 on 24-11-9.
//
#include <stdio.h>
int arr[10002];
int begin = 0;
int top = -1;
void in(int i);
void out();
void cat();
int main() {
    int n;
    scanf("%d", &n);
    while (n>0) {
        char command[4];
        scanf("%s", command);
        if (command[0] == 'I') {
            int i;
            scanf("%d", &i);
            in(i);
        } else if (command[0] == 'C') {
            cat();
        } else if (command[0] == 'O') {
            out();
        }
        n--;
    }
    return 0;
}
void in(int i) {
    arr[++top] = i;
}
void out() {
    printf("%d\n", arr[begin++]);
}
void cat() {
    printf("%d ", top-begin+1);
    printf("[");
    for (int i = begin; i < top; i++) {
        printf("%d,", arr[i]);
    }
    if (arr[top]!=0) {
        printf("%d]\n", arr[top]);
    }
    else {
        printf("]\n");
    }
}

