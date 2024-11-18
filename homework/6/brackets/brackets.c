//
// Created by 35861 on 24-11-11.
//
#include <stdio.h>
#include <string.h>
#define STACK_SIZE 100002
char stack[STACK_SIZE];
int t = -1;
void push(char);
void pop();
char top();
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        int flag =1;
        char ch;
        while ((ch = getchar()) != '\n'&& ch != EOF) {
            if (ch == '['|| ch == '('|| ch == '{') {
                push(ch);
            } else {
                if (t==-1)flag=0;
                else {
                    char prev = top();
                    if((prev =='('&& ch ==')')||(prev =='{'&& ch =='}')||(prev =='['&& ch ==']')) {
                        pop();
                    } else {
                        flag=0;
                    }
                }
            }
        }
        if (flag &&t==-1) {
            printf("True\n");
        } else {
            printf("False\n");
        }
        memset(stack, '0', STACK_SIZE);
        t=-1;
    }
    return 0;
}
void push(char ch) {
    stack[++t] = ch;
}
void pop() {
    t--;
}
char top() {
    return stack[t];
}