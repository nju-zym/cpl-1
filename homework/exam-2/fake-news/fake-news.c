//
// Created by 35861 on 24-11-16.
//
#include <stdio.h>
#include <string.h>

int main() {
    char str[1026];
    scanf("%s", str);
    int len = strlen(str);
    printf("%c",str[0]);
    for (int i = 1; i < len; i++) {
        if (str[i]<'a' || str[i]>'z') {
            printf(" %c",str[i]-'A'+'a');
        } else {
            printf("%c",str[i]);
        }
    }
    printf("\n");
    return 0;
}
