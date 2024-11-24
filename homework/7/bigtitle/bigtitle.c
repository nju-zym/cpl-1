//
// Created by 35861 on 24-11-22.
//
#include <ctype.h>
#include <stdio.h>
int main() {
    char ch;
    int flag = 1;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            printf("%c", ch);
            flag = 1;
        }
        else {
            if(flag == 1) {
                printf("%c", toupper(ch));
                flag = 0;
            }
            else {
                printf("%c", tolower(ch));
            }
        }
    }
    return 0;
}