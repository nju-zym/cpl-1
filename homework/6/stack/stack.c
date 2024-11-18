//
// Created by 35861 on 24-11-9.
//
#include <stdio.h>
#define STACK_SIZE 1002
char stack[STACK_SIZE];
int t = -1;
void push(char);
void pop();
char top();
void print();
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char command[6]={0};
        scanf("%s", command);
        if (command[0] == 'p'&&command[1] == 'u') {
            char ch;
            scanf(" %c" ,&ch);
            push(ch);
        }
        if (t!=-1) {
             if (command[0] == 'p'&&command[1] == 'o') pop();
            else if (command[0] == 't') printf("%c\n",top());
            else if (command[0] == 'p'&&command[1] == 'r') print();
        }
        else {
            printf("Empty\n");
        }
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
void print() {
    int temp = t;
    while (temp>=0) {
        printf("| %c |\n",stack[temp]);
        temp--;
    }
    printf("|===|\n");
}